project(UI)
cmake_minimum_required(VERSION 2.8)
find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})
set(sources 
	#appMain.cpp 
	MainWindow.cpp
	execute.cpp
	)
set(moc_headers 
	MainWindow.h
	execute.h
	)
set(headers ${moc_headers}) 
#set(moc_sources ${headers})
QT4_WRAP_CPP(mocs ${headers})
add_library(UI SHARED ${sources} ${mocs} ${headers})
target_link_libraries(UI ${QT_LIBRARIES})
set_target_properties(UI PROPERTIES OUTPUT_NAME UI)
