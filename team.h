#ifndef TEAM_H
#define TEAM_H
#include <QString>

class Team
{
    QString name;
    int count;
    int goals;
    QString leader;
    int goalLeader;
public:
    Team();
    bool operator==(const Team& right) const;
    void incrementCount() {
        count++;
    }
    void decrementCount() {
        count--;
    }
    void addGoals(int goals) {
        this->goals += goals;
    }
    int getGoalLeader(){
        return goalLeader;
    }
    void setLeader(QString leader){
        this->leader = leader;
    }
    void setName(QString name) {
        this->name = name;
    }
    int getCount() {
        return count;
    }
    int getGoals() {
        return goals;
    }
    void setGoalLeader(int goal) {
        this->goalLeader = goal;
    }
    QString getName() {
        return name;
    }
    QString getLeader() {
        return leader;
    }
};

#endif // TEAM_H
