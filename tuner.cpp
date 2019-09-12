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

#undef ENABLE_DEBUG_PI
#undef ENABLE_DEBUG_T
#undef ENABLE_DEBUG_L

#ifdef ENABLE_DEBUG_PI
    #define XDEBUG_PI(...) wxLogError(__VA_ARGS__)
#else
    #define XDEBUG_PI(...)  /**/
#endif

#ifdef ENABLE_DEBUG_T
    #define XDEBUG_T(...) wxLogError(__VA_ARGS__)
#else
    #define XDEBUG_T(...)  /**/
#endif

#ifdef ENABLE_DEBUG_L
    #define XDEBUG_L(...) wxLogError(__VA_ARGS__)
#else
    #define XDEBUG_L(...)  /**/
#endif

tuner::tuner( wxWindow* parent ) : tunerDialog( parent )
{
	SetIcon(wxICON(aaaa));
}

void tuner::Update()
{
	dl_tunerFrequency->ChangeValue(m_tunerFrequencyStr);
	dl_tunerPower->ChangeValue(m_tunerPowerStr);
	dl_tunerSourceResistance->ChangeValue(m_tunerSourceResistanceStr);
	dl_tunerSourceReactance->ChangeValue(m_tunerSourceReactanceStr);
	dl_tunerLoadResistance->ChangeValue(m_tunerLoadResistanceStr);
	dl_tunerLoadReactance->ChangeValue(m_tunerLoadReactanceStr);
	dl_tunerNetworkQ->ChangeValue(m_tunerNetworkQStr);
	dl_tunerInductorQ->ChangeValue(m_tunerInductorQStr);
	dl_tunerCapacitorQ->ChangeValue(m_tunerCapacitorQStr);

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

void tuner::onTunerFrequency( wxCommandEvent& event )
{
	m_tunerFrequencyStr = event.GetString();

	recalculate();
}

void tuner::onTunerPower( wxCommandEvent& event )
{
	m_tunerPowerStr = event.GetString();

	recalculate();
}

void tuner::onTunerSourceResistance( wxCommandEvent& event )
{
	m_tunerSourceResistanceStr = event.GetString();

	recalculate();
}

void tuner::onTunerSourceReactance( wxCommandEvent& event )
{
	m_tunerSourceReactanceStr = event.GetString();

	recalculate();
}

void tuner::onTunerLoadResistance( wxCommandEvent& event )
{
	m_tunerLoadResistanceStr = event.GetString();

	recalculate();
}

void tuner::onTunerLoadReactance( wxCommandEvent& event )
{
	m_tunerLoadReactanceStr = event.GetString();

	recalculate();
}

void tuner::onTunerNetworkQ( wxCommandEvent& event )
{
	m_tunerNetworkQStr = event.GetString();

	recalculate();
}

void tuner::onTunerInductorQ( wxCommandEvent& event )
{
	m_tunerInductorQStr = event.GetString();

	recalculate();
}

void tuner::onTunerCapacitorQ( wxCommandEvent& event )
{
	m_tunerCapacitorQStr = event.GetString();

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

void tuner::findLnetComponentValues(LNET_RESULTS *result, double w, double x1, double x2, int slot)
{
	double value;

	// Convert the reactances to L and C as appropriate.  The x1 side
	// is always "series-connected" and the x2 side is always
	// "parallel-connected".
	if(x1 >= 0) {
		// Series Inductor
		value = x1 / w;
		value *= 1E9; // nH
		result->solnSerIs[m_useSlot][slot] = 'L';
		result->solnSer[m_useSlot][slot] = value;
	} else {
		// Series Capacitor
		value = 1.0 / (-x1 * w);
		value *= 1E12; // pF
		result->solnSerIs[m_useSlot][slot] = 'C';
		result->solnSer[m_useSlot][slot] = value;
	}

	if(x2 >= 0) {
		// Parallel Inductor
		value = x2 / w;
		value *= 1E9; // nH
		result->solnParIs[m_useSlot][slot] = 'L';
		result->solnPar[m_useSlot][slot] = value;
	} else {
		// Parallel Capacitor
		value = 1.0 / (-x2 * w);
		value *= 1E12; // pF
		result->solnParIs[m_useSlot][slot] = 'C';
		result->solnPar[m_useSlot][slot] = value;
	}

	// Now that we have the component values, assign a topology that matches.
	if(m_useSlot == 0) {
		// Source is on the left (series), load is on the right (parallel).
		if(result->solnSerIs[m_useSlot][slot] == 'L' && result->solnParIs[m_useSlot][slot] == 'L') {
			result->solnType[m_useSlot][slot] = USE_LSLP;
		} else if(result->solnSerIs[m_useSlot][slot] == 'C' && result->solnParIs[m_useSlot][slot] == 'C') {
			result->solnType[m_useSlot][slot] = USE_CSCP;
		} else if(result->solnSerIs[m_useSlot][slot] == 'L' && result->solnParIs[m_useSlot][slot] == 'C') {
			result->solnType[m_useSlot][slot] = USE_LCLP;
		} else if(result->solnSerIs[m_useSlot][slot] == 'C' && result->solnParIs[m_useSlot][slot] == 'L') {
			result->solnType[m_useSlot][slot] = USE_CLHP;
		}
	} else {
		// Source is on the right (parallel), load is on the left (series).
		if(result->solnSerIs[m_useSlot][slot] == 'L' && result->solnParIs[m_useSlot][slot] == 'L') {
			result->solnType[m_useSlot][slot] = USE_LPLS;
		} else if(result->solnSerIs[m_useSlot][slot] == 'C' && result->solnParIs[m_useSlot][slot] == 'C') {
			result->solnType[m_useSlot][slot] = USE_CPCS;
		} else if(result->solnSerIs[m_useSlot][slot] == 'L' && result->solnParIs[m_useSlot][slot] == 'C') {
			result->solnType[m_useSlot][slot] = USE_CLLP;
		} else if(result->solnSerIs[m_useSlot][slot] == 'C' && result->solnParIs[m_useSlot][slot] == 'L') {
			result->solnType[m_useSlot][slot] = USE_LCHP;
		}
	}
}

void tuner::lnetInit(LNET_RESULTS *result)
{
	int i;
	int j;

	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			result->solnType[i][j] = -1;
			result->solnParRes[i][j] = 1E+200;
			result->solnSerRes[i][j] = 0.0;
		}
	}
}

