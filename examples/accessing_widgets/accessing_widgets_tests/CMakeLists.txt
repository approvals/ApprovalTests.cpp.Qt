project("accessing_widgets_tests")

add_executable(
        ${PROJECT_NAME}
        main.cpp
        samplewidgets00_tests.cpp
        samplewidgets01_tests.cpp
        samplewidgets02_tests.cpp
        samplewidgets03_tests.cpp
        samplewidgets04_tests.cpp
)
target_link_libraries(${PROJECT_NAME} ApprovalTestsQt catch2 accessing_widgets_lib)

find_package(Qt5 COMPONENTS Widgets Test REQUIRED)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
