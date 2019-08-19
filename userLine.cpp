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
	m_attenuation = atof(event.GetString());

	userLineRebuildEstimatedCableReactance();
}

void userLine::onVelocityFactorSelected( wxCommandEvent& event )
{
	m_velocityFactor = atof(event.GetString());

	userLineRebuildEstimatedCableReactance();
}

void userLine::onCableResistanceSelected( wxCommandEvent& event )
{
	m_cableResistance = atof(event.GetString());

	userLineRebuildEstimatedCableReactance();
}

void userLine::onCableReactanceSelected( wxCommandEvent& event )
{
	m_cableReactance = atof(event.GetString());
}

void userLine::onCableVoltageLimitSelected( wxCommandEvent& event )
{
	m_cableVoltageLimit = atof(event.GetString());
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

void userLine::onUseEstimatedReactanceClicked( wxCommandEvent& event )
{
	userLineSetCableReactance(m_cableReactanceEstimate);
}

void userLine::userLineSetFrequency( double v )
{
	m_frequency = v;

	dl_frequencyStr->ChangeValue(wxString::Format(wxT("%.2f"), m_frequency / 1e6));
}

double userLine::userLineGetAttenuation()
{
	return m_attenuation;
}

void userLine::userLineSetAttenuation( double v )
{
	m_attenuation = v;

	dl_attenuationStr->ChangeValue(wxString::Format(wxT("%.2f"), m_attenuation));
}

double userLine::userLineGetVelocityFactor()
{
	return m_velocityFactor;
}

void userLine::userLineSetVelocityFactor( double v )
{
	m_velocityFactor = v;

	dl_velocityFactorStr->ChangeValue(wxString::Format(wxT("%.2f"), m_velocityFactor));
}

double userLine::userLineGetCableResistance()
{
	return m_cableResistance;
}

void userLine::userLineSetCableResistance( double v )
{
	m_cableResistance = v;

	dl_cableResistanceStr->ChangeValue(wxString::Format(wxT("%.2f"), m_cableResistance));
}

double userLine::userLineGetCableReactance()
{
	return m_cableReactance;
}

void userLine::userLineSetCableReactance( double v )
{
	m_cableReactance = v;

	dl_cableReactanceStr->ChangeValue(wxString::Format(wxT("%.2f"), m_cableReactance));
}

double userLine::userLineGetCableVoltageLimit()
{
	return m_cableVoltageLimit;
}

void userLine::userLineSetCableVoltageLimit( double v )
{
	m_cableVoltageLimit = v;

	dl_cableVoltageLimitStr->ChangeValue(wxString::Format(wxT("%.2f"), m_cableVoltageLimit));
}

void userLine::userLineRebuildEstimatedCableReactance()
{
	double			attenuation;
	double			wavelength;
	double			phase;

	wavelength = m_velocityFactor * SPEED_OF_LIGHT_F / m_frequency;
	phase = (2.0 * PI) / wavelength;
	attenuation = DB_TO_NEPERS * m_attenuation / 100.0;

	m_cableReactanceEstimate = -m_cableResistance * (attenuation / phase);
	dl_cableReactanceEstimatedStr->ChangeValue(wxString::Format(wxT("%.2f Ω"), m_cableReactanceEstimate));
}
