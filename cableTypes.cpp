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

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include <cstring>

#include "cableTypes.h"
#include "constants.h"

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_8215[] = {
	{     1E6, 0.4 },
	{    10E6, 0.8 },
	{    50E6, 1.9 },
	{   100E6, 2.7 },
	{   200E6, 4.1 },
	{   400E6, 5.9 },
	{   700E6, 8.1 },
	{   900E6, 9.4 },
	{  1000E6, 9.8 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION TMS_LMR400[] = {
	{    30E6,  0.7 },
	{    50E6,  0.9 },
	{   150E6,  1.5 },
	{   220E6,  1.9 },
	{   450E6,  2.7 },
	{   900E6,  3.9 },
	{  1500E6,  5.1 },
	{  1800E6,  5.7 },
	{  2000E6,  6.0 },
	{  2500E6,  6.8 },
	{  5800E6, 10.8 },
	{  8000E6, 13.0 },
	{ 99999E6,  0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_9913[] = {
	{     5E6, 0.4 },
	{    10E6, 0.5 },
	{    50E6, 1.0 },
	{   100E6, 1.4 },
	{   200E6, 1.8 },
	{   400E6, 2.6 },
	{   700E6, 3.6 },
	{   900E6, 4.1 },
	{  1000E6, 4.4 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION DXE_8U[] = {
	{     5E6, 0.3 },
	{    10E6, 0.6 },
	{    30E6, 1.0 },
	{    50E6, 1.3 },
	{   150E6, 2.2 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION WIREMAN_CQ106[] = {
	{    30E6, 1.1 },
	{   150E6, 1.8 },
	{   450E6, 3.0 },
	{  1000E6, 4.8 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_8237[] = {
	{     1E6, 0.2 },
	{    10E6, 0.6 },
	{    50E6, 1.3 },
	{   100E6, 1.9 },
	{   200E6, 2.8 },
	{   400E6, 4.2 },
	{   700E6, 5.9 },
	{   900E6, 6.9 },
	{  1000E6, 7.4 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_9258[] = {
	{     1E6,  0.3 },
	{    10E6,  0.9 },
	{    50E6,  2.1 },
	{   100E6,  3.1 },
	{   200E6,  4.5 },
	{   400E6,  6.6 },
	{   700E6,  9.1 },
	{   900E6, 10.7 },
	{  1000E6, 11.2 },
	{ 99999E6,  0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION DXE_8X[] = {
	{     5E6, 0.6 },
	{    10E6, 0.9 },
	{    30E6, 1.4 },
	{    50E6, 2.0 },
	{   150E6, 3.8 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION TMS_LMR240[] = {
	{    30E6,  1.3 },
	{    50E6,  1.7 },
	{   150E6,  3.0 },
	{   220E6,  3.7 },
	{   450E6,  5.3 },
	{   900E6,  7.6 },
	{  1500E6,  9.9 },
	{  1800E6, 10.9 },
	{  2000E6, 11.5 },
	{  2500E6, 12.9 },
	{  5800E6, 20.4 },
	{  8000E6, 24.3 },
	{ 99999E6,  0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_8213[] = {
	{     1E6, 0.2 },
	{     5E6, 0.9 },
	{   100E6, 1.3 },
	{   200E6, 1.9 },
	{   400E6, 2.9 },
	{   700E6, 4.1 },
	{   900E6, 4.8 },
	{  1000E6, 5.2 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION DXE_11U[] = {
	{     1E6, 0.2 },
	{     5E6, 0.3 },
	{    10E6, 0.4 },
	{    30E6, 0.7 },
	{    50E6, 1.0 },
	{   150E6, 1.8 },
	{   450E6, 3.3 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_8261[] = {
	{     1E6, 0.2 },
	{    10E6, 0.7 },
	{    50E6, 1.3 },
	{   100E6, 2.0 },
	{   200E6, 2.9 },
	{   400E6, 4.2 },
	{   700E6, 5.8 },
	{   900E6, 6.8 },
	{  1000E6, 7.1 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION TMS_LMR200[] = {
	{    30E6,  1.8 },
	{    50E6,  2.3 },
	{   150E6,  4.0 },
	{   220E6,  4.8 },
	{   450E6,  7.0 },
	{   900E6,  9.9 },
	{  1500E6, 12.9 },
	{  1800E6, 14.2 },
	{  2000E6, 15.0 },
	{  2500E6, 16.9 },
	{  5800E6, 26.4 },
	{  8000E6, 31.3 },
	{ 99999E6,  0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_8219[] = {
	{     1E6,  0.4 },
	{    10E6,  1.3 },
	{    50E6,  3.1 },
	{   100E6,  4.5 },
	{   200E6,  6.6 },
	{   400E6, 10.0 },
	{   700E6, 14.2 },
	{   900E6, 16.6 },
	{  1000E6, 18.1 },
	{ 99999E6,  0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_8259[] = {
	{     1E6,  0.4 },
	{    10E6,  1.5 },
	{    50E6,  3.7 },
	{   100E6,  5.4 },
	{   200E6,  8.1 },
	{   400E6, 12.4 },
	{   700E6, 17.7 },
	{   900E6, 21.1 },
	{  1000E6, 22.8 },
	{ 99999E6,  0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION DXE_58AU[] = {
	{     1E6, 0.5 },
	{     5E6, 1.5 },
	{    30E6, 2.8 },
	{    50E6, 3.0 },
	{   150E6, 4.0 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_8212[] = {
	{     1E6,  0.6 },
	{    10E6,  1.0 },
	{    50E6,  2.1 },
	{   100E6,  3.0 },
	{   200E6,  4.5 },
	{   400E6,  6.6 },
	{   700E6,  8.9 },
	{   900E6, 10.1 },
	{  1000E6, 10.9 },
	{ 99999E6,  0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_8263[] = {
	{     1E6,  0.6 },
	{    10E6,  1.1 },
	{    50E6,  2.4 },
	{   100E6,  3.4 },
	{   200E6,  4.9 },
	{   400E6,  7.0 },
	{   700E6,  9.7 },
	{   900E6, 11.1 },
	{  1000E6, 12.0 },
	{ 99999E6,  0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_9269[] = {
	{     1E6, 0.3 },
	{    10E6, 0.9 },
	{    50E6, 1.9 },
	{   100E6, 2.7 },
	{   200E6, 3.8 },
	{   400E6, 5.3 },
	{   700E6, 7.3 },
	{   900E6, 8.2 },
	{  1000E6, 8.7 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION PASTER_142[] = {
	{   100E6,  3.9 },
	{  1000E6, 13.0 },
	{  3000E6, 23.8 },
	{  5000E6, 36.0 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_8216[] = {
	{     1E6,  1.9 },
	{    10E6,  3.3 },
	{    50E6,  5.8 },
	{   100E6,  8.4 },
	{   200E6, 12.5 },
	{   400E6, 19.0 },
	{   700E6, 27.0 },
	{   900E6, 31.0 },
	{  1000E6, 34.0 },
	{ 99999E6,  0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION BELDEN_8267[] = {
	{     1E6,  0.27 },
	{    10E6,  0.55 },
	{    50E6,  1.3  },
	{   100E6,  1.9  },
	{   200E6,  2.7  },
	{   400E6,  4.1  },
	{   700E6,  6.5  },
	{   900E6,  7.6  },
	{  1000E6,  8.0  },
	{  4000E6, 21.5  },
	{ 99999E6,  0.0  }
};

// Attenuation in dB per hundred feet.
ATTENUATION DXE_213U[] = {
	{     5E6, 0.4 },
	{    10E6, 0.6 },
	{    30E6, 1.0 },
	{    50E6, 1.3 },
	{   150E6, 2.4 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION PASTER_218[] = {
	{    50E6, 0.65 },
	{   100E6, 1.0  },
	{   400E6, 2.75 },
	{  1000E6, 5.0  },
	{ 99999E6, 0.0  }
};

// Attenuation in dB per hundred feet.
ATTENUATION DXE_RG400[] = {
	{     1E6, 0.4 },
	{     5E6, 1.9 },
	{    30E6, 2.2 },
	{    50E6, 2.9 },
	{   150E6, 5.1 },
	{   450E6, 9.1 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION DXE_400MAX[] = {
	{     5E6, 0.3 },
	{    10E6, 0.5 },
	{    30E6, 0.8 },
	{    50E6, 1.1 },
	{   150E6, 1.8 },
	{   450E6, 3.3 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION TMS_LMR500[] = {
	{    30E6,  0.5 },
	{    50E6,  0.7 },
	{   150E6,  1.2 },
	{   220E6,  1.5 },
	{   450E6,  2.2 },
	{   900E6,  3.1 },
	{  1500E6,  4.1 },
	{  1800E6,  4.6 },
	{  2000E6,  4.8 },
	{  2500E6,  5.5 },
	{  5800E6,  8.9 },
	{  8000E6, 10.7 },
	{ 99999E6,  0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION TMS_LMR600[] = {
	{    30E6, 0.4 },
	{    50E6, 0.5 },
	{   150E6, 1.0 },
	{   220E6, 1.2 },
	{   450E6, 1.7 },
	{   900E6, 2.5 },
	{  1500E6, 3.3 },
	{  1800E6, 3.7 },
	{  2000E6, 3.9 },
	{  2500E6, 4.4 },
	{  5800E6, 7.3 },
	{  8000E6, 8.0 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION TMS_LMR1200[] = {
	{    30E6, 0.2 },
	{    50E6, 0.3 },
	{   150E6, 0.5 },
	{   220E6, 0.6 },
	{   450E6, 0.9 },
	{   900E6, 1.3 },
	{  1500E6, 1.7 },
	{  1800E6, 1.9 },
	{  2000E6, 2.0 },
	{  2500E6, 2.3 },
	{ 99999E6, 0.0 }
};

// Attenuation in dB per hundred feet.
ATTENUATION HEL_LDF4_50A[] = {
	{     1E6,  0.064 },
	{    10E6,  0.205 },
	{    50E6,  0.463 },
	{   100E6,  0.661 },
	{   200E6,  0.946 },
	{   450E6,  1.45  },
	{   700E6,  1.83  },
	{   960E6,  2.17  },
	{  1500E6,  2.77  },
	{  1800E6,  3.07  },
	{  2000E6,  3.25  },
	{  3000E6,  4.09  },
	{  5000E6,  5.49  },
	{  6000E6,  6.11  },
	{  8000E6,  7.26  },
	{  8800E6,  7.69  },
	{ 99999E6,  0.0   }
};

// Attenuation in dB per hundred feet.
ATTENUATION HEL_LDF5_50A[] = {
	{     1E6,  0.115 },
	{    10E6,  0.366 },
	{    50E6,  0.833 },
	{   100E6,  1.193 },
	{   200E6,  1.716 },
	{   450E6,  2.65  },
	{   700E6,  3.375 },
	{   960E6,  4.022 },
	{  1500E6,  5.178 },
	{  1800E6,  5.751 },
	{  2000E6,  6.114 },
	{  3000E6,  7.764 },
	{  5000E6, 10.59  },
	{ 99999E6,  0.0   }
};

// Attenuation in dB per hundred feet.
ATTENUATION HEL_LDF6_50A[] = {
	{     1E6,  0.075 },
	{    10E6,  0.241 },
	{    50E6,  0.551 },
	{   100E6,  0.792 },
	{   200E6,  1.146 },
	{   450E6,  1.784 },
	{   700E6,  2.285 },
	{   960E6,  2.737 },
	{  1500E6,  3.551 },
	{  1800E6,  3.958 },
	{  2000E6,  4.216 },
	{  3000E6,  5.402 },
	{ 99999E6,  0.0   }
};

// Attenuation in dB per hundred feet.
ATTENUATION DXE_LL300[] = {
	{     1E6,  0.240 },
	{    10E6,  0.485 },
	{    30E6,  0.668 },
	{    50E6,  0.890 },
	{ 99999E6,  0.0   }
};

// Attenuation in dB per hundred feet.
ATTENUATION WIREMAN_551[] = {
	{     1E6,  0.05 },
	{     5E6,  0.10 },
	{    10E6,  0.15 },
	{    50E6,  0.33 },
	{ 99999E6,  0.0  }
};

// Attenuation in dB per hundred feet.
ATTENUATION WIREMAN_554[] = {
	{     1E6,  0.06 },
	{     5E6,  0.13 },
	{    10E6,  0.18 },
	{    50E6,  0.41 },
	{ 99999E6,  0.0  }
};

// Attenuation in dB per hundred feet, from the ARRL chart.
ATTENUATION W7FG_TLL[] = {
	{    28E6,  0.10 },
	{    60E6,  0.16 },
	{   100E6,  0.21 },
	{   140E6,  0.25 },
	{ 99999E6,  0.0  }
};

CABLE_PROPERTIES cableProperties[] = {
	{ "RG-6 (Belden 8215)",				BELDEN_8215,	0.66,    75.0,   2700.0 },
	{ "RG-8 (TMS LMR400)",				TMS_LMR400,	0.84,    50.0,    600.0 },
	{ "RG-8 (Belden 9913/9086)",			BELDEN_9913,	0.84,    50.0,    600.0 },
	{ "RG-8 (DX Engineering)",			DXE_8U,		0.81,    50.0,    600.0 },
	{ "RG-8 (Wireman CQ106)",			WIREMAN_CQ106,	0.82,    50.0,    600.0 },
	{ "RG-8A (Belden 8237)",			BELDEN_8237,	0.66,    50.0,   3700.0 },
	{ "RG-8X (Belden 9258)",			BELDEN_9258,	0.82,    50.0,    300.0 },
	{ "RG-8X (DX Engineering)",			DXE_8X,		0.82,    50.0,    300.0 },
	{ "RG-8X (TMS LMR240)",				TMS_LMR240,	0.83,    50.0,   1500.0 },
	{ "RG-11 Foam (Belden 8213)",			BELDEN_8213,	0.84,    75.0,    300.0 },
	{ "RG-11 (DX Engineering)",			DXE_11U,	0.82,    75.0,    600.0 },
	{ "RG-11A (Belden 8261)",			BELDEN_8261,	0.66,    75.0,   3700.0 },
	{ "RG-58 (TMS LMR200)",				TMS_LMR200,	0.83,    50.0,   1000.0 },
	{ "RG-58A Foam (Belden 8219)",			BELDEN_8219,	0.73,    53.5,    300.0 },
	{ "RG-58A (Belden 8259)",			BELDEN_8259,	0.66,    50.0,   1400.0 },
	{ "RG-58A (DX Engineering)",			DXE_58AU,	0.66,    50.0,   1400.0 },
	{ "RG-59 Foam (Belden 8212)",			BELDEN_8212,	0.78,    75.0,    300.0 },
	{ "RG-59B (Belden 8263)",			BELDEN_8263,	0.66,    75.0,   1700.0 },
	{ "RG-62A (Belden 9269)",			BELDEN_9269,	0.84,    93.0,    300.0 },
	{ "RG-142/303 High-Temp. Teflon",		PASTER_142,	0.692,   50.0,   1900.0 },
	{ "RG-174 (Belden 8216)",			BELDEN_8216,	0.66,    50.0,   1100.0 },
	{ "RG-213 (Belden 8267)",			BELDEN_8267,	0.66,    50.0,   3700.0 },
	{ "RG-213 (DX Engineering)",			DXE_213U,	0.66,    50.0,   3700.0 },
	{ "RG-218A (ex RG-17)",				PASTER_218,	0.66,    50.0,  11000.0 },
	{ "RG-400 (DX Engineering)",			DXE_RG400,	0.695,   50.0,   1900.0 },
	{ "DX Engineering DXE-400MAX",			DXE_400MAX,	0.84,    50.0,   3700.0 },
	{ "1/2-inch, LMR500",				TMS_LMR500,	0.82,    50.0,   3000.0 },
	{ "0.59-inch, LMR600",				TMS_LMR600,	0.85,    50.0,   4000.0 },
	{ "1.2-inch, LMR1200",				TMS_LMR1200,	0.88,    50.0,   6000.0 },
	{ "1/2-inch LDF4-50A Andrew Heliax",		HEL_LDF4_50A,	0.88,    50.0,   4000.0 },
	{ "7/8-inch LDF5-50A Andrew Heliax",		HEL_LDF5_50A,	0.89,    50.0,   6000.0 },
	{ "1-1/4 Inch LDF6-50A Andrew Heliax",		HEL_LDF6_50A,	0.89,    50.0,   9000.0 },
	{ "300-Ohm DXE #18 Ladder Line",		DXE_LL300,	0.88,   272.0,   8000.0 },
	{ "450-Ohm Window Line, Wireman #551",		WIREMAN_551,	0.902,  405.0,  10000.0 },
	{ "450-Ohm Window Line, Wireman #554",		WIREMAN_554,	0.928,  359.0,  10000.0 },
	{ "600-Ohm Open-Wire Ladder Line, #12 Wire",	W7FG_TLL,	0.98,   600.0,  12000.0 },
	// This one is intentionally undefined here, which will cause us to return 0
	// from findCable(), which will open a dialog.
	// { "User-Defined Transmission Line",		W7FG_TLL,	0.98,   600.0,  12000.0 },
	{ 0, 0, 0, 0, 0 }
};

cableTypes::cableTypes( void )
{
}

// Look up the cable properties.
CABLE_PROPERTIES *
cableTypes::findCable(
		const char		*name
		)
{
	CABLE_PROPERTIES		*cp;

	for(cp = cableProperties; cp->name != 0; cp++) {
		if(strcmp(name, cp->name) == 0) {
			return cp;
		}
	}

	return 0;
}

// Return attenuation per hundred feet.
double
cableTypes::findAtten(
		CABLE_PROPERTIES	*cp,
		double			frequency
		)
{
	ATTENUATION			*attenuation;
	double				attenLow  = 0.0;
	double				attenHigh = 0.0;
	double				freqLow   = 0.0;
	double				freqHigh  = 0.0;

	for(attenuation = cp->attenuation; cp->attenuation->frequency != 99999E6; attenuation++) {
		if(frequency >= attenuation->frequency) {
			freqLow  = attenuation->frequency;
			attenLow = attenuation->attenuation;
		}
		if(frequency < attenuation->frequency) {
			freqHigh  = attenuation->frequency;
			attenHigh = attenuation->attenuation;
			if(freqLow == 0.0) {
				// Special case - frequency is below the attenuation chart, so just use
				// the lower bound.
				return attenHigh;
			}

			// Attenuation is pretty close to a straight line if plotted log-log, so convert
			// all values to their logs, then perform a linear interpolation, then convert back.
			return pow(10.0, (((log10(frequency) - log10(freqLow)) / (log10(freqHigh) - log10(freqLow))) * (log10(attenHigh) - log10(attenLow))) + log10(attenLow));
		}
	}

	return -1.0;
}
