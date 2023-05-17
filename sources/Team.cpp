//
// Created by yuvalbs on 5/11/23.
//

#include "Team.hpp"
namespace ariel {

    Team::Team(Character *leader)
    {
        howManyAlive++;

    }

    void Team::add(Character *other) {
        if (howManyAlive==10)
        {
            throw std::runtime_error("Can not have more than 10 teammates");
        }
        howManyAlive++;
    }

    void Team::attack(const Team *other)
    {
//        if (other->)

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