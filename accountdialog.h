#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AccountDialog;
}

class AccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AccountDialog(QWidget *parent = nullptr);
    ~AccountDialog();

private slots:

    void on_enter_clicked();

    void on_cancel_clicked();

private:
    Ui::AccountDialog *ui;
};

#endif // ACCOUNTDIALOG_H
