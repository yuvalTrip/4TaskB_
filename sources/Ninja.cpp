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
        cout<<"im in move in ninja"<<endl;
        this->location = this->location.moveTowards(this->getLocation(),other->getLocation(),this->speed);
    }

    void Ninja::slash(Character *other)// Get pointer to enemy
    {
        if(other->isAlive() == false)
        {
            throw std::runtime_error("If the other person is dead you can not slash him");

        }
//        cout<<"coeboy is dead??: "<<other->isAlive()<<endl;
        if(other == this)
        {
            throw std::runtime_error("No self harm allowed!");
        }
        if(this->getLocation().distance(other->getLocation()) <= 1)
        {
            other->hit(40);
        }
        if(hits <= 0)
        {
            throw std::runtime_error("If you are dead you can not attack");
        }


    }
}