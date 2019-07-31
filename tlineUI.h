///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jul 30 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class tlineUI
///////////////////////////////////////////////////////////////////////////////
class tlineUI : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar;
		wxMenu* fileMenu;
		wxMenuItem* m_fileMenuExit;
		wxMenu* helpMenu;
		wxStaticText* m_programTitle;
		wxComboBox* m_cableType;
		wxRadioBox* m_unitsRadioButtons;
		wxStaticText* m_cableLengthTag;
		wxTextCtrl* m_cableLength;
		wxStaticText* m_lengthUnits;
		wxStaticText* m_lambdaTag;
		wxTextCtrl* m_lambda;
		wxStaticText* m_frequencyTag;
		wxTextCtrl* m_frequency;
		wxStaticText* m_frequencyUnits;
		wxStaticText* m_wSuffixNote;
		wxStaticText* m_characteristicZ0Tag;
		wxTextCtrl* m_characteristicZ0;
		wxStaticText* m_matchedLineLossTag;
		wxTextCtrl* m_matchedLineLoss;
		wxStaticText* m_matchedLineLossUnits;
		wxStaticText* m_velocityFactorTag;
		wxTextCtrl* m_velocityFactor;
		wxStaticText* m_maxVoltageTag;
		wxTextCtrl* m_maxVoltage;
		wxStaticText* m_maxVoltageUnits;
		wxStaticText* m_totalMatchedLineLossTag;
		wxTextCtrl* m_totalMatchedLineLoss;
		wxStaticText* m_totalMatchedLineLossUnits;
		wxRadioBox* m_sourceRadioButtons;
		wxRadioBox* m_loadInputRadioButtons;
		wxStaticText* m_staticText16;
		wxStaticText* m_staticText17;

		// Virtual event handlers, overide them in your derived class
		virtual void onFileExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableTypeSelected( wxCommandEvent& event ) { event.Skip(); }


	public:

		tlineUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("tline"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 844,604 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~tlineUI();

};

