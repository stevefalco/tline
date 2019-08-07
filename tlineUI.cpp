///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jul 30 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "tlineUI.h"

///////////////////////////////////////////////////////////////////////////

tlineUI::tlineUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	ui_menubar = new wxMenuBar( 0 );
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

	ui_cableType = new wxComboBox( this, wxID_ANY, wxT("RG-8U"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	ui_cableType->Append( wxT("RG-6 (Belden 8215)") );
	ui_cableType->Append( wxT("RG-8 (TMS LMR400)") );
	ui_cableType->Append( wxT("RG-8 (Belden 9913/9086)") );
	ui_cableType->Append( wxT("RG-8 (DX Engineering)") );
	ui_cableType->Append( wxT("RG-8 (Wireman CQ106)") );
	ui_cableType->Append( wxT("RG-8A (Belden 8237)") );
	ui_cableType->Append( wxT("RG-8X (Belden 9258)") );
	ui_cableType->Append( wxT("RG-8X (DX Engineering)") );
	ui_cableType->Append( wxT("RG-8X (TMS LMR240)") );
	ui_cableType->Append( wxT("RG-11 Foam (Belden 8213)") );
	ui_cableType->Append( wxT("RG-11 (DX Engineering)") );
	ui_cableType->Append( wxT("RG-11A (Belden 8261)") );
	ui_cableType->Append( wxT("RG-58 (TMS LMR200)") );
	ui_cableType->Append( wxT("RG-58A Foam (Belden 8219)") );
	ui_cableType->Append( wxT("RG-58A (Belden 8259)") );
	ui_cableType->Append( wxT("RG-58A (DX Engineering)") );
	ui_cableType->Append( wxT("RG-59 Foam (Belden 8212)") );
	ui_cableType->Append( wxT("RG-59B (Belden 8263)") );
	ui_cableType->Append( wxT("RG-62A (Belden 9269)") );
	ui_cableType->Append( wxT("RG-142/303 High-Temp. Teflon") );
	ui_cableType->Append( wxT("RG-174 (Belden 8216)") );
	ui_cableType->Append( wxT("RG-213 (Belden 8267)") );
	ui_cableType->Append( wxT("RG-213 (DX Engineering)") );
	ui_cableType->Append( wxT("RG-218A (ex RG-17)") );
	ui_cableType->Append( wxT("RG-400 (DX Engineering)") );
	ui_cableType->Append( wxT("DX Engineering DXE-400MAX") );
	ui_cableType->Append( wxT("1/2-inch, LMR500") );
	ui_cableType->Append( wxT("0.59-inch, LMR600") );
	ui_cableType->Append( wxT("1.2-inch, LMR1200") );
	ui_cableType->Append( wxT("1/2-inch LDF4-50A Andrew Heliax") );
	ui_cableType->Append( wxT("7/8-inch LDF5-50A Andrew Heliax") );
	ui_cableType->Append( wxT("1-1/4 Inch LDF6-50A Andrew Heliax") );
	ui_cableType->Append( wxT("300-Ohm DXE #18 Ladder Line") );
	ui_cableType->Append( wxT("450-Ohm Window Line, Wireman #551") );
	ui_cableType->Append( wxT("450-Ohm Window Line, Wireman #554") );
	ui_cableType->Append( wxT("600-Ohm Open-Wire Ladder Line, #12 Wire") );
	ui_cableType->Append( wxT("User-Defined Transmission Line") );
	ui_cableType->SetSelection( 0 );
	ui_cableType->SetMinSize( wxSize( 500,-1 ) );

	bMainWindow->Add( ui_cableType, 0, wxALL, 5 );

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
	bPane1RightUpper->Add( ui_cableLength, 0, wxALL, 0 );

	ui_lengthUnits = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Feet"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_lengthUnits->Wrap( -1 );
	bPane1RightUpper->Add( ui_lengthUnits, 0, wxALL, 5 );


	bPane1RightUpper->Add( 40, 0, 1, wxALL, 5 );

	ui_lambdaTag = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Lambda:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_lambdaTag->Wrap( -1 );
	bPane1RightUpper->Add( ui_lambdaTag, 0, wxALL, 5 );

	ui_lambda = new wxTextCtrl( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	bPane1RightUpper->Add( ui_lambda, 0, wxALL, 5 );


	bPane1RightUpper->Add( 30, 0, 1, wxALL, 5 );

	ui_frequencyTag = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Frequency:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_frequencyTag->Wrap( -1 );
	bPane1RightUpper->Add( ui_frequencyTag, 0, wxALL, 5 );

	ui_frequency = new wxTextCtrl( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("7.00"), wxDefaultPosition, wxDefaultSize, 0 );
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
	bPane2LeftBottom->Add( ui_inputVoltage, 0, wxALL, 5 );


	sbPane2Left->Add( bPane2LeftBottom, 1, wxEXPAND, 5 );


	bPane2->Add( sbPane2Left, 1, wxEXPAND, 5 );


	bPane2->Add( 0, 0, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbPane2Center;
	sbPane2Center = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxHORIZONTAL );

	wxBoxSizer* bPane2CenterLeft;
	bPane2CenterLeft = new wxBoxSizer( wxVERTICAL );

	wxString ui_loadInputRadioButtonsChoices[] = { wxT("Load"), wxT("Input") };
	int ui_loadInputRadioButtonsNChoices = sizeof( ui_loadInputRadioButtonsChoices ) / sizeof( wxString );
	ui_loadInputRadioButtons = new wxRadioBox( sbPane2Center->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, ui_loadInputRadioButtonsNChoices, ui_loadInputRadioButtonsChoices, 1, wxRA_SPECIFY_COLS );
	ui_loadInputRadioButtons->SetSelection( 0 );
	bPane2CenterLeft->Add( ui_loadInputRadioButtons, 0, wxALL, 5 );


	sbPane2Center->Add( bPane2CenterLeft, 1, wxEXPAND, 5 );

	wxBoxSizer* bCenterRight;
	bCenterRight = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bPane2CenterRightTop;
	bPane2CenterRightTop = new wxBoxSizer( wxHORIZONTAL );

	ui_resistanceTag = new wxStaticText( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("Resistance"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_resistanceTag->Wrap( -1 );
	bPane2CenterRightTop->Add( ui_resistanceTag, 0, wxALL, 5 );

	ui_resistance = new wxTextCtrl( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2CenterRightTop->Add( ui_resistance, 0, wxALL, 0 );

	ui_resistanceUnits = new wxStaticText( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("Ohms"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_resistanceUnits->Wrap( -1 );
	bPane2CenterRightTop->Add( ui_resistanceUnits, 0, wxALL, 5 );


	bCenterRight->Add( bPane2CenterRightTop, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane2CenterRightBottom;
	bPane2CenterRightBottom = new wxBoxSizer( wxHORIZONTAL );

	ui_reactanceTag = new wxStaticText( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("Reactance"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_reactanceTag->Wrap( -1 );
	bPane2CenterRightBottom->Add( ui_reactanceTag, 0, wxALL, 5 );

	ui_reactance = new wxTextCtrl( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2CenterRightBottom->Add( ui_reactance, 0, wxALL, 0 );

	ui_reactanceUnits = new wxStaticText( sbPane2Center->GetStaticBox(), wxID_ANY, wxT("Ohms"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_reactanceUnits->Wrap( -1 );
	bPane2CenterRightBottom->Add( ui_reactanceUnits, 0, wxALL, 5 );


	bCenterRight->Add( bPane2CenterRightBottom, 1, wxEXPAND, 5 );


	sbPane2Center->Add( bCenterRight, 1, wxEXPAND, 5 );


	bPane2->Add( sbPane2Center, 1, wxEXPAND, 5 );


	bPane2->Add( 0, 0, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbPane2Right;
	sbPane2Right = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Actions") ), wxHORIZONTAL );

	wxBoxSizer* bPane2RightLeft;
	bPane2RightLeft = new wxBoxSizer( wxVERTICAL );

	ui_plotZ = new wxButton( sbPane2Right->GetStaticBox(), wxID_ANY, wxT("Plot Z"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2RightLeft->Add( ui_plotZ, 0, wxALL, 5 );

	ui_plotVI = new wxButton( sbPane2Right->GetStaticBox(), wxID_ANY, wxT("Plot V/I"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2RightLeft->Add( ui_plotVI, 0, wxALL, 5 );

	ui_tuner = new wxButton( sbPane2Right->GetStaticBox(), wxID_ANY, wxT("Tuner"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane2RightLeft->Add( ui_tuner, 0, wxALL, 5 );


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
	bPane3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bPane3Line1;
	bPane3Line1 = new wxBoxSizer( wxHORIZONTAL );

	ui_characteristicZ0Tag = new wxStaticText( this, wxID_ANY, wxT("Characteristic Z0:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_characteristicZ0Tag->Wrap( -1 );
	bPane3Line1->Add( ui_characteristicZ0Tag, 0, wxALL, 5 );

	ui_characteristicZ0 = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_characteristicZ0->SetMinSize( wxSize( 200,-1 ) );

	bPane3Line1->Add( ui_characteristicZ0, 0, wxALL, 5 );


	bPane3Line1->Add( 0, 0, 1, 0, 5 );

	ui_matchedLineLossTag = new wxStaticText( this, wxID_ANY, wxT("Matched-Line Loss:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_matchedLineLossTag->Wrap( -1 );
	bPane3Line1->Add( ui_matchedLineLossTag, 0, wxALL, 5 );

	ui_matchedLineLoss = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_matchedLineLoss->SetMinSize( wxSize( 160,-1 ) );

	bPane3Line1->Add( ui_matchedLineLoss, 0, wxALL, 5 );


	bPane3->Add( bPane3Line1, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane3Line2;
	bPane3Line2 = new wxBoxSizer( wxHORIZONTAL );

	ui_velocityFactorTag = new wxStaticText( this, wxID_ANY, wxT("Velocity Factor:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_velocityFactorTag->Wrap( -1 );
	bPane3Line2->Add( ui_velocityFactorTag, 0, wxALL, 5 );

	ui_velocityFactor = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	bPane3Line2->Add( ui_velocityFactor, 0, wxALL, 5 );


	bPane3Line2->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_maxVoltageTag = new wxStaticText( this, wxID_ANY, wxT("Max Voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_maxVoltageTag->Wrap( -1 );
	bPane3Line2->Add( ui_maxVoltageTag, 0, wxALL, 5 );

	ui_maxVoltage = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	bPane3Line2->Add( ui_maxVoltage, 0, wxALL, 5 );


	bPane3Line2->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_totalMatchedLineLossTag = new wxStaticText( this, wxID_ANY, wxT("Total Matched-Line Loss"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_totalMatchedLineLossTag->Wrap( -1 );
	bPane3Line2->Add( ui_totalMatchedLineLossTag, 0, wxALL, 5 );

	ui_totalMatchedLineLoss = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	bPane3Line2->Add( ui_totalMatchedLineLoss, 0, wxALL, 5 );


	bPane3->Add( bPane3Line2, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane3Line3;
	bPane3Line3 = new wxBoxSizer( wxHORIZONTAL );

	ui_swrInputTag = new wxStaticText( this, wxID_ANY, wxT("SWR (Line Input):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_swrInputTag->Wrap( -1 );
	bPane3Line3->Add( ui_swrInputTag, 0, wxALL, 5 );

	ui_swrInput = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	bPane3Line3->Add( ui_swrInput, 0, wxALL, 5 );


	bPane3Line3->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_swrLoadTag = new wxStaticText( this, wxID_ANY, wxT("SWR (Load):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_swrLoadTag->Wrap( -1 );
	bPane3Line3->Add( ui_swrLoadTag, 0, wxALL, 5 );

	ui_swrLoad = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	bPane3Line3->Add( ui_swrLoad, 0, wxALL, 5 );


	bPane3Line3->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_rhoLoadTag = new wxStaticText( this, wxID_ANY, wxT("Rho (Load):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_rhoLoadTag->Wrap( -1 );
	bPane3Line3->Add( ui_rhoLoadTag, 0, wxALL, 5 );

	ui_rhoLoad = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	bPane3Line3->Add( ui_rhoLoad, 0, wxALL, 5 );


	bPane3->Add( bPane3Line3, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane3Line4;
	bPane3Line4 = new wxBoxSizer( wxHORIZONTAL );

	ui_addedLossTag = new wxStaticText( this, wxID_ANY, wxT("Additional Loss Due To SWR:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_addedLossTag->Wrap( -1 );
	bPane3Line4->Add( ui_addedLossTag, 0, wxALL, 5 );

	ui_addedLoss = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	bPane3Line4->Add( ui_addedLoss, 0, wxALL, 5 );


	bPane3Line4->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_totalLossTag = new wxStaticText( this, wxID_ANY, wxT("Total Line Loss:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_totalLossTag->Wrap( -1 );
	bPane3Line4->Add( ui_totalLossTag, 0, wxALL, 5 );

	ui_totalLoss = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	bPane3Line4->Add( ui_totalLoss, 0, wxALL, 5 );


	bPane3->Add( bPane3Line4, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane3Line5;
	bPane3Line5 = new wxBoxSizer( wxHORIZONTAL );

	ui_impedanceRectangularTag = new wxStaticText( this, wxID_ANY, wxT("Impedance at Input (Real/Imaginary):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_impedanceRectangularTag->Wrap( -1 );
	bPane3Line5->Add( ui_impedanceRectangularTag, 0, wxALL, 5 );

	ui_impedanceRectangular = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_impedanceRectangular->SetMinSize( wxSize( 200,-1 ) );

	bPane3Line5->Add( ui_impedanceRectangular, 0, wxALL, 5 );


	bPane3Line5->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_impedancePolarTag = new wxStaticText( this, wxID_ANY, wxT("Impedance at Input (Polar):"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	ui_impedancePolarTag->Wrap( -1 );
	bPane3Line5->Add( ui_impedancePolarTag, 0, wxALL, 5 );

	ui_impedancePolar = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	ui_impedancePolar->SetMinSize( wxSize( 200,-1 ) );

	bPane3Line5->Add( ui_impedancePolar, 0, wxALL, 5 );


	bPane3->Add( bPane3Line5, 1, wxEXPAND, 5 );


	bMainWindow->Add( bPane3, 0, wxEXPAND, 5 );


	this->SetSizer( bMainWindow );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onFileLoad ), this, ui_fileMenuLoad->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onFileSave ), this, ui_fileMenuSave->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onFileExit ), this, ui_fileMenuExit->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onHelpInfo ), this, ui_helpInfo->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onHelpAbout ), this, ui_helpAbout->GetId());
	ui_cableType->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( tlineUI::onCableTypeSelected ), NULL, this );
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
	ui_cableType->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( tlineUI::onCableTypeSelected ), NULL, this );
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
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxGridSizer* gParameters;
	gParameters = new wxGridSizer( 7, 3, 0, 0 );

	dl_frequencyTag = new wxStaticText( this, wxID_ANY, wxT("Frequency (MHz)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_frequencyTag->Wrap( -1 );
	gParameters->Add( dl_frequencyTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_frequencyStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_frequencyStr->SetMinSize( wxSize( 150,-1 ) );

	gParameters->Add( dl_frequencyStr, 0, wxALL, 5 );


	gParameters->Add( 0, 0, 1, wxEXPAND, 5 );

	dl_attenuationTag = new wxStaticText( this, wxID_ANY, wxT("Attenuation (dB/100 feet)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_attenuationTag->Wrap( -1 );
	gParameters->Add( dl_attenuationTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_attenuationStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_attenuationStr->SetMinSize( wxSize( 150,-1 ) );

	gParameters->Add( dl_attenuationStr, 0, wxALL, 0 );


	gParameters->Add( 0, 0, 1, wxEXPAND, 5 );

	dl_velocityFactorTag = new wxStaticText( this, wxID_ANY, wxT("Velocity Factor (0.00 to 1.00)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_velocityFactorTag->Wrap( -1 );
	gParameters->Add( dl_velocityFactorTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_velocityFactorStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_velocityFactorStr->SetMinSize( wxSize( 150,-1 ) );

	gParameters->Add( dl_velocityFactorStr, 0, wxALL, 0 );


	gParameters->Add( 0, 0, 1, wxEXPAND, 5 );

	dl_cableResistanceTag = new wxStaticText( this, wxID_ANY, wxT("Cable Characteristic Resistance (Ohms)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableResistanceTag->Wrap( -1 );
	gParameters->Add( dl_cableResistanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_cableResistanceStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableResistanceStr->SetMinSize( wxSize( 150,-1 ) );

	gParameters->Add( dl_cableResistanceStr, 0, wxALL, 0 );

	dl_cableReactanceEstimatedTag = new wxStaticText( this, wxID_ANY, wxT("Estimated Reactance"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableReactanceEstimatedTag->Wrap( -1 );
	gParameters->Add( dl_cableReactanceEstimatedTag, 0, wxALL, 5 );

	dl_cableReactanceTag = new wxStaticText( this, wxID_ANY, wxT("Cable Characteristic Reactance (Ohms)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableReactanceTag->Wrap( -1 );
	gParameters->Add( dl_cableReactanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_cableReactanceStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableReactanceStr->SetMinSize( wxSize( 150,-1 ) );

	gParameters->Add( dl_cableReactanceStr, 0, wxALL, 0 );

	dl_cableReactanceEstimatedStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	dl_cableReactanceEstimatedStr->SetMinSize( wxSize( 200,-1 ) );

	gParameters->Add( dl_cableReactanceEstimatedStr, 0, wxALL, 5 );

	dl_cableVoltageLimitTag = new wxStaticText( this, wxID_ANY, wxT("Cable Voltage Limit (Volts)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableVoltageLimitTag->Wrap( -1 );
	gParameters->Add( dl_cableVoltageLimitTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_cableVoltageLimitStr = new wxTextCtrl( this, wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_cableVoltageLimitStr->SetMinSize( wxSize( 150,-1 ) );

	gParameters->Add( dl_cableVoltageLimitStr, 0, wxALL, 0 );

	dl_useEstimatedReactanceButton = new wxButton( this, wxID_ANY, wxT("Use Estimated Reactance"), wxDefaultPosition, wxDefaultSize, 0 );
	gParameters->Add( dl_useEstimatedReactanceButton, 0, wxALL, 5 );

	dl_hiddenPad = new wxStaticText( this, wxID_ANY, wxT("Hidden Pad"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_hiddenPad->Wrap( -1 );
	dl_hiddenPad->Hide();

	gParameters->Add( dl_hiddenPad, 0, wxALL, 5 );

	dl_okButton = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	gParameters->Add( dl_okButton, 0, wxALL, 5 );


	this->SetSizer( gParameters );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	dl_attenuationStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onAttenuationSelected ), NULL, this );
	dl_velocityFactorStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onVelocityFactorSelected ), NULL, this );
	dl_cableResistanceStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableResistanceSelected ), NULL, this );
	dl_cableReactanceStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableReactanceSelected ), NULL, this );
	dl_cableVoltageLimitStr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableVoltageLimitSelected ), NULL, this );
	dl_useEstimatedReactanceButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( userLineDialog::onUseEstimatedReactanceClicked ), NULL, this );
	dl_okButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( userLineDialog::onOkClicked ), NULL, this );
}

userLineDialog::~userLineDialog()
{
	// Disconnect Events
	dl_attenuationStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onAttenuationSelected ), NULL, this );
	dl_velocityFactorStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onVelocityFactorSelected ), NULL, this );
	dl_cableResistanceStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableResistanceSelected ), NULL, this );
	dl_cableReactanceStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableReactanceSelected ), NULL, this );
	dl_cableVoltageLimitStr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( userLineDialog::onCableVoltageLimitSelected ), NULL, this );
	dl_useEstimatedReactanceButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( userLineDialog::onUseEstimatedReactanceClicked ), NULL, this );
	dl_okButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( userLineDialog::onOkClicked ), NULL, this );

}

helpInfoDialog::helpInfoDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bHelpInfo;
	bHelpInfo = new wxBoxSizer( wxVERTICAL );

	dl_htmlWindow = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxSize( 700,600 ), wxHW_SCROLLBAR_AUTO|wxHSCROLL|wxVSCROLL );
	bHelpInfo->Add( dl_htmlWindow, 0, wxALL, 5 );


	this->SetSizer( bHelpInfo );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	dl_htmlWindow->Connect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( helpInfoDialog::onLinkClicked ), NULL, this );
}

helpInfoDialog::~helpInfoDialog()
{
	// Disconnect Events
	dl_htmlWindow->Disconnect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( helpInfoDialog::onLinkClicked ), NULL, this );

}

helpAboutDialog::helpAboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

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
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bTunerOuter;
	bTunerOuter = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bTunerInner;
	bTunerInner = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bTunerLeft;
	bTunerLeft = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbTunerParameterContainer;
	sbTunerParameterContainer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Parameters") ), wxVERTICAL );

	wxGridSizer* gTunerParameters;
	gTunerParameters = new wxGridSizer( 6, 2, 0, 0 );

	dl_tunerSourceResistanceTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Source Resistance"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerSourceResistanceTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerSourceResistanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerSourceResistance = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	gTunerParameters->Add( dl_tunerSourceResistance, 0, wxALL, 0 );

	dl_tunerSourceReactanceTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Source Reactance"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerSourceReactanceTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerSourceReactanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerSourceReactance = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	gTunerParameters->Add( dl_tunerSourceReactance, 0, wxALL, 0 );

	dl_tunerLoadResistanceTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Load Resistance"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerLoadResistanceTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerLoadResistanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerLoadResistance = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	gTunerParameters->Add( dl_tunerLoadResistance, 0, wxALL, 0 );

	dl_tunerLoadReactanceTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Load Reactance"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerLoadReactanceTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerLoadReactanceTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerLoadReactance = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	gTunerParameters->Add( dl_tunerLoadReactance, 0, wxALL, 0 );

	dl_tunerQtag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Desired Q"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerQtag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerQtag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerQ = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, 0 );
	gTunerParameters->Add( dl_tunerQ, 0, wxALL, 0 );

	dl_tunerFrequencyTag = new wxStaticText( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("Frequency (MHz)"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerFrequencyTag->Wrap( -1 );
	gTunerParameters->Add( dl_tunerFrequencyTag, 0, wxALIGN_RIGHT|wxALL, 5 );

	dl_tunerFrequency = new wxTextCtrl( sbTunerParameterContainer->GetStaticBox(), wxID_ANY, wxT("XXXXXX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE );
	gTunerParameters->Add( dl_tunerFrequency, 0, wxALL, 5 );


	sbTunerParameterContainer->Add( gTunerParameters, 1, wxEXPAND|wxSHAPED, 5 );


	bTunerLeft->Add( sbTunerParameterContainer, 1, wxEXPAND|wxSHAPED, 5 );

	dl_tunerParameterNote = new wxStaticText( this, wxID_ANY, wxT("Parameter note: The tuner can be located in the shack, or it can be located at the antenna. Therefore, rather than having this tool fill in the values from the main screen, we leave it up to the user to fill in the source and load impedances.\n\nRegarding the \"Q\" parameter, typically, one will specify a fairly low Q.  Try a value less than 10 for the Q.\n"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerParameterNote->Wrap( 300 );
	bTunerLeft->Add( dl_tunerParameterNote, 0, wxALL, 5 );

	dl_tunerTopologyNote = new wxStaticText( this, wxID_ANY, wxT("Topology note: The radio buttons list components in order, from source to load, where Lpar is a parallel inductor, Cpar is a parallel capacitor, Lser is a series inductor, and Cser is a series capacitor.  "), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerTopologyNote->Wrap( 300 );
	bTunerLeft->Add( dl_tunerTopologyNote, 0, wxALL, 5 );


	bTunerInner->Add( bTunerLeft, 1, wxEXPAND|wxSHAPED, 5 );

	wxBoxSizer* bTunerRight;
	bTunerRight = new wxBoxSizer( wxVERTICAL );

	wxString dl_topologyChoices[] = { wxT("High Pass (Lpar Cser)"), wxT("Low Pass (Cpar Lser)"), wxT("Low Pass (Lser Cpar)"), wxT("High Pass (Cser Lpar)"), wxT("High Pass PI (Lpar Cser Lpar)"), wxT("Low Pass PI (Cpar Lser Cpar)"), wxT("High Pass T (Cser Lpar Cser)"), wxT("Low Pass T (Lser Cpar Lser)"), wxT("High Pass (Lpar Cser Lpar Cser)"), wxT("High Pass (Cser Lpar Cser Lpar)"), wxT("Low Pass (Cpar Lser Cpar Lser)"), wxT("Low Pass (Lser Cpar Lser Cpar)"), wxT("Band Pass (Lpar Cser Cpar Lser)"), wxT("Band Pass (Lser Cpar Cser Lpar)"), wxT("Band Pass (Cpar Lser Lpar Cser)"), wxT("Band Pass (Cser Lpar Lser Cpar)") };
	int dl_topologyNChoices = sizeof( dl_topologyChoices ) / sizeof( wxString );
	dl_topology = new wxRadioBox( this, wxID_ANY, wxT("Topology"), wxDefaultPosition, wxDefaultSize, dl_topologyNChoices, dl_topologyChoices, 1, wxRA_SPECIFY_COLS );
	dl_topology->SetSelection( 0 );
	bTunerRight->Add( dl_topology, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	dl_tunerCalculateButton = new wxButton( this, wxID_ANY, wxT("Calculate and Display"), wxDefaultPosition, wxDefaultSize, 0 );
	bTunerRight->Add( dl_tunerCalculateButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	dl_tunerOKbutton = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bTunerRight->Add( dl_tunerOKbutton, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bTunerInner->Add( bTunerRight, 1, wxEXPAND, 5 );


	bTunerOuter->Add( bTunerInner, 1, wxEXPAND, 5 );

	dl_tunerCredit = new wxStaticText( this, wxID_ANY, wxT("This portion of tline is based on a Javascript implementation by John Wetherell:\n\nhttp://home.sandiego.edu/~ekim/e194rfs01/jwmatcher/matcher2.html"), wxDefaultPosition, wxDefaultSize, 0 );
	dl_tunerCredit->Wrap( -1 );
	bTunerOuter->Add( dl_tunerCredit, 0, wxALL, 5 );


	this->SetSizer( bTunerOuter );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	dl_tunerSourceResistance->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onSourceResistance ), NULL, this );
	dl_tunerSourceReactance->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onSourceReactance ), NULL, this );
	dl_tunerLoadResistance->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onLoadResistance ), NULL, this );
	dl_tunerLoadReactance->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onLoadReactance ), NULL, this );
	dl_tunerQ->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onQ ), NULL, this );
	dl_tunerFrequency->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTUnerQSelected ), NULL, this );
	dl_topology->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( tunerDialog::onTunerTopologySelected ), NULL, this );
	dl_tunerCalculateButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tunerDialog::onTunerCalculateClicked ), NULL, this );
	dl_tunerOKbutton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tunerDialog::onTunerOKclicked ), NULL, this );
}

tunerDialog::~tunerDialog()
{
	// Disconnect Events
	dl_tunerSourceResistance->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onSourceResistance ), NULL, this );
	dl_tunerSourceReactance->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onSourceReactance ), NULL, this );
	dl_tunerLoadResistance->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onLoadResistance ), NULL, this );
	dl_tunerLoadReactance->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onLoadReactance ), NULL, this );
	dl_tunerQ->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onQ ), NULL, this );
	dl_tunerFrequency->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tunerDialog::onTUnerQSelected ), NULL, this );
	dl_topology->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( tunerDialog::onTunerTopologySelected ), NULL, this );
	dl_tunerCalculateButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tunerDialog::onTunerCalculateClicked ), NULL, this );
	dl_tunerOKbutton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tunerDialog::onTunerOKclicked ), NULL, this );

}
