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

#include <complex>

#include "constants.h"
#include "tlineIcon.h"
#include "tuner.h"

// Generated images from PNG files.
#include "nt_cc1.h"
#include "nt_cc2.h"
#include "nt_ll1.h"
#include "nt_ll2.h"
#include "nt_lchp.h"
#include "nt_cllp.h"
#include "nt_lclp.h"
#include "nt_clhp.h"
#include "nt_hppi.h"
#include "nt_lppi.h"
#include "nt_hpt.h"
#include "nt_lpt.h"

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
	}

	recalculate();
}

void tuner::onFrequency( wxCommandEvent& event )
{
	m_tunerFrequencyStr = event.GetString();

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

void tuner::onTunerOKclicked( wxCommandEvent& event )
{
	if ( Validate() )
	{
		EndModal( wxID_OK );
	}
}

void tuner::findLnetComponentValues(double w, double x1, double x2, int item)
{
	double value;

	// Convert the reactances to L and C as appropriate.  The x1 side
	// is always "series-connected" and the x2 side is always
	// "parallel-connected".
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

	// Now that we have the component values, assign a topology that matches.
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

void tuner::lnetAlgorithm()
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

	// See equations.odt (or equations.pdf) for the derivation of the
	// equations used here.
	//
	// Basically, this method comes from a paper: "Impedance-Matching
	// Networks Of The L Type" by P. B. Walkley, May 1978.

	// Solution 1.
	x1 = -m_xA + m_rA * sqrtTerm;
	b2 = -bB + gB * sqrtTerm;
	x1a = x1;
	x2a = -1.0 / b2;

	// Check solution 1, as it may be bogus because of failures to overlap
	// the resistance/admittance circles.
	//
	// The real parts should be equal, and the imaginary parts should have
	// opposite signs, since we expect a conjugate match.
	left = complex<double>(m_rA, m_xA + x1);
	right = 1.0 / complex<double>(gB, bB + b2);
	if(fabs(real(left) - real(right)) < 1E-10 && fabs(imag(left) + imag(right)) < 1E-10) {
		// This solution is good.  Store the reactances and component values.
		m_walkleySolnX1[m_useSlot][0] = x1a;
		m_walkleySolnX2[m_useSlot][0] = x2a;
		findLnetComponentValues(w, x1a, x2a, 0);

		// Find the network Q.
		m_walkleySolnQ[m_useSlot][0] = fabs((m_xA + x1) / m_rA);
	}

	// Solution 2.
	x1 = -m_xA - m_rA * sqrtTerm;
	b2 = -bB - gB * sqrtTerm;
	x1b = x1;
	x2b = -1.0 / b2;

	// Check solution 2, as it may be bogus because of failures to overlap
	// the resistance/admittance circles.
	//
	// The real parts should be equal, and the imaginary parts should have
	// opposite signs, since we expect a conjugate match.
	left = complex<double>(m_rA, m_xA + x1);
	right = 1.0 / complex<double>(gB, bB + b2);
	if(fabs(real(left) - real(right)) < 1E-10 && fabs(imag(left) + imag(right)) < 1E-10) {
		// This solution is good.  Store the reactances and component values.
		m_walkleySolnX1[m_useSlot][1] = x1b;
		m_walkleySolnX2[m_useSlot][1] = x2b;
		findLnetComponentValues(w, x1b, x2b, 1);

		// Find the network Q.
		m_walkleySolnQ[m_useSlot][1] = fabs((m_xA + x1) / m_rA);
	}
}

void tuner::recalculateLnet()
{
	int i;
	int j;

	// Clear old status.  Only some solutions will be viable.
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			m_walkleySolnType[i][j] = -1;
		}
	}

	// Find all the possible solutions for a given set of impedances.
	// We will always get at least two solutions, but in some cases
	// we will get four solutions.
	//
	// Start with the source impedance as the "A" parameters, and
	// the load impedance as the "B" parameters.
	m_useSlot = 0;
	m_rA = m_sourceResistance;
	m_xA = m_sourceReactance;
	m_rB = m_loadResistance;
	m_xB = m_loadReactance;
	lnetAlgorithm();

	// Now try again, with the source and load reversed.
	m_useSlot = 1;
	m_rB = m_sourceResistance;
	m_xB = m_sourceReactance;
	m_rA = m_loadResistance;
	m_xA = m_loadReactance;
	lnetAlgorithm();
}

