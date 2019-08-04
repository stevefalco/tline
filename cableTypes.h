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

#ifndef __cableTypes__
#define __cableTypes__

typedef struct {
	double frequency;
	double attenuation;
} ATTENUATION;

typedef struct {
		const char	*name;
		ATTENUATION	*attenuation;
		double		velocityFactor;
		double		impedance;
		double		maximumVoltage;
} CABLE_PROPERTIES;

class cableTypes
{
	public:
		cableTypes( void );

		CABLE_PROPERTIES * findCable(
				const char		*name
				);

		double findAtten(
				CABLE_PROPERTIES	*cp,
				double			frequency
				);
};

#endif // __cableTypes__
