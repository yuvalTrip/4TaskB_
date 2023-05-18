//
// Created by yuvalbs on 5/11/23.
//

#ifndef INC_4TASKA_Team
#define INC_4TASKA_Team

#include <stdio.h>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "vector" //to use vector for team members
using namespace std;

namespace ariel {


    class Team {

    public:
        Team(Character *leader);
        Team();// Default constructor
        Character *leader;//Team leader
        int howManyAlive=0;//how many alive characters in the team
        std::vector<Character*> members;//vector of all members in the class
        void add(Character *other);

        void attack(const Team *other);

        int stillAlive();

        void print();
        Character choose_closest_to_leader(Character *other);// Function get leader and find the next member who is the closest to him
        ~Team();
        // Disabling copy and move operations
        Team(const Team&) = delete;// Deleting the copy constructor.
// This line prevents creating new instances of Team by copying an existing instance.

        Team& operator=(const Team&) = delete;// Deleting the copy assignment operator.
// This line prevents assigning one Team object to another using the assignment operator.

        Team(Team&&) = delete;// Deleting the move constructor.
// This line prevents creating new instances of Team by moving an existing instance.

        Team& operator=(Team&&) = delete;// Deleting the move assignment operator.
// This line prevents assigning one Team object to another using the move assignment operator.

    };

}

#endif //INC_4TASKA_Team
