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

#include "tlineUI.h"

// WARNING: These assigments must match the order in the GUI.
#define USE_LCHP		0
#define USE_CLLP		1
#define USE_LCLP		2
#define USE_CLHP		3
#define USE_HPPI		4
#define USE_LPPI		5
#define USE_HPT			6
#define USE_LPT			7
#define USE_HP1LL		8
#define USE_HP2LL		9
#define USE_LP1LL		10
#define USE_LP2LL		11
#define USE_BP1LL		12
#define USE_BP2LL		13
#define USE_BP3LL		14
#define USE_BP4LL		15

class tuner : public tunerDialog
{
	public:
		tuner( wxWindow* parent );

		void		SetFrequency( double v );

		wxString	GetTopology();
		void		SetTopology( wxString v );

		void		Update();

	protected:
		void		onSourceResistance( wxCommandEvent& event );
		void		onSourceReactance( wxCommandEvent& event );
		void		onLoadResistance( wxCommandEvent& event );
		void		onLoadReactance( wxCommandEvent& event );
		void		onQ( wxCommandEvent& event );
		void		onTunerTopologySelected( wxCommandEvent& event );
		void		onTunerOKclicked( wxCommandEvent& event );

	private:
		void		recalculate();

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

		wxString	m_topologyStr = "High Pass (Lpar Cser)";

		double		m_sourceResistance;
		double		m_sourceReactance;
		double		m_loadResistance;
		double		m_loadReactance;
		double		m_desiredQ;
		double		m_frequency;
};

#endif // __tuner__
