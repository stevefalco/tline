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
#undef ENABLE_DEBUG_DISP

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

#ifdef ENABLE_DEBUG_DISP
    #define XDEBUG_DISP(...) wxLogError(__VA_ARGS__)
#else
    #define XDEBUG_DISP(...)  /**/
#endif

tuner::tuner( wxWindow* parent ) : tunerDialog( parent )
{
	int i;

	SetIcon(wxICON(aaaa));

	// We need a convenient way to map from array indexing
	// to the gui structures.
	m_r[0].box	= sbTunerResults1;
	m_r[0].line0	= dl_tunerResult1;
	m_r[0].line0Tag	= dl_tunerResultTag1;
	m_r[0].line1	= dl_tunerResult2;
	m_r[0].line1Tag	= dl_tunerResultTag2;
	m_r[0].line2	= dl_tunerResult3;
	m_r[0].line2Tag	= dl_tunerResultTag3;
	m_r[0].line3	= dl_tunerResult4;
	m_r[0].line3Tag	= dl_tunerResultTag4;
	m_r[1].box	= sbTunerResults2;
	m_r[1].line0	= dl_tunerResult5;
	m_r[1].line0Tag	= dl_tunerResultTag5;
	m_r[1].line1	= dl_tunerResult6;
	m_r[1].line1Tag	= dl_tunerResultTag6;
	m_r[1].line2	= dl_tunerResult7;
	m_r[1].line2Tag	= dl_tunerResultTag7;
	m_r[1].line3	= dl_tunerResult8;
	m_r[1].line3Tag	= dl_tunerResultTag8;
	m_r[2].box	= sbTunerResults3;
	m_r[2].line0	= dl_tunerResult9;
	m_r[2].line0Tag	= dl_tunerResultTag9;
	m_r[2].line1	= dl_tunerResult10;
	m_r[2].line1Tag	= dl_tunerResultTag10;
	m_r[2].line2	= dl_tunerResult11;
	m_r[2].line2Tag	= dl_tunerResultTag11;
	m_r[2].line3	= dl_tunerResult12;
	m_r[2].line3Tag	= dl_tunerResultTag12;
	m_r[3].box	= sbTunerResults4;
	m_r[3].line0	= dl_tunerResult13;
	m_r[3].line0Tag	= dl_tunerResultTag13;
	m_r[3].line1	= dl_tunerResult14;
	m_r[3].line1Tag	= dl_tunerResultTag14;
	m_r[3].line2	= dl_tunerResult15;
	m_r[3].line2Tag	= dl_tunerResultTag15;
	m_r[3].line3	= dl_tunerResult16;
	m_r[3].line3Tag	= dl_tunerResultTag16;

	// Start out with all results hidden.
	for(i = 0; i < (MAX_COMPONENTS + 1); i++) {
		m_r[i].box->GetStaticBox()->Hide();
	}
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

double tuner::powerFromVoltage(
		complex<double> voltage,
		complex<double> admittance
		)
{
	return real(voltage * conj(voltage) * admittance);
}

double tuner::powerFromCurrent(
		complex<double> current,
		complex<double> impedance
		)
{
	return real(current * conj(current) * impedance);
}

void tuner::findLnetComponentValues(LNET_RESULTS *result, double w, double x1, double x2, int slot)
{
	SOLUTION *p;

	double value;

	p = &result->s[m_useSlot][slot];

	// Convert the reactances to L and C as appropriate.  The x1 side
	// is always "series-connected" and the x2 side is always
	// "parallel-connected".
	if(x1 >= 0) {
		// Series Inductor
		value = x1 / w;
		value *= 1E9; // nH
		p->seriesComponentType = 'L';
		p->seriesComponentValue = value;
	} else {
		// Series Capacitor
		value = 1.0 / (-x1 * w);
		value *= 1E12; // pF
		p->seriesComponentType = 'C';
		p->seriesComponentValue = value;
	}

	if(x2 >= 0) {
		// Parallel Inductor
		value = x2 / w;
		value *= 1E9; // nH
		p->parallelComponentType = 'L';
		p->parallelComponentValue = value;
	} else {
		// Parallel Capacitor
		value = 1.0 / (-x2 * w);
		value *= 1E12; // pF
		p->parallelComponentType = 'C';
		p->parallelComponentValue = value;
	}

	// Now that we have the component values, assign a topology that matches.
	if(m_useSlot == 0) {
		// Source is on the left (series), load is on the right (parallel).
		if(p->seriesComponentType == 'L' && p->parallelComponentType == 'L') {
			p->type = USE_LSLP;
		} else if(p->seriesComponentType == 'C' && p->parallelComponentType == 'C') {
			p->type = USE_CSCP;
		} else if(p->seriesComponentType == 'L' && p->parallelComponentType == 'C') {
			p->type = USE_LCLP;
		} else if(p->seriesComponentType == 'C' && p->parallelComponentType == 'L') {
			p->type = USE_CLHP;
		}
	} else {
		// Source is on the right (parallel), load is on the left (series).
		if(p->seriesComponentType == 'L' && p->parallelComponentType == 'L') {
			p->type = USE_LPLS;
		} else if(p->seriesComponentType == 'C' && p->parallelComponentType == 'C') {
			p->type = USE_CPCS;
		} else if(p->seriesComponentType == 'L' && p->parallelComponentType == 'C') {
			p->type = USE_CLLP;
		} else if(p->seriesComponentType == 'C' && p->parallelComponentType == 'L') {
			p->type = USE_LCHP;
		}
	}
}

void tuner::lnetInit(LNET_RESULTS *result)
{
	int j;
	int k;

	SOLUTION *p;

	// Start off with "no solution" and ideal components.
	for(j = 0; j < 2; j++) {
		for(k = 0; k < 2; k++) {
			p = &result->s[j][k];
			p->type = -1;
			p->parallelComponentResistance = 0.0;
			p->seriesComponentResistance = 0.0;
		}
	}
}

void tuner::lnetAlgorithm(wxString where, LNET_RESULTS *result)
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

	complex<double> z;
	complex<double> y;
	double gB;
	double bB;

	double ra;
	double rb;

	SOLUTION *p;

	// See equations.odt (or equations.pdf) for the derivation of the
	// equations used here.
	//
	// Basically, this method comes from a paper: "Impedance-Matching
	// Networks Of The L Type" by P. B. Walkley, May 1978.

	// Solution 1.
	slot = 0;
	p = &result->s[m_useSlot][slot];
	ra = m_rA;
	rb = m_rB;
	z = complex<double>(rb, m_xB);
	y = 1.0 / z;
	gB = real(y);
	bB = imag(y);
	sqrtTerm = sqrt((1.0 / (ra * gB)) - 1.0);
	x1 = -m_xA + ra * sqrtTerm;
	b2 = -bB + gB * sqrtTerm;
	x1a = x1;
	x2a = -1.0 / b2;

	// Check solution 1, as it may be bogus because of failures to overlap
	// the impedance/admittance circles.
	//
	// The real parts should be equal, and the imaginary parts should have
	// opposite signs, since we expect a conjugate match.
	//
	// Also, we want "normal" values for x1 and b2.  I.e., not NaN, inf, etc.
	left = complex<double>(ra, m_xA + x1);
	right = 1.0 / complex<double>(gB, bB + b2);
	if(fabs(real(left) - real(right)) < 1E-10 && fabs(imag(left) + imag(right)) < 1E-10 && isnormal(x1) && isnormal(b2)) {
		// This solution is good.  Store the reactances and component values.
		p->seriesComponentReactance = x1a;
		p->parallelComponentReactance = x2a;
		findLnetComponentValues(result, w, x1a, x2a, slot);

		// Find the network Q.
		p->qualityFactor = fabs((m_xA + x1) / ra);

		// Calculate the values of the resistive part of the series
		// and parallel components.
		if(p->parallelComponentType == 'C') {
			p->parallelComponentResistance = -p->parallelComponentReactance / m_capacitorQ;
		} else {
			p->parallelComponentResistance = p->parallelComponentReactance / m_inductorQ;
		}
		if(p->seriesComponentType == 'C') {
			p->seriesComponentResistance = -p->seriesComponentReactance / m_capacitorQ;
		} else {
			p->seriesComponentResistance = p->seriesComponentReactance / m_inductorQ;
		}
		XDEBUG_L("%s %d %d: ra=%g rb=%g %cpar=%g parR=%g parX=%g %cser=%g serR=%g serX=%g",
				where,
				m_useSlot, slot,
				ra, rb,
				p->parallelComponentType,
				p->parallelComponentValue,
				p->parallelComponentResistance,
				p->parallelComponentReactance,
				p->seriesComponentType,
				p->seriesComponentValue,
				p->seriesComponentResistance,
				p->seriesComponentReactance);
	}

	// Solution 2.
	slot = 1;
	p = &result->s[m_useSlot][slot];
	ra = m_rA;
	rb = m_rB;
	z = complex<double>(rb, m_xB);
	y = 1.0 / z;
	gB = real(y);
	bB = imag(y);
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
	//
	// Also, we want "normal" values for x1 and b2.  I.e., not NaN, inf, etc.
	left = complex<double>(ra, m_xA + x1);
	right = 1.0 / complex<double>(gB, bB + b2);
	if(fabs(real(left) - real(right)) < 1E-10 && fabs(imag(left) + imag(right)) < 1E-10 && isnormal(x1) && isnormal(b2)) {
		// This solution is good.  Store the reactances and component values.
		p->seriesComponentReactance = x1b;
		p->parallelComponentReactance = x2b;
		findLnetComponentValues(result, w, x1b, x2b, slot);

		// Find the network Q.
		p->qualityFactor = fabs((m_xA + x1) / ra);

		// Calculate the values of the resistive part of the series
		// and parallel components.
		if(p->parallelComponentType == 'C') {
			p->parallelComponentResistance = -p->parallelComponentReactance / m_capacitorQ;
		} else {
			p->parallelComponentResistance = p->parallelComponentReactance / m_inductorQ;
		}
		if(p->seriesComponentType == 'C') {
			p->seriesComponentResistance = -p->seriesComponentReactance / m_capacitorQ;
		} else {
			p->seriesComponentResistance = p->seriesComponentReactance / m_inductorQ;
		}
		XDEBUG_L("%s %d %d: ra=%g rb=%g %cpar=%g parR=%g parX=%g %cser=%g serR=%g serX=%g",
				where,
			       	m_useSlot, slot,
				ra, rb,
				p->parallelComponentType,
				p->parallelComponentValue,
				p->parallelComponentResistance,
				p->parallelComponentReactance,
				p->seriesComponentType,
				p->seriesComponentValue,
				p->seriesComponentResistance,
				p->seriesComponentReactance);
	}
}

