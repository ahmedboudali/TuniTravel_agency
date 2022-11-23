#include "login.h"
#include "ui_login.h"
#include <QMessageBox>              //el conection mta3 el oracle (pt3.)
#include <QPixmap>                  //el taswira eli bich t7otha fil login.ui (pt1.)
#include "employee.h"
#include "arduino.h"


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

   QPixmap pix("C:/Users/dell/Documents/NOTION/2eme année (2-A-27)/subjects/Projet C++/uni-removebg-preview");                           //el taswira eli bich t7otha fil login.ui (pt2.)
   ui->label_signin_pic->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));                                                              //el taswira eli bich t7otha fil login.ui (pt3.)
  // ui->tableWidget_pass->setModel(Etmp.afficher_m());

   serial = new QSerialPort(); //Inicializa la variable Serial
   arduino_available = false;

   foreach (const QSerialPortInfo &serial_Info, QSerialPortInfo::availablePorts())
   {
       //Lee la información de cada puerto serial
       qDebug()<<"Puerto: "<<serial_Info.portName();
       portname = serial_Info.portName();
       qDebug()<<"Vendor Id: "<<serial_Info.vendorIdentifier();
       vendorId = serial_Info.vendorIdentifier();
       qDebug()<<"Product Id: "<<serial_Info.productIdentifier();
       productId = serial_Info.productIdentifier();
       arduino_available = true;
   }

   if(arduino_available)
   {
       arduino_init();
   }

/*

   int ret=A.connect_arduino(); // lancer la connexion à arduino
   switch(ret){
   case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
       break;
   case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
      break;
   case(-1):qDebug() << "arduino is not available";
   }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
    //le slot update_label suite à la reception du signal readyRead (reception des données).


*/
}

login::~login()
{
    delete ui;
}


/*
void login::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}
*/



void login::arduino_init()
{
    serial->setPortName(portname);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
}




void login::on_pushButton_signin_login_clicked()
{


         // ****
    QString username_pass= ui->lineEdit_signin_username->text();
    int username = ui->lineEdit_signin_username->text().toUInt();
    QString password = ui->lineEdit_signin_password->text();

    QSqlQuery  query;
    QString res1=QString::number(username);
    query.bindValue(":ID_E",res1);
     // ****
    query.prepare("select * from DB_EMPLOYEE_LOGIN where ID_E='"+res1+"' and MOTPASS_E='"+password+"'");


    int i=0;

    /*
     if (username_pass=="admin_password" && password=="admin_password")
        {
        ui->tableView_pass->setModel(Etmp.afficher_m());
        }
    */


    if (query.exec())
    {
        while(query.next()){i++;}
        if (i==1)  QMessageBox::information(this,"Login","User name and password are correct");
        if (i<1) //QMessageBox::warning(this,"Login","Incorrect Username or Password !");
            ui->label_etatlogin->setText("Incorrect Username or Password !");
        //if(i>1) QMessageBox::warning(this,"Login","duplique!");
    }

    if(i==1)
    {

        if(serial->isWritable())
        {
            serial->write("1");
            qDebug()<<"OK";
        }

          hide();                                  //el menu eli bich n7ilo ki el login yi5dim (pt3.1)
          mainWindow = new MainWindow(this);       //el menu eli bich n7ilo ki el login yi5dim (pt3.2)
          mainWindow->show();                      //el menu eli bich n7ilo ki el login yi5dim (pt3.f)
    }


    /*
   if(username=="admin" && password=="admin" )

    {
       QMessageBox::information(this,"Login","User name and password are correct");


       hide();                                  //el menu eli bich n7ilo ki el login yi5dim (pt3.1)
       mainWindow = new MainWindow(this);       //el menu eli bich n7ilo ki el login yi5dim (pt3.2)
       mainWindow->show();                      //el menu eli bich n7ilo ki el login yi5dim (pt3.f)
    }
    else QMessageBox::warning(this,"Login","Incorrect Username or Password !");*/

}




bool login::createconnect()                     //el conection mta3 el oracle (pt3.)
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Tuni_Travel_DB");
    db.setUserName("boudali");//inserer nom de l'utilisateur
    db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

    if (db.open()) test=true;

    return  test;
}




void login::on_pushButton_signin_login_2_clicked()
{
    if(serial->isReadable())
    {
         data=serial->readAll(); //récupérer les données reçues

    }

}
