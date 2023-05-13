//
// Created by yuvalbs on 5/11/23.
//

#include "doctest.h"
#include "sources/Team.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>

using namespace std;

using namespace ariel;

    TEST_CASE("Point initial"){
        Point a(1.5,4.5),c(1.5,3.5),d(5.5,4.5);
        CHECK(a.getX()== c.getX());
        CHECK(a.getY() == d.getY());
    }

TEST_CASE("Distance checks"){
    Point a(4.15831,1.5),b(2.5,4);
    CHECK(a.distance(b) == b.distance(a));
    double dist1=3;
    double dist2=a.distance(b);
    cout<<"hiiiiiiiiiiiiiiiiiiiiiiii"<<endl;
    cout<<dist2<<endl;

//    CHECK(dist2 == dist1);
}


    TEST_CASE("Cowboy initiation and shooting") {
    Point a(1.5, 4.5);
//    Point b(1.3,3.5);
//        Point c(64,57), d(12,81);
    CHECK_NOTHROW(Cowboy * evgeni = new Cowboy("evgeni", a));
    Cowboy * evgeni = new Cowboy("evgeni", a);
    CHECK_NOTHROW(Cowboy * harel = new Cowboy("harel", a));
    Cowboy * harel = new Cowboy("harel", a);

    CHECK(evgeni->bullets == 6);
    CHECK(evgeni->hits == 110);
    CHECK("evgeni"==evgeni->getName());
    CHECK(evgeni->getLocation().getX()==a.getX());
    CHECK(evgeni->getLocation().getY()==a.getY());
    //CHECK(evgeni->print()=="evgeni,110,(1.5,4.5)");// Print: character name, number of hits, point of the character
    CHECK(evgeni->hasBoolets()==true);
    evgeni->shoot(harel);
    CHECK(evgeni->bullets == 5);
    evgeni->reload();// Reload the gun with 6 new bullets
    CHECK(evgeni->hasBoolets() == true);// Check if there is more bullets
    CHECK(evgeni->bullets == 11);// Check how many bullets
    //Add to team
    CHECK_NOTHROW(Team team_A(evgeni));
    CHECK(evgeni->isAlive()==true);


}

TEST_CASE("Ninjas initiation") {
        Point b(1.3,3.5);
//        Point c(64,57), d(12,81);
        Point c(88,160), d(11,99);

    CHECK_NOTHROW(OldNinja *jackie_chan = new OldNinja("jackie_chan", b));
    OldNinja *jackie_chan = new OldNinja("jackie_chan", b);
    CHECK("jackie_chan"==jackie_chan->getName());
    CHECK_NOTHROW(YoungNinja *Master_shiffo= new YoungNinja("Master_shiffo", c));
    YoungNinja *Master_shiffo= new YoungNinja("Master_shiffo", c);
    CHECK_NOTHROW(TrainedNinja *Kong_foo_Panda = new TrainedNinja("Kong_foo_Panda", d));
    TrainedNinja *Kong_foo_Panda = new TrainedNinja("Kong_foo_Panda", d);
    //Check locations
    CHECK(jackie_chan->getLocation().getX() == b.getX());
    CHECK(jackie_chan->getLocation().getY() == b.getY());
    CHECK(Master_shiffo->getLocation().getX() == c.getX());
    CHECK(Master_shiffo->getLocation().getY() == c.getY());
    CHECK(Kong_foo_Panda->getLocation().getX() == d.getX());
    CHECK(Kong_foo_Panda->getLocation().getY() == d.getY());
    //Check numbers of hits
    CHECK(jackie_chan->hits == 150);
    CHECK(Master_shiffo->hits == 100);
    CHECK(Kong_foo_Panda->hits == 120);
    //Check speeds
    CHECK(jackie_chan->speed == 8);
    CHECK(Master_shiffo->speed == 14);
    CHECK(Kong_foo_Panda->speed == 12);
    //Check if alive
    CHECK(jackie_chan->isAlive()==true);
    CHECK(Master_shiffo->isAlive()==true);
    CHECK(Kong_foo_Panda->isAlive()==true);


}

    TEST_CASE("Team fights"){
        Point a(1.3,4.5),b(1.3,3.54);
        Point c(64,57), d(12,81), e(1.5,2.5);

        //Create characters
        Cowboy *Yehonatan = new Cowboy("Yehonatan", a);
        OldNinja *jackie_chan = new OldNinja("jackie_chan", b);
        OldNinja *mr_ping = new OldNinja("mr_ping", e);
        YoungNinja *Master_shiffo = new YoungNinja("Master_shiffo", c);
        TrainedNinja *Kong_foo_Panda = new TrainedNinja("Kong_foo_Panda", d);

        //Create teams
        Team team_A(Yehonatan);
        Team team_B(jackie_chan);

        //Add charecters to the teams
        team_A.add(Master_shiffo);
        team_A.add(mr_ping);
        team_B.add(Kong_foo_Panda);

        // Check the number of characters in each team
        CHECK(team_A.stillAlive()==3);
        CHECK(team_B.stillAlive()==2);

        // Check shooting (Yehonatan have 6 bullets)
        for(int i=0; i<6; i++){
            Yehonatan->shoot(mr_ping);
        }
        CHECK(Yehonatan->hasBoolets()==false);

        //Check slash
        int beforeSlash = Master_shiffo->hits;
        Master_shiffo->move(mr_ping);
        Master_shiffo->slash(mr_ping);
        int afterSlash = Master_shiffo ->hits;
        CHECK(beforeSlash-40==afterSlash);
        while( team_B.stillAlive() > 0){
            team_A.attack(&team_B);
        }
        CHECK(team_B.stillAlive()==0);
        CHECK(team_A.stillAlive()>0);

    }
