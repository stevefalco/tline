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

#include <wx/log.h>

#include "constants.h"
#include "tlineIcon.h"
#include "tuner.h"

// Generated images from PNG files.
#include "nt_bp1ll.h"
#include "nt_bp2ll.h"
#include "nt_bp3ll.h"
#include "nt_clhp.h"
#include "nt_bp4ll.h"
#include "nt_hppi.h"
#include "nt_hp2ll.h"
#include "nt_hp1ll.h"
#include "nt_cllp.h"
#include "nt_hpt.h"
#include "nt_lclp.h"
#include "nt_lchp.h"
#include "nt_lp2ll.h"
#include "nt_lp1ll.h"
#include "nt_lpt.h"
#include "nt_lppi.h"
#include "nt_cc1.h"
#include "nt_cc2.h"
#include "nt_ll1.h"
#include "nt_ll2.h"

tuner::tuner( wxWindow* parent ) : tunerDialog( parent )
{
	SetIcon(wxICON(aaaa));
}

void tuner::Update()
{
	dl_tunerFrequency->ChangeValue(m_tunerFrequencyStr);
	dl_tunerSourceResistance->ChangeValue(m_tunerSourceResistanceStr);
	dl_tunerSourceReactance->ChangeValue(m_tunerSourceReactanceStr);
	dl_tunerLoadResistance->ChangeValue(m_tunerLoadResistanceStr);
	dl_tunerLoadReactance->ChangeValue(m_tunerLoadReactanceStr);
	dl_tunerQ->ChangeValue(m_tunerQStr);

	if(strcmp(m_tunerTopologyStr, "Two Cap (Cpar Cser)") == 0) {
		dl_topology->SetSelection(USE_CPCS);
	} else if(strcmp(m_tunerTopologyStr, "Two Cap (Cser Cpar)") == 0) {
		dl_topology->SetSelection(USE_CSCP);
	} else if(strcmp(m_tunerTopologyStr, "Two Coil (Lpar Lser)") == 0) {
		dl_topology->SetSelection(USE_LPLS);
	} else if(strcmp(m_tunerTopologyStr, "Two Coil (Lser Lpar)") == 0) {
		dl_topology->SetSelection(USE_LSLP);
	} else if(strcmp(m_tunerTopologyStr, "High Pass (Lpar Cser)") == 0) {
		dl_topology->SetSelection(USE_LCHP);
	} else if(strcmp(m_tunerTopologyStr, "Low Pass (Cpar Lser)") == 0) {
		dl_topology->SetSelection(USE_CLLP);
	} else if(strcmp(m_tunerTopologyStr, "Low Pass (Lser Cpar)") == 0) {
		dl_topology->SetSelection(USE_LCLP);
	} else if(strcmp(m_tunerTopologyStr, "High Pass (Cser Lpar)") == 0) {
		dl_topology->SetSelection(USE_CLHP);
	} else if(strcmp(m_tunerTopologyStr, "High Pass PI (Lpar Cser Lpar)") == 0) {
		dl_topology->SetSelection(USE_HPPI);
	} else if(strcmp(m_tunerTopologyStr, "Low Pass PI (Cpar Lser Cpar)") == 0) {
		dl_topology->SetSelection(USE_LPPI);
	} else if(strcmp(m_tunerTopologyStr, "High Pass T (Cser Lpar Cser)") == 0) {
		dl_topology->SetSelection(USE_HPT);
	} else if(strcmp(m_tunerTopologyStr, "Low Pass T (Lser Cpar Lser)") == 0) {
		dl_topology->SetSelection(USE_LPT);
#if 0
		// These don't seem to work correctly.
	} else if(strcmp(m_tunerTopologyStr, "High Pass (Lpar Cser Lpar Cser)") == 0) {
		dl_topology->SetSelection(USE_HP1LL);
	} else if(strcmp(m_tunerTopologyStr, "High Pass (Cser Lpar Cser Lpar)") == 0) {
		dl_topology->SetSelection(USE_HP2LL);
	} else if(strcmp(m_tunerTopologyStr, "Low Pass (Cpar Lser Cpar Lser)") == 0) {
		dl_topology->SetSelection(USE_LP1LL);
	} else if(strcmp(m_tunerTopologyStr, "Low Pass (Lser Cpar Lser Cpar)") == 0) {
		dl_topology->SetSelection(USE_LP2LL);
	} else if(strcmp(m_tunerTopologyStr, "Band Pass (Lpar Cser Cpar Lser)") == 0) {
		dl_topology->SetSelection(USE_BP1LL);
	} else if(strcmp(m_tunerTopologyStr, "Band Pass (Lser Cpar Cser Lpar)") == 0) {
		dl_topology->SetSelection(USE_BP2LL);
	} else if(strcmp(m_tunerTopologyStr, "Band Pass (Cpar Lser Lpar Cser)") == 0) {
		dl_topology->SetSelection(USE_BP3LL);
	} else if(strcmp(m_tunerTopologyStr, "Band Pass (Cser Lpar Lser Cpar)") == 0) {
		dl_topology->SetSelection(USE_BP4LL);
#endif
	}

	recalculate();
}

void tuner::onSourceResistance( wxCommandEvent& event )
{
	m_tunerSourceResistanceStr = event.GetString();

	recalculate();
}

void tuner::onSourceReactance( wxCommandEvent& event )
{
	m_tunerSourceReactanceStr = event.GetString();

	recalculate();
}

void tuner::onLoadResistance( wxCommandEvent& event )
{
	m_tunerLoadResistanceStr = event.GetString();

	recalculate();
}

void tuner::onLoadReactance( wxCommandEvent& event )
{
	m_tunerLoadReactanceStr = event.GetString();

	recalculate();
}

