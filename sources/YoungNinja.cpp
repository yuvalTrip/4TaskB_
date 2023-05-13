//
// Created by yuvalbs on 5/11/23.
//

#include "YoungNinja.hpp"
namespace ariel {

    YoungNinja::YoungNinja(const string name, Point location) : Ninja(name, location) {
        this->speed = 14;
        this->hits = 100;
    }

}