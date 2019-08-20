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

#include "constants.h"
#include "tlineIcon.h"
#include "userLine.h"

userLine::userLine( wxWindow* parent ) : userLineDialog( parent )
{
	SetIcon(wxICON(aaaa));
}

void userLine::onAttenuationSelected( wxCommandEvent& event )
{
	m_userLineAttenuationStr = event.GetString();

	Update();
}

void userLine::onVelocityFactorSelected( wxCommandEvent& event )
{
	m_userLineVelocityFactorStr = event.GetString();

	Update();
}

void userLine::onCableResistanceSelected( wxCommandEvent& event )
{
	m_userLineCableResistanceStr = event.GetString();

	Update();
}

void userLine::onCableReactanceSelected( wxCommandEvent& event )
{
	m_userLineCableReactanceStr = event.GetString();

	Update();
}

void userLine::onCableVoltageLimitSelected( wxCommandEvent& event )
{
	m_userLineCableVoltageLimitStr = event.GetString();

	Update();
}

void userLine::onUseEstimatedReactanceClicked( wxCommandEvent& event )
{
	m_userLineCableReactanceStr = m_cableReactanceEstimateStr;

	Update();
}

void userLine::onOkClicked( wxCommandEvent& event )
{
	if ( Validate() )
	{
		EndModal( wxID_OK );
	}
}

void userLine::onCancelClicked( wxCommandEvent& event )
{
	if ( Validate() )
	{
		EndModal( wxID_CANCEL );
	}
}

void userLine::Update()
{
	double			attenuation;
	double			wavelength;
	double			phase;

	// Convert those parameters that we need for estimating reactance.
	m_frequency = atof(m_userLineFrequencyStr) * 1.0E6;
	m_attenuation = atof(m_userLineAttenuationStr);
	m_velocityFactor = atof(m_userLineVelocityFactorStr);
	m_cableResistance = atof(m_userLineCableResistanceStr);

	// Compute the estimated reactance, and convert to string format.
	wavelength = m_velocityFactor * SPEED_OF_LIGHT_F / m_frequency;
	phase = (2.0 * PI) / wavelength;
	attenuation = DB_TO_NEPERS * m_attenuation / 100.0;
	m_cableReactanceEstimate = -m_cableResistance * (attenuation / phase);
	m_cableReactanceEstimateStr = wxString::Format(wxT("%.2f"), m_cableReactanceEstimate);

	// Update all the displayed values.
	dl_frequencyStr->ChangeValue(m_userLineFrequencyStr);
	dl_attenuationStr->ChangeValue(m_userLineAttenuationStr);
	dl_velocityFactorStr->ChangeValue(m_userLineVelocityFactorStr);
	dl_cableResistanceStr->ChangeValue(m_userLineCableResistanceStr);
	dl_cableReactanceStr->ChangeValue(m_userLineCableReactanceStr);
	dl_cableReactanceEstimatedStr->ChangeValue(m_cableReactanceEstimateStr);
	dl_cableVoltageLimitStr->ChangeValue(m_userLineCableVoltageLimitStr);
}
