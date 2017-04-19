#ifndef TESTQINN_H
#define TESTQINN_H

#include <QtTest/QtTest>

class TestQInn : public QObject
{
    Q_OBJECT
private slots:
    void testValid_data();
    void testValid();

    void testInvalid_data();
    void testInvalid();

    void testCompare_data();
    void testCompare();

    void testEmptyAsInvalid();
};

#endif // TESTQINN_H
