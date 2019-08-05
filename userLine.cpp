// Copyright 2019 Steven A. Falco <stevenfalco@gmail.com>
//
// This file is part of tline.
//
//  tline is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  tline is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with tline.  If not, see <https://www.gnu.org/licenses/>.

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include "userLine.h"

#ifndef WX_PRECOMP
#include "wx/utils.h"
#include "wx/dialog.h"
#include "wx/button.h"
#include "wx/stattext.h"
#include "wx/textctrl.h"
#include "wx/intl.h"
#include "wx/sizer.h"
#endif

#if wxUSE_STATLINE
#include "wx/statline.h"
#endif

const char userLinePromptString[] = "Input Text";

// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

static const int wxID_TEXT = 3000;

// ============================================================================
// implementation
// ============================================================================

// ----------------------------------------------------------------------------
// userLineDialog
// ----------------------------------------------------------------------------

wxBEGIN_EVENT_TABLE(userLineDialog, wxDialog)
EVT_BUTTON(wxID_OK, userLineDialog::OnOK)
wxEND_EVENT_TABLE()

	wxIMPLEMENT_CLASS(userLineDialog, wxDialog);

bool userLineDialog::Create(wxWindow *parent,
		const wxString& message,
		const wxString& caption,
		const wxString& value,
		long style,
		const wxPoint& pos)
{
	// Do not pass style to GetParentForModalDialog() as wxDIALOG_NO_PARENT
	// has the same numeric value as wxTE_MULTILINE and so attempting to create
	// a dialog for editing multiline text would also prevent it from having a
	// parent which is undesirable. As it is, we can't create a text entry
	// dialog without a parent which is not ideal neither but is a much less
	// important problem.
	if ( !wxDialog::Create(GetParentForModalDialog(parent, 0),
				wxID_ANY, caption,
				pos, wxDefaultSize,
				wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER) )
	{
		return false;
	}

	m_dialogStyle = style;
	m_value = value;

	wxBeginBusyCursor();

	wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );

	wxSizerFlags flagsBorder2;
	flagsBorder2.DoubleBorder();

#if wxUSE_STATTEXT
	// 1) text message
	topsizer->Add(CreateTextSizer(message), flagsBorder2);
#endif

	// 2) text ctrl
	m_textctrl = new wxTextCtrl(this, wxID_TEXT, value,
			wxDefaultPosition, wxSize(300, wxDefaultCoord),
			style & ~userLineDialogStyle);

	topsizer->Add(m_textctrl,
			wxSizerFlags(style & wxTE_MULTILINE ? 1 : 0).
			Expand().
			TripleBorder(wxLEFT | wxRIGHT));

	// 3) buttons if any
	wxSizer *buttonSizer = CreateSeparatedButtonSizer(style & (wxOK | wxCANCEL));
	if ( buttonSizer )
	{
		topsizer->Add(buttonSizer, wxSizerFlags(flagsBorder2).Expand());
	}

	SetAutoLayout( true );
	SetSizer( topsizer );

	topsizer->SetSizeHints( this );
	topsizer->Fit( this );

	if ( style & wxCENTRE )
		Centre( wxBOTH );

	wxEndBusyCursor();

	return true;
}

bool userLineDialog::TransferDataToWindow()
{
	if ( m_textctrl )
	{
		m_textctrl->SetValue(m_value);
		m_textctrl->SetFocus();
	}

	return wxDialog::TransferDataToWindow();
}

bool userLineDialog::TransferDataFromWindow()
{
	if ( m_textctrl )
	{
		m_value = m_textctrl->GetValue();
	}

	return wxDialog::TransferDataFromWindow();
}

void userLineDialog::OnOK(wxCommandEvent& WXUNUSED(event) )
{
	if ( Validate() && TransferDataFromWindow() )
	{
		EndModal( wxID_OK );
	}
}

void userLineDialog::SetMaxLength(unsigned long len)
{
	if ( m_textctrl )
	{
		m_textctrl->SetMaxLength(len);
	}
}

void userLineDialog::SetValue(const wxString& val)
{
	m_value = val;

	if ( m_textctrl )
	{
		m_textctrl->SetValue(val);
	}
}
