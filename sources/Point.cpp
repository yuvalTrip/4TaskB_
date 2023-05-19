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

    double Point::distance(const Point& otherPoint)const
    {
        //cout<<"im distance in point"<<endl;
        double dx = x - otherPoint.x;
        double dy = y - otherPoint.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    void Point::print()
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

     Point Point::moveTowards(const Point &source, const Point &destination, double distance)
    {
        cout<<"im in moveTowards in point"<<endl;

        if(distance < 0)
        {
            throw std::invalid_argument("Can not move negative distance");
        }
        double totalDistance = source.distance(destination);
        if (totalDistance <= distance) {// If current distance is smaller than distance, we will arive to the destination
            return destination;
        }
        double distx = destination.getX() - source.getX();
        double disty = destination.getY() - source.getY();
        double factor = distance / totalDistance;

        double newX = source.getX() + distx * factor;
        double newY = source.getY() + disty * factor;

        return Point(newX, newY);
    }

    double Point::getX() const{
        return this->x;
    }

    double Point::getY() const{
        return this->y;
    }

}