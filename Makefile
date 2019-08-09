# Copyright 2019 Steven A. Falco <stevenfalco@gmail.com>
# 
# This file is part of tline.
# 
#  tline is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
# 
#  tline is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  You should have received a copy of the GNU General Public License
#  along with tline.  If not, see <https://www.gnu.org/licenses/>.

WX_CXX_FLAGS = $(shell wx-config --cxxflags)
WX_CXX_LIBS  = $(shell wx-config --libs)

BUILD_DIR = build
TOPOLOGY_DIR = topologies

SRC :=									\
	tlineMain.cpp							\
	tlineLogic.cpp							\
	tlineUI.cpp							\
	cableTypes.cpp							\
	userLine.cpp							\
	helpAbout.cpp							\
	helpInfo.cpp							\
	tuner.cpp							\
	topologies.cpp							\
	#

TOPOLOGY :=								\
	nt_bp1ll.gif							\
	nt_bp2ll.gif							\
	nt_bp3ll.gif							\
	nt_clhp.gif							\
	nt_bp4ll.gif							\
	nt_hppi.gif							\
	nt_hp2ll.gif							\
	nt_hp1ll.gif							\
	nt_cllp.gif							\
	nt_hpt.gif							\
	nt_lclp.gif							\
	nt_lchp.gif							\
	nt_lp2ll.gif							\
	nt_lp1ll.gif							\
	nt_lpt.gif							\
	nt_lppi.gif							\
	#

OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)
DEP := $(SRC:%.cpp=$(BUILD_DIR)/%.d)
TOP := $(TOPOLOGY:%.gif=$(TOPOLOGY_DIR)/%.gif)
GEN := $(TOP:$(TOPOLOGY_DIR)/%.gif=$(BUILD_DIR)/%.h)

all: $(BUILD_DIR) $(GEN) $(BUILD_DIR)/tline

install: $(BUILD_DIR) $(GEN) $(BUILD_DIR)/tline
	cp $(BUILD_DIR)/tline ~/bin

$(BUILD_DIR)/tline: $(OBJ)
	g++ -g -o $@ $^ $(WX_CXX_LIBS)

$(BUILD_DIR)/%.o: %.cpp
	g++ -MMD -g $(WX_CXX_FLAGS) -o $@ -c $<

$(BUILD_DIR)/%.h: $(TOPOLOGY_DIR)/%.gif
	xxd --include $^ > $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEP)
