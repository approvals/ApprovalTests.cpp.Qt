#pragma once

// TODO Add detection of QVERIFY, QTRY_COMPARE and so on

#include <type_traits>
#include <QCoreApplication>
#include <QTest>

namespace qft
{

    void sender(...);
}

// A custom QCOMPARE implementation, for use with tests that are driven
// by Catch2, or any other non-QtTest main(), that want access to QtTest
// in order to use QSignalSpy - but must not use QCOMPARE and similar,
// as any failures in these macros are silently ignored when called
// from outside a QObject slot.
//
// Credit: Fabian Kosmale at Qt, November 2019

#undef QCOMPARE
#define QCOMPARE(actual, expected)                                                       \
    do                                                                                   \
    {                                                                                    \
        using namespace qft;                                                             \
        static_assert(std::is_same<decltype(sender()), QObject*>::value,                 \
                      "Cannot user QCOMPARE outside of a QObject slot");                 \
        if (!QTest::qCompare(actual, expected, #actual, #expected, __FILE__, __LINE__))  \
            return;                                                                      \
    } while (false)
