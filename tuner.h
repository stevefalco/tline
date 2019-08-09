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

class tuner : public tunerDialog
{
	public:
		tuner( wxWindow* parent );

		void		SetFrequency( double frequency );

		double		GetSourceResistance();
		void		SetSourceResistance( double v );

		double		GetSourceReactance();
		void		SetSourceReactance( double v );

		double		GetLoadResistance();
		void		SetLoadResistance( double v );

		double		GetLoadReactance();
		void		SetLoadReactance( double v );

		double		GetQ();
		void		SetQ( double v );

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

		wxString	m_topology = "High Pass (Lpar Cser)";

		double		m_sourceResistance;
		double		m_sourceReactance;
		double		m_loadResistance;
		double		m_loadReactance;
		double		m_desiredQ;
		double		m_frequency;
};

#endif // __tuner__
