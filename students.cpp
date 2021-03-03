#include "students.h"

Students::Students()
{
    beginInsertRows(QModelIndex(),
                           0,
                           size());

    load();

    endInsertRows();
}

Students::~Students()
{
    save();
}

int Students::rowCount(const QModelIndex &parent) const
{
    return mStudents.size();
}

int Students::columnCount(const QModelIndex &parent) const
{
    return 7;
}

QVariant Students::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
            return mStudents[index.row()].getName();
        if (index.column() == 1)
            return mStudents[index.row()].getSurname();
        if (index.column() == 2)
            return mStudents[index.row()].getRoom();
        if (index.column() == 3)
            return mStudents[index.row()].getBirthDate();
        if (index.column() == 4)
            return mStudents[index.row()].getGroupNumber();
        if (index.column() == 5)
            return mStudents[index.row()].getUniversity();
        if (index.column() == 6)
            return mStudents[index.row()].getStrike();
    }
    return QVariant();
}

QVariant Students::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            if (section == 0)
                return "  Имя  ";
            if (section == 1)
                return "  Фамилия  ";
            if (section == 2)
                return "  Номер комнаты  ";
            if (section == 3)
                return "  Дата рождения  ";
            if (section == 4)
                return "  Номер группы  ";
            if (section == 5)
                return "  Университет   ";
            if (section == 6)
                return "  Выговор  ";
        }
        else if (orientation == Qt::Vertical)
        {
            return QString::number(section);
        }
    }
    return QVariant();
}

const Student &Students::operator[](int idx) const
{
    return mStudents[idx];
}

int Students::size()
{
    return mStudents.size();
}

void Students::erase(int idx)
{
    //! Удаление из вектора
    beginRemoveRows(QModelIndex(),
                    idx,
                    idx
                    );
    mStudents.erase(std::next(mStudents.begin(), idx));
    endRemoveRows();
}

void Students::save()
{
    //! Сохранение в файл
    QFile file("StudentsBase.bin");

    file.open(QIODevice::WriteOnly);

    QDataStream ost(&file);

    for (int i = 0; i < size(); ++i)
    {
        ost << mStudents[i];
    }

    file.close();
}

void Students::load()
{
    //! Выгрузка из файла
    QFile file("StudentsBase.bin");

    file.open(QIODevice::ReadOnly);

    QDataStream ist(&file);

    Student student;

    while (!file.atEnd())
    {
        ist >> student;
        add(student);
    }

    file.close();
}

void Students::add(Student student)
{
    //! Добавление студента в конец вектора
    beginInsertRows(QModelIndex(),
                           size(),
                           size());
    mStudents.push_back(student);
    endInsertRows();
}

void Students::addInPose(Student student, int index)
{
    //! Добавление в определенную позицию
    beginInsertRows(QModelIndex(),
                          size(),
                          size());
    mStudents.insert(mStudents.begin() + index, student);
    endInsertRows();
}
