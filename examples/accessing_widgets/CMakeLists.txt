project("accessing_widgets")

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ApprovalTestsQt catch2)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
