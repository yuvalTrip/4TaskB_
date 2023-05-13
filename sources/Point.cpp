//
// Created by yuvalbs on 5/11/23.
//

#include "Point.hpp"
#include <cmath>
namespace ariel {

    Point::Point(const double &x, const double &y) {
        this->x = x;
        this->y = y;
    }

//Empty constructor
    Point::Point() {
        this->x = 0;
        this->y = 0;
    }

    double Point::distance(Point otherPoint)
    {
        double dx = x - otherPoint.x;
        double dy = y - otherPoint.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    void Point::print()
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    Point Point::moveTowards(Point source, Point destination, double distance)
    {
        Point answer=Point();
        double dx = destination.x - source.x ;
        double dy = destination.y - source.y;
        double currentDist = std::sqrt(dx * dx + dy * dy);

        if (currentDist <= distance) // If current distance is smaller than distance, we will arive to the destination
        {
            answer.x = destination.x;
            answer.y = destination.y;
        } else {
            double ratio = distance / currentDist;
            answer.x = source.x + dx * ratio;
            answer.y = source.y + dy * ratio;
        }
        return Point();
    }

    double Point::getX() {
        return this->x;
    }

    double Point::getY() {
        return this->y;
    }

}