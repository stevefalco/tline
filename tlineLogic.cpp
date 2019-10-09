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

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/textfile.h>
#include <wx/wfstream.h>

#include "constants.h"
#include "helpAbout.h"
#include "helpInfo.h"
#include "info.h"
#include "strchrnul.h"
#include "tlineIcon.h"
#include "tlineLogic.h"
#include "tuner.h"
#include "userLine.h"
#include "version.h"

wxString g_widthStr;
wxString g_heightStr;

tlineLogic::tlineLogic( wxWindow* parent, wxString fileName ) : tlineUI( parent )
{
	wxImage::AddHandler(new wxPNGHandler);
	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxGIFHandler);

	SetIcon(wxICON(aaaa));
	SetTitle("Tline - A Transmission Line Calculator");

	wxString title = _("Transmission Line Calculator, Version ") + VERSION + _(", by AC2XM");

	m_c = new cableTypes;
	ui_programTitle->SetLabel(title);

	// Once any parameter is changed, this will flip to 0.
	m_saved = 1;

	// Remember when the tuner dialog has been opened at least once.
	m_tunerInit = FALSE;

	// Set our defaults.
	m_powerStr = _("1500.0");
	ui_power->ChangeValue(m_powerStr);

	m_resistanceStr = _("50");
	ui_resistance->ChangeValue(m_resistanceStr);

	m_reactanceStr = _("0");
	ui_reactance->ChangeValue(m_reactanceStr);

	m_frequencyStr = _("7.00");
	ui_frequency->ChangeValue(m_frequencyStr);

	// Length is special because we allow a 'w' character to specify wavelength
	// rather than feet or meters.
	m_lengthStr = _("100");
	wxTextValidator* txtValidator = wxDynamicCast(ui_cableLength->GetValidator(), wxTextValidator);
	if(txtValidator) {
		txtValidator->SetCharIncludes("0123456789.eE+-w");
	}
	ui_cableLength->ChangeValue(m_lengthStr);

	// If a file was specified on the command line, read it now.  This has to be after
	// all the above initializations.
	if(fileName != "") {
		loadFile(fileName);
	}

	recalculate();
}

