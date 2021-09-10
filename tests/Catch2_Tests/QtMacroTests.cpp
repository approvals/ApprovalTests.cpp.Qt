#include <catch2/catch.hpp>

#include <iostream>

#include <QTest>

// Include "SafeQTestMacros.h" after <QTest> to enable compile-time prevention
// of use of QCOMPARE outside QObject slots
#include "SafeQTestMacros.h"

#define ENABLE_CODE_THAT_SHOULD_FAIL_TO_COMPILE 0

#if ENABLE_CODE_THAT_SHOULD_FAIL_TO_COMPILE
// -----------------------------------------------------------------------------------------------
// QCOMPARE-based tests

TEST_CASE("Demonstrate wrongly-passing QCOMPARE test" /*, "[!shouldfail]"*/)
{
    // https://github.com/approvals/ApprovalTests.cpp.Qt/issues/6
    std::cout << "before QCOMPARE\n";
    QCOMPARE(1, 2); // this will return, silently, as called from outside a slot
    std::cout << "after QCOMPARE - this line will never be reached\n";
}

TEST_CASE("Demonstrate wrongly-passing QTRY_COMPARE test" /*, "[!shouldfail]"*/)
{
    // This takes 15 seconds to run
    std::cout << "before QTRY_COMPARE\n";
    QTRY_COMPARE(1, 2);
    std::cout << "after QTRY_COMPARE - this line will never be reached\n";
}

TEST_CASE(
    "Demonstrate wrongly-passing QTRY_COMPARE_WITH_TIMEOUT test" /*, "[!shouldfail]"*/)
{
    // This takes 1.5 seconds to run
    std::cout << "before QTRY_COMPARE_WITH_TIMEOUT\n";
    QTRY_COMPARE_WITH_TIMEOUT(1, 2, 500);
    std::cout << "after QTRY_COMPARE_WITH_TIMEOUT - this line will never be reached\n";
}
#endif // ENABLE_CODE_THAT_SHOULD_FAIL_TO_COMPILE

// -----------------------------------------------------------------------------------------------
// Simple checks

TEST_CASE("Demonstrate wrongly-passing QVERIFY test" /*, "[!shouldfail]"*/)
{
    std::cout << "before QVERIFY\n";
    QVERIFY(1 == 2);
    std::cout << "after QVERIFY - this line will never be reached\n";
}

TEST_CASE("Demonstrate wrongly-passing QFAIL test" /*, "[!shouldfail]"*/)
{
    std::cout << "before QFAIL\n";
    QFAIL("this test should fail");
    std::cout << "after QFAIL - this line will never be reached\n";
}

TEST_CASE("Demonstrate wrongly-passing QVERIFY2 test" /*, "[!shouldfail]"*/)
{
    std::cout << "before QVERIFY2\n";
    QVERIFY2(1 == 2, "one should equaly two - this should fail");
    std::cout << "after QVERIFY2 - this line will never be reached\n";
}

// -----------------------------------------------------------------------------------------------
// QTRY_* checks

TEST_CASE(
    "Demonstrate wrongly-passing QTRY_VERIFY_WITH_TIMEOUT test" /*, "[!shouldfail]"*/)
{
    // This takes 1.5 seconds to run
    std::cout << "before QTRY_VERIFY_WITH_TIMEOUT\n";
    QTRY_VERIFY_WITH_TIMEOUT(1 == 2, 500);
    std::cout << "after QTRY_VERIFY_WITH_TIMEOUT - this line will never be reached\n";
}

TEST_CASE(
    "Demonstrate wrongly-passing QTRY_VERIFY2_WITH_TIMEOUT test" /*, "[!shouldfail]"*/)
{
#ifdef QTRY_VERIFY2_WITH_TIMEOUT
    // This takes 1.5 seconds to run
    std::cout << "before QTRY_VERIFY2_WITH_TIMEOUT\n";
    QTRY_VERIFY2_WITH_TIMEOUT(1 == 2, "1 != 2 - this should fail", 500);
    std::cout << "after QTRY_VERIFY2_WITH_TIMEOUT - this line will never be reached\n";
#else
    std::cout << "Macro QTRY_VERIFY2_WITH_TIMEOUT is not available";
#endif
}
