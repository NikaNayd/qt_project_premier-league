#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
class Player
{
public:
    QString name;
    QString team;
    QString nation;
    QString position;
    int minutes;
    int goals;
    int assists;
    bool operator==(const Player& right) const;
    QString getName();
    QString getNation();
    QString getPosition();
    int getMinutes();
    int getGoals();
    int getAssists();
};

#endif // PLAYER_H
