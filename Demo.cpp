/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;
    cout << "OK" << endl;

    sushi->move(tom);
    sushi->slash(tom);
    cout << "OK2" << endl;

    Team team_A(tom);
    team_A.add(new YoungNinja("Yogi", Point(64,57)));
    cout << "OK3" << endl;

    // Team b(tom); should throw tom is already in team a

    Team team_B(sushi);
    cout << "OK4" << endl;

    team_B.add(new TrainedNinja("Hikari", Point(12,81)));
    cout << "BEFORE WHILE" << endl;

    int i=0;
    while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        cout << "INTO WHILE" << endl;

        team_A.attack(&team_B);
        cout << " attack1" << endl;

        team_B.attack(&team_A);
        cout << " attack2" << endl;

        team_A.print();
        team_B.print();
        cout << "i: "<< i << endl;
        i++;
    }
    cout << "END WHILE" << endl;
    if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
    else cout << "winner is team_B" << endl;

    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}