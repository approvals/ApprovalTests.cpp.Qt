project(Catch2_Tests)
set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME}
    main.cpp
    )
target_link_libraries(${PROJECT_NAME} ApprovalTests catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_FAST_COMPILE)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
