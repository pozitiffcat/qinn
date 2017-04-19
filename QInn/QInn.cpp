#include "QInn.h"

QInn::QInn()
{
}

void QInn::setValue(const QString &inn)
{
    m_inn = inn;
}

QInn::QInn(const QString &inn)
    : m_inn(inn)
{
}

bool QInn::isValid() const
{
    if (!hasOnlyDigits())
        return false;

    const int Inn_10_C_Offset = 2;
    const int Inn_12_C1_Offset = 1;
    const int Inn_12_C2_Offset = 0;

    if (m_inn.length() == 12)
    {
        return calc(Inn_12_C1_Offset) == m_inn.at(10).digitValue() &&
                calc(Inn_12_C2_Offset) == m_inn.at(11).digitValue();
    }
    if (m_inn.length() == 10)
    {
        return calc(Inn_10_C_Offset) == m_inn.at(9).digitValue();
    }
    else
    {
        return false;
    }
}

bool QInn::isEmpty() const
{
    return m_inn.isEmpty();
}

bool QInn::isNull() const
{
    return m_inn.isNull();
}

const QString &QInn::value() const
{
    return m_inn;
}

bool QInn::operator ==(const QInn &inn) const
{
    if (!isValid() || !inn.isValid())
        return false;

    return m_inn == inn.m_inn;
}

int QInn::calc(int offset) const
{
    const int Weights[] = {3, 7, 2, 4, 10, 3, 5, 9, 4, 6, 8};
    const int WeightsCount = sizeof(Weights) / sizeof(int);

    int a = 0;

    for (int i = 0; i < WeightsCount - offset; ++i)
        a += m_inn.at(i).digitValue() * Weights[offset + i];

    return a % 11 % 10;
}

bool QInn::hasOnlyDigits() const
{
    foreach (const QChar &c, m_inn)
    {
        if (!c.isDigit())
            return false;
    }

    return true;
}
