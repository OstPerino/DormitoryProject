#include "student.h"

Student::Student()
{

}

Student::~Student()
{

}

Student::Student(QString name, QString surname, QString groupNumber,
                 QString room, QString university, QString birthDate, int strike)
    : mName(name)
    , mSurname(surname)
    , mGroupNumber(groupNumber)
    , mRoom(room)
    , mUniversity(university)
    , mBirthDate(birthDate)
    , mStrike(strike)
{}

const QString &Student::getName() const
{
    return mName;
}

void Student::setName(const QString &name)
{
    mName = name;
}

const QString &Student::getSurname() const
{
    return mSurname;
}

void Student::setSurname(const QString &surname)
{
    mSurname = surname;
}

const QString &Student::getGroupNumber() const
{
    return mGroupNumber;
}

void Student::setGroupNumber(const QString &groupNumber)
{
    mGroupNumber = groupNumber;
}

const QString &Student::getRoom() const
{
    return mRoom;
}

void Student::setRoom(const QString &room)
{
    mRoom = room;
}

const QString &Student::getUniversity() const
{
    return mUniversity;
}

void Student::setUniversity(const QString &university)
{
    mUniversity = university;
}

const QString &Student::getBirthDate() const
{
    return mBirthDate;
}

void Student::setBirthDate(const QString &birthDate)
{
    mBirthDate = birthDate;
}

const int &Student::getStrike() const
{
    return mStrike;
}

void Student::setStrike(const int &strike)
{
    mStrike = strike;
}

QDataStream &operator >>(QDataStream &ist, Student &student)
{
    ist >> student.mName
        >> student.mSurname
        >> student.mGroupNumber
        >> student.mUniversity
        >> student.mRoom
        >> student.mBirthDate;
    return ist;
}

QDataStream &operator <<(QDataStream &ost, const Student &student)
{
    ost << student.mName
        << student.mSurname
        << student.mGroupNumber
        << student.mUniversity
        << student.mRoom
        << student.mBirthDate;
    return ost;
}
