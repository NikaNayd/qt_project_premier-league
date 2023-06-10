#include "teamsmodel.h"

TeamsModel::TeamsModel(QObject* parent):QAbstractTableModel(parent)
{
    QFile file("C:\\Users\\inaydenova\\Documents\\untitled5\\footbal.csv");
    this->parseLinesToTeams(file);
    custom_headers.push_back("Name");
    custom_headers.push_back("Number of players");
    custom_headers.push_back("Goals");
    custom_headers.push_back("Leader");
}


void TeamsModel::parseLinesToTeams(QFile& file)
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
        newPlayer.nation = fields.at(2);
        newPlayer.position = fields.at(3);
        newPlayer.minutes = fields.at(7).toInt();
        newPlayer.goals = fields.at(9).toInt();
        newPlayer.assists = fields.at(10).toInt();
        players.push_back(newPlayer);
    }
    file.close();
    for(int i = 0; i < players.size(); i++) {
        int currentGoals = players.at(i).goals;
        QString currentPlayerName = players.at(i).name;
        Team team = Team();
        team.setName(players.at(i).team);
        auto element = std::find(teams.begin(), teams.end(), team);

        if (element != teams.end()) {
            element->incrementCount();
            element->addGoals(currentGoals);
            if (element->getGoalLeader() < currentGoals) {
                element->setLeader(currentPlayerName);
            }
        }
        else {
            Team newTeam = Team();
            newTeam.setName(players.at(i).team);
            newTeam.incrementCount();
            newTeam.addGoals(currentGoals);
            newTeam.setGoalLeader(currentGoals);
            newTeam.setLeader(currentPlayerName);
            teams.push_back(newTeam);
        }
    }
}

int TeamsModel::rowCount(const QModelIndex& parent ) const{
    return teams.size();
}
int TeamsModel::columnCount(const QModelIndex& parent ) const {
    return 4;
}
QVariant TeamsModel::data(const QModelIndex& index, int role) const {
    if (role == Qt::DisplayRole)
    {

        int indexRow=index.row();
        int indexColumn=index.column();
        Team currTeam=teams.at(indexRow);
        QString data = "";
        if (indexColumn == 0) {
            data = currTeam.getName();
        }
        else if (indexColumn == 1) {
            data = QString::number(currTeam.getCount());
        }
        else if (indexColumn == 2) {
            data = QString::number(currTeam.getGoals());
        }
        else if (indexColumn == 3) {
            data = currTeam.getLeader();
        }
        return data
            .arg(index.row()+1)
            .arg(index.column()+1);
    }
    return QVariant();
}

QVariant TeamsModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation != Qt::Horizontal || section > columnCount())
        return QVariant();
    if (role == Qt::DisplayRole)
        return custom_headers.at(section);
    if (role == Qt::BackgroundRole)
        return QBrush(Qt::red);
    return QVariant();
}
bool cmpByName(Team team1, Team team2)
{
    return team1.getName()<team2.getName();
}
bool cmpByNumbPlayers(Team team1, Team team2)
{
    return team1.getCount() >team2.getCount();
}
bool cmpByGoals(Team team1, Team team2)
{
    return team1.getGoals() >team2.getGoals();
}
bool cmpByLeader(Team team1, Team team2)
{
    return team1.getLeader()<team2.getLeader();
}
void TeamsModel::sortByName(){
    std::sort(teams.begin(), teams.end(), cmpByName);
}
void TeamsModel::sortByNumb(){
    std::sort(teams.begin(), teams.end(), cmpByNumbPlayers);

}
void TeamsModel::sortByGoals(){
    std::sort(teams.begin(), teams.end(), cmpByGoals);

}
void TeamsModel::sortByLeader(){
    std::sort(teams.begin(), teams.end(), cmpByLeader);

}
QString TeamsModel::getTeamName(const QModelIndex& index){
        int row = index.row();
    return teams.at(row).getName();
    }

