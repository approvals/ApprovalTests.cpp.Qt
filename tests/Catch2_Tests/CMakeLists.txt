project(Catch2_Tests)
set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME}
    main.cpp
    )
target_link_libraries(${PROJECT_NAME} ApprovalTests ApprovalTestsQt catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_FAST_COMPILE)

# TODO Remove hard-coded path - needed for now to get building in CLion
# See https://stackoverflow.com/questions/30235175/how-to-configure-clion-ide-for-qt-framework
set(CMAKE_PREFIX_PATH "/Users/clare/Documents/develop/tools/qt/5.12.5/clang_64/lib/cmake")
find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
