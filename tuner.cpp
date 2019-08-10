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

#include "tuner.h"
#include "constants.h"

#include <wx/log.h>

#include "build/nt_bp1ll.h"
#include "build/nt_bp2ll.h"
#include "build/nt_bp3ll.h"
#include "build/nt_clhp.h"
#include "build/nt_bp4ll.h"
#include "build/nt_hppi.h"
#include "build/nt_hp2ll.h"
#include "build/nt_hp1ll.h"
#include "build/nt_cllp.h"
#include "build/nt_hpt.h"
#include "build/nt_lclp.h"
#include "build/nt_lchp.h"
#include "build/nt_lp2ll.h"
#include "build/nt_lp1ll.h"
#include "build/nt_lpt.h"
#include "build/nt_lppi.h"

tuner::tuner( wxWindow* parent ) : tunerDialog( parent )
{
	recalculate();
}

void tuner::SetFrequency( double v )
{
	char buffer[512];

	m_frequency = v;

	snprintf(buffer, 512, "%.2f", m_frequency / 1e6);
	dl_tunerFrequency->ChangeValue(buffer);

	recalculate();
}

double tuner::GetSourceResistance()
{
	return m_sourceResistance;
}

void tuner::SetSourceResistance( double v )
{
	char buffer[512];

	m_sourceResistance = v;

	snprintf(buffer, 512, "%.2f", m_sourceResistance);
	dl_tunerSourceResistance->ChangeValue(buffer);

	recalculate();
}

double tuner::GetSourceReactance()
{
	return m_sourceReactance;
}

void tuner::SetSourceReactance( double v )
{
	char buffer[512];

	m_sourceReactance = v;

	snprintf(buffer, 512, "%.2f", m_sourceReactance);
	dl_tunerSourceReactance->ChangeValue(buffer);

	recalculate();
}

double tuner::GetLoadResistance()
{
	return m_loadResistance;
}

void tuner::SetLoadResistance( double v )
{
	char buffer[512];

	m_loadResistance = v;

	snprintf(buffer, 512, "%.2f", m_loadResistance);
	dl_tunerLoadResistance->ChangeValue(buffer);

	recalculate();
}

double tuner::GetLoadReactance()
{
	return m_loadReactance;
}

void tuner::SetLoadReactance( double v )
{
	char buffer[512];

	m_loadReactance = v;

	snprintf(buffer, 512, "%.2f", m_loadReactance);
	dl_tunerLoadReactance->ChangeValue(buffer);

	recalculate();
}

double tuner::GetQ()
{
	return m_desiredQ;
}

void tuner::SetQ( double v )
{
	char buffer[512];

	m_desiredQ = v;

	snprintf(buffer, 512, "%.2f", m_desiredQ);
	dl_tunerQ->ChangeValue(buffer);

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
	m_topology = event.GetString();

	recalculate();
}

void tuner::recalculate()
{

	if(strcmp(m_topology, "High Pass (Lpar Cser)") == 0) {
		LCHP();
	} else if(strcmp(m_topology, "Low Pass (Cpar Lser)") == 0) {
		CLLP();
	} else if(strcmp(m_topology, "Low Pass (Lser Cpar)") == 0) {
		LCLP();
	} else if(strcmp(m_topology, "High Pass (Cser Lpar)") == 0) {
		CLHP();
	} else if(strcmp(m_topology, "High Pass PI (Lpar Cser Lpar)") == 0) {
		HPPI();
	} else if(strcmp(m_topology, "Low Pass PI (Cpar Lser Cpar)") == 0) {
		LPPI();
	} else if(strcmp(m_topology, "High Pass T (Cser Lpar Cser)") == 0) {
		HPT();
	} else if(strcmp(m_topology, "Low Pass T (Lser Cpar Lser)") == 0) {
		LPT();
	} else if(strcmp(m_topology, "High Pass (Lpar Cser Lpar Cser)") == 0) {
		HP1LL();
	} else if(strcmp(m_topology, "High Pass (Cser Lpar Cser Lpar)") == 0) {
		HP2LL();
	} else if(strcmp(m_topology, "Low Pass (Cpar Lser Cpar Lser)") == 0) {
		LP1LL();
	} else if(strcmp(m_topology, "Low Pass (Lser Cpar Lser Cpar)") == 0) {
		LP2LL();
	} else if(strcmp(m_topology, "Band Pass (Lpar Cser Cpar Lser)") == 0) {
		BP1LL();
	} else if(strcmp(m_topology, "Band Pass (Lser Cpar Cser Lpar)") == 0) {
		BP2LL();
	} else if(strcmp(m_topology, "Band Pass (Cpar Lser Lpar Cser)") == 0) {
		BP3LL();
	} else if(strcmp(m_topology, "Band Pass (Cser Lpar Lser Cpar)") == 0) {
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
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lchp);

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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", lchplval);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	snprintf(buffer, 512, "%.2f", lchpcval);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("C Value (pF)");

	snprintf(buffer, 512, "%.2f", lchpqval);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("Q Value");

	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	Layout();
}

void tuner::CLLP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_cllp);

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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", cllplval);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	snprintf(buffer, 512, "%.2f", cllpcval);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("C Value (pF)");

	snprintf(buffer, 512, "%.2f", cllpqval);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("Q Value");

	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	Layout();
}

