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
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/valtext.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/html/htmlwin.h>
#include <wx/statbmp.h>

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
		wxStaticText* ui_updateWarning;
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
		wxStaticText* ui_matchedLineLossTag;
		wxTextCtrl* ui_matchedLineLoss;
		wxStaticText* ui_totalMatchedLineLossTag;
		wxTextCtrl* ui_totalMatchedLineLoss;
		wxStaticText* ui_addedLossTag;
		wxTextCtrl* ui_addedLoss;
		wxStaticText* ui_totalLossTag;
		wxTextCtrl* ui_totalLoss;
		wxStaticText* ui_impedanceRectangularTag;
		wxTextCtrl* ui_impedanceRectangular;
		wxStaticText* ui_impedancePolarTag;
		wxTextCtrl* ui_impedancePolar;
		wxStaticText* ui_characteristicZ0Tag;
		wxTextCtrl* ui_characteristicZ0;
		wxStaticText* ui_velocityFactorTag;
		wxTextCtrl* ui_velocityFactor;
		wxStaticText* ui_maxVoltageTag;
		wxTextCtrl* ui_maxVoltage;
		wxStaticText* ui_swrInputTag;
		wxTextCtrl* ui_swrInput;
		wxStaticText* ui_swrLoadTag;
		wxTextCtrl* ui_swrLoad;
		wxStaticText* ui_rhoLoadTag;
		wxTextCtrl* ui_rhoLoad;

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
		wxString m_lengthStr;
		wxString m_frequencyStr;
		wxString m_powerStr;
		wxString m_resistanceStr;
		wxString m_reactanceStr;

		tlineUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("tline"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 850,570 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

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
		wxStaticText* dl_hiddenPadFQ;
		wxStaticText* dl_attenuationTag;
		wxTextCtrl* dl_attenuationStr;
		wxStaticText* dl_hiddenPadATTN;
		wxStaticText* dl_velocityFactorTag;
		wxTextCtrl* dl_velocityFactorStr;
		wxStaticText* dl_hiddenPadVF;
		wxStaticText* dl_cableImpedanceTag;
		wxTextCtrl* dl_cableImpedanceStr;
		wxStaticText* dl_cableImpedanceCtlStr;
		wxStaticText* dl_cableResistanceTag;
		wxTextCtrl* dl_cableResistanceStr;
		wxStaticText* dl_cableResistanceCtlStr;
		wxStaticText* dl_cableReactanceTag;
		wxTextCtrl* dl_cableReactanceStr;
		wxStaticText* dl_cableReactanceCtlStr;
		wxStaticText* dl_cableVoltageLimitTag;
		wxTextCtrl* dl_cableVoltageLimitStr;
		wxStaticText* dl_hiddenPadVL;
		wxStaticText* dl_hiddenPadBTN;
		wxButton* dl_okButton;
		wxButton* dl_cancelButton;
		wxStaticText* dl_help;

		// Virtual event handlers, overide them in your derived class
		virtual void onAttenuationSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onVelocityFactorSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableImpedanceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableResistanceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableReactanceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableVoltageLimitSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOkClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCancelClicked( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxString m_userLineFrequencyStr;
		wxString m_userLineAttenuationStr;
		wxString m_userLineVelocityFactorStr;
		wxString m_userLineCableImpedanceStr;
		wxString m_userLineCableResistanceStr;
		wxString m_userLineCableReactanceStr;
		wxString m_userLineCableVoltageLimitStr;

		userLineDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("User Defined Line"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 750,450 ), long style = wxDEFAULT_DIALOG_STYLE );
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
		wxButton* dl_helpInfoOk;

		// Virtual event handlers, overide them in your derived class
		virtual void onLinkClicked( wxHtmlLinkEvent& event ) { event.Skip(); }
		virtual void onHelpInfoOK( wxCommandEvent& event ) { event.Skip(); }


	public:

		helpInfoDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
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

		helpAboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,200 ), long style = wxDEFAULT_DIALOG_STYLE );
		~helpAboutDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class tunerDialog
