//
// Created by yuvalbs on 5/17/23.
//

#ifndef INC_4TASKA_STeam
#define INC_4TASKA_STeam

#include "Team.hpp"
#include "vector" //to use vector for team members

using namespace std;
namespace ariel {

    class SmartTeam : public Team {
//    private:
//        using Team::members;
    public:
        SmartTeam(Character *leader);
        SmartTeam();// Empty Constructor (compiler said this is must )
        void add(Character *other) override;
        ~SmartTeam() override; // Destructor declaration

        // Rule of Five: declare or delete special member functions
        SmartTeam(const SmartTeam&) = delete; // Delete copy constructor
        SmartTeam& operator=(const SmartTeam&) = delete; // Delete copy assignment operator
        SmartTeam(SmartTeam&&) = delete; // Delete move constructor
        SmartTeam& operator=(SmartTeam&&) = delete; // Delete move assignment operator
    };

}
#endif //INC_4TASKA_STeam
