cmake_minimum_required (VERSION 3.14)
project (tline)

find_package(wxWidgets REQUIRED COMPONENTS net core base webview xrc html qa adv xml)

include(${wxWidgets_USE_FILE})
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I.")

set(TOPOLOGIES
	nt_bp1ll.png
	nt_bp2ll.png
	nt_bp3ll.png
	nt_bp4ll.png
	nt_clhp.png
	nt_cllp.png
	nt_hp1ll.png
	nt_hp2ll.png
	nt_hppi.png
	nt_hpt.png
	nt_lchp.png
	nt_lclp.png
	nt_lp1ll.png
	nt_lp2ll.png
	nt_lppi.png
	nt_lpt.png
	)

foreach(VAR IN LISTS TOPOLOGIES)
	string(REGEX REPLACE ".png$" ".h" H ${VAR})
	set(HEADER ${CMAKE_CURRENT_BINARY_DIR}/${H})
	add_custom_target(${H}
		COMMAND xxd --include ${VAR} ${HEADER}
		WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/topologies
		)
endforeach()

add_executable(${PROJECT_NAME}
	cableTypes.cpp
	helpAbout.cpp
	helpInfo.cpp
	strchrnul.cpp
	tlineIcon.cpp
	tlineLogic.cpp
	tlineMain.cpp
	tlineUI.cpp
	tuner.cpp
	userLine.cpp
	tline.rc
	)

target_link_libraries(
	${PROJECT_NAME}
	${wxWidgets_LIBRARIES}
	)

foreach(VAR IN LISTS TOPOLOGIES)
	string(REGEX REPLACE ".png$" ".h" H ${VAR})
	add_dependencies(tline ${H})
endforeach()

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/tline DESTINATION /usr/bin)