void tuner::lnetAlgorithm(LNET_RESULTS *result)
{
	int slot;

	double w = 2.0 * PI * m_frequency;

	double x1a;
	double x1b;

	double x2a;
	double x2b;

	double x1;
	double b2;

	complex<double> left;
	complex<double> right;

	double sqrtTerm;

	double den;
	double gB;
	double bB;

	double ra;
	double rb;

	// See equations.odt (or equations.pdf) for the derivation of the
	// equations used here.
	//
	// Basically, this method comes from a paper: "Impedance-Matching
	// Networks Of The L Type" by P. B. Walkley, May 1978.

	// Solution 1.
	slot = 0;
	ra = m_rA - result->solnSerRes[m_useSlot][slot];
	rb = parRes(m_rB, -(result->solnParRes[m_useSlot][slot]));
	den = SQ(rb) + SQ(m_xB);
	gB =  rb / den;
	bB = -m_xB / den;
	sqrtTerm = sqrt((1.0 / (ra * gB)) - 1.0);
	x1 = -m_xA + ra * sqrtTerm;
	b2 = -bB + gB * sqrtTerm;
	x1a = x1;
	x2a = -1.0 / b2;

	// Check solution 1, as it may be bogus because of failures to overlap
	// the resistance/admittance circles.
	//
	// The real parts should be equal, and the imaginary parts should have
	// opposite signs, since we expect a conjugate match.
	left = complex<double>(ra, m_xA + x1);
	right = 1.0 / complex<double>(gB, bB + b2);
	if(fabs(real(left) - real(right)) < 1E-10 && fabs(imag(left) + imag(right)) < 1E-10) {
		// This solution is good.  Store the reactances and component values.
		result->solnX1[m_useSlot][slot] = x1a;
		result->solnX2[m_useSlot][slot] = x2a;
		findLnetComponentValues(result, w, x1a, x2a, slot);

		// Find the network Q.
		result->solnQ[m_useSlot][slot] = fabs((m_xA + x1) / ra);

		// Calculate the next values of the resistive part of the series
		// and parallel components.
		if(result->solnParIs[m_useSlot][slot] == 'C') {
			result->solnParRes[m_useSlot][slot] = -m_capacitorQ * result->solnX2[m_useSlot][slot];
		} else {
			result->solnParRes[m_useSlot][slot] = m_inductorQ * result->solnX2[m_useSlot][slot];
		}
		if(result->solnSerIs[m_useSlot][slot] == 'C') {
			result->solnSerRes[m_useSlot][slot] = -result->solnX1[m_useSlot][slot] / m_capacitorQ;
		} else {
			result->solnSerRes[m_useSlot][slot] = result->solnX1[m_useSlot][slot] / m_inductorQ;
		}
		XDEBUG_L("%d %d: %cpar=%g parRes=%g %cser=%g serRes=%g", m_useSlot, slot,
				result->solnParIs[m_useSlot][slot],
				result->solnPar[m_useSlot][slot],
				result->solnParRes[m_useSlot][slot],
				result->solnSerIs[m_useSlot][slot],
				result->solnSer[m_useSlot][slot],
				result->solnSerRes[m_useSlot][slot]);
	}

	// Solution 2.
	slot = 1;
	ra = m_rA - result->solnSerRes[m_useSlot][slot];
	rb = parRes(m_rB, -(result->solnParRes[m_useSlot][slot]));
	den = SQ(rb) + SQ(m_xB);
	gB =  rb / den;
	bB = -m_xB / den;
	sqrtTerm = sqrt((1.0 / (ra * gB)) - 1.0);
	x1 = -m_xA - ra * sqrtTerm;
	b2 = -bB - gB * sqrtTerm;
	x1b = x1;
	x2b = -1.0 / b2;

	// Check solution 2, as it may be bogus because of failures to overlap
	// the resistance/admittance circles.
	//
	// The real parts should be equal, and the imaginary parts should have
	// opposite signs, since we expect a conjugate match.
	left = complex<double>(ra, m_xA + x1);
	right = 1.0 / complex<double>(gB, bB + b2);
	if(fabs(real(left) - real(right)) < 1E-10 && fabs(imag(left) + imag(right)) < 1E-10) {
		// This solution is good.  Store the reactances and component values.
		result->solnX1[m_useSlot][slot] = x1b;
		result->solnX2[m_useSlot][slot] = x2b;
		findLnetComponentValues(result, w, x1b, x2b, slot);

		// Find the network Q.
		result->solnQ[m_useSlot][slot] = fabs((m_xA + x1) / ra);

		// Calculate the next values of the resistive part of the series
		// and parallel components.
		if(result->solnParIs[m_useSlot][slot] == 'C') {
			result->solnParRes[m_useSlot][slot] = -m_capacitorQ * result->solnX2[m_useSlot][slot];
		} else {
			result->solnParRes[m_useSlot][slot] = m_inductorQ * result->solnX2[m_useSlot][slot];
		}
		if(result->solnSerIs[m_useSlot][slot] == 'C') {
			result->solnSerRes[m_useSlot][slot] = -result->solnX1[m_useSlot][slot] / m_capacitorQ;
		} else {
			result->solnSerRes[m_useSlot][slot] = result->solnX1[m_useSlot][slot] / m_inductorQ;
		}
		XDEBUG_L("%d %d: %cpar=%g parRes=%g %cser=%g serRes=%g", m_useSlot, slot,
				result->solnParIs[m_useSlot][slot],
				result->solnPar[m_useSlot][slot],
				result->solnParRes[m_useSlot][slot],
				result->solnSerIs[m_useSlot][slot],
				result->solnSer[m_useSlot][slot],
				result->solnSerRes[m_useSlot][slot]);
	}
}

