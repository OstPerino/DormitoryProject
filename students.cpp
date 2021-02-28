#include "students.h"

Students::Students()
{
    beginInsertRows(QModelIndex(), // Индекс родителя, в список потомков которого добавляются строки
                           0, // Номер первой добавляемой строки
                           size()); // Номер последней добавляемой строки

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
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole)
    {
        // Если столбец первый, возвращаем заголовок заметки, находящейся
        // в соответствующей строке таблицы
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
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

QVariant Students::headerData(int section, Qt::Orientation orientation, int role) const
{
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole)
    {
        // Если речь о заголовках столбцов...
        if (orientation == Qt::Horizontal)
        {
            // Если столбец первый, возвращаем заголовок
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
        // Если речь о заголовках строк...
        else if (orientation == Qt::Vertical)
        {
            // Возвращаем номер строки
            return QString::number(section);
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
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
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем удалять строки из модели
    beginRemoveRows(QModelIndex(), // Индекс родителя, из списка потомков которого удаляются строки
                    idx, // Номер первой удаляемой строки
                    idx // Номер последней удаляемой строки
                    );
    // Удаляем из вектора элемент с индексом idx
    mStudents.erase(std::next(mStudents.begin(), idx));
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили удалять строки из модели
    endRemoveRows();
}

void Students::save()
{
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
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем вставлять строки в модель.
    // Вставку производим в конец, поэтому номер новой строки будет равен size()
    beginInsertRows(QModelIndex(), // Индекс родителя, в список потомков которого добавляются строки
                           size(), // Номер первой добавляемой строки
                           size()); // Номер последней добавляемой строки
    // Вставляем заметку в конец вектора mNotes
    mStudents.push_back(student);
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили вставлять строки в модель.
    endInsertRows();
}

Student &Students::returnStudent(int index) {
    return mStudents[index];
}

void Students::edit(QModelIndex index, QString s1, QString s2, QString s3, QString s4, QString s5, QString s6)
{
    mStudents[index.row()].setName(s1);
    mStudents[index.row()].setSurname(s2);
    mStudents[index.row()].setRoom(s3);
    mStudents[index.row()].setGroupNumber(s4);
    mStudents[index.row()].setUniversity(s5);
    mStudents[index.row()].setBirthDate(s6);
}
