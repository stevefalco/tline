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
	#

TOPOLOGY :=								\
	nt_bp1ll.png							\
	nt_bp2ll.png							\
	nt_bp3ll.png							\
	nt_clhp.png							\
	nt_bp4ll.png							\
	nt_hppi.png							\
	nt_hp2ll.png							\
	nt_hp1ll.png							\
	nt_cllp.png							\
	nt_hpt.png							\
	nt_lclp.png							\
	nt_lchp.png							\
	nt_lp2ll.png							\
	nt_lp1ll.png							\
	nt_lpt.png							\
	nt_lppi.png							\
	#

OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)
DEP := $(SRC:%.cpp=$(BUILD_DIR)/%.d)
TOP := $(TOPOLOGY:%.png=$(TOPOLOGY_DIR)/%.png)
GEN := $(TOP:$(TOPOLOGY_DIR)/%.png=$(BUILD_DIR)/%.h)

all: $(BUILD_DIR) $(GEN) $(BUILD_DIR)/tline

install: $(BUILD_DIR) $(GEN) $(BUILD_DIR)/tline
	cp $(BUILD_DIR)/tline ~/bin

$(BUILD_DIR)/tline: $(OBJ)
	g++ -Wall -Werror -g -o $@ $^ $(WX_CXX_LIBS)

$(BUILD_DIR)/%.o: %.cpp
	g++ -Wall -Werror -MMD -g $(WX_CXX_FLAGS) -o $@ -c $<

$(BUILD_DIR)/%.h: $(TOPOLOGY_DIR)/%.png
	xxd --include $^ > $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEP)
