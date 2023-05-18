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
        if(otherTeam == nullptr)
            throw std::invalid_argument("Can not attack a 'null' team!");
        if (this->leader->isAlive())//If the leader of the attackers is still alive
        {

        }
        else// We will choose new leader -the closest one
        {
            Character* new_leader=choose_closest_to_leader(leader);//Choose new leader from our team
            Character* next_target=choose_closest_to_leader(otherTeam->leader);//choose next victim from the enemy team
/////////////////////////////////////////////////////////////////////////////////////////////????
        }


    }

    int Team::stillAlive() {
        return howManyAlive;
    }

    void Team::print() {

    }

    Character* Team::choose_closest_to_leader(Character *leader)// Function get leader and find the next member who is the closest to him
{
    Point leaderLocation = leader->location;
    int size = members.size();
    Character *temp=nullptr;
    int minValue = std::numeric_limits<int>::min();
    for (Character *member: members)
    {
        if (member==leader)
        {continue;}
        else {
            if (member->location.distance(leaderLocation)<minValue)
            {
                temp=member;
            }
        }

    }
    return temp;
}
    Team::~Team() {

    }
}