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
		wxMenuBar* ui_menubar;
		wxMenu* fileMenu;
		wxMenuItem* ui_fileMenuExit;
		wxMenu* helpMenu;
		wxStaticText* ui_programTitle;
		wxComboBox* ui_cableType;
		wxRadioBox* ui_unitsRadioButtons;
		wxStaticText* ui_cableLengthTag;
		wxTextCtrl* ui_cableLength;
		wxStaticText* ui_lengthUnits;
		wxStaticText* ui_lambdaTag;
		wxTextCtrl* ui_lambda;
		wxStaticText* ui_frequencyTag;
		wxTextCtrl* ui_frequency;
		wxStaticText* ui_frequencyUnits;
		wxStaticText* ui_wSuffixNote;
		wxStaticText* ui_characteristicZ0Tag;
		wxTextCtrl* ui_characteristicZ0;
		wxStaticText* ui_matchedLineLossTag;
		wxTextCtrl* ui_matchedLineLoss;
		wxStaticText* ui_matchedLineLossUnits;
		wxStaticText* ui_velocityFactorTag;
		wxTextCtrl* ui_velocityFactor;
		wxStaticText* ui_maxVoltageTag;
		wxTextCtrl* ui_maxVoltage;
		wxStaticText* ui_maxVoltageUnits;
		wxStaticText* ui_totalMatchedLineLossTag;
		wxTextCtrl* ui_totalMatchedLineLoss;
		wxStaticText* ui_totalMatchedLineLossUnits;
		wxRadioBox* ui_sourceRadioButtons;
		wxRadioBox* ui_loadInputRadioButtons;
		wxStaticText* ui_resistanceTag;
		wxTextCtrl* ui_resistance;
		wxStaticText* ui_resistanceUnits;
		wxStaticText* ui_reactanceTag;
		wxTextCtrl* ui_reactance;
		wxStaticText* ui_reactanceUnits;
		wxButton* ui_graphVI;
		wxButton* ui_graphZ;
		wxButton* ui_tuner;
		wxStaticText* ui_swrInputTag;
		wxTextCtrl* ui_swrInput;
		wxStaticText* ui_swrLoadTag;
		wxTextCtrl* ui_swrLoad;
		wxStaticText* ui_rhoLoadTag;
		wxTextCtrl* ui_rhoLoad;
		wxStaticText* ui_addedLossTag;
		wxTextCtrl* ui_addedLoss;
		wxStaticText* ui_addedLossUnits;
		wxStaticText* ui_totalLossTag;
		wxTextCtrl* ui_totalLoss;
		wxStaticText* ui_totalLossUnits;
		wxStaticText* ui_impedanceRectangularTag;
		wxTextCtrl* ui_impedanceRectangular;
		wxStaticText* ui_impedancePolarTag;
		wxTextCtrl* ui_impedancePolar;

		// Virtual event handlers, overide them in your derived class
		virtual void onFileLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFileSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFileExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableTypeSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onUnitsSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLengthSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFrequencySelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLoadInputSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onResistanceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onReactanceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onGraphVIClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onGraphZClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		tlineUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("tline"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 844,604 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~tlineUI();

};

