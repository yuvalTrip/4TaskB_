//
// Created by yuvalbs on 5/11/23.
//
///////////////////// In this class I create the order as you told in the Add function :)
#include "Team.hpp"
namespace ariel {

    Team::Team(Character *leader)
    {
//        howManyAlive++;
        if(leader->alreadyInTeam == true)// If the leader already in group
        {
            throw std::runtime_error("leader belongs to team");//Throw an error
//            cout << "OK6" << endl;

        }
        else{
//            leader->alreadyInTeam = true;//Change the leader to true so he can not be a leader of another team

            this->leader = leader;

            this->add(leader);//add leader to the member stack

        }


    }

    void Team::add(Character *other) {//Implementation of order- first cowboys and then ninjas
        if (members.size()==10)
        {
            throw std::runtime_error("Can not have more than 10 members");
        }
        if (other->alreadyInTeam)
        {
            throw std::runtime_error("Character already in another team");
        }
        Cowboy* cowboy = dynamic_cast<Cowboy*>(other);//Check if cowboy
        if (cowboy != nullptr)//If this is a cowboy (and not a ninja)
        {
//            cout<<"indX: "<<last_index_cowboy<<endl;

            // Insert a new element at index last_index_cowboy
            members.insert(members.begin() + last_index_cowboy, other);
            last_index_cowboy++;
        }else//this is a ninja
         {
//             cout<<"adding ninja "<<endl;
            // Insert a new element at the end of the members
            members.push_back(other);

        }
//        howManyAlive++;
//        members.push_back(other);
        other->alreadyInTeam = true;//Change flag
    }

    void Team::attack(const Team* enemyTeam)
    {
//        cout<<"STARTED NEW ATTACK"<<endl;

        if (enemyTeam == nullptr )
        {
            throw std::invalid_argument("Can not attack a 'null' team !");
        }
        if (enemyTeam->stillAlive()==0 )
        {
            throw std::runtime_error("Can not attack a dead team !");
        }
        if ( !leader->isAlive())
        {
            // Choose new leader from our team
            leader = choose_closest_to_leader(leader);
        }
        if (leader== nullptr)
        {
            return;
        }
            // Attack the chosen victim
            for (Character* attacker : members)//For any member in the attack team
            {
                // Choose victim from the enemy team
                Character* victim = enemyTeam->choose_closest_to_leader(leader);
                //cout<<"After choose_closest_to_leader: "<<endl;
                if (victim== nullptr)
                {
                    return;
                }
//                cout<<"first condition: attacker->isAlive() "<<attacker->isAlive()<<endl;
//                cout<<"sec condition: victim->isAlive() "<<victim->isAlive()<<endl;

                if (attacker->isAlive() && victim->isAlive())
                {
                    Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker);
                    if (cowboy != nullptr)//If this is a cowboy (and not a ninja)
                    {
                        if (cowboy->bullets > 0)
                        {
//                            cout<<"cowboy->bullets-"<<cowboy->bullets<<endl;
//                            cout<<"cowboy shoot-"<<victim->name<<endl;
                            cowboy->shoot(victim);
//                            cout<<"hits left to victim after attack"<<victim->hits<<endl;

                        }
                        else
                        {
                            cowboy->reload();
                        }
                    }

                    Ninja* ninja = dynamic_cast<Ninja*>(attacker);
                    if (ninja != nullptr)
                    {
//                        cout<<"c->distance(victim) "<<ninja->distance(victim) <<endl;

                        if (ninja->location.distance(victim->location) <= 1)
                        {
//                            cout<<"Ninja shoot-"<<victim->name<<endl;
                            ninja->slash(victim);
//                            cout<<"hits left to victim after attack(ninja)"<<victim->hits<<endl;

                        }
                        else
                        {
                            ninja->move(victim);
                        }
                    }
                }
            }
    }


    int Team::stillAlive() const
    {
        int stillAlivePeople=0;
        for (Character *member: members)
        {
            if (member->isAlive())
            {
//                cout<<"member name: "<<member->name<<endl;
                stillAlivePeople++;
            }
        }
        return stillAlivePeople;
    }

    void Team::print() {
        for (Character* member: members) {
                cout << member->print() << endl;
        }
    }

    Character* Team::choose_closest_to_leader(Character *leader) const// Function get leader and find the member who is the closest to him
{
    //cout<<"im in choose_closest_to_leader: "<<endl;
    if (leader == nullptr) {
        // Handle the case when leader pointer is null
        throw std::invalid_argument("Invalid leader pointer!");
    }
    Point leaderLocation = leader->location;
    Character *temp=nullptr;
    int maxValue = std::numeric_limits<int>::max();
    for (Character *member: members)
    {
//        if (member==leader)/////////////////////////??
//        {continue;}
//        else {
            if (member->location.distance(leaderLocation)<maxValue && member->isAlive()==true)
            {
                maxValue = member->location.distance(leaderLocation);
                temp=member;
                //cout<<"victim updated! "<<endl;
            }
//            if(member->isAlive()==false)
//            {
//                howManyAlive=howManyAlive-1;
//            }
//        }
    }

    return temp;
}
    Team::~Team() {
        for (Character* member: members) {
            delete member ;
        }
    }
}