// Compute resistors in parallel.
double tuner::parRes(double a, double b)
{
	return 1.0 / (1.0 / a + 1.0 / b);
}

void tuner::recalculateLnet(LNET_RESULTS *result)
{
	int k;

	// Clear old status, and start off with ideal initial components.
	//
	// Only some solutions will be viable.
	lnetInit(result);

	// We run this in a loop, because we don't have a closed form solution
	// that takes the Q of the components into accound.  Hence we have to
	// run through a few times to converge the solution.  10 loops should
	// be more than enough.
	for(k = 0; k < 10; k++) {
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
		lnetAlgorithm(result);
	}

	for(k = 0; k < 10; k++) {
		// Now try again, with the source and load reversed.
		m_useSlot = 1;
		m_rB = m_sourceResistance;
		m_xB = m_sourceReactance;
		m_rA = m_loadResistance;
		m_xA = m_loadReactance;
		lnetAlgorithm(result);
	}
}

bool tuner::tryPI(
		int slot,
		double ra,
		double xa,
		double rb,
		double xb,
		double *outA,
		double *outB,
		double *outC,
		char expectSer,
		char expectPar,
		bool wantInductance
		)
{
	int j;

	LNET_RESULTS result;

	double w = 2.0 * PI * m_frequency;

	double rAdded;
	double xAdded;
	double value;

	complex<double> zA = complex<double>(ra, xa);
	complex<double> zB = complex<double>(rb, xb);

	complex<double> yA = 1.0 / zA;

	complex<double> zAdded;
	complex<double> zCombined;

	// How much reactance must we add to hit our Q target?
	if(wantInductance) {
		xAdded = 1.0 / (m_networkQ * real(yA) + imag(yA));
	} else {
		xAdded = 1.0 / (imag(yA) - m_networkQ * real(yA));
	}

	// What component type would we be adding?  It has to be an inductor for an HPPI
	// or a capacitor for an LPPI.
	if((wantInductance == TRUE && xAdded >= 0.0) ||
			(wantInductance == FALSE && xAdded <= 0.0)) {
		// It is correct.  Calculate inductance in nH or capacitance in pF.
		if(wantInductance == TRUE) {
			value = 1E9 * (xAdded / w);
			rAdded = m_inductorQ * xAdded;
		} else {
			value = 1E12 / (w * -xAdded);
			rAdded = m_capacitorQ * -xAdded;
		}
		XDEBUG_PI("%c %c xAdded = %f, value %f", expectSer, expectPar, xAdded, value);

		// Clear the lnet status.
		lnetInit(&result);

		// Try to find solutions.  Because this is a PI-network, the source and
		// load points must be on the parallel side.
		zAdded = complex<double>(0, xAdded);
		zCombined = 1.0 / (1.0 / zA + 1.0 / zAdded);
		m_useSlot = slot;
		m_rA = parRes(real(zCombined), -rAdded);
		m_xA = imag(zCombined);
		m_rB = rb;
		m_xB = xb;
		XDEBUG_PI("rAdded=%g xAdded=%g zCombined=%g %g rA=%g xA=%g", rAdded, xAdded, real(zCombined), imag(zCombined), m_rA, m_xA);

		// Run the L-net solver.
		lnetAlgorithm(&result);

		// See if we found a valid solution.
		for(j = 0; j < 2; j++) {
			if(result.solnType[slot][j] != -1) {
				// L-net found something.  Test this solution.
				zAdded = complex<double>(0, result.solnX2[slot][j]);
				zCombined = 1.0 / ((1.0 / zB) + (1.0 / zAdded));
				if((m_networkQ - fabs(imag(zCombined) / real(zCombined))) > -1E-10) {
					// This solution is ok from a Q perspective.  However, the
					// component types may or may not be correct.
					//
					// The series component must be an inductor, and the parallel
					// component must be a capacitor.
					if((result.solnSerIs[slot][j] == expectSer) &&
							(result.solnParIs[slot][j] == expectPar)) {
						// Good component types.
						*outA = value;
						*outB = result.solnSer[slot][j];
						*outC = result.solnPar[slot][j];
						XDEBUG_PI("%d is %c %c good!", j, result.solnSerIs[slot][j], result.solnParIs[slot][j]);
						return TRUE;
					} else {
						XDEBUG_PI("%d is %c %c bad!", j, result.solnSerIs[slot][j], result.solnParIs[slot][j]);
					}
				} else {
					XDEBUG_PI("%c %c %d wrong q %f vs %f, comps %f %f %f", expectSer, expectPar, j, fabs(imag(zCombined) / real(zCombined)), m_networkQ, value, result.solnSer[slot][j], result.solnPar[slot][j]);
				}
			} else {
				XDEBUG_PI("%c %c %d bad", expectSer, expectPar, j);
			}
		}
	} else {
		XDEBUG_PI("%c %c wrong type %f", expectSer, expectPar, xAdded);
	}

	return FALSE;
}


