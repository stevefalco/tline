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

#include "helpAbout.h"
#include "theme.h"
#include "tlineIcon.h"

helpAbout::helpAbout( wxWindow* parent ) : helpAboutDialog( parent )
{
	if(g_darkMode) {
		SetForegroundColour( wxColour( WHITE ) );
		SetBackgroundColour( wxColour( BLACK ) );
	} else {
		SetForegroundColour( wxColour( BLACK ) );
		SetBackgroundColour( wxColour( WHITE ) );
	}

	SetIcon(wxICON(aaaa));
}

void helpAbout::helpAboutAddTextLine1( const wxString& s )
{
	dl_helpAboutTextLine1->SetLabel(s);
}

void helpAbout::helpAboutAddTextLine2( const wxString& s )
{
	dl_helpAboutTextLine2->SetLabel(s);
}

void helpAbout::helpAboutAddTextLine3( const wxString& s )
{
	dl_helpAboutTextLine3->SetLabel(s);
}

void helpAbout::helpAboutAddTextLine4( const wxString& s )
{
	dl_helpAboutTextLine4->SetLabel(s);
}

void helpAbout::onHelpAboutOK( wxCommandEvent& event )
{
	if ( Validate() )
	{
		EndModal( wxID_OK );
	}
}
