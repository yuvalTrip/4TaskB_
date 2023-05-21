//
// Created by yuvalbs on 5/17/23.
//

#include "SmartTeam.hpp"
namespace ariel {
    SmartTeam::SmartTeam(Character *leader) : Team(leader){
        // SmartTeam constructor implementation
    }

    void SmartTeam::add(Character *other) {//Implementation of order- first will be the one with the most hits points
//        const std::vector<Character*>& members = getMembers();
        if (get_team_size()==10)
        {
            throw std::runtime_error("Can not have more than 10 members");
        }
        if (other->alreadyInTeam)
        {
            throw std::runtime_error("Character already in another team");
        }

        int index_toPutNew=0;
        std::vector<Character*> get_member_vector= SmartTeam::getVector();//function return the 'member' vector

        for(Character* member: get_member_vector)
        {
            if(member->hits<other->hits)
            {
                break;
            }
            index_toPutNew++;
        }
        // Insert a new element at index index_toPutNew
        SmartTeam::insert_by_index(other,index_toPutNew);//done this because I changed vector to be private (and not public/protected)
//        members.insert(members.begin() + index_toPutNew, other);//members.begin()  is like 0
        other->alreadyInTeam = true;//Change flag
    }

    SmartTeam::~SmartTeam() {
        // SmartTeam destructor implementation
        // The base class destructor will be called automatically
    }
}