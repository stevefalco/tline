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
#include <wx/dialog.h>
#include <wx/html/htmlwin.h>

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
		wxStaticText* ui_powerTag;
		wxTextCtrl* ui_power;
		wxStaticText* ui_powerUnits;
		wxStaticText* ui_inputVoltageTag;
		wxTextCtrl* ui_inputVoltage;
		wxRadioBox* ui_loadInputRadioButtons;
		wxStaticText* ui_resistanceTag;
		wxTextCtrl* ui_resistance;
		wxStaticText* ui_resistanceUnits;
		wxStaticText* ui_reactanceTag;
		wxTextCtrl* ui_reactance;
		wxStaticText* ui_reactanceUnits;
		wxButton* ui_plotZ;
		wxButton* ui_plotVI;
		wxButton* ui_tuner;
		wxButton* ui_saveZplot;
		wxButton* ui_saveVIplot;
		wxButton* ui_saveData;
		wxStaticText* ui_characteristicZ0Tag;
		wxTextCtrl* ui_characteristicZ0;
		wxStaticText* ui_matchedLineLossTag;
		wxTextCtrl* ui_matchedLineLoss;
		wxStaticText* ui_velocityFactorTag;
		wxTextCtrl* ui_velocityFactor;
		wxStaticText* ui_maxVoltageTag;
		wxTextCtrl* ui_maxVoltage;
		wxStaticText* ui_totalMatchedLineLossTag;
		wxTextCtrl* ui_totalMatchedLineLoss;
		wxStaticText* ui_swrInputTag;
		wxTextCtrl* ui_swrInput;
		wxStaticText* ui_swrLoadTag;
		wxTextCtrl* ui_swrLoad;
		wxStaticText* ui_rhoLoadTag;
		wxTextCtrl* ui_rhoLoad;
		wxStaticText* ui_addedLossTag;
		wxTextCtrl* ui_addedLoss;
		wxStaticText* ui_totalLossTag;
		wxTextCtrl* ui_totalLoss;
		wxStaticText* ui_impedanceRectangularTag;
		wxTextCtrl* ui_impedanceRectangular;
		wxStaticText* ui_impedancePolarTag;
		wxTextCtrl* ui_impedancePolar;

		// Virtual event handlers, overide them in your derived class
		virtual void onFileLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFileSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFileExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelpInfo( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelpAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableTypeSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onUnitsSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLengthSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFrequencySelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPowerSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLoadInputSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onResistanceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onReactanceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPlotZclicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPlotVIclicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSavePlotZclicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSavePlotVIclicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSaveDataClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		tlineUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("tline"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 920,615 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~tlineUI();

};

///////////////////////////////////////////////////////////////////////////////
/// Class userLineDialog
///////////////////////////////////////////////////////////////////////////////
class userLineDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* dl_frequencyTag;
		wxTextCtrl* dl_frequencyStr;
		wxStaticText* dl_attenuationTag;
		wxTextCtrl* dl_attenuationStr;
		wxStaticText* dl_velocityFactorTag;
		wxTextCtrl* dl_velocityFactorStr;
		wxStaticText* dl_cableResistanceTag;
		wxTextCtrl* dl_cableResistanceStr;
		wxStaticText* dl_cableReactanceEstimatedTag;
		wxStaticText* dl_cableReactanceTag;
		wxTextCtrl* dl_cableReactanceStr;
		wxTextCtrl* dl_cableReactanceEstimatedStr;
		wxStaticText* dl_cableVoltageLimitTag;
		wxTextCtrl* dl_cableVoltageLimitStr;
		wxButton* dl_useEstimatedReactanceButton;
		wxStaticText* dl_hiddenPad;
		wxButton* dl_okButton;

		// Virtual event handlers, overide them in your derived class
		virtual void onAttenuationSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onVelocityFactorSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableResistanceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableReactanceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableVoltageLimitSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onUseEstimatedReactanceClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOkClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		userLineDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 828,310 ), long style = wxDEFAULT_DIALOG_STYLE );
		~userLineDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class helpInfoDialog
///////////////////////////////////////////////////////////////////////////////
class helpInfoDialog : public wxDialog
{
	private:

	protected:
		wxHtmlWindow* dl_htmlWindow;

		// Virtual event handlers, overide them in your derived class
		virtual void onLinkClicked( wxHtmlLinkEvent& event ) { event.Skip(); }


	public:

		helpInfoDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,600 ), long style = wxDEFAULT_DIALOG_STYLE );
		~helpInfoDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class helpAboutDialog
///////////////////////////////////////////////////////////////////////////////
class helpAboutDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* dl_helpAboutTextLine1;
		wxStaticText* dl_helpAboutTextLine2;
		wxStaticText* dl_helpAboutTextLine3;
		wxStaticText* dl_helpAboutTextLine4;
		wxButton* dl_helpAboutOk;

		// Virtual event handlers, overide them in your derived class
		virtual void onHelpAboutOK( wxCommandEvent& event ) { event.Skip(); }


	public:

		helpAboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 495,194 ), long style = wxDEFAULT_DIALOG_STYLE );
		~helpAboutDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class tunerDialog
///////////////////////////////////////////////////////////////////////////////
class tunerDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* dl_tunerSourceResistanceTag;
		wxTextCtrl* dl_tunerSourceResistance;
		wxStaticText* dl_tunerSourceReactanceTag;
		wxTextCtrl* dl_tunerSourceReactance;
		wxStaticText* dl_tunerLoadResistanceTag;
		wxTextCtrl* dl_tunerLoadResistance;
		wxStaticText* dl_tunerLoadReactanceTag;
		wxTextCtrl* dl_tunerLoadReactance;
		wxStaticText* dl_tunerQtag;
		wxTextCtrl* dl_tunerQ;
		wxStaticText* dl_tunerFrequencyTag;
		wxTextCtrl* dl_tunerFrequency;
		wxStaticText* dl_tunerParameterNote;
		wxStaticText* dl_tunerTopologyNote;
		wxRadioBox* dl_topology;
		wxButton* dl_tunerCalculateButton;
		wxButton* dl_tunerOKbutton;
		wxStaticText* dl_tunerCredit;

		// Virtual event handlers, overide them in your derived class
		virtual void onSourceResistance( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSourceReactance( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLoadResistance( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLoadReactance( wxCommandEvent& event ) { event.Skip(); }
		virtual void onQ( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerTopologySelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerCalculateClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerOKclicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		tunerDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 750,750 ), long style = wxDEFAULT_DIALOG_STYLE );
		~tunerDialog();

};

