WX_CXX_FLAGS = $(shell wx-config --cxxflags)
WX_CXX_LIBS  = $(shell wx-config --libs)

tline: tlineApp.cpp tlineLogic.cpp tline.cpp
	g++ $(WX_CXX_FLAGS) -o $@ $^ $(WX_CXX_LIBS)