bool tuner::tryHPPI(
		int slot,
		double ra,
		double xa,
		double rb,
		double xb,
		double *la,
		double *c,
		double *lb
		)
{
	int i;
	int j;

	double w = 2.0 * PI * m_frequency;

	double xAdded;
	double value;

	complex<double> zA = complex<double>(ra, xa);
	complex<double> zB = complex<double>(rb, xb);

	complex<double> yA = 1.0 / zA;
	complex<double> yB = 1.0 / zB;

	complex<double> zAdded;
	complex<double> zCombined;

	// How much reactance must we add to hit our Q target?
	xAdded = 1.0 / (m_desiredQ * real(yA) + imag(yA));

	// What component type would we be adding?  It has to be an inductor for an HPPI.
	if(xAdded >= 0.0) {
		// It is an inductor.  Calculate inductance in nH.
		value = (xAdded * 1E9) / w;

		// Clear the lnet status.
		for(i = 0; i < 2; i++) {
			for(j = 0; j < 2; j++) {
				m_walkleySolnType[i][j] = -1;
			}
		}

		// Try to find solutions.  Because this is a PI-network, the source and
		// load points must be on the parallel side.
		zAdded = complex<double>(0, xAdded);
		zCombined = 1.0 / (1.0 / zA + 1.0 / zAdded);
		m_useSlot = slot;
		m_rA = real(zCombined);
		m_xA = imag(zCombined);
		m_rB = rb;
		m_xB = xb;

		// Run the L-net solver.
		lnetAlgorithm();

		// See if we found a valid solution.
		for(j = 0; j < 2; j++) {
			if(m_walkleySolnType[slot][j] != -1) {
				// L-net found something.  Test this solution.
				zAdded = complex<double>(0, m_walkleySolnX2[slot][j]);
				zCombined = 1.0 / ((1.0 / zB) + (1.0 / zAdded));
				if((m_desiredQ - fabs(imag(zCombined) / real(zCombined))) > -1E-10) {
					// This solution is ok from a Q perspective.  However, the
					// component types may or may not be correct.
					//
					// The series component must be an inductor, and the parallel
					// component must be a capacitor.
					if((m_walkleySolnSerIs[slot][j] == 'C') &&
							(m_walkleySolnParIs[slot][j] == 'L')) {
						// Good component types.
						*la = value;
						*c = m_walkleySolnSer[slot][j];
						*lb = m_walkleySolnPar[slot][j];
						//wxLogError("%d is %c %c good!", j, m_walkleySolnSerIs[slot][j], m_walkleySolnParIs[slot][j]);
						return TRUE;
					} else {
						//wxLogError("%d is %c %c", j, m_walkleySolnSerIs[slot][j], m_walkleySolnParIs[slot][j]);
					}
				} else {
					//wxLogError("%d wrong q %f vs %f", j, fabs(imag(zCombined) / real(zCombined)), m_desiredQ);
				}
			} else {
				//wxLogError("%d bad", j);
			}
		}
	} else {
		//wxLogError("not inductor");
	}
	//wxLogError("failed");

	return FALSE;
}


void tuner::recalculateHPPI()
{
	// Because of the Q constraint, we have to try this two ways, and see
	// which one works.
	if(tryHPPI(0, m_sourceResistance, m_sourceReactance, m_loadResistance, m_loadReactance, &m_lspi, &m_cpi, &m_llpi)) {
		m_hppiValid = TRUE;
		return;
	}

	if(tryHPPI(1, m_loadResistance, m_loadReactance, m_sourceResistance, m_sourceReactance, &m_llpi, &m_cpi, &m_lspi)) {
		m_hppiValid = TRUE;
		return;
	}

	m_hppiValid = FALSE;
}

void tuner::recalculateLPPI()
{
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

	if(Q < 0.0) {
		m_cspi = NAN;
		m_clpi = NAN;
		m_lpi = NAN;
	} else {
		if(Q == 0.0 && rs == rl) {
			m_cspi = 0.0;
			m_clpi = 0.0;
			m_lpi = 0.0;
		} else { 
			if(Q < sqrt(std::max(rs, rl) / std::min(rs, rl) - 1.0)) {
				m_cspi = NAN;
				m_clpi = NAN;
				m_lpi = NAN;
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
				m_cspi = cs * 1.0e12;
				ls = q * rv / w;
				q = sqrt(rpl / rv - 1.0);
				cl = q / w / rpl - cpl;
				m_clpi = cl * 1.0e12;
				ll = q * rv / w;
				l = ls + ll;
				m_lpi = l * 1.0e9;
			}
		}
	}

	if(!isfinite(m_lpi) || !isfinite(m_cspi) || !isfinite(m_clpi) ||
			m_lpi < 0.0 || m_cspi < 0.0 || m_clpi < 0.0 ||
			m_lpi > 1e7 || m_cspi > 1e7 || m_clpi > 1e7) {
		m_lppiValid = FALSE;
	} else {
		m_lppiValid = TRUE;
	}
}