void tuner::LCLP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lclp);

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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", lclplval);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	snprintf(buffer, 512, "%.2f", lclpcval);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("C Value (pF)");

	snprintf(buffer, 512, "%.2f", lclpqval);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("Q Value");

	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	Layout();
}

void tuner::CLHP()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_clhp);

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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", clhplval);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	snprintf(buffer, 512, "%.2f", clhpcval);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("C Value (pF)");

	snprintf(buffer, 512, "%.2f", clhpqval);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("Q Value");

	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	Layout();
}

void tuner::HPPI()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_hppi);

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
				l = ls + ll;
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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", cpi);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("C Value (pF)");

	snprintf(buffer, 512, "%.2f", lspi);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("LS Value (nH)");

	snprintf(buffer, 512, "%.2f", llpi);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	Layout();
}

void tuner::LPPI()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lppi);

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
	double c;

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
				c = cl * cs / (cl + cs);
			}
		}
	}

	char buffer[512];

	snprintf(buffer, 512, "%.2f", lpi);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	snprintf(buffer, 512, "%.2f", cspi);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	snprintf(buffer, 512, "%.2f", clpi);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("CL Value (pF)");

	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	Layout();
}

void tuner::HPT()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_hpt);

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
	double c;

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
				c = cs + cl;
			}
		}
	}

	char buffer[512];

	snprintf(buffer, 512, "%.2f", lt);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	snprintf(buffer, 512, "%.2f", cst);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	snprintf(buffer, 512, "%.2f", clt);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("CL Value (pF)");

	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	Layout();
}

void tuner::LPT()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lpt);

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
				l = ll * ls / (ll + ls);
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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", ct);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("C Value (pF)");

	snprintf(buffer, 512, "%.2f", lst);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("LS Value (nH)");

	snprintf(buffer, 512, "%.2f", llt);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->Hide();
	dl_tunerResultTag4->Hide();

	Layout();
}

void tuner::HP1LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_hp1ll);

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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", hp1ls);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	snprintf(buffer, 512, "%.2f", hp1cs);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	snprintf(buffer, 512, "%.2f", hp1ll);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	snprintf(buffer, 512, "%.2f", hp1cl);
	dl_tunerResult4->ChangeValue(buffer);
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::HP2LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_hp2ll);

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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", hp2ls);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	snprintf(buffer, 512, "%.2f", hp2cs);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	snprintf(buffer, 512, "%.2f", hp2ll);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	snprintf(buffer, 512, "%.2f", hp2cl);
	dl_tunerResult4->ChangeValue(buffer);
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::LP1LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lp1ll);

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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", lp1ls);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	snprintf(buffer, 512, "%.2f", lp1cs);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	snprintf(buffer, 512, "%.2f", lp1ll);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	snprintf(buffer, 512, "%.2f", lp1cl);
	dl_tunerResult4->ChangeValue(buffer);
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::LP2LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_lp2ll);

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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", lp2ls);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	snprintf(buffer, 512, "%.2f", lp2cs);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	snprintf(buffer, 512, "%.2f", lp2ll);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	snprintf(buffer, 512, "%.2f", lp2cl);
	dl_tunerResult4->ChangeValue(buffer);
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::BP1LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_bp1ll);

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
	
	char buffer[512];

	snprintf(buffer, 512, "%.2f", bp1ls);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	snprintf(buffer, 512, "%.2f", bp1cs);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	snprintf(buffer, 512, "%.2f", bp1ll);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	snprintf(buffer, 512, "%.2f", bp1cl);
	dl_tunerResult4->ChangeValue(buffer);
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::BP2LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_bp2ll);

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

	char buffer[512];

	snprintf(buffer, 512, "%.2f", bp2ls);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	snprintf(buffer, 512, "%.2f", bp2cs);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	snprintf(buffer, 512, "%.2f", bp2ll);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	snprintf(buffer, 512, "%.2f", bp2cl);
	dl_tunerResult4->ChangeValue(buffer);
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::BP3LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_bp3ll);

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
	
	char buffer[512];

	snprintf(buffer, 512, "%.2f", bp3ls);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	snprintf(buffer, 512, "%.2f", bp3cs);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	snprintf(buffer, 512, "%.2f", bp3ll);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	snprintf(buffer, 512, "%.2f", bp3cl);
	dl_tunerResult4->ChangeValue(buffer);
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}

void tuner::BP4LL()
{
	wxBitmap bmp = wxBITMAP_PNG_FROM_DATA(topologies_nt_bp4ll);

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
	
	char buffer[512];

	snprintf(buffer, 512, "%.2f", bp4ls);
	dl_tunerResult1->ChangeValue(buffer);
	dl_tunerResultTag1->SetLabel("LS Value (nH)");

	snprintf(buffer, 512, "%.2f", bp4cs);
	dl_tunerResult2->ChangeValue(buffer);
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	snprintf(buffer, 512, "%.2f", bp4ll);
	dl_tunerResult3->ChangeValue(buffer);
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	dl_tunerResult4->Show();
	dl_tunerResultTag4->Show();

	snprintf(buffer, 512, "%.2f", bp4cl);
	dl_tunerResult4->ChangeValue(buffer);
	dl_tunerResultTag4->SetLabel("CL Value (pF)");

	Layout();
}
