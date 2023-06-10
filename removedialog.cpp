#include "removedialog.h"
#include "ui_removedialog.h"

removeDialog::removeDialog(QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeDialog)
{
    this->name = name;
    ui->setupUi(this);
    ui->label_question->setText("Do you want to delete "+name + "?");
}

removeDialog::~removeDialog()
{
    delete ui;
}
