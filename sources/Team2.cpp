//
// Created by yuvalbs on 5/17/23.
//

#include "Team2.hpp"
namespace ariel {

    Team2::Team2(Character *leader) : Team(leader) {

    }

    void Team2::add(Character *other) {//Implementation of order- first we got is the first in the team
//        if (members.size()==10) changed members to private so have to change
        if (Team::get_team_size()==10)
        {
            throw std::runtime_error("Can not have more than 10 members");
        }
        if (other->alreadyInTeam)
        {
            throw std::runtime_error("Character already in another team");
        }
            // Insert a new element at the end of the members
            //members.push_back(other);
            Team2::push_member(other);//Function get character and do the action of vector.push(character)

        other->alreadyInTeam = true;//Change flag
    }
}