void tuner::recalculateHPPI()
{
	// Because of the Q constraint, we have to try this two ways, and see
	// which one works.
	if(tryPI(0, m_sourceResistance, m_sourceReactance, m_loadResistance, m_loadReactance, &m_lspi, &m_cpi, &m_llpi, 'C', 'L', TRUE)) {
		m_hppiValid = TRUE;
		return;
	}

	if(tryPI(1, m_loadResistance, m_loadReactance, m_sourceResistance, m_sourceReactance, &m_llpi, &m_cpi, &m_lspi, 'C', 'L', TRUE)) {
		m_hppiValid = TRUE;
		return;
	}

	m_hppiValid = FALSE;
}

void tuner::recalculateLPPI()
{
	// Because of the Q constraint, we have to try this two ways, and see
	// which one works.
	if(tryPI(0, m_sourceResistance, m_sourceReactance, m_loadResistance, m_loadReactance, &m_cspi, &m_lpi, &m_clpi, 'L', 'C', FALSE)) {
		m_lppiValid = TRUE;
		return;
	}

	if(tryPI(1, m_loadResistance, m_loadReactance, m_sourceResistance, m_sourceReactance, &m_clpi, &m_lpi, &m_cspi, 'L', 'C', FALSE)) {
		m_lppiValid = TRUE;
		return;
	}

	m_lppiValid = FALSE;
}

