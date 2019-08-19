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

tuner::tuner( wxWindow* parent ) : tunerDialog( parent )
{
	SetIcon(wxICON(aaaa));

	recalculate();
}

void tuner::SetFrequency( double v )
{
	m_frequency = v;

	dl_tunerFrequency->ChangeValue(wxString::Format(wxT("%.2f"), m_frequency / 1e6));

	recalculate();
}

double tuner::GetSourceResistance()
{
	return m_sourceResistance;
}

void tuner::SetSourceResistance( double v )
{
	m_sourceResistance = v;

	dl_tunerSourceResistance->ChangeValue(wxString::Format(wxT("%.2f"), m_sourceResistance));

	recalculate();
}

double tuner::GetSourceReactance()
{
	return m_sourceReactance;
}

void tuner::SetSourceReactance( double v )
{
	m_sourceReactance = v;

	dl_tunerSourceReactance->ChangeValue(wxString::Format(wxT("%.2f"), m_sourceReactance));

	recalculate();
}

double tuner::GetLoadResistance()
{
	return m_loadResistance;
}

void tuner::SetLoadResistance( double v )
{
	m_loadResistance = v;

	dl_tunerLoadResistance->ChangeValue(wxString::Format(wxT("%.2f"), m_loadResistance));

	recalculate();
}

double tuner::GetLoadReactance()
{
	return m_loadReactance;
}

void tuner::SetLoadReactance( double v )
{
	m_loadReactance = v;

	dl_tunerLoadReactance->ChangeValue(wxString::Format(wxT("%.2f"), m_loadReactance));

	recalculate();
}

double tuner::GetQ()
{
	return m_desiredQ;
}

void tuner::SetQ( double v )
{
	m_desiredQ = v;

	dl_tunerQ->ChangeValue(wxString::Format(wxT("%.2f"), m_desiredQ));

	recalculate();
}

wxString tuner::GetTopology()
{
	return m_topologyStr;
}

void tuner::SetTopology( wxString v )
{
	m_topologyStr = v;

	if(strcmp(m_topologyStr, "High Pass (Lpar Cser)") == 0) {
		dl_topology->SetSelection(USE_LCHP);
	} else if(strcmp(m_topologyStr, "Low Pass (Cpar Lser)") == 0) {
		dl_topology->SetSelection(USE_CLLP);
	} else if(strcmp(m_topologyStr, "Low Pass (Lser Cpar)") == 0) {
		dl_topology->SetSelection(USE_LCLP);
	} else if(strcmp(m_topologyStr, "High Pass (Cser Lpar)") == 0) {
		dl_topology->SetSelection(USE_CLHP);
	} else if(strcmp(m_topologyStr, "High Pass PI (Lpar Cser Lpar)") == 0) {
		dl_topology->SetSelection(USE_HPPI);
	} else if(strcmp(m_topologyStr, "Low Pass PI (Cpar Lser Cpar)") == 0) {
		dl_topology->SetSelection(USE_LPPI);
	} else if(strcmp(m_topologyStr, "High Pass T (Cser Lpar Cser)") == 0) {
		dl_topology->SetSelection(USE_HPT);
	} else if(strcmp(m_topologyStr, "Low Pass T (Lser Cpar Lser)") == 0) {
		dl_topology->SetSelection(USE_LPT);
	} else if(strcmp(m_topologyStr, "High Pass (Lpar Cser Lpar Cser)") == 0) {
		dl_topology->SetSelection(USE_HP1LL);
	} else if(strcmp(m_topologyStr, "High Pass (Cser Lpar Cser Lpar)") == 0) {
		dl_topology->SetSelection(USE_HP2LL);
	} else if(strcmp(m_topologyStr, "Low Pass (Cpar Lser Cpar Lser)") == 0) {
		dl_topology->SetSelection(USE_LP1LL);
	} else if(strcmp(m_topologyStr, "Low Pass (Lser Cpar Lser Cpar)") == 0) {
		dl_topology->SetSelection(USE_LP2LL);
	} else if(strcmp(m_topologyStr, "Band Pass (Lpar Cser Cpar Lser)") == 0) {
		dl_topology->SetSelection(USE_BP1LL);
	} else if(strcmp(m_topologyStr, "Band Pass (Lser Cpar Cser Lpar)") == 0) {
		dl_topology->SetSelection(USE_BP2LL);
	} else if(strcmp(m_topologyStr, "Band Pass (Cpar Lser Lpar Cser)") == 0) {
		dl_topology->SetSelection(USE_BP3LL);
	} else if(strcmp(m_topologyStr, "Band Pass (Cser Lpar Lser Cpar)") == 0) {
		dl_topology->SetSelection(USE_BP4LL);
	}

	recalculate();
}

