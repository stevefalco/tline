// Copyright Steven A. Falco <stevenfalco@gmail.com>
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

#ifndef __tlineLogic__
#define __tlineLogic__

#include <complex>

using namespace std;

#include "cableTypes.h"
#include "tlineUI.h"

class tlineLogic : public tlineUI
{
	public:
		tlineLogic( wxWindow* parent, wxString fileName );

		wxString getWidth() { return m_widthStr; }
		wxString getHeight() { return m_heightStr; }

		// Public, so we can call it from a drag/dropped file.
		void loadFile( wxString path );

	private:
		void onFileLoad( wxCommandEvent& event );
		void onFileSave( wxCommandEvent& event );
		void onFileExit( wxCommandEvent& event );

		void onHelpInfo( wxCommandEvent& event );
		void onHelpAbout( wxCommandEvent& event );

		void onCableTypeSelected( wxCommandEvent& event );
		void onUnitsSelected( wxCommandEvent& event );
		void onFrequencySelected( wxCommandEvent& event );
		void onLengthSelected( wxCommandEvent& event );
		void onResistanceSelected( wxCommandEvent& event );
		void onReactanceSelected( wxCommandEvent& event );
		void onLoadInputSelected( wxCommandEvent& event );
		void onPowerSelected( wxCommandEvent& event );

		void onPlotZclicked( wxCommandEvent& event );
		void onPlotVIclicked( wxCommandEvent& event );
		void onTunerClicked( wxCommandEvent& event );
		void onSavePlotZclicked( wxCommandEvent& event );
		void onSavePlotVIclicked( wxCommandEvent& event );
		void onSaveDataClicked( wxCommandEvent& event );

		double wavelength();

		complex<double> impedanceAtLoad( double distance );
		complex<double> impedanceAtInput( double distance );
		complex<double> voltageOut( double distance );
		complex<double> currentOut( double distance );

		void recalculate();
		void doPlot( int type, int mode );
		void setControlZ( wxFFile* file, wxString name );
		void setControlVI( wxFFile* file, wxString name );
		void saveData();

		bool setOutput( wxFFile* file );

		void generateGraphableData( wxFFile* file );

		inline double sq( double v ) {
			return v * v;
		}

		int			m_saved;
		int			m_width;
		int			m_height;

		bool			m_newUserLine;
		bool			m_tunerInit;
		bool			m_userLineInit;
		bool			m_userSpecifiedZ;

		// The cable type strings here must match the first member
		// of the cableProperties table.
		wxString		m_cableTypeStr = _("Andrew Braided CNT-100");
		wxString		m_cableTypePrevStr = _("Andrew Braided CNT-100");
		wxString		m_loadInputStr = _("Load");
		wxString		m_unitsStr = _("Feet");
		wxString		m_widthStr = _("800");
		wxString		m_heightStr = _("700");

		double			m_attenDBPerUnitLength;
		double			m_attenNepersPerUnitLength;
		double			m_attenPer100Feet;
		double			m_attenPer100Meters;
		double			m_attenPer100Units;
		double			m_cableReactivePart;
		double			m_cableResistivePart;
		double			m_extraSWRloss;
		double			m_frequency;
		double			m_lambda;
		double			m_length;
		double			m_maximumVoltage;
		double			m_phase;
		double			m_power;
		double			m_reactance;
		double			m_resistance;
		double			m_returnLossAtLoad;
		double			m_returnLossAtSource;
		double			m_rhoMagnitudeAtLoad;
		double			m_rhoMagnitudeAtSource;
		double			m_swrAtLoad;
		double			m_swrAtSource;
		double			m_totalLoss;
		double			m_totalMatchedLineLoss;
		double			m_units;
		double			m_velocityFactor;
		double			m_voltageForPower;
		double			m_wavelength;

		wxString		m_tunerCapacitorQStr;
		wxString		m_tunerFrequencyStr;
		wxString		m_tunerInductorQStr;
		wxString		m_tunerLoadReactanceStr;
		wxString		m_tunerLoadResistanceStr;
		wxString		m_tunerNetworkQStr;
		wxString		m_tunerPowerStr;
		wxString		m_tunerSourceReactanceStr;
		wxString		m_tunerSourceResistanceStr;
		wxString		m_tunerTopologyStr;

		wxString		m_userLineAttenuationStr = _("0.0");
		wxString		m_userLineCableImpedanceStr = _("0.0");
		wxString		m_userLineCableReactanceStr = _("0.0");
		wxString		m_userLineCableResistanceStr = _("0.0");
		wxString		m_userLineCableVoltageLimitStr = _("0.0");
		wxString		m_userLineVelocityFactorStr = _("0.0");
		wxString		m_userLineLastMethodStr = _("1");

		complex<double>		m_lossCoef;
		complex<double>		m_rhoLoad;
		complex<double>		m_rhoSource;
		complex<double>		m_zCable;
		complex<double>		m_zInput;
		complex<double>		m_zLoad;

};

#endif // __tlineLogic__
