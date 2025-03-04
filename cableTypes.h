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

#ifndef __cableTypes__
#define __cableTypes__

#define CABLE_TYPE_NO_MATCH	1

class cableTypes
{
	public:
		cableTypes(
				const char		*name,
				double			frequency
				);

		double findAtten();
		double findVF();
		double findZoReal();
		double findZoImag();
		double findVoltageLimit();

	private:
		double			m_voltageLimit;
		double			m_Rdc;
		double			m_Rhf;
		double			m_Lhf;
		double			m_Ghf;
		double			m_Chf;
		double			m_w;
		complex<double>		m_Zinternal;
		complex<double>		m_RjwL;
		complex<double>		m_GjwC;
		complex<double>		m_Zo;
		complex<double>		m_gamma;
};

#endif // __cableTypes__
