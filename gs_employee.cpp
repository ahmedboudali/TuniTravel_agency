
#include "ui_gs_employee.h"

#include <QMessageBox>
#include "login.h"

#include "gs_employee.h"

#include "employee.h"

#include"todolist_e.h"

//*************
#include <QIntValidator>
#include <QTextStream>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>

//********


//************************************
gs_employee::gs_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_employee)
{
    ui->setupUi(this);
  // supprimer_task s;
    QPixmap pix("C:/Users/dell/Documents/NOTION/2eme année (2-A-27)/subjects/Projet C++/uni-removebg-preview");                  //el taswira eli bich t7otha fil login.ui (pt2.)
    ui->label_signin_pic->setPixmap(pix.scaled(50,50,Qt::KeepAspectRatio));                                                      //el taswira eli bich t7otha fil login.ui (pt3.)

    ui->tab_employee->setModel(Etmp.afficher());                                                                                    //Affichage de liste des employee
    ui->tab_employee_2->setModel(Etmp.afficher_task());
   //

///
    todolist_e e;
    float nbreT=e.nbre_totale();
    float  nbreTP=e.nbre_totalep();
    float nbreTD=e.nbre_totaled();

    ui->label_statusp_e->setNum((nbreTP*100)/nbreT);
    ui->label_statusd_e->setNum((nbreTD*100)/nbreT);
    ui->label_statust_e->setNum(nbreT);



    //*********************


}

//***********************************


gs_employee::~gs_employee()
{
    delete ui;
}


//************************************

void gs_employee::on_pushButton_ajouter_e_clicked()
{

    //Récuperation des information saisies dans les champs
    QString nom=ui->lineEdit_nom_e->text();
    QString prenom=ui->lineEdit_prenom_e->text();
    int cin=ui->lineEdit_cin_e->text().toInt();
    int id=ui->lineEdit_id_e->text().toInt();
    QString motpass=ui->lineEdit_motpass_e->text();
    int salaire=ui->lineEdit_salaire_e->text().toInt();
    int tel=ui->lineEdit_numerotel_e->text().toInt();
    int heure=ui->lineEdit_heure_e->text().toInt();

    employee E(nom,prenom,cin,id,motpass,tel,salaire,heure);

   msgBox= new QMessageBox(this);
    if(E.ajouter())
    {


         msgBox->setText("effectué");
           ui->lineEdit_nom_e->clear();
           ui->lineEdit_prenom_e->clear();
           ui->lineEdit_cin_e->clear();
           ui->lineEdit_id_e->clear();
           ui->lineEdit_motpass_e->clear();
           ui->lineEdit_salaire_e->clear();
           ui->lineEdit_numerotel_e->clear();
           ui->lineEdit_heure_e->clear();

         ui->tab_employee->setModel(Etmp.afficher());

         msgBox->show();

    }
    else
   {

     msgBox->setText("non effectué");
     msgBox->show();
    }
}
//************************************
void gs_employee::on_pushButton_supprimer_e_clicked()
{
    employee E; E.setId(ui->lineEdit_idsupp_e->text().toInt());
    bool test=E.supprimer(E.getId());
    msgBox= new QMessageBox(this);
    if(test)
    {

        msgBox->setText("effectué");
        ui->lineEdit_idsupp_e->clear();
        ui->tab_employee->setModel(Etmp.afficher());
         msgBox->show();
     }
    else
        msgBox->setText("non effectué");
        msgBox->show();
}
//************************************


