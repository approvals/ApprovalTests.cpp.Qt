#include <catch2/catch.hpp>

#include <iostream>

#include <QTest>

TEST_CASE("Demonstrate wrongly-passing QCOMPARE test"/*, "[!shouldfail]"*/)
{
    // https://github.com/approvals/ApprovalTests.cpp.Qt/issues/6
    std::cout << "before QCOMPARE\n";
    QCOMPARE(1, 2); // this will return, silently, as called from outside a slot
    std::cout << "after QCOMPARE - this line will never be reached\n";
}
