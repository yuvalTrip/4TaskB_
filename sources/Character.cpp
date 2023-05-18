//
// Created by yuvalbs on 5/11/23.
//

#include "Character.hpp"
namespace ariel {

    Character::Character(const string name, const Point location)//Constructor
    {
        this->name = name;
        this->location = location;
    }

    Character::Character() //Empty Constructor
    {

    }

    bool Character::isAlive()// Is Character alive?== Is Character has more than 0 hits points
    {
        return (hits>0);
    }

    double Character::distance( Character *other)//return distance between 2 Characters
    {
        return this->location.distance(other->getLocation());
    }

    void Character::hit(int hitsToDecrease)//פגע hit מקבל מספר שלם. מחסיר את כמות נקודות הפגיעה המתאים מהדמות. לא מחזיר דבר. –
    {
        hits=hits-hitsToDecrease;// decrease hitsToDecrease from hits number of the character
    }

    string Character::getName()// Return character name
    {
        return name;
    }

    Point Character::getLocation()// Return character location
    {
        return location;
    }

    string Character::print()
    {
        std::string characterInfo = name + "," + std::to_string(hits) + ", Location: (" + std::to_string(location.getX()) + ", " + std::to_string(location.getY()) + ")";

        std::cout << characterInfo << std::endl; // We can print the result to the console
        return characterInfo;
    }



}
