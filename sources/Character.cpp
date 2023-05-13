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
        return hits > 0;
    }

    double Character::distance(Character &other)//return distance between 2 Characters
    {
        Point first = location;
        Point second = other.location;
        double distance_ = first.distance(second);
        return distance_;
    }

    void Character::hit(int hits) {    // Reduce the character's hit points by the specified amount
        this->hits -= hits;
    }

    string Character::getName()// Return character name
    {
        return name;
    }

    Point Character::getLocation()// Return character location
    {
        return location;
    }

    string Character::print() {// Print the character's name, number of hits, and current location
        // If the character is dead, the number of hits will not be printed and the name will be enclosed in parentheses
        // A letter indicating the type of character (N for ninja, C for cowboy) will be displayed before the name
            if (this->isAlive()) {
                std::cout << name << "," << hits << ",";
                location.print();
            } else {
                std::cout << "(" << name << ")";
            }
            return "";


        }
    }
