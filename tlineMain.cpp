#include <wx/wx.h>
#include "tlineLogic.h"

class tlineMain: public wxApp {

public:
	tlineMain() {}
	virtual ~tlineMain() {}
	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP (tlineMain);

inline bool tlineMain::OnInit() {
	wxFrame* mainFrame = new tlineLogic(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}

