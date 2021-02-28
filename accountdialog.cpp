#include "accountdialog.h"
#include "ui_accountdialog.h"

AccountDialog::AccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountDialog)
{
    ui->setupUi(this);
}

AccountDialog::~AccountDialog()
{
    delete ui;
}

void AccountDialog::on_buttonBox_accepted()
{
    QMessageBox *warning = new QMessageBox();

    warning->setWindowTitle("Ошибка");
    warning->setText("Логин или пароль администратора неверны");
    warning->setIcon(QMessageBox::Warning);
    warning->addButton(QMessageBox::Ok);

    if (ui->loginEdit->text() == "Admin" && ui->passwordEdit->text() == "12345")
        accept();
    else
    {
        warning->exec();
        ui->passwordEdit->text() = "";
    }
}

void AccountDialog::on_buttonBox_rejected()
{
    reject();
}
