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

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include "wx/log.h"

#include <cstring>
#include <complex>
using namespace std;

#include "cableTypes.h"
#include "constants.h"

typedef struct {
		const char	*name;
		double		impedance;
		double		velocityFactor;
		double		k0;
		double		k1;
		double		k2;
		double		maximumVoltage;
} CABLE_PROPERTIES;

CABLE_PROPERTIES cableProperties[] = {
	{ "Andrew Braided CNT-100"	,	50.0,	0.66,	0.352647,	0.691672,	0.001106,   500.0 },
	{ "Andrew Braided CNT-195"	,	50.0,	0.8,	0.108574,	0.363325,	0.000299,  1500.0 },
	{ "Andrew Braided CNT-240"	,	50.0,	0.83,	0.062452,	0.260761,	0.000000,  1500.0 },
	{ "Andrew Braided CNT-300"	,	50.0,	0.83,	0.039521,	0.201307,	0.000000,  2500.0 },
	{ "Andrew Braided CNT-400"	,	50.0,	0.85,	0.026753,	0.131386,	0.000000,  2500.0 },
	{ "Andrew Braided CNT-600"	,	50.0,	0.87,	0.015027,	0.082774,	0.000059,  4600.0 },
	{ "Andrew Heliax  LDF4-50A"	,	50.0,	0.88,	0.008946,	0.064142,	0.000193,  4000.0 },
	{ "Andrew Heliax  LDF5-50A"	,	50.0,	0.89,	0.005906,	0.034825,	0.000153,  6000.0 },
	{ "Andrew Heliax  LDF6-50"	,	50.0,	0.89,	0.003561,	0.022861,	0.000131,  9000.0 },
	{ "Belden 8215    (RG-6A/U)"	,	75.0,	0.66,	0.375388,	0.246660,	0.002253,  2700.0 },
	{ "Belden 7915A   (RG-6/HDTV)"	,	75.0,	0.83,	0.063697,	0.195292,	0.000071,   350.0 },
	{ "Belden 9116    (RG-6/CATV)"	,	75.0,	0.83,	0.615093,	0.196584,	0.000190,   300.0 },
	{ "Belden 8237    (RG-8/U)"	,	52.0,	0.66,	0.025891,	0.185562,	0.001357,  3700.0 },
	{ "Belden 9251    (RG-8/U)"	,	52.0,	0.66,	0.025891,	0.185562,	0.001357,  3700.0 },
	{ "Belden 9913    (RG-8/U)"	,	50.0,	0.84,	0.402115,	0.129373,	0.000223,   300.0 },
	{ "Belden 9913F7 (RG-8/U)"	,	52.0,	0.85,	0.024220,	0.158114,	0.000000,   300.0 },
	{ "Belden 9914    (RG-8/U)"	,	50.0,	0.82,	0.019978,	0.139420,	0.000000,   300.0 },
	{ "Belden 9258    (RG-8X)"	,	50.0,	0.82,	0.066013,	0.288776,	0.002125,   300.0 },
	{ "Belden 8213    (RG-11/U)"	,	75.0,	0.84,	0.190155,	0.113867,	0.001554,   300.0 },
	{ "Belden 8238    (RG-11/U)"	,	75.0,	0.66,	0.042271,	0.199492,	0.000720,   300.0 },
	{ "Belden 8261    (RG-11A/U)"	,	75.0,	0.66,	0.042271,	0.199492,	0.000720,  3700.0 },
	{ "Belden 9212    (RG-11/U)"	,	76.0,	0.66,	0.041715,	0.198907,	0.000803,  3700.0 },
	{ "Belden 8219    (RG-58A/U)"	,	53.5,	0.73,	0.104718,	0.398776,	0.005265,   300.0 },
	{ "Belden 8240    (RG-58A/U)"	,	51.5,	0.66,	0.118904,	0.321239,	0.004695,  1400.0 },
	{ "Belden 8259    (RG-58A/U)"	,	50.0,	0.66,	0.129420,	0.436326,	0.009218,  1400.0 },
	{ "Belden 8262    (RG-58C/U)"	,	50.0,	0.66,	0.129420,	0.403833,	0.008761,  1400.0 },
	{ "Belden 9201    (RG-58/U)"	,	52.0,	0.66,	0.129453,	0.320710,	0.004718,  1400.0 },
	{ "Belden 8212    (RG-59/U)"	,	75.0,	0.78,	0.603418,	0.280797,	0.002069,   300.0 },
	{ "Belden 8241    (RG-59/U)"	,	75.0,	0.66,	0.594885,	0.319915,	0.001754,  1700.0 },
	{ "Belden 8263    (RG-59B/U)"	,	75.0,	0.66,	0.594885,	0.319915,	0.001754,  1700.0 },
	{ "Belden 9269    (RG-62A/U)"	,	90.0,	0.84,	0.212804,	0.271020,	0.000073,   750.0 },
	{ "Belden 9857    (RG-63/U)"	,	125.0,	0.84,	0.147313,	0.149965,	0.000989,   750.0 },
	{ "Belden 83242  (RG-142B/U)"	,	50.0,	0.7,	0.187615,	0.353181,	0.001996,  1400.0 },
	{ "Belden 7805    (RG-174/U)"	,	50.0,	0.66,	0.356990,	0.690569,	0.001356,  1100.0 },
	{ "Belden 8216    (RG-174/U)"	,	50.0,	0.66,	2.156088,	0.777862,	0.008695,  1100.0 },
	{ "Belden 83265  (RG-178B/U)"	,	50.0,	0.695,	3.098352,	1.448062,	0.000000,   750.0 },
	{ "Belden 83269  (RG-188A/U)"	,	50.0,	0.695,	0.865983,	0.856815,	0.001408,   900.0 },
	{ "Belden 8267    (RG-213/U)"	,	50.0,	0.66,	0.256179,	0.154587,	0.003135,  3700.0 },
	{ "Belden 8268    (RG-214/U)"	,	50.0,	0.66,	0.020846,	0.163915,	0.002752,  3700.0 },
	{ "Belden 84303   (RG-303/U)"	,	50.0,	0.7,	0.178929,	0.338634,	0.003147,  1400.0 },
	{ "Belden 84316   (RG-316/U)"	,	50.0,	0.695,	1.189647,	0.800401,	0.003536,   900.0 },
	{ "CommScope 2427K   (RG-8)"	,	50.0,	0.84,	0.020151,	0.136083,	0.001562,  3000.0 },
	{ "CommScope 3227     (RG-8)"	,	50.0,	0.84,	0.020151,	0.123024,	0.000460,  3000.0 },
	{ "Davis RF Bury-Flex"		,	50.0,	0.82,	0.025189,	0.154616,	0.000000,     0.0 },
	{ "DX Engineering RG-8"		,	50.0,	0.81,	0.027409,	0.183432,	0.000000,   600.0 },
	{ "DX Engineering RG-8X"	,	50.0,	0.82,	0.066128,	0.266440,	0.002503,   300.0 },
	{ "DX Engineering RG-11"	,	75.0,	0.82,	0.183078,	0.129148,	0.001243,   600.0 },
	{ "DX Engineering RG-58A"	,	50.0,	0.66,	0.360694,	0.444896,	0.000000,  1400.0 },
	{ "DX Engineering RG-213"	,	50.0,	0.66,	0.112383,	0.172695,	0.001803,  3700.0 },
	{ "DX Engineering RG-214"	,	50.0,	0.66,	0.052153,	0.177443,	0.001034,  5000.0 },
	{ "DX Engineering RG-400"	,	50.0,	0.695,	0.156144,	0.402633,	0.001282,  1900.0 },
	{ "DX Engineering DXE-400MAX"	,	50.0,	0.84,	0.025623,	0.143396,	0.000580,  3700.0 },
	{ "DX Engineering 300-Ohm LL"	,	272.0,	0.88,	0.060914,	0.130916,	0.000000,  8000.0 },
	{ "DX Eng 300-Ohm LL (wet)"	,	272.0,	0.88,	0.026664,	0.329810,	0.000000,  8000.0 },
	{ "Pasternack RG-142"		,	50.0,	0.692,	0.185183,	0.381876,	0.000966,  1900.0 },
	{ "Pasternack RG-218"		,	50.0,	0.66,	0.005298,	0.073183,	0.002686, 11000.0 },
	{ "Radioware RG-6"		,	75.0,	0.82,	0.063697,	0.196827,	0.000257,     0.0 },
	{ "Radioware RG-8X"		,	50.0,	0.78,	0.466609,	0.316133,	0.003738,     0.0 },
	{ "Radioware RG-11"		,	75.0,	0.78,	0.178674,	0.130375,	0.001802,     0.0 },
	{ "Radioware RG-58"		,	50.0,	0.66,	0.129420,	0.403626,	0.008667,     0.0 },
	{ "Radioware RG-174"		,	50.0,	0.66,	2.108132,	0.868020,	0.002986,     0.0 },
	{ "Radioware RG-213"		,	50.0,	0.66,	0.025189,	0.199693,	0.002006,     0.0 },
	{ "Radioware RF-9913"		,	50.0,	0.84,	0.186127,	0.123263,	0.000541,     0.0 },
	{ "Radioware RF-9914F"		,	50.0,	0.83,	0.298145,	0.140867,	0.000557,     0.0 },
	{ "Tandy Cable RG-8X"		,	50.0,	0.78,	0.069487,	0.316119,	0.002984,     0.0 },
	{ "Tandy Cable RG-58"		,	50.0,	0.66,	0.138974,	0.378678,	0.003754,     0.0 },
	{ "Tandy Cable RG-59"		,	75.0,	0.66,	0.191090,	0.300255,	0.000076,     0.0 },
	{ "Times  LMR-100A"		,	50.0,	0.66,	0.786073,	0.709385,	0.001766,   500.0 },
	{ "Times  LMR-195"		,	50.0,	0.76,	0.108574,	0.358541,	0.000424,  1000.0 },
	{ "Times  LMR-200"		,	50.0,	0.83,	0.089117,	0.326439,	0.000172,  1000.0 },
	{ "Times  LMR-240"		,	50.0,	0.84,	0.061583,	0.239481,	0.000447,  1500.0 },
	{ "Times  LMR-240-UF"		,	50.0,	0.84,	0.070964,	0.293214,	0.000307,  1500.0 },
	{ "Times  LMR-240-75"		,	75.0,	0.84,	0.081010,	0.232188,	0.000260,  1500.0 },
	{ "Times  LMR-300"		,	50.0,	0.85,	0.037610,	0.196637,	0.000181,  2000.0 },
	{ "Times  LMR-400"		,	50.0,	0.85,	0.026405,	0.124805,	0.000187,  2500.0 },
	{ "Times  LMR-400-UF"		,	50.0,	0.85,	0.023626,	0.147204,	0.000315,  2500.0 },
	{ "Times  LMR-400-75"		,	75.0,	0.85,	0.024031,	0.112936,	0.000374,  2000.0 },
	{ "Times  LMR-500"		,	50.0,	0.86,	0.018154,	0.094339,	0.000332,  3000.0 },
	{ "Times  LMR-600"		,	50.0,	0.87,	0.015027,	0.072828,	0.000353,  4000.0 },
	{ "Times  LMR-600-UF"		,	50.0,	0.87,	0.014158,	0.093622,	0.000237,  4000.0 },
	{ "Times  LMR-600-75"		,	75.0,	0.87,	0.014998,	0.070230,	0.000260,  4000.0 },
	{ "Times  LMR-900"		,	50.0,	0.87,	0.009468,	0.055074,	0.000065,  5000.0 },
	{ "Times  LMR-1200"		,	50.0,	0.88,	0.005993,	0.038836,	0.000143,  6000.0 },
	{ "Times  LMR-1700"		,	50.0,	0.89,	0.004169,	0.022220,	0.000275,  9000.0 },
	{ "Wireman CQ102     (RG-8)"	,	50.0,	0.84,	0.023452,	0.131438,	0.000000,  4000.0 },
	{ "Wireman CQ106     (RG-8)"	,	50.0,	0.82,	0.025623,	0.164155,	0.000000,  4000.0 },
	{ "Wireman CQ1000   (RG-8)"	,	50.0,	0.85,	0.025189,	0.131439,	0.000000,  4000.0 },
	{ "Wireman CQ116     (RG-8X)"	,	50.0,	0.78,	0.066013,	0.242334,	0.003309,   300.0 },
	{ "Wireman CQ117     (RG-8X)"	,	50.0,	0.72,	0.066013,	0.327886,	0.001195,  1500.0 },
	{ "Wireman CQ118     (RG-8X)"	,	50.0,	0.8,	0.063407,	0.239480,	0.001934,   300.0 },
	{ "Wireman CQ124     (RG-58)"	,	50.0,	0.66,	0.255365,	0.482485,	0.000295,  1400.0 },
	{ "Wireman CQ129FF (RG-58)"	,	52.0,	0.78,	0.126112,	0.473162,	0.000000,     0.0 },
	{ "Wireman CQ113     (RG-213)"	,	50.0,	0.66,	1.104626,	0.120013,	0.001291,     0.0 },
	{ "Wireman CQ142A   (RG-217)"	,	50.0,	0.66,	0.024494,	0.152518,	0.000171,  7000.0 },
	{ "UTP Category 3"		,	100.0,	0.61,	0.247548,	0.683349,	0.083457,     0.0 },
	{ "UTP Category 5E"		,	100.0,	0.61,	0.247548,	0.612538,	0.006121,     0.0 },
	{ "UTP Category 6"		,	100.0,	0.61,	0.247548,	0.591814,	0.000360,     0.0 },
	{ "STP-A 150 ohm"		,	150.0,	0.61,	0.101335,	0.326196,	0.006211,  1200.0 },
	{ "Wireman 551 Ladder Line"	,	400.0,	0.902,	0.249956,	0.044559,	0.001200,     0.0 },
	{ "Wireman 552 Ladder Line"	,	380.0,	0.918,	0.355771,	0.041126,	0.001000,     0.0 },
	{ "Wireman 553 Ladder Line"	,	395.0,	0.902,	0.077708,	0.078862,	0.000900,     0.0 },
	{ "Wireman 554 Ladder Line"	,	360.0,	0.93,	0.149143,	0.043640,	0.001700,     0.0 },
	{ "Wireman 551 LL (ice/snow)"	,	390.0,	0.864,	0.256365,	0.045702,	0.086984,     0.0 },
	{ "Wireman 552 LL (ice/snow)"	,	365.0,	0.883,	0.370392,	0.042816,	0.077033,     0.0 },
	{ "Wireman 553 LL (ice/snow)"	,	380.0,	0.869,	0.080775,	0.081975,	0.069739,     0.0 },
	{ "Wireman 554 LL (ice/snow)"	,	350.0,	0.887,	0.153404,	0.044887,	0.092957,     0.0 },
	{ "Generic 300 ohm Tubular"	,	300.0,	0.8,	0.021715,	0.092240,	0.001089,     0.0 },
	{ "Generic 450 ohm Window"	,	450.0,	0.91,	0.009651,	0.022439,	0.000459,     0.0 },
	{ "Generic 600 ohm Open"	,	600.0,	0.92,	0.003619,	0.019219,	0.000090, 12000.0 },
	{ "Ideal (lossless) 50 ohm"	,	50.0,	0.66,	0.000000,	0.000000,	0.000000,     0.0 },
	{ "Ideal (lossless) 75 ohm"	,	75.0,	0.66,	0.000000,	0.000000,	0.000000,     0.0 },
	// "User-Defined Transmission Line" is intentionally undefined here, which will cause us to throw an
	// error in our constructor.
	{ 0, 0, 0, 0, 0, 0, 0 } // End-marker
};