void tuner::onSourceResistance( wxCommandEvent& event )
{
	m_sourceResistance = atof(event.GetString());

	recalculate();
}

void tuner::onSourceReactance( wxCommandEvent& event )
{
	m_sourceReactance = atof(event.GetString());

	recalculate();
}

void tuner::onLoadResistance( wxCommandEvent& event )
{
	m_loadResistance = atof(event.GetString());

	recalculate();
}

void tuner::onLoadReactance( wxCommandEvent& event )
{
	m_loadReactance = atof(event.GetString());

	recalculate();
}

void tuner::onQ( wxCommandEvent& event )
{
	m_desiredQ = atof(event.GetString());

	recalculate();
}

void tuner::onTunerTopologySelected( wxCommandEvent& event )
{
	m_topologyStr = event.GetString();

	recalculate();
}

void tuner::recalculate()
{
	if(strcmp(m_topologyStr, "High Pass (Lpar Cser)") == 0) {
		LCHP();
	} else if(strcmp(m_topologyStr, "Low Pass (Cpar Lser)") == 0) {
		CLLP();
	} else if(strcmp(m_topologyStr, "Low Pass (Lser Cpar)") == 0) {
		LCLP();
	} else if(strcmp(m_topologyStr, "High Pass (Cser Lpar)") == 0) {
		CLHP();
	} else if(strcmp(m_topologyStr, "High Pass PI (Lpar Cser Lpar)") == 0) {
		HPPI();
	} else if(strcmp(m_topologyStr, "Low Pass PI (Cpar Lser Cpar)") == 0) {
		LPPI();
	} else if(strcmp(m_topologyStr, "High Pass T (Cser Lpar Cser)") == 0) {
		HPT();
	} else if(strcmp(m_topologyStr, "Low Pass T (Lser Cpar Lser)") == 0) {
		LPT();
	} else if(strcmp(m_topologyStr, "High Pass (Lpar Cser Lpar Cser)") == 0) {
		HP1LL();
	} else if(strcmp(m_topologyStr, "High Pass (Cser Lpar Cser Lpar)") == 0) {
		HP2LL();
	} else if(strcmp(m_topologyStr, "Low Pass (Cpar Lser Cpar Lser)") == 0) {
		LP1LL();
	} else if(strcmp(m_topologyStr, "Low Pass (Lser Cpar Lser Cpar)") == 0) {
		LP2LL();
	} else if(strcmp(m_topologyStr, "Band Pass (Lpar Cser Cpar Lser)") == 0) {
		BP1LL();
	} else if(strcmp(m_topologyStr, "Band Pass (Lser Cpar Cser Lpar)") == 0) {
		BP2LL();
	} else if(strcmp(m_topologyStr, "Band Pass (Cpar Lser Lpar Cser)") == 0) {
		BP3LL();
	} else if(strcmp(m_topologyStr, "Band Pass (Cser Lpar Lser Cpar)") == 0) {
		BP4LL();
	}
}

void tuner::onTunerOKclicked( wxCommandEvent& event )
{
	if ( Validate() )
	{
		EndModal( wxID_OK );
	}
}

