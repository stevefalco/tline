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

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include <wx/cmdline.h>

#include "dragDrop.h"
#include "tlineLogic.h"

class tlineMain: public wxApp {
	public:
		tlineMain() {}
		virtual ~tlineMain() {}
		virtual bool OnInit();
		virtual int OnExit();
		virtual void OnInitCmdLine(wxCmdLineParser& parser);
		virtual bool OnCmdLineParsed(wxCmdLineParser& parser);

	private:
		wxString m_file = "";
};

static const wxCmdLineEntryDesc g_cmdLineDesc[] =
{
	{ wxCMD_LINE_SWITCH, "h", "help", "This help message.",
		wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
	{ wxCMD_LINE_PARAM, NULL, NULL, "optional_saved_parameter_file.tline",
		wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
	{ wxCMD_LINE_NONE }
};

IMPLEMENT_APP (tlineMain);

inline bool tlineMain::OnInit() {
	if(!wxApp::OnInit()) {
		return false;
	}

	// The main frame will be owned by the wxWidgets library, and will
	// be deleted by the library when appropriate.
	wxFrame* mainFrame = new tlineLogic(NULL, m_file);
	mainFrame->SetDropTarget(new DnDFile(mainFrame));
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}

int tlineMain::OnExit()
{
	return 0;
}

void tlineMain::OnInitCmdLine(wxCmdLineParser& parser)
{
	parser.SetDesc(g_cmdLineDesc);
	parser.SetSwitchChars(wxT("-"));
}

bool tlineMain::OnCmdLineParsed(wxCmdLineParser& parser)
{
	if(parser.GetParamCount() > 0) {
		m_file = parser.GetParam(0);
	}

	return true;
}
