cmake_minimum_required(VERSION 3.28)
project(MazeSolver LANGUAGES CXX)

file(GLOB source_files
	"src/*.cpp"
	"src/algorythm/*.cpp"
	"src/module/*.cpp"
	"include/algorythm/*.h"
	"include/module/*.h"
)

set(SOURCES ${source_files})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main ${SOURCES})

target_compile_features(main PRIVATE cxx_std_17)
target_include_directories(main PRIVATE src include)
target_link_libraries(main PRIVATE SFML::Graphics)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})