void gs_employee::on_pushButton_modifier_e_clicked()
{
    int id=ui->lineEdit_idmod_e->text().toInt();
    QString nom=ui->lineEdit_nommod_e->text();
    QString prenom=ui->lineEdit_prenommod_e->text();
    int cin=ui->lineEdit_cinmod_e->text().toInt();
    int salaire=ui->lineEdit_salairemod_e->text().toInt();
    int tel=ui->lineEdit_numerotelmod_e->text().toInt();
    int heure=ui->lineEdit_heuremod_e->text().toInt();

 //   QString motpass=ui->lineEdit_motpassmod_e->text();


    employee E(nom,prenom,cin,tel,salaire,heure);


            msgBox= new QMessageBox(this);
            bool test=E.modifier(id);
            if(test)
            {
                ui->lineEdit_idmod_e->clear();
                 ui->lineEdit_nommod_e->clear();
                  ui->lineEdit_prenommod_e->clear();
                ui->lineEdit_cinmod_e->clear();
                ui->lineEdit_salairemod_e->clear();
              ui->lineEdit_numerotelmod_e->clear();
          ui->lineEdit_heuremod_e->clear();

                ui->tab_employee->setModel(Etmp.afficher());
                msgBox->setText("effectué");
                msgBox->show();
              }
            else
            {

            msgBox->setText("non effectué");
            msgBox->show();
            }

}
//************************************
/*void gs_employee::on_pushButton_clicked()    //rechercher
{
    int id=ui->lineEdit_idrecherche_e->text().toInt();

    ui->tab_employee->setModel(Etmp.recherche(id));

}*/
//************************************
void gs_employee::on_pushButton_2_clicked()  //button pour actualiser la liste apres rechercher
{
      ui->tab_employee->setModel(Etmp.afficher());
}

//************************************
void gs_employee::on_radioButton_trinom_e_toggled(bool checked)  //button radio  pour actualiser la liste apres rechercher ( ki tinzel 3ala "aller au slaut"-->"toggled" moch "clicked)
{
    employee Etmp;
    if(checked==true)
    {
        ui->tab_employee->setModel(Etmp.tri_nom());
    }
    else {
        ui->tab_employee->setModel(Etmp.afficher());
        }
}
//************************************
void gs_employee::on_radioButton_trisalaire_e_toggled(bool checked)
{
    employee Etmp;
    if(checked==true)
    {
        ui->tab_employee->setModel(Etmp.tri_salaire());
    }

     else {
              ui->tab_employee->setModel(Etmp.afficher());
        }
}
//************************************
void gs_employee::on_radioButton_triheure_e_toggled(bool checked)
{
      employee Etmp;
    if(checked==true)
    {
     ui->tab_employee->setModel(Etmp.tri_heure());
    }

        else
    {
        ui->tab_employee->setModel(Etmp.afficher());
        }
}
//************************************
void gs_employee::on_pushButton_modifier_metier_clicked()
{

    int id=ui->lineEdit_idmetier1_e->text().toInt();
    QString motpass=ui->lineEdit_motpassa_e->text();
    QString motpassn=ui->lineEdit_motpassn_e->text();
    QString motpassnv=ui->lineEdit_motpassnv_e->text();

    employee E(motpass);

   msgBox= new QMessageBox(this);
    if(motpassn==motpassnv)
    {

        if(E.modifier_mot_passe(id,motpass,motpassn))
        {
         msgBox->setText("effectué");
         msgBox->show();
        }
        else
        {
            msgBox->setText("non effectué");
            msgBox->show();
        }

    }
    else
   {
    msgBox->setText("verifier votre JDID mot de passe !");
    msgBox->show();
    }

}
//************************************

/*

void gs_employee::on_pushButton_ajoutertask_e_3_clicked()
{
    todolist_e e;


    int nbreT=e.nbre_totale(); //Hedha
    int nbreTP=e.nbre_totalep();
    int nbreTD=e.nbre_totaled();
    ui->tab_employee_2->setModel(Etmp.afficher_task());


    ui->label_statusp_e->setNum((nbreTP*100)/nbreT);
    ui->label_statusd_e->setNum((nbreTD*100)/nbreT);
    ui->label_statust_e->setNum(nbreT);


}
*/
/*
void gs_employee::on_pushButton_modifiertask_e_clicked()
{

}
*/





