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
}

QTEST_MAIN(TestNumbers)
#include "TestNumbers.moc"