void tuner::LCHP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_lchp);

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
	double rp;
	double qs;
	double lp;
	double c;
	double l;
	double cs;
	double c1;
	double l1;
	double Q;

	double lchpcval;
	double lchpqval;
	double lchplval;

	if((m_sourceResistance == m_loadResistance) && (m_sourceReactance == -m_loadReactance)) {
		lchpcval = 0.0;
		lchpqval = m_sourceReactance / m_sourceResistance;
		lchplval = 0.0;
	} else {
		w = 2.0 * PI * f;
		qs = xs / rs;
		c1 = -1.0 / w / xl;
		l1 = (1.0 + qs * qs) * xs / w / qs / qs;
		rp = (1.0 + qs * qs) * rs;
		rs = rl;
		if(rs > rp) {
			lchpcval = NAN;
			lchpqval = NAN;
			lchplval = NAN;
		} else {
			Q = sqrt(rp / rs - 1.0);
			lp = rp / w / Q;
			cs = 1.0 / Q / w / rs;
			if(xl == 0.0) {
				c = cs * 1.0e12;
			} else {
				if(c1 == cs) {
					c = INFINITY;
				} else {
					c = c1 * cs / (c1 - cs) * 1.0e12;
				}
			}
			if(xs == 0.0) {
				l = lp * 1.0e9;
			} else {
				if(l1 == lp) {
					l = INFINITY;
				} else {
					l = lp * l1 / (l1 - lp) * 1.0e9;
				}
			}
			lchpcval = c;
			lchpqval = fabs(Q);
			lchplval = l;
		}
	}

	if(!isfinite(lchplval) || !isfinite(lchpcval) || !isfinite(lchpqval) ||
			lchplval < 0.0 || lchpcval < 0.0 || lchpqval < 0.0 ||
			lchplval > 1e7 || lchpcval > 1e7 || lchpqval > 1e7) {
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

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), lchplval));
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), lchpcval));
	dl_tunerResultTag2->SetLabel("C Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), lchpqval));
	dl_tunerResultTag3->SetLabel("Q Value");

	Layout();
}

void tuner::CLLP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_cllp);

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
	double rp;
	double qs;
	double c;
	double l;
	double cp;
	double c1;
	double l1;
	double Q;
	double ls;

	double cllpcval;
	double cllpqval;
	double cllplval;

	if((m_sourceResistance == m_loadResistance) && (m_sourceReactance == -m_loadReactance)) {
		cllpcval = 0.0;
		cllpqval = m_sourceReactance / m_sourceResistance;
		cllplval = 0.0;
	} else {
		w = 2.0 * PI * f;
		qs = -xs / rs;
		rp = rs * (1.0 + qs * qs);
		c1 = qs / rp / w;
		l1 = xl / w;
		if(rl > rp) {
			cllpcval = NAN;
			cllpqval = NAN;
			cllplval = NAN;
		} else {
			Q = sqrt(rp / rl - 1.0);
			cp = Q / rp / w;
			c = (cp - c1) * 1.0e12;
			ls = Q * rl / w;
			l = (ls - l1) * 1.0e9;
			cllpcval = c;
			cllpqval = fabs(Q);
			cllplval = l;
		}
	}

	if(!isfinite(cllplval) || !isfinite(cllpcval) || !isfinite(cllpqval) ||
			cllplval < 0.0 || cllpcval < 0.0 || cllpqval < 0.0 ||
			cllplval > 1e7 || cllpcval > 1e7 || cllpqval > 1e7) {
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

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), cllplval));
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), cllpcval));
	dl_tunerResultTag2->SetLabel("C Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), cllpqval));
	dl_tunerResultTag3->SetLabel("Q Value");

	Layout();
}