cableTypes::cableTypes(
		const char		*name,
		double			frequency
		)
{
	CABLE_PROPERTIES		*cp;

	for(cp = cableProperties; cp->name != 0; cp++) {
		if(strcmp(name, cp->name) == 0) {
			m_voltageLimit = cp->maximumVoltage;

			// Compute attenuation, impedance, gamma, etc from the k factors.
			m_Rdc = 2.0 * (cp->k0 / 100.0 / NEPERS_TO_DB) * cp->impedance;
			m_Rhf = 2.0 * (cp->k1 / 100.0 / NEPERS_TO_DB * sqrt(frequency / 1E6)) * cp->impedance;
			m_Lhf = cp->impedance / (SPEED_OF_LIGHT_F * cp->velocityFactor);
			m_Ghf = 2.0 * (cp->k2 / 100.0 / NEPERS_TO_DB * (frequency / 1E6)) / cp->impedance;
			m_Chf = 1.0 / (cp->impedance * SPEED_OF_LIGHT_F * cp->velocityFactor);
			m_w = (2.0 * PI) * frequency;
			m_Zinternal = sqrt(pow(complex<double>(m_Rdc, 0), 2.0) + pow(complex<double>(m_Rhf, m_Rhf), 2.0));
			m_RjwL = m_Zinternal + complex<double>(0, m_w * m_Lhf);
			m_GjwC = complex<double>(m_Ghf, m_w * m_Chf);
			m_Zo = sqrt(m_RjwL / m_GjwC);
			m_gamma = sqrt(m_RjwL * m_GjwC);

			return;
		}
	}

	throw CABLE_TYPE_NO_MATCH;
}

// Return attenuation per hundred feet.
double
cableTypes::findAtten(
		)
{
	return real(m_gamma) * NEPERS_TO_DB * 100.0;
}

// Return corrected velocity factor.
double
cableTypes::findVF(
		)
{
	return m_w / (SPEED_OF_LIGHT_F * imag(m_gamma));
}

// Return real part of impedance.
double
cableTypes::findZoReal(
		)
{
	return real(m_Zo);
}

// Return imaginary part of impedance.
double
cableTypes::findZoImag(
		)
{
	return imag(m_Zo);
}

// Return voltage limit of cable.
double
cableTypes::findVoltageLimit(
		)
{
	return m_voltageLimit;
}
