//
// Created by yuvalbs on 5/11/23.
//

#include "Cowboy.hpp"
namespace ariel {

    Cowboy::Cowboy(const string name, const Point location):Character(name, location)//constructor,like:Cowboy *tom = new Cowboy("Tom", a);
    {
        this->name = name;
        this->location = location;
        hits = 110;
        bullets=6;

    }


    void Cowboy::shoot(Character *other)//get pointer to the enemy.
    {
        if (bullets == 0)//If there is no bullets left, do nothing
        {
            return;
        }

        if (this->isAlive()==false)
        {
            throw std::runtime_error("Can not attack while dead");
        }
        if (other->isAlive()==false)
        {
            throw std::runtime_error("You can not shoot a dead target");
        }
        if(other == this)
        {
            throw std::runtime_error("No self harm allowed!");
        }
        other->hit(10);// Inflict a hit of 10 points on the enemy
        bullets--;//Decrease by 1
    }

    bool Cowboy::hasboolets()// If there are left any bullets in the cowboy gun
    {
        if (bullets==0)
        {
            return false;// No bullets left
        }
        return true;
    }

    void Cowboy::reload()// Reload the gun with 6 new bullets
    {
        if(hits <= 0)
            throw std::runtime_error("Cowboy is dead. Can not overload!");
        bullets=6;
    }


}