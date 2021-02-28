#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->studentsTable->setModel(&mStudents);

    //this->accountDialog = accountDialog;

    this->setFixedSize(946, 406);

    this->setWindowTitle("Общежитие");

    //parent->hide();

    //int res = accountDialog->exec();

    //if (res == QDialog::Accepted)
        //this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveData()
{
    mStudents.save();
}

void MainWindow::loadData()
{
    mStudents.load();
}

void MainWindow::on_addStudent_clicked()
{
    int res;
    Student newStudent;

    AddNewStudentsDialog newStudentDialog(this);
    newStudentDialog.setStudent(&newStudent);

    res = newStudentDialog.exec();

    if (res == QDialog::Accepted)
        mStudents.add(newStudent);
}

void MainWindow::on_deleteStudent_clicked()
{
    int ask = QMessageBox::question(this,
                                      QString("Warning"),
                                      QString("Вы действительно хотите выселить студента?"),
                                      QMessageBox::Yes | QMessageBox::No);
    if (ask == QMessageBox::Yes)
    {
        std::set<int> rows;
        {
            QModelIndexList idc = ui->studentsTable->selectionModel()->selectedRows();

            for (const auto &i : idc)
            {
                rows.insert(i.row());
            }
        }
        for (auto it = rows.rbegin(); it != rows.rend(); ++it){
            mStudents.erase(*it);
        }
    }
}

void MainWindow::on_talkingTo_clicked()
{
    QMessageBox *message = new QMessageBox();
    Student student;

    message->setWindowTitle("Предупреждение");
    message->setText("Вы уверены что вы хотите вынести выговор данному студенту?");
    message->setIcon(QMessageBox::Warning);
    message->addButton(QMessageBox::Yes);
    message->addButton(QMessageBox::No);

    int res = message->exec();

    if (res == QMessageBox::Yes)
    {
        QModelIndex index = ui->studentsTable->currentIndex();
        int newStrike = mStudents[index.row()].getStrike();
        newStrike++;

        student = mStudents[index.row()];
        student.setStrike(newStrike);

        mStudents.erase(index.row());

        if (student.getStrike() >= 3)
        {
            QMessageBox *fired = new QMessageBox();
            fired->setWindowTitle("Информация");
            fired->setText("Студент имеет ключевое количество выговор. Студент выселен");
            fired->setIcon(QMessageBox::Information);
            fired->addButton(QMessageBox::Yes);
            fired->exec();
        }
        else
            mStudents.addInPose(student, index.row());
    }
}