void tuner::onQ( wxCommandEvent& event )
{
	m_tunerQStr = event.GetString();

	recalculate();
}

void tuner::onTunerTopologySelected( wxCommandEvent& event )
{
	m_tunerTopologyStr = event.GetString();

	recalculate();
}

void tuner::recalculate()
{
	m_frequency = atof(m_tunerFrequencyStr) * 1.0E6;
	m_sourceResistance = atof(m_tunerSourceResistanceStr);
	m_sourceReactance = atof(m_tunerSourceReactanceStr);
	m_loadResistance = atof(m_tunerLoadResistanceStr);
	m_loadReactance = atof(m_tunerLoadReactanceStr);
	m_desiredQ = atof(m_tunerQStr);

	if(strcmp(m_tunerTopologyStr, "Two Cap (Cpar Cser)") == 0) {
		CPCS();
	} else if(strcmp(m_tunerTopologyStr, "Two Cap (Cser Cpar)") == 0) {
		CSCP();
	} else if(strcmp(m_tunerTopologyStr, "Two Coil (Lpar Lser)") == 0) {
		LPLS();
	} else if(strcmp(m_tunerTopologyStr, "Two Coil (Lser Lpar)") == 0) {
		LSLP();
	} else if(strcmp(m_tunerTopologyStr, "High Pass (Lpar Cser)") == 0) {
		LCHP();
	} else if(strcmp(m_tunerTopologyStr, "Low Pass (Cpar Lser)") == 0) {
		CLLP();
	} else if(strcmp(m_tunerTopologyStr, "Low Pass (Lser Cpar)") == 0) {
		LCLP();
	} else if(strcmp(m_tunerTopologyStr, "High Pass (Cser Lpar)") == 0) {
		CLHP();
	} else if(strcmp(m_tunerTopologyStr, "High Pass PI (Lpar Cser Lpar)") == 0) {
		HPPI();
	} else if(strcmp(m_tunerTopologyStr, "Low Pass PI (Cpar Lser Cpar)") == 0) {
		LPPI();
	} else if(strcmp(m_tunerTopologyStr, "High Pass T (Cser Lpar Cser)") == 0) {
		HPT();
	} else if(strcmp(m_tunerTopologyStr, "Low Pass T (Lser Cpar Lser)") == 0) {
		LPT();
#if 0
		// These don't seem to work correctly.
	} else if(strcmp(m_tunerTopologyStr, "High Pass (Lpar Cser Lpar Cser)") == 0) {
		HP1LL();
	} else if(strcmp(m_tunerTopologyStr, "High Pass (Cser Lpar Cser Lpar)") == 0) {
		HP2LL();
	} else if(strcmp(m_tunerTopologyStr, "Low Pass (Cpar Lser Cpar Lser)") == 0) {
		LP1LL();
	} else if(strcmp(m_tunerTopologyStr, "Low Pass (Lser Cpar Lser Cpar)") == 0) {
		LP2LL();
	} else if(strcmp(m_tunerTopologyStr, "Band Pass (Lpar Cser Cpar Lser)") == 0) {
		BP1LL();
	} else if(strcmp(m_tunerTopologyStr, "Band Pass (Lser Cpar Cser Lpar)") == 0) {
		BP2LL();
	} else if(strcmp(m_tunerTopologyStr, "Band Pass (Cpar Lser Lpar Cser)") == 0) {
		BP3LL();
	} else if(strcmp(m_tunerTopologyStr, "Band Pass (Cser Lpar Lser Cpar)") == 0) {
		BP4LL();
#endif
	}
}

void tuner::onTunerOKclicked( wxCommandEvent& event )
{
	if ( Validate() )
	{
		EndModal( wxID_OK );
	}
}

void
tuner::walkleyShow(double w, double x1, double x2, int item)
{
	double value;

	if(x1 >= 0) {
		// Series Inductor
		value = x1 / w;
		value *= 1E9; // nH
		m_walkleySolnSerIs[m_useSlot][item] = 'L';
		m_walkleySolnSer[m_useSlot][item] = value;
	} else {
		// Series Capacitor
		value = 1.0 / (-x1 * w);
		value *= 1E12; // pF
		m_walkleySolnSerIs[m_useSlot][item] = 'C';
		m_walkleySolnSer[m_useSlot][item] = value;
	}

	if(x2 >= 0) {
		// Parallel Inductor
		value = x2 / w;
		value *= 1E9; // nH
		m_walkleySolnParIs[m_useSlot][item] = 'L';
		m_walkleySolnPar[m_useSlot][item] = value;
	} else {
		// Parallel Capacitor
		value = 1.0 / (-x2 * w);
		value *= 1E12; // pF
		m_walkleySolnParIs[m_useSlot][item] = 'C';
		m_walkleySolnPar[m_useSlot][item] = value;
	}

	if(m_useSlot == 0) {
		// Source is on the left (series), load is on the right (parallel).
		if(m_walkleySolnSerIs[m_useSlot][item] == 'L' && m_walkleySolnParIs[m_useSlot][item] == 'L') {
			m_walkleySolnType[m_useSlot][item] = USE_LSLP;
		} else if(m_walkleySolnSerIs[m_useSlot][item] == 'C' && m_walkleySolnParIs[m_useSlot][item] == 'C') {
			m_walkleySolnType[m_useSlot][item] = USE_CSCP;
		} else if(m_walkleySolnSerIs[m_useSlot][item] == 'L' && m_walkleySolnParIs[m_useSlot][item] == 'C') {
			m_walkleySolnType[m_useSlot][item] = USE_LCLP;
		} else if(m_walkleySolnSerIs[m_useSlot][item] == 'C' && m_walkleySolnParIs[m_useSlot][item] == 'L') {
			m_walkleySolnType[m_useSlot][item] = USE_CLHP;
		}
	} else {
		// Source is on the right (parallel), load is on the left (series).
		if(m_walkleySolnSerIs[m_useSlot][item] == 'L' && m_walkleySolnParIs[m_useSlot][item] == 'L') {
			m_walkleySolnType[m_useSlot][item] = USE_LPLS;
		} else if(m_walkleySolnSerIs[m_useSlot][item] == 'C' && m_walkleySolnParIs[m_useSlot][item] == 'C') {
			m_walkleySolnType[m_useSlot][item] = USE_CPCS;
		} else if(m_walkleySolnSerIs[m_useSlot][item] == 'L' && m_walkleySolnParIs[m_useSlot][item] == 'C') {
			m_walkleySolnType[m_useSlot][item] = USE_CLLP;
		} else if(m_walkleySolnSerIs[m_useSlot][item] == 'C' && m_walkleySolnParIs[m_useSlot][item] == 'L') {
			m_walkleySolnType[m_useSlot][item] = USE_LCHP;
		}
	}
}

