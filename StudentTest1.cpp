#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include <random>
#include <chrono>
#include <iostream>

using namespace ariel;
using namespace std;
//<--------------------Helper Functions-------------------->
//https://www.geeksforgeeks.org/generate-a-random-float-number-in-cpp/
double random_float(double min = -100, double max = 100) {
    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> distribution(min, max);

    return distribution(generator);
}

auto create_yninja = [](double x = random_float(), double y = random_float()) {
    return new YoungNinja{"Bob1", Point{x, y}};
};

auto create_tninja = [](double x = random_float(), double y = random_float()) {
    return new TrainedNinja{"Bob2", Point{x, y}};
};

auto create_oninja = [](double x = random_float(), double y = random_float()) {
    return new OldNinja{"Bob3", Point{x, y}};
};

auto create_cowboy = [](double x = 22, double y = 22) {
    return new Cowboy{"Bob4", Point{x, y}};
};

auto random_char(double x = random_float(), double y = random_float()) -> Character * {
    int flag = static_cast<int>(random_float()) % 4;

    if (flag == 0) return create_cowboy(x, y);

    if (flag == 1) return create_yninja(x, y);

    if (flag == 2) return create_tninja(x, y);

    return create_oninja(x, y);
}

auto simulate_battle = [](Team &team, Team &team2) {
    int i = 0;
    while (team.stillAlive() && team2.stillAlive()) {
        if (i % 2 == 0) {
            team.attack(&team2);
        } else {
            team2.attack(&team);
        }
        i++;
    }
};
//<-------------------------------------------------->

const int MAX_TEAM = 10;






TEST_SUITE("Battle simulations") {

    auto multi_attack = [](int n, Team &attacker, Team &defender) {
        for (int i = 0; i < n; i++) {
            if (defender.stillAlive()) {
                attacker.attack(&defender);
            }
        }
    };

    TEST_CASE("Characters attack the closest enemy to the captain and ignore dead enemies ") {
        Team team{create_cowboy(-1, -1)};
        team.add(create_yninja(0, 0));
        team.add(create_oninja(-0.5, -0.5));
        team.add(create_tninja(0.5, 0.5));
        team.add(create_cowboy());

        CHECK_EQ(team.stillAlive(), 5);

        auto young_ninja = create_yninja(0, 0);
        auto trained_ninja = create_tninja(1, 1);
        auto old_ninja = create_oninja(2, 2);
        auto young_ninja2 = create_yninja(3, 3);
        auto cowboy = create_cowboy(-6, -6);
        auto cowboy2 = create_cowboy(-7, -7);
        auto cowboy3 = create_cowboy(-8, -8);
        Team team2{young_ninja};
        team2.add(trained_ninja);
        team2.add(old_ninja);
        team2.add(young_ninja2);
        team2.add(cowboy);
        team2.add(cowboy2);
        team2.add(cowboy3);
        team2.print();
        cout<<"**********************"<<endl;
        team.print();

        CHECK_EQ(team2.stillAlive(), 7);

        multi_attack(2, team, team2);
        CHECK_FALSE(young_ninja->isAlive()); // Young ninja should be dead
        CHECK((trained_ninja->isAlive() && old_ninja->isAlive() &&
               young_ninja2->isAlive())); // Everyone else should still be alive

        team.attack(&team2);
        CHECK((!trained_ninja->isAlive() && old_ninja->isAlive() &&
               young_ninja2->isAlive())); // No one should die in the attack

        multi_attack(2, team, team2);
        CHECK_FALSE(trained_ninja->isAlive()); // Trained ninja should be dead
        CHECK((!old_ninja->isAlive() && young_ninja2->isAlive()));

        multi_attack(4, team, team2);
        CHECK_FALSE(old_ninja->isAlive()); // Old ninja should be dead
        CHECK(!young_ninja2->isAlive());

        multi_attack(2, team, team2);
        CHECK_NOTHROW(team.attack(
                &team2)); // The entire enemy team will be dead before every cowboy shoots, the attack should stop and not throw an exception
        CHECK_FALSE(young_ninja2->isAlive()); // Young ninja should be dead
        CHECK_THROWS_AS(team.attack(&team2), std::runtime_error); // Attacking a dead team should throw an exception
    }

}