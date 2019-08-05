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


#ifndef __USER_LINE__
#define __USER_LINE__

#include "wx/defs.h"

#include "wx/dialog.h"

#if wxUSE_VALIDATORS
#include "wx/valtext.h"
#include "wx/textctrl.h"
#endif

class WXDLLIMPEXP_FWD_CORE wxTextCtrl;

extern WXDLLIMPEXP_DATA_CORE(const char) userLinePromptString[];

#define userLineDialogStyle (wxOK | wxCANCEL | wxCENTRE)

// ----------------------------------------------------------------------------
// userLineDialog: a dialog with text control, [ok] and [cancel] buttons
// ----------------------------------------------------------------------------

class userLineDialog : public wxDialog
{
	public:
		userLineDialog()
		{
			m_textctrlAttenuation = NULL;
			m_textctrlVelocityFactor = NULL;
		}

		userLineDialog(wxWindow *parent,
				const wxString& message,
				const wxString& caption = userLinePromptString,
				const wxString& valueAttenuation = wxEmptyString,
				const wxString& valueVelocityFactor = wxEmptyString,
				long style = userLineDialogStyle,
				const wxPoint& pos = wxDefaultPosition)
		{
			Create(parent, message, caption, valueAttenuation,
					valueVelocityFactor, style, pos);
		}

		bool Create(wxWindow *parent,
				const wxString& message,
				const wxString& caption = userLinePromptString,
				const wxString& valueAttenuation = wxEmptyString,
				const wxString& valueVelocityFactor = wxEmptyString,
				long style = userLineDialogStyle,
				const wxPoint& pos = wxDefaultPosition);

		void SetAttenuationValue(const wxString& val);
		wxString GetAttenuationValue() const { return m_valueAttenuation; }
		void SetAttenuationMaxLength(unsigned long len);
		bool TransferAttenuationDataToWindow();
		bool TransferAttenuationDataFromWindow();

		void SetVelocityFactorValue(const wxString& val);
		wxString GetVelocityFactorValue() const { return m_valueVelocityFactor; }
		void SetVelocityFactorMaxLength(unsigned long len);
		bool TransferVelocityFactorDataToWindow();
		bool TransferVelocityFactorDataFromWindow();

		// implementation only
		void OnOK(wxCommandEvent& event);

	protected:
		wxTextCtrl *m_textctrlAttenuation;
		wxTextCtrl *m_textctrlVelocityFactor;

		wxString    m_valueAttenuation;
		wxString    m_valueVelocityFactor;

		long        m_dialogStyle;

	private:
		wxDECLARE_EVENT_TABLE();
		wxDECLARE_DYNAMIC_CLASS(userLineDialog);
		wxDECLARE_NO_COPY_CLASS(userLineDialog);
};

#endif // __USER_LINE__
