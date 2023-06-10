#include "dialogadd.h"
#include "ui_dialogadd.h"


dialogAdd::dialogAdd(QString teamName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAdd), intvalid(0, 200, this)
{
    this->myparent = parent;
    this->teamName = teamName;
    ui->setupUi(this);
}

dialogAdd::~dialogAdd()
{
    delete ui;
}

void dialogAdd::on_buttonAdd_clicked()
{
    QString name = ui->editName->text();
    QString nation = ui->editNation->text();
    QString position = ui->editPosition->text();
    QString goals = ui->editGoals->text();
    int begin = 0;
    QValidator::State check = intvalid.validate(goals, begin);
    if (check == 0)
    {
        QMessageBox *mess = new QMessageBox();
        mess->setText("Invalid input");
        mess->show();
        return;
    }
    QString assists = ui->editAssists->text();
    QFile file("C:\\Users\\inaydenova\\Documents\\untitled5\\footbal.csv");
    if (!file.open(QIODevice::Append))
    {
        QMessageBox::information(0, "error", file.errorString());
    }
    QString newStr = name+','+this->teamName+ ','+nation+','+position+','+','+','+','+','+','+goals+','+ assists+"\n";
    file.write(newStr.toUtf8());
    file.close();
    myparent->close();
    this->close();
}

