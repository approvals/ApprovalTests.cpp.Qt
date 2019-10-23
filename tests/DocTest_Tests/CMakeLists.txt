project(DocTest_Tests)
set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME}
    main.cpp
    )
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
