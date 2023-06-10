#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    teamsModel=new TeamsModel();
    ui->playerTableView->setModel(teamsModel);
    QString style = R"(
                QScrollBar:vertical {
                 background: black;
                }
                QScrollBar:horizontal {
                 background: black;
                }
                QTableView { alternate-background-color: white; background-color: #D9D9D9; }
                QTableView::item:selected { background: black; color: white; }
               )";
    ui->playerTableView->setStyleSheet(style);

    for (int i = 0; i < 4; i++) {
            ui->playerTableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }
    //here

    ui->label->setStyleSheet("QLabel { background-color : #D9D9D9; }");
    QList<QString> comboBoxList;
    comboBoxList.append("Name");
    comboBoxList.append("Number of players");
    comboBoxList.append("Goals");
    comboBoxList.append("Leader");
    ui->comboBox->addItems(comboBoxList);
    QList<QString> combolanguage;
    combolanguage.append("English");
    combolanguage.append("Russian");
    ui->choose_lang->addItems(combolanguage);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index==0)
    {
            ui->playerTableView->reset();
            teamsModel->sortByName();
            ui->playerTableView->setModel(teamsModel);

    }
    else if (index==1)
    {
            ui->playerTableView->reset();
            teamsModel->sortByNumb();
            ui->playerTableView->setModel(teamsModel);
    }
    else if (index==2)
    {
            ui->playerTableView->reset();
            teamsModel->sortByGoals();
            ui->playerTableView->setModel(teamsModel);
    }
    else if (index==3)
    {
            ui->playerTableView->reset();
            teamsModel->sortByLeader();
            ui->playerTableView->setModel(teamsModel);
    }
}


void MainWindow::on_playerTableView_doubleClicked(const QModelIndex &index)
{
    QString name = teamsModel->getTeamName(index);
    secondwindow* currTeam= new secondwindow(name);
    currTeam->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog *dialogAbout= new Dialog();
    dialogAbout->exec();
}



void MainWindow::on_pushButton_3_clicked()
{
    predictionDialog *dlg = new predictionDialog();
    dlg->exec();
}

