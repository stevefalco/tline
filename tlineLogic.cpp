#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include "tlineLogic.h"
#include "cableTypes.h"

tlineLogic::tlineLogic( wxWindow* parent ) : tlineUI( parent )
{
	m_programTitle->SetLabel("Transmission Line Calculator");
}

void tlineLogic::onCableTypeSelected( wxCommandEvent& event )
{
	cableTypes* c = new cableTypes;
	wxString v = event.GetString();
	CABLE_PROPERTIES *cp = c->findCable(v.mb_str());

	if(cp) {
		wxLogMessage("velocity factor %f", cp->velocityFactor);
	} else {
		wxLogMessage("no such cable");
	}
}

void tlineLogic::onFileExit( wxCommandEvent& event )
{
	//wxLogMessage("got exit event %d", event.GetInt());
	// Could check for dirty and request save before exiting here.
	Destroy();
}
