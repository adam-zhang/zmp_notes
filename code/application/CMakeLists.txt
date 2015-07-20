project(notes)
cmake_minimum_required(VERSION 2.8)
message(${PROJECT_SOURCE_DIR}/libUI)
include_directories(${PROJECT_SOURCE_DIR}/libUI)
set(sources appMain.cpp)
add_executable(notes ${sources} 
	${headers})
target_link_libraries(notes libUI ${QT_LIBRARIES})

