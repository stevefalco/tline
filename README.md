# tline
Transmission Line Calculator for Ham Radio

tline - A Transmission Line Calculator for Ham Radio
====================================================

**_tline_** is intended to calculate various transmission line parameters. For example, given a type of cable and a known load impedance, **_tline_** can calculate the impedance at the input of the cable. Similarly, one can specify the input impedance and find the impedance at the far end of the cable.

**_tline_** makes use of gnuplot for visualizing its calculations. Graphs of impedance, voltage, and current along the line can be generated on-screen, and can be saved to files in png, jpeg, and gif formats. The raw data used to make the graphs can also be saved as a text file for post-processing.

**_tline_** uses the wxWidgets library, so while it is being developed on Linux, it can be ported to other operating systems. If you want to help make that happen, please fork the project and create pull requests on github. The project page is [here](http://github.com/stevefalco/tline).
