// Copyright Steven A. Falco <stevenfalco@gmail.com>
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
#include "theme.h"
#include "tlineIcon.h"
#include "userLine.h"

userLine::userLine( wxWindow* parent ) : userLineDialog( parent )
{
	if(g_darkMode) {
		dl_frequencyStr->SetBackgroundColour( wxColour( DARK_GRAY ) );
		dl_attenuationStr->SetBackgroundColour( wxColour( DARK_GRAY ) );
		dl_velocityFactorStr->SetBackgroundColour( wxColour( DARK_GRAY ) );
		dl_cableImpedanceStr->SetBackgroundColour( wxColour( DARK_GRAY ) );
		dl_cableResistanceStr->SetBackgroundColour( wxColour( DARK_GRAY ) );
		dl_cableReactanceStr->SetBackgroundColour( wxColour( DARK_GRAY ) );
		dl_cableVoltageLimitStr->SetBackgroundColour( wxColour( DARK_GRAY ) );
		SetForegroundColour( wxColour( WHITE ) );
		SetBackgroundColour( wxColour( BLACK ) );
	} else {
		dl_frequencyStr->SetBackgroundColour( wxColour( LIGHT_GRAY ) );
		dl_attenuationStr->SetBackgroundColour( wxColour( LIGHT_GRAY ) );
		dl_velocityFactorStr->SetBackgroundColour( wxColour( LIGHT_GRAY ) );
		dl_cableImpedanceStr->SetBackgroundColour( wxColour( LIGHT_GRAY ) );
		dl_cableResistanceStr->SetBackgroundColour( wxColour( LIGHT_GRAY ) );
		dl_cableReactanceStr->SetBackgroundColour( wxColour( LIGHT_GRAY ) );
		dl_cableVoltageLimitStr->SetBackgroundColour( wxColour( LIGHT_GRAY ) );
		SetForegroundColour( wxColour( BLACK ) );
		SetBackgroundColour( wxColour( WHITE ) );
	}

	SetIcon(wxICON(aaaa));
}

void userLine::onAttenuationSelected( wxCommandEvent& event )
{
	m_userLineAttenuationStr = event.GetString();

	// This event will be triggered by user input or by programmed changes
	// to the text.  We only want to recalculate on user input.  Otherwise,
	// previous settings won't replay correctly when reopening this dialog.
	if(dl_attenuationStr->IsModified()) {
		if(m_userLineLastMethodStr == UL_LAST_METHOD_RX_FROM_Z) {
			ResistanceReactanceFromImpedance();
		} else {
			ImpedanceFromResistanceReactance();
		}
	}
}

void userLine::onVelocityFactorSelected( wxCommandEvent& event )
{
	m_userLineVelocityFactorStr = event.GetString();

	// This event will be triggered by user input or by programmed changes
	// to the text.  We only want to recalculate on user input.  Otherwise,
	// previous settings won't replay correctly when reopening this dialog.
	if(dl_velocityFactorStr->IsModified()) {
		if(m_userLineLastMethodStr == UL_LAST_METHOD_RX_FROM_Z) {
			ResistanceReactanceFromImpedance();
		} else {
			ImpedanceFromResistanceReactance();
		}
	}
}

void userLine::onCableImpedanceSelected( wxCommandEvent& event )
{
	m_userLineCableImpedanceStr = event.GetString();

	// This event will be triggered by user input or by programmed changes
	// to the text.  We only want to recalculate on user input.  Otherwise,
	// previous settings won't replay correctly when reopening this dialog.
	if(dl_cableImpedanceStr->IsModified()) {
		ResistanceReactanceFromImpedance();
		m_userLineLastMethodStr = UL_LAST_METHOD_RX_FROM_Z;
	}
}

void userLine::onCableResistanceSelected( wxCommandEvent& event )
{
	m_userLineCableResistanceStr = event.GetString();

	// This event will be triggered by user input or by programmed changes
	// to the text.  We only want to recalculate on user input.  Otherwise,
	// previous settings won't replay correctly when reopening this dialog.
	if(dl_cableResistanceStr->IsModified()) {
		ImpedanceFromResistanceReactance();
		m_userLineLastMethodStr = UL_LAST_METHOD_Z_FROM_RX;
	}
}