bool tuner::tryT(
		int slot,
		double ra,
		double xa,
		double rb,
		double xb,
		double *outA,
		double *outB,
		double *outC,
		char expectSer,
		char expectPar,
		bool wantInductance
		)
{
	int i;
	int j;

	LNET_RESULTS result;

	double w = 2.0 * PI * m_frequency;

	double xTotal;
	double rAdded;
	double xAdded;
	double value;

	// How much reactance must we add to hit our Q target?
	if(wantInductance) {
		xTotal = ra * m_networkQ;
		xAdded = xTotal - xa;
		rAdded = xAdded / m_inductorQ;
	} else {
		xTotal = -ra * m_networkQ;
		xAdded = xTotal - xa;
		rAdded = -xAdded / m_capacitorQ;
	}

	// What component type would we be adding?  It has to be an inductor for an LPT
	// or a capacitor for an HPT.
	if((wantInductance == TRUE && xAdded >= 0.0) ||
			(wantInductance == FALSE && xAdded <= 0.0)) {
		// It is correct.  Calculate inductance in nH or capacitance in pF.
		if(wantInductance == TRUE) {
			value = 1E9 * (xAdded / w);
		} else {
			value = 1E12 / (w * -xAdded);
		}
		XDEBUG_T("%c %c right type %f", expectSer, expectPar, value);

		// Clear the lnet status.
		lnetInit(&result);

		// Try to find solutions.  Because this is a T-network, the source and
		// load points must be on the series side.
		m_useSlot = slot;
		m_rA = rb;
		m_xA = xb;
		m_rB = ra - rAdded;
		m_xB = xTotal;

		// Run the L-net solver.
		for(i = 0; i < 10; i++) {
			lnetAlgorithm(&result);
		}

		// See if we found a valid solution.
		for(j = 0; j < 2; j++) {
			if(result.solnType[slot][j] != -1) {
				// L-net found something.  Test this solution.
				if(m_networkQ - fabs((m_xA + result.solnX1[slot][j]) / m_rA) >= -1E-10) {
					// This solution is ok from a Q perspective.  However, the
					// component types may or may not be correct.
					//
					// The series component must be an inductor, and the parallel
					// component must be a capacitor.
					if((result.solnSerIs[slot][j] == expectSer) &&
							(result.solnParIs[slot][j] == expectPar)) {
						// Good component types.
						XDEBUG_T("LS=%f C=%f LL=%f", result.solnSer[slot][j], result.solnPar[slot][j], value);
						*outA = value;
						*outB = result.solnPar[slot][j];
						*outC = result.solnSer[slot][j];
						return TRUE;
					} else {
						XDEBUG_T("bad types, want %c %c, got %c %c", expectSer, expectPar, result.solnSerIs[slot][j], result.solnParIs[slot][j]);
					}
				} else {
					XDEBUG_T("%c %c %d bad Q %f %f", expectSer, expectPar, j, m_networkQ, fabs((m_xA + result.solnX1[slot][j]) / m_rA));
				}
			} else {
				XDEBUG_T("%c %c %d invalid", expectSer, expectPar, j);
			}
		}
	} else {
		XDEBUG_T("%c %c wrong type %f", expectSer, expectPar, xAdded);
	}

	return FALSE;
}

void tuner::recalculateHPT()
{
	// Because of the Q constraint, we have to try this two ways, and see
	// which one works.
	if(tryT(0, m_sourceResistance, m_sourceReactance, m_loadResistance, m_loadReactance, &m_cst, &m_lt, &m_clt, 'C', 'L', FALSE)) {
		m_hptValid = TRUE;
		return;
	}

	if(tryT(1, m_loadResistance, m_loadReactance, m_sourceResistance, m_sourceReactance, &m_clt, &m_lt, &m_cst, 'C', 'L', FALSE)) {
		m_hptValid = TRUE;
		return;
	}

	m_hptValid = FALSE;
}

void tuner::recalculateLPT()
{
	// Because of the Q constraint, we have to try this two ways, and see
	// which one works.
	if(tryT(0, m_sourceResistance, m_sourceReactance, m_loadResistance, m_loadReactance, &m_lst, &m_ct, &m_llt, 'L', 'C', TRUE)) {
		m_lptValid = TRUE;
		return;
	}

	if(tryT(1, m_loadResistance, m_loadReactance, m_sourceResistance, m_sourceReactance, &m_llt, &m_ct, &m_lst, 'L', 'C', TRUE)) {
		m_lptValid = TRUE;
		return;
	}

	m_lptValid = FALSE;
}

