#ifndef GS_CLIENT_H
#define GS_CLIENT_H
#include <QSqlQueryModel>
#include <QDialog>

namespace Ui {
class gs_client;
}

class gs_client : public QDialog
{
    Q_OBJECT

public:
    explicit gs_client(QWidget *parent = nullptr);
    ~gs_client();


private slots:
    void on_Ajouterc_clicked();

    void on_update_clicked();

    void on_suppc_clicked();

    void on_rechc_clicked();

    void on_pushButton_clicked();

    void on_radioButton_6_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

   // void on_ajoutm_clicked();

    void on_pdf_clicked();

    //void on_Supph_clicked();

private:
    Ui::gs_client *ui;

     gs_client *GS_client;
};

#endif // GS_CLIENT_H
