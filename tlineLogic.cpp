// Copyright 2019 Steven A. Falco <stevenfalco@gmail.com>
//
// This file is part of t;ome.
//
//  tline is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  tline is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with tline.  If not, see <https://www.gnu.org/licenses/>.

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include <wx/textfile.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/filename.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>

#include "version.h"
#include "tlineLogic.h"
#include "constants.h"

wxString g_widthStr;
wxString g_heightStr;

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
    
	wxFileDialog openFileDialog(this, _("Open tline file"), "", "", "tline files (*.tline)|*.tline", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if(openFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}
    
	wxFileInputStream input_stream(openFileDialog.GetPath());
	if(!input_stream.IsOk()) {
		wxLogError("Cannot open file '%s'", openFileDialog.GetPath());
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

		if(strcmp(buffer, "loadInput") == 0) {
			m_loadInputStr = p;
			if(strcmp(m_loadInputStr, "Load") == 0) {
				ui_loadInputRadioButtons->SetSelection(USE_LOAD);
			}
			if(strcmp(m_loadInputStr, "Input") == 0) {
				ui_loadInputRadioButtons->SetSelection(USE_INPUT);
			}
		}

		if(strcmp(buffer, "power") == 0) {
			m_powerStr = p;
			ui_power->ChangeValue(m_powerStr);
		}
	}

	f->Close();

	recalculate();
}

