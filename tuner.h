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
#define USE_HP1LL		12
#define USE_HP2LL		13
#define USE_LP1LL		14
#define USE_LP2LL		15
#define USE_BP1LL		16
#define USE_BP2LL		17
#define USE_BP3LL		18
#define USE_BP4LL		19

class tuner : public tunerDialog
{
	public:
		tuner( wxWindow* parent );

		void		Update();

		wxString	m_tunerTopologyStr = "High Pass (Lpar Cser)";

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
		void		recalculate();

		void		walkleyShow(double w, double x1, double x2, int item);
		void		walkley();
		void		walkleyPrep1();
		void		walkleyPrep2();
		void		walkleyDisplay(
					int type,
					double sourceVar[2][2],
					const char *sourceLabel,
					double loadVar[2][2],
					const char *loadLabel
					);
		bool		walkleySetup(wxBitmap bmp);

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
		void		HP1LL();
		void		HP2LL();
		void		LP1LL();
		void		LP2LL();
		void		BP1LL();
		void		BP2LL();
		void		BP3LL();
		void		BP4LL();

		double		m_sourceResistance;
		double		m_sourceReactance;
		double		m_loadResistance;
		double		m_loadReactance;
		double		m_desiredQ;
		double		m_frequency;

		int		m_walkleySolnType[2][2];
		double		m_walkleySolnQ[2][2];
		char		m_walkleySolnParIs[2][2];
		double		m_walkleySolnPar[2][2];
		char		m_walkleySolnSerIs[2][2];
		double		m_walkleySolnSer[2][2];

		int		m_useSlot;
		double		m_rA;
		double		m_xA;
		double		m_rB;
		double		m_xB;
};

#endif // __tuner__
