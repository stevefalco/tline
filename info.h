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

#ifndef __INFO_H__
#define __INFO_H__

const char* INFO_PAGE =
	"<html><body>\n"
	"<h1>tline - A Transmission Line Calculator for Ham Radio</h1>\n"
	"<p>\n"
	"<b><i>tline</i></b> is intended to calculate various transmission line parameters.\n"
	"For example, given a type of cable and a known load impedance, <b><i>tline</i></b> can calculate\n"
	"the impedance at the input of the cable.  Similarly, one can specify the input\n"
	"impedance and find the impedance at the far end of the cable.\n"
	"<p>\n"
	"<b><i>tline</i></b> makes use of gnuplot for visualizing its calculations.  Graphs of impedance,\n"
	"voltage, and current along the line can be generated on-screen, and can be saved\n"
	"to files in png, jpeg, and gif formats.  The raw data used to make the graphs can\n"
	"also be saved as a text file for post-processing.\n"
	"<p>\n"
	"<b><i>tline</i></b> uses the wxWidgets library, so while it is being developed on Linux, it can\n"
	"be ported to other operating systems.  If you want to help make that happen, please\n"
	"fork the project and create pull requests on github.  The project page is \n"
	"<a href=\"http://github.com/stevefalco/tline\">here</a>.\n"
	"</body></html>\n";

#endif // __INFO_H__
