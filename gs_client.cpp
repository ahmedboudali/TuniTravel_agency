#include "gs_client.h"
#include "ui_gs_client.h"
#include "client.h"
#include "adresseemail.h"
#include <QMessageBox>

#include <QIntValidator>
#include <QTextStream>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>

gs_client::gs_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_client)
{
    ui->setupUi(this);
    client Etmp;
    ui->tablec->setModel(Etmp.afficher());
    client c;
       float nbreT=c.nbre_totale();
       float  nbreTA=c.nbre_totalea();
       float nbreTS=c.nbre_totales();
       float nbreTM=c.nbre_totalem();

       ui->ajoup->setNum((nbreTA*100)/nbreT);
       ui->updatep->setNum((nbreTM*100)/nbreT);
       ui->suppp->setNum((nbreTS*100)/nbreT);



       ui->lineEdit_cind->setValidator(new QIntValidator(0,999999999, this));
       ui->lineEdit_telephoned->setValidator(new QIntValidator(0,888888888, this));

       ui->lineEdit_nomd ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));
       ui->lineEdit_prenomd ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));
       ui->lineEdit_emaild ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z-@. _]+"), this ));
       ui->lineEdit_adressed ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));



}

gs_client::~gs_client()
{
    delete ui;
}


void gs_client::on_Ajouterc_clicked()
{
    {
        int cin=ui->lineEdit_cind->text().toInt();
         QString nom=ui->lineEdit_nomd->text() ;
         QString prenom=ui->lineEdit_prenomd->text() ;
         QString email=ui->lineEdit_emaild->text() ;
         int telephone=ui->lineEdit_telephoned->text().toInt();
         QString adresse=ui->lineEdit_adressed->text() ;

         client c(cin,nom,prenom,email,telephone,adresse);

        if (c.ajouter())
        {QMessageBox msgBox;


           client Etmp;
           ui->tablec->setModel(Etmp.afficher());
           ui->His->setModel(Etmp.afficher_HIS());

           QMessageBox::information(this,"ajout","The document has been modified");
           /*
           msgBox.setText("The document has been modified.");
           msgBox.exec();
*/}
        else
        {
            QMessageBox msgBox;
            QMessageBox::information(this,"Ajout","leeee");

        }

    }
}


void gs_client::on_update_clicked()
{
    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text() ;
    QString prenom=ui->lineEdit_prenom->text() ;
    QString email=ui->lineEdit_email->text() ;
    int telephone=ui->lineEdit_telephone->text().toInt();
    QString adresse=ui->lineEdit_adresse->text() ;
    client c(cin,nom,prenom,email,telephone,adresse);

  QMessageBox msgBox;
  bool test=c.modifier(cin);

  if(test)
  {
      client Etmp;
          ui->tablec->setModel(Etmp.afficher());
          ui->His->setModel(Etmp.afficher_HIS());

          QMessageBox::information(this,"Modifier","cbn");

                           /*   ui->lineEdit_cin->clear();
                              ui->lineEdit_nom->clear();
                              ui->lineEdit_prenom->clear();
                              ui->lineEdit_email->clear();
                              ui->lineEdit_telephone->clear();
                              ui->lineEdit_adresse->clear();*/
   }
  else
      QMessageBox::information(this,"Modifier","Leeeeee");
}

void gs_client::on_suppc_clicked()
{
    client c;

                int num = ui->cimsupp->text().toInt();
                bool test=c.supprimer(num);
                    if(test)
                    {
                        ui->tablec->setModel(c.afficher());
                        ui->His->setModel(c.afficher_HIS());

                        QMessageBox::information(this,"suppression","The document has been modified");


                    }
                   else
                    {
                        QMessageBox msgBox;
                        QMessageBox::information(this,"suppression","leeee");
                    }
}