void tuner::recalculatePower()
{
	m_sourceImpedance = complex<double>(m_sourceResistance, m_sourceReactance);
	m_voltageForPower = sqrt(m_power * m_sourceImpedance);
	m_currentForPower = sqrt(m_power / m_sourceImpedance);
}

void tuner::recalculate()
{
	int i;
	int j;
	bool arry[USE_LAST];

	m_frequency = atof(m_tunerFrequencyStr) * 1.0E6;
	m_power = atof(m_tunerPowerStr);
	m_sourceResistance = atof(m_tunerSourceResistanceStr);
	m_sourceReactance = atof(m_tunerSourceReactanceStr);
	m_loadResistance = atof(m_tunerLoadResistanceStr);
	m_loadReactance = atof(m_tunerLoadReactanceStr);
	m_networkQ = atof(m_tunerNetworkQStr);
	m_inductorQ = atof(m_tunerInductorQStr);
	m_capacitorQ = atof(m_tunerCapacitorQStr);

	recalculatePower();
	recalculateLnet(&m_lnet);
	recalculateHPPI();
	recalculateLPPI();
	recalculateHPT();
	recalculateLPT();

	// Gray out invalid radio buttons.  First handle the eight L-match
	// cases.
	for(i = 0; i < USE_LAST; i++) {
		arry[i] = FALSE;
	}
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			if(m_lnet.solnType[i][j] != -1) {
				arry[m_lnet.solnType[i][j]] = TRUE;
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
		int sourceConnect,
		double sourceVar[2][2],
		double sourceRes[2][2],
		wxString sourceLabel,
		int loadConnect,
		double loadVar[2][2],
		double loadRes[2][2],
		wxString loadLabel
		)
{
	int i;
	int j;

	// There are four solution slots.  We search the slots to see if the
	// requested topology is among the solutions.
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			if(m_lnet.solnType[i][j] == type) {
				// Found a solution for the requested topology.
				// Display it.
				dl_tunerResult1->Show();
				dl_tunerResultTag1->Show();
				dl_tunerResult2->Show();
				dl_tunerResultTag2->Show();
				dl_tunerResult3->Show();
				dl_tunerResultTag3->Show();
				dl_tunerResult4->Show();
				dl_tunerResultTag4->Show();
				dl_tunerResult5->Show();
				dl_tunerResultTag5->Show();
				dl_tunerResult6->Show();
				dl_tunerResultTag6->Show();
				dl_tunerResult7->Show();
				dl_tunerResultTag7->Show();
				dl_tunerResult8->Hide();
				dl_tunerResultTag8->Hide();
				dl_tunerResult9->Hide();
				dl_tunerResultTag9->Hide();
				dl_tunerResult10->Hide();
				dl_tunerResultTag10->Hide();

				dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), sourceVar[i][j]));
				if(sourceLabel.at(0) == 'C') {
					dl_tunerResultTag1->SetLabel(sourceLabel + " Value (pF)");
				} else {
					dl_tunerResultTag1->SetLabel(sourceLabel + " Value (nH)");
				}

				if(sourceConnect == IS_PAR) {
					// Use voltage for loss.
					dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), sourceVar[i][j]));
					dl_tunerResultTag2->SetLabel(sourceLabel + " Voltage");
				} else {
					// Use current for loss.
					dl_tunerResult2->ChangeValue(wxString::Format(wxT("%.2f"), sourceVar[i][j]));
					dl_tunerResultTag2->SetLabel(sourceLabel + " Current");
				}

				dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), loadVar[i][j]));
				if(loadLabel.at(0) == 'C') {
					dl_tunerResultTag4->SetLabel(loadLabel + " Value (pF)");
				} else {
					dl_tunerResultTag4->SetLabel(loadLabel + " Value (nH)");
				}

				if(loadConnect == IS_PAR) {
					// Use voltage for loss.
					dl_tunerResult5->ChangeValue(wxString::Format(wxT("%.2f"), loadVar[i][j]));
					dl_tunerResultTag5->SetLabel(loadLabel + " Voltage");
				} else {
					// Use current for loss.
					dl_tunerResult5->ChangeValue(wxString::Format(wxT("%.2f"), loadVar[i][j]));
					dl_tunerResultTag5->SetLabel(loadLabel + " Current");
				}

				dl_tunerResult7->ChangeValue(wxString::Format(wxT("%.2f"), m_lnet.solnQ[i][j]));
				dl_tunerResultTag7->SetLabel("Q Value");

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
	dl_tunerResult5->Hide();
	dl_tunerResultTag5->Hide();
	dl_tunerResult6->Hide();
	dl_tunerResultTag6->Hide();
	dl_tunerResult7->Hide();
	dl_tunerResultTag7->Hide();
	dl_tunerResult8->Hide();
	dl_tunerResultTag8->Hide();
	dl_tunerResult9->Hide();
	dl_tunerResultTag9->Hide();
	dl_tunerResult10->Hide();
	dl_tunerResultTag10->Hide();

	dl_tunerResultTag1->SetLabel("No Match Found");

	Layout();
}

