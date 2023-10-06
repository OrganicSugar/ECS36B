cmake_minimum_required(VERSION 3.5)
project(4_BattleShip)
set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED)
if(NOT IS_DIRECTORY ${PROJECT_SOURCE_DIR}/googletest)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG main
    )
    FetchContent_GetProperties(googletest)
    if (NOT googletest_POPULATED)
        FetchContent_Populate(googletest)
    endif()
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
else()
    add_subdirectory(googletest)
endif()

add_executable(Test
        isMoveValid.cpp)

target_link_libraries(Test
        PRIVATE
        BattleShipSrc
        gtest
        gmock
        gtest_main
        )
target_compile_options(Test PRIVATE -Wall -Werror)