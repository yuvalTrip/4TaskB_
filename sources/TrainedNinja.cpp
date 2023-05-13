//
// Created by yuvalbs on 5/11/23.
//

#include "TrainedNinja.hpp"

namespace ariel {

    TrainedNinja::TrainedNinja(const string name, Point location) : Ninja(name, location) {
        this->speed = 12;
        this->hits = 120;
    }
}