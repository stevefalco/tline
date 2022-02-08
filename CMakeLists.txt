cmake_minimum_required (VERSION 3.10)
project (tline)

find_package(wxWidgets REQUIRED COMPONENTS net core base webview xrc html qa adv xml)

include(${wxWidgets_USE_FILE})
 
set( EXTRA_CXX_FLAGS "")

option( TLINE_DEBUG
	"Build for debugging (default OFF)"
	OFF )

if ( TLINE_DEBUG )
	set( EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -g")
else()
	set( EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -O2")
endif()

option( TLINE_STRIP
	"Strip build (default ON)"
	ON )

if ( NOT TLINE_DEBUG AND TLINE_STRIP )
	set( EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -s")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I. -Wall ${EXTRA_CXX_FLAGS}")

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
	nt_cc1.png
	nt_cc2.png
	nt_ll1.png
	nt_ll2.png
	)

foreach(VAR IN LISTS TOPOLOGIES)
	string(REGEX REPLACE ".png$" ".h" H ${VAR})
	set(HEADER ${CMAKE_CURRENT_BINARY_DIR}/${H})
	add_custom_target(${H}
		COMMAND xxd --include ${VAR} ${HEADER}
		WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/topologies
		)
endforeach()

add_custom_target(GEN_RESOURCES
	COMMAND make
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources
)

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

add_dependencies(${PROJECT_NAME} GEN_RESOURCES)

target_link_libraries(
	${PROJECT_NAME}
	${wxWidgets_LIBRARIES}
	)

foreach(VAR IN LISTS TOPOLOGIES)
	string(REGEX REPLACE ".png$" ".h" H ${VAR})
	add_dependencies(tline ${H})
endforeach()

if( NOT DEFAULT_PREFIX_PATH )
	set( DEFAULT_PREFIX_PATH "/usr/local"
		CACHE
		PATH
		"Location of tline." )
endif()

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/tline DESTINATION ${DEFAULT_PREFIX_PATH}/bin)

if( UNIX AND NOT APPLE )
	# Set paths
	set( UNIX_MIME_DIR generated-resources/linux/mime )
	set( UNIX_MIME_FILES ${UNIX_MIME_DIR}/mime )
	set( UNIX_ICON_FILES ${UNIX_MIME_DIR}/icons )
	set( UNIX_APPLICATIONS_FILES ${UNIX_MIME_DIR}/applications )
	set( UNIX_APPDATA_FILES generated-resources/linux/appdata )

	# Install Mime directory
	install( DIRECTORY ${UNIX_ICON_FILES}
		DESTINATION ${DEFAULT_PREFIX_PATH}/share
		COMPONENT resources
		)

	# Install Icons
	install( DIRECTORY ${UNIX_MIME_FILES}
		DESTINATION ${DEFAULT_PREFIX_PATH}/share
		COMPONENT resources
		)

	# Install Applications directory (.desktop files)
	install( DIRECTORY ${UNIX_APPLICATIONS_FILES}
		DESTINATION ${DEFAULT_PREFIX_PATH}/share
		COMPONENT resources
		)

	# Install AppStream directory (app store entry)
	install( DIRECTORY ${UNIX_APPDATA_FILES}
		DESTINATION ${DEFAULT_PREFIX_PATH}/share
		COMPONENT resources
		)
endif()
