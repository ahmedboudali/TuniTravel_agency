#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMainWindow>

#include "mainwindow.h"                             //el menu eli bich n7ilo ki el login yi5dim (pt1.)
#include <QTableWidget>

#include <QSqlDatabase>                             //el conection mta3 el oracle (pt1.)
#include <QSqlError>                                //el conection mta3 el oracle (pt1.)
#include <QSqlQuery>                                //el conection mta3 el oracle (pt1.)

#include "employee.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "arduino.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    bool createconnect();                           //el conection mta3 el oracle (pt2.)







private slots:
    void on_pushButton_signin_login_clicked();




    void on_pushButton_signin_login_2_clicked();

private:



    Ui::login *ui;
    MainWindow *mainWindow;                         //el menu eli bich n7ilo ki el login yi5dim (pt2.)
    employee Etmp,E;



    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire




};

#endif // LOGIN_H