void tuner::walkley()
{
	double w = 2.0 * PI * m_frequency;

	double x1a;
	double x1b;

	double x2a;
	double x2b;

	double x1;
	double b2;

	double den = SQ(m_rB) + SQ(m_xB);
	double gB =  m_rB / den;
	double bB = -m_xB / den;

	double sqrtTerm = sqrt((1.0 / (m_rA * gB)) - 1.0);

	complex<double> left;
	complex<double> right;

	// Solution 1.
	x1 = -m_xA + m_rA * sqrtTerm;
	b2 = -bB + gB * sqrtTerm;
	x1a = x1;
	x2a = -1.0 / b2;

	// Check solution 1, as it may be bogus because of failures to overlap
	// the resistance/admittance circles.
	left = complex<double>(m_rA, m_xA + x1);
	right = (1.0 / complex<double>(gB, -(bB + b2))) * (complex<double>(gB, bB + b2) / complex<double>(gB, bB + b2));
	if(fabs(real(left) - real(right)) < 1E-10 && fabs(imag(left) - imag(right)) < 1E-10) {
		// This solution is good.  Print the component values.
		walkleyShow(w, x1a, x2a, 0);
	}

	// Solution 2.
	x1 = -m_xA - m_rA * sqrtTerm;
	b2 = -bB - gB * sqrtTerm;
	x1b = x1;
	x2b = -1.0 / b2;

	// Check solution 2, as it may be bogus because of failures to overlap
	// the resistance/admittance circles.
	left = complex<double>(m_rA, m_xA + x1);
	right = (1.0 / complex<double>(gB, -(bB + b2))) * (complex<double>(gB, bB + b2) / complex<double>(gB, bB + b2));
	if(fabs(real(left) - real(right)) < 1E-10 && fabs(imag(left) - imag(right)) < 1E-10) {
		// This solution is good.  Print the component values.
		walkleyShow(w, x1b, x2b, 1);
	}
}

void tuner::walkleyPrep1()
{
	m_useSlot = 0;
	m_rA = m_sourceResistance;
	m_xA = m_sourceReactance;
	m_rB = m_loadResistance;
	m_xB = m_loadReactance;
	walkley();
}

void tuner::walkleyPrep2()
{
	m_useSlot = 1;
	m_rB = m_sourceResistance;
	m_xB = m_sourceReactance;
	m_rA = m_loadResistance;
	m_xA = m_loadReactance;
	walkley();
}

void tuner::walkleyDisplay(
		int type,
		double sourceVar[2][2],
		const char *sourceLabel,
		double loadVar[2][2],
		const char *loadLabel
		)
{
	int i;
	int j;

	// See if this topology is among the solutions.
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			if(m_walkleySolnType[i][j] == type) {
				dl_tunerResult1->Show();
				dl_tunerResultTag1->Show();
				dl_tunerResult2->Show();
				dl_tunerResultTag2->Show();
				dl_tunerResult3->Hide();
				dl_tunerResultTag3->Hide();
				dl_tunerResult4->Hide();
				dl_tunerResultTag4->Hide();

				dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), sourceVar[i][j]));
				dl_tunerResultTag1->SetLabel(sourceLabel);

				dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), loadVar[i][j]));
				dl_tunerResultTag2->SetLabel(loadLabel);

				Layout();
				return;
			}
		}
	}

	// Invalid
	dl_tunerResult1->Hide();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Hide();
	dl_tunerResultTag2->Hide();
	dl_tunerResult3->Hide();
	dl_tunerResultTag3->Hide();
	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	dl_tunerResultTag1->SetLabel("No Match Found");

	Layout();
}

bool tuner::walkleySetup(wxBitmap bmp)
{
	int i;
	int j;

	dl_tunerQtag->Hide();
	dl_tunerQ->Hide();

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return FALSE;
	}

	// Clear old status.
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			m_walkleySolnType[i][j] = -1;
		}
	}

	// Find all solutions.
	walkleyPrep1();
	walkleyPrep2();

	return TRUE;
}

void tuner::CPCS()
{
	if(!walkleySetup(wxBITMAP_PNG_FROM_DATA(nt_cc1))) {
		return;
	}

	walkleyDisplay(
			USE_CPCS,
			m_walkleySolnPar,
			"CS Value (pF)",
			m_walkleySolnSer,
			"CL Value (pF)"
			);
}

void tuner::CSCP()
{
	if(!walkleySetup(wxBITMAP_PNG_FROM_DATA(nt_cc2))) {
		return;
	}

	walkleyDisplay(
			USE_CSCP,
			m_walkleySolnSer,
			"CS Value (pF)",
			m_walkleySolnPar,
			"CL Value (pF)"
			);
}

