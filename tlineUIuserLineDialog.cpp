// Copyright 2019 Steven A. Falco <stevenfalco@gmail.com>
//
// This file is part of tline.
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

#include "tlineUIuserLineDialog.h"
#include "constants.h"

tlineUIuserLineDialog::tlineUIuserLineDialog( wxWindow* parent ) : userLineDialog( parent )
{
}

void tlineUIuserLineDialog::onAttenuationSelected( wxCommandEvent& event )
{
	m_attenuation = atof(event.GetString());

	tlineUIrebuildEstimatedCableReactance();
}

void tlineUIuserLineDialog::onVelocityFactorSelected( wxCommandEvent& event )
{
	m_velocityFactor = atof(event.GetString());

	tlineUIrebuildEstimatedCableReactance();
}

void tlineUIuserLineDialog::onCableResistanceSelected( wxCommandEvent& event )
{
	m_cableResistance = atof(event.GetString());

	tlineUIrebuildEstimatedCableReactance();
}

void tlineUIuserLineDialog::onCableReactanceSelected( wxCommandEvent& event )
{
	m_cableReactance = atof(event.GetString());
}

void tlineUIuserLineDialog::onCableVoltageLimitSelected( wxCommandEvent& event )
{
	m_cableVoltageLimit = atof(event.GetString());
}

void tlineUIuserLineDialog::onOkClicked( wxCommandEvent& event )
{
	if ( Validate() )
	{
		EndModal( wxID_OK );
	}
}

void tlineUIuserLineDialog::onUseEstimatedReactanceClicked( wxCommandEvent& event )
{
	tlineUIuserLineDialogSetCableReactance(m_cableReactanceEstimate);
}

void tlineUIuserLineDialog::tlineUIuserLineDialogSetFrequency( double v )
{
	char buffer[512];

	m_frequency = v;

	snprintf(buffer, 512, "%.2f", m_frequency / 1e6);
	dl_frequencyStr->ChangeValue(buffer);
}

double tlineUIuserLineDialog::tlineUIuserLineDialogGetAttenuation()
{
	return m_attenuation;
}

void tlineUIuserLineDialog::tlineUIuserLineDialogSetAttenuation( double v )
{
	char buffer[512];

	m_attenuation = v;

	snprintf(buffer, 512, "%.2f", m_attenuation);
	dl_attenuationStr->ChangeValue(buffer);
}

double tlineUIuserLineDialog::tlineUIuserLineDialogGetVelocityFactor()
{
	return m_velocityFactor;
}

void tlineUIuserLineDialog::tlineUIuserLineDialogSetVelocityFactor( double v )
{
	char buffer[512];

	m_velocityFactor = v;

	snprintf(buffer, 512, "%.2f", m_velocityFactor);
	dl_velocityFactorStr->ChangeValue(buffer);
}

double tlineUIuserLineDialog::tlineUIuserLineDialogGetCableResistance()
{
	return m_cableResistance;
}

void tlineUIuserLineDialog::tlineUIuserLineDialogSetCableResistance( double v )
{
	char buffer[512];

	m_cableResistance = v;

	snprintf(buffer, 512, "%.2f", m_cableResistance);
	dl_cableResistanceStr->ChangeValue(buffer);
}

double tlineUIuserLineDialog::tlineUIuserLineDialogGetCableReactance()
{
	return m_cableReactance;
}

void tlineUIuserLineDialog::tlineUIuserLineDialogSetCableReactance( double v )
{
	char buffer[512];

	m_cableReactance = v;

	snprintf(buffer, 512, "%.2f", m_cableReactance);
	dl_cableReactanceStr->ChangeValue(buffer);
}

double tlineUIuserLineDialog::tlineUIuserLineDialogGetCableVoltageLimit()
{
	return m_cableVoltageLimit;
}

void tlineUIuserLineDialog::tlineUIuserLineDialogSetCableVoltageLimit( double v )
{
	char buffer[512];

	m_cableVoltageLimit = v;

	snprintf(buffer, 512, "%.2f", m_cableVoltageLimit);
	dl_cableVoltageLimitStr->ChangeValue(buffer);
}

void tlineUIuserLineDialog::tlineUIrebuildEstimatedCableReactance()
{
	char			buffer[512];

	double			attenuation;
	double			wavelength;
	double			phase;

	wavelength = m_velocityFactor * SPEED_OF_LIGHT_F / m_frequency;
	phase = (2.0 * PI) / wavelength;
	attenuation = DB_TO_NEPERS * m_attenuation / 100.0;

	m_cableReactanceEstimate = -m_cableResistance * (attenuation / phase);

	snprintf(buffer, 512, "%.2f Ohms", m_cableReactanceEstimate);
	dl_cableReactanceEstimatedStr->ChangeValue(buffer);
}
