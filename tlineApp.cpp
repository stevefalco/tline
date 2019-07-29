/***************************************************************
 * Name:      tlineApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Dedy Yasriady (yasriady@yahoo.com)
 * Created:   2014-04-20
 * Copyright: Dedy Yasriady (http://yasriady.blogspot.com)
 * License:
 **************************************************************/

#include <wx/wx.h>
#include "tlineLogic.h"

class tlineApp: public wxApp {

public:
	tlineApp() {}
	virtual ~tlineApp() {}
	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP (tlineApp);

inline bool tlineApp::OnInit() {
	//Init main Frame
	wxFrame* mainFrame = new tlineLogic(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}

