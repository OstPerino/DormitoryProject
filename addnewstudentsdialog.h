#ifndef ADDNEWSTUDENTSDIALOG_H
#define ADDNEWSTUDENTSDIALOG_H

#include "student.h"

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AddNewStudentsDialog;
}

class AddNewStudentsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewStudentsDialog(QWidget *parent = nullptr);
    ~AddNewStudentsDialog();

    //! Сеттер для студента
    void setStudent(Student* newStudent);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    //! Указатель на нового студента
    Ui::AddNewStudentsDialog *ui;
    Student *newStudent;
};

#endif // ADDNEWSTUDENTSDIALOG_H