void tuner::recalculateHPT()
{
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

	if(Q < 0.0) {
		m_cst = NAN;
		m_clt = NAN;
		m_lt = NAN;
	} else {
		if(Q == 0.0 && rs == rl) {
			m_cst = 0.0;
			m_clt = 0.0;
			m_lt = 0.0;
		} else {
			if(Q < sqrt(std::max(rs, rl) / std::min(rs, rl) - 1.0)) {
				m_cst = NAN;
				m_clt = NAN;
				m_lt = NAN;
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
				m_cst = cs * 1.0e12;
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
				m_clt = cl * 1.0e12;
				ll = rv / w / q;
				l = ll * ls / (ll + ls);
				m_lt = l * 1.0e9;
			}
		}
	}

	if(!isfinite(m_lt) || !isfinite(m_cst) || !isfinite(m_clt) ||
			m_lt < 0.0 || m_cst < 0.0 || m_clt < 0.0 ||
			m_lt > 1e7 || m_cst > 1e7 || m_clt > 1e7) {
		m_hptValid = FALSE;
	} else {
		m_hptValid = TRUE;
	}
}

bool tuner::tryLPT(
		int slot,
		double ra,
		double xa,
		double rb,
		double xb,
		double *la,
		double *c,
		double *lb
		)
{
	int i;
	int j;

	double w = 2.0 * PI * m_frequency;

	double xTotal;
	double xAdded;
	double value;

	// How much reactance must we add to hit our Q target?
	xTotal = ra * m_desiredQ;
	xAdded = xTotal - xa;

	// What component type would we be adding?  It has to be an inductor for an LPT.
	if(xAdded >= 0.0) {
		// It is an inductor.  Calculate inductance in nH.
		value = (xAdded * 1E9) / w;

		// Clear the lnet status.
		for(i = 0; i < 2; i++) {
			for(j = 0; j < 2; j++) {
				m_walkleySolnType[i][j] = -1;
			}
		}

		// Try to find solutions.  Because this is a T-network, the source and
		// load points must be on the series side.
		m_useSlot = slot;
		m_rA = rb;
		m_xA = xb;
		m_rB = ra;
		m_xB = xTotal;

		// Run the L-net solver.
		lnetAlgorithm();

		// See if we found a valid solution.
		for(j = 0; j < 2; j++) {
			if(m_walkleySolnType[slot][j] != -1) {
				// L-net found something.  Test this solution.
				if(m_desiredQ - fabs((m_xA + m_walkleySolnX1[slot][j]) / m_rA) >= -1E-10) {
					// This solution is ok from a Q perspective.  However, the
					// component types may or may not be correct.
					//
					// The series component must be an inductor, and the parallel
					// component must be a capacitor.
					if((m_walkleySolnSerIs[slot][j] == 'L') &&
							(m_walkleySolnParIs[slot][j] == 'C')) {
						// Good component types.
						//wxLogError("0: LS=%f C=%f LL=%f", m_walkleySolnSer[slot][j], m_walkleySolnPar[slot][j], value);
						*la = value;
						*c = m_walkleySolnPar[slot][j];
						*lb = m_walkleySolnSer[slot][j];
						return TRUE;
					}
				}
			}
		}
	}

	return FALSE;
}

void tuner::recalculateLPT()
{
	// Because of the Q constraint, we have to try this two ways, and see
	// which one works.
	if(tryLPT(0, m_sourceResistance, m_sourceReactance, m_loadResistance, m_loadReactance, &m_lst, &m_ct, &m_llt)) {
		m_lptValid = TRUE;
		return;
	}

	if(tryLPT(1, m_loadResistance, m_loadReactance, m_sourceResistance, m_sourceReactance, &m_llt, &m_ct, &m_lst)) {
		m_lptValid = TRUE;
		return;
	}

	m_lptValid = FALSE;
}

void tuner::recalculate()
{
	int i;
	int j;
	bool arry[USE_LAST];

	m_frequency = atof(m_tunerFrequencyStr) * 1.0E6;
	m_sourceResistance = atof(m_tunerSourceResistanceStr);
	m_sourceReactance = atof(m_tunerSourceReactanceStr);
	m_loadResistance = atof(m_tunerLoadResistanceStr);
	m_loadReactance = atof(m_tunerLoadReactanceStr);
	m_desiredQ = atof(m_tunerQStr);

	recalculateHPPI();
	recalculateLPPI();
	recalculateHPT();
	recalculateLPT();

	// This has to be after the PI and T calculations, because PI and T
	// overwrite the L-net solutions.
	recalculateLnet();

	// Gray out invalid radio buttons.  First handle the eight L-match
	// cases.
	for(i = 0; i < USE_LAST; i++) {
		arry[i] = FALSE;
	}
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			if(m_walkleySolnType[i][j] != -1) {
				arry[m_walkleySolnType[i][j]] = TRUE;
			}
		}
	}
	for(i = USE_CPCS; i <= USE_CLHP; i++) {
		dl_topology->Enable(i, arry[i]);
	}

	// Gray out invalid radio buttons.  Handle the PI and T match
	// cases.
	dl_topology->Enable(USE_HPPI, m_hppiValid);
	dl_topology->Enable(USE_LPPI, m_lppiValid);
	dl_topology->Enable(USE_HPT, m_hptValid);
	dl_topology->Enable(USE_LPT, m_lptValid);

	// Display the appropriate results.
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
	}
}

