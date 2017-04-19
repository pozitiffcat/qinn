#include "TestQInn.h"
#include "QInn.h"

void TestQInn::testValid_data()
{
    QTest::addColumn<QString>("innValue");

    QStringList validInnList = QStringList()
            << "500100732259"
            << "7825706086"
            << "7715277300"
            << "7706202481"
            << "7729355029"
            << "7830002293";

    foreach (const QString &innValue, validInnList)
        QTest::newRow(innValue.toLocal8Bit().constData()) << innValue;
}

void TestQInn::testValid()
{
    QFETCH(QString, innValue);

    QCOMPARE(QInn(innValue).isValid(), true);
}

void TestQInn::testInvalid_data()
{
    QTest::addColumn<QString>("innValue");

    QStringList invalidInnList = QStringList()
            << "500100732258"
            << "7825706085"
            << "7715277301"
            << "7706202482"
            << "7729355023"
            << "7830002294"
            << "783000229a"
            << QString()
            << "";

    foreach (const QString &innValue, invalidInnList)
        QTest::newRow(innValue.toLocal8Bit().constData()) << innValue;
}

void TestQInn::testInvalid()
{
    QFETCH(QString, innValue);

    QCOMPARE(QInn(innValue).isValid(), false);
}

void TestQInn::testCompare_data()
{
    QTest::addColumn<QInn>("inn1");
    QTest::addColumn<QInn>("inn2");
    QTest::addColumn<bool>("result");

    QTest::newRow("valid data") << QInn("500100732259") << QInn("500100732259") << true;
    QTest::newRow("invalid data") << QInn("500100732259") << QInn("500100732258") << false;
    QTest::newRow("empty datas are not same") << QInn("") << QInn("") << false;
    QTest::newRow("null datas are not same") << QInn() << QInn() << false;
}

void TestQInn::testCompare()
{
    QFETCH(QInn, inn1);
    QFETCH(QInn, inn2);
    QFETCH(bool, result);

    QCOMPARE(inn1 == inn2, result);
}

void TestQInn::testEmptyAsInvalid()
{
    QInn inn("");
    QCOMPARE(inn.isValid(), false);
}

QTEST_MAIN(TestQInn)