bool tuner::lnetSetBitmap(wxBitmap bmp)
{
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

			IS_PAR,
			m_lnet.solnPar,
			m_lnet.solnParRes,
			"CS",

			IS_SER,
			m_lnet.solnSer,
			m_lnet.solnSerRes,
			"CL"
			);
}

void tuner::CSCP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_cc2))) {
		return;
	}

	lnetDisplayValues(
			USE_CSCP,

			IS_SER,
			m_lnet.solnSer,
			m_lnet.solnSerRes,
			"CS",

			IS_PAR,
			m_lnet.solnPar,
			m_lnet.solnParRes,
			"CL"
			);
}

void tuner::LPLS()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_ll1))) {
		return;
	}

	lnetDisplayValues(
			USE_LPLS,

			IS_PAR,
			m_lnet.solnPar,
			m_lnet.solnParRes,
			"LS",

			IS_SER,
			m_lnet.solnSer,
			m_lnet.solnSerRes,
			"LL"
			);
}

void tuner::LSLP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_ll2))) {
		return;
	}

	lnetDisplayValues(
			USE_LSLP,

			IS_SER,
			m_lnet.solnSer,
			m_lnet.solnSerRes,
			"LS",

			IS_PAR,
			m_lnet.solnPar,
			m_lnet.solnParRes,
			"LL"
			);
}

void tuner::LCHP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_lchp))) {
		return;
	}

	lnetDisplayValues(
			USE_LCHP,

			IS_PAR,
			m_lnet.solnPar,
			m_lnet.solnParRes,
			"L",

			IS_SER,
			m_lnet.solnSer,
			m_lnet.solnSerRes,
			"C"
			);
}

void tuner::CLLP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_cllp))) {
		return;
	}

	lnetDisplayValues(
			USE_CLLP,

			IS_PAR,
			m_lnet.solnPar,
			m_lnet.solnParRes,
			"C",

			IS_SER,
			m_lnet.solnSer,
			m_lnet.solnSerRes,
			"L"
			);
}

void tuner::LCLP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_lclp))) {
		return;
	}

	lnetDisplayValues(
			USE_LCLP,

			IS_SER,
			m_lnet.solnSer,
			m_lnet.solnSerRes,
			"L",

			IS_PAR,
			m_lnet.solnPar,
			m_lnet.solnParRes,
			"C"
			);
}

