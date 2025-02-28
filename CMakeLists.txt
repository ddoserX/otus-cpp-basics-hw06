cmake_minimum_required(VERSION 3.25)

project(hw06-hw07 VERSION 1.0 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        6910c9d   # release-1.16.0
)

FetchContent_MakeAvailable(googletest)

set(SRC_MAIN
    source/main.cpp
    source/containers.hpp
    source/array.hpp
    source/list.hpp
)

set(TEST_FILES
    tests/test_array.hpp
    tests/test_list.hpp
    tests/test_main.cpp
)

add_executable(hw06 ${SRC_MAIN})
add_executable(hw07_test ${TEST_FILES})

target_include_directories(hw07_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source")

target_link_libraries(hw07_test PRIVATE gtest)

target_compile_features(hw06 PUBLIC cxx_std_20)
target_compile_options(hw06 PUBLIC
    -Wall
    -Wextra
    -Werror
    -pedantic
)

target_compile_features(hw07_test PUBLIC cxx_std_20)
target_compile_options(hw07_test PUBLIC
    -Wall
    -Wextra
    -Werror
    -pedantic
)