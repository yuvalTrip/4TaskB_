//
// Created by yuvalbs on 5/11/23.
//

#include "Team.hpp"
namespace ariel {

    Team::Team(Character *leader)
    {
        howManyAlive++;
        cout << "OK5" << endl;
        cout << "leader name" << leader->name<<endl;
        cout << "leader in team?" << leader->alreadyInTeam<<endl;

        if(leader->alreadyInTeam == true)// If the leader already in group
        {
            throw std::runtime_error("leader belongs to team");//Throw an error
            cout << "OK6" << endl;

        }
        else{
            cout << "OK7" << endl;
//????
            leader->alreadyInTeam = true;//Change the leader to true so he can not be a leader of another team
            cout << "OK8" << endl;

            this->leader = leader;
            cout << "OK9" << endl;

            this->members.push_back(leader);//add leader to the member stack
            cout << "OK10" << endl;

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