#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //! Связь между таблицей и вектором студентов
    ui->studentsTable->setModel(&mStudents);

    //! Фиксированный размер главного окна
    this->setFixedSize(990, 474);

    //! Название главного окна
    this->setWindowTitle("Общежитие");

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
    //! Создание нового студента
    int res;
    Student newStudent;

    //! Окно добавление и передача пустого студента для заполнения
    AddNewStudentsDialog newStudentDialog(this);
    newStudentDialog.setStudent(&newStudent);

    res = newStudentDialog.exec();

    //! Добавление студента в вектор
    if (res == QDialog::Accepted)
        mStudents.add(newStudent);
}

void MainWindow::on_deleteStudent_clicked()
{
    if (!ui->studentsTable->selectionModel()->isSelected(ui->studentsTable->currentIndex()))
    {
        QMessageBox *ask = new QMessageBox();
        ask->setWindowTitle("Warning");
        ask->setText("Выберите студента перед совершением операции!");
        ask->exec();
    }
    else {
        //! Сообщение предупреждение об удалении студента
        int ask = QMessageBox::question(this,
                                          QString("Warning"),
                                          QString("Вы действительно хотите выселить студента?"),
                                          QMessageBox::Yes | QMessageBox::No);
        if (ask == QMessageBox::Yes)
        {
            std::set<int> rows;
            {
                //! Вычленение индекса студента
                QModelIndexList idc = ui->studentsTable->selectionModel()->selectedRows();

                for (const auto &i : idc)
                {
                    rows.insert(i.row());
                }
            }
            //! Удаление по указателю
            for (auto it = rows.rbegin(); it != rows.rend(); ++it){
                mStudents.erase(*it);
            }
        }
    }
}

void MainWindow::on_talkingTo_clicked()
{
    if (!ui->studentsTable->selectionModel()->isSelected(ui->studentsTable->currentIndex()))
    {
        QMessageBox *ask = new QMessageBox();
        ask->setWindowTitle("Warning");
        ask->setText("Выберите студента перед совершением операции!");
        ask->exec();
    }
    else {
        //! Предупреждение при выговоре
        QMessageBox *message = new QMessageBox();
        Student student;

        message->setWindowTitle("Предупреждение");
        message->setText("Вы уверены что вы хотите вынести выговор данному студенту?");
        message->setIcon(QMessageBox::Warning);
        message->addButton(QMessageBox::Yes);
        message->addButton(QMessageBox::No);

        int res = message->exec();

        //! Создание буферного студента, которуму будет
        //! выдан выговор, а также замена его местами
        //! и удаление прежнего, для изменения параметра
        //! mStrikes
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
                fired->setText("Студент имеет максимальное количество выговор. Студент выселен");
                fired->setIcon(QMessageBox::Information);
                fired->addButton(QMessageBox::Yes);
                fired->exec();
            }
            else
                mStudents.addInPose(student, index.row());
        }
    }
}