void tuner::CLHP()
{
	if(!lnetSetBitmap(wxBITMAP_PNG_FROM_DATA(nt_clhp))) {
		return;
	}

	lnetDisplayValues(
			USE_CLHP,

			IS_SER,
			m_lnet.solnSer,
			m_lnet.solnSerRes,
			"C",

			IS_PAR,
			m_lnet.solnPar,
			m_lnet.solnParRes,
			"L"
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
		dl_tunerResult5->Hide();
		dl_tunerResultTag5->Hide();
		dl_tunerResult6->Hide();
		dl_tunerResultTag6->Hide();
		dl_tunerResult7->Hide();
		dl_tunerResultTag7->Hide();
		dl_tunerResult8->Hide();
		dl_tunerResultTag8->Hide();
		dl_tunerResult9->Hide();
		dl_tunerResultTag9->Hide();
		dl_tunerResult10->Hide();
		dl_tunerResultTag10->Hide();

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
	dl_tunerResult5->Show();
	dl_tunerResultTag5->Show();
	dl_tunerResult6->Show();
	dl_tunerResultTag6->Show();
	dl_tunerResult7->Show();
	dl_tunerResultTag7->Show();
	dl_tunerResult8->Show();
	dl_tunerResultTag8->Show();
	dl_tunerResult9->Show();
	dl_tunerResultTag9->Show();
	dl_tunerResult10->Hide();
	dl_tunerResultTag10->Hide();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), m_cpi));
	dl_tunerResultTag1->SetLabel("C Value (pF)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), m_lspi));
	dl_tunerResultTag4->SetLabel("LS Value (nH)");

	dl_tunerResult7->ChangeValue(wxString::Format(wxT("%.2f"), m_llpi));
	dl_tunerResultTag7->SetLabel("LL Value (nH)");

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
		dl_tunerResult5->Hide();
		dl_tunerResultTag5->Hide();
		dl_tunerResult6->Hide();
		dl_tunerResultTag6->Hide();
		dl_tunerResult7->Hide();
		dl_tunerResultTag7->Hide();
		dl_tunerResult8->Hide();
		dl_tunerResultTag8->Hide();
		dl_tunerResult9->Hide();
		dl_tunerResultTag9->Hide();
		dl_tunerResult10->Hide();
		dl_tunerResultTag10->Hide();

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
	dl_tunerResult5->Show();
	dl_tunerResultTag5->Show();
	dl_tunerResult6->Show();
	dl_tunerResultTag6->Show();
	dl_tunerResult7->Show();
	dl_tunerResultTag7->Show();
	dl_tunerResult8->Show();
	dl_tunerResultTag8->Show();
	dl_tunerResult9->Show();
	dl_tunerResultTag9->Show();
	dl_tunerResult10->Hide();
	dl_tunerResultTag10->Hide();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), m_lpi));
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), m_cspi));
	dl_tunerResultTag4->SetLabel("CS Value (pF)");

	dl_tunerResult7->ChangeValue(wxString::Format(wxT("%.2f"), m_clpi));
	dl_tunerResultTag7->SetLabel("CL Value (pF)");

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
		dl_tunerResult5->Hide();
		dl_tunerResultTag5->Hide();
		dl_tunerResult6->Hide();
		dl_tunerResultTag6->Hide();
		dl_tunerResult7->Hide();
		dl_tunerResultTag7->Hide();
		dl_tunerResult8->Hide();
		dl_tunerResultTag8->Hide();
		dl_tunerResult9->Hide();
		dl_tunerResultTag9->Hide();
		dl_tunerResult10->Hide();
		dl_tunerResultTag10->Hide();

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
	dl_tunerResult5->Show();
	dl_tunerResultTag5->Show();
	dl_tunerResult6->Show();
	dl_tunerResultTag6->Show();
	dl_tunerResult7->Show();
	dl_tunerResultTag7->Show();
	dl_tunerResult8->Show();
	dl_tunerResultTag8->Show();
	dl_tunerResult9->Show();
	dl_tunerResultTag9->Show();
	dl_tunerResult10->Hide();
	dl_tunerResultTag10->Hide();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), m_lt));
	dl_tunerResultTag1->SetLabel("L Value (nH)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), m_cst));
	dl_tunerResultTag4->SetLabel("CS Value (pF)");

	dl_tunerResult7->ChangeValue(wxString::Format(wxT("%.2f"), m_clt));
	dl_tunerResultTag7->SetLabel("CL Value (pF)");

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
		dl_tunerResult5->Hide();
		dl_tunerResultTag5->Hide();
		dl_tunerResult6->Hide();
		dl_tunerResultTag6->Hide();
		dl_tunerResult7->Hide();
		dl_tunerResultTag7->Hide();
		dl_tunerResult8->Hide();
		dl_tunerResultTag8->Hide();
		dl_tunerResult9->Hide();
		dl_tunerResultTag9->Hide();
		dl_tunerResult10->Hide();
		dl_tunerResultTag10->Hide();

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
	dl_tunerResult5->Show();
	dl_tunerResultTag5->Show();
	dl_tunerResult6->Show();
	dl_tunerResultTag6->Show();
	dl_tunerResult7->Show();
	dl_tunerResultTag7->Show();
	dl_tunerResult8->Show();
	dl_tunerResultTag8->Show();
	dl_tunerResult9->Show();
	dl_tunerResultTag9->Show();
	dl_tunerResult10->Hide();
	dl_tunerResultTag10->Hide();

	dl_tunerResult1->ChangeValue(wxString::Format(wxT("%.2f"), m_ct));
	dl_tunerResultTag1->SetLabel("C Value (pF)");

	dl_tunerResult4->ChangeValue(wxString::Format(wxT("%.2f"), m_lst));
	dl_tunerResultTag4->SetLabel("LS Value (nH)");

	dl_tunerResult7->ChangeValue(wxString::Format(wxT("%.2f"), m_llt));
	dl_tunerResultTag7->SetLabel("LL Value (nH)");

	Layout();
}
