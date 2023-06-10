#ifndef TEAMSMODEL_H
#define TEAMSMODEL_H
#include <QAbstractTableModel>
#include <QFile>
#include <QMessageBox>
#include "Team.h"
#include "Player.h"
#include <string>
#include <vector>
#include <sstream>

class TeamsModel : public QAbstractTableModel
{
    Q_OBJECT
protected:
    std::vector<Team> teams;
    std::vector<Player> players;
    std::vector<QString> custom_headers;

public:
    explicit TeamsModel(QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const override;
    void parseLinesToTeams(QFile& fs);
    void sortByName();
    void sortByNumb();
    void sortByGoals();
    void sortByLeader();
    QString getTeamName(const QModelIndex& index);
};

#endif // TEAMSMODEL_H