void tlineLogic::onFileLoad( wxCommandEvent& event )
{
	if(!m_saved) {
		if(wxMessageBox(_("Current content has not been saved! Proceed?"), _("Please confirm"), wxICON_QUESTION | wxYES_NO, this) == wxNO) {
			return;
		}
	}
    
	wxFileDialog openFileDialog(this, _("Open tline file"), "", "", "tline files (*.tline)|*.tline", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if(openFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}

	loadFile(openFileDialog.GetPath());
}
    
void tlineLogic::loadFile( wxString path )
{
	char buffer[512];
	char *p;

	wxFileInputStream input_stream( path );
	if(!input_stream.IsOk()) {
		wxLogError("Cannot open file '%s'", path);
		return;
	}
    
	wxFile *f = input_stream.GetFile();
	FILE *fp = fdopen(f->fd(), "r");

	while(fgets(buffer, 512, fp) != NULL) {
		*strchrnul(buffer, '\n') = 0;

		if(buffer[0] == '#') {
			continue;
		}

		if((p = strchr(buffer, '=')) == NULL) {
			wxLogError("Missing '=' in %s", buffer);
			continue;
		}
		*p++ = 0;

		// Parse top-level parameters
		if(strcmp(buffer, "cableType") == 0) {
			m_cableTypeStr = p;
			ui_cableType->ChangeValue(m_cableTypeStr);
		}

		if(strcmp(buffer, "units") == 0) {
			m_unitsStr = p;
			if(strcmp(m_unitsStr, "Feet") == 0) {
				ui_unitsRadioButtons->SetSelection(USE_FEET);
			}
			if(strcmp(m_unitsStr, "Meters") == 0) {
				ui_unitsRadioButtons->SetSelection(USE_METERS);
			}
		}

		if(strcmp(buffer, "frequency") == 0) {
			m_frequencyStr = p;
			ui_frequency->ChangeValue(m_frequencyStr);
		}

		if(strcmp(buffer, "length") == 0) {
			m_lengthStr = p;
			ui_cableLength->ChangeValue(m_lengthStr);
		}

		if(strcmp(buffer, "resistance") == 0) {
			m_resistanceStr = p;
			ui_resistance->ChangeValue(m_resistanceStr);
		}

		if(strcmp(buffer, "reactance") == 0) {
			m_reactanceStr = p;
			ui_reactance->ChangeValue(m_reactanceStr);
		}

		if(strcmp(buffer, "loadInput") == 0) {
			m_loadInputStr = p;
			if(strcmp(m_loadInputStr, "Load") == 0) {
				ui_loadInputRadioButtons->SetSelection(USE_LOAD);
			}
			if(strcmp(m_loadInputStr, "Input") == 0) {
				ui_loadInputRadioButtons->SetSelection(USE_INPUT);
			}
		}

		if(strcmp(buffer, "power") == 0) {
			m_powerStr = p;
			ui_power->ChangeValue(m_powerStr);
		}

		// Parse tuner parameters
		if(strcmp(buffer, "m_tunerFrequency") == 0) {
			m_tunerFrequencyStr = p;
			m_tunerInit = TRUE;
		}

		if(strcmp(buffer, "m_tunerPower") == 0) {
			m_tunerPowerStr = p;
			m_tunerInit = TRUE;
		}

		if(strcmp(buffer, "m_tunerSourceResistance") == 0) {
			m_tunerSourceResistanceStr = p;
			m_tunerInit = TRUE;
		}

		if(strcmp(buffer, "m_tunerSourceReactance") == 0) {
			m_tunerSourceReactanceStr = p;
			m_tunerInit = TRUE;
		}

		if(strcmp(buffer, "m_tunerLoadResistance") == 0) {
			m_tunerLoadResistanceStr = p;
			m_tunerInit = TRUE;
		}

		if(strcmp(buffer, "m_tunerLoadReactance") == 0) {
			m_tunerLoadReactanceStr = p;
			m_tunerInit = TRUE;
		}

		if(strcmp(buffer, "m_tunerNetworkQ") == 0) {
			m_tunerNetworkQStr = p;
			m_tunerInit = TRUE;
		}

		if(strcmp(buffer, "m_tunerInductorQ") == 0) {
			m_tunerInductorQStr = p;
			m_tunerInit = TRUE;
		}

		if(strcmp(buffer, "m_tunerCapacitorQ") == 0) {
			m_tunerCapacitorQStr = p;
			m_tunerInit = TRUE;
		}

		if(strcmp(buffer, "m_tunerTopology") == 0) {
			m_tunerTopologyStr = p;
			m_tunerInit = TRUE;
		}

		// Parse user line parameters
		if(strcmp(buffer, "m_userLineAttenuation") == 0) {
			m_userLineAttenuationStr = p;
			m_userLineInit = 1;
		}

		if(strcmp(buffer, "m_userLineVelocityFactor") == 0) {
			m_userLineVelocityFactorStr = p;
			m_userLineInit = 1;
		}

		if(strcmp(buffer, "m_userLineCableImpedance") == 0) {
			m_userLineCableImpedanceStr = p;
			m_userLineInit = 1;
		}

		if(strcmp(buffer, "m_userLineCableResistance") == 0) {
			m_userLineCableResistanceStr = p;
			m_userLineInit = 1;
		}

		if(strcmp(buffer, "m_userLineCableReactance") == 0) {
			m_userLineCableReactanceStr = p;
			m_userLineInit = 1;
		}

		if(strcmp(buffer, "m_userLineCableVoltageLimit") == 0) {
			m_userLineCableVoltageLimitStr = p;
			m_userLineInit = 1;
		}
	}

	f->Close();

	recalculate();
}

void tlineLogic::onFileSave( wxCommandEvent& event )
{
	wxFileDialog saveFileDialog(this, _("Save tline file"), "", "", "tline files (*.tline)|*.tline", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}
    
	wxFileOutputStream output_stream(saveFileDialog.GetPath());
	if (!output_stream.IsOk()) {
		wxLogError("Cannot save current contents in file '%s'", saveFileDialog.GetPath());
		return;
	}
    
	wxFile *f = output_stream.GetFile();
	FILE *fp = fdopen(f->fd(), "w");

	if(fp == NULL) {
		wxLogError("Cannot open file '%s' for writing", saveFileDialog.GetPath());
		return;
	}

	// Save top-level parameters
	fprintf(fp, "cableType=%s\n",	(const char *)m_cableTypeStr.mb_str());
	fprintf(fp, "units=%s\n",	(const char *)m_unitsStr.mb_str());
	fprintf(fp, "frequency=%s\n",	(const char *)m_frequencyStr.mb_str());
	fprintf(fp, "length=%s\n",	(const char *)m_lengthStr.mb_str());
	fprintf(fp, "resistance=%s\n",	(const char *)m_resistanceStr.mb_str());
	fprintf(fp, "reactance=%s\n",	(const char *)m_reactanceStr.mb_str());
	fprintf(fp, "loadInput=%s\n",	(const char *)m_loadInputStr.mb_str());
	fprintf(fp, "power=%s\n",	(const char *)m_powerStr.mb_str());

	// Save tuner parameters
	if(m_tunerInit) {
		fprintf(fp, "m_tunerFrequency=%s\n",		(const char *)m_tunerFrequencyStr.mb_str());
		fprintf(fp, "m_tunerPower=%s\n",		(const char *)m_tunerPowerStr.mb_str());
		fprintf(fp, "m_tunerSourceResistance=%s\n",	(const char *)m_tunerSourceResistanceStr.mb_str());
		fprintf(fp, "m_tunerSourceReactance=%s\n",	(const char *)m_tunerSourceReactanceStr.mb_str());
		fprintf(fp, "m_tunerLoadResistance=%s\n",	(const char *)m_tunerLoadResistanceStr.mb_str());
		fprintf(fp, "m_tunerLoadReactance=%s\n",	(const char *)m_tunerLoadReactanceStr.mb_str());
		fprintf(fp, "m_tunerNetworkQ=%s\n",		(const char *)m_tunerNetworkQStr.mb_str());
		fprintf(fp, "m_tunerInductorQ=%s\n",		(const char *)m_tunerInductorQStr.mb_str());
		fprintf(fp, "m_tunerCapacitorQ=%s\n",		(const char *)m_tunerCapacitorQStr.mb_str());
		fprintf(fp, "m_tunerTopology=%s\n",		(const char *)m_tunerTopologyStr.mb_str());
	}

	// Save user line parameters
	if(m_userLineInit) {
		fprintf(fp, "m_userLineAttenuation=%s\n",	(const char *)m_userLineAttenuationStr.mb_str());
		fprintf(fp, "m_userLineVelocityFactor=%s\n",	(const char *)m_userLineVelocityFactorStr.mb_str());
		fprintf(fp, "m_userLineCableImpedance=%s\n",	(const char *)m_userLineCableImpedanceStr.mb_str());
		fprintf(fp, "m_userLineCableResistance=%s\n",	(const char *)m_userLineCableResistanceStr.mb_str());
		fprintf(fp, "m_userLineCableReactance=%s\n",	(const char *)m_userLineCableReactanceStr.mb_str());
		fprintf(fp, "m_userLineCableVoltageLimit=%s\n",	(const char *)m_userLineCableVoltageLimitStr.mb_str());
	}

	if(fflush(fp) == EOF) {
		wxLogError("Cannot flush file '%s'", saveFileDialog.GetPath());
		return;
	}

	f->Close();

	m_saved = 1;
}

void tlineLogic::onFileExit( wxCommandEvent& event )
{
	// Could check for dirty and request save before exiting here.
	Destroy();
}

void tlineLogic::onHelpInfo( wxCommandEvent& event )
{
	helpInfo* dialog = new helpInfo(this);

	dialog->helpInfoSetPage(INFO_PAGE);

	dialog->ShowModal();
}

void tlineLogic::onHelpAbout( wxCommandEvent& event )
{
	helpAbout* dialog = new helpAbout(this);

	dialog->helpAboutAddTextLine1("tline - A Transmission Line Calculator");
	dialog->helpAboutAddTextLine2(wxString::Format(wxT("Version %s"), VERSION));
	dialog->helpAboutAddTextLine3("by Steven A. Falco, AC2XM");
	dialog->helpAboutAddTextLine4("License: GPLv3");

	dialog->ShowModal();
}

// On Linux, this event only happens if the selected item changes.
// Reselecting the same item a second time does not cause this event.
// However, Windows behaves differently; reselecting the same item does
// regenerate this event.
//
// I consider the Linux behavior to be a bug; it is certainly not what
// I want here.  I have a special case of "User Specified Line", and I
// want a reselection of that item to reopen the associated dialog box.
//
// I tried onComboBoxCloseup, but it doesn't return the string in the
// event.  And, if I try to recover the string from the combo box itself,
// I get the previous value.  Consequently, when switching away from
// "User Specified Line", I wind up getting the dialog opening when it
// shouldn't.
//
// After much experimentation, I found that if I set the selection to
// wxNOT_FOUND on Linux, then I will get this event even if the same
// item is reselected.  But I cannot use that on Windows, because it
// blanks out the displayed string.  Thus, we use the wxNOT_FOUND hack
// only on Linux.
void tlineLogic::onCableTypeSelected( wxCommandEvent& event )
{
	m_cableTypePrevStr = m_cableTypeStr;
	m_cableTypeStr = event.GetString();
#ifdef __linux
	ui_cableType->SetSelection(wxNOT_FOUND);
#endif

	if(m_cableTypeStr == "User-Defined Transmission Line") {
		m_newUserLine = TRUE;
	}

	m_saved = 0;

	recalculate();
}

void tlineLogic::onUnitsSelected( wxCommandEvent& event )
{
	m_unitsStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onFrequencySelected( wxCommandEvent& event )
{
	m_frequencyStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onLengthSelected( wxCommandEvent& event )
{
	m_lengthStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onResistanceSelected( wxCommandEvent& event )
{
	m_resistanceStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onReactanceSelected( wxCommandEvent& event )
{
	m_reactanceStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onLoadInputSelected( wxCommandEvent& event )
{
	m_loadInputStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onPowerSelected( wxCommandEvent& event )
{
	m_powerStr = event.GetString();
	m_saved = 0;

	recalculate();
}

void tlineLogic::onPlotZclicked( wxCommandEvent& event )
{
	doPlot(DO_IMPEDANCE, PLOT);
}

void tlineLogic::onPlotVIclicked( wxCommandEvent& event )
{
	doPlot(DO_VOLT_AMP, PLOT);
}

void tlineLogic::onSavePlotZclicked( wxCommandEvent& event )
{
	doPlot(DO_IMPEDANCE, SAVE);
}

void tlineLogic::onSavePlotVIclicked( wxCommandEvent& event )
{
	doPlot(DO_VOLT_AMP, SAVE);
}

void tlineLogic::onSaveDataClicked( wxCommandEvent& event )
{
	saveData();
}

void tlineLogic::onTunerClicked( wxCommandEvent& event )
{
	tuner* dialog = new tuner(this);

	if(m_tunerInit == FALSE) {
		// Start the tuner off with reasonable values.
		m_tunerFrequencyStr = m_frequencyStr;
		m_tunerPowerStr = m_powerStr;
		m_tunerSourceResistanceStr = "50.0";
		m_tunerSourceReactanceStr = "0.0";
		m_tunerLoadResistanceStr = wxString::Format(wxT("%.2f"), real(m_zInput));
		m_tunerLoadReactanceStr = wxString::Format(wxT("%.2f"), imag(m_zInput));
		m_tunerNetworkQStr= "1.0";
		m_tunerInductorQStr= "200.0";
		m_tunerCapacitorQStr= "2000.0";
		m_tunerTopologyStr = _("Two Cap (Cpar Cser)");

		m_tunerInit = TRUE;
	}

	dialog->m_tunerFrequencyStr = m_tunerFrequencyStr;
	dialog->m_tunerPowerStr = m_tunerPowerStr;
	dialog->m_tunerSourceResistanceStr = m_tunerSourceResistanceStr;
	dialog->m_tunerSourceReactanceStr = m_tunerSourceReactanceStr;
	dialog->m_tunerLoadResistanceStr = m_tunerLoadResistanceStr;
	dialog->m_tunerLoadReactanceStr = m_tunerLoadReactanceStr;
	dialog->m_tunerNetworkQStr = m_tunerNetworkQStr;
	dialog->m_tunerInductorQStr = m_tunerInductorQStr;
	dialog->m_tunerCapacitorQStr = m_tunerCapacitorQStr;
	dialog->m_tunerTopologyStr = m_tunerTopologyStr;
	dialog->Update();

	if (dialog->ShowModal() == wxID_OK) {
		m_tunerFrequencyStr = dialog->m_tunerFrequencyStr;
		m_tunerPowerStr = dialog->m_tunerPowerStr;
		m_tunerSourceResistanceStr = dialog->m_tunerSourceResistanceStr;
		m_tunerSourceReactanceStr = dialog->m_tunerSourceReactanceStr;
		m_tunerLoadResistanceStr = dialog->m_tunerLoadResistanceStr;
		m_tunerLoadReactanceStr = dialog->m_tunerLoadReactanceStr;
		m_tunerNetworkQStr = dialog->m_tunerNetworkQStr;
		m_tunerInductorQStr = dialog->m_tunerInductorQStr;
		m_tunerCapacitorQStr = dialog->m_tunerCapacitorQStr;
		m_tunerTopologyStr = dialog->m_tunerTopologyStr;
	}
}

double tlineLogic::wavelength()
{
	double				wavelength;

	if(m_units == USE_FEET) {
		wavelength = m_velocityFactor * SPEED_OF_LIGHT_F / m_frequency;
	} else if(m_units == USE_METERS) {
		wavelength = m_velocityFactor * SPEED_OF_LIGHT_M / m_frequency;
	} else {
		wavelength = -1.0;
	}

	return wavelength;
}

// Return complex impedance at input of cable for a given length and load.
complex<double> tlineLogic::impedanceAtInput(double distance)
{
	return m_zCable * (
			(m_zLoad * cosh(m_lossCoef * distance) + m_zCable * sinh(m_lossCoef * distance))
			/
			(m_zCable * cosh(m_lossCoef * distance) + m_zLoad * sinh(m_lossCoef * distance))
		       );
}

// Return complex impedance at load of cable for a given length and input.
complex<double> tlineLogic::impedanceAtLoad(double distance)
{
	return m_zCable * (
			(m_zInput * cosh(m_lossCoef * distance) - m_zCable * sinh(m_lossCoef * distance))
			/
			(m_zCable * cosh(m_lossCoef * distance) - m_zInput * sinh(m_lossCoef * distance))
		       );
}

// Return the complex voltage at a given point along the line.
complex<double> tlineLogic::voltageOut(double distance)
{
	return m_voltageForPower * (cosh(m_lossCoef * distance) - (m_zCable / m_zInput) * sinh(m_lossCoef * distance));
}

// Return the complex current at a given point along the line.
complex<double> tlineLogic::currentOut(double distance)
{
	return (m_voltageForPower / m_zInput) * (cosh(m_lossCoef * distance) - (m_zInput / m_zCable) * sinh(m_lossCoef * distance));
}

// panel with custom controls for file dialog
class MyExtraPanel : public wxPanel
{
	public:
		MyExtraPanel(wxWindow *parent, wxString width, wxString height);
		wxString GetWidth() const
		{
			return wxString::Format("%s", (const char *)m_widthBox->GetValue());
		}
		wxString GetHeight() const
		{
			return wxString::Format("%s", (const char *)m_heightBox->GetValue());
		}
		void onWidthSelected( wxCommandEvent& event );
		void onHeightSelected( wxCommandEvent& event );
		
	private:
		wxString	m_widthStr;
		wxString	m_heightStr;
		wxStaticText	*m_widthTag;
		wxTextCtrl	*m_widthBox;
		wxStaticText	*m_heightTag;
		wxTextCtrl	*m_heightBox;
};

MyExtraPanel::MyExtraPanel(wxWindow *parent, wxString width, wxString height) : wxPanel(parent)
{
	m_widthStr = width;
	m_heightStr = height;

	m_widthTag = new wxStaticText(this, -1, "Width");
	m_widthBox = new wxTextCtrl(this, -1, m_widthStr);

	m_heightTag = new wxStaticText(this, -1, "   Height");
	m_heightBox = new wxTextCtrl(this, -1, m_heightStr);

	wxBoxSizer *sizerTop = new wxBoxSizer(wxHORIZONTAL);
	sizerTop->Add(m_widthTag, wxSizerFlags().Right().Border());
	sizerTop->Add(m_widthBox, wxSizerFlags().Right().Border(wxALL, 0));
	sizerTop->Add(m_heightTag, wxSizerFlags().Right().Border());
	sizerTop->Add(m_heightBox, wxSizerFlags().Right().Border(wxALL, 0));
	SetSizerAndFit(sizerTop);
	m_widthBox->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyExtraPanel::onWidthSelected ), NULL, this );
	m_heightBox->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyExtraPanel::onHeightSelected ), NULL, this );
}

void MyExtraPanel::onWidthSelected( wxCommandEvent& event )
{
	m_widthStr = event.GetString();
}

void MyExtraPanel::onHeightSelected( wxCommandEvent& event )
{
	m_heightStr = event.GetString();
}

// a static method can be used instead of a function with most of compilers
static wxWindow* createMyExtraPanel(wxWindow *parent)
{
	return new MyExtraPanel(parent, g_widthStr, g_heightStr);
}

// Warning: File names must be in single-quotes for gnuplot on Windows,
// otherwise the backslashes are interpolated and the paths don't work.
bool tlineLogic::setOutput( wxFFile* file )
{
	const char		*q = "png";
	wxString		fileName;

	g_widthStr = m_widthStr;
	g_heightStr = m_heightStr;

	wxFileDialog saveFileDialog(this, _("Save plot graphic file"), "", "", "", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	saveFileDialog.SetExtraControlCreator(&createMyExtraPanel);
	if (saveFileDialog.ShowModal() == wxID_CANCEL) {
		return FALSE;
	}

	fileName = saveFileDialog.GetFilename();
	std::size_t dot = fileName.find_last_of(".");
	if(dot != string::npos) {
		// We default to png, but process the suffix and change
		// the selection to match the user's request if possible.
		if(fileName.substr(dot).Lower() == ".jpg" || fileName.substr(dot).Lower() == ".jpeg") {
			q = "jpeg";
		} else if(fileName.substr(dot).Lower() == ".gif") {
			q = "gif";
		}
	}

	wxWindow * const extra = saveFileDialog.GetExtraControl();
	if(extra) {
		m_widthStr = static_cast<MyExtraPanel*>(extra)->GetWidth();
		m_width = atoi(m_widthStr);

		m_heightStr = static_cast<MyExtraPanel*>(extra)->GetHeight();
		m_height = atoi(m_heightStr);
	}

	fprintf(file->fp(), "set terminal %s size %d,%d\n", q, m_width, m_height);
	fprintf(file->fp(), "set output '%s'\n", (const char*)saveFileDialog.GetPath());

	return TRUE;
}

// Warning: File names must be in single-quotes for gnuplot on Windows,
// otherwise the backslashes are interpolated and the paths don't work.
void tlineLogic::setControlZ( wxFFile* file, const char* name )
{
	fprintf(file->fp(), "set ytics nomirror tc lt 1\n");
	fprintf(file->fp(), "set ylabel 'Imaginary (Ω)' tc lt 1\n");
	fprintf(file->fp(), "set y2tics nomirror tc lt 2\n");
	fprintf(file->fp(), "set y2label 'Real (Ω)' tc lt 2\n");
	fprintf(file->fp(), "set xlabel 'Length (%s)'\n", (const char*)m_unitsStr);
	fprintf(file->fp(), "plot \\\n");
	fprintf(file->fp(), "  '%s' u 1:3 w l axes x1y1 title 'imag', \\\n", name);
	fprintf(file->fp(), "  '%s' u 1:2 w l axes x1y2 title 'real'\n", name);
}

// Warning: File names must be in single-quotes for gnuplot on Windows,
// otherwise the backslashes are interpolated and the paths don't work.
void tlineLogic::setControlVI( wxFFile* file, const char* name )
{	
	fprintf(file->fp(), "set ytics nomirror tc lt 1\n");
	fprintf(file->fp(), "set ylabel 'Current (Amps)' tc lt 1\n");
	fprintf(file->fp(), "set y2tics nomirror tc lt 2\n");
	fprintf(file->fp(), "set y2label 'Voltage (Volts)' tc lt 2\n");
	fprintf(file->fp(), "set xlabel 'Length (%s)'\n", (const char*)m_unitsStr);
	fprintf(file->fp(), "plot \\\n");
	fprintf(file->fp(), "  '%s' u 1:9 w l axes x1y1 title 'amps', \\\n", name);
	fprintf(file->fp(), "  '%s' u 1:8 w l axes x1y2 title 'volts'\n", name);
}

// Build data and control files, then spawn gnuplot.
void tlineLogic::doPlot( int type, int mode )
{
	wxString		dataName;
	wxString		controlName;

	wxFFile			dataFP;
	wxFFile			controlFP;

	// Create temporary data file.
	dataName = wxFileName::CreateTempFileName("", &dataFP);
	if(dataName.IsEmpty()) {
		wxLogError("Cannot create temporary data file");
		goto QUIT;
	}

	// Create temporary control file.
	controlName = wxFileName::CreateTempFileName("", &controlFP);
	if(controlName.IsEmpty()) {
		wxLogError("Cannot create temporary control file");
		goto DELETE_DATA;
	}

	// Generate the data.
	generateGraphableData(dataFP.fp());

	if(!dataFP.Flush()) {
		wxLogError("Cannot flush data file '%s'", dataName);
		goto DELETE_CONTROL;
	}

	// Arrange for gnuplot to handle special characters.
	fprintf(controlFP.fp(), "set encoding utf8\n");

	// If saving, we need to set the terminal type and output file.
	if(mode == SAVE) {
		if(!setOutput( &controlFP )) {
			goto DELETE_CONTROL;
		}
	}

	// Add the remaining control statements.
	switch(type) {
		case DO_IMPEDANCE:
			setControlZ( &controlFP, (const char*)dataName );
			break;

		case DO_VOLT_AMP:
			setControlVI( &controlFP, (const char*)dataName );
			break;
	}
	
	if(!controlFP.Flush()) {
		wxLogError("Cannot flush control file '%s'", controlName);
		goto DELETE_CONTROL;
	}

	// Build and execute the plot command.
	system(wxString::Format(wxT("gnuplot %s %s"), (mode == PLOT) ? "-p" : "", controlName));
	
	// Delete the temporary files from the filesystem.
DELETE_CONTROL:
	controlFP.Close();
	wxRemoveFile(controlName);

DELETE_DATA:
	dataFP.Close();
	wxRemoveFile(dataName);

QUIT:
	return;
}

void tlineLogic::saveData()
{
	wxFileDialog saveFileDialog(this, _("Save plot data file"), "", "", "plot data files (*.plot)|*.plot", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}
    
	wxFileOutputStream output_stream(saveFileDialog.GetPath());
	if (!output_stream.IsOk()) {
		wxLogError("Cannot save current contents in file '%s'", saveFileDialog.GetPath());
		return;
	}
    
	wxFile *f = output_stream.GetFile();
	FILE *fp = fdopen(f->fd(), "w");

	if(fp == NULL) {
		wxLogError("Cannot open file '%s' for writing", saveFileDialog.GetPath());
		return;
	}

	generateGraphableData(fp);

	if(fflush(fp) == EOF) {
		wxLogError("Cannot flush file '%s'", saveFileDialog.GetPath());
		return;
	}

	f->Close();
}

// Calculate the graphable data.  We write it to a temporary file which we
// will pass to gnuplot.
void tlineLogic::generateGraphableData(
		FILE*		fp
		)
{
	int				i;

	double				distanceFromSource;
	double				distanceFromLoad;

	complex<double>		zPoint;
	complex<double>		vOut;
	complex<double>		iOut;

	// Show column headings.
	fprintf(fp, "#       Length        Z_In_Real      Z_In_Imag           V_Real         V_Imag           I_Real         I_Imag           V_Magn         I_Magn\n");

	// Scale cable length by SCALE for a smoother curve.
	for(i = 0; i <= POINTS_ON_X; i++) {
		distanceFromSource = m_length * ((double)i / (double)POINTS_ON_X);
		distanceFromLoad = m_length - distanceFromSource;

		// Find the impedance at the input for a given length of line.
		zPoint = impedanceAtInput(distanceFromLoad);

		// Find the voltage at a point along the cable.
		vOut = voltageOut(distanceFromSource);

		// Find the current at a point along the cable.
		iOut = currentOut(distanceFromSource);

		fprintf(fp, "%14.6f   %14.6f %14.6f   %14.6f %14.6f   %14.6f %14.6f   %14.6f %14.6f\n",
				distanceFromSource,
				real(zPoint), imag(zPoint),
				real(vOut), imag(vOut),
				real(iOut), imag(iOut),
				abs(vOut), abs(iOut));
	}
}

void tlineLogic::recalculate()
{
	// Convert the units string.
	if(m_unitsStr == "Feet") {
		m_units = USE_FEET;
	} else if(m_unitsStr == "Meters") {
		m_units = USE_METERS;
	} else {
		m_units = USE_FEET;
		wxLogMessage("Unknown Units %s", m_unitsStr);
	}
	ui_lengthUnits->SetLabel(m_unitsStr);

	// Convert the frequency string.
	m_frequency = atof(m_frequencyStr) * 1.0E6;

	// Look up the cable parameters.
	m_cp = m_c->findCable(m_cableTypeStr.mb_str());
	if(m_cp == 0) {
		if(m_newUserLine == TRUE) {
			// No such cable - open a dialog to ask for parameters.
			userLine* dialog = new userLine(this);

			// Fill in the previous user-provided values.
			dialog->m_userLineFrequencyStr = m_frequencyStr;
			dialog->m_userLineAttenuationStr = m_userLineAttenuationStr;
			dialog->m_userLineVelocityFactorStr = m_userLineVelocityFactorStr;
			dialog->m_userLineCableImpedanceStr = m_userLineCableImpedanceStr;
			dialog->m_userLineCableResistanceStr = m_userLineCableResistanceStr;
			dialog->m_userLineCableReactanceStr = m_userLineCableReactanceStr;
			dialog->m_userLineCableVoltageLimitStr = m_userLineCableVoltageLimitStr;
			dialog->Update();

			if (dialog->ShowModal() == wxID_OK) {
				// Save the new user values.
				m_userLineAttenuationStr = dialog->m_userLineAttenuationStr;
				m_userLineVelocityFactorStr = dialog->m_userLineVelocityFactorStr;
				m_userLineCableImpedanceStr = dialog->m_userLineCableImpedanceStr;
				m_userLineCableResistanceStr = dialog->m_userLineCableResistanceStr;
				m_userLineCableReactanceStr = dialog->m_userLineCableReactanceStr;
				m_userLineCableVoltageLimitStr = dialog->m_userLineCableVoltageLimitStr;

				// Also set our working values.
				m_userSpecifiedZ = TRUE;
				m_attenPer100Feet = atof(m_userLineAttenuationStr);
				m_velocityFactor = atof(m_userLineVelocityFactorStr);
				m_cableResistivePart = atof(m_userLineCableResistanceStr);
				m_cableReactivePart = atof(m_userLineCableReactanceStr);
				m_maximumVoltage = atof(m_userLineCableVoltageLimitStr);

				// Cache has been loaded.
				m_newUserLine = FALSE;

				// Permit saving the values.
				m_userLineInit = TRUE;
			} else {
				// If cancelled, set back to previous type.
				m_cableTypeStr = m_cableTypePrevStr;
				ui_cableType->ChangeValue(m_cableTypeStr);
			}
		} else {
			// Use the cached values.
			m_userSpecifiedZ = TRUE;
			m_attenPer100Feet = atof(m_userLineAttenuationStr);
			m_velocityFactor = atof(m_userLineVelocityFactorStr);
			m_cableResistivePart = atof(m_userLineCableResistanceStr);
			m_cableReactivePart = atof(m_userLineCableReactanceStr);
			m_maximumVoltage = atof(m_userLineCableVoltageLimitStr);
		}
	} else {
		m_userSpecifiedZ = FALSE;
		m_attenPer100Feet = m_c->findAtten(m_cp, m_frequency);
		m_velocityFactor = m_cp->velocityFactor;
		m_impedance = m_cp->impedance;
		m_maximumVoltage = m_cp->maximumVoltage;
	}

	ui_velocityFactor->ChangeValue(wxString::Format(wxT("%.2f"), m_velocityFactor));
	ui_maxVoltage->ChangeValue(wxString::Format(wxT("%.0f V"), m_maximumVoltage));

	// Calculate the wavelength.  We need the velocity factor here.
	m_wavelength = wavelength();
	
	// Convert the length string.  We need the wavelength here.
	if(!m_lengthStr.empty()) {
		char lastChar = *m_lengthStr.rbegin();

		if(lastChar == 'w' || lastChar == 'W') {
			m_length = atof(m_lengthStr) * m_wavelength;
			ui_cableLength->ChangeValue(wxString::Format(wxT("%.2f"), m_length));
		} else {
			m_length = atof(m_lengthStr);
		}
	} else {
		m_length = atof(m_lengthStr);
	}

	// Calculate the length of the line in wavelength units.
	m_lambda = m_length / m_wavelength;
	ui_lambda->ChangeValue(wxString::Format(wxT("%.2f"), m_lambda));

	// Look up the attenuation in dB per hundred feet, and convert to the
	// other formats we will need.
	m_attenPer100Meters = m_attenPer100Feet * M_TO_F;
	if(m_units == USE_FEET) {
		m_attenPer100Units = m_attenPer100Feet;
		ui_matchedLineLoss->ChangeValue(wxString::Format(wxT("%.2f dB/100 Feet"), m_attenPer100Units));
	} else {
		m_attenPer100Units = m_attenPer100Meters;
		ui_matchedLineLoss->ChangeValue(wxString::Format(wxT("%.2f dB/100 Meters"), m_attenPer100Units));
	}
	m_attenDBPerUnitLength = m_attenPer100Units / 100.0;
	m_attenNepersPerUnitLength = m_attenDBPerUnitLength * DB_TO_NEPERS;

	// Calculate the phase angle per unit length at the chosen frequency.
	m_phase = (2.0 * PI) / m_wavelength;

	// Combine attenuation and phase angle to get the loss coefficient.
	m_lossCoef = complex<double>(m_attenNepersPerUnitLength, m_phase);

	// The user can specify the cable resistance / reactance, in which
	// case we use those values directly.  But manufacturers don't
	// specify cable that way, so we have to generate the values
	// ourselves from the attenuation and phase angle.
	if(!m_userSpecifiedZ) {
		// Find the complex impedance of the coax.  There are several ways to
		// do this, and they each give different answers.  This is the best
		// method that I've found...
		m_cableResistivePart = m_impedance * sqrt(1.0 / (1.0 + sq(m_attenNepersPerUnitLength / m_phase)));
		m_cableReactivePart = -m_cableResistivePart * (m_attenNepersPerUnitLength / m_phase);
	}
	m_zCable = complex<double>(m_cableResistivePart, m_cableReactivePart);
	ui_characteristicZ0->ChangeValue(wxString::Format(wxT("%.2f, %.2fi Ω"), real(m_zCable), imag(m_zCable)));

	m_resistance = atof(m_resistanceStr);
	m_reactance = atof(m_reactanceStr);
	if(m_loadInputStr == "Load") {
		// Use the provided load impedance.
		m_zLoad = complex<double>(m_resistance, m_reactance);

		// Find the input impedance for the full length of cable.
		m_zInput = impedanceAtInput(m_length);
		ui_impedanceRectangular->ChangeValue(wxString::Format(wxT("%.2f, %.2fi Ω"), real(m_zInput), imag(m_zInput)));
		ui_impedancePolar->ChangeValue(wxString::Format(wxT("%.2f @ %.2f°"), abs(m_zInput), arg(m_zInput) * RADIANS_TO_DEGREES));

		ui_impedanceRectangularTag->SetLabel("Impedance at Input (Real/Imaginary):");
		ui_impedancePolarTag->SetLabel("Impedance at Input (Polar):");
	} else if(m_loadInputStr == "Input") {
		// Use the provided input impedance.
		m_zInput = complex<double>(m_resistance, m_reactance);

		// Find the load impedance for the full length of cable.
		m_zLoad = impedanceAtLoad(m_length);
		ui_impedanceRectangular->ChangeValue(wxString::Format(wxT("%.2f, %.2fi Ω"), real(m_zLoad), imag(m_zLoad)));
		ui_impedancePolar->ChangeValue(wxString::Format(wxT("%.2f @ %.2f°"), abs(m_zLoad), arg(m_zLoad) * RADIANS_TO_DEGREES));

		ui_impedanceRectangularTag->SetLabel("Impedance at Load (Real/Imaginary):");
		ui_impedancePolarTag->SetLabel("Impedance at Load (Polar):");
	}

	// Calculate the reflection coefficient at the load.
	m_rho = (m_zLoad - m_zCable) / (m_zLoad + m_zCable);
	m_rhoMagnitudeAtLoad = abs(m_rho);
	m_returnLossAtLoad = 20.0 * log10(m_rhoMagnitudeAtLoad);
	ui_rhoLoad->ChangeValue(wxString::Format(wxT("%.2f"), m_rhoMagnitudeAtLoad));

	// Calculate the SWR at the load.
	m_swrAtLoad = (1.0 + m_rhoMagnitudeAtLoad) / (1.0 - m_rhoMagnitudeAtLoad);
	ui_swrLoad->ChangeValue(wxString::Format(wxT("%.2f"), m_swrAtLoad));

	// Calculate matched line loss.
	m_totalMatchedLineLoss = m_attenDBPerUnitLength * m_length;
	ui_totalMatchedLineLoss->ChangeValue(wxString::Format(wxT("%.2f dB"), m_totalMatchedLineLoss));

	// Calculate total loss.
	double tmp = pow(10.0, 0.1 * m_totalMatchedLineLoss);
	m_totalLoss = 10.0 * log10((sq(tmp) - sq(m_rhoMagnitudeAtLoad)) / (tmp * (1.0 - sq(m_rhoMagnitudeAtLoad))));
	ui_totalLoss->ChangeValue(wxString::Format(wxT("%.2f dB"), m_totalLoss));
	
	// Calculate extra loss caused by SWR.
	m_extraSWRloss = m_totalLoss - m_totalMatchedLineLoss;
	ui_addedLoss->ChangeValue(wxString::Format(wxT("%.2f dB"), m_extraSWRloss));

	// Calculate the SWR at the source.
	m_returnLossAtSource = m_returnLossAtLoad - 2.0 * m_totalLoss;
	m_rhoMagnitudeAtSource = pow(10.0, m_returnLossAtSource / 20.0);
	m_swrAtSource = (1 + m_rhoMagnitudeAtSource) / (1 - m_rhoMagnitudeAtSource);
	ui_swrInput->ChangeValue(wxString::Format(wxT("%.2f"), m_swrAtSource));
	
	// Find the voltage necessary to produce the desired power at the
	// input of the cable, given the magnitude of the complex input
	// impedance.
	m_power = atof(m_powerStr);
	m_voltageForPower = sqrt(m_power * abs(m_zInput));
	ui_inputVoltage->ChangeValue(wxString::Format(wxT("%.2f V"), m_voltageForPower));
}