///////////////////////////////////////////////////////////////////////////////
class tunerDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* dl_tunerFrequencyTag;
		wxTextCtrl* dl_tunerFrequency;
		wxStaticText* dl_tunerPowerTag;
		wxTextCtrl* dl_tunerPower;
		wxStaticText* dl_tunerSourceResistanceTag;
		wxTextCtrl* dl_tunerSourceResistance;
		wxStaticText* dl_tunerSourceReactanceTag;
		wxTextCtrl* dl_tunerSourceReactance;
		wxStaticText* dl_tunerLoadResistanceTag;
		wxTextCtrl* dl_tunerLoadResistance;
		wxStaticText* dl_tunerLoadReactanceTag;
		wxTextCtrl* dl_tunerLoadReactance;
		wxStaticText* dl_tunerInductorQTag;
		wxTextCtrl* dl_tunerInductorQ;
		wxStaticText* dl_tunerCapacitorQTag;
		wxTextCtrl* dl_tunerCapacitorQ;
		wxStaticText* dl_tunerNetworkQTag;
		wxTextCtrl* dl_tunerNetworkQ;
		wxStaticBoxSizer* sbTunerResults1;
		wxStaticText* dl_tunerResultTag1;
		wxTextCtrl* dl_tunerResult1;
		wxStaticText* dl_tunerResultTag2;
		wxTextCtrl* dl_tunerResult2;
		wxStaticText* dl_tunerResultTag3;
		wxTextCtrl* dl_tunerResult3;
		wxStaticText* dl_tunerResultTag4;
		wxTextCtrl* dl_tunerResult4;
		wxStaticBoxSizer* sbTunerResults2;
		wxStaticText* dl_tunerResultTag5;
		wxTextCtrl* dl_tunerResult5;
		wxStaticText* dl_tunerResultTag6;
		wxTextCtrl* dl_tunerResult6;
		wxStaticText* dl_tunerResultTag7;
		wxTextCtrl* dl_tunerResult7;
		wxStaticText* dl_tunerResultTag8;
		wxTextCtrl* dl_tunerResult8;
		wxStaticBoxSizer* sbTunerResults3;
		wxStaticText* dl_tunerResultTag9;
		wxTextCtrl* dl_tunerResult9;
		wxStaticText* dl_tunerResultTag10;
		wxTextCtrl* dl_tunerResult10;
		wxStaticText* dl_tunerResultTag11;
		wxTextCtrl* dl_tunerResult11;
		wxStaticText* dl_tunerResultTag12;
		wxTextCtrl* dl_tunerResult12;
		wxRadioBox* dl_topology;
		wxStaticBitmap* dl_bitmap;
		wxStaticBoxSizer* sbTunerStatus;
		wxStaticText* dl_tunerStatusTag0;
		wxStaticText* dl_tunerStatus0;
		wxStaticText* dl_tunerStatusTag1;
		wxStaticText* dl_tunerStatus1;
		wxStaticText* dl_tunerStatusTag2;
		wxStaticText* dl_tunerStatus2;
		wxStaticText* dl_tunerStatusTag3;
		wxStaticText* dl_tunerStatus3;
		wxStaticText* dl_tunerStatusTag4;
		wxStaticText* dl_tunerStatus4;
		wxStaticText* dl_tunerStatusTag5;
		wxStaticText* dl_tunerStatus5;
		wxStaticText* dl_tunerStatusTag6;
		wxStaticText* dl_tunerStatus6;
		wxStaticText* dl_tunerParameterNote;
		wxStaticText* dl_tunerTopologyNote;
		wxButton* dl_tunerOKbutton;
		wxStaticText* dl_tunerInfo;

		// Virtual event handlers, overide them in your derived class
		virtual void onTunerFrequency( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerPower( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerSourceResistance( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerSourceReactance( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerLoadResistance( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerLoadReactance( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerInductorQ( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerCapacitorQ( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerNetworkQ( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerTopologySelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTunerOKclicked( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxString m_tunerFrequencyStr;
		wxString m_tunerPowerStr;
		wxString m_tunerSourceResistanceStr;
		wxString m_tunerSourceReactanceStr;
		wxString m_tunerLoadResistanceStr;
		wxString m_tunerLoadReactanceStr;
		wxString m_tunerInductorQStr;
		wxString m_tunerCapacitorQStr;
		wxString m_tunerNetworkQStr;

		tunerDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Tuner Calculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 930,740 ), long style = wxDEFAULT_DIALOG_STYLE );
		~tunerDialog();

};

