#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "student.h"
#include "students.h"
#include "addnewstudentsdialog.h"
#include "accountdialog.h"

#include <QMainWindow>
#include <QMessageBox>

#include <set>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void saveData();
    void loadData();

private slots:
    void on_addStudent_clicked();

    void on_deleteStudent_clicked();

    void on_talkingTo_clicked();

private:
    Ui::MainWindow *ui;
    AccountDialog *accountDialog;
    Students mStudents;
};
#endif // MAINWINDOW_H
