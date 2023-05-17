//
// Created by yuvalbs on 5/11/23.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
namespace ariel {


    class Point {

    private:
        double x;
        double y;

    public:
        Point(const double &x_value, const double &y_value); //Constructor get 2 coordinate
        Point();// Empty Constructor
        double distance(const Point& otherPoint)const;//Get point and calculate the distance between 2 points
//change from getting point to const Point& otherPoint because of tests
        void print();// Print both coordinates between 2 ( ) ,example: (1.1,2.3)
        static Point moveTowards(const Point &src,const Point &dest,double dist);//get 3 points, return the closest point ,that at most is in distance dist from src point
        // I made it static because of the way they used it in tests
        double getX()const;//Return x value
        double getY()const;//Return y value
    };
}