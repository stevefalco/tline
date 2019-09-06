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

typedef struct {
		int		solnType[2][2];
		double		solnQ[2][2];
		char		solnParIs[2][2];
		double		solnPar[2][2];
		double		solnX2[2][2];
		char		solnSerIs[2][2];
		double		solnSer[2][2];
		double		solnX1[2][2];
} LNET_RESULTS;

class tuner : public tunerDialog
{
	public:
		tuner( wxWindow* parent );

		void		Update();

		wxString	m_tunerTopologyStr;

	protected:
		void		onFrequency( wxCommandEvent& event );
		void		onSourceResistance( wxCommandEvent& event );
		void		onSourceReactance( wxCommandEvent& event );
		void		onLoadResistance( wxCommandEvent& event );
		void		onLoadReactance( wxCommandEvent& event );
		void		onQ( wxCommandEvent& event );
		void		onTunerTopologySelected( wxCommandEvent& event );
		void		onTunerOKclicked( wxCommandEvent& event );

	private:
		bool		tryPI(
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
					);

		bool		tryT(
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
					);

		void		recalculateHPPI();
		void		recalculateLPPI();
		void		recalculateHPT();
		void		recalculateLPT();
		void		recalculateLnet(LNET_RESULTS *result);
		void		recalculate();

		void		findLnetComponentValues(LNET_RESULTS *result, double w, double x1, double x2, int item);
		void		lnetAlgorithm(LNET_RESULTS *result);
		void		lnetDisplayValues(
					int type,
					double sourceVar[2][2],
					const char *sourceLabel,
					double loadVar[2][2],
					const char *loadLabel
					);
		bool		lnetSetBitmap(wxBitmap bmp);

		void		CPCS();
		void		CSCP();
		void		LPLS();
		void		LSLP();
		void		LCHP();
		void		CLLP();
		void		LCLP();
		void		CLHP();
		void		HPPI();
		void		LPPI();
		void		HPT();
		void		LPT();

		double		m_sourceResistance;
		double		m_sourceReactance;
		double		m_loadResistance;
		double		m_loadReactance;
		double		m_desiredQ;
		double		m_frequency;

		LNET_RESULTS	m_lnet;

		int		m_useSlot;
		double		m_rA;
		double		m_xA;
		double		m_rB;
		double		m_xB;

		double		m_lspi;
		double		m_llpi;
		double		m_cpi;
		bool		m_hppiValid;

		double		m_cspi;
		double		m_clpi;
		double		m_lpi;
		bool		m_lppiValid;

		double		m_cst;
		double		m_clt;
		double		m_lt;
		bool		m_hptValid;

		double		m_lst;
		double		m_llt;
		double		m_ct;
		bool		m_lptValid;
};

#endif // __tuner__
