//
// Created by yuvalbs on 5/11/23.
//

#include "Team.hpp"
namespace ariel {

    Team::Team(Character *leader)
    {
        howManyAlive++;
        if(leader->alreadyInTeam == true)// If the leader already in group
        {
            throw std::runtime_error("leader belongs to team");//Throw an error
            cout << "OK6" << endl;

        }
        else{
            leader->alreadyInTeam = true;//Change the leader to true so he can not be a leader of another team

            this->leader = leader;

            this->members.push_back(leader);//add leader to the member stack

        }


    }

    void Team::add(Character *other) {
        if (members.size()==10)
        {
            throw std::runtime_error("Can not have more than 10 teammates");
        }
        if (other->alreadyInTeam)
        {
            throw std::runtime_error("Character already in another team");
        }
        howManyAlive++;
        members.push_back(other);
        other->alreadyInTeam = true;//Change flag
    }

    void Team::attack(const Team *otherTeam)
    {
//        if (other->)

        if(otherTeam == nullptr)
            throw std::invalid_argument("Can not attack a 'null' team!");
    }

    int Team::stillAlive() {
        return howManyAlive;
        return 0;
    }

    void Team::print() {

    }

    Team::~Team() {

    }
}