void gs_employee::on_pushButton_3_clicked()
{
           QString strStream;
            QTextStream out(&strStream);


            const int rowCount = ui->tab_employee->model()->rowCount();
            const int columnCount = ui->tab_employee->model()->columnCount();


            out <<  "<html>\n"
                   "<head>\n"

                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                   <<  QString("<title>%60 les postes</title>\n").arg("poste")
                  <<  "</head>\n"
                   "<body bgcolor=#ffffff link=#5000A0>\n"
                   "<table border=1 cellspacing=0 cellpadding=2>\n";
                   out << "<thead><tr bgcolor=#f0f0f0>";
                   for (int column = 0; column < columnCount; column++)
                   if (! ui->tab_employee->isColumnHidden(column))
                   out << QString("<th>%1</th>").arg(ui->tab_employee->model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";

                   for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                          if (!ui->tab_employee->isColumnHidden(column)) {
                           QString data = ui->tab_employee->model()->data(ui->tab_employee->model()->index(row, column)).toString().simplified();
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
                           if (dialog->exec() == QDialog::Accepted)
                           {

                                document->print(&printer);
                                Gs_employee = new gs_employee(this);
                                Gs_employee->show();
                            }
                            delete document;

}





void gs_employee::on_lineEdit_idrecherche_e_textEdited(const QString &arg1)
{

    QString id=ui->lineEdit_idrecherche_e->text();

    ui->tab_employee->setModel(Etmp.recherche(id));
    if (id=="")
    {
        ui->tab_employee->setModel(Etmp.afficher());

    }

}

void gs_employee::on_pushButton_ajoutertask_e_2_clicked()
{
    int id_task=ui->lineEdit_id_task->text().toUInt();
     QString employee_task=ui->lineEdit_employee_task->text();
     QString etat_task=ui->comboBox_etatajout->currentText();
     QString task=ui->lineEdit_task->text();
     todolist_e t(id_task,employee_task,task,etat_task);

    // gs_employee e;
     msgBox= new QMessageBox(this);
      if(t.ajouter_task())
      {


           msgBox->setText("effectué");
   // ui->tab_employee->setModel(Etmp.afficher_task());
           msgBox->show();


           todolist_e e;


           int nbreT=e.nbre_totale(); //Hedha
           int nbreTP=e.nbre_totalep();
           int nbreTD=e.nbre_totaled();
           ui->tab_employee_2->setModel(Etmp.afficher_task());


           ui->label_statusp_e->setNum((nbreTP*100)/nbreT);
           ui->label_statusd_e->setNum((nbreTD*100)/nbreT);
           ui->label_statust_e->setNum(nbreT);



      }
      else
     {

       msgBox->setText("non effectué");
       msgBox->show();
      }

}

void gs_employee::on_pushButton_supprimer_e_2_clicked()
{

    //SUpprimer
    todolist_e E;
    E.setId_task(ui->lineEdit_idsupptask_e->text().toInt());
    bool test=E.supprimer_task(E.getId_task());
    msgBox= new QMessageBox(this);
    if(test)
    {

        msgBox->setText("effectué");
        msgBox->show();


        todolist_e e;


        int nbreT=e.nbre_totale(); //Hedha
        int nbreTP=e.nbre_totalep();
        int nbreTD=e.nbre_totaled();
        ui->tab_employee_2->setModel(Etmp.afficher_task());


        ui->label_statusp_e->setNum((nbreTP*100)/nbreT);
        ui->label_statusd_e->setNum((nbreTD*100)/nbreT);
        ui->label_statust_e->setNum(nbreT);


     }
    else
    {
        msgBox->setText("non effectué");
        msgBox->show();
    }

}

void gs_employee::on_pushButton_modifier_e_2_clicked()
{
    int id=ui->lineEdit_idmodtask2_e->text().toInt();
    QString etat=ui->comboBox_e->currentText();

    todolist_e e(etat);


    msgBox= new QMessageBox(this);
    bool test=e.modifier_task(id);
    if(test)
    {

       // ui->tab_employee->setModel(Etmp.afficher());
        msgBox->setText("effectué");
        msgBox->show();

        todolist_e e;


        int nbreT=e.nbre_totale(); //Hedha
        int nbreTP=e.nbre_totalep();
        int nbreTD=e.nbre_totaled();
        ui->tab_employee_2->setModel(Etmp.afficher_task());


        ui->label_statusp_e->setNum((nbreTP*100)/nbreT);
        ui->label_statusd_e->setNum((nbreTD*100)/nbreT);
        ui->label_statust_e->setNum(nbreT);


      }
    else
    {

    msgBox->setText("non effectué");
    msgBox->show();
    }
}


/*void gs_employee::on_lineEdit_idrecherchetodo_e_textEdited(const QString &arg1)
{
    int id=ui->lineEdit_idrecherche_e->text().toInt();
    ui->tab_employee->setModel(Etmp.recherche(id));
    if (id==NULL)
    {
        ui->tab_employee->setModel(Etmp.afficher());

    }

}*/
