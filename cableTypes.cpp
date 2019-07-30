#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include <cstring>

#include "constants.h"
#include "cableTypes.h"

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
ATTENUATION DXE_213U[] = {
	{     5E6, 0.4 },
	{    10E6, 0.6 },
	{    30E6, 1.0 },
	{    50E6, 1.3 },
	{   150E6, 2.4 },
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
ATTENUATION DXE_8X[] = {
	{     5E6, 0.6 },
	{    10E6, 0.9 },
	{    30E6, 1.4 },
	{    50E6, 2.0 },
	{   150E6, 3.8 },
	{ 99999E6, 0.0 }
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
	{    30E6, 0.7 },
	{    50E6, 0.9 },
	{   150E6, 1.5 },
	{   220E6, 1.9 },
	{   450E6, 2.7 },
	{   900E6, 3.9 },
	{  1500E6, 5.1 },
	{ 99999E6, 0.0 }
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

CABLE_PROPERTIES cableProperties[] = {
	{ "RG-6 (Belden 8215)",			BELDEN_8215,	0.66,  75.0 },
	{ "RG-8 (TMS LMR400)",			TMS_LMR400,	0.84,  50.0 },
	{ "RG-8 (Belden 9913/9086)",		BELDEN_9913,	0.84,  50.0 },
	{ "RG-8 (DX Engineering)",		DXE_8U,		0.81,  50.0 },
	{ "RG-8A (Belden 8237)",		BELDEN_8237,	0.66,  50.0 },
	{ "RG-8X (DX Engineering)",		DXE_8X,		0.82,  50.0 },
	{ "RG-11 (DX Engineering)",		DXE_11U,	0.82,  75.0 },
	{ "RG-58A (DX Engineering)",		DXE_58AU,	0.66,  50.0 },
	{ "RG-174 (Belden 8216)",		BELDEN_8216,	0.66,  50.0 },
	{ "RG-213 (DX Engineering)",		DXE_213U,	0.66,  50.0 },
	{ "RG-400 (DX Engineering)",		DXE_58AU,	0.695, 50.0 },
	{ "DX Engineering DXE-400MAX",		DXE_400MAX,	0.84,  50.0 },
	{ 0, 0, 0 }
};

#if 0
RG-6 (Belden 8215)		- ok
RG-8 (TMS LMR400)		- ok
RG-8 (Belden 9913/9086)		- ok
RG-8 (DX Engineering)		- ok
RG-8 (Wireman CQ106)
RG-8A (Belden 8237)		- ok
RG-8X (Belden 9258)
RG-8X (DX Engineering)		- ok
RG-8X (TMS LMR240)
RG-11 Foam (Belden 8213)
RG-11 (DX Engineering)		- ok
RG-11A (Belden 8261)
RG-58 (TMS LMR200)
RG-58A Foam (Belden 8219)
RG-58A (Belden 8259)
RG-58A (DX Engineering)		- ok
RG-59 Foam (Belden 8212)
RG-59B (Belden 8263)
RG-62A (Belden 9269)
RG-142/303 High-Temp. Teflon
RG-174 (Belden 8216)		- ok
RG-213 (Belden 8267)
RG-213 (DX Engineering)		- ok
RG-218A (ex RG-17)
RG-400 (DX Engineering)		- ok
DX Engineering DXE-400MAX	- ok
1/2-inch, LMR500
0.59-inch, LMR600
1.2-inch, LMR1200
1/2-inch 50-Ohm Hardline
1/2-inch 75-Ohm Hardline
7/8-inch 50-Ohm Hardline
7/8-inch 75-Ohm Hardline
1/2-inch LDF4-50A Andrew Heliax
7/8-inch LDF5-50A Andrew Heliax
1-1/4 Inch LDF6-50A Andrew Heliax
300-Ohm Tubular Transmitting Line, #20 Wire
450-Ohm Window Line, Wireman #551
450-Ohm Window Line, Wireman #554
600-Ohm Open-Wire Ladder Line, #12 Wire
User-Defined Transmission Line
#endif

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

// Return attenuation per unit length, in nepers.
double
cableTypes::findAtten(
		int			units,
		CABLE_PROPERTIES	*cp,
		double			frequency
		)
{
	ATTENUATION			*attenuation;
	double				attenLow  = 0.0;
	double				attenHigh = 0.0;
	double				freqLow   = 0.0;
	double				freqHigh  = 0.0;
	double				result;

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
				result = attenHigh;
				if(units == USE_FEET) {
					return DB_TO_NEPERS * result / 100.0;
				} else if(units == USE_METERS) {
					return M_TO_F * DB_TO_NEPERS * result / 100.0;
				} else {
					return -1.0;
				}
			}

			// Linear interpolation of attenuation.
			result = (((frequency - freqLow) / (freqHigh - freqLow)) * (attenHigh - attenLow)) + attenLow;
			if(units == USE_FEET) {
				return DB_TO_NEPERS * result / 100.0;
			} else if(units == USE_METERS) {
				return M_TO_F * DB_TO_NEPERS * result / 100.0;
			} else {
				return -1.0;
			}
		}
	}

	return -1.0;
}
