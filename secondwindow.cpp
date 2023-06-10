#include "secondwindow.h"
#include "ui_secondwindow.h"

secondwindow::secondwindow(QString name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);

    this->name= name;
    ui->label_name_team->setText(name);

    renderTable();
    QList<QString> comboBoxList;
    comboBoxList.append("Name");
    comboBoxList.append("Nation");
    comboBoxList.append("Position");
    comboBoxList.append("Minutes");
    comboBoxList.append("Goals");
    comboBoxList.append("Assists");
    ui->comboBox->addItems(comboBoxList);
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::renderTable()
{
    model = new TeamModel();
    model->setName(name);
    ui->table_team->setModel(model);
}

void secondwindow::dialog_delete_finished(int code)
{

    if (code==QDialog::Accepted){
        QItemSelectionModel *select = ui->table_team->selectionModel();

        if (select->hasSelection()){
            std::vector<QString> namesDelete;

            QModelIndexList selectedRows = select->selection().indexes();
            for(int i =0; i<selectedRows.count(); ++i)
            {
                namesDelete.push_back(model->findNameById(selectedRows.at(i).row()));
            }
            model->deleteSelectedPlayers(namesDelete);
            this->close();
        }

    }

}



void secondwindow::on_button_add_clicked()
{
    dialogAdd *dialog = new dialogAdd(this->name, this); //this - parent of dialogWindow
    dialog->exec();
}


void secondwindow::on_comboBox_currentIndexChanged(int index)
{
    if (index==0)
    {

        ui->table_team->reset();
        model->sortByName();
        ui->table_team->setModel(model);
    }
    if (index==1)
    {

        ui->table_team->reset();
        model->sortByNation();
        ui->table_team->setModel(model);
    }
    if (index==2)
    {

        ui->table_team->reset();
        model->sortByPosition();
        ui->table_team->setModel(model);
    }
    if (index==3)
    {

        ui->table_team->reset();
        model->sortByNation();
        ui->table_team->setModel(model);
    }
    if (index==4)
    {

        ui->table_team->reset();
        model->sortByMinutes();
        ui->table_team->setModel(model);
    }
    if (index==5)
    {

        ui->table_team->reset();
        model->sortByGoals();
        ui->table_team->setModel(model);
    }
    if (index==6)
    {

        ui->table_team->reset();
        model->sortByAssists();
        ui->table_team->setModel(model);
    }





}


void secondwindow::on_button_delete_clicked()
{
    deleteDialog *dialogdel = new deleteDialog("player(s)");
    QObject::connect(dialogdel, SIGNAL(finished(int)), this, SLOT(dialog_delete_finished(int)));
    dialogdel->exec();
}


void secondwindow::on_table_team_doubleClicked(const QModelIndex &index)
{
    int myindex=index.row();
    Player thisPlayer = model->getPlayerById(myindex);
    QString name = thisPlayer.getName();
    QString nation = thisPlayer.getNation();
    QString position = thisPlayer.getPosition();
    int minutes = thisPlayer.getMinutes();
    int goals = thisPlayer.getGoals();
    int assists = thisPlayer.getAssists();
    EditDialog *dialogEdit = new EditDialog(this->name, name, nation, position, minutes, goals, assists, this);
    dialogEdit->exec();
}




