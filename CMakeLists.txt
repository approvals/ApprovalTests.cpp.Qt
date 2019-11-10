cmake_minimum_required(VERSION 3.8)

# disable testsuite if used via add_subdirectory()
if (NOT DEFINED PROJECT_NAME)
    set(NOT_SUBPROJECT ON)
endif ()

project(ApprovalTests.cpp.Qt)
add_subdirectory(ApprovalTestsQt)

set(CMAKE_VERBOSE_MAKEFILE off)

if (NOT_SUBPROJECT)
    enable_testing()
    add_subdirectory(third_party)
    add_subdirectory(tests)
    add_subdirectory(examples)
endif ()
