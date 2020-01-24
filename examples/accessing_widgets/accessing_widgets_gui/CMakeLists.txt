project("accessing_widgets_gui")

add_executable(
        ${PROJECT_NAME}
        main.cpp
)
target_link_libraries(${PROJECT_NAME} accessing_widgets_lib)
