cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
enable_testing()

include_directories(
	"src"
	"lib/cype/src"
)

project(cpm_test)

add_subdirectory("test")