void tuner::lnetDisplayValues(
		int type,
		double sourceVar[2][2],
		const char *sourceLabel,
		double loadVar[2][2],
		const char *loadLabel
		)
{
	int i;
	int j;

	// There are four solution slots.  We search the slots to see if the
	// requested topology is among the solutions.
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			if(m_walkleySolnType[i][j] == type) {
				// Found a solution for the requested topology.
				// Display it.
				dl_tunerResult1->Show();
				dl_tunerResultTag1->Show();
				dl_tunerResult2->Show();
				dl_tunerResultTag2->Show();
				dl_tunerResult3->Show();
				dl_tunerResultTag3->Show();
				dl_tunerResult4->Hide();
				dl_tunerResultTag4->Hide();

				dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), sourceVar[i][j]));
				dl_tunerResultTag1->SetLabel(sourceLabel);

				dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), loadVar[i][j]));
				dl_tunerResultTag2->SetLabel(loadLabel);

				dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), m_walkleySolnQ[i][j]));
				dl_tunerResultTag3->SetLabel("Q Value");

				Layout();
				return;
			}
		}
	}

	// Invalid - no solution found for the requested topology.
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

bool tuner::lnetSetBitmap(wxBitmap bmp)
{
	int i;
	int j;

	// Display the network topology schematic.
	if ( bmp.IsOk() ) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return FALSE;
	}

	return TRUE;
}

void tuner::CPCS()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_cc1))) {
		return;
	}

	lnetDisplayValues(
			USE_CPCS,
			m_walkleySolnPar,
			"CS Value (pF)",
			m_walkleySolnSer,
			"CL Value (pF)"
			);
}

void tuner::CSCP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_cc2))) {
		return;
	}

	lnetDisplayValues(
			USE_CSCP,
			m_walkleySolnSer,
			"CS Value (pF)",
			m_walkleySolnPar,
			"CL Value (pF)"
			);
}

void tuner::LPLS()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_ll1))) {
		return;
	}

	lnetDisplayValues(
			USE_LPLS,
			m_walkleySolnPar,
			"LS Value (nH)",
			m_walkleySolnSer,
			"LL Value (nH)"
			);
}

void tuner::LSLP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_ll2))) {
		return;
	}

	lnetDisplayValues(
			USE_LSLP,
			m_walkleySolnSer,
			"LS Value (nH)",
			m_walkleySolnPar,
			"LL Value (nH)"
			);
}

void tuner::LCHP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_lchp))) {
		return;
	}

	lnetDisplayValues(
			USE_LCHP,
			m_walkleySolnPar,
			"L Value (nH)",
			m_walkleySolnSer,
			"C Value (pF)"
			);
}

void tuner::CLLP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_cllp))) {
		return;
	}

	lnetDisplayValues(
			USE_CLLP,
			m_walkleySolnPar,
			"C Value (pF)",
			m_walkleySolnSer,
			"L Value (nH)"
			);
}

void tuner::LCLP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_lclp))) {
		return;
	}

	lnetDisplayValues(
			USE_LCLP,
			m_walkleySolnSer,
			"L Value (nH)",
			m_walkleySolnPar,
			"C Value (pF)"
			);
}

void tuner::CLHP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_clhp))) {
		return;
	}

	lnetDisplayValues(
			USE_CLHP,
			m_walkleySolnSer,
			"C Value (pF)",
			m_walkleySolnPar,
			"L Value (nH)"
			);
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

	if(!m_hppiValid) {
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

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), m_cpi));
	dl_tunerResultTag1->SetLabel("C Value (pF)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), m_lspi));
	dl_tunerResultTag2->SetLabel("LS Value (nH)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), m_llpi));
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

	if(!m_lppiValid) {
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

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), m_lpi));
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), m_cspi));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), m_clpi));
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

	if(!m_hptValid) {
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

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), m_lt));
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), m_cst));
	dl_tunerResultTag2->SetLabel("CS Value (pF)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), m_clt));
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

	if(!m_lptValid) {
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

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), m_ct));
	dl_tunerResultTag1->SetLabel("C Value (pF)");

	dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), m_lst));
	dl_tunerResultTag2->SetLabel("LS Value (nH)");

	dl_tunerResult3->ChangeValue(wxString::Format(wxT("%.2f"), m_llt));
	dl_tunerResultTag3->SetLabel("LL Value (nH)");

	Layout();
}
