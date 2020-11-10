// Based on https://doc.qt.io/qt-5/qttestlib-tutorial1-example.html

#include <QtTest>

class TestQString : public QObject
{
    Q_OBJECT
private slots:
    void toUpper();
};

void TestQString::toUpper()
{
    QString str = "Hello";

    QVERIFY(str.toUpper() == "HELLO");
    /* Failure would look like:
FAIL!  : TestQString::toUpper() 'str.toUpper() == "HELLzO"' returned FALSE. ()
Loc: [.../ApprovalTests.cpp.Qt/examples/vanilla_qt_tests/TestQString.cpp(15)]
    */

    QCOMPARE(str.toUpper(), QString("HELLO"));
    /* Failure would look like:
FAIL!  : TestQString::toUpper() Compared values are not the same
Actual   (str.toUpper())    : "HELLO"
Expected (QString("HELqLO")): "HELqLO"
Loc: [.../ApprovalTests.cpp.Qt/examples/vanilla_qt_tests/TestQString.cpp(16)]
    */
}

QTEST_MAIN(TestQString)
#include "TestQString.moc"
