#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include <wx/textfile.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>

#include "version.h"
#include "tlineLogic.h"
#include "constants.h"

tlineLogic::tlineLogic( wxWindow* parent ) : tlineUI( parent )
{
	wxString title = _("Transmission Line Calculator, Version ") + VERSION + _(", by AC2XM");

	m_c = new cableTypes;
	ui_programTitle->SetLabel(title);

	// Once any parameter is changed, this will flip to 0.
	m_saved = 1;

	recalculate();
}

void tlineLogic::onFileLoad( wxCommandEvent& event )
{
	char buffer[512];
	char *p;

	if(!m_saved) {
		if(wxMessageBox(_("Current content has not been saved! Proceed?"), _("Please confirm"), wxICON_QUESTION | wxYES_NO, this) == wxNO) {
			return;
		}
	}
    
	wxFileDialog openFileDialog(this, _("Open tline file"), "", "", "tline files (*.tline)|*.tline", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if(openFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}
    
	wxFileInputStream input_stream(openFileDialog.GetPath());
	if(!input_stream.IsOk()) {
		wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
		return;
	}
    
	wxFile *f = input_stream.GetFile();
	FILE *fp = fdopen(f->fd(), "r");

	while(fgets(buffer, 512, fp) != NULL) {
		*strchrnul(buffer, '\n') = 0;

		if(buffer[0] == '#') {
			continue;
		}

		if((p = strchr(buffer, '=')) == NULL) {
			wxLogError("Missing '=' in %s", buffer);
			continue;
		}
		*p++ = 0;

		if(strcmp(buffer, "cableType") == 0) {
			m_cableTypeStr = p;
			ui_cableType->ChangeValue(m_cableTypeStr);
		}

		if(strcmp(buffer, "units") == 0) {
			m_unitsStr = p;
			if(strcmp(m_unitsStr, "Feet") == 0) {
				ui_unitsRadioButtons->SetSelection(USE_FEET);
			}
			if(strcmp(m_unitsStr, "Meters") == 0) {
				ui_unitsRadioButtons->SetSelection(USE_METERS);
			}
		}

		if(strcmp(buffer, "frequency") == 0) {
			m_frequencyStr = p;
			ui_frequency->ChangeValue(m_frequencyStr);
		}

		if(strcmp(buffer, "length") == 0) {
			m_lengthStr = p;
			ui_cableLength->ChangeValue(m_lengthStr);
		}

		if(strcmp(buffer, "resistance") == 0) {
			m_resistanceStr = p;
			ui_resistance->ChangeValue(m_resistanceStr);
		}

		if(strcmp(buffer, "reactance") == 0) {
			m_reactanceStr = p;
			ui_reactance->ChangeValue(m_reactanceStr);
		}
	}

	f->Close();

	recalculate();
}

void tlineLogic::onFileSave( wxCommandEvent& event )
{
	wxFileDialog saveFileDialog(this, _("Save tline file"), "", "", "tline files (*.tline)|*.tline", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}
    
	wxFileOutputStream output_stream(saveFileDialog.GetPath());
	if (!output_stream.IsOk()) {
		wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
		return;
	}
    
	wxFile *f = output_stream.GetFile();
	FILE *fp = fdopen(f->fd(), "w");

	if(fp == NULL) {
		wxLogError("Cannot open file '%s' for writing.", saveFileDialog.GetPath());
		return;
	}

	fprintf(fp, "cableType=%s\n",	(const char *)m_cableTypeStr.mb_str());
	fprintf(fp, "units=%s\n",	(const char *)m_unitsStr.mb_str());
	fprintf(fp, "frequency=%s\n",	(const char *)m_frequencyStr.mb_str());
	fprintf(fp, "length=%s\n",	(const char *)m_lengthStr.mb_str());
	fprintf(fp, "resistance=%s\n",	(const char *)m_resistanceStr.mb_str());
	fprintf(fp, "reactance=%s\n",	(const char *)m_reactanceStr.mb_str());

	if(fflush(fp) == EOF) {
		wxLogError("Cannot flush file '%s'.", saveFileDialog.GetPath());
		return;
	}

	f->Close();

	m_saved = 1;
}

void tlineLogic::onFileExit( wxCommandEvent& event )
{
	// Could check for dirty and request save before exiting here.
	Destroy();
}

void tlineLogic::onCableTypeSelected( wxCommandEvent& event )
{
	m_cableTypeStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onUnitsSelected( wxCommandEvent& event )
{
	m_unitsStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onFrequencySelected( wxCommandEvent& event )
{
	m_frequencyStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onLengthSelected( wxCommandEvent& event )
{
	m_lengthStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onResistanceSelected( wxCommandEvent& event )
{
	m_resistanceStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onReactanceSelected( wxCommandEvent& event )
{
	m_reactanceStr = event.GetString();
	m_saved = 0;

	recalculate();
}

double tlineLogic::wavelength()
{
	double				wavelength;

	if(m_units == USE_FEET) {
		wavelength = m_cp->velocityFactor * SPEED_OF_LIGHT_F / m_frequency;
	} else if(m_units == USE_METERS) {
		wavelength = m_cp->velocityFactor * SPEED_OF_LIGHT_M / m_frequency;
	} else {
		wavelength = -1.0;
	}

	return wavelength;
}

// Return complex impedance at input of cable for a given length and load.
std::complex<double> tlineLogic::impedance()
{
	return m_zCable * (
			(m_zLoad * cosh(m_lossCoef * m_length) + m_zCable * sinh(m_lossCoef * m_length))
			/
			(m_zLoad * sinh(m_lossCoef * m_length) + m_zCable * cosh(m_lossCoef * m_length))
		       );
}

void tlineLogic::recalculate()
{
	char				buffer[512];

	// Convert the units string.
	if(m_unitsStr == "Feet") {
		m_units = USE_FEET;
	} else if(m_unitsStr == "Meters") {
		m_units = USE_METERS;
	} else {
		m_units = USE_FEET;
		wxLogMessage("Unkown Units %s", m_unitsStr);
	}
	ui_lengthUnits->SetLabel(m_unitsStr);

	// Convert the frequency string.
	m_frequency = atof(m_frequencyStr) * 1.0E6;

	// Look up the cable parameters.
	m_cp = m_c->findCable(m_cableTypeStr.mb_str());

	// FIXME - this is just for safety - remove it once all cable types are populated.
	if(!m_cp) {
		m_cp = m_c->findCable("RG-6 (Belden 8215)");
	}

	//Calculate the wavelength.  We need the velocity factor here.
	m_wavelength = wavelength();
	
	// Convert the length string.  We need the wavelength here.
	if(!m_lengthStr.empty()) {
		char lastChar = *m_lengthStr.rbegin();

		if(lastChar == 'w' || lastChar == 'W') {
			m_length = atof(m_lengthStr) * m_wavelength;
			snprintf(buffer, 512, "%.2f", m_length);
			ui_cableLength->ChangeValue(buffer);
		} else {
			m_length = atof(m_lengthStr);
		}
	} else {
		m_length = atof(m_lengthStr);
	}

	// Calculate the length of the line in wavelength units.
	m_lambda = m_length / m_wavelength;

	// Look up the attenuation in dB per hundred feet, and convert to the
	// other formats we will need.
	m_attenPer100Feet = m_c->findAtten(m_cp, m_frequency);
	m_attenPer100Meters = m_attenPer100Feet * M_TO_F;
	if(m_units == USE_FEET) {
		m_attenPer100Units = m_attenPer100Feet;
		snprintf(buffer, 512, "dB/100 Feet");
		ui_matchedLineLossUnits->SetLabel(buffer);
	} else {
		m_attenPer100Units = m_attenPer100Meters;
		snprintf(buffer, 512, "dB/100 Meters");
		ui_matchedLineLossUnits->SetLabel(buffer);
	}
	m_attenDBPerUnitLength = m_attenPer100Units / 100.0;
	m_attenNepersPerUnitLength = m_attenDBPerUnitLength * DB_TO_NEPERS;

	// Calculate the phase angle per unit length at the chosen frequency.
	m_phase = (2.0 * PI) / m_wavelength;

	// Combine attenuation and phase angle to get the loss coefficient.
	m_lossCoef = std::complex<double>(m_attenNepersPerUnitLength, m_phase);

	// Find the complex impedance of the coax.  There are several ways to
	// do this, and they each give different answers.  This is the best
	// method that I've found...
	m_cableResistivePart = sqrt(sq(m_cp->impedance) / (1.0 + sq(m_attenNepersPerUnitLength) / sq(m_phase)));
	m_cableReactivePart = -m_cableResistivePart * (m_attenNepersPerUnitLength / m_phase);
	m_zCable = std::complex<double>(m_cableResistivePart, m_cableReactivePart);

	// Use the provided load impedance.
	m_resistance = atof(m_resistanceStr);
	m_reactance = atof(m_reactanceStr);
	m_zLoad = std::complex<double>(m_resistance, m_reactance);

	// Find the input impedance for the full length of cable.
	m_zIn = impedance();

	// Calculate the reflection coefficient at the load.
	m_rho = (m_zLoad - m_zCable) / (m_zLoad + m_zCable);
	m_rhoMagnitude = abs(m_rho);

	// Calculate the SWR at the load.
	m_swrAtLoad = (1.0 + m_rhoMagnitude) / (1.0 - m_rhoMagnitude);

	// Calculate matched line loss.
	m_matchedLineLoss = m_attenDBPerUnitLength * m_length;

	//Calculate total loss.
	double a = pow(10.0, 0.1 * m_matchedLineLoss);
	m_totalLoss = 10.0 * log10((sq(a) - sq(m_rhoMagnitude)) / (a * (1.0 - sq(m_rhoMagnitude))));
	
	// Calculate extra lost caused by SWR.
	m_extraSWRloss = m_totalLoss - m_matchedLineLoss;

	snprintf(buffer, 512, "%.2f", m_lambda);
	ui_lambda->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f, %.2fj Ohms", real(m_zCable), imag(m_zCable));
	ui_characteristicZ0->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f", m_attenPer100Units);
	ui_matchedLineLoss->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f", m_cp->velocityFactor);
	ui_velocityFactor->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f", m_matchedLineLoss);
	ui_totalMatchedLineLoss->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f, %.2fj Ohms", real(m_zIn), imag(m_zIn));
	ui_impedanceRectangular->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f, %.2fj Ohms", abs(m_zIn), arg(m_zIn) * RADIANS_TO_DEGREES);
	ui_impedancePolar->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f", m_rhoMagnitude);
	ui_rhoLoad->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f", m_swrAtLoad);
	ui_swrLoad->ChangeValue(buffer);

	snprintf(buffer, 512, "%.0f", m_cp->maximumVoltage);
	ui_maxVoltage->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f", m_totalLoss);
	ui_totalLoss->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f", m_extraSWRloss);
	ui_addedLoss->ChangeValue(buffer);
}
