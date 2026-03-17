cmake_minimum_required(VERSION 3.20)
project(Ollin)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#add_subdirectory(extern/pybind11)

#add_library(pre_src_dummy OBJECT pre_src/lexer.cpp)

#target_link_libraries(pre_src_dummy PRIVATE pybind11::module)
#set_target_properties(pre_src_dummy PROPERTIES
#    EXCLUDE_FROM_ALL TRUE
#)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE PRE_SOURCES CONFIGURE_DEPENDS "pre_src/*.cpp")

add_executable(Ollin ${SOURCES} ${PRE_SOURCES})

target_include_directories(Ollin PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_source_files_properties(${PRE_SOURCES} PROPERTIES HEADER_FILE_ONLY TRUE)
#pybind11_add_module(lexer ${SOURCES})