cmake_minimum_required(VERSION 3.10)

AUX_SOURCE_DIRECTORY(./ QUASICONTROLTRACK)

add_library(quasicontroltrack ${QUASICONTROLTRACK})

target_include_directories (quasicontroltrack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
