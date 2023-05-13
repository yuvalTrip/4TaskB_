//
// Created by yuvalbs on 5/11/23.
//

#include "OldNinja.hpp"
using namespace std;

namespace ariel {

    OldNinja::OldNinja(string name, Point location) : Ninja(name, location) {
        speed = 8;
        hits = 150;
    }
}