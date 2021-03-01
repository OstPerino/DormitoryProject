#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student();
    ~Student();
    Student(QString name, QString surname, QString groupNumber, QString room, QString university, QString birthDate, int strike);
    const QString &getName() const;
    void setName(const QString &name);
    const QString &getSurname() const;
    void setSurname(const QString &surname);
    const QString &getGroupNumber() const;
    void setGroupNumber(const QString &groupNumber);
    const QString &getRoom() const;
    void setRoom(const QString &room);
    const QString &getUniversity() const;
    void setUniversity(const QString &university);
    const QString &getBirthDate() const;
    void setBirthDate(const QString &birthDate);
    const int &getStrike() const;
    void setStrike(const int &strike);
    friend QDataStream &operator >>(QDataStream &ist, Student &student);
    friend QDataStream &operator <<(QDataStream &ost, const Student &student);
    // Потоковый ввод вывод, перегрузка операторов
private:
    QString mName, mSurname, mGroupNumber,
            mRoom, mUniversity, mBirthDate;
    int mStrike = 0;
};

#endif // STUDENT_H
