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

#include "tuner.h"

tuner::tuner( wxWindow* parent ) : tunerDialog( parent )
{
}

void tuner::SetFrequency( double frequency )
{
	m_frequency = frequency;
}

void tuner::onSourceResistance( wxCommandEvent& event )
{
// TODO: Implement onSourceResistance
}

void tuner::onSourceReactance( wxCommandEvent& event )
{
// TODO: Implement onSourceReactance
}

void tuner::onLoadResistance( wxCommandEvent& event )
{
// TODO: Implement onLoadResistance
}

void tuner::onLoadReactance( wxCommandEvent& event )
{
// TODO: Implement onLoadReactance
}

void tuner::onQ( wxCommandEvent& event )
{
// TODO: Implement onQ
}

void tuner::onTUnerQSelected( wxCommandEvent& event )
{
// TODO: Implement onTUnerQSelected
}

void tuner::onTunerTopologySelected( wxCommandEvent& event )
{
// TODO: Implement onTunerTopologySelected
}

void tuner::onTunerCalculateClicked( wxCommandEvent& event )
{
// TODO: Implement onTunerCalculateClicked
}

void tuner::onTunerOKclicked( wxCommandEvent& event )
{
	if ( Validate() )
	{
		EndModal( wxID_OK );
	}
}