void tuner::LPLS()
{
	if(!walkleySetup(wxBITMAP_PNG_FROM_DATA(nt_ll1))) {
		return;
	}

	walkleyDisplay(
			USE_LPLS,
			m_walkleySolnPar,
			"LS Value (nH)",
			m_walkleySolnSer,
			"LL Value (nH)"
			);
}

void tuner::LSLP()
{
	if(!walkleySetup(wxBITMAP_PNG_FROM_DATA(nt_ll2))) {
		return;
	}

	walkleyDisplay(
			USE_LSLP,
			m_walkleySolnSer,
			"LS Value (nH)",
			m_walkleySolnPar,
			"LL Value (nH)"
			);
}

void tuner::LCHP()
{
	if(!walkleySetup(wxBITMAP_PNG_FROM_DATA(nt_lchp))) {
		return;
	}

	walkleyDisplay(
			USE_LCHP,
			m_walkleySolnPar,
			"L Value (nH)",
			m_walkleySolnSer,
			"C Value (pF)"
			);
}

void tuner::CLLP()
{
	if(!walkleySetup(wxBITMAP_PNG_FROM_DATA(nt_cllp))) {
		return;
	}

	walkleyDisplay(
			USE_CLLP,
			m_walkleySolnPar,
			"C Value (pF)",
			m_walkleySolnSer,
			"L Value (nH)"
			);
}

void tuner::LCLP()
{
	if(!walkleySetup(wxBITMAP_PNG_FROM_DATA(nt_lclp))) {
		return;
	}

	walkleyDisplay(
			USE_LCLP,
			m_walkleySolnSer,
			"L Value (nH)",
			m_walkleySolnPar,
			"C Value (pF)"
			);
}

void tuner::CLHP()
{
	if(!walkleySetup(wxBITMAP_PNG_FROM_DATA(nt_clhp))) {
		return;
	}

	walkleyDisplay(
			USE_CLHP,
			m_walkleySolnSer,
			"C Value (pF)",
			m_walkleySolnPar,
			"L Value (nH)"
			);
}

