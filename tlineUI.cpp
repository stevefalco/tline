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

	m_menubar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	m_fileMenuExit = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( m_fileMenuExit );

	m_menubar->Append( fileMenu, wxT("File") );

	helpMenu = new wxMenu();
	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( helpMenu, wxID_ANY, wxString( wxT("Help") ) , wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( m_menuItem2 );

	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( helpMenu, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( m_menuItem3 );

	m_menubar->Append( helpMenu, wxT("Help") );

	this->SetMenuBar( m_menubar );

	wxBoxSizer* bMainWindow;
	bMainWindow = new wxBoxSizer( wxVERTICAL );

	m_programTitle = new wxStaticText( this, wxID_ANY, wxT("program title"), wxDefaultPosition, wxDefaultSize, 0 );
	m_programTitle->Wrap( -1 );
	bMainWindow->Add( m_programTitle, 0, wxALL, 5 );

	m_cableType = new wxComboBox( this, wxID_ANY, wxT("RG-8U"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_cableType->Append( wxT("RG-6 (Belden 8215)") );
	m_cableType->Append( wxT("RG-8 (TMS LMR400)") );
	m_cableType->Append( wxT("RG-8 (Belden 9913/9086)") );
	m_cableType->Append( wxT("RG-8 (DX Engineering)") );
	m_cableType->Append( wxT("RG-8 (Wireman CQ106)") );
	m_cableType->Append( wxT("RG-8A (Belden 8237)") );
	m_cableType->Append( wxT("RG-8X (Belden 9258)") );
	m_cableType->Append( wxT("RG-8X (DX Engineering)") );
	m_cableType->Append( wxT("RG-8X (TMS LMR240)") );
	m_cableType->Append( wxT("RG-11 Foam (Belden 8213)") );
	m_cableType->Append( wxT("RG-11 (DX Engineering)") );
	m_cableType->Append( wxT("RG-11A (Belden 8261)") );
	m_cableType->Append( wxT("RG-58 (TMS LMR200)") );
	m_cableType->Append( wxT("RG-58A Foam (Belden 8219)") );
	m_cableType->Append( wxT("RG-58A (Belden 8259)") );
	m_cableType->Append( wxT("RG-58A (DX Engineering)") );
	m_cableType->Append( wxT("RG-59 Foam (Belden 8212)") );
	m_cableType->Append( wxT("RG-59B (Belden 8263)") );
	m_cableType->Append( wxT("RG-62A (Belden 9269)") );
	m_cableType->Append( wxT("RG-142/303 High-Temp. Teflon") );
	m_cableType->Append( wxT("RG-174 (Belden 8216)") );
	m_cableType->Append( wxT("RG-213 (Belden 8267)") );
	m_cableType->Append( wxT("RG-213 (DX Engineering)") );
	m_cableType->Append( wxT("RG-218A (ex RG-17)") );
	m_cableType->Append( wxT("RG-400 (DX Engineering)") );
	m_cableType->Append( wxT("DX Engineering DXE-400MAX") );
	m_cableType->Append( wxT("1/2-inch, LMR500") );
	m_cableType->Append( wxT("0.59-inch, LMR600") );
	m_cableType->Append( wxT("1.2-inch, LMR1200") );
	m_cableType->Append( wxT("1/2-inch 50-Ohm Hardline") );
	m_cableType->Append( wxT("1/2-inch 75-Ohm Hardline") );
	m_cableType->Append( wxT("7/8-inch 50-Ohm Hardline") );
	m_cableType->Append( wxT("7/8-inch 75-Ohm Hardline") );
	m_cableType->Append( wxT("1/2-inch LDF4-50A Andrew Heliax") );
	m_cableType->Append( wxT("7/8-inch LDF5-50A Andrew Heliax") );
	m_cableType->Append( wxT("1-1/4 Inch LDF6-50A Andrew Heliax") );
	m_cableType->Append( wxT("300-Ohm Tubular Transmitting Line, #20 Wire") );
	m_cableType->Append( wxT("450-Ohm Window Line, Wireman #551") );
	m_cableType->Append( wxT("450-Ohm Window Line, Wireman #554") );
	m_cableType->Append( wxT("600-Ohm Open-Wire Ladder Line, #12 Wire") );
	m_cableType->Append( wxT("User-Defined Transmission Line") );
	m_cableType->SetSelection( 1 );
	bMainWindow->Add( m_cableType, 0, wxALL, 5 );

	wxBoxSizer* bPane1;
	bPane1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bPane1Left;
	bPane1Left = new wxBoxSizer( wxHORIZONTAL );

	wxString m_unitsRadioButtonsChoices[] = { wxT("Feet"), wxT("Meters") };
	int m_unitsRadioButtonsNChoices = sizeof( m_unitsRadioButtonsChoices ) / sizeof( wxString );
	m_unitsRadioButtons = new wxRadioBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_unitsRadioButtonsNChoices, m_unitsRadioButtonsChoices, 1, wxRA_SPECIFY_COLS );
	m_unitsRadioButtons->SetSelection( 0 );
	bPane1Left->Add( m_unitsRadioButtons, 0, wxALL, 5 );


	bPane1->Add( bPane1Left, 0, wxALL, 5 );

	wxBoxSizer* bPane1Right;
	bPane1Right = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bPane1RightUpper;
	bPane1RightUpper = new wxBoxSizer( wxHORIZONTAL );

	m_cableLengthTag = new wxStaticText( this, wxID_ANY, wxT("Length:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cableLengthTag->Wrap( -1 );
	bPane1RightUpper->Add( m_cableLengthTag, 0, wxALL, 5 );

	m_cableLength = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bPane1RightUpper->Add( m_cableLength, 0, wxALL, 5 );

	m_lengthUnits = new wxStaticText( this, wxID_ANY, wxT("Feet"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lengthUnits->Wrap( -1 );
	bPane1RightUpper->Add( m_lengthUnits, 0, wxALL, 5 );


	bPane1RightUpper->Add( 40, 0, 1, wxALL, 5 );

	m_lambdaTag = new wxStaticText( this, wxID_ANY, wxT("Lambda:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lambdaTag->Wrap( -1 );
	bPane1RightUpper->Add( m_lambdaTag, 0, wxALL, 5 );

	m_lambda = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_lambda->Enable( false );

	bPane1RightUpper->Add( m_lambda, 0, wxALL, 5 );


	bPane1RightUpper->Add( 30, 0, 1, wxALL, 5 );

	m_frequencyTag = new wxStaticText( this, wxID_ANY, wxT("Frequency:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_frequencyTag->Wrap( -1 );
	bPane1RightUpper->Add( m_frequencyTag, 0, wxALL, 5 );

	m_frequency = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bPane1RightUpper->Add( m_frequency, 0, wxALL, 5 );

	m_frequencyUnits = new wxStaticText( this, wxID_ANY, wxT("MHz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_frequencyUnits->Wrap( -1 );
	bPane1RightUpper->Add( m_frequencyUnits, 0, wxALL, 5 );


	bPane1Right->Add( bPane1RightUpper, 1, wxEXPAND|wxSHAPED, 5 );

	m_wSuffixNote = new wxStaticText( this, wxID_ANY, wxT("Use \"w\" suffix for wavelength (for example, 0.25w)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_wSuffixNote->Wrap( -1 );
	bPane1Right->Add( m_wSuffixNote, 0, 0, 5 );


	bPane1->Add( bPane1Right, 1, wxEXPAND|wxSHAPED, 5 );


	bMainWindow->Add( bPane1, 1, wxALL, 5 );

	wxBoxSizer* bPane2;
	bPane2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bPane2Upper;
	bPane2Upper = new wxBoxSizer( wxHORIZONTAL );

	m_characteristicZ0Tag = new wxStaticText( this, wxID_ANY, wxT("Characteristic Z0:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_characteristicZ0Tag->Wrap( -1 );
	bPane2Upper->Add( m_characteristicZ0Tag, 0, wxALL, 5 );

	m_characteristicZ0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane2Upper->Add( m_characteristicZ0, 0, wxALL, 5 );


	bPane2Upper->Add( 0, 0, 1, 0, 5 );

	m_matchedLineLossTag = new wxStaticText( this, wxID_ANY, wxT("Matched-Line Loss:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_matchedLineLossTag->Wrap( -1 );
	bPane2Upper->Add( m_matchedLineLossTag, 0, wxALL, 5 );

	m_matchedLineLoss = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane2Upper->Add( m_matchedLineLoss, 0, wxALL, 5 );

	m_matchedLineLossUnits = new wxStaticText( this, wxID_ANY, wxT("dB/100 Feet"), wxDefaultPosition, wxDefaultSize, 0 );
	m_matchedLineLossUnits->Wrap( -1 );
	bPane2Upper->Add( m_matchedLineLossUnits, 0, wxALL, 5 );


	bPane2->Add( bPane2Upper, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane2Lower;
	bPane2Lower = new wxBoxSizer( wxHORIZONTAL );

	m_velocityFactorTag = new wxStaticText( this, wxID_ANY, wxT("Velocity Factor:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_velocityFactorTag->Wrap( -1 );
	bPane2Lower->Add( m_velocityFactorTag, 0, wxALL, 5 );

	m_velocityFactor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane2Lower->Add( m_velocityFactor, 0, wxALL, 5 );


	bPane2Lower->Add( 0, 0, 1, wxEXPAND, 5 );

	m_maxVoltageTag = new wxStaticText( this, wxID_ANY, wxT("Max Voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_maxVoltageTag->Wrap( -1 );
	bPane2Lower->Add( m_maxVoltageTag, 0, wxALL, 5 );

	m_maxVoltage = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane2Lower->Add( m_maxVoltage, 0, wxALL, 5 );

	m_maxVoltageUnits = new wxStaticText( this, wxID_ANY, wxT("V"), wxDefaultPosition, wxDefaultSize, 0 );
	m_maxVoltageUnits->Wrap( -1 );
	bPane2Lower->Add( m_maxVoltageUnits, 0, wxALL, 5 );


	bPane2Lower->Add( 0, 0, 1, wxEXPAND, 5 );

	m_totalMatchedLineLossTag = new wxStaticText( this, wxID_ANY, wxT("Total Matched-Line Loss"), wxDefaultPosition, wxDefaultSize, 0 );
	m_totalMatchedLineLossTag->Wrap( -1 );
	bPane2Lower->Add( m_totalMatchedLineLossTag, 0, wxALL, 5 );

	m_totalMatchedLineLoss = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bPane2Lower->Add( m_totalMatchedLineLoss, 0, wxALL, 5 );

	m_totalMatchedLineLossUnits = new wxStaticText( this, wxID_ANY, wxT("dB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_totalMatchedLineLossUnits->Wrap( -1 );
	bPane2Lower->Add( m_totalMatchedLineLossUnits, 0, wxALL, 5 );


	bPane2->Add( bPane2Lower, 1, wxEXPAND, 5 );


	bMainWindow->Add( bPane2, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane3;
	bPane3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bPane3Left;
	bPane3Left = new wxBoxSizer( wxVERTICAL );

	wxString m_sourceRadioButtonsChoices[] = { wxT("Normal"), wxT("Autec"), wxT("Noise Bridge") };
	int m_sourceRadioButtonsNChoices = sizeof( m_sourceRadioButtonsChoices ) / sizeof( wxString );
	m_sourceRadioButtons = new wxRadioBox( this, wxID_ANY, wxT("Source"), wxDefaultPosition, wxDefaultSize, m_sourceRadioButtonsNChoices, m_sourceRadioButtonsChoices, 1, wxRA_SPECIFY_COLS );
	m_sourceRadioButtons->SetSelection( 0 );
	bPane3Left->Add( m_sourceRadioButtons, 0, wxALL, 5 );


	bPane3->Add( bPane3Left, 1, wxEXPAND, 5 );

	wxBoxSizer* bPane3Center;
	bPane3Center = new wxBoxSizer( wxHORIZONTAL );

	wxString m_loadInputRadioButtonsChoices[] = { wxT("Load"), wxT("Input") };
	int m_loadInputRadioButtonsNChoices = sizeof( m_loadInputRadioButtonsChoices ) / sizeof( wxString );
	m_loadInputRadioButtons = new wxRadioBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_loadInputRadioButtonsNChoices, m_loadInputRadioButtonsChoices, 1, wxRA_SPECIFY_COLS );
	m_loadInputRadioButtons->SetSelection( 0 );
	bPane3Center->Add( m_loadInputRadioButtons, 0, wxALL, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Resistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer14->Add( m_staticText16, 0, wxALL, 5 );


	bSizer13->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Reactance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer15->Add( m_staticText17, 0, wxALL, 5 );


	bSizer13->Add( bSizer15, 1, wxEXPAND, 5 );


	bPane3Center->Add( bSizer13, 1, wxEXPAND, 5 );


	bPane3->Add( bPane3Center, 1, wxEXPAND, 5 );


	bMainWindow->Add( bPane3, 1, wxEXPAND, 5 );


	this->SetSizer( bMainWindow );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( tlineUI::onFileExit ), this, m_fileMenuExit->GetId());
	m_cableType->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( tlineUI::onCableTypeSelected ), NULL, this );
}

tlineUI::~tlineUI()
{
	// Disconnect Events
	m_cableType->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( tlineUI::onCableTypeSelected ), NULL, this );

}
