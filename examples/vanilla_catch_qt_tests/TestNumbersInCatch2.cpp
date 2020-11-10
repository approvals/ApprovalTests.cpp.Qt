#include <catch2/catch.hpp>

#include <QString>

TEST_CASE("LessThan")
{
    CHECK(12 < 42);
    /* Failure would look like:
.../ApprovalTests.cpp.Qt/examples/vanilla_catch_qt_tests/TestNumbersInCatch2.cpp:7: FAILED:
CHECK( 52 < 42 )
    */
}
