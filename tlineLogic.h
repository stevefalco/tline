#ifndef __tlineLogic__
#define __tlineLogic__

#include <complex>

using namespace std;

#include "cableTypes.h"
#include "tlineUI.h"

class tlineLogic : public tlineUI
{
	public:
		tlineLogic( wxWindow* parent );

	private:
		void onCableTypeSelected( wxCommandEvent& event );
		void onFileLoad( wxCommandEvent& event );
		void onFileSave( wxCommandEvent& event );
		void onFileExit( wxCommandEvent& event );
		void onUnitsSelected( wxCommandEvent& event );
		void onFrequencySelected( wxCommandEvent& event );
		void onLengthSelected( wxCommandEvent& event );
		void onResistanceSelected( wxCommandEvent& event );
		void onReactanceSelected( wxCommandEvent& event );
		void onLoadInputSelected( wxCommandEvent& event );
		void onShowPlotsClicked( wxCommandEvent& event );
		void onSavePlotsClicked( wxCommandEvent& event );
		void onSaveDataClicked( wxCommandEvent& event );
		void onTunerClicked( wxCommandEvent& event );
		void onPowerSelected( wxCommandEvent& event );

		double wavelength();

		complex<double> impedanceAtLoad(double distance);
		complex<double> impedanceAtInput(double distance);
		complex<double> voltageOut(double distance);
		complex<double> currentOut(double distance);

		void recalculate();
		void showPlots();
		void savePlots();
		void saveData();

		void generateGraphableData( FILE* fp );

		inline double sq( double v ) {
			return v * v;
		}

		cableTypes		*m_c;
		CABLE_PROPERTIES	*m_cp;

		int			m_saved;

		wxString		m_cableTypeStr = _("RG-6 (Belden 8215)");
		wxString		m_frequencyStr = _("7.0");
		wxString		m_lengthStr = _("100");
		wxString		m_loadInputStr = _("Load");
		wxString		m_powerStr = _("1500");
		wxString		m_reactanceStr = _("0");
		wxString		m_resistanceStr = _("50");
		wxString		m_unitsStr = _("Feet");

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
		double			m_voltageForPower;
		double			m_wavelength;

		complex<double>		m_lossCoef;
		complex<double>		m_rho;
		complex<double>		m_zCable;
		complex<double>		m_zInput;
		complex<double>		m_zLoad;

};

#endif // __tlineLogic__
