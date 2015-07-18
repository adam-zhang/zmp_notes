project(database)
cmake_minimum_required(VERSION 2.8)
set(sources Precondition.cpp)
set(headers Precondition.h)
add_library(database ${sources}
	${headers})
set_target_properties(database PROPERTIES OUTPUT_NAME database)
