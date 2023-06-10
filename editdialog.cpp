#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QString nameTeam,     QString name,
                       QString nation,
                       QString position,
                       int minutes,
                       int goals,
                       int assists, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    this->nameTeam= nameTeam;
    this->name = name;
    this->nation = nation;
    this->position = position;
    this->minutes = minutes;
    this->goals = goals;
    this->assists = assists;
    ui->editName->setText(name);
    ui->editnation->setText(nation);
    ui->editPosition->setText(position);
    ui->editGoals->setText(QString::number(goals));
    ui->editAssists->setText(QString::number(assists));
    myparent = parent;



}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::on_pushButton_clicked()
{
    QString name = ui->editName->text();
    QString nation = ui->editnation->text();
    QString position = ui->editPosition->text();
    QString goals = ui->editGoals->text();
    int begin = 0;
    if (intvalid.validate(goals, begin)==0)
    {
        QMessageBox *msg = new QMessageBox();
        msg->setText("Invalid input");
        msg->show();
    }
    QString assists = ui->editAssists->text();
    if (intvalid.validate(assists, begin)==0)
    {
        QMessageBox *msg = new QMessageBox();
        msg->setText("Invalid input");
        msg->show();
    }
    TeamModel *model = new TeamModel();
    model->updateFile(nameTeam, name, nation,  position,  goals.toInt(),  assists.toInt());
    myparent->close();
    this->close();
}


void EditDialog::on_pushButton_2_clicked()
{
    this->close();
}

