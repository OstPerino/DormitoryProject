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
    Students();
    ~Students();
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    const Student &operator[](int idx) const;
    Student &returnStudent(int index);
    int size();
    void erase(int idx);
    void save();
    void load();
    void add(Student student);
    void addInPose(Student student, int index);
    void edit(QModelIndex index, QString s1, QString s2, QString s3, QString s4, QString s5, QString s6);
private:
    std::vector<Student> mStudents;
};
#endif // STUDENTS_H
