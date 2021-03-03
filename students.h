#ifndef STUDENTS_H
#define STUDENTS_H

#include "student.h"

#include <QAbstractTableModel>
#include <QDataStream>
#include <QFile>

class Students : public QAbstractTableModel
{
    Q_OBJECT;
public:
    //! Дефолтный конструктор и деструктор для класса Students
    Students();
    ~Students();

    //! Методы, определяющие количество столбцов и строк
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    //! Методы, определяющие название и количество столбцов - заголовок таблицы
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    //! Перегрузка оператора квадратных скобок
    const Student &operator[](int idx) const;

    //! Инкапсулированные методы стандартного вектора
    //! из стандартной библиотеки C++
    //! Возвращает размер вектора
    int size();
    //! Удаляет элемент из вектора
    void erase(int idx);
    //! Сохраняет вектор в бинарный файл при закрытии
    void save();
    //! Выгружает данный вектор при начале работы программы
    void load();
    //! Добавляет студента в вектор
    void add(Student student);
    //! Добавляет студента в вектор на определенную позицию
    void addInPose(Student student, int index);

private:
    //! Контейнер для хранения студентов
    std::vector<Student> mStudents;
};
#endif // STUDENTS_H
