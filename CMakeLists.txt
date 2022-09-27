cmake_minimum_required(VERSION 3.20)

project(DataStructure VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_subdirectory(./src)
List(APPEND LIBS data_structure_libs)

add_subdirectory(./test)
List(APPEND TEST test)

add_executable(res main.c)

target_link_libraries(res PRIVATE
                    ${TEST}
                    )