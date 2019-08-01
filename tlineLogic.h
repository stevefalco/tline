#ifndef __tlineLogic__
#define __tlineLogic__

#include <complex>

using namespace std;

#include "cableTypes.h"

/**
@file
Subclass of tline, which is generated by wxFormBuilder.
*/

#include "tlineUI.h"

//// end generated include

/** Implementing tline */
class tlineLogic : public tlineUI
{
	public:
		/** Constructor */
		tlineLogic( wxWindow* parent );
	//// end generated class members

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

		double wavelength();
		std::complex<double> impedanceAtLoad();
		std::complex<double> impedanceAtInput();


		void recalculate();

		inline double sq(
				double v
				)
		{
			return v * v;
		}

		cableTypes		*m_c;
		CABLE_PROPERTIES	*m_cp;

		int			m_saved;

		wxString		m_cableTypeStr = _("RG-6 (Belden 8215)");
		wxString		m_unitsStr = _("Feet");
		wxString		m_frequencyStr = _("7.0");
		wxString		m_lengthStr = _("100");
		wxString		m_resistanceStr = _("50");
		wxString		m_reactanceStr = _("0");
		wxString		m_loadInputStr = _("Load");

		double			m_units;
		double			m_attenPer100Feet;
		double			m_attenPer100Meters;
		double			m_attenPer100Units;
		double			m_attenNepersPerUnitLength;
		double			m_attenDBPerUnitLength;
		double			m_frequency;
		double			m_length;
		double			m_phase;
		double			m_cableResistivePart;
		double			m_cableReactivePart;
		double			m_wavelength;
		double			m_lambda;
		double			m_resistance;
		double			m_reactance;
		double			m_rhoMagnitudeAtLoad;
		double			m_rhoMagnitudeAtSource;
		double			m_returnLossAtLoad;
		double			m_returnLossAtSource;
		double			m_swrAtLoad;
		double			m_swrAtSource;
		double			m_totalMatchedLineLoss;
		double			m_totalLoss;
		double			m_extraSWRloss;

		std::complex<double>	m_lossCoef;
		std::complex<double>	m_zCable;
		std::complex<double>	m_zLoad;
		std::complex<double>	m_zInput;
		std::complex<double>	m_rho;
};

#endif // __tlineLogic__
