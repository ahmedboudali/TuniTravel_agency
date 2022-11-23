#ifndef GS_EMPLOYEE_H
#define GS_EMPLOYEE_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "employee.h"
#include "ajouter_task.h"
#include "supprimer_task.h"
#include "modifier_task.h"



#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QBarSet>
#include <QChartView>
#include <QtWidgets>




namespace Ui {
class gs_employee;
}

class gs_employee : public QDialog
{
    Q_OBJECT

public:
    explicit gs_employee(QWidget *parent = nullptr);
    ~gs_employee();

private slots:

    void on_pushButton_ajouter_e_clicked();
     void on_pushButton_supprimer_e_clicked();

     void on_pushButton_modifier_e_clicked();

     //void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     //void on_radioButton_trinom_e_clicked();

     void on_radioButton_trinom_e_toggled(bool checked);

     void on_radioButton_trisalaire_e_toggled(bool checked);

     void on_radioButton_triheure_e_toggled(bool checked);

     void on_pushButton_modifier_metier_clicked();

    // void on_pushButton_ajoutertask_e_clicked();

    // void on_pushButton_5_clicked();

    // void on_pushButton_ajoutertask_e_3_clicked();


    // void on_pushButton_modifiertask_e_clicked();


     void on_pushButton_3_clicked();

     void on_lineEdit_idrecherche_e_textEdited(const QString &arg1);

    // void on_lineEdit_idrecherche_e_textChanged(const QString &arg1);

     //void on_lineEdit_idrecherche_e_editingFinished();

     void on_pushButton_ajoutertask_e_2_clicked();

     void on_pushButton_supprimer_e_2_clicked();

     void on_pushButton_modifier_e_2_clicked();

    // void on_pushButton_chart_clicked();

   //  void on_lineEdit_idrecherchetodo_e_textEdited(const QString &arg1);

    // void on_lineEdit_idrecherche_e_cursorPositionChanged(int arg1, int arg2);


    // void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
     // ce slot est lancé à chaque réception d'un message de Arduino

private:

    Ui::gs_employee *ui;
    employee Etmp,E;
    
    ajouter_task *Ajouter_task;
    supprimer_task *Supprimer_task;
    modifier_task *Modifier_task;
    QMessageBox *msgBox;

    gs_employee *Gs_employee;

};




#endif // GS_EMPLOYEE_H


