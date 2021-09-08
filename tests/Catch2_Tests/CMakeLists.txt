project(Catch2_Tests)
set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME}
        main.cpp
        ApprovalsQtTests.cpp
        QtMacroTests.cpp
        integrations/catch/Catch2QtStringMakerTests.cpp
        writers/QImageApprovalWriterTests.cpp
        )
target_link_libraries(${PROJECT_NAME} ApprovalTestsQt::ApprovalTestsQt catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_FAST_COMPILE)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
