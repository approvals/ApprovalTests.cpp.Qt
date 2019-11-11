project("accessing_widgets")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(
        ${PROJECT_NAME}
        main.cpp
        samplewidgets.cpp
        samplewidgets.h
        samplewidgets.ui
)
target_link_libraries(${PROJECT_NAME} ApprovalTestsQt catch2)

find_package(Qt5 COMPONENTS Widgets Test REQUIRED)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