void tuner::HPPI()
{
	dl_tunerQtag->Show();
	dl_tunerQ->Show();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_hppi);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rs = m_sourceResistance;
	double xs = m_sourceReactance;
	double rl = m_loadResistance;
	double xl = m_loadReactance;
	double Q  = m_desiredQ;
	double f  = m_frequency;

	double rv;
	double w;
	double qs;
	double ql;
	double rps;
	double rpl;
	double cps;
	double cpl;
	double q;
	double cs;
	double ls;
	double cl;
	double ll;
	double lps;
	double lpl;
	double c;

	double lspi;
	double llpi;
	double cpi;

	if(Q < 0.0) {
		lspi = NAN;
		llpi = NAN;
		cpi = NAN;
	} else {
		if(Q == 0.0 && rs == rl) {
			lspi = 0.0;
			llpi = 0.0;
			cpi = 0.0;
		} else { 
			if(Q < sqrt(std::max(rs, rl) / std::min(rs, rl) - 1.0)) {
				lspi = NAN;
				llpi = NAN;
				cpi = NAN;
			} else {
				rv = std::max(rs, rl) / (Q * Q + 1.0);
				w = 2.0 * PI * f;
				qs = -xs / rs;
				ql = -xl / rl;
				rps = rs * (1.0 + qs * qs);  
				rpl = rl * (1.0 + ql * ql);
				cps = qs / rps / w;
				cpl = ql / rpl / w;
				q = sqrt(rps / rv - 1.0);
				cs = q / w / rps - cps;
				ls = q * rv / w;
				q = sqrt(rpl / rv - 1.0);
				cl = q / w / rpl - cpl;
				ll = q * rv / w;
				q = sqrt(rps / rv - 1.0);
				ls = rps / w / q;
				if(qs != 0.0) {
					lps = rps / qs / w;
					ls = ls * lps / (ls - lps);
				}
				lspi = ls * 1.0e9;
				cs = 1.0 / w / q / rv;
				q = sqrt(rpl / rv - 1.0);
				ll = rpl / w / q;
				if(ql != 0.0) {
					lpl = rpl / ql / w;
					ll = ll * lpl / (ll - lpl);
				}
				llpi = ll * 1.0e9;
				cl = 1.0 / w / q / rv;
				c = cl * cs / (cl + cs);
				cpi = c * 1.0e12;
			}
		}
	}

	if(!isfinite(cpi) || !isfinite(lspi) || !isfinite(llpi) ||
			cpi < 0.0 || lspi < 0.0 || llpi < 0.0 ||
			cpi > 1e7 || lspi > 1e7 || llpi > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), cpi));
	dl_tunerResultTag1->SetLabel("C Value (pF)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), lspi));
	dl_tunerResultTag2->SetLabel("LS Value (nH)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), llpi));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	Layout();
}

void tuner::LPPI()
{
	dl_tunerQtag->Show();
	dl_tunerQ->Show();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_lppi);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rs = m_sourceResistance;
	double xs = m_sourceReactance;
	double rl = m_loadResistance;
	double xl = m_loadReactance;
	double Q  = m_desiredQ;
	double f  = m_frequency;

	double rv;
	double w;
	double qs;
	double ql;
	double rps;
	double rpl;
	double cps;
	double cpl;
	double q;
	double cs;
	double ls;
	double cl;
	double ll;
	double l;
	double lps;
	double lpl;

	double cspi;
	double clpi;
	double lpi;

	if(Q < 0.0) {
		cspi = NAN;
		clpi = NAN;
		lpi = NAN;
	} else {
		if(Q == 0.0 && rs == rl) {
			cspi = 0.0;
			clpi = 0.0;
			lpi = 0.0;
		} else { 
			if(Q < sqrt(std::max(rs, rl) / std::min(rs, rl) - 1.0)) {
				cspi = NAN;
				clpi = NAN;
				lpi = NAN;
			} else {
				rv = std::max(rs, rl) / (Q * Q + 1.0);
				w = 2.0 * PI * f;
				qs = -xs / rs;
				ql = -xl / rl;
				rps = rs * (1.0 + qs * qs);  
				rpl = rl * (1.0 + ql * ql);
				cps = qs / rps / w;
				cpl = ql / rpl / w;
				q = sqrt(rps / rv - 1.0);
				cs = q / w / rps - cps;
				cspi = cs * 1.0e12;
				ls = q * rv / w;
				q = sqrt(rpl / rv - 1.0);
				cl = q / w / rpl - cpl;
				clpi = cl * 1.0e12;
				ll = q * rv / w;
				l = ls + ll;
				lpi = l * 1.0e9;
				q = sqrt(rps / rv - 1.0);
				ls = rps / w / q;
				if(qs != 0.0) {
					lps = rps / qs / w;
					ls = ls * lps / (ls - lps);
				}
				cs = 1.0 / w / q / rv;
				q = sqrt(rpl / rv - 1.0);
				ll = rpl / w / q;
				if(ql != 0.0) {
					lpl = rpl / ql / w;
					ll = ll * lpl / (ll - lpl);
				}
				cl = 1.0 / w / q / rv;
			}
		}
	}

	if(!isfinite(lpi) || !isfinite(cspi) || !isfinite(clpi) ||
			lpi < 0.0 || cspi < 0.0 || clpi < 0.0 ||
			lpi > 1e7 || cspi > 1e7 || clpi > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), lpi));
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), cspi));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), clpi));
	dl_tunerResultTag3->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::HPT()
{
	dl_tunerQtag->Show();
	dl_tunerQ->Show();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_hpt);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rs = m_sourceResistance;
	double xs = m_sourceReactance;
	double rl = m_loadResistance;
	double xl = m_loadReactance;
	double Q  = m_desiredQ;
	double f  = m_frequency;

	double rv;
	double w;
	double q;
	double cs;
	double ls;
	double cl;
	double ll;
	double l;

	double cst;
	double clt;
	double lt;

	if(Q < 0.0) {
		cst = NAN;
		clt = NAN;
		lt = NAN;
	} else {
		if(Q == 0.0 && rs == rl) {
			cst = 0.0;
			clt = 0.0;
			lt = 0.0;
		} else {
			if(Q < sqrt(std::max(rs, rl) / std::min(rs, rl) - 1.0)) {
				cst = NAN;
				clt = NAN;
				lt = NAN;
			} else {
				rv = std::min(rs, rl) * (Q * Q + 1.0);
				w = 2.0 * PI * f;
				q = sqrt(rv / rs - 1.0);
				cs = 1.0 / w / rs / q;
				if(xs != 0.0) {
					if(cs==(-1.0 / w / xs)) {
						cs = INFINITY;
					} else {
						cs = cs * (-1.0 / w / xs) / (cs + 1.0 / w / xs);
					}
				}
				cst = cs * 1.0e12;
				ls = rv / w / q;
				q = sqrt(rv / rl - 1.0);
				cl = 1.0 / w / rl / q;
				if(xl != 0.0) {
					if(cl==(-1.0 / w / xs)) {
						cl = INFINITY;
					} else {
						cl = cl * (-1.0 / w / xs) / (cl + 1.0 / w / xs);
					}
				}
				clt = cl * 1.0e12;
				ll = rv / w / q;
				l = ll * ls / (ll + ls);
				lt = l * 1.0e9;
				q = sqrt(rv / rs - 1.0);
				ls = q * rs / w - xs / w;
				cs = q / w / rv;
				q = sqrt(rv / rl - 1.0);
				ll = q * rl / w - xl / w;
				cl = q / w / rv;
			}
		}
	}

	if(!isfinite(lt) || !isfinite(cst) || !isfinite(clt) ||
			lt < 0.0 || cst < 0.0 || clt < 0.0 ||
			lt > 1e7 || cst > 1e7 || clt > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), lt));
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), cst));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), clt));
	dl_tunerResultTag3->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::LPT()
{
	dl_tunerQtag->Show();
	dl_tunerQ->Show();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_lpt);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rs = m_sourceResistance;
	double xs = m_sourceReactance;
	double rl = m_loadResistance;
	double xl = m_loadReactance;
	double Q  = m_desiredQ;
	double f  = m_frequency;

	double rv;
	double w;
	double q;
	double cs;
	double ls;
	double cl;
	double ll;
	double c;

	double lst;
	double llt;
	double ct;

	if(Q < 0.0) {
		lst = NAN;
		llt = NAN;
		ct = NAN;
	} else {
		if(Q == 0.0 && rs == rl) {
			lst = 0.0;
			llt = 0.0;
			ct = 0.0;
		} else {
			if(Q < sqrt(std::max(rs, rl) / std::min(rs, rl) - 1.0)) {
				lst = NAN;
				llt = NAN;
				ct = NAN;
			} else {
				rv = std::min(rs, rl) * (Q * Q + 1.0);
				w = 2.0 * PI * f;
				q = sqrt(rv / rs - 1.0);
				cs = 1.0 / w / rs / q;
				if(xs != 0.0) {
					if(cs==(-1.0 / w / xs)) {
						cs = INFINITY;
					} else {
						cs = cs * (-1.0 / w / xs) / (cs + 1.0 / w / xs);
					}
				}
				ls = rv / w / q;
				q = sqrt(rv / rl - 1.0);
				cl = 1.0 / w / rl / q;
				if(xl != 0.0) {
					if(cl==(-1.0 / w / xs)) {
						cl = INFINITY;
					} else {
						cl = cl * (-1.0 / w / xs) / (cl + 1.0 / w / xs);
					}
				}
				ll = rv / w / q;
				q = sqrt(rv / rs - 1.0);
				ls = q * rs / w - xs / w;
				lst = ls * 1.0e9;
				cs = q / w / rv;
				q = sqrt(rv / rl - 1.0);
				ll = q * rl / w - xl / w;
				llt = ll * 1.0e9;
				cl = q / w / rv;
				c = cs + cl;
				ct = c * 1.0e12;
			}
		}
	}

	if(!isfinite(ct) || !isfinite(lst) || !isfinite(llt) ||
			ct < 0.0 || lst < 0.0 || llt < 0.0 ||
			ct > 1e7 || lst > 1e7 || llt > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), ct));
	dl_tunerResultTag1->SetLabel("C Value (pF)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), lst));
	dl_tunerResultTag2->SetLabel("LS Value (nH)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), llt));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	Layout();
}

#if 0
// These don't seem to work correctly.
void tuner::HP1LL()
{
	dl_tunerQtag->Hide();
	dl_tunerQ->Hide();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_hp1ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rs = m_sourceResistance;
	double xs = m_sourceReactance;
	double rl = m_loadResistance;
	double xl = m_loadReactance;
	double f  = m_frequency;

	double w;
	double q;
	double rp;
	double rv;
	double qs;
	double ql;
	double lp;
	double c;
	double l;
	double cs;

	double hp1cs;
	double hp1ls;
	double hp1cl;
	double hp1ll;

	w = 2.0 * PI * f;
	q = xs / rs;
	rp = (1.0 + q * q) * rs;
	rv = sqrt(rp * rl);
	if(rp > rv) {
		qs = sqrt(rp / rv - 1.0);
		ql = sqrt(rv / rl - 1.0);
		lp = rp / w / q;
		c = 1.0 / w / rv / qs;
		hp1cs = c * 1.0e12;
		l = rp / w / qs;
		if(xs != 0.0) {
			if(lp == l) {
				l = INFINITY;
			} else {
				l = 1.0 * lp / (lp - l);
			}
		}
		hp1ls = l * 1.0e9;
		cs = -1.0 / w / xl;
		l = rv / w / ql;
		hp1ll = l * 1.0e9;
		c = 1.0 / w / rl / ql;
		if(xl != 0.0) {
			if(cs == c) {
				c = INFINITY;
			} else {
				c = c * cs / (cs - c);
		       	}
		}
		hp1cl = c * 1.0e12;
	} else {
		hp1cs = NAN;
		hp1ls = NAN;
		hp1cl = NAN;
		hp1ll = NAN;
	}

	if(!isfinite(hp1ls) || !isfinite(hp1cs) || !isfinite(hp1ll) || !isfinite(hp1cl) ||
			hp1ls < 0.0 || hp1cs < 0.0 || hp1ll < 0.0 || hp1cl < 0.0 ||
			hp1ls > 1e7 || hp1cs > 1e7 || hp1ll > 1e7 || hp1cl > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), hp1ls));
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), hp1cs));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), hp1ll));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), hp1cl));
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::HP2LL()
{
	dl_tunerQtag->Hide();
	dl_tunerQ->Hide();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_hp2ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rl = m_sourceResistance;
	double xl = m_sourceReactance;
	double rs = m_loadResistance;
	double xs = m_loadReactance;
	double f  = m_frequency;

	double w;
	double q;
	double rp;
	double rv;
	double qs;
	double ql;
	double lp;
	double c;
	double l;
	double cs;

	double hp2cs;
	double hp2ls;
	double hp2cl;
	double hp2ll;

	w = 2.0 * PI * f;
	q = xs / rs;
	rp = (1.0 + q * q) * rs;
	rv = sqrt(rp * rl);
	if(rp > rv) {
		qs = sqrt(rp / rv - 1.0);
		ql = sqrt(rv / rl - 1.0);
		lp = rp / w / q;
		c = 1.0 / w / rv / qs;
		hp2cs = c * 1.0e12;
		l = rp / w / qs;
		if(xs != 0.0) {
			if(lp == l) {
				l = INFINITY;
			} else {
				l = 1.0 * lp / (lp - l);
			}
		}
		hp2ls = l * 1.0e9;
		cs = -1.0 / w / xl;
		l = rv / w / ql;
		hp2ll = l * 1.0e9;
		c = 1.0 / w / rl / ql;
		if (xl != 0.0) {
			if(cs == c) {
				c = INFINITY;
		       	} else {
				c = c * cs / (cs - c);
		       	}
		}
		hp2cl = c * 1.0e12;
	} else {
		hp2cs = NAN;
		hp2ls = NAN;
		hp2cl = NAN;
		hp2ll = NAN;
	}

	if(!isfinite(hp2ls) || !isfinite(hp2cs) || !isfinite(hp2ll) || !isfinite(hp2cl) ||
			hp2ls < 0.0 || hp2cs < 0.0 || hp2ll < 0.0 || hp2cl < 0.0 ||
			hp2ls > 1e7 || hp2cs > 1e7 || hp2ll > 1e7 || hp2cl > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), hp2ls));
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), hp2cs));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), hp2ll));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), hp2cl));
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::LP1LL()
{
	dl_tunerQtag->Hide();
	dl_tunerQ->Hide();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_lp1ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rs = m_sourceResistance;
	double xs = m_sourceReactance;
	double rl = m_loadResistance;
	double xl = m_loadReactance;
	double f  = m_frequency;

	double w;
	double q;
	double rp;
	double rv;
	double qs;
	double ql;
	double cp;
	double c;
	double l;

	double lp1cs;
	double lp1ls;
	double lp1cl;
	double lp1ll;

	w = 2.0 * PI * f;
	q = -xs / rs;
	rp = (1.0 + q * q) * rs;
	rv = sqrt(rp * rl);
	if(rp > rv) {
		qs = sqrt(rp / rv - 1.0);
		ql = sqrt(rv / rl - 1.0);
		cp = q / w / rp;
		c = qs / w / rp - cp;
		lp1cs = c * 1.0e12;
		l = qs * rv / w;
		lp1ls = l * 1.0e9;
		l = rl * ql / w - xl / w;
		lp1ll = l * 1.0e9;
		c = ql / w / rv;
		lp1cl = c * 1.0e12;
	} else {
		lp1cs = NAN;
		lp1ls = NAN;
		lp1cl = NAN;
		lp1ll = NAN;
	}

	if(!isfinite(lp1ls) || !isfinite(lp1cs) || !isfinite(lp1ll) || !isfinite(lp1cl) ||
			lp1ls < 0.0 || lp1cs < 0.0 || lp1ll < 0.0 || lp1cl < 0.0 ||
			lp1ls > 1e7 || lp1cs > 1e7 || lp1ll > 1e7 || lp1cl > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), lp1ls));
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), lp1cs));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), lp1ll));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), lp1cl));
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::LP2LL()
{
	dl_tunerQtag->Hide();
	dl_tunerQ->Hide();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_lp2ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rl = m_sourceResistance;
	double xl = m_sourceReactance;
	double rs = m_loadResistance;
	double xs = m_loadReactance;
	double f  = m_frequency;

	double w;
	double q;
	double rp;
	double rv;
	double qs;
	double ql;
	double cp;
	double c;
	double l;

	double lp2cs;
	double lp2ls;
	double lp2cl;
	double lp2ll;

	w = 2.0 * PI * f;
	q = -xs / rs;
	rp = (1.0 + q * q) * rs;
	rv = sqrt(rp * rl);
	if(rp > rv) {
		qs = sqrt(rp / rv - 1.0);
		ql = sqrt(rv / rl - 1.0);
		cp = q / w / rp;
		c = qs / w / rp - cp;
		lp2cs = c * 1.0e12;
		l = qs * rv / w;
		lp2ls = l * 1.0e9;
		l = rl * ql / w - xl / w;
		lp2ll = l * 1.0e9;
		c = ql / w / rv;
		lp2cl = c * 1.0e12;
	} else {
		lp2cs = NAN;
		lp2ls = NAN;
		lp2cl = NAN;
		lp2ll = NAN;
	}

	if(!isfinite(lp2ls) || !isfinite(lp2cs) || !isfinite(lp2ll) || !isfinite(lp2cl) ||
			lp2ls < 0.0 || lp2cs < 0.0 || lp2ll < 0.0 || lp2cl < 0.0 ||
			lp2ls > 1e7 || lp2cs > 1e7 || lp2ll > 1e7 || lp2cl > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), lp2ls));
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), lp2cs));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), lp2ll));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), lp2cl));
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::BP1LL()
{
	dl_tunerQtag->Hide();
	dl_tunerQ->Hide();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_bp1ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rs = m_sourceResistance;
	double xs = m_sourceReactance;
	double rl = m_loadResistance;
	double xl = m_loadReactance;
	double f  = m_frequency;

	double w;
	double q;
	double rp;
	double rv;
	double qs;
	double ql;
	double lp;
	double c;
	double l;

	double bp1cs;
	double bp1ls;
	double bp1cl;
	double bp1ll;

	w = 2.0 * PI * f;
	q = xs / rs;
	rp = (1.0 + q * q) * rs;
	rv = sqrt(rp * rl);
	if(rp > rv) {
		qs = sqrt(rp / rv - 1.0);
		ql = sqrt(rv / rl - 1.0);
		lp = rp / w / q;
		c = 1.0 / w / rv / qs;
		bp1cs = c * 1.0e12;
		l = rp / w / qs;
		if (xs != 0.0) {
			if(lp == l) {
				l = INFINITY;
		       	} else {
				l = 1.0 * lp / (lp - l);
		       	}
		}
		bp1ls = l * 1.0e9;
		l = ql * rl / w - xl / w;
		bp1ll = l * 1.0e9;
		c = ql / w / rv;
		bp1cl = c * 1.0e12;
	} else {
		bp1cs = NAN;
		bp1ls = NAN;
		bp1cl = NAN;
		bp1ll = NAN;
	}
	
	if(!isfinite(bp1ls) || !isfinite(bp1cs) || !isfinite(bp1ll) || !isfinite(bp1cl) ||
			bp1ls < 0.0 || bp1cs < 0.0 || bp1ll < 0.0 || bp1cl < 0.0 ||
			bp1ls > 1e7 || bp1cs > 1e7 || bp1ll > 1e7 || bp1cl > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), bp1ls));
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), bp1cs));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), bp1ll));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), bp1cl));
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::BP2LL()
{
	dl_tunerQtag->Hide();
	dl_tunerQ->Hide();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_bp2ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rl = m_sourceResistance;
	double xl = m_sourceReactance;
	double rs = m_loadResistance;
	double xs = m_loadReactance;
	double f  = m_frequency;

	double w;
	double q;
	double rp;
	double rv;
	double qs;
	double ql;
	double lp;
	double c;
	double l;

	double bp2cs;
	double bp2ls;
	double bp2cl;
	double bp2ll;

	w = 2.0 * PI * f;
	q = xs / rs;
	rp = (1.0 + q * q) * rs;
	rv = sqrt(rp * rl);
	if(rp > rv) {
		qs = sqrt(rp / rv - 1.0);
		ql = sqrt(rv / rl - 1.0);
		lp = rp / w / q;
		c = 1.0 / w / rv / qs;
		bp2cs = c * 1.0e12;
		l = rp / w / qs;
		if (xs != 0.0) {
			if(lp == l) {
				l = INFINITY;
			} else {
				l = 1.0 * lp / (lp - l);
			}
		}
		bp2ls = l * 1.0e9;
		l = ql * rl / w - xl / w;
		bp2ll = l * 1.0e9;
		c = ql / w / rv;
		bp2cl = c * 1.0e12;
	} else {
		bp2cs = NAN;
		bp2ls = NAN;
		bp2cl = NAN;
		bp2ll = NAN;
	}

	if(!isfinite(bp2ls) || !isfinite(bp2cs) || !isfinite(bp2ll) || !isfinite(bp2cl) ||
			bp2ls < 0.0 || bp2cs < 0.0 || bp2ll < 0.0 || bp2cl < 0.0 ||
			bp2ls > 1e7 || bp2cs > 1e7 || bp2ll > 1e7 || bp2cl > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), bp2ls));
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), bp2cs));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), bp2ll));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), bp2cl));
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::BP3LL()
{
	dl_tunerQtag->Hide();
	dl_tunerQ->Hide();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_bp3ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rs = m_sourceResistance;
	double xs = m_sourceReactance;
	double rl = m_loadResistance;
	double xl = m_loadReactance;
	double f  = m_frequency;

	double w;
	double q;
	double rp;
	double rv;
	double qs;
	double ql;
	double c;
	double l;
	double cs;
	double cp;

	double bp3cs;
	double bp3ls;
	double bp3cl;
	double bp3ll;

	w = 2.0 * PI * f;
	q = -xs / rs;
	rp = (1.0 + q * q) * rs;
	rv = sqrt(rp * rl);
	if(rp > rv) {
		qs = sqrt(rp / rv - 1.0);
		ql = sqrt(rv / rl - 1.0);
		cp = q / w / rp;
		c = qs / w / rp - cp;
		bp3cs = c * 1.0e12;
		l = qs * rv / w;
		bp3ls = l * 1.0e9;
		l = rv / w / ql;
		bp3ll = l * 1.0e9;
		cs = -1.0 / w / xl;
		c = 1.0 / w / rl / ql;
		if (xl != 0.0) {
			if(cs == c) {
				c = INFINITY;
			} else {
				c = c * cs / (cs - c);
			}
		}
		bp3cl = c * 1.0e12;
	} else {
		bp3cs = NAN;
		bp3ls = NAN;
		bp3cl = NAN;
		bp3ll = NAN;
	}
	
	if(!isfinite(bp3ls) || !isfinite(bp3cs) || !isfinite(bp3ll) || !isfinite(bp3cl) ||
			bp3ls < 0.0 || bp3cs < 0.0 || bp3ll < 0.0 || bp3cl < 0.0 ||
			bp3ls > 1e7 || bp3cs > 1e7 || bp3ll > 1e7 || bp3cl > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), bp3ls));
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), bp3cs));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), bp3ll));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), bp3cl));
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::BP4LL()
{
	dl_tunerQtag->Hide();
	dl_tunerQ->Hide();

	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_bp4ll);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rl = m_sourceResistance;
	double xl = m_sourceReactance;
	double rs = m_loadResistance;
	double xs = m_loadReactance;
	double f  = m_frequency;

	double w;
	double q;
	double rp;
	double rv;
	double qs;
	double ql;
	double c;
	double l;
	double cs;
	double cp;

	double bp4cs;
	double bp4ls;
	double bp4cl;
	double bp4ll;

	w = 2.0 * PI * f;
	q = -xs / rs;
	rp = (1.0 + q * q) * rs;
	rv = sqrt(rp * rl);
	if(rp > rv) {
		qs = sqrt(rp / rv - 1.0);
		ql = sqrt(rv / rl - 1.0);
		cp = q / w / rp;
		c = qs / w / rp - cp;
		bp4cs = c * 1.0e12;
		l = qs * rv / w;
		bp4ls = l * 1.0e9;
		l = rv / w / ql;
		bp4ll = l * 1.0e9;
		cs = -1.0 / w / xl;
		c = 1.0 / w / rl / ql;
		if(xl != 0.0) {
			if(cs == c) {
				c = INFINITY;
			} else {
				c = c * cs / (cs - c);
			}
		}
		bp4cl = c * 1.0e12;
	} else {
		bp4cs = NAN;
		bp4ls = NAN;
		bp4cl = NAN;
		bp4ll = NAN;
	}
	
	if(!isfinite(bp4ls) || !isfinite(bp4cs) || !isfinite(bp4ll) || !isfinite(bp4cl) ||
			bp4ls < 0.0 || bp4cs < 0.0 || bp4ll < 0.0 || bp4cl < 0.0 ||
			bp4ls > 1e7 || bp4cs > 1e7 || bp4ll > 1e7 || bp4cl > 1e7) {
		// Invalid
		dl_tunerResult1->Hide();
		dl_tunerResultTag1->Show();
		dl_tunerResult2->Hide();
		dl_tunerResultTag2->Hide();
		dl_tunerResult3->Hide();
		dl_tunerResultTag3->Hide();
		dl_tunerResult4->Hide();
		dl_tunerResultTag4->Hide();

		dl_tunerResultTag1->SetLabel("No Match Found");

		Layout();
		return;
	}

	dl_tunerResult1->Show();
	dl_tunerResultTag1->Show();
	dl_tunerResult2->Show();
	dl_tunerResultTag2->Show();
	dl_tunerResult3->Show();
	dl_tunerResultTag3->Show();
	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), bp4ls));
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), bp4cs));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), bp4ll));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), bp4cl));
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}
#endif
