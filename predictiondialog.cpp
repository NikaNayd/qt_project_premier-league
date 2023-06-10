#include "predictiondialog.h"
#include "teammodel.h"
#include "ui_predictiondialog.h"

predictionDialog::predictionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::predictionDialog)
{
    ui->setupUi(this);
}

predictionDialog::~predictionDialog()
{
    delete ui;
}

void predictionDialog::on_pushButton_clicked()
{
    QString team1 =ui->team1->currentText();
    QString team2 =ui->team1->currentText();
    TeamModel *model = new TeamModel();
    QString result = model->calculateChance(team1, team2);
    QMessageBox *msg = new QMessageBox();
    msg->setText(result);
    msg->show();

}

