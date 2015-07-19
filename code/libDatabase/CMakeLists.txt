project(database)
cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS "-std=c++11")
find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})
set(QT_DONT_USE_QTGUI TRUE)
set(QT_USE_QTSQL TRUE)
set(sources Database.cpp
	BaseObject.cpp
	User.cpp
	Content.cpp
	)
set(headers Database.h
	BaseObject.h
	User.h
	Content.h
	)
add_library(database SHARED ${sources}
	${headers})
target_link_libraries(database ${QT_LIBRARIES})
set_target_properties(database PROPERTIES OUTPUT_NAME Database)
