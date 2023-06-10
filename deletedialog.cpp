#include "deletedialog.h"
#include "ui_deletedialog.h"

deleteDialog::deleteDialog(QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteDialog)
{
    this->name = name;
    ui->setupUi(this);
    ui->label_question->setText("Do you want to delete "+name + "?");
}

deleteDialog::~deleteDialog()
{
    delete ui;
}
