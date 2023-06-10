#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    logotype = new draw(ui->container_widget);
    ui->logo_layout->addWidget(logotype);
}

Dialog::~Dialog()
{
    delete ui;
}
