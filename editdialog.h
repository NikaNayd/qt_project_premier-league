#ifndef EDITDIALOG_H
#define EDITDIALOG_H
#include <QValidator>
#include <QDialog>
#include <QMessageBox>
#include <QIntValidator>
#include "teammodel.h"


namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT
    QString nameTeam;
    QString name;
    QString nation;
    QString position;
    int minutes;
    int goals;
    int assists;
    QWidget *myparent;


public:
    explicit EditDialog(QString nameTeam,     QString name,
                        QString nation,
                        QString position,
                        int minutes,
                        int goals,
                        int assists, QWidget *parent = nullptr);

    ~EditDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditDialog *ui;
    QIntValidator intvalid;
};

#endif // EDITDIALOG_H
