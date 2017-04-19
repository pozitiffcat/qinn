#ifndef QINN_H
#define QINN_H

#include <QString>
#include <QMetaType>

class QInn
{
public:
    explicit QInn(const QString &inn);
    QInn();

    /**
     * @brief setValue задать значение ИНН
     * @param inn ИНН
     */
    void setValue(const QString &inn);

    /**
     * @brief isValid проверка на валидность ИНН
     * @return валидно, либо нет
     */
    bool isValid() const;

    /**
     * @brief isEmpty проверка на пустое значение ИНН
     * @details пустое значение не является валидным
     * @return пусто, либо нет
     */
    bool isEmpty() const;

    /**
     * @brief isNull проверка на присутствие переданного значения ИНН
     * @return задавался ИНН, либо нет
     */
    bool isNull() const;

    /**
     * @brief value
     * @return строковое значение ИНН
     */
    const QString &value() const;

    /**
     * @brief operator == проверяет на равенство
     * @details невалидные объекты не могут быть сравнимы, по-этому результат всегда false
     * @param inn ИНН с которым сравниваем
     * @return равны, либо нет
     */
    bool operator ==(const QInn &inn) const;

private:
    int calc(int offset) const;
    bool hasOnlyDigits() const;

private:
    QString m_inn;
};

Q_DECLARE_METATYPE(QInn)

#endif // QINN_H
