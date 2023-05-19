//
// Created by yuvalbs on 5/17/23.
//

#include "Team2.hpp"
namespace ariel {

    Team2::Team2(Character *leader) : Team(leader) {

    }

    void Team2::add(Character *other) {//Implementation of order- first we got is the first in the team
        if (members.size()==10)
        {
            throw std::runtime_error("Can not have more than 10 members");
        }
        if (other->alreadyInTeam)
        {
            throw std::runtime_error("Character already in another team");
        }
            // Insert a new element at the end of the members
            members.push_back(other);
        other->alreadyInTeam = true;//Change flag
    }
}