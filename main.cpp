#include "mainwindow.h"
#include "accountdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qApp->setStyleSheet("* {font-family: century gothic; font-size: 20px;}"
                        "QDialog {background-color: #252525; color: 64dfdf;}"
                        "QMainWindow {background-color: #252525}"
                        "QLabel {color: #64dfdf;}"
                        "QLineEdit {background-color: #6930c3; color: #64dfdf;}"
                        "QPushButton {background-color: #6930c3; color: #64dfdf; font-weight: bold;}"
                        "QTableView {background-color: #6a2c70; color: #64dfdf;}"
                        "QHeaderView:section {background-color: #6a2c70; color: #64dfdf}"
                        );

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
