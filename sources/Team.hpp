//
// Created by yuvalbs on 5/11/23.
//
#include <stdio.h>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

using namespace std;

namespace ariel {


    class Team {

    public:
        Team(Character *leader);

        Character leader;

        void add(Character *other);

        void attack(const Team *other);

        int stillAlive();

        void print();

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