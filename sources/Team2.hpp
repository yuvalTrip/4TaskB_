//
// Created by yuvalbs on 5/17/23.
//

#ifndef INC_4TASKA_Team2
#define INC_4TASKA_Team2

#include "Team.hpp"

using namespace std;
namespace ariel {

    class Team2 : public Team {
    public:
        Team2(Character *leader);
        Team2();// Empty Constructor (compiler said this is must )
        void add(Character *other) override;

    };

}
#endif //INC_4TASKA_Team2