void tuner::recalculateLnet(LNET_RESULTS *result)
{
	// Clear old status, and start off with ideal initial components.
	//
	// Only some solutions will be viable.
	lnetInit(result);

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
	lnetAlgorithm("L1", result);

	// Now try again, with the source and load reversed.
	m_useSlot = 1;
	m_rB = m_sourceResistance;
	m_xB = m_sourceReactance;
	m_rA = m_loadResistance;
	m_xA = m_loadReactance;
	lnetAlgorithm("L2", result);
}

bool tuner::tryPI(
		wxString where,
		int slot,
		double ra,
		double xa,
		double rb,
		double xb,
		double *outA,
		double *outAR,
		double *outAX,
		double *outB,
		double *outBR,
		double *outBX,
		double *outC,
		double *outCR,
		double *outCX,
		char expectSer,
		char expectPar,
		bool wantInductance
		)
{
	int j;

	LNET_RESULTS result;
	SOLUTION *p;

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
	if(!isnormal(xAdded)) {
		return FALSE;
	}

	// What component type would we be adding?  It has to be an inductor for an HPPI
	// or a capacitor for an LPPI.
	if((wantInductance == TRUE && xAdded >= 0.0) ||
			(wantInductance == FALSE && xAdded <= 0.0)) {
		// The component type is correct.  Calculate inductance in nH or
		// capacitance in pF.  Also find the resistive value for the
		// (lossy) components.
		if(wantInductance == TRUE) {
			value = 1E9 * (xAdded / w);
			rAdded = xAdded / m_inductorQ;
		} else {
			value = 1E12 / (w * -xAdded);
			rAdded = -xAdded / m_capacitorQ;
		}
		XDEBUG_PI("%c %c xAdded = %f, value %f", expectSer, expectPar, xAdded, value);

		// Clear the lnet status.
		lnetInit(&result);

		// Try to find solutions.  Because this is a PI-network, the source and
		// load points must be on the parallel side.
		zAdded = complex<double>(0, xAdded);
		zCombined = 1.0 / (1.0 / zA + 1.0 / zAdded);
		m_useSlot = slot;
		m_rA = real(zCombined);
		m_xA = imag(zCombined);
		m_rB = rb;
		m_xB = xb;
		XDEBUG_PI("rAdded=%g xAdded=%g zCombined=%g %g rA=%g xA=%g", rAdded, xAdded, real(zCombined), imag(zCombined), m_rA, m_xA);

		// Run the L-net solver.
		lnetAlgorithm(where, &result);

		// See if we found a valid solution.
		for(j = 0; j < 2; j++) {
			p = &result.s[slot][j];
			if(p->type != -1) {
				// L-net found something.  Test this solution - we must
				// be sure not to exceed the specified Q.
				zAdded = complex<double>(0, p->parallelComponentReactance);
				zCombined = 1.0 / ((1.0 / zB) + (1.0 / zAdded));
				if((m_networkQ - fabs(imag(zCombined) / real(zCombined))) > -1E-10) {
					// This solution is ok from a Q perspective.  However, the
					// component types may or may not be correct.
					if((p->seriesComponentType == expectSer) &&
							(p->parallelComponentType == expectPar)) {
						// Good component types.
						*outA = value;
						*outAR = rAdded;
						*outAX = xAdded;
						*outB = p->seriesComponentValue;
						*outBR = p->seriesComponentResistance;
						*outBX = p->seriesComponentReactance;
						*outC = p->parallelComponentValue;
						*outCR = p->parallelComponentResistance;
						*outCX = p->parallelComponentReactance;
						XDEBUG_PI("%d is %c %c good!", j, p->seriesComponentType, p->parallelComponentType);
						return TRUE;
					} else {
						XDEBUG_PI("%d is %c %c bad!", j, p->seriesComponentType, p->parallelComponentType);
					}
				} else {
					XDEBUG_PI("%c %c %d wrong q %f vs %f, comps %f %f %f", expectSer, expectPar, j, fabs(imag(zCombined) / real(zCombined)), m_networkQ, value, p->seriesComponentValue, p->parallelComponentValue);
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
	//
	// Try source on the left and load on the right.
	if(tryPI("HPPI", 0, m_sourceResistance, m_sourceReactance, m_loadResistance, m_loadReactance,
				&m_lspi,
				&m_lspiR,
				&m_lspiX,
				&m_cpi,
				&m_cpiR,
				&m_cpiX,
				&m_llpi,
				&m_llpiR,
				&m_llpiX,
				'C', 'L', TRUE)) {
		m_hppiValid = TRUE;
		return;
	}

	// Try load on the left and source on the right.
	if(tryPI("HPPI", 1, m_loadResistance, m_loadReactance, m_sourceResistance, m_sourceReactance,
				&m_llpi,
				&m_llpiR,
				&m_llpiX,
				&m_cpi,
				&m_cpiR,
				&m_cpiX,
				&m_lspi,
				&m_lspiR,
				&m_lspiX,
				'C', 'L', TRUE)) {
		m_hppiValid = TRUE;
		return;
	}

	// Neither one is valid.
	m_hppiValid = FALSE;
}

void tuner::recalculateLPPI()
{
	// Because of the Q constraint, we have to try this two ways, and see
	// which one works.
	//
	// Try source on the left and load on the right.
	if(tryPI("LPPI", 0, m_sourceResistance, m_sourceReactance, m_loadResistance, m_loadReactance,
				&m_cspi,
				&m_cspiR,
				&m_cspiX,
				&m_lpi,
				&m_lpiR,
				&m_lpiX,
				&m_clpi,
				&m_clpiR,
				&m_clpiX,
				'L', 'C', FALSE)) {
		m_lppiValid = TRUE;
		return;
	}

	// Try load on the left and source on the right.
	if(tryPI("LPPI", 1, m_loadResistance, m_loadReactance, m_sourceResistance, m_sourceReactance,
				&m_clpi,
				&m_clpiR,
				&m_clpiX,
				&m_lpi,
				&m_lpiR,
				&m_lpiX,
				&m_cspi,
				&m_cspiR,
				&m_cspiX,
				'L', 'C', FALSE)) {
		m_lppiValid = TRUE;
		return;
	}

	// Neither one is valid.
	m_lppiValid = FALSE;
}

bool tuner::tryT(
		wxString where,
		int slot,
		double ra,
		double xa,
		double rb,
		double xb,
		double *outA,
		double *outAR,
		double *outAX,
		double *outB,
		double *outBR,
		double *outBX,
		double *outC,
		double *outCR,
		double *outCX,
		char expectSer,
		char expectPar,
		bool wantInductance
		)
{
	int i;

	LNET_RESULTS result;
	SOLUTION *p;

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
	if(!isnormal(xAdded)) {
		return FALSE;
	}

	// What component type would we be adding?  It has to be an inductor for an LPT
	// or a capacitor for an HPT.
	if((wantInductance == TRUE && xAdded >= 0.0) ||
			(wantInductance == FALSE && xAdded <= 0.0)) {
		// The component type is correct.  Calculate inductance in nH or
		// capacitance in pF.  Also find the resistive value for the
		// (lossy) components.
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
		m_rB = ra;
		m_xB = xTotal;

		// Run the L-net solver.
		lnetAlgorithm(where, &result);

		// See if we found a valid solution.
		for(i = 0; i < 2; i++) {
			p = &result.s[slot][i];
			if(p->type != -1) {
				// L-net found something.  Test this solution - we must
				// be sure not to exceed the specified Q.
				if(m_networkQ - fabs((m_xA + p->seriesComponentReactance) / m_rA) >= -1E-10) {
					// This solution is ok from a Q perspective.  However, the
					// component types may or may not be correct.
					if((p->seriesComponentType == expectSer) &&
							(p->parallelComponentType == expectPar)) {
						// Good component types.
						XDEBUG_T("LS=%f C=%f LL=%f", p->seriesComponentValue, p->parallelComponentValue, value);
						*outA = value;
						*outAR = rAdded;
						*outAX = xAdded;
						*outB = p->parallelComponentValue;
						*outBR = p->parallelComponentResistance;
						*outBX = p->parallelComponentReactance;
						*outC = p->seriesComponentValue;
						*outCR = p->seriesComponentResistance;
						*outCX = p->seriesComponentReactance;
						return TRUE;
					} else {
						XDEBUG_T("bad types, want %c %c, got %c %c", expectSer, expectPar, p->seriesComponentType, p->parallelComponentType);
					}
				} else {
					XDEBUG_T("%c %c %d bad Q %f %f", expectSer, expectPar, i, m_networkQ, fabs((m_xA + p->seriesComponentReactance) / m_rA));
				}
			} else {
				XDEBUG_T("%c %c %d invalid", expectSer, expectPar, i);
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
	//
	// Try source on the left and load on the right.
	if(tryT("HPT", 0, m_sourceResistance, m_sourceReactance, m_loadResistance, m_loadReactance,
				&m_cst,
				&m_cstR,
				&m_cstX,
				&m_lt,
				&m_ltR,
				&m_ltX,
				&m_clt,
				&m_cltR,
				&m_cltX,
				'C', 'L', FALSE)) {
		m_hptValid = TRUE;
		return;
	}

	// Try load on the left and source on the right.
	if(tryT("HPT", 1, m_loadResistance, m_loadReactance, m_sourceResistance, m_sourceReactance,
				&m_clt,
				&m_cltR,
				&m_cltX,
				&m_lt,
				&m_ltR,
				&m_ltX,
				&m_cst,
				&m_cstR,
				&m_cstX,
				'C', 'L', FALSE)) {
		m_hptValid = TRUE;
		return;
	}

	// Neither one is valid.
	m_hptValid = FALSE;
}

void tuner::recalculateLPT()
{
	// Because of the Q constraint, we have to try this two ways, and see
	// which one works.
	//
	// Try source on the left and load on the right.
	if(tryT("LPT", 0, m_sourceResistance, m_sourceReactance, m_loadResistance, m_loadReactance,
				&m_lst,
				&m_lstR,
				&m_lstX,
				&m_ct,
				&m_ctR,
				&m_ctX,
				&m_llt,
				&m_lltR,
				&m_lltX,
				'L', 'C', TRUE)) {
		m_lptValid = TRUE;
		return;
	}

	// Try load on the left and source on the right.
	if(tryT("LPT", 1, m_loadResistance, m_loadReactance, m_sourceResistance, m_sourceReactance,
				&m_llt,
				&m_lltR,
				&m_lltX,
				&m_ct,
				&m_ctR,
				&m_ctX,
				&m_lst,
				&m_lstR,
				&m_lstX,
				'L', 'C', TRUE)) {
		m_lptValid = TRUE;
		return;
	}

	// Neither one is valid.
	m_lptValid = FALSE;
}

void tuner::recalculatePower()
{
	m_sourceImpedance = complex<double>(m_sourceResistance, m_sourceReactance);
	m_voltageForPower = sqrt(m_power * m_sourceImpedance);
	m_currentForPower = sqrt(m_power / m_sourceImpedance);
}

void tuner::buildCPCS(DISPLAYED_RESULTS *d, SOLUTION *s)
{
	ONE_COMPONENT *c;

	c = &d->component[0];
	c->type = 'C';
	c->label = "CS";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_capacitorQ;
	c->resistance = s->parallelComponentResistance;
	c->reactance = s->parallelComponentReactance;
	c->value = s->parallelComponentValue;

	c = &d->component[1];
	c->type = 'C';
	c->label = "CL";
	c->arrangement = IS_SER;
	c->qualityFactor = m_capacitorQ;
	c->resistance = s->seriesComponentResistance;
	c->reactance = s->seriesComponentReactance;
	c->value = s->seriesComponentValue;
}

void tuner::buildCSCP(DISPLAYED_RESULTS *d, SOLUTION *s)
{
	ONE_COMPONENT *c;

	c = &d->component[0];
	c->type = 'C';
	c->label = "CS";
	c->arrangement = IS_SER;
	c->qualityFactor = m_capacitorQ;
	c->resistance = s->seriesComponentResistance;
	c->reactance = s->seriesComponentReactance;
	c->value = s->seriesComponentValue;

	c = &d->component[1];
	c->type = 'C';
	c->label = "CL";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_capacitorQ;
	c->resistance = s->parallelComponentResistance;
	c->reactance = s->parallelComponentReactance;
	c->value = s->parallelComponentValue;
}

void tuner::buildLPLS(DISPLAYED_RESULTS *d, SOLUTION *s)
{
	ONE_COMPONENT *c;

	c = &d->component[0];
	c->type = 'L';
	c->label = "LS";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_inductorQ;
	c->resistance = s->parallelComponentResistance;
	c->reactance = s->parallelComponentReactance;
	c->value = s->parallelComponentValue;

	c = &d->component[1];
	c->type = 'L';
	c->label = "LL";
	c->arrangement = IS_SER;
	c->qualityFactor = m_inductorQ;
	c->resistance = s->seriesComponentResistance;
	c->reactance = s->seriesComponentReactance;
	c->value = s->seriesComponentValue;
}

void tuner::buildLSLP(DISPLAYED_RESULTS *d, SOLUTION *s)
{
	ONE_COMPONENT *c;

	c = &d->component[0];
	c->type = 'L';
	c->label = "LS";
	c->arrangement = IS_SER;
	c->qualityFactor = m_inductorQ;
	c->resistance = s->seriesComponentResistance;
	c->reactance = s->seriesComponentReactance;
	c->value = s->seriesComponentValue;

	c = &d->component[1];
	c->type = 'L';
	c->label = "LL";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_inductorQ;
	c->resistance = s->parallelComponentResistance;
	c->reactance = s->parallelComponentReactance;
	c->value = s->parallelComponentValue;
}

void tuner::buildLCHP(DISPLAYED_RESULTS *d, SOLUTION *s)
{
	ONE_COMPONENT *c;

	c = &d->component[0];
	c->type = 'L';
	c->label = "L";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_inductorQ;
	c->resistance = s->parallelComponentResistance;
	c->reactance = s->parallelComponentReactance;
	c->value = s->parallelComponentValue;

	c = &d->component[1];
	c->type = 'C';
	c->label = "C";
	c->arrangement = IS_SER;
	c->qualityFactor = m_capacitorQ;
	c->resistance = s->seriesComponentResistance;
	c->reactance = s->seriesComponentReactance;
	c->value = s->seriesComponentValue;
}

void tuner::buildCLLP(DISPLAYED_RESULTS *d, SOLUTION *s)
{
	ONE_COMPONENT *c;

	c = &d->component[0];
	c->type = 'C';
	c->label = "C";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_capacitorQ;
	c->resistance = s->parallelComponentResistance;
	c->reactance = s->parallelComponentReactance;
	c->value = s->parallelComponentValue;

	c = &d->component[1];
	c->type = 'L';
	c->label = "L";
	c->arrangement = IS_SER;
	c->qualityFactor = m_inductorQ;
	c->resistance = s->seriesComponentResistance;
	c->reactance = s->seriesComponentReactance;
	c->value = s->seriesComponentValue;
}

void tuner::buildLCLP(DISPLAYED_RESULTS *d, SOLUTION *s)
{
	ONE_COMPONENT *c;

	c = &d->component[0];
	c->type = 'L';
	c->label = "L";
	c->arrangement = IS_SER;
	c->qualityFactor = m_inductorQ;
	c->resistance = s->seriesComponentResistance;
	c->reactance = s->seriesComponentReactance;
	c->value = s->seriesComponentValue;

	c = &d->component[1];
	c->type = 'C';
	c->label = "C";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_capacitorQ;
	c->resistance = s->parallelComponentResistance;
	c->reactance = s->parallelComponentReactance;
	c->value = s->parallelComponentValue;
}

void tuner::buildCLHP(DISPLAYED_RESULTS *d, SOLUTION *s)
{
	ONE_COMPONENT *c;

	c = &d->component[0];
	c->type = 'C';
	c->label = "C";
	c->arrangement = IS_SER;
	c->qualityFactor = m_capacitorQ;
	c->resistance = s->seriesComponentResistance;
	c->reactance = s->seriesComponentReactance;
	c->value = s->seriesComponentValue;

	c = &d->component[1];
	c->type = 'L';
	c->label = "L";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_inductorQ;
	c->resistance = s->parallelComponentResistance;
	c->reactance = s->parallelComponentReactance;
	c->value = s->parallelComponentValue;
}

void tuner::buildHPPI(DISPLAYED_RESULTS *d)
{
	ONE_COMPONENT *c;

	d->validSolution = m_hppiValid;
	if(!d->validSolution) {
		return;
	}

	c = &d->component[0];
	c->type = 'L';
	c->label = "LS";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_inductorQ;
	c->resistance = m_lspiR;
	c->reactance = m_lspiX;
	c->value = m_lspi;

	c = &d->component[1];
	c->type = 'C';
	c->label = "C";
	c->arrangement = IS_SER;
	c->qualityFactor = m_capacitorQ;
	c->resistance = m_cpiR;
	c->reactance = m_cpiX;
	c->value = m_cpi;

	c = &d->component[2];
	c->type = 'L';
	c->label = "LL";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_inductorQ;
	c->resistance = m_llpiR;
	c->reactance = m_llpiX;
	c->value = m_llpi;
}

void tuner::buildLPPI(DISPLAYED_RESULTS *d)
{
	ONE_COMPONENT *c;

	d->validSolution = m_lppiValid;
	if(!d->validSolution) {
		return;
	}

	c = &d->component[0];
	c->type = 'C';
	c->label = "CS";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_capacitorQ;
	c->resistance = m_cspiR;
	c->reactance = m_cspiX;
	c->value = m_cspi;

	c = &d->component[1];
	c->type = 'L';
	c->label = "L";
	c->arrangement = IS_SER;
	c->qualityFactor = m_inductorQ;
	c->resistance = m_lpiR;
	c->reactance = m_lpiX;
	c->value = m_lpi;

	c = &d->component[2];
	c->type = 'C';
	c->label = "CL";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_capacitorQ;
	c->resistance = m_clpiR;
	c->reactance = m_clpiX;
	c->value = m_clpi;
}

void tuner::buildHPT(DISPLAYED_RESULTS *d)
{
	ONE_COMPONENT *c;

	d->validSolution = m_hptValid;
	if(!d->validSolution) {
		return;
	}

	c = &d->component[0];
	c->type = 'C';
	c->label = "CS";
	c->arrangement = IS_SER;
	c->qualityFactor = m_capacitorQ;
	c->resistance = m_cstR;
	c->reactance = m_cstX;
	c->value = m_cst;

	c = &d->component[1];
	c->type = 'L';
	c->label = "L";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_inductorQ;
	c->resistance = m_ltR;
	c->reactance = m_ltX;
	c->value = m_lt;

	c = &d->component[2];
	c->type = 'C';
	c->label = "CL";
	c->arrangement = IS_SER;
	c->qualityFactor = m_capacitorQ;
	c->resistance = m_cltR;
	c->reactance = m_cltX;
	c->value = m_clt;
}

void tuner::buildLPT(DISPLAYED_RESULTS *d)
{
	ONE_COMPONENT *c;

	d->validSolution = m_lptValid;
	if(!d->validSolution) {
		return;
	}

	c = &d->component[0];
	c->type = 'L';
	c->label = "LS";
	c->arrangement = IS_SER;
	c->qualityFactor = m_inductorQ;
	c->resistance = m_lstR;
	c->reactance = m_lstX;
	c->value = m_lst;

	c = &d->component[1];
	c->type = 'C';
	c->label = "C";
	c->arrangement = IS_PAR;
	c->qualityFactor = m_capacitorQ;
	c->resistance = m_ctR;
	c->reactance = m_ctX;
	c->value = m_ct;

	c = &d->component[2];
	c->type = 'L';
	c->label = "LL";
	c->arrangement = IS_SER;
	c->qualityFactor = m_inductorQ;
	c->resistance = m_lltR;
	c->reactance = m_lltX;
	c->value = m_llt;
}

void tuner::buildResults()
{
	int i;
	int j;
	int k;

	SOLUTION *s;
	DISPLAYED_RESULTS *d;
	ONE_COMPONENT *c;

	// See if we have a valid solution for each type.
	for(i = 0; i < USE_LAST; i++) {
		d = &m_results[i];

		if(i >= USE_CPCS && i <= USE_CLHP) {
			// For the L-network cases, we have to search the solution arrays.
			// There are eight possible L-networks, but no more than four
			// solutions.  Start off by assuming this case is invalid, then
			// search for a valid solution.
			d->validSolution = FALSE;
			for(j = 0; j < 2; j++) {
				for(k = 0; k < 2; k++) {
					s = &m_lnet.s[j][k];
					if(s->type == i) {
						// Set the common parameters.
						d->validSolution = TRUE;
						d->networkQ = s->qualityFactor;
						
						// The third component is not present.
						c = &d->component[2];
						c->type = ' ';
						c->label = "";
						c->arrangement = 0;
						c->qualityFactor = 0.0;
						c->resistance = 0.0;
						c->reactance = 0.0;
						c->value = 0.0;

						// Set the specific parameters.
						switch(i) {
							case USE_CPCS: buildCPCS(d, s); break;
							case USE_CSCP: buildCSCP(d, s); break;
							case USE_LPLS: buildLPLS(d, s); break;
							case USE_LSLP: buildLSLP(d, s); break;
							case USE_LCHP: buildLCHP(d, s); break;
							case USE_CLLP: buildCLLP(d, s); break;
							case USE_LCLP: buildLCLP(d, s); break;
							case USE_CLHP: buildCLHP(d, s); break;
						}
					}
				}
			}
		} else {
			// For the PI and T network cases, we've already broken down
			// the solutions.
			switch(i) {
				case USE_HPPI: buildHPPI(d); break;
				case USE_LPPI: buildLPPI(d); break;
				case USE_HPT: buildHPT(d); break;
				case USE_LPT: buildLPT(d); break;
			}
		}
	}

	// Hide invalid solutions; show valid ones.
	for(i = 0; i < USE_LAST; i++) {
		d = &m_results[i];
		dl_topology->Show(i, d->validSolution);
	}

	// If the current item is hidden, try pick the first valid one that we find.
	if(!dl_topology->IsItemShown(dl_topology->GetSelection())) {
		for(i = 0; i < USE_LAST; i++) {
			d = &m_results[i];
			if(d->validSolution) {
				dl_topology->SetSelection(i);
				m_tunerTopologyStr = dl_topology->GetString(i);
				dl_bitmap->Show();
				break;
			}
		}
		if(i == USE_LAST) {
			// There is no valid topology.  Hide the bitmap to avoid
			// confusion.
			dl_bitmap->Hide();
		}
	} else {
		// The current item is shown, so show the bitmap too.
		dl_bitmap->Show();
	}
}

void tuner::recalculate()
{
	m_frequency = atof(m_tunerFrequencyStr) * 1.0E6;
	m_power = atof(m_tunerPowerStr);
	m_sourceResistance = atof(m_tunerSourceResistanceStr);
	m_sourceReactance = atof(m_tunerSourceReactanceStr);
	m_loadResistance = atof(m_tunerLoadResistanceStr);
	m_loadReactance = atof(m_tunerLoadReactanceStr);
	m_networkQ = atof(m_tunerNetworkQStr);
	m_inductorQ = atof(m_tunerInductorQStr);
	m_capacitorQ = atof(m_tunerCapacitorQStr);

	// We always calculate every topology, so we can identify the
	// valid solutions.
	recalculatePower();
	recalculateLnet(&m_lnet);
	recalculateHPPI();
	recalculateLPPI();
	recalculateHPT();
	recalculateLPT();

	buildResults();

	// Display the requested topology.  The user won't be able
	// to select invalid topologies, but they can change a
	// parameter such that a previously valid topology becomes
	// invalid.  In that case, they can select away from the
	// now invalid topology, but cannot go back to it until a
	// parameter change makes it valid again.
	if(strcmp(m_tunerTopologyStr, "Two Cap (Cpar Cser)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_cc1), USE_CPCS, 2);
	} else if(strcmp(m_tunerTopologyStr, "Two Cap (Cser Cpar)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_cc2), USE_CSCP, 2);
	} else if(strcmp(m_tunerTopologyStr, "Two Coil (Lpar Lser)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_ll1), USE_LPLS, 2);
	} else if(strcmp(m_tunerTopologyStr, "Two Coil (Lser Lpar)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_ll2), USE_LSLP, 2);
	} else if(strcmp(m_tunerTopologyStr, "High Pass (Lpar Cser)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_lchp), USE_LCHP, 2);
	} else if(strcmp(m_tunerTopologyStr, "Low Pass (Cpar Lser)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_cllp), USE_CLLP, 2);
	} else if(strcmp(m_tunerTopologyStr, "Low Pass (Lser Cpar)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_lclp), USE_LCLP, 2);
	} else if(strcmp(m_tunerTopologyStr, "High Pass (Cser Lpar)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_clhp), USE_CLHP, 2);
	} else if(strcmp(m_tunerTopologyStr, "High Pass PI (Lpar Cser Lpar)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_hppi), USE_HPPI, 3);
	} else if(strcmp(m_tunerTopologyStr, "Low Pass PI (Cpar Lser Cpar)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_lppi), USE_LPPI, 3);
	} else if(strcmp(m_tunerTopologyStr, "High Pass T (Cser Lpar Cser)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_hpt), USE_HPT, 3);
	} else if(strcmp(m_tunerTopologyStr, "Low Pass T (Lser Cpar Lser)") == 0) {
		show3Part(wxBITMAP_PNG_FROM_DATA(nt_lpt), USE_LPT, 3);
	}
}

void tuner::show3Part(wxBitmap bmp, int type, int count)
{
	DISPLAYED_RESULTS *d = &m_results[type];
	ONE_COMPONENT *c;
	RESULT_MAP *r;

	int i;

	complex<double> zLoad = complex<double>(m_loadResistance, m_loadReactance);;
	complex<double> yLoad = 1.0 / zLoad;

	complex<double> zComp[MAX_COMPONENTS + 1];
	complex<double> yComp[MAX_COMPONENTS + 1];

	complex<double> zCombined[MAX_COMPONENTS + 1];
	complex<double> yCombined[MAX_COMPONENTS + 1];

	complex<double> voltage[MAX_COMPONENTS + 1];
	complex<double> current[MAX_COMPONENTS + 1];

	double powerRemaining = m_power;
	double loss;

	if(bmp.IsOk()) {
		dl_bitmap->SetBitmap(bmp);
	} else {
		wxLogError("bad png?");
		return;
	}

	// Handle invalid case first.
	if(!d->validSolution) {
		for(i = 0; i < (MAX_COMPONENTS + 1); i++) {
			r = &m_r[i];
			r->box->GetStaticBox()->Hide();
			r->line0->Hide();
			r->line0Tag->Hide();
			r->line1->Hide();
			r->line1Tag->Hide();
			r->line2->Hide();
			r->line2Tag->Hide();
			r->line3->Hide();
			r->line3Tag->Hide();
		}

		r = &m_r[0];
		r->box->GetStaticBox()->Show();
		r->box->GetStaticBox()->SetLabel("Invalid");
		r->line0Tag->Show();
		r->line0Tag->SetLabel("No Match Found");

		Layout();
		return;
	}

	// Set up to display the appropriate fields.
	for(i = 0; i < (MAX_COMPONENTS + 1); i++) {
		r = &m_r[i];
		if(count == 2 && i == 2) {
			// For simple L-networks, hide the third component
			// completely.
			r->box->GetStaticBox()->Hide();
			r->line0->Hide();
			r->line0Tag->Hide();
			r->line1->Hide();
			r->line1Tag->Hide();
			r->line2->Hide();
			r->line2Tag->Hide();
			r->line3->Hide();
			r->line3Tag->Hide();
		} else if(count == 2 && i == 3) {
			// For simple L-networks, we need four slots in the
			// fourth component.
			r->box->GetStaticBox()->Show();
			r->line0->Show();
			r->line0Tag->Show();
			r->line1->Show();
			r->line1Tag->Show();
			r->line2->Show();
			r->line2Tag->Show();
			r->line3->Show();
			r->line3Tag->Show();
		} else if(count == 3 && i == 3) {
			// For PI and T networks, we need three slots in the
			// fourth component.
			r->box->GetStaticBox()->Show();
			r->line0->Show();
			r->line0Tag->Show();
			r->line1->Show();
			r->line1Tag->Show();
			r->line2->Show();
			r->line2Tag->Show();
			r->line3->Hide();
			r->line3Tag->Hide();
		} else {
			// In all other cases, we need all four slots in
			// the component.
			r->box->GetStaticBox()->Show();
			r->line0->Show();
			r->line0Tag->Show();
			r->line1->Show();
			r->line1Tag->Show();
			r->line2->Show();
			r->line2Tag->Show();
			r->line3->Show();
			r->line3Tag->Show();
		}
	}

	// Work backwards so we can solve for impedances/admittances.
	zCombined[count] = zLoad;
	yCombined[count] = yLoad;
	zComp[count]=complex<double>(0.0,0.0);
	yComp[count]=complex<double>(0.0,0.0);
	for(i = (count - 1); i >= 0; i--) {
		c = &d->component[i];
		zComp[i] = complex<double>(c->resistance, c->reactance);
		yComp[i] = 1.0 / zComp[i];

		if(c->arrangement == IS_PAR) {
			yCombined[i] = yComp[i] + yCombined[i + 1];
			zCombined[i] = 1.0 / yCombined[i];
		} else {
			zCombined[i] = zComp[i] + zCombined[i + 1];
			yCombined[i] = 1.0 / zCombined[i];
		}
	}

	// Work forwards so we can solve for voltages/currents.
	voltage[0] = m_voltageForPower;
	current[0] = m_currentForPower;
	for(i = 0; i < count; i++) {
		c = &d->component[i];

		if(c->arrangement == IS_PAR) {
			current[i + 1] = voltage[i] / zCombined[i + 1];
			voltage[i + 1] = current[i + 1] * zCombined[i + 1];
		} else {
			voltage[i + 1] = current[i] * zCombined[i + 1];
			current[i + 1] = voltage[i + 1] / zCombined[i + 1];
		}
	}

	// We can now display the various components.
	for(i = 0; i < count; i++) {
		c = &d->component[i];
		r = &m_r[i];
		r->box->GetStaticBox()->SetLabel(c->label);
		r->line0->ChangeValue(wxString::Format(wxT("%.2f"), c->value));
		if(c->type == 'C') {
			r->line0Tag->SetLabel("Value (pF)");
		} else {
			r->line0Tag->SetLabel("Value (nH)");
		}

		if(c->arrangement == IS_PAR) {
			r->line1->ChangeValue(wxString::Format(wxT("%.2f"), fabs(voltage[i])));
			r->line1Tag->SetLabel("Voltage Across");

			r->line2->ChangeValue(wxString::Format(wxT("%.2f"), fabs(current[i + 1] - current[i])));
			r->line2Tag->SetLabel("Current Through");

			// Use voltage for loss.
			loss = powerFromVoltage(voltage[i], yComp[i]);
			powerRemaining -= loss;
			r->line3->ChangeValue(wxString::Format(wxT("%.2f"), loss));
			r->line3Tag->SetLabel("Loss (Watts)");
		} else {
			r->line1->ChangeValue(wxString::Format(wxT("%.2f"), fabs(voltage[i + 1] - voltage[i])));
			r->line1Tag->SetLabel("Voltage Across");

			r->line2->ChangeValue(wxString::Format(wxT("%.2f"), fabs(current[i])));
			r->line2Tag->SetLabel("Current Through");

			// Use current for loss.
			loss = powerFromCurrent(current[i], zComp[i]);
			powerRemaining -= loss;
			r->line3->ChangeValue(wxString::Format(wxT("%.2f"), powerFromCurrent(current[i], zComp[i])));
			r->line3Tag->SetLabel("Loss (Watts)");
		}
	}

	r = &m_r[3];
	r->box->GetStaticBox()->Show();
	r->box->GetStaticBox()->SetLabel("Notes");

	r->line0->ChangeValue(wxString::Format(wxT("%.2f"), fabs(m_voltageForPower)));
	r->line0Tag->SetLabel("Source Voltage");

	r->line1->ChangeValue(wxString::Format(wxT("%.2f"), fabs(voltage[count])));
	r->line1Tag->SetLabel("Load Voltage");

	r->line2->ChangeValue(wxString::Format(wxT("%.2f"), powerRemaining));
	r->line2Tag->SetLabel("Load Power");

	if(count == 2) {
		r->line3->ChangeValue(wxString::Format(wxT("%.2f"), d->networkQ));
		r->line3Tag->SetLabel("Network Q");
	}

	Layout();
}
