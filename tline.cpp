///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jul 29 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "tline.h"

///////////////////////////////////////////////////////////////////////////

tline::tline( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	file = new wxMenu();
	m_menubar1->Append( file, wxT("File") );

	help = new wxMenu();
	m_menubar1->Append( help, wxT("Help") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("program title"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 0, wxALL, 5 );

	m_comboBox1 = new wxComboBox( this, wxID_ANY, wxT("RG-8U"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_comboBox1->Append( wxT("RG-6 (Belden 8215)") );
	m_comboBox1->Append( wxT("RG-8 Type, TMS LMR400") );
	m_comboBox1->Append( wxT("RG-8 Type, Belden 9913/9086") );
	m_comboBox1->Append( wxT("RG-8A (Belden 8237)") );
	m_comboBox1->Append( wxT("RG-8 Type, Wireman CQ106") );
	m_comboBox1->Append( wxT("RG-8X Type, TMS LMR240") );
	m_comboBox1->Append( wxT("RG-8X (Belden 9258)") );
	m_comboBox1->Append( wxT("RG-11 Foam (Belden 8213)") );
	m_comboBox1->Append( wxT("RG-11A (Belden 8261)") );
	m_comboBox1->Append( wxT("RG-58 Type, TMS LMR200") );
	m_comboBox1->Append( wxT("RG-58A Foam (Belden 8219)") );
	m_comboBox1->Append( wxT("RG-58A (Belden 8259)") );
	m_comboBox1->Append( wxT("RG-59 Foam (Belden 8212)") );
	m_comboBox1->Append( wxT("RG-59B (Belden 8263)") );
	m_comboBox1->Append( wxT("RG-62A (Belden 9269)") );
	m_comboBox1->Append( wxT("RG-142/303 High-Temp. Teflon") );
	m_comboBox1->Append( wxT("RG-174 (Belden 8216)") );
	m_comboBox1->Append( wxT("RG-213 (Belden 8267)") );
	m_comboBox1->Append( wxT("RG-218A (ex RG-17)") );
	m_comboBox1->Append( wxT("1/2-inch, LMR500") );
	m_comboBox1->Append( wxT("0.59-inch, LMR600") );
	m_comboBox1->Append( wxT("1.2-inch, LMR1200") );
	m_comboBox1->Append( wxT("1/2-inch 50-Ohm Hardline") );
	m_comboBox1->Append( wxT("1/2-inch 75-Ohm Hardline") );
	m_comboBox1->Append( wxT("7/8-inch 50-Ohm Hardline") );
	m_comboBox1->Append( wxT("7/8-inch 75-Ohm Hardline") );
	m_comboBox1->Append( wxT("1/2-inch LDF4-50A Andrew Heliax") );
	m_comboBox1->Append( wxT("7/8-inch LDF5-50A Andrew Heliax") );
	m_comboBox1->Append( wxT("1-1/4 Inch LDF6-50A Andrew Heliax") );
	m_comboBox1->Append( wxT("300-Ohm Tubular Transmitting Line, #20 Wire") );
	m_comboBox1->Append( wxT("450-Ohm Window Line, Wireman #551") );
	m_comboBox1->Append( wxT("450-Ohm Window Line, Wireman #554") );
	m_comboBox1->Append( wxT("600-Ohm Open-Wire Ladder Line, #12 Wire") );
	m_comboBox1->Append( wxT("User-Defined Transmission Line") );
	m_comboBox1->Append( wxEmptyString );
	m_comboBox1->SetSelection( 1 );
	bSizer3->Add( m_comboBox1, 0, wxALL, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	wxString m_radioBox1Choices[] = { wxT("Feet"), wxT("Meters") };
	int m_radioBox1NChoices = sizeof( m_radioBox1Choices ) / sizeof( wxString );
	m_radioBox1 = new wxRadioBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_radioBox1NChoices, m_radioBox1Choices, 1, wxRA_SPECIFY_COLS );
	m_radioBox1->SetSelection( 0 );
	bSizer4->Add( m_radioBox1, 0, wxALL, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Length:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL, 5 );

	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_textCtrl1, 0, wxALL, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Feet"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer6->Add( m_staticText4, 0, wxALL, 5 );

	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("Feet"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	bSizer6->Add( m_staticText41, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Lambda"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer6->Add( m_staticText5, 0, wxALL, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Frequency"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer6->Add( m_staticText6, 0, wxALL, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("MHz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer6->Add( m_staticText7, 0, wxALL, 5 );

	m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_textCtrl3, 0, wxALL, 5 );


	bSizer9->Add( bSizer6, 1, wxEXPAND, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Use \"w\" suffix for wavelength (for example, 0.25w)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer9->Add( m_staticText8, 0, wxALL, 5 );


	bSizer4->Add( bSizer9, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Characteristic Z0:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer10->Add( m_staticText12, 0, wxALL, 5 );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Impedance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer10->Add( m_staticText13, 0, wxALL, 5 );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Matched-Line Loss:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer10->Add( m_staticText15, 0, wxALL, 5 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("LineLoss"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer10->Add( m_staticText16, 0, wxALL, 5 );


	bSizer3->Add( bSizer10, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText121 = new wxStaticText( this, wxID_ANY, wxT("Velocity Factor:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText121->Wrap( -1 );
	bSizer101->Add( m_staticText121, 0, wxALL, 5 );

	m_staticText131 = new wxStaticText( this, wxID_ANY, wxT("VFactor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131->Wrap( -1 );
	bSizer101->Add( m_staticText131, 0, wxALL, 5 );

	m_staticText151 = new wxStaticText( this, wxID_ANY, wxT("Max Voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	bSizer101->Add( m_staticText151, 0, wxALL, 5 );

	m_staticText161 = new wxStaticText( this, wxID_ANY, wxT("MaxV"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText161->Wrap( -1 );
	bSizer101->Add( m_staticText161, 0, wxALL, 5 );

	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Total Matched-Line Loss:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer101->Add( m_staticText25, 0, wxALL, 5 );

	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("LossDB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer101->Add( m_staticText26, 0, wxALL, 5 );


	bSizer3->Add( bSizer101, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );
}

tline::~tline()
{
}
