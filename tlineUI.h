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
#include <wx/statbox.h>
#include <wx/button.h>
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
		wxStaticText* m_resistanceTag;
		wxTextCtrl* m_resistance;
		wxStaticText* m_resistanceUnits;
		wxStaticText* m_reactanceTag;
		wxTextCtrl* m_reactance;
		wxStaticText* m_reactanceUnits;
		wxButton* m_button1;
		wxButton* m_button5;
		wxButton* m_button2;
		wxStaticText* m_swrInputTag;
		wxTextCtrl* m_swrInput;
		wxStaticText* m_swrLoadTag;
		wxTextCtrl* m_swrLoad;
		wxStaticText* m_rhoLoadTag;
		wxTextCtrl* m_rhoLoad;
		wxStaticText* m_addedLossTag;
		wxTextCtrl* m_addedLoss;
		wxStaticText* m_addedLossUnits;
		wxStaticText* m_totalLossTag;
		wxTextCtrl* m_totalLoss;
		wxStaticText* m_totalLossUnits;
		wxStaticText* m_impedanceRectangularTag;
		wxTextCtrl* m_impedanceRectangular;
		wxStaticText* m_impedanceRectangularUnits;
		wxStaticText* m_impedancePolarTag;
		wxTextCtrl* m_impedancePolar;
		wxStaticText* m_impedancePolarUnits;

		// Virtual event handlers, overide them in your derived class
		virtual void onFileExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableTypeSelected( wxCommandEvent& event ) { event.Skip(); }


	public:

		tlineUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("tline"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 844,604 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~tlineUI();

};

