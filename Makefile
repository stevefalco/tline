WX_CXX_FLAGS = $(shell wx-config --cxxflags)
WX_CXX_LIBS  = $(shell wx-config --libs)

BUILD_DIR = build

SRC :=									\
	tlineMain.cpp							\
	tlineLogic.cpp							\
	tlineUI.cpp							\
	cableTypes.cpp							\
	userLine.cpp							\
	helpAbout.cpp							\
	helpInfo.cpp							\
	#

OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)
DEP := $(SRC:%.cpp=$(BUILD_DIR)/%.d)

all: $(BUILD_DIR) $(BUILD_DIR)/tline

install: $(BUILD_DIR) $(BUILD_DIR)/tline
	cp $(BUILD_DIR)/tline ~/bin

$(BUILD_DIR)/tline: $(OBJ)
	g++ -g -o $@ $^ $(WX_CXX_LIBS)

$(BUILD_DIR)/%.o: %.cpp
	g++ -MMD -g $(WX_CXX_FLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEP)
