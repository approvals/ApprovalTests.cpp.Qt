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
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_MAIN(TestQString)
#include "TestQString.moc"
