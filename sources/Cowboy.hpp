//
// Created by yuvalbs on 5/11/23.
//
#ifndef INC_4TASKA_COWB
#define INC_4TASKA_COWB
#include "Character.hpp"
//#include "Ninja.hpp"

using namespace std;
namespace ariel {


    class Cowboy : public Character //character is the base class, cowboy is the derived class
    {// cowboy always initial with 6 bullets , 110 hits
    private:
    public:
        int bullets;
        int hits;
        Cowboy( string name,  Point location);//constructor,like:Cowboy *tom = new Cowboy("Tom", a);
        void shoot(Character *other);//get pointer to the enemy.
        // If the cowboy is not dead, and left with bulllets he will shoot the enemy . Decrease 10 hit points from the enemy and loose one ball
        // Else - nothing happen to the enemy
        bool hasBoolets();// If there are left any bullets in the cowboy gun
        void reload();// Reload the gun with 6 new bullets

    };
}
#endif //INC_4TASKA_COWB
