#include <catch2/catch.hpp>

#include <QString>

TEST_CASE("String::toUpper")
{
    QString str = "Hello";
    CHECK(str.toUpper() == "HELLO");
    /* Failure would look like:
.../ApprovalTests.cpp.Qt/examples/vanilla_catch_qt_tests/TestQStringInCatch2.cpp:8: FAILED:
  CHECK( str.toUpper() == "HExLLO" )
with expansion:
  { {?}, {?}, {?}, {?}, {?} } == "HExLLO"
    */
}
