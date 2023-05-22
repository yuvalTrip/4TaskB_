//
// Created by yuvalbs on 5/11/23.
//

#include "Ninja.hpp"
namespace ariel {

    Ninja::Ninja(string name, Point location):Character(name, location) {
        type="N";//For prints
    }

    void Ninja::move(Character *other)// Get pointer to enemy and move toward him. Move distance equal to his speed
    {
        //cout<<"im in move in ninja"<<endl;
        location = location.moveTowards(this->getLocation(),other->getLocation(),speed);
    }

    void Ninja::slash(Character *other)// Get pointer to enemy
    {
        if(hits <= 0)// Dead ninja can not attack
        {
            throw std::runtime_error("If you are dead you can not attack");
        }
        if(other->isAlive() == false)//Deadcharacter can not be attacked
        {
            throw std::runtime_error("If the other person is dead you can not slash him");
        }
        if(other == this)//Added because tests
        {
            throw std::runtime_error("No self harm allowed!");
        }
        if(this->getLocation().distance(other->getLocation()) <= 1)// If distance is smaller than 1 meter, ninja will slash the enemy
        {
            other->hit(40);
        }

    }
}