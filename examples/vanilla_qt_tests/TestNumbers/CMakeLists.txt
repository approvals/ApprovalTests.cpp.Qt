project(vanilla_qt_tests_TestNumbers)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
add_executable(${PROJECT_NAME}
        TestNumbers.cpp
        )
find_package(Qt5 COMPONENTS Test REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Test)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
