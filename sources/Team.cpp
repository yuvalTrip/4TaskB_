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

//    void Team::attack(const Team *otherTeam)
//    {
//        if(otherTeam == nullptr)
//        {
//            throw std::invalid_argument("Can not attack a 'null' team!");
//        }
//
//        if (this->leader->isAlive())//If the leader of the attackers is still alive
//        {
//            // Attack the enemy team- if stillalive=0 in the attacker team, or in the enemy team, the attack will finish.
//            while (this->stillAlive() > 0 && otherTeam->stillAlive() > 0) {
//
//                //Choose victim
//                Character *victim = otherTeam->choose_closest_to_leader(this->leader);
//                cout << " VICTIM nameeeeeee: " << victim->name<<endl;
//
//                cout << " attack BEFOER WHILE ****" << endl;
//
//                // Check if the chosen victim is dead (if it is we will coose another victim
//                while (!victim->isAlive()) {
//                    cout << " attack IN WHILE ****" << endl;
//
//                    victim = otherTeam->choose_closest_to_leader(this->leader);
//                }
//
//                // Attack the chosen victim
//                for (Character *attacker: this->members) {
//                    if (attacker->isAlive()) {
//
//                        // Cowboys with bullets shoot the victim
//                        Cowboy *cowboy = static_cast<Cowboy *>(attacker);
//                        if (cowboy != nullptr && cowboy->bullets > 0) {
//                            cout << "before falling" << endl;
//                            if(victim->isAlive() == false)
//                            {
//                                victim=otherTeam->choose_closest_to_leader(this->leader);
//                            }
//
//                            cowboy->shoot(victim);
//
//                        } else {
//                            if(cowboy==nullptr)
//                            {
//                                cout<<"cowboy is nullptr"<< endl;
//                            }
//                            // Reload guns for cowboys without bullets
//                            cowboy->reload();
//                            cout << " attack****else2" << endl;
//
//                        }
//                        cout << " try; " << endl;
//
//                        // Ninjas close to the victim slash, others move towards the victim
//                        Ninja *ninja = static_cast<Ninja *>(attacker);//try to cast to a ninja
//                        //Ninja* ninja = dynamic_cast<Ninja *>(ptr);
////                        cout << " ninja->name; " <<ninja->name<< endl;
//
//                        if (ninja != nullptr) {
//                            cout << " ninja not nullptr; " << endl;
//                            cout << " ninja->location; " << ninja->location.getX()<< ","<< ninja->location.getY()<< endl;
//                            cout << " victim->location; " << victim->location.getX()<< ","<< victim->location.getY()<< endl;
//
//                            if (ninja->location.distance(victim->location) < 1)
//                            {//Ninjas locates less than 1 meter from the victim will slash() him
//                                cout << " inside the condition; " << endl;
//
//                                ninja->slash(victim);
//                            }
//                            else
//                                {//Ninjas located more far will move towards the victim.
//                                ninja->move(victim);
//                                }
//                        }
////                        cout << " ninja is nullptr; " << endl;
//
//                    }
//                }
//
//
//                // Check if the chosen victim is dead after the attack
//                if (!victim->isAlive()) {
//                    cout << " ninja is nullptr-continue; " << endl;
//
//                    victim = otherTeam->choose_closest_to_leader(this->leader);
//                }
//            }
//        }
//        else// We will choose new leader -the closest one
//        {
//            //Choose new leader from our team
//            Character* new_leader=this->choose_closest_to_leader(leader);
//            Character* next_target=choose_closest_to_leader(otherTeam->leader);//choose next victim from the enemy team
///////////////////////////////////////////////////////////////////////////////////////////////????
//            if (this->leader == nullptr)
//            {
//                throw std::runtime_error("No team member found to be the new leader!");
//            }
//
//            // Recursively call the attack function with the updated leader
//            this->attack(otherTeam);
//        }
//
//
//    }

    void Team::attack(const Team* enemyTeam)
    {
        if (enemyTeam == nullptr)
        {
            throw std::invalid_argument("Cannot attack a 'null' team!");
        }

        if (leader == nullptr || !leader->isAlive())
        {
            // Choose new leader from our team
            leader = choose_closest_to_leader(leader);
        }

        while (stillAlive() > 0 && enemyTeam->stillAlive() > 0)
        {
            // Choose victim from the enemy team
            Character* victim = enemyTeam->choose_closest_to_leader(leader);

            while (!victim->isAlive())
            {
                // Choose another victim if the current one is dead
                victim = enemyTeam->choose_closest_to_leader(leader);
            }
            cout<<"victim is alive: "<<victim->isAlive()<<endl;
            // Attack the chosen victim
            for (Character* attacker : members)
            {
                if (attacker->isAlive()&& victim->isAlive())// The seconed condition is in case the victim killed during the attack ahd there were attackers left
                {
                    cout<<"attacker is alive"<<endl;

                    Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker);
                    if (cowboy != nullptr)
                    {
                        if (cowboy->bullets > 0)
                        {
                            cout<<"abefore error"<<endl;

                            cowboy->shoot(victim);
                            cout<<"after error"<<endl;

                        }
                        else
                        {
                            cowboy->reload();
                        }
                    }

                    Ninja* ninja = dynamic_cast<Ninja*>(attacker);
                    if (ninja != nullptr)
                    {
                        if (ninja->location.distance(victim->location) < 1)
                        {
                            ninja->slash(victim);
                        }
                        else
                        {
                            ninja->move(victim);
                        }
                    }
                }
                if(!victim->isAlive()) //If victim killed during the attack, we will choose a new victim
                {
                    while (!victim->isAlive())///////////////////////////////
                    {
                        // Choose another victim if the current one is dead
                        victim = enemyTeam->choose_closest_to_leader(leader);
                    }
                }
            }

            // Check if the chosen victim is dead after the attack
            if (!victim->isAlive())
            {
                victim = enemyTeam->choose_closest_to_leader(leader);
            }
        }
    }


    int Team::stillAlive() const{
        return howManyAlive;
    }

    void Team::print() {

    }

    Character* Team::choose_closest_to_leader(Character *leader) const// Function get leader and find the member who is the closest to him
{
    cout<<"im in choose_closest_to_leader: "<<endl;

    Point leaderLocation = leader->location;
    int size = members.size();
    int i=0;
    Character *temp=nullptr;
    int maxValue = std::numeric_limits<int>::max();
    for (Character *member: members)
    {
        if (member==leader)
        {
            cout<<"i: "<<i<<endl;
            cout<<"member==leader "<<endl;

            i++;

            continue;}
        else {
            if (member->location.distance(leaderLocation)<maxValue && member->isAlive()==true)
            {
                maxValue = member->location.distance(leaderLocation);
                temp=member;
                cout<<"victim updated! "<<endl;
            }
        }
    }
    return temp;
}
    Team::~Team() {

    }
}