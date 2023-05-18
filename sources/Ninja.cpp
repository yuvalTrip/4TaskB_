//
// Created by yuvalbs on 5/11/23.
//

#include "Ninja.hpp"
namespace ariel {

    Ninja::Ninja(string name, Point location) {
        this->name = name;
        this->location = location;
    }

    void Ninja::move(Character *other)// Get pointer to enemy and move toward him. Move distance equal to his speed
    {
        this->location = this->location.moveTowards(this->getLocation(),other->getLocation(),this->speed);
    }

    void Ninja::slash(Character *other)// Get pointer to enemy
    {
        if(this->getLocation().distance(other->getLocation()) <= 1)
        {
            other->hit(40);
        }
        if(hits <= 0)
        {
            throw std::runtime_error("If you are dead you can not attack");
        }
        if(other->isAlive() == false)
        {
            throw std::runtime_error("If the other person is dead you can not slash him");

        }

    }
}