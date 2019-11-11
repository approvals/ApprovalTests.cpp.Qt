project("accessing_widgets_lib")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(
        ${PROJECT_NAME}
        samplewidgets01.cpp
        samplewidgets01.h
        samplewidgets02.cpp
        samplewidgets02.h
        samplewidgets.ui
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Qt5 COMPONENTS Widgets Test REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Widgets)
