cmake_minimum_required(VERSION 3.10)

AUX_SOURCE_DIRECTORY(./ LINEARCONTROL)

add_library(linearcontrol ${LINEARCONTROL})

target_include_directories (linearcontrol PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
