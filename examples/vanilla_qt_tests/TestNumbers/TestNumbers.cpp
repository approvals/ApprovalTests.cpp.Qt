#include <QtTest>

class TestNumbers : public QObject
{
Q_OBJECT
private slots:
    void lessThan();
};

void TestNumbers::lessThan()
{
    QVERIFY(12 < 42);
    /* Failure would look like:
FAIL!  : TestNumbers::lessThan() '52 < 42' returned FALSE. ()
Loc: [.../ApprovalTests.cpp.Qt/examples/vanilla_qt_tests/TestNumbers/TestNumbers.cpp(12)]
    */
}

QTEST_MAIN(TestNumbers)
#include "TestNumbers.moc"