void gs_client::on_rechc_clicked()
{
    client Etmp;

    int id=ui->lineRech->text().toInt();
    ui->tablec->setModel(Etmp.recherche(id));
    ui->His->setModel(Etmp.afficher_HIS());


}

void gs_client::on_pushButton_clicked()
{
    client Etmp;
    ui->tablec->setModel(Etmp.afficher());

}

void gs_client::on_radioButton_6_toggled(bool checked)
{
    client Etmp;
  if(checked==true)
  {
      ui->tablec->setModel(Etmp.tri_cin());
      ui->His->setModel(Etmp.afficher_HIS());

  }
  else {
      ui->tablec->setModel(Etmp.afficher());
      }

}

void gs_client::on_radioButton_toggled(bool checked)
{
    client Etmp;
  if(checked==true)
  {
      ui->tablec->setModel(Etmp.tri_nom());
      ui->His->setModel(Etmp.afficher_HIS());

  }
  else {
      ui->tablec->setModel(Etmp.afficher());
      }
}


void gs_client::on_radioButton_2_toggled(bool checked)
{
    client Etmp;
  if(checked==true)
  {
      ui->tablec->setModel(Etmp.tri_prenom());
      ui->His->setModel(Etmp.afficher_HIS());

  }
  else {
      ui->tablec->setModel(Etmp.afficher());
      }
}


void gs_client::on_radioButton_3_toggled(bool checked)
{
    client Etmp;
  if(checked==true)
  {
      ui->tablec->setModel(Etmp.tri_email());
      ui->His->setModel(Etmp.afficher_HIS());

  }
  else {
      ui->tablec->setModel(Etmp.afficher());
      }
}



/*void gs_client::on_ajoutm_clicked()
{

    int cin=ui->cina->text().toInt();
     QString add=ui->emaila->text() ;
     QString password=ui->passa->text() ;

     adresseemail a (cin,add,password);

    if (a.ajouterE())
    {QMessageBox msgBox;


       adresseemail Etmp;
       ui->emailss->setModel(Etmp.afficherE());
       ui->His->setModel(Etmp.afficher_HI());

       QMessageBox::information(this,"ajout","The document has been modified");
      }
    else
    {
        QMessageBox msgBox;
        QMessageBox::information(this,"Ajout","leeee");

    }


}*/

void gs_client::on_pdf_clicked()
{
        QString strStream;
        QTextStream out(&strStream);



        const int rowCount = ui->tablec->model()->rowCount();
        const int columnCount = ui->tablec->model()->columnCount();

        out <<  "<html>\n"
               "<head>\n"

               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
               <<  QString("<title>%60 les postes</title>\n").arg("poste")
              <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"
               "<table border=1 cellspacing=0 cellpadding=2>\n";
               out << "<thead><tr bgcolor=#f0f0f0>";
               for (int column = 0; column < columnCount; column++)
               if (! ui->tablec->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tablec->model()->headerData(column, Qt::Horizontal).toString());
               out << "</tr></thead>\n";

               for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                      if (!ui->tablec->isColumnHidden(column)) {
                       QString data = ui->tablec->model()->data(ui->tablec->model()->index(row, column)).toString().simplified();
                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                          }
                       }
                     out << "</tr>\n";
                       }
                     out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

          QTextDocument *document = new QTextDocument();
                        document->setHtml(strStream);

         QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                       if (dialog->exec() == QDialog::Accepted) {
                            document->print(&printer);
                        }

                        delete document;

                     /*  gs_client * c;
                       c->show();*/

    }


/*void gs_client::on_Supph_clicked()
{
    client c ;

                int num = ui->supphi->text().toInt();
                bool test=c.supprimerh(num);
                    if(test)
                    {
                        ui->His->setModel(c.afficher_HIS());

                        QMessageBox::information(this,"suppression","Historique supprimé");


                    }
                   else
                    {
                        QMessageBox msgBox;
                        QMessageBox::information(this,"suppression","leeee");
                    }
}
*/
