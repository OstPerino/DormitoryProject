#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    //! Стандартные конструктор и деструктор для класса Student
    Student();
    ~Student();

    //! Конструктор с принятием параметров объекта
    Student(QString name, QString surname, QString groupNumber, QString room, QString university, QString birthDate, int strike);

    //! Геттер для имени студента
    const QString &getName() const;
    //! Сеттер для имени студента
    void setName(const QString &name);

    //! Геттр для фамилии студента
    const QString &getSurname() const;
    //! Сеттер для имени студента
    void setSurname(const QString &surname);

    //! Геттер для группы студента
    const QString &getGroupNumber() const;
    //! Сеттер для группы студента
    void setGroupNumber(const QString &groupNumber);

    //! Геттер для комнаты студента
    const QString &getRoom() const;
    //! Сеттер для комнаты студента
    void setRoom(const QString &room);

    //! Геттер для университета студента
    const QString &getUniversity() const;
    //! Сеттер для университета студента
    void setUniversity(const QString &university);

    //! Геттер для даты рождения студента
    const QString &getBirthDate() const;
    //! Сеттер для даты рождения студента
    void setBirthDate(const QString &birthDate);

    //! Кол-во предупреждений студента
    const int &getStrike() const;
    void setStrike(const int &strike);

    //! Дружественные операторы для работы с потоками
    friend QDataStream &operator >>(QDataStream &ist, Student &student);
    friend QDataStream &operator <<(QDataStream &ost, const Student &student);

private:

    QString mName, mSurname, mGroupNumber,
            mRoom, mUniversity, mBirthDate;
    int mStrike = 0;
};

#endif // STUDENT_H
