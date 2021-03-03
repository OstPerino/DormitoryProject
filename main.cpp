#include "mainwindow.h"
#include "accountdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    AccountDialog authorisation;
    int res = authorisation.exec();
    w.hide();
    if (res != QDialog::Accepted)
        w.hide();
    else
        w.show();
    return a.exec();
}
