#include "addnewstudentsdialog.h"
#include "ui_addnewstudentsdialog.h"

#include <QRegExpValidator>

//! Пространство символов для валидатора
#define NAME_SURNAME_RX "^[А-Я][а-я]+$"
#define ROOM_RX "^\\w{5,20}$"

AddNewStudentsDialog::AddNewStudentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewStudentsDialog)
{
    ui->setupUi(this);

    //! Создание объекта валидации
    QRegExp rxName(NAME_SURNAME_RX);
    QRegExp rxRoom(ROOM_RX);

    //! Создание валидатора
    QRegExpValidator *nameValidator = new QRegExpValidator(rxName, this);
    QRegExpValidator *roomValidator = new QRegExpValidator(rxRoom, this);

    //! Установка валидации для полей: имя, фамилия, комната
    ui->nameEdit->setValidator(nameValidator);
    ui->surnameEdit->setValidator(nameValidator);
    ui->roomEdit->setValidator(roomValidator);
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
    //! Заполнение парамтеров нового студента
    newStudent->setName(ui->nameEdit->text());
    newStudent->setSurname(ui->surnameEdit->text());
    newStudent->setRoom(ui->roomEdit->text());
    newStudent->setGroupNumber(ui->groupEdit->text());
    newStudent->setBirthDate(ui->birthEdit->text());
    newStudent->setUniversity(ui->universityEdit->text());

    //! Проверка полей на пустоту
    if (ui->nameEdit->text() == "" ||
        ui->surnameEdit->text() == "" ||
        ui->roomEdit->text() == "" ||
        ui->birthEdit->text() == "" ||
        ui->groupEdit->text() == "" ||
        ui->universityEdit->text() == "")
    {
        //! Создание окна с сообщением об ошибке
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
