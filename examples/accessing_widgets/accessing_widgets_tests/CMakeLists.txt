project("accessing_widgets_tests")

add_executable(
        ${PROJECT_NAME}
        main.cpp
        samplewidgets00_tests_no_fixture.cpp
        samplewidgets00_tests_with_fixture.cpp
        samplewidgets02_tests.cpp
        samplewidgets03_tests_inheritance.cpp
        samplewidgets03_tests_non_inheritance.cpp
)
target_link_libraries(${PROJECT_NAME} ApprovalTestsQt catch2 accessing_widgets_lib)

find_package(Qt5 COMPONENTS Widgets Test REQUIRED)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