void tuner::LCLP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_lclp);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rs = m_loadResistance;
	double xs = m_loadReactance;
	double rl = m_sourceResistance;
	double xl = m_sourceReactance;
	double f  = m_frequency;

	double w;
	double rp;
	double qs;
	double c;
	double l;
	double cp;
	double c1;
	double l1;
	double Q;
	double ls;

	double lclpcval;
	double lclpqval;
	double lclplval;

	if((m_sourceResistance == m_loadResistance) && (m_sourceReactance == -m_loadReactance)) {
		lclpcval = 0.0;
		lclpqval = m_sourceReactance / m_sourceResistance;
		lclplval = 0.0;
	} else {
		w = 2.0 * PI * f;
		qs = -xs / rs;
		rp = rs * (1.0 + qs * qs);
		c1 = qs / rp / w;
		l1 = xl / w;
		if(rl > rp) {
			lclpcval = NAN;
			lclpqval = NAN;
			lclplval = NAN;
		} else {
			Q = sqrt(rp / rl - 1.0);
			cp = Q / rp / w;
			c = (cp - c1) * 1.0e12;
			ls = Q * rl / w;
			l = (ls - l1) * 1.0e9;
			lclpcval = c;
			lclpqval = fabs(Q);
			lclplval = l;
		}
	}

	if(!isfinite(lclplval) || !isfinite(lclpcval) || !isfinite(lclpqval) ||
			lclplval < 0.0 || lclpcval < 0.0 || lclpqval < 0.0 ||
			lclplval > 1e7 || lclpcval > 1e7 || lclpqval > 1e7) {
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

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), lclplval));
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), lclpcval));
	dl_tunerResultTag2->SetLabel("C Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), lclpqval));
	dl_tunerResultTag3->SetLabel("Q Value");

	Layout();
}

void tuner::CLHP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(nt_clhp);

	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	double rs = m_loadResistance;
	double xs = m_loadReactance;
	double rl = m_sourceResistance;
	double xl = m_sourceReactance;
	double f  = m_frequency;

	double w;
	double rp;
	double qs;
	double lp;
	double c;
	double l;
	double cs;
	double c1;
	double l1;
	double Q;

	double clhpcval;
	double clhpqval;
	double clhplval;

	if((m_sourceResistance == m_loadResistance) && (m_sourceReactance == -m_loadReactance)) {
		clhpcval = 0.0;
		clhpqval = m_sourceReactance / m_sourceResistance;
		clhplval = 0.0;
	} else {
		w = 2.0 * PI * f;
		qs = xs / rs;
		c1 = -1.0 / w / xl;
		l1 = (1.0 + qs * qs) * xs / w / qs / qs;
		rp = (1.0 + qs * qs) * rs;
		rs = rl;
		if(rs > rp) {
			clhpcval = NAN;
			clhpqval = NAN;
			clhplval = NAN;
		} else {
			Q = sqrt(rp / rs - 1.0);
			lp = rp / w / Q;
			cs = 1.0 / Q / w / rs;
			if(xl == 0.0) {
				c = cs * 1.0e12;
			} else {
				if(c1 == cs) {
					c = INFINITY;
				} else {
					c = c1 * cs / (c1 - cs) * 1.0e12;
				}
			}
			if(xs == 0.0) {
				l = lp * 1.0e9;
			} else {
				if(l1 == lp) {
					l = INFINITY;
				} else {
					l = lp * l1 / (l1 - lp) * 1.0e9;
				}
			}
			clhpcval = c;
			clhpqval = fabs(Q);
			clhplval = l;
		}
	}

	if(!isfinite(clhplval) || !isfinite(clhpcval) || !isfinite(clhpqval) ||
			clhplval < 0.0 || clhpcval < 0.0 || clhpqval < 0.0 ||
			clhplval > 1e7 || clhpcval > 1e7 || clhpqval > 1e7) {
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

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), clhplval));
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), clhpcval));
	dl_tunerResultTag2->SetLabel("C Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), clhpqval));
	dl_tunerResultTag3->SetLabel("Q Value");

	Layout();
}

void tuner::HPPI()
{
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

void tuner::HP1LL()
{
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
