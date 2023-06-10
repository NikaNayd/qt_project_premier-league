#ifndef TEAMMODEL_H
#define TEAMMODEL_H
#include <QAbstractTableModel>
#include <QFile>
#include <QMessageBox>
#include "Player.h"
#include "Team.h"
#include <string>
#include <vector>
#include <sstream>

class TeamModel : public QAbstractTableModel
{
    Q_OBJECT
protected:
    std::vector<Player> players;
public:
    explicit TeamModel(QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const override;
    void setName(QString name);
    void sortByName();
    void sortByNation();
    void sortByPosition();
    void sortByMinutes();
    void sortByGoals();
    void sortByAssists();
    QString findNameById(int id);
    void deleteSelectedPlayers(std::vector<QString> names);
    Player getPlayerById(int newid);
    void updateFile(QString nameTeam, QString name, QString nation, QString position, int goals, int assists );

    QString calculateChance(QString team1, QString team2);
private:
    QString name;
    std::vector<QString> our_headers;
    void parseLinesToPlayers(QFile& fs);
    QString nameFile = "C:\\Users\\inaydenova\\Documents\\untitled5\\footbal.csv";
};

#endif // TEAMMODEL_H
