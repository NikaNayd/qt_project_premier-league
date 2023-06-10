#include "teammodel.h"


TeamModel::TeamModel(QObject* parent):QAbstractTableModel(parent)
{
    our_headers = {"Name", "Nation", "Position", "Minutes", "Goals", "Assists"};
}
void TeamModel::setName(QString name){
    this->name=name;
    QFile file(nameFile);
    this->parseLinesToPlayers(file);
}
void TeamModel::parseLinesToPlayers(QFile& file)
{
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream in(&file);
    int i = 0;
    while(!in.atEnd()) {
        i++;
        QString line = in.readLine();
        if (i == 1){
            continue;
        }

        QStringList fields = line.split(",");
        Player newPlayer = Player();
        newPlayer.name = fields.at(0);
        newPlayer.team = fields.at(1);
        if (newPlayer.team==name)
        {
            newPlayer.nation = fields.at(2);

            newPlayer.position = fields.at(3);
            newPlayer.minutes = fields.at(7).toInt();
            newPlayer.goals = fields.at(9).toInt();
            newPlayer.assists = fields.at(10).toInt();
            players.push_back(newPlayer);
        }
    }
    file.close();
}
int TeamModel::rowCount(const QModelIndex& parent ) const{
    return players.size();
}
int TeamModel::columnCount(const QModelIndex& parent ) const {
    return 6;
}
QVariant TeamModel::data(const QModelIndex& index, int role) const {
    if (role == Qt::DisplayRole)
    {

        int indexRow=index.row();
        int indexColumn=index.column();
        Player currPlayer=players.at(indexRow);
        QString data = "";
        if (indexColumn == 0) {
            data = currPlayer.name;
        }
        else if (indexColumn == 1) {
            data = currPlayer.nation;
        }
        else if (indexColumn == 2) {
            data = currPlayer.position;
        }
        else if (indexColumn == 3) {
            data = QString::number(currPlayer.minutes);
        }
        else if (indexColumn == 4) {
            data = QString::number(currPlayer.goals);
        }
        else if (indexColumn == 5) {
            data = QString::number(currPlayer.assists);
        }
        return data
            .arg(index.row()+1)
            .arg(index.column()+1);
    }
    return QVariant();
}

QVariant TeamModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation != Qt::Horizontal || section > columnCount())
        return QVariant();
    if (role == Qt::DisplayRole)
        return our_headers.at(section);
    if (role == Qt::BackgroundRole)
        return QBrush(Qt::red);
    return QVariant();
}
bool cmpByName(Player player1, Player player2)
{
    return player1.getName()<player2.getName();
}
void TeamModel::sortByName(){
    std::sort(players.begin(), players.end(), cmpByName);
}
bool cmpByNation(Player player1, Player player2)
{
    return player1.getNation()<player2.getNation();
}
void TeamModel::sortByNation(){
    std::sort(players.begin(), players.end(), cmpByNation);
}
bool cmpByPosition(Player player1, Player player2)
{
    return player1.getPosition()<player2.getPosition();
}
void TeamModel::sortByPosition(){
    std::sort(players.begin(), players.end(), cmpByPosition);
}
bool cmpByMinutes(Player player1, Player player2)
{
    return player1.getMinutes()<player2.getMinutes();
}
void TeamModel::sortByMinutes(){
    std::sort(players.begin(), players.end(), cmpByMinutes);
}
bool cmpByGoals(Player player1, Player player2)
{
    return player1.getGoals()<player2.getGoals();
}
void TeamModel::sortByGoals(){
    std::sort(players.begin(), players.end(), cmpByGoals);
}
bool cmpByAssists(Player player1, Player player2)
{
    return player1.getAssists()<player2.getAssists();
}
void TeamModel::sortByAssists(){
    std::sort(players.begin(), players.end(), cmpByAssists);
}

QString TeamModel::findNameById(int id)
{
    return players.at(id).getName();
}

void TeamModel::deleteSelectedPlayers(std::vector<QString> names)
{
    QFile file(nameFile);
    if (file.open(QIODevice::ReadWrite))
    {
        QString str;
        QTextStream textStream(&file);
        while(!textStream.atEnd())
        {
            bool flagDelete = false;

            QString line = textStream.readLine();
            for (int i = 0; i<names.size(); ++i)
            {
                if (line.contains(names.at(i)))
                {
                    QMessageBox *ms = new QMessageBox();
                    ms->setText(names.at(i));
                    //ms->show();

                    flagDelete = true;
                }

            }
            if (!flagDelete)
            {
                str.append(line +"\n");

            }

        }
        file.resize(0);
        textStream << str;
        file.close();

    }

}

Player TeamModel::getPlayerById(int newid)
{
    return players.at(newid);
}

void TeamModel::updateFile(QString nameTeam, QString name, QString nation, QString position, int goals, int assists)
{
    QFile file(nameFile);
    if (file.open(QIODevice::ReadWrite))
    {
        QString str;
        QTextStream textStream(&file);
        int index=0;
        QString newStr = name+','+nameTeam+ ','+nation+','+position+','+','+','+','+','+','+QString::number(goals)+','+QString::number(assists)+"\n";
        while(!textStream.atEnd())
        {
            QString line = textStream.readLine();
            if (line.contains(name) && line.contains(nameTeam))
            {
                str.append(newStr);
            }
            else
            {
                str.append(line+"\n");

            }
        }
        file.resize(0);
        textStream << str;
        file.close();

    }

}

QString TeamModel:: calculateChance(QString team1, QString team2)
{
    QFile file(nameFile);

    int sum1 = 0;
    int sum2 = 0;
    QString output;

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    int i = 0;
    while(!in.atEnd()) {
        i++;
        QString line = in.readLine();
        if (i == 1){
            continue;
        }

        if (line.contains(team1))
        {

            QStringList fields1 = line.split(",");
            sum1+=fields1.at(9).toInt();
        }
        if (line.contains(team2)){
            QStringList fields2 = line.split(",");
            sum1+=fields2.at(9).toInt();
        }
        }
        QMessageBox *m1 = new QMessageBox();
        m1->setText(QString::number(sum1));
        m1->show();
        QMessageBox *m2 = new QMessageBox();
        m2->setText(QString::number(sum2));
        m2->show();
        file.close();
        if (sum1>sum2)
        {
            if (sum2==0){
                double percent=100;
                output = "Team '"+team1+"' will win with probability of"+QString::number(percent)+"%.";
            }
            else if(sum1==0)
            {
                double percent = 0;
                output = "Team '"+team1+"' will win with probability of"+QString::number(percent)+"%.";

            }
            else{
                double percent=(sum2*100)/sum1;
                output = "Team '"+team1+"' will win with probability of"+QString::number(percent)+"%.";
            }
        }
        else if (sum1<=sum2)
        {
            if (sum1==sum2){
                double percent = 50;
                output = "Team '"+team2+"' will win with probability of"+QString::number(percent)+"%.";

            }
            else if (sum1==0){
                double percent=100;
                output = "Team '"+team2+"' will win with probability of"+QString::number(percent)+"%.";
            }
            else if(sum2==0){
                double percent = 100;
                output = "Team '"+team2+"' will win with probability of"+QString::number(percent)+"%.";

            }
            else{
                double percent=(sum1*100)/sum2;
                output = "Team '"+team2+"' will win with probability of"+QString::number(percent)+"%.";
            }
        }
        return output;
}




