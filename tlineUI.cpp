///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6-dirty)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "tlineUI.h"

///////////////////////////////////////////////////////////////////////////

tlineUI::tlineUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	this->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	ui_menubar = new wxMenuBar( 0 );
	ui_menubar->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	fileMenu = new wxMenu();
	wxMenuItem* ui_fileMenuLoad;
	ui_fileMenuLoad = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( ui_fileMenuLoad );

	wxMenuItem* ui_fileMenuSave;
	ui_fileMenuSave = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( ui_fileMenuSave );

	ui_fileMenuExit = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( ui_fileMenuExit );

	ui_menubar->Append( fileMenu, wxT("File") );

	cableMenu = new wxMenu();
	m_cableAndrew = new wxMenu();
	wxMenuItem* m_cableAndrewItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Andrew"), wxEmptyString, wxITEM_NORMAL, m_cableAndrew );
	wxMenuItem* m_Andrew_Braided_CNT_100;
	m_Andrew_Braided_CNT_100 = new wxMenuItem( m_cableAndrew, ct_Andrew_Braided_CNT_100, wxString( wxT("Andrew Braided CNT-100") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableAndrew->Append( m_Andrew_Braided_CNT_100 );

	wxMenuItem* m_Andrew_Braided_CNT_195;
	m_Andrew_Braided_CNT_195 = new wxMenuItem( m_cableAndrew, ct_Andrew_Braided_CNT_195, wxString( wxT("Andrew Braided CNT-195") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableAndrew->Append( m_Andrew_Braided_CNT_195 );

	wxMenuItem* m_Andrew_Braided_CNT_240;
	m_Andrew_Braided_CNT_240 = new wxMenuItem( m_cableAndrew, ct_Andrew_Braided_CNT_240, wxString( wxT("Andrew Braided CNT-240") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableAndrew->Append( m_Andrew_Braided_CNT_240 );

	wxMenuItem* m_Andrew_Braided_CNT_300;
	m_Andrew_Braided_CNT_300 = new wxMenuItem( m_cableAndrew, ct_Andrew_Braided_CNT_300, wxString( wxT("Andrew Braided CNT-300") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableAndrew->Append( m_Andrew_Braided_CNT_300 );

	wxMenuItem* m_Andrew_Braided_CNT_400;
	m_Andrew_Braided_CNT_400 = new wxMenuItem( m_cableAndrew, ct_Andrew_Braided_CNT_400, wxString( wxT("Andrew Braided CNT-400") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableAndrew->Append( m_Andrew_Braided_CNT_400 );

	wxMenuItem* m_Andrew_Braided_CNT_600;
	m_Andrew_Braided_CNT_600 = new wxMenuItem( m_cableAndrew, ct_Andrew_Braided_CNT_600, wxString( wxT("Andrew Braided CNT-600") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableAndrew->Append( m_Andrew_Braided_CNT_600 );

	wxMenuItem* m_Andrew_Heliax_LDF4_50A;
	m_Andrew_Heliax_LDF4_50A = new wxMenuItem( m_cableAndrew, ct_Andrew_Heliax_LDF4_50A, wxString( wxT("Andrew Heliax LDF4-50A") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableAndrew->Append( m_Andrew_Heliax_LDF4_50A );

	wxMenuItem* m_Andrew_Heliax_LDF5_50A;
	m_Andrew_Heliax_LDF5_50A = new wxMenuItem( m_cableAndrew, ct_Andrew_Heliax_LDF5_50A, wxString( wxT("Andrew Heliax LDF5-50A") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableAndrew->Append( m_Andrew_Heliax_LDF5_50A );

	wxMenuItem* m_Andrew_Heliax_LDF6_50;
	m_Andrew_Heliax_LDF6_50 = new wxMenuItem( m_cableAndrew, ct_Andrew_Heliax_LDF6_50, wxString( wxT("Andrew Heliax LDF6-50") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableAndrew->Append( m_Andrew_Heliax_LDF6_50 );

	cableMenu->Append( m_cableAndrewItem );

	m_cableBelden = new wxMenu();
	wxMenuItem* m_cableBeldenItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Belden"), wxEmptyString, wxITEM_NORMAL, m_cableBelden );
	wxMenuItem* m_Belden_8215;
	m_Belden_8215 = new wxMenuItem( m_cableBelden, ct_Belden_8215, wxString( wxT("Belden 8215    (RG-6A/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8215 );

	wxMenuItem* m_Belden_7915A;
	m_Belden_7915A = new wxMenuItem( m_cableBelden, ct_Belden_7915A, wxString( wxT("Belden 7915A   (RG-6/HDTV)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_7915A );

	wxMenuItem* m_Belden_9116;
	m_Belden_9116 = new wxMenuItem( m_cableBelden, ct_Belden_9116, wxString( wxT("Belden 9116    (RG-6/CATV)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_9116 );

	wxMenuItem* m_Belden_8237;
	m_Belden_8237 = new wxMenuItem( m_cableBelden, ct_Belden_8237, wxString( wxT("Belden 8237    (RG-8/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8237 );

	wxMenuItem* m_Belden_9251;
	m_Belden_9251 = new wxMenuItem( m_cableBelden, ct_Belden_9251, wxString( wxT("Belden 9251    (RG-8/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_9251 );

	wxMenuItem* m_Belden_9913;
	m_Belden_9913 = new wxMenuItem( m_cableBelden, ct_Belden_9913, wxString( wxT("Belden 9913    (RG-8/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_9913 );

	wxMenuItem* m_Belden_9913F7;
	m_Belden_9913F7 = new wxMenuItem( m_cableBelden, ct_Belden_9913F7, wxString( wxT("Belden 9913F7 (RG-8/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_9913F7 );

	wxMenuItem* m_Belden_9914;
	m_Belden_9914 = new wxMenuItem( m_cableBelden, ct_Belden_9914, wxString( wxT("Belden 9914    (RG-8/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_9914 );

	wxMenuItem* m_Belden_9258;
	m_Belden_9258 = new wxMenuItem( m_cableBelden, ct_Belden_9258, wxString( wxT("Belden 9258    (RG-8X)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_9258 );

	wxMenuItem* m_Belden_8213;
	m_Belden_8213 = new wxMenuItem( m_cableBelden, ct_Belden_8213, wxString( wxT("Belden 8213    (RG-11/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8213 );

	wxMenuItem* m_Belden_8238;
	m_Belden_8238 = new wxMenuItem( m_cableBelden, ct_Belden_8238, wxString( wxT("Belden 8238    (RG-11/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8238 );

	wxMenuItem* m_Belden_8261;
	m_Belden_8261 = new wxMenuItem( m_cableBelden, ct_Belden_8261, wxString( wxT("Belden 8261    (RG-11A/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8261 );

	wxMenuItem* m_Belden_9212;
	m_Belden_9212 = new wxMenuItem( m_cableBelden, ct_Belden_9212, wxString( wxT("Belden 9212    (RG-11/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_9212 );

	wxMenuItem* m_Belden_8219;
	m_Belden_8219 = new wxMenuItem( m_cableBelden, ct_Belden_8219, wxString( wxT("Belden 8219    (RG-58A/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8219 );

	wxMenuItem* m_Belden_8240;
	m_Belden_8240 = new wxMenuItem( m_cableBelden, ct_Belden_8240, wxString( wxT("Belden 8240    (RG-58A/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8240 );

	wxMenuItem* m_Belden_8259;
	m_Belden_8259 = new wxMenuItem( m_cableBelden, ct_Belden_8259, wxString( wxT("Belden 8259    (RG-58A/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8259 );

	wxMenuItem* m_Belden_8262;
	m_Belden_8262 = new wxMenuItem( m_cableBelden, ct_Belden_8262, wxString( wxT("Belden 8262    (RG-58C/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8262 );

	wxMenuItem* m_Belden_9201;
	m_Belden_9201 = new wxMenuItem( m_cableBelden, ct_Belden_9201, wxString( wxT("Belden 9201    (RG-58/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_9201 );

	wxMenuItem* m_Belden_8212;
	m_Belden_8212 = new wxMenuItem( m_cableBelden, ct_Belden_8212, wxString( wxT("Belden 8212    (RG-59/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8212 );

	wxMenuItem* m_Belden_8241;
	m_Belden_8241 = new wxMenuItem( m_cableBelden, ct_Belden_8241, wxString( wxT("Belden 8241    (RG-59/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8241 );

	wxMenuItem* m_Belden_8263;
	m_Belden_8263 = new wxMenuItem( m_cableBelden, ct_Belden_8263, wxString( wxT("Belden 8263    (RG-59B/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8263 );

	wxMenuItem* m_Belden_9269;
	m_Belden_9269 = new wxMenuItem( m_cableBelden, ct_Belden_9269, wxString( wxT("Belden 9269    (RG-62A/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_9269 );

	wxMenuItem* m_Belden_9857;
	m_Belden_9857 = new wxMenuItem( m_cableBelden, ct_Belden_9857, wxString( wxT("Belden 9857    (RG-63/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_9857 );

	wxMenuItem* m_Belden_83242;
	m_Belden_83242 = new wxMenuItem( m_cableBelden, ct_Belden_83242, wxString( wxT("Belden 83242  (RG-142B/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_83242 );

	wxMenuItem* m_Belden_7805;
	m_Belden_7805 = new wxMenuItem( m_cableBelden, ct_Belden_7805, wxString( wxT("Belden 7805    (RG-174/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_7805 );

	wxMenuItem* m_Belden_8216;
	m_Belden_8216 = new wxMenuItem( m_cableBelden, ct_Belden_8216, wxString( wxT("Belden 8216    (RG-174/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8216 );

	wxMenuItem* m_Belden_83265;
	m_Belden_83265 = new wxMenuItem( m_cableBelden, ct_Belden_83265, wxString( wxT("Belden 83265  (RG-178B/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_83265 );

	wxMenuItem* m_Belden_83269;
	m_Belden_83269 = new wxMenuItem( m_cableBelden, ct_Belden_83269, wxString( wxT("Belden 83269  (RG-188A/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_83269 );

	wxMenuItem* m_Belden_8267;
	m_Belden_8267 = new wxMenuItem( m_cableBelden, ct_Belden_8267, wxString( wxT("Belden 8267    (RG-213/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8267 );

	wxMenuItem* m_Belden_8268;
	m_Belden_8268 = new wxMenuItem( m_cableBelden, ct_Belden_8268, wxString( wxT("Belden 8268    (RG-214/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_8268 );

	wxMenuItem* m_Belden_84303;
	m_Belden_84303 = new wxMenuItem( m_cableBelden, ct_Belden_84303, wxString( wxT("Belden 84303   (RG-303/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_84303 );

	wxMenuItem* m_Belden_84316;
	m_Belden_84316 = new wxMenuItem( m_cableBelden, ct_Belden_84316, wxString( wxT("Belden 84316   (RG-316/U)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableBelden->Append( m_Belden_84316 );

	cableMenu->Append( m_cableBeldenItem );

	m_cableCommScope = new wxMenu();
	wxMenuItem* m_cableCommScopeItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("CommScope"), wxEmptyString, wxITEM_NORMAL, m_cableCommScope );
	wxMenuItem* m_CommScope_2427K;
	m_CommScope_2427K = new wxMenuItem( m_cableCommScope, ct_CommScope_2427K, wxString( wxT("CommScope 2427K   (RG-8)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableCommScope->Append( m_CommScope_2427K );

	wxMenuItem* m_CommScope_3227;
	m_CommScope_3227 = new wxMenuItem( m_cableCommScope, ct_CommScope_3227, wxString( wxT("CommScope 3227     (RG-8)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableCommScope->Append( m_CommScope_3227 );

	cableMenu->Append( m_cableCommScopeItem );

	m_cableDavis = new wxMenu();
	wxMenuItem* m_cableDavisItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Davis"), wxEmptyString, wxITEM_NORMAL, m_cableDavis );
	wxMenuItem* m_Davis_RF_Bury_Flex;
	m_Davis_RF_Bury_Flex = new wxMenuItem( m_cableDavis, ct_Davis_RF_Bury_Flex, wxString( wxT("Davis RF Bury-Flex") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDavis->Append( m_Davis_RF_Bury_Flex );

	cableMenu->Append( m_cableDavisItem );

	m_cableDXengineering = new wxMenu();
	wxMenuItem* m_cableDXengineeringItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("DX Engineering"), wxEmptyString, wxITEM_NORMAL, m_cableDXengineering );
	wxMenuItem* m_DX_Engineering_RG_8;
	m_DX_Engineering_RG_8 = new wxMenuItem( m_cableDXengineering, ct_DX_Engineering_RG_8, wxString( wxT("DX Engineering RG-8") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDXengineering->Append( m_DX_Engineering_RG_8 );

	wxMenuItem* m_DX_Engineering_RG_8X;
	m_DX_Engineering_RG_8X = new wxMenuItem( m_cableDXengineering, ct_DX_Engineering_RG_8X, wxString( wxT("DX Engineering RG-8X") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDXengineering->Append( m_DX_Engineering_RG_8X );

	wxMenuItem* m_DX_Engineering_RG_11;
	m_DX_Engineering_RG_11 = new wxMenuItem( m_cableDXengineering, ct_DX_Engineering_RG_11, wxString( wxT("DX Engineering RG-11") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDXengineering->Append( m_DX_Engineering_RG_11 );

	wxMenuItem* m_DX_Engineering_RG_58A;
	m_DX_Engineering_RG_58A = new wxMenuItem( m_cableDXengineering, ct_DX_Engineering_RG_58A, wxString( wxT("DX Engineering RG-58A") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDXengineering->Append( m_DX_Engineering_RG_58A );

	wxMenuItem* m_DX_Engineering_RG_213;
	m_DX_Engineering_RG_213 = new wxMenuItem( m_cableDXengineering, ct_DX_Engineering_RG_213, wxString( wxT("DX Engineering RG-213") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDXengineering->Append( m_DX_Engineering_RG_213 );

	wxMenuItem* m_DX_Engineering_RG_214;
	m_DX_Engineering_RG_214 = new wxMenuItem( m_cableDXengineering, ct_DX_Engineering_RG_214, wxString( wxT("DX Engineering RG-214") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDXengineering->Append( m_DX_Engineering_RG_214 );

	wxMenuItem* m_DX_Engineering_RG_400;
	m_DX_Engineering_RG_400 = new wxMenuItem( m_cableDXengineering, ct_DX_Engineering_RG_400, wxString( wxT("DX Engineering RG-400") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDXengineering->Append( m_DX_Engineering_RG_400 );

	wxMenuItem* m_DX_Engineering_DXE_400MAX;
	m_DX_Engineering_DXE_400MAX = new wxMenuItem( m_cableDXengineering, ct_DX_Engineering_DXE_400MAX, wxString( wxT("DX Engineering DXE-400MAX") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDXengineering->Append( m_DX_Engineering_DXE_400MAX );

	wxMenuItem* m_DX_Engineering_300_Ohm_LL;
	m_DX_Engineering_300_Ohm_LL = new wxMenuItem( m_cableDXengineering, ct_DX_Engineering_300_Ohm_LL, wxString( wxT("DX Engineering 300-Ohm LL") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDXengineering->Append( m_DX_Engineering_300_Ohm_LL );

	wxMenuItem* m_DX_Eng_300_Ohm_LL_wet;
	m_DX_Eng_300_Ohm_LL_wet = new wxMenuItem( m_cableDXengineering, ct_DX_Eng_300_Ohm_LL_wet, wxString( wxT("DX Eng 300-Ohm LL (wet)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableDXengineering->Append( m_DX_Eng_300_Ohm_LL_wet );

	cableMenu->Append( m_cableDXengineeringItem );

	m_cablePasternack = new wxMenu();
	wxMenuItem* m_cablePasternackItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Pasternack"), wxEmptyString, wxITEM_NORMAL, m_cablePasternack );
	wxMenuItem* m_Pasternack_RG_142;
	m_Pasternack_RG_142 = new wxMenuItem( m_cablePasternack, ct_Pasternack_RG_142, wxString( wxT("Pasternack RG-142") ) , wxEmptyString, wxITEM_NORMAL );
	m_cablePasternack->Append( m_Pasternack_RG_142 );

	wxMenuItem* m_Pasternack_RG_218;
	m_Pasternack_RG_218 = new wxMenuItem( m_cablePasternack, ct_Pasternack_RG_218, wxString( wxT("Pasternack RG-218") ) , wxEmptyString, wxITEM_NORMAL );
	m_cablePasternack->Append( m_Pasternack_RG_218 );

	cableMenu->Append( m_cablePasternackItem );

	m_cableRadioware = new wxMenu();
	wxMenuItem* m_cableRadiowareItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Radioware"), wxEmptyString, wxITEM_NORMAL, m_cableRadioware );
	wxMenuItem* m_Radioware_RG_6;
	m_Radioware_RG_6 = new wxMenuItem( m_cableRadioware, ct_Radioware_RG_6, wxString( wxT("Radioware RG-6") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableRadioware->Append( m_Radioware_RG_6 );

	wxMenuItem* m_Radioware_RG_8X;
	m_Radioware_RG_8X = new wxMenuItem( m_cableRadioware, ct_Radioware_RG_8X, wxString( wxT("Radioware RG-8X") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableRadioware->Append( m_Radioware_RG_8X );

	wxMenuItem* m_Radioware_RG_11;
	m_Radioware_RG_11 = new wxMenuItem( m_cableRadioware, ct_Radioware_RG_11, wxString( wxT("Radioware RG-11") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableRadioware->Append( m_Radioware_RG_11 );

	wxMenuItem* m_Radioware_RG_58;
	m_Radioware_RG_58 = new wxMenuItem( m_cableRadioware, ct_Radioware_RG_58, wxString( wxT("Radioware RG-58") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableRadioware->Append( m_Radioware_RG_58 );

	wxMenuItem* m_Radioware_RG_174;
	m_Radioware_RG_174 = new wxMenuItem( m_cableRadioware, ct_Radioware_RG_174, wxString( wxT("Radioware RG-174") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableRadioware->Append( m_Radioware_RG_174 );

	wxMenuItem* m_Radioware_RG_213;
	m_Radioware_RG_213 = new wxMenuItem( m_cableRadioware, ct_Radioware_RG_213, wxString( wxT("Radioware RG-213") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableRadioware->Append( m_Radioware_RG_213 );

	wxMenuItem* m_Radioware_RF_9913;
	m_Radioware_RF_9913 = new wxMenuItem( m_cableRadioware, ct_Radioware_RF_9913, wxString( wxT("Radioware RF-9913") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableRadioware->Append( m_Radioware_RF_9913 );

	wxMenuItem* m_Radioware_RF_9914F;
	m_Radioware_RF_9914F = new wxMenuItem( m_cableRadioware, ct_Radioware_RF_9914F, wxString( wxT("Radioware RF-9914F") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableRadioware->Append( m_Radioware_RF_9914F );

	cableMenu->Append( m_cableRadiowareItem );

	m_cableTandy = new wxMenu();
	wxMenuItem* m_cableTandyItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Tandy Cable"), wxEmptyString, wxITEM_NORMAL, m_cableTandy );
	wxMenuItem* m_Tandy_Cable_RG_8X;
	m_Tandy_Cable_RG_8X = new wxMenuItem( m_cableTandy, ct_Tandy_Cable_RG_8X, wxString( wxT("Tandy Cable RG-8X") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTandy->Append( m_Tandy_Cable_RG_8X );

	wxMenuItem* m_Tandy_Cable_RG_58;
	m_Tandy_Cable_RG_58 = new wxMenuItem( m_cableTandy, ct_Tandy_Cable_RG_58, wxString( wxT("Tandy Cable RG-58") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTandy->Append( m_Tandy_Cable_RG_58 );

	wxMenuItem* m_Tandy_Cable_RG_59;
	m_Tandy_Cable_RG_59 = new wxMenuItem( m_cableTandy, ct_Tandy_Cable_RG_59, wxString( wxT("Tandy Cable RG-59") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTandy->Append( m_Tandy_Cable_RG_59 );

	cableMenu->Append( m_cableTandyItem );

	m_cableTimes = new wxMenu();
	wxMenuItem* m_cableTimesItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Times LMR"), wxEmptyString, wxITEM_NORMAL, m_cableTimes );
	wxMenuItem* m_Times_LMR_100A;
	m_Times_LMR_100A = new wxMenuItem( m_cableTimes, ct_Times_LMR_100A, wxString( wxT("Times LMR-100A") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_100A );

	wxMenuItem* m_Times_LMR_195;
	m_Times_LMR_195 = new wxMenuItem( m_cableTimes, ct_Times_LMR_195, wxString( wxT("Times LMR-195") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_195 );

	wxMenuItem* m_Times_LMR_200;
	m_Times_LMR_200 = new wxMenuItem( m_cableTimes, ct_Times_LMR_200, wxString( wxT("Times LMR-200") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_200 );

	wxMenuItem* m_Times_LMR_240;
	m_Times_LMR_240 = new wxMenuItem( m_cableTimes, ct_Times_LMR_240, wxString( wxT("Times LMR-240") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_240 );

	wxMenuItem* m_Times_LMR_240_UF;
	m_Times_LMR_240_UF = new wxMenuItem( m_cableTimes, ct_Times_LMR_240_UF, wxString( wxT("Times LMR-240-UF") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_240_UF );

	wxMenuItem* m_Times_LMR_240_75;
	m_Times_LMR_240_75 = new wxMenuItem( m_cableTimes, ct_Times_LMR_240_75, wxString( wxT("Times LMR-240-75") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_240_75 );

	wxMenuItem* m_Times_LMR_300;
	m_Times_LMR_300 = new wxMenuItem( m_cableTimes, ct_Times_LMR_300, wxString( wxT("Times LMR-300") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_300 );

	wxMenuItem* m_Times_LMR_400;
	m_Times_LMR_400 = new wxMenuItem( m_cableTimes, ct_Times_LMR_400, wxString( wxT("Times LMR-400") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_400 );

	wxMenuItem* m_Times_LMR_400_UF;
	m_Times_LMR_400_UF = new wxMenuItem( m_cableTimes, ct_Times_LMR_400_UF, wxString( wxT("Times LMR-400-UF") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_400_UF );

	wxMenuItem* m_Times_LMR_400_75;
	m_Times_LMR_400_75 = new wxMenuItem( m_cableTimes, ct_Times_LMR_400_75, wxString( wxT("Times LMR-400-75") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_400_75 );

	wxMenuItem* m_Times_LMR_500;
	m_Times_LMR_500 = new wxMenuItem( m_cableTimes, ct_Times_LMR_500, wxString( wxT("Times LMR-500") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_500 );

	wxMenuItem* m_Times_LMR_600;
	m_Times_LMR_600 = new wxMenuItem( m_cableTimes, ct_Times_LMR_600, wxString( wxT("Times LMR-600") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_600 );

	wxMenuItem* m_Times_LMR_600_UF;
	m_Times_LMR_600_UF = new wxMenuItem( m_cableTimes, ct_Times_LMR_600_UF, wxString( wxT("Times LMR-600-UF") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_600_UF );

	wxMenuItem* m_Times_LMR_600_75;
	m_Times_LMR_600_75 = new wxMenuItem( m_cableTimes, ct_Times_LMR_600_75, wxString( wxT("Times LMR-600-75") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_600_75 );

	wxMenuItem* m_Times_LMR_900;
	m_Times_LMR_900 = new wxMenuItem( m_cableTimes, ct_Times_LMR_900, wxString( wxT("Times LMR-900") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_900 );

	wxMenuItem* m_Times_LMR_1200;
	m_Times_LMR_1200 = new wxMenuItem( m_cableTimes, ct_Times_LMR_1200, wxString( wxT("Times LMR-1200") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_1200 );

	wxMenuItem* m_Times_LMR_1700;
	m_Times_LMR_1700 = new wxMenuItem( m_cableTimes, ct_Times_LMR_1700, wxString( wxT("Times LMR-1700") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableTimes->Append( m_Times_LMR_1700 );

	cableMenu->Append( m_cableTimesItem );

	m_cableWiremanCoax = new wxMenu();
	wxMenuItem* m_cableWiremanCoaxItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Wireman Coax"), wxEmptyString, wxITEM_NORMAL, m_cableWiremanCoax );
	wxMenuItem* m_Wireman_CQ102;
	m_Wireman_CQ102 = new wxMenuItem( m_cableWiremanCoax, ct_Wireman_CQ102, wxString( wxT("Wireman CQ102     (RG-8)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanCoax->Append( m_Wireman_CQ102 );

	wxMenuItem* m_Wireman_CQ106;
	m_Wireman_CQ106 = new wxMenuItem( m_cableWiremanCoax, ct_Wireman_CQ106, wxString( wxT("Wireman CQ106     (RG-8)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanCoax->Append( m_Wireman_CQ106 );

	wxMenuItem* m_Wireman_CQ1000;
	m_Wireman_CQ1000 = new wxMenuItem( m_cableWiremanCoax, ct_Wireman_CQ1000, wxString( wxT("Wireman CQ1000   (RG-8)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanCoax->Append( m_Wireman_CQ1000 );

	wxMenuItem* m_Wireman_CQ116;
	m_Wireman_CQ116 = new wxMenuItem( m_cableWiremanCoax, ct_Wireman_CQ116, wxString( wxT("Wireman CQ116     (RG-8X)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanCoax->Append( m_Wireman_CQ116 );

	wxMenuItem* m_Wireman_CQ117;
	m_Wireman_CQ117 = new wxMenuItem( m_cableWiremanCoax, ct_Wireman_CQ117, wxString( wxT("Wireman CQ117     (RG-8X)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanCoax->Append( m_Wireman_CQ117 );

	wxMenuItem* m_Wireman_CQ118;
	m_Wireman_CQ118 = new wxMenuItem( m_cableWiremanCoax, ct_Wireman_CQ118, wxString( wxT("Wireman CQ118     (RG-8X)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanCoax->Append( m_Wireman_CQ118 );

	wxMenuItem* m_Wireman_CQ124;
	m_Wireman_CQ124 = new wxMenuItem( m_cableWiremanCoax, ct_Wireman_CQ124, wxString( wxT("Wireman CQ124     (RG-58)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanCoax->Append( m_Wireman_CQ124 );

	wxMenuItem* m_Wireman_CQ129FF;
	m_Wireman_CQ129FF = new wxMenuItem( m_cableWiremanCoax, ct_Wireman_CQ129FF, wxString( wxT("Wireman CQ129FF (RG-58)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanCoax->Append( m_Wireman_CQ129FF );

	wxMenuItem* m_Wireman_CQ113;
	m_Wireman_CQ113 = new wxMenuItem( m_cableWiremanCoax, ct_Wireman_CQ113, wxString( wxT("Wireman CQ113     (RG-213)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanCoax->Append( m_Wireman_CQ113 );

	wxMenuItem* m_Wireman_CQ142A;
	m_Wireman_CQ142A = new wxMenuItem( m_cableWiremanCoax, ct_Wireman_CQ142A, wxString( wxT("Wireman CQ142A   (RG-217)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanCoax->Append( m_Wireman_CQ142A );

	cableMenu->Append( m_cableWiremanCoaxItem );

	m_cableUTP = new wxMenu();
	wxMenuItem* m_cableUTPItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("UTP"), wxEmptyString, wxITEM_NORMAL, m_cableUTP );
	wxMenuItem* m_UTP_Category_3;
	m_UTP_Category_3 = new wxMenuItem( m_cableUTP, ct_UTP_Category_3, wxString( wxT("UTP Category 3") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableUTP->Append( m_UTP_Category_3 );

	wxMenuItem* m_UTP_Category_5E;
	m_UTP_Category_5E = new wxMenuItem( m_cableUTP, ct_UTP_Category_5E, wxString( wxT("UTP Category 5E") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableUTP->Append( m_UTP_Category_5E );

	wxMenuItem* m_UTP_Category_6;
	m_UTP_Category_6 = new wxMenuItem( m_cableUTP, ct_UTP_Category_6, wxString( wxT("UTP Category 6") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableUTP->Append( m_UTP_Category_6 );

	cableMenu->Append( m_cableUTPItem );

	m_cableSTP = new wxMenu();
	wxMenuItem* m_cableSTPItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("STP"), wxEmptyString, wxITEM_NORMAL, m_cableSTP );
	wxMenuItem* m_STP_A_150_ohm;
	m_STP_A_150_ohm = new wxMenuItem( m_cableSTP, ct_STP_A_150_ohm, wxString( wxT("STP-A 150 ohm") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableSTP->Append( m_STP_A_150_ohm );

	cableMenu->Append( m_cableSTPItem );

	m_cableWiremanLadder = new wxMenu();
	wxMenuItem* m_cableWiremanLadderItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Wireman Ladder Line"), wxEmptyString, wxITEM_NORMAL, m_cableWiremanLadder );
	wxMenuItem* m_Wireman_551_LL;
	m_Wireman_551_LL = new wxMenuItem( m_cableWiremanLadder, ct_Wireman_551_LL, wxString( wxT("Wireman 551 Ladder Line") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanLadder->Append( m_Wireman_551_LL );

	wxMenuItem* m_Wireman_552_LL;
	m_Wireman_552_LL = new wxMenuItem( m_cableWiremanLadder, ct_Wireman_552_LL, wxString( wxT("Wireman 552 Ladder Line") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanLadder->Append( m_Wireman_552_LL );

	wxMenuItem* m_Wireman_553_LL;
	m_Wireman_553_LL = new wxMenuItem( m_cableWiremanLadder, ct_Wireman_553_LL, wxString( wxT("Wireman 553 Ladder Line") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanLadder->Append( m_Wireman_553_LL );

	wxMenuItem* m_Wireman_554_LL;
	m_Wireman_554_LL = new wxMenuItem( m_cableWiremanLadder, ct_Wireman_554_LL, wxString( wxT("Wireman 554 Ladder Line") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanLadder->Append( m_Wireman_554_LL );

	wxMenuItem* m_Wireman_551_LL_ice_snow;
	m_Wireman_551_LL_ice_snow = new wxMenuItem( m_cableWiremanLadder, ct_Wireman_551_LL_ice_snow, wxString( wxT("Wireman 551 LL (ice/snow)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanLadder->Append( m_Wireman_551_LL_ice_snow );

	wxMenuItem* m_Wireman_552_LL_ice_snow;
	m_Wireman_552_LL_ice_snow = new wxMenuItem( m_cableWiremanLadder, ct_Wireman_552_LL_ice_snow, wxString( wxT("Wireman 552 LL (ice/snow)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanLadder->Append( m_Wireman_552_LL_ice_snow );

	wxMenuItem* m_Wireman_553_LL_ice_snow;
	m_Wireman_553_LL_ice_snow = new wxMenuItem( m_cableWiremanLadder, ct_Wireman_553_LL_ice_snow, wxString( wxT("Wireman 553 LL (ice/snow)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanLadder->Append( m_Wireman_553_LL_ice_snow );

	wxMenuItem* m_Wireman_554_LL_ice_snow;
	m_Wireman_554_LL_ice_snow = new wxMenuItem( m_cableWiremanLadder, ct_Wireman_554_LL_ice_snow, wxString( wxT("Wireman 554 LL (ice/snow)") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableWiremanLadder->Append( m_Wireman_554_LL_ice_snow );

	cableMenu->Append( m_cableWiremanLadderItem );

	m_cableGenericLadder = new wxMenu();
	wxMenuItem* m_cableGenericLadderItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Generic Ladder Line"), wxEmptyString, wxITEM_NORMAL, m_cableGenericLadder );
	wxMenuItem* m_Generic_300_ohm_Tubular;
	m_Generic_300_ohm_Tubular = new wxMenuItem( m_cableGenericLadder, ct_Generic_300_ohm_Tubular, wxString( wxT("Generic 300 ohm Tubular") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableGenericLadder->Append( m_Generic_300_ohm_Tubular );

	wxMenuItem* m_Generic_450_ohm_Window;
	m_Generic_450_ohm_Window = new wxMenuItem( m_cableGenericLadder, ct_Generic_450_ohm_Window, wxString( wxT("Generic 450 ohm Window") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableGenericLadder->Append( m_Generic_450_ohm_Window );

	wxMenuItem* m_Generic_600_ohm_Open;
	m_Generic_600_ohm_Open = new wxMenuItem( m_cableGenericLadder, ct_Generic_600_ohm_Open, wxString( wxT("Generic 600 ohm Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableGenericLadder->Append( m_Generic_600_ohm_Open );

	cableMenu->Append( m_cableGenericLadderItem );

	m_cableIdealCoax = new wxMenu();
	wxMenuItem* m_cableIdealCoaxItem = new wxMenuItem( cableMenu, wxID_ANY, wxT("Ideal Coax"), wxEmptyString, wxITEM_NORMAL, m_cableIdealCoax );
	wxMenuItem* m_Ideal_lossless_50_ohm;
	m_Ideal_lossless_50_ohm = new wxMenuItem( m_cableIdealCoax, ct_Ideal_lossless_50_ohm, wxString( wxT("Ideal (lossless) 50 ohm") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableIdealCoax->Append( m_Ideal_lossless_50_ohm );

	wxMenuItem* m_Ideal_lossless_75_ohm;
	m_Ideal_lossless_75_ohm = new wxMenuItem( m_cableIdealCoax, ct_Ideal_lossless_75_ohm, wxString( wxT("Ideal (lossless) 75 ohm") ) , wxEmptyString, wxITEM_NORMAL );
	m_cableIdealCoax->Append( m_Ideal_lossless_75_ohm );

	cableMenu->Append( m_cableIdealCoaxItem );

	wxMenuItem* m_cableUserDefined;
	m_cableUserDefined = new wxMenuItem( cableMenu, ct_user_defined, wxString( wxT("User Defined Line") ) , wxEmptyString, wxITEM_NORMAL );
	cableMenu->Append( m_cableUserDefined );

	ui_menubar->Append( cableMenu, wxT("Cable Type") );

	helpMenu = new wxMenu();
	wxMenuItem* ui_helpInfo;
	ui_helpInfo = new wxMenuItem( helpMenu, wxID_ANY, wxString( wxT("Info") ) , wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( ui_helpInfo );

	wxMenuItem* ui_helpAbout;
	ui_helpAbout = new wxMenuItem( helpMenu, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( ui_helpAbout );

	ui_menubar->Append( helpMenu, wxT("Help") );

	this->SetMenuBar( ui_menubar );

	wxBoxSizer* bMainWindow;
	bMainWindow = new wxBoxSizer( wxVERTICAL );

	ui_programTitle = new wxStaticText( this, wxID_ANY, wxT("program title"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_programTitle->Wrap( -1 );
	bMainWindow->Add( ui_programTitle, 0, wxALL, 5 );

	wxStaticBoxSizer* sbCable;
	sbCable = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Cable Type") ), wxHORIZONTAL );

	ui_cableType = new wxTextCtrl( sbCable->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	ui_cableType->SetMinSize( wxSize( 300,-1 ) );

	sbCable->Add( ui_cableType, 0, wxALL, 5 );

	ui_updateWarning = new wxStaticText( sbCable->GetStaticBox(), wxID_ANY, wxT("Parameters have changed. Reselect UserLine cable type to update."), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	ui_updateWarning->Wrap( -1 );
	ui_updateWarning->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	ui_updateWarning->SetForegroundColour( wxColour( 255, 0, 0 ) );

	sbCable->Add( ui_updateWarning, 0, wxALIGN_CENTER_VERTICAL, 5 );


	bMainWindow->Add( sbCable, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane1;
	bPane1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bPane1Left;
	bPane1Left = new wxBoxSizer( wxHORIZONTAL );

	wxString ui_unitsRadioButtonsChoices[] = { wxT("Feet"), wxT("Meters") };
	int ui_unitsRadioButtonsNChoices = sizeof( ui_unitsRadioButtonsChoices ) / sizeof( wxString );
	ui_unitsRadioButtons = new wxRadioBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, ui_unitsRadioButtonsNChoices, ui_unitsRadioButtonsChoices, 1, wxRA_SPECIFY_COLS );
	ui_unitsRadioButtons->SetSelection( 0 );
	bPane1Left->Add( ui_unitsRadioButtons, 0, wxALL, 5 );


	bPane1->Add( bPane1Left, 0, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbPane1Right;
	sbPane1Right = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );

	wxBoxSizer* bPane1RightUpper;
	bPane1RightUpper = new wxBoxSizer( wxHORIZONTAL );

	ui_cableLengthTag = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Length:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_cableLengthTag->Wrap( -1 );
	bPane1RightUpper->Add( ui_cableLengthTag, 0, wxALL, 5 );

	ui_cableLength = new wxTextCtrl( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_cableLength->SetValidator( wxTextValidator( wxFILTER_INCLUDE_CHAR_LIST, &m_lengthStr ) );

	bPane1RightUpper->Add( ui_cableLength, 0, wxALL, 0 );

	ui_lengthUnits = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Feet"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_lengthUnits->Wrap( -1 );
	bPane1RightUpper->Add( ui_lengthUnits, 0, wxALL, 5 );


	bPane1RightUpper->Add( 40, 0, 1, wxALL, 5 );

	ui_lambdaTag = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Length (λ):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_lambdaTag->Wrap( -1 );
	bPane1RightUpper->Add( ui_lambdaTag, 0, wxALL, 5 );

	ui_lambda = new wxTextCtrl( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_lambda->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	bPane1RightUpper->Add( ui_lambda, 0, wxALL, 5 );


	bPane1RightUpper->Add( 30, 0, 1, wxALL, 5 );

	ui_frequencyTag = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Frequency:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_frequencyTag->Wrap( -1 );
	bPane1RightUpper->Add( ui_frequencyTag, 0, wxALL, 5 );

	ui_frequency = new wxTextCtrl( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("7.00"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_frequency->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_frequencyStr ) );

	bPane1RightUpper->Add( ui_frequency, 0, wxALL, 0 );

	ui_frequencyUnits = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("MHz"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_frequencyUnits->Wrap( -1 );
	bPane1RightUpper->Add( ui_frequencyUnits, 0, wxALL, 5 );


	sbPane1Right->Add( bPane1RightUpper, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane1RightLower;
	bPane1RightLower = new wxBoxSizer( wxHORIZONTAL );

	ui_wSuffixNote = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Use \"w\" suffix for wavelength (for example, 0.25w)"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_wSuffixNote->Wrap( -1 );
	bPane1RightLower->Add( ui_wSuffixNote, 0, 0, 5 );


	sbPane1Right->Add( bPane1RightLower, 1, wxALL, 5 );


	bPane1->Add( sbPane1Right, 1, wxEXPAND, 5 );


	bMainWindow->Add( bPane1, 1, wxSHAPED, 5 );

	wxBoxSizer* bPane2;
	bPane2 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbPane2Left;
	sbPane2Left = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Input") ), wxVERTICAL );

	wxBoxSizer* bPane2LeftTop;
	bPane2LeftTop = new wxBoxSizer( wxHORIZONTAL );

	ui_powerTag = new wxStaticText( sbPane2Left->GetStaticBox(), wxID_ANY, wxT("Power"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_powerTag->Wrap( -1 );
	bPane2LeftTop->Add( ui_powerTag, 0, wxALL, 5 );

	ui_power = new wxTextCtrl( sbPane2Left->GetStaticBox(), wxID_ANY, wxT("1500"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_power->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_powerStr ) );

	bPane2LeftTop->Add( ui_power, 0, wxALL, 0 );

	ui_powerUnits = new wxStaticText( sbPane2Left->GetStaticBox(), wxID_ANY, wxT("Watts"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_powerUnits->Wrap( -1 );
	bPane2LeftTop->Add( ui_powerUnits, 0, wxALL, 5 );


	sbPane2Left->Add( bPane2LeftTop, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane2LeftBottom;
	bPane2LeftBottom = new wxBoxSizer( wxHORIZONTAL );

	ui_inputVoltageTag = new wxStaticText( sbPane2Left->GetStaticBox(), wxID_ANY, wxT("Input Voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_inputVoltageTag->Wrap( -1 );
	bPane2LeftBottom->Add( ui_inputVoltageTag, 0, wxALL, 5 );

	ui_inputVoltage = new wxTextCtrl( sbPane2Left->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_inputVoltage->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	bPane2LeftBottom->Add( ui_inputVoltage, 0, wxALL, 5 );


	sbPane2Left->Add( bPane2LeftBottom, 1, wxEXPAND, 5 );


	bPane2->Add( sbPane2Left, 1, wxEXPAND, 5 );


	bPane2->Add( 10, 0, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbPane2Center;
	sbPane2Center = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Line/Load") ), wxHORIZONTAL );

	wxString ui_loadInputRadioButtonsChoices[] = { wxT("Load"), wxT("Input") };
	int ui_loadInputRadioButtonsNChoices = sizeof( ui_loadInputRadioButtonsChoices ) / sizeof( wxString );
	ui_loadInputRadioButtons = new wxRadioBox( sbPane2Center->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, ui_loadInputRadioButtonsNChoices, ui_loadInputRadioButtonsChoices, 1, wxRA_SPECIFY_COLS );
	ui_loadInputRadioButtons->SetSelection( 0 );
	sbPane2Center->Add( ui_loadInputRadioButtons, 0, wxALL, 5 );


	sbPane2Center->Add( 20, 0, 0, wxEXPAND, 5 );

	wxBoxSizer* bPane2CenterRight;
	bPane2CenterRight = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bPane2CenterRightTop;
	bPane2CenterRightTop = new wxBoxSizer( wxHORIZONTAL );

	ui_resistanceTag = new wxStaticText( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("Resistance"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_resistanceTag->Wrap( -1 );
	bPane2CenterRightTop->Add( ui_resistanceTag, 0, wxALL, 5 );

	ui_resistance = new wxTextCtrl( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_resistance->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_resistanceStr ) );

	bPane2CenterRightTop->Add( ui_resistance, 0, wxALL, 0 );

	ui_resistanceUnits = new wxStaticText( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("Ω"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_resistanceUnits->Wrap( -1 );
	bPane2CenterRightTop->Add( ui_resistanceUnits, 0, wxALL, 5 );


	bPane2CenterRight->Add( bPane2CenterRightTop, 1, 0, 5 );

	wxBoxSizer* bPane2CenterRightBottom;
	bPane2CenterRightBottom = new wxBoxSizer( wxHORIZONTAL );

	ui_reactanceTag = new wxStaticText( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("Reactance"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_reactanceTag->Wrap( -1 );
	bPane2CenterRightBottom->Add( ui_reactanceTag, 0, wxALL, 5 );

	ui_reactance = new wxTextCtrl( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_reactance->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_reactanceStr ) );

	bPane2CenterRightBottom->Add( ui_reactance, 0, wxALL, 0 );

	ui_reactanceUnits = new wxStaticText( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("Ω"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_reactanceUnits->Wrap( -1 );
	bPane2CenterRightBottom->Add( ui_reactanceUnits, 0, wxALL, 5 );


	bPane2CenterRight->Add( bPane2CenterRightBottom, 1, 0, 5 );


	sbPane2Center->Add( bPane2CenterRight, 1, wxEXPAND, 5 );


	bPane2->Add( sbPane2Center, 1, wxEXPAND, 5 );


	bPane2->Add( 10, 0, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbPane2Right;
	sbPane2Right = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Actions") ), wxHORIZONTAL );

	wxBoxSizer* bPane2RightLeft;
	bPane2RightLeft = new wxBoxSizer( wxVERTICAL );

	ui_plotZ = new wxButton( sbPane2Right->GetStaticBox(), wxID_ANY, wxT("Plot Z"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2RightLeft->Add( ui_plotZ, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_plotVI = new wxButton( sbPane2Right->GetStaticBox(), wxID_ANY, wxT("Plot V/I"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2RightLeft->Add( ui_plotVI, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_tuner = new wxButton( sbPane2Right->GetStaticBox(), wxID_ANY, wxT("Tuner"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2RightLeft->Add( ui_tuner, 0, wxALIGN_RIGHT|wxALL, 5 );


	sbPane2Right->Add( bPane2RightLeft, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane2RightRight;
	bPane2RightRight = new wxBoxSizer( wxVERTICAL );

	ui_saveZplot = new wxButton( sbPane2Right->GetStaticBox(), wxID_ANY, wxT("Save Z Plot"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2RightRight->Add( ui_saveZplot, 0, wxALL, 5 );

	ui_saveVIplot = new wxButton( sbPane2Right->GetStaticBox(), wxID_ANY, wxT("Save V/I Plot"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2RightRight->Add( ui_saveVIplot, 0, wxALL, 5 );

	ui_saveData = new wxButton( sbPane2Right->GetStaticBox(), wxID_ANY, wxT("Save Raw Data"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2RightRight->Add( ui_saveData, 0, wxALL, 5 );


	sbPane2Right->Add( bPane2RightRight, 1, wxEXPAND, 5 );


	bPane2->Add( sbPane2Right, 1, wxEXPAND, 5 );


	bMainWindow->Add( bPane2, 0, 0, 5 );

	wxBoxSizer* bPane3;
	bPane3 = new wxBoxSizer( wxHORIZONTAL );

	wxGridSizer* gPane3Left;
	gPane3Left = new wxGridSizer( 0, 2, 0, 0 );

	ui_matchedLineLossTag = new wxStaticText( this, wxID_ANY, wxT("Matched-Line Loss:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_matchedLineLossTag->Wrap( -1 );
	ui_matchedLineLossTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Left->Add( ui_matchedLineLossTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_matchedLineLoss = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_matchedLineLoss->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_matchedLineLoss->SetMinSize( wxSize( 200,20 ) );

	gPane3Left->Add( ui_matchedLineLoss, 0, wxALL, 5 );

	ui_totalMatchedLineLossTag = new wxStaticText( this, wxID_ANY, wxT("Total Matched-Line Loss:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_totalMatchedLineLossTag->Wrap( -1 );
	ui_totalMatchedLineLossTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Left->Add( ui_totalMatchedLineLossTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_totalMatchedLineLoss = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_totalMatchedLineLoss->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_totalMatchedLineLoss->SetMinSize( wxSize( 200,20 ) );

	gPane3Left->Add( ui_totalMatchedLineLoss, 0, wxALL, 5 );

	ui_addedLossTag = new wxStaticText( this, wxID_ANY, wxT("Additional Loss Due To SWR:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_addedLossTag->Wrap( -1 );
	ui_addedLossTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Left->Add( ui_addedLossTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_addedLoss = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_addedLoss->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_addedLoss->SetMinSize( wxSize( 200,20 ) );

	gPane3Left->Add( ui_addedLoss, 0, wxALL, 5 );

	ui_totalLossTag = new wxStaticText( this, wxID_ANY, wxT("Total Line Loss:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	ui_totalLossTag->Wrap( -1 );
	ui_totalLossTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Left->Add( ui_totalLossTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_totalLoss = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_totalLoss->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_totalLoss->SetMinSize( wxSize( 200,20 ) );

	gPane3Left->Add( ui_totalLoss, 0, wxALL, 5 );

	ui_impedanceRectangularTag = new wxStaticText( this, wxID_ANY, wxT("Impedance at Input (Real/Imaginary):"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	ui_impedanceRectangularTag->Wrap( -1 );
	ui_impedanceRectangularTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Left->Add( ui_impedanceRectangularTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_impedanceRectangular = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_impedanceRectangular->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_impedanceRectangular->SetMinSize( wxSize( 200,20 ) );

	gPane3Left->Add( ui_impedanceRectangular, 0, wxALL, 5 );

	ui_impedancePolarTag = new wxStaticText( this, wxID_ANY, wxT("Impedance at Input (Polar):"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	ui_impedancePolarTag->Wrap( -1 );
	ui_impedancePolarTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Left->Add( ui_impedancePolarTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_impedancePolar = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_impedancePolar->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_impedancePolar->SetMinSize( wxSize( 200,20 ) );

	gPane3Left->Add( ui_impedancePolar, 0, wxALL, 5 );


	bPane3->Add( gPane3Left, 1, wxEXPAND, 5 );

	wxGridSizer* gPane3Right;
	gPane3Right = new wxGridSizer( 0, 2, 0, 0 );

	ui_characteristicZ0Tag = new wxStaticText( this, wxID_ANY, wxT("Characteristic Z0:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_characteristicZ0Tag->Wrap( -1 );
	ui_characteristicZ0Tag->SetMinSize( wxSize( -1,20 ) );

	gPane3Right->Add( ui_characteristicZ0Tag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_characteristicZ0 = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_characteristicZ0->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_characteristicZ0->SetMinSize( wxSize( 200,20 ) );

	gPane3Right->Add( ui_characteristicZ0, 0, wxALL, 5 );

	ui_velocityFactorTag = new wxStaticText( this, wxID_ANY, wxT("Velocity Factor:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_velocityFactorTag->Wrap( -1 );
	ui_velocityFactorTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Right->Add( ui_velocityFactorTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_velocityFactor = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_velocityFactor->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_velocityFactor->SetMinSize( wxSize( 200,20 ) );

	gPane3Right->Add( ui_velocityFactor, 0, wxALL, 5 );

	ui_maxVoltageTag = new wxStaticText( this, wxID_ANY, wxT("Max Voltage:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_maxVoltageTag->Wrap( -1 );
	ui_maxVoltageTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Right->Add( ui_maxVoltageTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_maxVoltage = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_maxVoltage->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_maxVoltage->SetMinSize( wxSize( 200,20 ) );

	gPane3Right->Add( ui_maxVoltage, 0, wxALL, 5 );

	ui_swrInputTag = new wxStaticText( this, wxID_ANY, wxT("SWR (Input):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_swrInputTag->Wrap( -1 );
	ui_swrInputTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Right->Add( ui_swrInputTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_swrInput = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_swrInput->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_swrInput->SetMinSize( wxSize( 200,20 ) );

	gPane3Right->Add( ui_swrInput, 0, wxALL, 5 );

	ui_swrLoadTag = new wxStaticText( this, wxID_ANY, wxT("SWR (Load):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_swrLoadTag->Wrap( -1 );
	ui_swrLoadTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Right->Add( ui_swrLoadTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_swrLoad = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_swrLoad->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_swrLoad->SetMinSize( wxSize( 200,20 ) );

	gPane3Right->Add( ui_swrLoad, 0, wxALL, 5 );

	ui_rhoLoadTag = new wxStaticText( this, wxID_ANY, wxT("Rho (Load):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_rhoLoadTag->Wrap( -1 );
	ui_rhoLoadTag->SetMinSize( wxSize( -1,20 ) );

	gPane3Right->Add( ui_rhoLoadTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	ui_rhoLoad = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_rhoLoad->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ui_rhoLoad->SetMinSize( wxSize( 200,20 ) );

	gPane3Right->Add( ui_rhoLoad, 0, wxALL, 5 );


	bPane3->Add( gPane3Right, 1, wxEXPAND, 5 );


	bMainWindow->Add( bPane3, 1, wxEXPAND, 5 );


	this->SetSizer( bMainWindow );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onFileLoad ), this, ui_fileMenuLoad->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onFileSave ), this, ui_fileMenuSave->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onFileExit ), this, ui_fileMenuExit->GetId());
	m_cableAndrew->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Andrew_Braided_CNT_100->GetId());
	m_cableAndrew->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Andrew_Braided_CNT_195->GetId());
	m_cableAndrew->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Andrew_Braided_CNT_240->GetId());
	m_cableAndrew->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Andrew_Braided_CNT_300->GetId());
	m_cableAndrew->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Andrew_Braided_CNT_400->GetId());
	m_cableAndrew->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Andrew_Braided_CNT_600->GetId());
	m_cableAndrew->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Andrew_Heliax_LDF4_50A->GetId());
	m_cableAndrew->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Andrew_Heliax_LDF5_50A->GetId());
	m_cableAndrew->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Andrew_Heliax_LDF6_50->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8215->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_7915A->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_9116->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8237->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_9251->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_9913->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_9913F7->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_9914->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_9258->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8213->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8238->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8261->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_9212->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8219->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8240->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8259->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8262->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_9201->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8212->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8241->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8263->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_9269->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_9857->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_83242->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_7805->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8216->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_83265->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_83269->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8267->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_8268->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_84303->GetId());
	m_cableBelden->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Belden_84316->GetId());
	m_cableCommScope->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_CommScope_2427K->GetId());
	m_cableCommScope->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_CommScope_3227->GetId());
	m_cableDavis->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Davis_RF_Bury_Flex->GetId());
	m_cableDXengineering->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_DX_Engineering_RG_8->GetId());
	m_cableDXengineering->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_DX_Engineering_RG_8X->GetId());
	m_cableDXengineering->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_DX_Engineering_RG_11->GetId());
	m_cableDXengineering->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_DX_Engineering_RG_58A->GetId());
	m_cableDXengineering->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_DX_Engineering_RG_213->GetId());
	m_cableDXengineering->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_DX_Engineering_RG_214->GetId());
	m_cableDXengineering->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_DX_Engineering_RG_400->GetId());
	m_cableDXengineering->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_DX_Engineering_DXE_400MAX->GetId());
	m_cableDXengineering->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_DX_Engineering_300_Ohm_LL->GetId());
	m_cableDXengineering->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_DX_Eng_300_Ohm_LL_wet->GetId());
	m_cablePasternack->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Pasternack_RG_142->GetId());
	m_cablePasternack->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Pasternack_RG_218->GetId());
	m_cableRadioware->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Radioware_RG_6->GetId());
	m_cableRadioware->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Radioware_RG_8X->GetId());
	m_cableRadioware->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Radioware_RG_11->GetId());
	m_cableRadioware->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Radioware_RG_58->GetId());
	m_cableRadioware->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Radioware_RG_174->GetId());
	m_cableRadioware->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Radioware_RG_213->GetId());
	m_cableRadioware->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Radioware_RF_9913->GetId());
	m_cableRadioware->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Radioware_RF_9914F->GetId());
	m_cableTandy->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Tandy_Cable_RG_8X->GetId());
	m_cableTandy->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Tandy_Cable_RG_58->GetId());
	m_cableTandy->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Tandy_Cable_RG_59->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_100A->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_195->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_200->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_240->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_240_UF->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_240_75->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_300->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_400->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_400_UF->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_400_75->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_500->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_600->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_600_UF->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_600_75->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_900->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_1200->GetId());
	m_cableTimes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Times_LMR_1700->GetId());
	m_cableWiremanCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_CQ102->GetId());
	m_cableWiremanCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_CQ106->GetId());
	m_cableWiremanCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_CQ1000->GetId());
	m_cableWiremanCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_CQ116->GetId());
	m_cableWiremanCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_CQ117->GetId());
	m_cableWiremanCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_CQ118->GetId());
	m_cableWiremanCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_CQ124->GetId());
	m_cableWiremanCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_CQ129FF->GetId());
	m_cableWiremanCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_CQ113->GetId());
	m_cableWiremanCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_CQ142A->GetId());
	m_cableUTP->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_UTP_Category_3->GetId());
	m_cableUTP->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_UTP_Category_5E->GetId());
	m_cableUTP->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_UTP_Category_6->GetId());
	m_cableSTP->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_STP_A_150_ohm->GetId());
	m_cableWiremanLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_551_LL->GetId());
	m_cableWiremanLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_552_LL->GetId());
	m_cableWiremanLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_553_LL->GetId());
	m_cableWiremanLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_554_LL->GetId());
	m_cableWiremanLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_551_LL_ice_snow->GetId());
	m_cableWiremanLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_552_LL_ice_snow->GetId());
	m_cableWiremanLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_553_LL_ice_snow->GetId());
	m_cableWiremanLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Wireman_554_LL_ice_snow->GetId());
	m_cableGenericLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Generic_300_ohm_Tubular->GetId());
	m_cableGenericLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Generic_450_ohm_Window->GetId());
	m_cableGenericLadder->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Generic_600_ohm_Open->GetId());
	m_cableIdealCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Ideal_lossless_50_ohm->GetId());
	m_cableIdealCoax->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_Ideal_lossless_75_ohm->GetId());
	cableMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onCableType ), this, m_cableUserDefined->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onHelpInfo ), this, ui_helpInfo->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onHelpAbout ), this, ui_helpAbout->GetId());
	ui_unitsRadioButtons->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( tlineUI::onUnitsSelected ), NULL, this );
	ui_cableLength->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onLengthSelected ), NULL, this );
	ui_frequency->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onFrequencySelected ), NULL, this );
	ui_power->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onPowerSelected ), NULL, this );
	ui_loadInputRadioButtons->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( tlineUI::onLoadInputSelected ), NULL, this );
	ui_resistance->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onResistanceSelected ), NULL, this );
	ui_reactance->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onReactanceSelected ), NULL, this );
	ui_plotZ->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onPlotZclicked ), NULL, this );
	ui_plotVI->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onPlotVIclicked ), NULL, this );
	ui_tuner->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onTunerClicked ), NULL, this );
	ui_saveZplot->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onSavePlotZclicked ), NULL, this );
	ui_saveVIplot->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onSavePlotVIclicked ), NULL, this );
	ui_saveData->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onSaveDataClicked ), NULL, this );
}

tlineUI::~tlineUI()
{
	// Disconnect Events
	ui_unitsRadioButtons->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( tlineUI::onUnitsSelected ), NULL, this );
	ui_cableLength->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onLengthSelected ), NULL, this );
	ui_frequency->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onFrequencySelected ), NULL, this );
	ui_power->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onPowerSelected ), NULL, this );
	ui_loadInputRadioButtons->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( tlineUI::onLoadInputSelected ), NULL, this );
	ui_resistance->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onResistanceSelected ), NULL, this );
	ui_reactance->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onReactanceSelected ), NULL, this );
	ui_plotZ->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onPlotZclicked ), NULL, this );
	ui_plotVI->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onPlotVIclicked ), NULL, this );
	ui_tuner->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onTunerClicked ), NULL, this );
	ui_saveZplot->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onSavePlotZclicked ), NULL, this );
	ui_saveVIplot->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onSavePlotVIclicked ), NULL, this );
	ui_saveData->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tlineUI::onSaveDataClicked ), NULL, this );

}

userLineDialog::userLineDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bUserLineOuter;
	bUserLineOuter = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgParameters;
	fgParameters = new wxFlexGridSizer( 0, 3, 10, 0 );
	fgParameters->SetFlexibleDirection( wxBOTH );
	fgParameters->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	dl_frequencyTag = new wxStaticText( this, wxID_ANY, wxT("Frequency (MHz)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_frequencyTag->Wrap( -1 );
	fgParameters->Add( dl_frequencyTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_frequencyStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_frequencyStr->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	dl_frequencyStr->SetMinSize( wxSize( 200,-1 ) );

	dl_frequencyStr->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_userLineFrequencyStr ) );

	fgParameters->Add( dl_frequencyStr, 0, wxALL, 5 );

	dl_hiddenPadFQ = new wxStaticText( this, wxID_ANY, wxT("Hidden Pad"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_hiddenPadFQ->Wrap( -1 );
	dl_hiddenPadFQ->Hide();

	fgParameters->Add( dl_hiddenPadFQ, 0, wxALL, 5 );

	dl_attenuationTag = new wxStaticText( this, wxID_ANY, wxT("Attenuation (dB/100 feet)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_attenuationTag->Wrap( -1 );
	fgParameters->Add( dl_attenuationTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_attenuationStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_attenuationStr->SetMinSize( wxSize( 200,-1 ) );

	dl_attenuationStr->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_userLineAttenuationStr ) );

	fgParameters->Add( dl_attenuationStr, 0, wxALL, 0 );

	dl_hiddenPadATTN = new wxStaticText( this, wxID_ANY, wxT("Hidden Pad"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_hiddenPadATTN->Wrap( -1 );
	dl_hiddenPadATTN->Hide();

	fgParameters->Add( dl_hiddenPadATTN, 0, wxALL, 5 );

	dl_velocityFactorTag = new wxStaticText( this, wxID_ANY, wxT("Velocity Factor (0.00 to 1.00)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_velocityFactorTag->Wrap( -1 );
	fgParameters->Add( dl_velocityFactorTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_velocityFactorStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_velocityFactorStr->SetMinSize( wxSize( 200,-1 ) );

	dl_velocityFactorStr->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_userLineVelocityFactorStr ) );

	fgParameters->Add( dl_velocityFactorStr, 0, wxALL, 0 );

	dl_hiddenPadVF = new wxStaticText( this, wxID_ANY, wxT("Hidden Pad"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_hiddenPadVF->Wrap( -1 );
	dl_hiddenPadVF->Hide();

	fgParameters->Add( dl_hiddenPadVF, 0, wxALL, 5 );

	dl_cableImpedanceTag = new wxStaticText( this, wxID_ANY, wxT("Cable Characteristic Impedance (Ω)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableImpedanceTag->Wrap( -1 );
	fgParameters->Add( dl_cableImpedanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_cableImpedanceStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableImpedanceStr->SetMinSize( wxSize( 200,-1 ) );

	dl_cableImpedanceStr->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_userLineCableImpedanceStr ) );

	fgParameters->Add( dl_cableImpedanceStr, 0, wxALL, 0 );

	dl_cableImpedanceCtlStr = new wxStaticText( this, wxID_ANY, wxT("Calculated from R, X"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableImpedanceCtlStr->Wrap( -1 );
	fgParameters->Add( dl_cableImpedanceCtlStr, 0, wxALL, 5 );

	dl_cableResistanceTag = new wxStaticText( this, wxID_ANY, wxT("Cable Characteristic Resistance (Ω)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableResistanceTag->Wrap( -1 );
	fgParameters->Add( dl_cableResistanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_cableResistanceStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableResistanceStr->SetMinSize( wxSize( 200,-1 ) );

	dl_cableResistanceStr->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_userLineCableResistanceStr ) );

	fgParameters->Add( dl_cableResistanceStr, 0, wxALL, 0 );

	dl_cableResistanceCtlStr = new wxStaticText( this, wxID_ANY, wxT("Calculated from Z"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableResistanceCtlStr->Wrap( -1 );
	fgParameters->Add( dl_cableResistanceCtlStr, 0, wxALL, 5 );

	dl_cableReactanceTag = new wxStaticText( this, wxID_ANY, wxT("Cable Characteristic Reactance (Ω)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableReactanceTag->Wrap( -1 );
	fgParameters->Add( dl_cableReactanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_cableReactanceStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableReactanceStr->SetMinSize( wxSize( 200,-1 ) );

	dl_cableReactanceStr->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_userLineCableReactanceStr ) );

	fgParameters->Add( dl_cableReactanceStr, 0, wxALL, 0 );

	dl_cableReactanceCtlStr = new wxStaticText( this, wxID_ANY, wxT("Calculated from Z"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableReactanceCtlStr->Wrap( -1 );
	fgParameters->Add( dl_cableReactanceCtlStr, 0, wxALL, 5 );

	dl_cableVoltageLimitTag = new wxStaticText( this, wxID_ANY, wxT("Cable Voltage Limit (Volts)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableVoltageLimitTag->Wrap( -1 );
	fgParameters->Add( dl_cableVoltageLimitTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_cableVoltageLimitStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableVoltageLimitStr->SetMinSize( wxSize( 200,-1 ) );

	dl_cableVoltageLimitStr->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_userLineCableVoltageLimitStr ) );

	fgParameters->Add( dl_cableVoltageLimitStr, 0, wxALL, 0 );

	dl_hiddenPadVL = new wxStaticText( this, wxID_ANY, wxT("Hidden Pad"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_hiddenPadVL->Wrap( -1 );
	dl_hiddenPadVL->Hide();

	fgParameters->Add( dl_hiddenPadVL, 0, wxALL, 5 );

	dl_hiddenPadBTN = new wxStaticText( this, wxID_ANY, wxT("Hidden Pad"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_hiddenPadBTN->Wrap( -1 );
	dl_hiddenPadBTN->Hide();

	fgParameters->Add( dl_hiddenPadBTN, 0, wxALL, 5 );

	wxBoxSizer* bButtons;
	bButtons = new wxBoxSizer( wxHORIZONTAL );

	dl_okButton = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bButtons->Add( dl_okButton, 0, wxALL, 5 );

	dl_cancelButton = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bButtons->Add( dl_cancelButton, 0, wxALL, 5 );


	fgParameters->Add( bButtons, 1, wxEXPAND, 5 );


	bUserLineOuter->Add( fgParameters, 1, wxEXPAND, 5 );

	wxBoxSizer* bUserLineBottom;
	bUserLineBottom = new wxBoxSizer( wxVERTICAL );

	dl_help = new wxStaticText( this, wxID_ANY, wxT("Note: When you enter the Cable Characteristic Impedance, the cable characteristic resistance and reactance will be estimated.  You can override the estimates, in which case the corresponding cable impedance will be recalculated.  A note will be shown to indicate which variables are calculated and which are user-specified."), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_help->Wrap( -1 );
	bUserLineBottom->Add( dl_help, 1, wxALL|wxEXPAND, 5 );


	bUserLineOuter->Add( bUserLineBottom, 1, wxEXPAND, 5 );


	this->SetSizer( bUserLineOuter );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	dl_attenuationStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onAttenuationSelected ), NULL, this );
	dl_velocityFactorStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onVelocityFactorSelected ), NULL, this );
	dl_cableImpedanceStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableImpedanceSelected ), NULL, this );
	dl_cableResistanceStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableResistanceSelected ), NULL, this );
	dl_cableReactanceStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableReactanceSelected ), NULL, this );
	dl_cableVoltageLimitStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableVoltageLimitSelected ), NULL, this );
	dl_okButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( userLineDialog::onOkClicked ), NULL, this );
	dl_cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( userLineDialog::onCancelClicked ), NULL, this );
}

userLineDialog::~userLineDialog()
{
	// Disconnect Events
	dl_attenuationStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onAttenuationSelected ), NULL, this );
	dl_velocityFactorStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onVelocityFactorSelected ), NULL, this );
	dl_cableImpedanceStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableImpedanceSelected ), NULL, this );
	dl_cableResistanceStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableResistanceSelected ), NULL, this );
	dl_cableReactanceStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableReactanceSelected ), NULL, this );
	dl_cableVoltageLimitStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableVoltageLimitSelected ), NULL, this );
	dl_okButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( userLineDialog::onOkClicked ), NULL, this );
	dl_cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( userLineDialog::onCancelClicked ), NULL, this );

}

helpInfoDialog::helpInfoDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,400 ), wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bHelpInfo;
	bHelpInfo = new wxBoxSizer( wxVERTICAL );

	bHelpInfo->SetMinSize( wxSize( 800,400 ) );
	dl_htmlWindow = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxHW_SCROLLBAR_AUTO|wxHSCROLL|wxVSCROLL );
	dl_htmlWindow->SetMinSize( wxSize( 800,400 ) );

	bHelpInfo->Add( dl_htmlWindow, 0, wxALL, 5 );

	dl_helpInfoOk = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bHelpInfo->Add( dl_helpInfoOk, 0, wxALIGN_CENTER|wxALL, 5 );


	this->SetSizer( bHelpInfo );
	this->Layout();
	bHelpInfo->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	dl_htmlWindow->Connect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( helpInfoDialog::onLinkClicked ), NULL, this );
	dl_helpInfoOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( helpInfoDialog::onHelpInfoOK ), NULL, this );
}

helpInfoDialog::~helpInfoDialog()
{
	// Disconnect Events
	dl_htmlWindow->Disconnect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( helpInfoDialog::onLinkClicked ), NULL, this );
	dl_helpInfoOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( helpInfoDialog::onHelpInfoOK ), NULL, this );

}

helpAboutDialog::helpAboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,200 ), wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bhelpAbout;
	bhelpAbout = new wxBoxSizer( wxVERTICAL );

	dl_helpAboutTextLine1 = new wxStaticText( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_helpAboutTextLine1->Wrap( -1 );
	bhelpAbout->Add( dl_helpAboutTextLine1, 0, wxALIGN_CENTER|wxALL, 5 );

	dl_helpAboutTextLine2 = new wxStaticText( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_helpAboutTextLine2->Wrap( -1 );
	bhelpAbout->Add( dl_helpAboutTextLine2, 0, wxALIGN_CENTER|wxALL, 5 );

	dl_helpAboutTextLine3 = new wxStaticText( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_helpAboutTextLine3->Wrap( -1 );
	bhelpAbout->Add( dl_helpAboutTextLine3, 0, wxALIGN_CENTER|wxALL, 5 );

	dl_helpAboutTextLine4 = new wxStaticText( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_helpAboutTextLine4->Wrap( -1 );
	bhelpAbout->Add( dl_helpAboutTextLine4, 0, wxALIGN_CENTER|wxALL, 5 );

	dl_helpAboutOk = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bhelpAbout->Add( dl_helpAboutOk, 0, wxALIGN_CENTER|wxALL, 5 );


	this->SetSizer( bhelpAbout );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	dl_helpAboutOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( helpAboutDialog::onHelpAboutOK ), NULL, this );
}

helpAboutDialog::~helpAboutDialog()
{
	// Disconnect Events
	dl_helpAboutOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( helpAboutDialog::onHelpAboutOK ), NULL, this );

}

tunerDialog::tunerDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bTunerOuter;
	bTunerOuter = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bTunerInner;
	bTunerInner = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bTunerLeft;
	bTunerLeft = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbTunerParameterContainer;
	sbTunerParameterContainer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Parameters") ), wxVERTICAL );

	wxGridSizer* gTunerParameters;
	gTunerParameters = new wxGridSizer( 0, 2, 0, 0 );

	dl_tunerFrequencyTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Frequency (MHz)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerFrequencyTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerFrequencyTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerFrequency = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerFrequency->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	dl_tunerFrequency->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_tunerFrequencyStr ) );

	gTunerParameters->Add( dl_tunerFrequency, 0, wxALL, 0 );

	dl_tunerPowerTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Power (W)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerPowerTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerPowerTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerPower = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerPower->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	dl_tunerPower->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_tunerPowerStr ) );

	gTunerParameters->Add( dl_tunerPower, 0, wxALL, 0 );

	dl_tunerSourceResistanceTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Source Resistance (Ω)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerSourceResistanceTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerSourceResistanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerSourceResistance = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerSourceResistance->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_tunerSourceResistanceStr ) );

	gTunerParameters->Add( dl_tunerSourceResistance, 0, wxALL, 0 );

	dl_tunerSourceReactanceTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Source Reactance (Ω)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerSourceReactanceTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerSourceReactanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerSourceReactance = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerSourceReactance->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_tunerSourceReactanceStr ) );

	gTunerParameters->Add( dl_tunerSourceReactance, 0, wxALL, 0 );

	dl_tunerLoadResistanceTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Load Resistance (Ω)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerLoadResistanceTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerLoadResistanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerLoadResistance = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerLoadResistance->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_tunerLoadResistanceStr ) );

	gTunerParameters->Add( dl_tunerLoadResistance, 0, wxALL, 0 );

	dl_tunerLoadReactanceTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Load Reactance (Ω)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerLoadReactanceTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerLoadReactanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerLoadReactance = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerLoadReactance->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_tunerLoadReactanceStr ) );

	gTunerParameters->Add( dl_tunerLoadReactance, 0, wxALL, 0 );

	dl_tunerInductorQTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Actual Inductor Q"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerInductorQTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerInductorQTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerInductorQ = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerInductorQ->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_tunerInductorQStr ) );

	gTunerParameters->Add( dl_tunerInductorQ, 0, wxALL, 0 );

	dl_tunerCapacitorQTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Actual Capacitor Q"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerCapacitorQTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerCapacitorQTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerCapacitorQ = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerCapacitorQ->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_tunerCapacitorQStr ) );

	gTunerParameters->Add( dl_tunerCapacitorQ, 0, wxALL, 0 );

	dl_tunerNetworkQTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Desired Network Q"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerNetworkQTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerNetworkQTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerNetworkQ = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerNetworkQ->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_tunerNetworkQStr ) );

	gTunerParameters->Add( dl_tunerNetworkQ, 0, wxALL, 0 );


	sbTunerParameterContainer->Add( gTunerParameters, 1, wxBOTTOM|wxEXPAND|wxLEFT, 10 );


	bTunerLeft->Add( sbTunerParameterContainer, 0, wxEXPAND|wxTOP, 5 );


	bTunerLeft->Add( 0, 20, 0, 0, 5 );

	wxStaticBoxSizer* sbTunerResultsContainer;
	sbTunerResultsContainer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Results") ), wxVERTICAL );

	sbTunerResults1 = new wxStaticBoxSizer( new wxStaticBox( sbTunerResultsContainer->GetStaticBox(), wxID_ANY, wxT("label") ), wxVERTICAL );

	wxGridSizer* gTunerResults1;
	gTunerResults1 = new wxGridSizer( 0, 2, 0, 0 );

	dl_tunerResultTag1 = new wxStaticText( sbTunerResults1->GetStaticBox(), wxID_ANY, wxT("Result 1"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerResultTag1->Wrap( -1 );
	gTunerResults1->Add( dl_tunerResultTag1, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult1 = new wxTextCtrl( sbTunerResults1->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult1->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults1->Add( dl_tunerResult1, 0, wxALL, 0 );

	dl_tunerResultTag2 = new wxStaticText( sbTunerResults1->GetStaticBox(), wxID_ANY, wxT("Result 2"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerResultTag2->Wrap( -1 );
	gTunerResults1->Add( dl_tunerResultTag2, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult2 = new wxTextCtrl( sbTunerResults1->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult2->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults1->Add( dl_tunerResult2, 0, wxALL, 0 );

	dl_tunerResultTag3 = new wxStaticText( sbTunerResults1->GetStaticBox(), wxID_ANY, wxT("Result 3"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerResultTag3->Wrap( -1 );
	gTunerResults1->Add( dl_tunerResultTag3, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult3 = new wxTextCtrl( sbTunerResults1->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult3->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults1->Add( dl_tunerResult3, 0, wxALL, 0 );

	dl_tunerResultTag4 = new wxStaticText( sbTunerResults1->GetStaticBox(), wxID_ANY, wxT("Result 4"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerResultTag4->Wrap( -1 );
	gTunerResults1->Add( dl_tunerResultTag4, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult4 = new wxTextCtrl( sbTunerResults1->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult4->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults1->Add( dl_tunerResult4, 0, wxALL, 0 );


	sbTunerResults1->Add( gTunerResults1, 1, wxEXPAND, 5 );


	sbTunerResultsContainer->Add( sbTunerResults1, 1, wxEXPAND|wxLEFT|wxRIGHT, 10 );


	sbTunerResultsContainer->Add( 0, 10, 0, 0, 0 );

	sbTunerResults2 = new wxStaticBoxSizer( new wxStaticBox( sbTunerResultsContainer->GetStaticBox(), wxID_ANY, wxT("label") ), wxVERTICAL );

	wxGridSizer* gTunerResults2;
	gTunerResults2 = new wxGridSizer( 0, 2, 0, 0 );

	dl_tunerResultTag5 = new wxStaticText( sbTunerResults2->GetStaticBox(), wxID_ANY, wxT("Result 5"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerResultTag5->Wrap( -1 );
	gTunerResults2->Add( dl_tunerResultTag5, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult5 = new wxTextCtrl( sbTunerResults2->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult5->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults2->Add( dl_tunerResult5, 0, wxALL, 0 );

	dl_tunerResultTag6 = new wxStaticText( sbTunerResults2->GetStaticBox(), wxID_ANY, wxT("Result 6"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerResultTag6->Wrap( -1 );
	gTunerResults2->Add( dl_tunerResultTag6, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult6 = new wxTextCtrl( sbTunerResults2->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult6->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults2->Add( dl_tunerResult6, 0, wxALL, 0 );

	dl_tunerResultTag7 = new wxStaticText( sbTunerResults2->GetStaticBox(), wxID_ANY, wxT("Result 7"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerResultTag7->Wrap( -1 );
	gTunerResults2->Add( dl_tunerResultTag7, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult7 = new wxTextCtrl( sbTunerResults2->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult7->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults2->Add( dl_tunerResult7, 0, wxALL, 0 );

	dl_tunerResultTag8 = new wxStaticText( sbTunerResults2->GetStaticBox(), wxID_ANY, wxT("Result 8"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerResultTag8->Wrap( -1 );
	gTunerResults2->Add( dl_tunerResultTag8, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult8 = new wxTextCtrl( sbTunerResults2->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult8->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults2->Add( dl_tunerResult8, 0, wxALL, 0 );


	sbTunerResults2->Add( gTunerResults2, 1, wxEXPAND, 5 );


	sbTunerResultsContainer->Add( sbTunerResults2, 1, wxEXPAND|wxLEFT|wxRIGHT, 10 );


	sbTunerResultsContainer->Add( 0, 10, 0, 0, 0 );

	sbTunerResults3 = new wxStaticBoxSizer( new wxStaticBox( sbTunerResultsContainer->GetStaticBox(), wxID_ANY, wxT("label") ), wxVERTICAL );

	wxGridSizer* gTunerResults3;
	gTunerResults3 = new wxGridSizer( 0, 2, 0, 0 );

	dl_tunerResultTag9 = new wxStaticText( sbTunerResults3->GetStaticBox(), wxID_ANY, wxT("Result 9"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerResultTag9->Wrap( -1 );
	gTunerResults3->Add( dl_tunerResultTag9, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult9 = new wxTextCtrl( sbTunerResults3->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult9->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults3->Add( dl_tunerResult9, 0, wxALL, 0 );

	dl_tunerResultTag10 = new wxStaticText( sbTunerResults3->GetStaticBox(), wxID_ANY, wxT("Result 10"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerResultTag10->Wrap( -1 );
	gTunerResults3->Add( dl_tunerResultTag10, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult10 = new wxTextCtrl( sbTunerResults3->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult10->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults3->Add( dl_tunerResult10, 0, wxALL, 0 );

	dl_tunerResultTag11 = new wxStaticText( sbTunerResults3->GetStaticBox(), wxID_ANY, wxT("Result 11"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerResultTag11->Wrap( -1 );
	gTunerResults3->Add( dl_tunerResultTag11, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult11 = new wxTextCtrl( sbTunerResults3->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult11->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults3->Add( dl_tunerResult11, 0, wxALL, 0 );

	dl_tunerResultTag12 = new wxStaticText( sbTunerResults3->GetStaticBox(), wxID_ANY, wxT("Result 12"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerResultTag12->Wrap( -1 );
	gTunerResults3->Add( dl_tunerResultTag12, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerResult12 = new wxTextCtrl( sbTunerResults3->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_tunerResult12->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gTunerResults3->Add( dl_tunerResult12, 0, wxALL, 0 );


	sbTunerResults3->Add( gTunerResults3, 1, wxEXPAND, 5 );


	sbTunerResultsContainer->Add( sbTunerResults3, 1, wxEXPAND|wxLEFT|wxRIGHT, 10 );


	sbTunerResultsContainer->Add( 0, 10, 0, 0, 0 );


	bTunerLeft->Add( sbTunerResultsContainer, 1, wxEXPAND, 5 );


	bTunerInner->Add( bTunerLeft, 1, 0, 5 );

	wxBoxSizer* bTunerCenter;
	bTunerCenter = new wxBoxSizer( wxVERTICAL );

	wxString dl_topologyChoices[] = { wxT("Two Cap (Cpar Cser)"), wxT("Two Cap (Cser Cpar)"), wxT("Two Coil (Lpar Lser)"), wxT("Two Coil (Lser Lpar)"), wxT("High Pass (Lpar Cser)"), wxT("Low Pass (Cpar Lser)"), wxT("Low Pass (Lser Cpar)"), wxT("High Pass (Cser Lpar)"), wxT("High Pass PI (Lpar Cser Lpar)"), wxT("Low Pass PI (Cpar Lser Cpar)"), wxT("High Pass T (Cser Lpar Cser)"), wxT("Low Pass T (Lser Cpar Lser)") };
	int dl_topologyNChoices = sizeof( dl_topologyChoices ) / sizeof( wxString );
	dl_topology = new wxRadioBox( this, wxID_ANY, wxT("Topology"), wxDefaultPosition, wxDefaultSize, dl_topologyNChoices, dl_topologyChoices, 1, wxRA_SPECIFY_COLS );
	dl_topology->SetSelection( 0 );
	bTunerCenter->Add( dl_topology, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	dl_bitmap = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	dl_bitmap->SetMinSize( wxSize( 300,180 ) );

	bTunerCenter->Add( dl_bitmap, 0, wxALIGN_CENTER|wxALL, 5 );

	sbTunerStatus = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("label") ), wxVERTICAL );

	wxFlexGridSizer* fgTunerStatus;
	fgTunerStatus = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgTunerStatus->SetFlexibleDirection( wxBOTH );
	fgTunerStatus->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	dl_tunerStatusTag0 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("Status 0"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerStatusTag0->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatusTag0, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerStatus0 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerStatus0->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatus0, 0, wxLEFT, 5 );

	dl_tunerStatusTag1 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("Status 1"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerStatusTag1->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatusTag1, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerStatus1 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerStatus1->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatus1, 0, wxLEFT, 5 );

	dl_tunerStatusTag2 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("Status 2"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerStatusTag2->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatusTag2, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerStatus2 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerStatus2->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatus2, 0, wxLEFT, 5 );

	dl_tunerStatusTag3 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("Status 3"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerStatusTag3->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatusTag3, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerStatus3 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerStatus3->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatus3, 0, wxLEFT, 5 );

	dl_tunerStatusTag4 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("Status 4"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerStatusTag4->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatusTag4, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerStatus4 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerStatus4->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatus4, 0, wxLEFT, 5 );

	dl_tunerStatusTag5 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("Status 5"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerStatusTag5->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatusTag5, 0, wxALIGN_RIGHT|wxALL, 0 );

	dl_tunerStatus5 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerStatus5->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatus5, 0, wxLEFT, 5 );

	dl_tunerStatusTag6 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("Status 6"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	dl_tunerStatusTag6->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatusTag6, 0, wxALIGN_RIGHT, 0 );

	dl_tunerStatus6 = new wxStaticText( sbTunerStatus->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerStatus6->Wrap( -1 );
	fgTunerStatus->Add( dl_tunerStatus6, 0, wxLEFT, 5 );


	sbTunerStatus->Add( fgTunerStatus, 1, wxALL, 5 );


	bTunerCenter->Add( sbTunerStatus, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	bTunerInner->Add( bTunerCenter, 1, wxEXPAND|wxSHAPED, 5 );

	wxBoxSizer* bTunerRight;
	bTunerRight = new wxBoxSizer( wxVERTICAL );

	dl_tunerParameterNote = new wxStaticText( this, wxID_ANY, wxT("Parameter note: The tuner can be located in the shack, or it can be located at the antenna. Since it is more common for the tuner to be located in the shack, we prepopulate the tuner source impedance assuming a 50 Ω transceiver and we prepopulate the tuner load impedance based on the calculated value at the input of the transmission line.  These values can be overridden in the \"Parameters\" box at left.\n\nThe Actual Inductor and Capacitor Q default to 200 and 2000 respectively, but can be overridden as desired.\n\nThe \"Desired Network Q\" parameter is only used for the PI and T topologies, and is an upper bound.  Typically, one will specify a fairly low Q.  Try a value around 1.0.  \n"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerParameterNote->Wrap( 300 );
	bTunerRight->Add( dl_tunerParameterNote, 0, wxALL, 5 );

	dl_tunerTopologyNote = new wxStaticText( this, wxID_ANY, wxT("Topology note: The radio buttons list the filter components in order, from source to load, where Lpar is a parallel inductor, Cpar is a parallel capacitor, Lser is a series inductor, and Cser is a series capacitor.  The circuit schematic of the selected radio button is shown at left.\n\nSome combinations of Parameters and Topologies will result in invalid component values.  This will be indicated in the results, and invalid topology choices will be grayed out.  In this case, try selecting a different topology.\n"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerTopologyNote->Wrap( 300 );
	bTunerRight->Add( dl_tunerTopologyNote, 0, wxALL, 5 );

	dl_tunerOKbutton = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bTunerRight->Add( dl_tunerOKbutton, 0, wxALIGN_CENTER|wxALL, 5 );


	bTunerInner->Add( bTunerRight, 1, wxEXPAND|wxSHAPED, 5 );


	bTunerOuter->Add( bTunerInner, 1, wxEXPAND, 5 );

	wxBoxSizer* bTunerBottom;
	bTunerBottom = new wxBoxSizer( wxVERTICAL );

	dl_tunerInfo = new wxStaticText( this, wxID_ANY, wxT("XXXXXX\nXXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerInfo->Wrap( -1 );
	bTunerBottom->Add( dl_tunerInfo, 0, wxALL, 5 );


	bTunerOuter->Add( bTunerBottom, 1, wxEXPAND, 5 );


	this->SetSizer( bTunerOuter );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	dl_tunerFrequency->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerFrequency ), NULL, this );
	dl_tunerPower->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerPower ), NULL, this );
	dl_tunerSourceResistance->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerSourceResistance ), NULL, this );
	dl_tunerSourceReactance->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerSourceReactance ), NULL, this );
	dl_tunerLoadResistance->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerLoadResistance ), NULL, this );
	dl_tunerLoadReactance->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerLoadReactance ), NULL, this );
	dl_tunerInductorQ->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerInductorQ ), NULL, this );
	dl_tunerCapacitorQ->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerCapacitorQ ), NULL, this );
	dl_tunerNetworkQ->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerNetworkQ ), NULL, this );
	dl_topology->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( tunerDialog::onTunerTopologySelected ), NULL, this );
	dl_tunerOKbutton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tunerDialog::onTunerOKclicked ), NULL, this );
}

tunerDialog::~tunerDialog()
{
	// Disconnect Events
	dl_tunerFrequency->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerFrequency ), NULL, this );
	dl_tunerPower->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerPower ), NULL, this );
	dl_tunerSourceResistance->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerSourceResistance ), NULL, this );
	dl_tunerSourceReactance->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerSourceReactance ), NULL, this );
	dl_tunerLoadResistance->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerLoadResistance ), NULL, this );
	dl_tunerLoadReactance->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerLoadReactance ), NULL, this );
	dl_tunerInductorQ->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerInductorQ ), NULL, this );
	dl_tunerCapacitorQ->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerCapacitorQ ), NULL, this );
	dl_tunerNetworkQ->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTunerNetworkQ ), NULL, this );
	dl_topology->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( tunerDialog::onTunerTopologySelected ), NULL, this );
	dl_tunerOKbutton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tunerDialog::onTunerOKclicked ), NULL, this );

}
