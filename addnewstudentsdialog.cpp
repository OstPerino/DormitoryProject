#include "addnewstudentsdialog.h"
#include "ui_addnewstudentsdialog.h"

AddNewStudentsDialog::AddNewStudentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewStudentsDialog)
{
    ui->setupUi(this);
}

AddNewStudentsDialog::~AddNewStudentsDialog()
{
    delete ui;
}

void AddNewStudentsDialog::setStudent(Student *newStudent)
{
    this->newStudent = newStudent;
}

void AddNewStudentsDialog::on_buttonBox_accepted()
{
    newStudent->setName(ui->nameEdit->text());
    newStudent->setSurname(ui->surnameEdit->text());
    newStudent->setRoom(ui->roomEdit->text());
    newStudent->setGroupNumber(ui->groupEdit->text());
    newStudent->setBirthDate(ui->birthEdit->text());
    newStudent->setUniversity(ui->universityEdit->text());

    if (ui->nameEdit->text() == "" ||
        ui->surnameEdit->text() == "" ||
        ui->roomEdit->text() == "" ||
        ui->birthEdit->text() == "" ||
        ui->groupEdit->text() == "" ||
        ui->universityEdit->text() == "")
    {
        QMessageBox fillRows(this);
        fillRows.setIcon(QMessageBox::Warning);
        fillRows.setWindowTitle("Ошибка");
        fillRows.setText(tr("Какое-либо поле не заполнено!"));
        fillRows.setStandardButtons(QMessageBox::Discard);
        fillRows.exec();
    }
    else
        accept();
}

void AddNewStudentsDialog::on_buttonBox_rejected()
{
    reject();
}
