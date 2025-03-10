///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6-dirty)
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

#define ct_Andrew_Braided_CNT_100 10000
#define ct_Andrew_Braided_CNT_195 10001
#define ct_Andrew_Braided_CNT_240 10002
#define ct_Andrew_Braided_CNT_300 10003
#define ct_Andrew_Braided_CNT_400 10004
#define ct_Andrew_Braided_CNT_600 10005
#define ct_Andrew_Heliax_LDF4_50A 10006
#define ct_Andrew_Heliax_LDF5_50A 10007
#define ct_Andrew_Heliax_LDF6_50 10008
#define ct_Belden_8215 10009
#define ct_Belden_7915A 10010
#define ct_Belden_9116 10011
#define ct_Belden_8237 10012
#define ct_Belden_9251 10013
#define ct_Belden_9913 10014
#define ct_Belden_9913F7 10015
#define ct_Belden_9914 10016
#define ct_Belden_9258 10017
#define ct_Belden_8213 10018
#define ct_Belden_8238 10019
#define ct_Belden_8261 10020
#define ct_Belden_9212 10021
#define ct_Belden_8219 10022
#define ct_Belden_8240 10023
#define ct_Belden_8259 10024
#define ct_Belden_8262 10025
#define ct_Belden_9201 10026
#define ct_Belden_8212 10027
#define ct_Belden_8241 10028
#define ct_Belden_8263 10029
#define ct_Belden_9269 10030
#define ct_Belden_9857 10031
#define ct_Belden_83242 10032
#define ct_Belden_7805 10033
#define ct_Belden_8216 10034
#define ct_Belden_83265 10035
#define ct_Belden_83269 10036
#define ct_Belden_8267 10037
#define ct_Belden_8268 10038
#define ct_Belden_84303 10039
#define ct_Belden_84316 10040
#define ct_CommScope_2427K 10041
#define ct_CommScope_3227 10042
#define ct_Davis_RF_Bury_Flex 10043
#define ct_DX_Engineering_RG_8 10044
#define ct_DX_Engineering_RG_8X 10045
#define ct_DX_Engineering_RG_11 10046
#define ct_DX_Engineering_RG_58A 10047
#define ct_DX_Engineering_RG_213 10048
#define ct_DX_Engineering_RG_214 10049
#define ct_DX_Engineering_RG_400 10050
#define ct_DX_Engineering_DXE_400MAX 10051
#define ct_DX_Engineering_300_Ohm_LL 10052
#define ct_DX_Eng_300_Ohm_LL_wet 10053
#define ct_Pasternack_RG_142 10054
#define ct_Pasternack_RG_218 10055
#define ct_Radioware_RG_6 10056
#define ct_Radioware_RG_8X 10057
#define ct_Radioware_RG_11 10058
#define ct_Radioware_RG_58 10059
#define ct_Radioware_RG_174 10060
#define ct_Radioware_RG_213 10061
#define ct_Radioware_RF_9913 10062
#define ct_Radioware_RF_9914F 10063
#define ct_Tandy_Cable_RG_8X 10064
#define ct_Tandy_Cable_RG_58 10065
#define ct_Tandy_Cable_RG_59 10066
#define ct_Times_LMR_100A 10067
#define ct_Times_LMR_195 10068
#define ct_Times_LMR_200 10069
#define ct_Times_LMR_240 10070
#define ct_Times_LMR_240_UF 10071
#define ct_Times_LMR_240_75 10072
#define ct_Times_LMR_300 10073
#define ct_Times_LMR_400 10074
#define ct_Times_LMR_400_UF 10075
#define ct_Times_LMR_400_75 10076
#define ct_Times_LMR_500 10077
#define ct_Times_LMR_600 10078
#define ct_Times_LMR_600_UF 10079
#define ct_Times_LMR_600_75 10080
#define ct_Times_LMR_900 10081
#define ct_Times_LMR_1200 10082
#define ct_Times_LMR_1700 10083
#define ct_Wireman_CQ102 10084
#define ct_Wireman_CQ106 10085
#define ct_Wireman_CQ1000 10086
#define ct_Wireman_CQ116 10087
#define ct_Wireman_CQ117 10088
#define ct_Wireman_CQ118 10089
#define ct_Wireman_CQ124 10090
#define ct_Wireman_CQ129FF 10091
#define ct_Wireman_CQ113 10092
#define ct_Wireman_CQ142A 10093
#define ct_UTP_Category_3 10094
#define ct_UTP_Category_5E 10095
#define ct_UTP_Category_6 10096
#define ct_STP_A_150_ohm 10097
#define ct_Wireman_551_LL 10098
#define ct_Wireman_552_LL 10099
#define ct_Wireman_553_LL 10100
#define ct_Wireman_554_LL 10101
#define ct_Wireman_551_LL_ice_snow 10102
#define ct_Wireman_552_LL_ice_snow 10103
#define ct_Wireman_553_LL_ice_snow 10104
#define ct_Wireman_554_LL_ice_snow 10105
#define ct_Generic_300_ohm_Tubular 10106
#define ct_Generic_450_ohm_Window 10107
#define ct_Generic_600_ohm_Open 10108
#define ct_Ideal_lossless_50_ohm 10109
#define ct_Ideal_lossless_75_ohm 10110

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
		wxMenu* cableMenu;
		wxMenu* m_cableAndrew;
		wxMenu* m_cableBelden;
		wxMenu* m_cableCommScope;
		wxMenu* m_cableDavis;
		wxMenu* m_cableDXengineering;
		wxMenu* m_cablePasternack;
		wxMenu* m_cableRadioware;
		wxMenu* m_cableTandy;
		wxMenu* m_cableTimes;
		wxMenu* m_cableWiremanCoax;
		wxMenu* m_cableUTP;
		wxMenu* m_cableSTP;
		wxMenu* m_cableWiremanLadder;
		wxMenu* m_cableGenericLadder;
		wxMenu* m_cableIdealCoax;
		wxMenu* m_cableUserDefined;
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

		// Virtual event handlers, override them in your derived class
		virtual void onFileLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFileSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFileExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCableType( wxCommandEvent& event ) { event.Skip(); }
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

		tlineUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("tline"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 860,570 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

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

		// Virtual event handlers, override them in your derived class
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

		// Virtual event handlers, override them in your derived class
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

		// Virtual event handlers, override them in your derived class
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

		// Virtual event handlers, override them in your derived class
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

		tunerDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Tuner Calculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 970,800 ), long style = wxDEFAULT_DIALOG_STYLE );

		~tunerDialog();

};

