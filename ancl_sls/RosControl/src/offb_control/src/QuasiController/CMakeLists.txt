cmake_minimum_required(VERSION 3.10)

AUX_SOURCE_DIRECTORY(./ QUASICONTROL)

add_library(quasicontrol ${QUASICONTROL})

target_include_directories (quasicontrol PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
