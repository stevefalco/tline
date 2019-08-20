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

#ifndef __userLine__
#define __userLine__

#include "tlineUI.h"

class userLine : public userLineDialog
{
	public:
		userLine( wxWindow* parent );

		void Update();

	private:
		void onAttenuationSelected( wxCommandEvent& event );
		void onVelocityFactorSelected( wxCommandEvent& event );
		void onCableResistanceSelected( wxCommandEvent& event );
		void onCableReactanceSelected( wxCommandEvent& event );
		void onCableVoltageLimitSelected( wxCommandEvent& event );

		void onOkClicked( wxCommandEvent& event );
		void onCancelClicked( wxCommandEvent& event );
		void onUseEstimatedReactanceClicked( wxCommandEvent& event );

		double m_frequency;
		double m_attenuation;
		double m_velocityFactor;
		double m_cableResistance;
		double m_cableReactanceEstimate;

		wxString m_cableReactanceEstimateStr;
};

#endif // __userLine__
