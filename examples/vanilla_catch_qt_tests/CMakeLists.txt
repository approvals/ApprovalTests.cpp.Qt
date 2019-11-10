project(vanilla_catch_qt_tests)
set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME}
        main.cpp
        )
find_package(Qt5 COMPONENTS Widgets Test REQUIRED)
target_link_libraries(${PROJECT_NAME} catch2 Qt5::Widgets)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
