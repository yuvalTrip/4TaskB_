//
// Created by yuvalbs on 5/11/23.
//
#ifndef INC_4TASKA_CHAR
#define INC_4TASKA_CHAR

#include <stdio.h>
#include "Point.hpp"

using namespace std;
namespace ariel{


class Character {
private:

public:
    Point location;//Character location
    string name; //Character name
    int hits;// Hits points
    bool alreadyInTeam=false;
    string type;

    Character( string name, Point location);//Constructor
    Character(); //Empty Constructor
    bool isAlive();// Is Character alive?== Is Character has more than 0 hits points
    double distance( Character *other);//return distance between 2 Characters. const because I don't intend to modify the passed object,
    void hit(int hits);//פגע hit מקבל מספר שלם. מחסיר את כמות נקודות הפגיעה המתאים מהדמות. לא מחזיר דבר. –
    string getName();// Return character name
    Point getLocation();// Return character location
    string print();// Print: character name, number of hits, point of the character
    // If character is dead, her number of hit will not be printed and character name will display in ()
    // Before character name a letter will be display N to ninja, C to cowboy
    virtual ~Character() = default;
    Character(const Character& other) = default; // Copy constructor
    Character& operator=(const Character& other) = default; // Copy assignment operator
    Character(Character&& other) = default; // Move constructor
    Character& operator=(Character&& other) = default; // Move assignment operator

};

};
#endif //INC_4TASKA_CHAR