void userLine::onCableReactanceSelected( wxCommandEvent& event )
{
	m_userLineCableReactanceStr = event.GetString();

	// This event will be triggered by user input or by programmed changes
	// to the text.  We only want to recalculate on user input.  Otherwise,
	// previous settings won't replay correctly when reopening this dialog.
	if(dl_cableReactanceStr->IsModified()) {
		ImpedanceFromResistanceReactance();
		m_userLineLastMethodStr = UL_LAST_METHOD_Z_FROM_RX;
	}
}

void userLine::onCableVoltageLimitSelected( wxCommandEvent& event )
{
	m_userLineCableVoltageLimitStr = event.GetString();
}

void userLine::onOkClicked( wxCommandEvent& event )
{
	if(Validate()) {
		EndModal( wxID_OK );
	}
}

void userLine::onCancelClicked( wxCommandEvent& event )
{
	if(Validate()) {
		EndModal( wxID_CANCEL );
	}
}

void userLine::ResistanceReactanceFromImpedance()
{
	double			attenuation;
	double			wavelength;
	double			phase;

	m_frequency = wxAtof(m_userLineFrequencyStr) * 1.0E6;
	m_attenuation = wxAtof(m_userLineAttenuationStr);
	m_velocityFactor = wxAtof(m_userLineVelocityFactorStr);
	m_cableImpedance = wxAtof(m_userLineCableImpedanceStr);

	wavelength = m_velocityFactor * SPEED_OF_LIGHT_F / m_frequency;
	phase = (2.0 * PI) / wavelength;
	attenuation = DB_TO_NEPERS * m_attenuation / 100.0;

	// Compute the estimated resistance, and convert to string format.
	m_cableResistance = m_cableImpedance * sqrt(1.0 / (1.0 + sq(attenuation / phase)));
	m_userLineCableResistanceStr = wxString::Format(wxT("%.2f"), m_cableResistance);
	dl_cableResistanceStr->ChangeValue(m_userLineCableResistanceStr);
	
	// Compute the estimated reactance, and convert to string format.
	m_cableReactance = -m_cableResistance * (attenuation / phase);
	m_userLineCableReactanceStr = wxString::Format(wxT("%.2f"), m_cableReactance);
	dl_cableReactanceStr->ChangeValue(m_userLineCableReactanceStr);

	dl_cableImpedanceCtlStr->SetLabel("User-Specified");
	dl_cableResistanceCtlStr->SetLabel("Calculated from Z");
	dl_cableReactanceCtlStr->SetLabel("Calculated from Z");
}

void userLine::ImpedanceFromResistanceReactance()
{
	m_cableResistance = wxAtof(m_userLineCableResistanceStr);
	m_cableReactance = wxAtof(m_userLineCableReactanceStr);

	m_cableImpedance = sqrt(sq(m_cableResistance) + sq(m_cableReactance));
	m_userLineCableImpedanceStr = wxString::Format(wxT("%.2f"), m_cableImpedance);
	dl_cableImpedanceStr->ChangeValue(m_userLineCableImpedanceStr);

	dl_cableImpedanceCtlStr->SetLabel("Calculated from R, X");
	dl_cableResistanceCtlStr->SetLabel("User-Specified");
	dl_cableReactanceCtlStr->SetLabel("User-Specified");
}

void userLine::Update()
{
	dl_frequencyStr->ChangeValue(m_userLineFrequencyStr);

	// Changing these values here will cause unwanted events.  The
	// events happen long after this code runs, so cannot use flags
	// to disambiguate wanted events from unwanted events.  Instead,
	// we have to use an IsModified() test in the event handlers to
	// reject the unwanted events.
	dl_attenuationStr->ChangeValue(m_userLineAttenuationStr);
	dl_velocityFactorStr->ChangeValue(m_userLineVelocityFactorStr);
	dl_cableImpedanceStr->ChangeValue(m_userLineCableImpedanceStr);
	dl_cableResistanceStr->ChangeValue(m_userLineCableResistanceStr);
	dl_cableReactanceStr->ChangeValue(m_userLineCableReactanceStr);
	dl_cableVoltageLimitStr->ChangeValue(m_userLineCableVoltageLimitStr);

	// Frequency may have changed on the home screen, in which case
	// we need to recalculate.
	if(m_userLineLastMethodStr == UL_LAST_METHOD_RX_FROM_Z) {
		ResistanceReactanceFromImpedance();
	} else {
		ImpedanceFromResistanceReactance();
	}
}
