//
// Created by yuvalbs on 5/17/23.
//

#include "SmartTeam.hpp"
namespace ariel {

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {
        // SmartTeam constructor implementation
    }
    SmartTeam::SmartTeam() : Team() {
        // SmartTeam empty constructor implementation
    }
    void SmartTeam::add(Character *other) {//Implementation of order- first will be the one with the most hits points
        const std::vector<Character*>& members = getMembers();
        if (members.size()==10)
        {
            throw std::runtime_error("Can not have more than 10 members");
        }
        if (other->alreadyInTeam)
        {
            throw std::runtime_error("Character already in another team");
        }

        int index_toPutNew=0;
        for(Character* member: members)
        {
            if(member->hits<other->hits)
            {
                break;
            }
            index_toPutNew++;
        }
        // Insert a new element at index index_toPutNew
        members.insert(members.begin() + index_toPutNew, other);//members.begin()  is like 0
        other->alreadyInTeam = true;//Change flag
    }

    SmartTeam::~SmartTeam() {
        // SmartTeam destructor implementation
        // The base class destructor will be called automatically
    }
}