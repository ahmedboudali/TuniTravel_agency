#ifndef ADRESSEEMAIL_H
#define ADRESSEEMAIL_H
#include <QSqlQueryModel>
#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QString>
#include <QSslSocket>
#include <QObject>
class adresseemail
{
public:
    adresseemail();
    ~adresseemail();
    adresseemail( const QString &user, const QString &pass, const QString &host, int port = 465, int timeout = 30000 );
    void sendMail( const QString &from, const QString &to,
                      const QString &subject, const QString &body );

   signals:
       void status( const QString &);

   private slots:
       void stateChanged(QAbstractSocket::SocketState socketState);
       void errorReceived(QAbstractSocket::SocketError socketError);
       void disconnected();
       void connected();
       void readyRead();

       /*int getcin();
       QString getadd();
       QString getpassword();
       void setcin(int cin);
       void setadd( QString add);
       void setpassword( QString password);
       bool ajouterE();
       QSqlQueryModel* afficherE();
       QSqlQueryModel * afficher_HI();*/


   private:
       int timeout;
          QString message;
          QTextStream *t;
          QSslSocket *socket;
          QString from;
          QString rcpt;
          QString response;
          QString user;
          QString pass;
          QString host;
          int port;
          enum states{Tls, HandShake ,Auth,User,Pass,Rcpt,Mail,Data,Init,Body,Quit,Close};
          int state;
};

#endif // ADRESSEEMAIL_H
