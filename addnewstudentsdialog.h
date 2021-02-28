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

    void setStudent(Student* newStudent);

    void edit(QString s1, QString s2, QString s3, QString s4, QString s5, QString s6);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddNewStudentsDialog *ui;
    Student *newStudent;
};

#endif // ADDNEWSTUDENTSDIALOG_H
