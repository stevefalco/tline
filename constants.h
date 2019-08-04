// Copyright 2019 Steven A. Falco <stevenfalco@gmail.com>
//
// This file is part of t;ome.
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

#ifndef __constants__
#define __constants__

#define SPEED_OF_LIGHT_F	983571056.4304	// ft/sec
#define SPEED_OF_LIGHT_M	299792458.0000	// m/sec
#define DB_TO_NEPERS		0.11512925464970228420
#define NEPERS_TO_DB		8.68588963806503655309
#define PI			3.14159265358979323846
#define RADIANS_TO_DEGREES	(180.0 / PI)
#define F_TO_M			0.3048
#define M_TO_F			3.28084
#define POINTS_ON_X		10000	// points on X axis

#define DO_IMPEDANCE		0
#define DO_VOLT_AMP		1

#define PLOT			0
#define SAVE			1

// WARNING: These assigments must match the order in the GUI.
#define USE_FEET		0
#define USE_METERS		1

// WARNING: These assigments must match the order in the GUI.
#define USE_LOAD		0
#define USE_INPUT		1

#endif // __constants__
