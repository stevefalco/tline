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
	recalculate();
}

void tuner::SetFrequency( double frequency )
{
	m_frequency = frequency;
}

void tuner::onSourceResistance( wxCommandEvent& event )
{
	m_sourceResistance = atof(event.GetString());

	recalculate();
}

void tuner::onSourceReactance( wxCommandEvent& event )
{
	m_sourceReactance = atof(event.GetString());

	recalculate();
}

void tuner::onLoadResistance( wxCommandEvent& event )
{
	m_loadResistance = atof(event.GetString());

	recalculate();
}

void tuner::onLoadReactance( wxCommandEvent& event )
{
	m_loadReactance = atof(event.GetString());

	recalculate();
}

void tuner::onQ( wxCommandEvent& event )
{
	m_desiredQ = atof(event.GetString());

	recalculate();
}

void tuner::onTunerTopologySelected( wxCommandEvent& event )
{
	m_topology = event.GetString();

	recalculate();
}

void tuner::recalculate()
{

	if(strcmp(m_topology, "High Pass (Lpar Cser)") == 0) {
		LCHP();
	} else if(strcmp(m_topology, "Low Pass (Cpar Lser)") == 0) {
		CLLP();
	} else if(strcmp(m_topology, "Low Pass (Lser Cpar)") == 0) {
		LCLP();
	} else if(strcmp(m_topology, "High Pass (Cser Lpar)") == 0) {
		CLHP();
	} else if(strcmp(m_topology, "High Pass PI (Lpar Cser Lpar)") == 0) {
		HPPI();
	} else if(strcmp(m_topology, "Low Pass PI (Cpar Lser Cpar)") == 0) {
		LPPI();
	} else if(strcmp(m_topology, "High Pass T (Cser Lpar Cser)") == 0) {
		HPT();
	} else if(strcmp(m_topology, "Low Pass T (Lser Cpar Lser)") == 0) {
		LPT();
	} else if(strcmp(m_topology, "High Pass (Lpar Cser Lpar Cser)") == 0) {
		HP1LL();
	} else if(strcmp(m_topology, "High Pass (Cser Lpar Cser Lpar)") == 0) {
		HP2LL();
	} else if(strcmp(m_topology, "Low Pass (Cpar Lser Cpar Lser)") == 0) {
		LP1LL();
	} else if(strcmp(m_topology, "Low Pass (Lser Cpar Lser Cpar)") == 0) {
		LP2LL();
	} else if(strcmp(m_topology, "Band Pass (Lpar Cser Cpar Lser)") == 0) {
		BP1LL();
	} else if(strcmp(m_topology, "Band Pass (Lser Cpar Cser Lpar)") == 0) {
		BP2LL();
	} else if(strcmp(m_topology, "Band Pass (Cpar Lser Lpar Cser)") == 0) {
		BP3LL();
	} else if(strcmp(m_topology, "Band Pass (Cser Lpar Lser Cpar)") == 0) {
		BP4LL();
	}
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
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lchp);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::CLLP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_cllp);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::LCLP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lclp);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::CLHP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_clhp);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::HPPI()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_hppi);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::LPPI()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lppi);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::HPT()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_hpt);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::LPT()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lpt);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::HP1LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_hp1ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::HP2LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_hp2ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::LP1LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lp1ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::LP2LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lp2ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::BP1LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_bp1ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::BP2LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_bp2ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::BP3LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_bp3ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
void tuner::BP4LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_bp4ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}
}
