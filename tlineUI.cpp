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
	ui_fileMenuExit = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( ui_fileMenuExit );

	ui_menubar->Append( fileMenu, wxT("File") );

	helpMenu = new wxMenu();
	wxMenuItem* ui_menuItem2;
	ui_menuItem2 = new wxMenuItem( helpMenu, wxID_ANY, wxString( wxT("Help") ) , wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( ui_menuItem2 );

	wxMenuItem* ui_menuItem3;
	ui_menuItem3 = new wxMenuItem( helpMenu, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( ui_menuItem3 );

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
	ui_cableType->Append( wxT("1/2-inch 50-Ohm Hardline") );
	ui_cableType->Append( wxT("1/2-inch 75-Ohm Hardline") );
	ui_cableType->Append( wxT("7/8-inch 50-Ohm Hardline") );
	ui_cableType->Append( wxT("7/8-inch 75-Ohm Hardline") );
	ui_cableType->Append( wxT("1/2-inch LDF4-50A Andrew Heliax") );
	ui_cableType->Append( wxT("7/8-inch LDF5-50A Andrew Heliax") );
	ui_cableType->Append( wxT("1-1/4 Inch LDF6-50A Andrew Heliax") );
	ui_cableType->Append( wxT("300-Ohm Tubular Transmitting Line, #20 Wire") );
	ui_cableType->Append( wxT("450-Ohm Window Line, Wireman #551") );
	ui_cableType->Append( wxT("450-Ohm Window Line, Wireman #554") );
	ui_cableType->Append( wxT("600-Ohm Open-Wire Ladder Line, #12 Wire") );
	ui_cableType->Append( wxT("User-Defined Transmission Line") );
	ui_cableType->SetSelection( 0 );
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


	bPane1->Add( bPane1Left, 0, wxALL, 5 );

	wxStaticBoxSizer* sbPane1Right;
	sbPane1Right = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );

	wxBoxSizer* bPane1RightUpper;
	bPane1RightUpper = new wxBoxSizer( wxHORIZONTAL );

	ui_cableLengthTag = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Length:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_cableLengthTag->Wrap( -1 );
	bPane1RightUpper->Add( ui_cableLengthTag, 0, wxALL, 5 );

	ui_cableLength = new wxTextCtrl( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane1RightUpper->Add( ui_cableLength, 0, wxALL, 5 );

	ui_lengthUnits = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Feet"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_lengthUnits->Wrap( -1 );
	bPane1RightUpper->Add( ui_lengthUnits, 0, wxALL, 5 );


	bPane1RightUpper->Add( 40, 0, 1, wxALL, 5 );

	ui_lambdaTag = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Lambda:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_lambdaTag->Wrap( -1 );
	bPane1RightUpper->Add( ui_lambdaTag, 0, wxALL, 5 );

	ui_lambda = new wxTextCtrl( sbPane1Right->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ui_lambda->Enable( false );

	bPane1RightUpper->Add( ui_lambda, 0, wxALL, 5 );


	bPane1RightUpper->Add( 30, 0, 1, wxALL, 5 );

	ui_frequencyTag = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Frequency:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_frequencyTag->Wrap( -1 );
	bPane1RightUpper->Add( ui_frequencyTag, 0, wxALL, 5 );

	ui_frequency = new wxTextCtrl( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("7.00"), wxDefaultPosition, wxDefaultSize, 0 );
	bPane1RightUpper->Add( ui_frequency, 0, wxALL, 5 );

	ui_frequencyUnits = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("MHz"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_frequencyUnits->Wrap( -1 );
	bPane1RightUpper->Add( ui_frequencyUnits, 0, wxALL, 5 );


	sbPane1Right->Add( bPane1RightUpper, 1, wxEXPAND|wxSHAPED, 5 );

	ui_wSuffixNote = new wxStaticText( sbPane1Right->GetStaticBox(), wxID_ANY, wxT("Use \"w\" suffix for wavelength (for example, 0.25w)"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_wSuffixNote->Wrap( -1 );
	sbPane1Right->Add( ui_wSuffixNote, 0, 0, 5 );


	bPane1->Add( sbPane1Right, 1, wxEXPAND, 5 );


	bMainWindow->Add( bPane1, 1, wxALL|wxSHAPED, 5 );

	wxBoxSizer* bPane2;
	bPane2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bPane2Upper;
	bPane2Upper = new wxBoxSizer( wxHORIZONTAL );

	ui_characteristicZ0Tag = new wxStaticText( this, wxID_ANY, wxT("Characteristic Z0:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_characteristicZ0Tag->Wrap( -1 );
	bPane2Upper->Add( ui_characteristicZ0Tag, 0, wxALL, 5 );

	ui_characteristicZ0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	ui_characteristicZ0->SetMinSize( wxSize( 200,-1 ) );

	bPane2Upper->Add( ui_characteristicZ0, 0, wxALL, 5 );


	bPane2Upper->Add( 0, 0, 1, 0, 5 );

	ui_matchedLineLossTag = new wxStaticText( this, wxID_ANY, wxT("Matched-Line Loss:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_matchedLineLossTag->Wrap( -1 );
	bPane2Upper->Add( ui_matchedLineLossTag, 0, wxALL, 5 );

	ui_matchedLineLoss = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane2Upper->Add( ui_matchedLineLoss, 0, wxALL, 5 );

	ui_matchedLineLossUnits = new wxStaticText( this, wxID_ANY, wxT("dB/100 Feet"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_matchedLineLossUnits->Wrap( -1 );
	ui_matchedLineLossUnits->SetMinSize( wxSize( 100,-1 ) );

	bPane2Upper->Add( ui_matchedLineLossUnits, 0, wxALL, 5 );


	bPane2->Add( bPane2Upper, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane2Lower;
	bPane2Lower = new wxBoxSizer( wxHORIZONTAL );

	ui_velocityFactorTag = new wxStaticText( this, wxID_ANY, wxT("Velocity Factor:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_velocityFactorTag->Wrap( -1 );
	bPane2Lower->Add( ui_velocityFactorTag, 0, wxALL, 5 );

	ui_velocityFactor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane2Lower->Add( ui_velocityFactor, 0, wxALL, 5 );


	bPane2Lower->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_maxVoltageTag = new wxStaticText( this, wxID_ANY, wxT("Max Voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_maxVoltageTag->Wrap( -1 );
	bPane2Lower->Add( ui_maxVoltageTag, 0, wxALL, 5 );

	ui_maxVoltage = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane2Lower->Add( ui_maxVoltage, 0, wxALL, 5 );

	ui_maxVoltageUnits = new wxStaticText( this, wxID_ANY, wxT("V"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_maxVoltageUnits->Wrap( -1 );
	bPane2Lower->Add( ui_maxVoltageUnits, 0, wxALL, 5 );


	bPane2Lower->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_totalMatchedLineLossTag = new wxStaticText( this, wxID_ANY, wxT("Total Matched-Line Loss"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_totalMatchedLineLossTag->Wrap( -1 );
	bPane2Lower->Add( ui_totalMatchedLineLossTag, 0, wxALL, 5 );

	ui_totalMatchedLineLoss = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane2Lower->Add( ui_totalMatchedLineLoss, 0, wxALL, 5 );

	ui_totalMatchedLineLossUnits = new wxStaticText( this, wxID_ANY, wxT("dB"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_totalMatchedLineLossUnits->Wrap( -1 );
	bPane2Lower->Add( ui_totalMatchedLineLossUnits, 0, wxALL, 5 );


	bPane2->Add( bPane2Lower, 1, wxEXPAND, 5 );


	bMainWindow->Add( bPane2, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane3;
	bPane3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bPane3Left;
	bPane3Left = new wxBoxSizer( wxVERTICAL );

	wxString ui_sourceRadioButtonsChoices[] = { wxT("Normal"), wxT("Autec"), wxT("Noise Bridge") };
	int ui_sourceRadioButtonsNChoices = sizeof( ui_sourceRadioButtonsChoices ) / sizeof( wxString );
	ui_sourceRadioButtons = new wxRadioBox( this, wxID_ANY, wxT("Source"), wxDefaultPosition, wxDefaultSize, ui_sourceRadioButtonsNChoices, ui_sourceRadioButtonsChoices, 1, wxRA_SPECIFY_COLS );
	ui_sourceRadioButtons->SetSelection( 0 );
	bPane3Left->Add( ui_sourceRadioButtons, 0, wxALL, 5 );


	bPane3->Add( bPane3Left, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbPane3Center;
	sbPane3Center = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxHORIZONTAL );

	wxBoxSizer* bPane3CenterLeft;
	bPane3CenterLeft = new wxBoxSizer( wxVERTICAL );

	wxString ui_loadInputRadioButtonsChoices[] = { wxT("Load"), wxT("Input") };
	int ui_loadInputRadioButtonsNChoices = sizeof( ui_loadInputRadioButtonsChoices ) / sizeof( wxString );
	ui_loadInputRadioButtons = new wxRadioBox( sbPane3Center->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, ui_loadInputRadioButtonsNChoices, ui_loadInputRadioButtonsChoices, 1, wxRA_SPECIFY_COLS );
	ui_loadInputRadioButtons->SetSelection( 0 );
	bPane3CenterLeft->Add( ui_loadInputRadioButtons, 0, wxALL, 5 );


	sbPane3Center->Add( bPane3CenterLeft, 1, wxEXPAND, 5 );

	wxBoxSizer* bCenterRight;
	bCenterRight = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bPane3CenterRightTop;
	bPane3CenterRightTop = new wxBoxSizer( wxHORIZONTAL );

	ui_resistanceTag = new wxStaticText( sbPane3Center->GetStaticBox(), wxID_ANY, wxT("Resistance"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_resistanceTag->Wrap( -1 );
	bPane3CenterRightTop->Add( ui_resistanceTag, 0, wxALL, 5 );

	ui_resistance = new wxTextCtrl( sbPane3Center->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bPane3CenterRightTop->Add( ui_resistance, 0, wxALL, 5 );

	ui_resistanceUnits = new wxStaticText( sbPane3Center->GetStaticBox(), wxID_ANY, wxT("Ohms"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_resistanceUnits->Wrap( -1 );
	bPane3CenterRightTop->Add( ui_resistanceUnits, 0, wxALL, 5 );


	bCenterRight->Add( bPane3CenterRightTop, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane3CenterRightBottom;
	bPane3CenterRightBottom = new wxBoxSizer( wxHORIZONTAL );

	ui_reactanceTag = new wxStaticText( sbPane3Center->GetStaticBox(), wxID_ANY, wxT("Reactance"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_reactanceTag->Wrap( -1 );
	bPane3CenterRightBottom->Add( ui_reactanceTag, 0, wxALL, 5 );

	ui_reactance = new wxTextCtrl( sbPane3Center->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bPane3CenterRightBottom->Add( ui_reactance, 0, wxALL, 5 );

	ui_reactanceUnits = new wxStaticText( sbPane3Center->GetStaticBox(), wxID_ANY, wxT("Ohms"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_reactanceUnits->Wrap( -1 );
	bPane3CenterRightBottom->Add( ui_reactanceUnits, 0, wxALL, 5 );


	bCenterRight->Add( bPane3CenterRightBottom, 1, wxEXPAND, 5 );


	sbPane3Center->Add( bCenterRight, 1, wxEXPAND, 5 );


	bPane3->Add( sbPane3Center, 1, wxEXPAND, 5 );


	bPane3->Add( 0, 0, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbPane3Right;
	sbPane3Right = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Actions") ), wxVERTICAL );

	ui_button1 = new wxButton( sbPane3Right->GetStaticBox(), wxID_ANY, wxT("Graph V/I"), wxDefaultPosition, wxDefaultSize, 0 );
	sbPane3Right->Add( ui_button1, 0, wxALL, 5 );

	ui_button5 = new wxButton( sbPane3Right->GetStaticBox(), wxID_ANY, wxT("Graph Z"), wxDefaultPosition, wxDefaultSize, 0 );
	sbPane3Right->Add( ui_button5, 0, wxALL, 5 );

	ui_button2 = new wxButton( sbPane3Right->GetStaticBox(), wxID_ANY, wxT("Tuner"), wxDefaultPosition, wxDefaultSize, 0 );
	sbPane3Right->Add( ui_button2, 0, wxALL, 5 );


	bPane3->Add( sbPane3Right, 1, wxEXPAND, 5 );


	bMainWindow->Add( bPane3, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane4;
	bPane4 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bPane4Line1;
	bPane4Line1 = new wxBoxSizer( wxHORIZONTAL );

	ui_swrInputTag = new wxStaticText( this, wxID_ANY, wxT("SWR (Line Input):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_swrInputTag->Wrap( -1 );
	bPane4Line1->Add( ui_swrInputTag, 0, wxALL, 5 );

	ui_swrInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane4Line1->Add( ui_swrInput, 0, wxALL, 5 );


	bPane4Line1->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_swrLoadTag = new wxStaticText( this, wxID_ANY, wxT("SWR (Load):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_swrLoadTag->Wrap( -1 );
	bPane4Line1->Add( ui_swrLoadTag, 0, wxALL, 5 );

	ui_swrLoad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane4Line1->Add( ui_swrLoad, 0, wxALL, 5 );


	bPane4Line1->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_rhoLoadTag = new wxStaticText( this, wxID_ANY, wxT("Rho (Load):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_rhoLoadTag->Wrap( -1 );
	bPane4Line1->Add( ui_rhoLoadTag, 0, wxALL, 5 );

	ui_rhoLoad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane4Line1->Add( ui_rhoLoad, 0, wxALL, 5 );


	bPane4->Add( bPane4Line1, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane4Line2;
	bPane4Line2 = new wxBoxSizer( wxHORIZONTAL );

	ui_addedLossTag = new wxStaticText( this, wxID_ANY, wxT("Additional Loss Due To SWR:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_addedLossTag->Wrap( -1 );
	bPane4Line2->Add( ui_addedLossTag, 0, wxALL, 5 );

	ui_addedLoss = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane4Line2->Add( ui_addedLoss, 0, wxALL, 5 );

	ui_addedLossUnits = new wxStaticText( this, wxID_ANY, wxT("dB"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_addedLossUnits->Wrap( -1 );
	bPane4Line2->Add( ui_addedLossUnits, 0, wxALL, 5 );


	bPane4Line2->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_totalLossTag = new wxStaticText( this, wxID_ANY, wxT("Total Line Loss:"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_totalLossTag->Wrap( -1 );
	bPane4Line2->Add( ui_totalLossTag, 0, wxALL, 5 );

	ui_totalLoss = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane4Line2->Add( ui_totalLoss, 0, wxALL, 5 );

	ui_totalLossUnits = new wxStaticText( this, wxID_ANY, wxT("dB"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_totalLossUnits->Wrap( -1 );
	bPane4Line2->Add( ui_totalLossUnits, 0, wxALL, 5 );


	bPane4->Add( bPane4Line2, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane4Line3;
	bPane4Line3 = new wxBoxSizer( wxHORIZONTAL );

	ui_impedanceRectangularTag = new wxStaticText( this, wxID_ANY, wxT("Impedance at Input (Rea/Imaginary):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_impedanceRectangularTag->Wrap( -1 );
	bPane4Line3->Add( ui_impedanceRectangularTag, 0, wxALL, 5 );

	ui_impedanceRectangular = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane4Line3->Add( ui_impedanceRectangular, 0, wxALL, 5 );

	ui_impedanceRectangularUnits = new wxStaticText( this, wxID_ANY, wxT("Ohms"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_impedanceRectangularUnits->Wrap( -1 );
	bPane4Line3->Add( ui_impedanceRectangularUnits, 0, wxALL, 5 );


	bPane4Line3->Add( 0, 0, 1, wxEXPAND, 5 );

	ui_impedancePolarTag = new wxStaticText( this, wxID_ANY, wxT("Impedance at Input (Polar):"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_impedancePolarTag->Wrap( -1 );
	bPane4Line3->Add( ui_impedancePolarTag, 0, wxALL, 5 );

	ui_impedancePolar = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane4Line3->Add( ui_impedancePolar, 0, wxALL, 5 );

	ui_impedancePolarUnits = new wxStaticText( this, wxID_ANY, wxT("Ohms"), wxDefaultPosition, wxDefaultSize, 0 );
	ui_impedancePolarUnits->Wrap( -1 );
	bPane4Line3->Add( ui_impedancePolarUnits, 0, wxALL, 5 );


	bPane4->Add( bPane4Line3, 1, wxEXPAND, 5 );


	bMainWindow->Add( bPane4, 1, wxEXPAND, 5 );


	this->SetSizer( bMainWindow );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onFileExit ), this, ui_fileMenuExit->GetId());
	ui_cableType->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( tlineUI::onCableTypeSelected ), NULL, this );
	ui_unitsRadioButtons->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( tlineUI::onUnitsSelected ), NULL, this );
	ui_cableLength->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onLengthSelected ), NULL, this );
	ui_frequency->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onFrequencySelected ), NULL, this );
}

tlineUI::~tlineUI()
{
	// Disconnect Events
	ui_cableType->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( tlineUI::onCableTypeSelected ), NULL, this );
	ui_unitsRadioButtons->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( tlineUI::onUnitsSelected ), NULL, this );
	ui_cableLength->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onLengthSelected ), NULL, this );
	ui_frequency->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( tlineUI::onFrequencySelected ), NULL, this );

}
