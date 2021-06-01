#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <iostream>

using namespace std;

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    qDebug() << "email: " << email;
    qDebug() << "password: " << password;





    if(email.length() > 0 || password.length() > 4){
        //open the main window
        hide();
        mainWindow = new MainWindow(this);
        mainWindow->show();
    }



}
