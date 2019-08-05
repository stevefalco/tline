WX_CXX_FLAGS = $(shell wx-config --cxxflags)
WX_CXX_LIBS  = $(shell wx-config --libs)

SRC :=									\
	tlineMain.cpp							\
	tlineLogic.cpp							\
	tlineUI.cpp							\
	cableTypes.cpp							\
	userLine.cpp							\
	#

OBJ := $(SRC:%.cpp=build/%.o)
DEP := $(SRC:%.cpp=build/%.d)

all: build $(OBJ) ftline

ftline: $(OBJ)
	g++ -g -o $@ $^ $(WX_CXX_LIBS)

build/%.o: %.cpp
	g++ -MMD -g $(WX_CXX_FLAGS) -o $@ -c $<

build:
	mkdir -p build

-include $(DEP)
