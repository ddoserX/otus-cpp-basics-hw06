cmake_minimum_required(VERSION 3.25)

project(hw06 VERSION 1.0 LANGUAGES CXX)

set(SRC_MAIN
    main.cpp
    containers.hpp
    array.hpp
    list.hpp
)

add_executable(hw06 
    ${SRC_MAIN}
)

target_compile_features(hw06 PUBLIC 
    cxx_std_20
)

target_compile_options(hw06 PUBLIC
    -Wall
    -Wextra
    -Werror
    -pedantic
)