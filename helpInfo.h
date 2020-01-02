// Copyright 2019,2020 Steven A. Falco <stevenfalco@gmail.com>
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

#ifndef __helpInfo__
#define __helpInfo__

#include "tlineUI.h"

class helpInfo : public helpInfoDialog
{
	public:
		helpInfo( wxWindow* parent );

		void helpInfoLoadPage( wxString s );
		void helpInfoSetPage( wxString s );

	private:
		void onLinkClicked( wxHtmlLinkEvent& event );
		void onHelpInfoOK( wxCommandEvent& event );
};

#endif // __helpInfo__
