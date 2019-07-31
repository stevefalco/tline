#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include "version.h"
#include "tlineLogic.h"
#include "constants.h"

tlineLogic::tlineLogic( wxWindow* parent ) : tlineUI( parent )
{
	wxString title = _("Transmission Line Calculator, Version ") + VERSION + _(", by AC2XM");

	m_c = new cableTypes;
	m_programTitle->SetLabel(title);

	recalculate();
}

void tlineLogic::onCableTypeSelected( wxCommandEvent& event )
{
	m_cableTypeStr = event.GetString();

	recalculate();
}

void tlineLogic::onFileExit( wxCommandEvent& event )
{
	// Could check for dirty and request save before exiting here.
	Destroy();
}

void tlineLogic::onUnitsSelected( wxCommandEvent& event )
{
	m_unitsStr = event.GetString();

	recalculate();
}

void tlineLogic::onFrequencySelected( wxCommandEvent& event )
{
	m_frequencyStr = event.GetString();

	recalculate();
}

void tlineLogic::onLengthSelected( wxCommandEvent& event )
{
	m_lengthStr = event.GetString();

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
	m_lengthUnits->SetLabel(m_unitsStr);

	// Convert the frequency string.
	m_frequency = atof(m_frequencyStr) * 1.0E6;

	// Convert the length string.
	m_length = atof(m_lengthStr);

	// Look up the cable parameters.
	m_cp = m_c->findCable(m_cableTypeStr.mb_str());

	// FIXME - this is just for safety - remove it once all cable types are populated.
	if(!m_cp) {
		m_cp = m_c->findCable("RG-6 (Belden 8215)");
	}

	//Calculate the wavelength.  We need the velocity factor here.
	m_wavelength = wavelength();
	
	// Look up the attenuation in nepers per unit length.
	m_atten = m_c->findAtten(m_units, m_cp, m_frequency);

	// Calculate the phase angle per unit length at the chosen frequency.
	m_phase = (2.0 * PI) / m_wavelength;

	// Combine attenuation and phase angle to get the loss coefficient.
	m_lossCoef = std::complex<double>(m_atten, m_phase);

	// Find the complex impedance of the coax.  There are several ways to
	// do this, and they each give different answers.  This seems to be the
	// best I've found...
	m_cableResistivePart = sqrt(sq(m_cp->impedance) / (1.0 + sq(m_atten) / sq(m_phase)));
	m_cableReactivePart = -m_cableResistivePart * (m_atten / m_phase);
	m_zCable =  std::complex<double>(m_cableResistivePart, m_cableReactivePart);

	snprintf(buffer, 512, "%.2f, %.2fj Ohms", real(m_zCable), imag(m_zCable));
	m_characteristicZ0->ChangeValue(buffer);

	snprintf(buffer, 512, "%.2f", m_length / m_wavelength);
	m_lambda->ChangeValue(buffer);
}
