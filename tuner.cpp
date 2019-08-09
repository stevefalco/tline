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
#include <wx/log.h>

#include "build/nt_bp1ll.h"
#include "build/nt_bp2ll.h"
#include "build/nt_bp3ll.h"
#include "build/nt_clhp.h"
#include "build/nt_bp4ll.h"
#include "build/nt_hppi.h"
#include "build/nt_hp2ll.h"
#include "build/nt_hp1ll.h"
#include "build/nt_cllp.h"
#include "build/nt_hpt.h"
#include "build/nt_lclp.h"
#include "build/nt_lchp.h"
#include "build/nt_lp2ll.h"
#include "build/nt_lp1ll.h"
#include "build/nt_lpt.h"
#include "build/nt_lppi.h"

tuner::tuner( wxWindow* parent ) : tunerDialog( parent )
{
}

void tuner::SetFrequency( double frequency )
{
	m_frequency = frequency;
}

void tuner::onSourceResistance( wxCommandEvent& event )
{
	m_sourceResistance = atof(event.GetString());
}

void tuner::onSourceReactance( wxCommandEvent& event )
{
	m_sourceReactance = atof(event.GetString());
}

void tuner::onLoadResistance( wxCommandEvent& event )
{
	m_loadResistance = atof(event.GetString());
}

void tuner::onLoadReactance( wxCommandEvent& event )
{
	m_loadReactance = atof(event.GetString());
}

void tuner::onQ( wxCommandEvent& event )
{
	m_desiredQ = atof(event.GetString());
}

void tuner::onTunerTopologySelected( wxCommandEvent& event )
{
	wxString s = event.GetString();

	wxLogError("type %s", s);

	if(strcmp(s, "High Pass (Lpar Cser)") == 0) {
		LCHP();
	} else if(strcmp(s, "Low Pass (Cpar Lser)") == 0) {
	} else if(strcmp(s, "Low Pass (Lser Cpar)") == 0) {
	} else if(strcmp(s, "High Pass (Cser Lpar)") == 0) {
	} else if(strcmp(s, "High Pass PI (Lpar Cser Lpar)") == 0) {
	} else if(strcmp(s, "Low Pass PI (Cpar Lser Cpar)") == 0) {
	} else if(strcmp(s, "High Pass T (Cser Lpar Cser)") == 0) {
	} else if(strcmp(s, "Low Pass T (Lser Cpar Lser)") == 0) {
	} else if(strcmp(s, "High Pass (Lpar Cser Lpar Cser)") == 0) {
	} else if(strcmp(s, "High Pass (Cser Lpar Cser Lpar)") == 0) {
	} else if(strcmp(s, "Low Pass (Cpar Lser Cpar Lser)") == 0) {
	} else if(strcmp(s, "Low Pass (Lser Cpar Lser Cpar)") == 0) {
	} else if(strcmp(s, "Band Pass (Lpar Cser Cpar Lser)") == 0) {
	} else if(strcmp(s, "Band Pass (Lser Cpar Cser Lpar)") == 0) {
	} else if(strcmp(s, "Band Pass (Cpar Lser Lpar Cser)") == 0) {
	} else if(strcmp(s, "Band Pass (Cser Lpar Lser Cpar)") == 0) {
	} else {
	}
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

void tuner::LCHP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_bp1ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
