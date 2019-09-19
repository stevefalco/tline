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

#ifndef __tuner__
#define __tuner__

#include <complex>
using namespace std;

#include "tlineUI.h"

// WARNING: These assigments must match the order in the GUI.
#define USE_CPCS		0
#define USE_CSCP		1
#define USE_LPLS		2
#define USE_LSLP		3
#define USE_LCHP		4
#define USE_CLLP		5
#define USE_LCLP		6
#define USE_CLHP		7
#define USE_HPPI		8
#define USE_LPPI		9
#define USE_HPT			10
#define USE_LPT			11
#define USE_LAST		12

#define IS_PAR			1
#define IS_SER			2

#define MAX_COMPONENTS		3

typedef struct {
	char			type;				// 'L', 'C', or ' '
	wxString		label;				// "LS". "CL", etc.
	int			arrangement;			// IS_PAR or IS_SER
	double			qualityFactor;
	double			resistance;
	double			reactance;
	double			value;				// pF for capacitors, nH for inductors
} ONE_COMPONENT;

typedef struct {
	bool			validSolution;
	double			networkQ;			// 0 if N/A
	ONE_COMPONENT		component[MAX_COMPONENTS];	// Ordered from source to load
} DISPLAYED_RESULTS;

// The left index iterates over the order of the source and load.
// The right index iterates over the two solutions of the equations.
typedef struct {
	int			type;				// CPCS through CLHP
	double			qualityFactor;
	char			parallelComponentType;		// 'L' or 'C'
	double			parallelComponentValue;		// pF for capacitors, nH for inductors
	double			parallelComponentResistance;
	double			parallelComponentReactance;
	char			seriesComponentType;		// 'L' or 'C'
	double			seriesComponentValue;		// pF for capacitors, nH for inductor
	double			seriesComponentResistance;
	double			seriesComponentReactance;
} SOLUTION;

typedef struct {
	SOLUTION		s[2][2];
} LNET_RESULTS;

typedef struct {
	wxStaticBoxSizer*	box;

	wxTextCtrl*		line0;
	wxStaticText*		line0Tag;

	wxTextCtrl*		line1;
	wxStaticText*		line1Tag;

	wxTextCtrl*		line2;
	wxStaticText*		line2Tag;

	wxTextCtrl*		line3;
	wxStaticText*		line3Tag;
} RESULT_MAP;

class tuner : public tunerDialog
{
	public:
		tuner( wxWindow* parent );

		void		Update();

		wxString	m_tunerTopologyStr;

	protected:
		void		onTunerFrequency( wxCommandEvent& event );
		void		onTunerPower( wxCommandEvent& event );
		void		onTunerSourceResistance( wxCommandEvent& event );
		void		onTunerSourceReactance( wxCommandEvent& event );
		void		onTunerLoadResistance( wxCommandEvent& event );
		void		onTunerLoadReactance( wxCommandEvent& event );
		void		onTunerNetworkQ( wxCommandEvent& event );
		void		onTunerInductorQ( wxCommandEvent& event );
		void		onTunerCapacitorQ( wxCommandEvent& event );
		void		onTunerTopologySelected( wxCommandEvent& event );
		void		onTunerOKclicked( wxCommandEvent& event );

	private:
		double		powerFromVoltage(complex<double> voltage, complex<double> admittance);
		double		powerFromCurrent(complex<double> current, complex<double> impedance);

		bool		tryPI(
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
					);

		bool		tryT(
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
					);

		void		recalculatePower();
		void		recalculateHPPI();
		void		recalculateLPPI();
		void		recalculateHPT();
		void		recalculateLPT();
		void		recalculateLnet(LNET_RESULTS *result);
		void		recalculate();

		void		findLnetComponentValues(LNET_RESULTS *result, double w, double x1, double x2, int slot);
		void		lnetInit(LNET_RESULTS *result);
		void		lnetAlgorithm(wxString where, LNET_RESULTS *result);

		void		buildCPCS(DISPLAYED_RESULTS *d, SOLUTION *s);
		void		buildCSCP(DISPLAYED_RESULTS *d, SOLUTION *s);
		void		buildLPLS(DISPLAYED_RESULTS *d, SOLUTION *s);
		void		buildLSLP(DISPLAYED_RESULTS *d, SOLUTION *s);
		void		buildLCHP(DISPLAYED_RESULTS *d, SOLUTION *s);
		void		buildCLLP(DISPLAYED_RESULTS *d, SOLUTION *s);
		void		buildLCLP(DISPLAYED_RESULTS *d, SOLUTION *s);
		void		buildCLHP(DISPLAYED_RESULTS *d, SOLUTION *s);
		void		buildHPPI(DISPLAYED_RESULTS *d);
		void		buildLPPI(DISPLAYED_RESULTS *d);
		void		buildHPT(DISPLAYED_RESULTS *d);
		void		buildLPT(DISPLAYED_RESULTS *d);

		void		buildResults();

		void		show3Part(wxBitmap bmp, int type, int count);

		double		m_sourceResistance;
		double		m_sourceReactance;
		double		m_loadResistance;
		double		m_loadReactance;
		double		m_networkQ;
		double		m_inductorQ;
		double		m_capacitorQ;
		double		m_frequency;
		double		m_power;

		complex<double>	m_sourceImpedance;
		complex<double>	m_voltageForPower;
		complex<double>	m_currentForPower;

		LNET_RESULTS	m_lnet;

		int		m_useSlot;
		double		m_rA;
		double		m_xA;
		double		m_rB;
		double		m_xB;

		double		m_lspi;
		double		m_lspiR;
		double		m_lspiX;
		double		m_llpi;
		double		m_llpiR;
		double		m_llpiX;
		double		m_cpi;
		double		m_cpiR;
		double		m_cpiX;
		bool		m_hppiValid;

		double		m_cspi;
		double		m_cspiR;
		double		m_cspiX;
		double		m_clpi;
		double		m_clpiR;
		double		m_clpiX;
		double		m_lpi;
		double		m_lpiR;
		double		m_lpiX;
		bool		m_lppiValid;

		double		m_cst;
		double		m_cstR;
		double		m_cstX;
		double		m_clt;
		double		m_cltR;
		double		m_cltX;
		double		m_lt;
		double		m_ltR;
		double		m_ltX;
		bool		m_hptValid;

		double		m_lst;
		double		m_lstR;
		double		m_lstX;
		double		m_llt;
		double		m_lltR;
		double		m_lltX;
		double		m_ct;
		double		m_ctR;
		double		m_ctX;
		bool		m_lptValid;

		RESULT_MAP	m_r[MAX_COMPONENTS + 1];

		DISPLAYED_RESULTS	m_results[USE_LAST];
};

#endif // __tuner__