void tlineLogic::onFileSave( wxCommandEvent& event )
{
	wxFileDialog saveFileDialog(this, _("Save tline file"), "", "", "tline files (*.tline)|*.tline", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}
    
	wxFileOutputStream output_stream(saveFileDialog.GetPath());
	if (!output_stream.IsOk()) {
		wxLogError("Cannot save current contents in file '%s'", saveFileDialog.GetPath());
		return;
	}
    
	wxFile *f = output_stream.GetFile();
	FILE *fp = fdopen(f->fd(), "w");

	if(fp == NULL) {
		wxLogError("Cannot open file '%s' for writing", saveFileDialog.GetPath());
		return;
	}

	fprintf(fp, "cableType=%s\n",	(const char *)m_cableTypeStr.mb_str());
	fprintf(fp, "units=%s\n",	(const char *)m_unitsStr.mb_str());
	fprintf(fp, "frequency=%s\n",	(const char *)m_frequencyStr.mb_str());
	fprintf(fp, "length=%s\n",	(const char *)m_lengthStr.mb_str());
	fprintf(fp, "resistance=%s\n",	(const char *)m_resistanceStr.mb_str());
	fprintf(fp, "reactance=%s\n",	(const char *)m_reactanceStr.mb_str());
	fprintf(fp, "loadInput=%s\n",	(const char *)m_loadInputStr.mb_str());
	fprintf(fp, "power=%s\n",	(const char *)m_powerStr.mb_str());

	if(fflush(fp) == EOF) {
		wxLogError("Cannot flush file '%s'", saveFileDialog.GetPath());
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

void tlineLogic::onLoadInputSelected( wxCommandEvent& event )
{
	m_loadInputStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onPowerSelected( wxCommandEvent& event )
{
	m_powerStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onPlotZclicked( wxCommandEvent& event )
{
	doPlots(PLOT_Z);
}

void tlineLogic::onPlotVIclicked( wxCommandEvent& event )
{
	doPlots(PLOT_VI);
}

void tlineLogic::onSavePlotZclicked( wxCommandEvent& event )
{
	doPlots(SAVE_Z);
}

void tlineLogic::onSavePlotVIclicked( wxCommandEvent& event )
{
	doPlots(SAVE_VI);
}

void tlineLogic::onSaveDataClicked( wxCommandEvent& event )
{
	saveData();
}

void tlineLogic::onTunerClicked( wxCommandEvent& event )
{
	wxLogMessage("Tuner clicked");
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
complex<double> tlineLogic::impedanceAtInput(double distance)
{
	return m_zCable * (
			(m_zLoad * cosh(m_lossCoef * distance) + m_zCable * sinh(m_lossCoef * distance))
			/
			(m_zLoad * sinh(m_lossCoef * distance) + m_zCable * cosh(m_lossCoef * distance))
		       );
}

// Return complex impedance at load of cable for a given length and input.
complex<double> tlineLogic::impedanceAtLoad(double distance)
{
	return -m_zCable * (
			(m_zInput * cosh(m_lossCoef * distance) - m_zCable * sinh(m_lossCoef * distance))
			/
			(m_zInput * sinh(m_lossCoef * distance) - m_zCable * cosh(m_lossCoef * distance))
		       );
}

// Return the complex voltage at a given point along the line.
complex<double> tlineLogic::voltageOut(double distance)
{
	return m_voltageForPower * (cosh(m_lossCoef * distance) - (m_zCable / m_zInput) * sinh(m_lossCoef * distance));
}

// Return the complex current at a given point along the line.
complex<double> tlineLogic::currentOut(double distance)
{
	return (m_voltageForPower / m_zInput) * (cosh(m_lossCoef * distance) - (m_zInput / m_zCable) * sinh(m_lossCoef * distance));
}

// panel with custom controls for file dialog
class MyExtraPanel : public wxPanel
{
	public:
		MyExtraPanel(wxWindow *parent, wxString width, wxString height);
		wxString GetWidth() const
		{
			return wxString::Format("%s", (const char *)m_widthBox->GetValue());
		}
		wxString GetHeight() const
		{
			return wxString::Format("%s", (const char *)m_heightBox->GetValue());
		}
		void onWidthSelected( wxCommandEvent& event );
		void onHeightSelected( wxCommandEvent& event );
		
	private:
		wxString	m_widthStr;
		wxString	m_heightStr;
		wxStaticText	*m_widthTag;
		wxTextCtrl	*m_widthBox;
		wxStaticText	*m_heightTag;
		wxTextCtrl	*m_heightBox;
};

MyExtraPanel::MyExtraPanel(wxWindow *parent, wxString width, wxString height) : wxPanel(parent)
{
	m_widthStr = width;
	m_heightStr = height;

	m_widthTag = new wxStaticText(this, -1, "Width");
	m_widthBox = new wxTextCtrl(this, -1, m_widthStr);

	m_heightTag = new wxStaticText(this, -1, "   Height");
	m_heightBox = new wxTextCtrl(this, -1, m_heightStr);

	wxBoxSizer *sizerTop = new wxBoxSizer(wxHORIZONTAL);
	sizerTop->Add(m_widthTag, wxSizerFlags().Right().Border());
	sizerTop->Add(m_widthBox, wxSizerFlags().Right().Border(wxALL, 0));
	sizerTop->Add(m_heightTag, wxSizerFlags().Right().Border());
	sizerTop->Add(m_heightBox, wxSizerFlags().Right().Border(wxALL, 0));
	SetSizerAndFit(sizerTop);
	m_widthBox->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyExtraPanel::onWidthSelected ), NULL, this );
	m_heightBox->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyExtraPanel::onHeightSelected ), NULL, this );
}

void MyExtraPanel::onWidthSelected( wxCommandEvent& event )
{
	m_widthStr = event.GetString();
}

void MyExtraPanel::onHeightSelected( wxCommandEvent& event )
{
	m_heightStr = event.GetString();
}

// a static method can be used instead of a function with most of compilers
static wxWindow* createMyExtraPanel(wxWindow *parent)
{
	return new MyExtraPanel(parent, g_widthStr, g_heightStr);
}

// Build data and control files, then spawn gnuplot.
void tlineLogic::doPlots( int request )
{
	wxString		dataName;
	wxString		impedanceControlName;
	wxString		voltAmpControlName;

	wxFFile			dataFP;
	wxFFile			impedanceControlFP;
	wxFFile			voltAmpControlFP;

	char			buffer[512];
	char			*p;
	const char		*q;

	// Create temporary data file.
	dataName = wxFileName::CreateTempFileName("", &dataFP);
	if(dataName.IsEmpty()) {
		wxLogError("Cannot create temporary data file");
		goto QUIT;
	}

	// Create temporary impedanceControl file.
	impedanceControlName = wxFileName::CreateTempFileName("", &impedanceControlFP);
	if(impedanceControlName.IsEmpty()) {
		wxLogError("Cannot create temporary impedanceControl file");
		goto DELETE_DATA;
	}

	// Create temporary voltAmpControl file.
	voltAmpControlName = wxFileName::CreateTempFileName("", &voltAmpControlFP);
	if(voltAmpControlName.IsEmpty()) {
		wxLogError("Cannot create temporary voltAmpControl file");
		goto DELETE_IMPEDANCE_CONTROL;
	}

	// Generate the data.
	generateGraphableData(dataFP.fp());

	if(!dataFP.Flush()) {
		wxLogError("Cannot flush data file '%s'", dataName);
		goto DELETE_VOLT_AMP_CONTROL;
	}

	if(request == SAVE_Z) {
		g_widthStr = m_widthStr;
		g_heightStr = m_heightStr;

		wxFileDialog saveFileDialog(this, _("Save Z plot graphic file"), "", "", "", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
		saveFileDialog.SetExtraControlCreator(&createMyExtraPanel);
		if (saveFileDialog.ShowModal() == wxID_CANCEL) {
			goto DELETE_VOLT_AMP_CONTROL;
		}

		snprintf(buffer, 512, "%s", (const char *)saveFileDialog.GetFilename().mb_str());
		if((p = strrchr(buffer, '.')) != NULL) {
			// Process the suffix.
			if(strcasecmp(p, ".png") == 0) {
				q = "png";
			} else if((strcasecmp(p, ".jpg") == 0) || (strcasecmp(p, ".jpeg") == 0)) {
				q = "jpeg";
			} else if(strcasecmp(p, ".gif") == 0) {
				q = "gif";
			} else {
				// Default
				q = "png";
			}
		}

		wxWindow * const extra = saveFileDialog.GetExtraControl();
		if(extra) {
			m_widthStr = static_cast<MyExtraPanel*>(extra)->GetWidth();
			m_width = atoi(m_widthStr);

			m_heightStr = static_cast<MyExtraPanel*>(extra)->GetHeight();
			m_height = atoi(m_heightStr);
		}

		fprintf(impedanceControlFP.fp(), "set terminal %s size %d,%d\n", q, m_width, m_height);
		fprintf(impedanceControlFP.fp(), "set output \"%s\"\n", (const char*)saveFileDialog.GetPath());
	}

	if(request == SAVE_VI) {
		g_widthStr = m_widthStr;
		g_heightStr = m_heightStr;

		wxFileDialog saveFileDialog(this, _("Save VI plot graphic file"), "", "", "", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
		saveFileDialog.SetExtraControlCreator(&createMyExtraPanel);
		if (saveFileDialog.ShowModal() == wxID_CANCEL) {
			goto DELETE_VOLT_AMP_CONTROL;
		}

		snprintf(buffer, 512, "%s", (const char *)saveFileDialog.GetFilename().mb_str());
		if((p = strrchr(buffer, '.')) != NULL) {
			// Process the suffix.
			if(strcasecmp(p, ".png") == 0) {
				q = "png";
			} else if((strcasecmp(p, ".jpg") == 0) || (strcasecmp(p, ".jpeg") == 0)) {
				q = "jpeg";
			} else if(strcasecmp(p, ".gif") == 0) {
				q = "gif";
			} else {
				// Default
				q = "png";
			}
		}

		wxWindow * const extra = saveFileDialog.GetExtraControl();
		if(extra) {
			m_widthStr = static_cast<MyExtraPanel*>(extra)->GetWidth();
			m_width = atoi(m_widthStr);

			m_heightStr = static_cast<MyExtraPanel*>(extra)->GetHeight();
			m_height = atoi(m_heightStr);
		}

		fprintf(voltAmpControlFP.fp(), "set terminal %s size %d,%d\n", q, m_width, m_height);
		fprintf(voltAmpControlFP.fp(), "set output \"%s\"\n", (const char*)saveFileDialog.GetPath());
	}

	// Fill in the impedanceControl file.
	fprintf(impedanceControlFP.fp(), "set ytics -1000000,10 nomirror tc lt 1\n");
	fprintf(impedanceControlFP.fp(), "set ylabel \"Imaginary (Ohms)\" tc lt 1\n");
	fprintf(impedanceControlFP.fp(), "set y2tics -1000000,10 nomirror tc lt 2\n");
	fprintf(impedanceControlFP.fp(), "set y2label \"Real (Ohms)\" tc lt 2\n");
	fprintf(impedanceControlFP.fp(), "set xlabel \"Length (%s)\"\n", (const char*)m_unitsStr);
	fprintf(impedanceControlFP.fp(), "plot \\\n");
	fprintf(impedanceControlFP.fp(), "  \"%s\" u 1:3 w l axes x1y1 title \"img\", \\\n", (const char*)dataName);
	fprintf(impedanceControlFP.fp(), "  \"%s\" u 1:2 w l axes x1y2 title \"img\"\n", (const char*)dataName);
	
	if(!impedanceControlFP.Flush()) {
		wxLogError("Cannot flush impedance control file '%s'", impedanceControlName);
		goto DELETE_VOLT_AMP_CONTROL;
	}

	// Fill in the voltAmpControl file.
	fprintf(voltAmpControlFP.fp(), "set ytics -1000000,1 nomirror tc lt 1\n");
	fprintf(voltAmpControlFP.fp(), "set ylabel \"Current (Amps)\" tc lt 1\n");
	fprintf(voltAmpControlFP.fp(), "set y2tics -1000000,20 nomirror tc lt 2\n");
	fprintf(voltAmpControlFP.fp(), "set y2label \"Voltage (Volts)\" tc lt 2\n");
	fprintf(voltAmpControlFP.fp(), "set xlabel \"Length (%s)\"\n", (const char*)m_unitsStr);
	fprintf(voltAmpControlFP.fp(), "plot \\\n");
	fprintf(voltAmpControlFP.fp(), "  \"%s\" u 1:9 w l axes x1y1 title \"amps\", \\\n", (const char*)dataName);
	fprintf(voltAmpControlFP.fp(), "  \"%s\" u 1:8 w l axes x1y2 title \"volts\"\n", (const char*)dataName);
	
	if(!voltAmpControlFP.Flush()) {
		wxLogError("Cannot flush volt/amp control file '%s'", voltAmpControlName);
		goto DELETE_VOLT_AMP_CONTROL;
	}

	// Build the plot command.
	switch(request) {
		case PLOT_Z:
			snprintf(buffer, 512, "gnuplot -p %s", (const char *)impedanceControlName.mb_str());
			break;

		case SAVE_Z:
			snprintf(buffer, 512, "gnuplot %s", (const char *)impedanceControlName.mb_str());
			break;

		case PLOT_VI:
			snprintf(buffer, 512, "gnuplot -p %s", (const char *)voltAmpControlName.mb_str());
			break;

		case SAVE_VI:
			snprintf(buffer, 512, "gnuplot %s", (const char *)voltAmpControlName.mb_str());
			break;

		default:
			goto DELETE_VOLT_AMP_CONTROL;
	}

	// Execute the plot command.
	system(buffer);
	
	// Delete the temporary files from the filesystem.
DELETE_VOLT_AMP_CONTROL:
	voltAmpControlFP.Close();
	wxRemoveFile(voltAmpControlName);

DELETE_IMPEDANCE_CONTROL:
	impedanceControlFP.Close();
	//wxRemoveFile(impedanceControlName);

DELETE_DATA:
	dataFP.Close();
	wxRemoveFile(dataName);

QUIT:
	return;
}

void tlineLogic::saveData()
{
	wxFileDialog saveFileDialog(this, _("Save plot data file"), "", "", "plot data files (*.plot)|*.plot", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}
    
	wxFileOutputStream output_stream(saveFileDialog.GetPath());
	if (!output_stream.IsOk()) {
		wxLogError("Cannot save current contents in file '%s'", saveFileDialog.GetPath());
		return;
	}
    
	wxFile *f = output_stream.GetFile();
	FILE *fp = fdopen(f->fd(), "w");

	if(fp == NULL) {
		wxLogError("Cannot open file '%s' for writing", saveFileDialog.GetPath());
		return;
	}

	generateGraphableData(fp);

	if(fflush(fp) == EOF) {
		wxLogError("Cannot flush file '%s'", saveFileDialog.GetPath());
		return;
	}

	f->Close();
}

// Calculate the graphable data.  We write it to a temporary file which we
// will pass to gnuplot.
void tlineLogic::generateGraphableData(
		FILE*		fp
		)
{
	int				i;

	double				distanceFromSource;
	double				distanceFromLoad;

	complex<double>		zPoint;
	complex<double>		vOut;
	complex<double>		iOut;

	// Show column headings.
	fprintf(fp, "#       Length        Z_In_Real      Z_In_Imag           V_Real         V_Imag           I_Real         I_Imag           V_Magn         I_Magn\n");

	// Scale cable length by SCALE for a smoother curve.
	for(i = 0; i <= POINTS_ON_X; i++) {
		distanceFromSource = m_length * ((double)i / (double)POINTS_ON_X);
		distanceFromLoad = m_length - distanceFromSource;

		// Find the impedance at the input for a given length of line.
		zPoint = impedanceAtInput(distanceFromLoad);

		// Find the voltage at a point along the cable.
		vOut = voltageOut(distanceFromSource);

		// Find the current at a point along the cable.
		iOut = currentOut(distanceFromSource);

		fprintf(fp, "%14.6f   %14.6f %14.6f   %14.6f %14.6f   %14.6f %14.6f   %14.6f %14.6f\n",
				distanceFromSource,
				real(zPoint), imag(zPoint),
				real(vOut), imag(vOut),
				real(iOut), imag(iOut),
				abs(vOut), abs(iOut));
	}
}

void tlineLogic::recalculate()
{
	char				buffer[512];
	double				tmp;

	// Convert the units string.
	if(m_unitsStr == "Feet") {
		m_units = USE_FEET;
	} else if(m_unitsStr == "Meters") {
		m_units = USE_METERS;
	} else {
		m_units = USE_FEET;
		wxLogMessage("Unknown Units %s", m_unitsStr);
	}
	ui_lengthUnits->SetLabel(m_unitsStr);

	// Convert the frequency string.
	m_frequency = atof(m_frequencyStr) * 1.0E6;

	// Look up the cable parameters.
	m_cp = m_c->findCable(m_cableTypeStr.mb_str());
	snprintf(buffer, 512, "%.2f", m_cp->velocityFactor);
	ui_velocityFactor->ChangeValue(buffer);
	snprintf(buffer, 512, "%.0f V", m_cp->maximumVoltage);
	ui_maxVoltage->ChangeValue(buffer);

	// Calculate the wavelength.  We need the velocity factor here.
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
	snprintf(buffer, 512, "%.2f", m_lambda);
	ui_lambda->ChangeValue(buffer);

	// Look up the attenuation in dB per hundred feet, and convert to the
	// other formats we will need.
	m_attenPer100Feet = m_c->findAtten(m_cp, m_frequency);
	m_attenPer100Meters = m_attenPer100Feet * M_TO_F;
	if(m_units == USE_FEET) {
		m_attenPer100Units = m_attenPer100Feet;
		snprintf(buffer, 512, "%.2f dB/100 Feet", m_attenPer100Units);
		ui_matchedLineLoss->ChangeValue(buffer);
	} else {
		m_attenPer100Units = m_attenPer100Meters;
		snprintf(buffer, 512, "%.2f dB/100 Meters", m_attenPer100Units);
		ui_matchedLineLoss->ChangeValue(buffer);
	}
	m_attenDBPerUnitLength = m_attenPer100Units / 100.0;
	m_attenNepersPerUnitLength = m_attenDBPerUnitLength * DB_TO_NEPERS;

	// Calculate the phase angle per unit length at the chosen frequency.
	m_phase = (2.0 * PI) / m_wavelength;

	// Combine attenuation and phase angle to get the loss coefficient.
	m_lossCoef = complex<double>(m_attenNepersPerUnitLength, m_phase);

	// Find the complex impedance of the coax.  There are several ways to
	// do this, and they each give different answers.  This is the best
	// method that I've found...
	m_cableResistivePart = sqrt(sq(m_cp->impedance) / (1.0 + sq(m_attenNepersPerUnitLength) / sq(m_phase)));
	m_cableReactivePart = -m_cableResistivePart * (m_attenNepersPerUnitLength / m_phase);
	m_zCable = complex<double>(m_cableResistivePart, m_cableReactivePart);
	snprintf(buffer, 512, "%.2f, %.2fJ Ohms", real(m_zCable), imag(m_zCable));
	ui_characteristicZ0->ChangeValue(buffer);

	m_resistance = atof(m_resistanceStr);
	m_reactance = atof(m_reactanceStr);
	if(m_loadInputStr == "Load") {
		// Use the provided load impedance.
		m_zLoad = complex<double>(m_resistance, m_reactance);

		// Find the input impedance for the full length of cable.
		m_zInput = impedanceAtInput(m_length);
		snprintf(buffer, 512, "%.2f, %.2fJ Ohms", real(m_zInput), imag(m_zInput));
		ui_impedanceRectangular->ChangeValue(buffer);
		snprintf(buffer, 512, "%.2f @ %.2f DEG", abs(m_zInput), arg(m_zInput) * RADIANS_TO_DEGREES);
		ui_impedancePolar->ChangeValue(buffer);

		ui_impedanceRectangularTag->SetLabel("Impedance at Input (Real/Imaginary):");
		ui_impedancePolarTag->SetLabel("Impedance at Input (Polar):");
	} else if(m_loadInputStr == "Input") {
		// Use the provided input impedance.
		m_zInput = complex<double>(m_resistance, m_reactance);

		// Find the load impedance for the full length of cable.
		m_zLoad = impedanceAtLoad(m_length);
		snprintf(buffer, 512, "%.2f, %.2fJ Ohms", real(m_zLoad), imag(m_zLoad));
		ui_impedanceRectangular->ChangeValue(buffer);
		snprintf(buffer, 512, "%.2f @ %.2f DEG", abs(m_zLoad), arg(m_zLoad) * RADIANS_TO_DEGREES);
		ui_impedancePolar->ChangeValue(buffer);

		ui_impedanceRectangularTag->SetLabel("Impedance at Load (Real/Imaginary):");
		ui_impedancePolarTag->SetLabel("Impedance at Load (Polar):");
	}

	// Calculate the reflection coefficient at the load.
	m_rho = (m_zLoad - m_zCable) / (m_zLoad + m_zCable);
	m_rhoMagnitudeAtLoad = abs(m_rho);
	m_returnLossAtLoad = 20.0 * log10(m_rhoMagnitudeAtLoad);
	snprintf(buffer, 512, "%.2f", m_rhoMagnitudeAtLoad);
	ui_rhoLoad->ChangeValue(buffer);

	// Calculate the SWR at the load.
	m_swrAtLoad = (1.0 + m_rhoMagnitudeAtLoad) / (1.0 - m_rhoMagnitudeAtLoad);
	snprintf(buffer, 512, "%.2f", m_swrAtLoad);
	ui_swrLoad->ChangeValue(buffer);

	// Calculate matched line loss.
	m_totalMatchedLineLoss = m_attenDBPerUnitLength * m_length;
	snprintf(buffer, 512, "%.2f dB", m_totalMatchedLineLoss);
	ui_totalMatchedLineLoss->ChangeValue(buffer);

	//Calculate total loss.
	tmp = pow(10.0, 0.1 * m_totalMatchedLineLoss);
	m_totalLoss = 10.0 * log10((sq(tmp) - sq(m_rhoMagnitudeAtLoad)) / (tmp * (1.0 - sq(m_rhoMagnitudeAtLoad))));
	snprintf(buffer, 512, "%.2f dB", m_totalLoss);
	ui_totalLoss->ChangeValue(buffer);
	
	// Calculate extra loss caused by SWR.
	m_extraSWRloss = m_totalLoss - m_totalMatchedLineLoss;
	snprintf(buffer, 512, "%.2f dB", m_extraSWRloss);
	ui_addedLoss->ChangeValue(buffer);

	// Calculate the SWR at the source.
	m_returnLossAtSource = m_returnLossAtLoad - 2.0 * m_totalLoss;
	m_rhoMagnitudeAtSource = pow(10.0, m_returnLossAtSource / 20.0);
	m_swrAtSource = (1 + m_rhoMagnitudeAtSource) / (1 - m_rhoMagnitudeAtSource);
	snprintf(buffer, 512, "%.2f", m_swrAtSource);
	ui_swrInput->ChangeValue(buffer);
	
	// Find the voltage necessary to produce the desired power at the
	// input of the cable, given the magnitude of the complex input
	// impedance.
	m_power = atof(m_powerStr);
	m_voltageForPower = sqrt(m_power * abs(m_zInput));
	snprintf(buffer, 512, "%.2f V", m_voltageForPower);
	ui_inputVoltage->ChangeValue(buffer);
}
