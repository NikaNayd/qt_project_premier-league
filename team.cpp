#include "team.h"

Team::Team()
{
    this->count = 0;
    this->goals = 0;
    this->goalLeader = 0;
}

bool Team::operator ==(const Team& right) const{
    return this->name == right.name;
}
