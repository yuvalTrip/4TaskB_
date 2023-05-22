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

    double Point::getX() const{
        return x;
    }

    double Point::getY() const{
        return y;
    }

     Point Point::moveTowards(const Point &source, const Point &destination, double distance)
    {
        //cout<<"im in moveTowards in point"<<endl;

        if(distance < 0)
        {
            throw std::invalid_argument("Can not move negative distance");
        }
        //Calculates the total distance between the source and destination points using the distance function of the Point class
        double totalDistance = source.distance(destination);
        //If the total distance is less than or equal to the desired distance,
        // it means that moving the desired distance would reach the destination. In that case, the function returns the destination point.
        if (totalDistance <= distance) {// If current distance is smaller than distance, we will arrive to the destination
            return destination;
        }
        //If the total distance is greater than the desired distance
        //calculates the difference in x-coordinates (distx) and y-coordinates (disty) between the source and destination points.
        double distx = destination.getX() - source.getX();
        double disty = destination.getY() - source.getY();
        //computes the factor by dividing the desired distance by the total distance.
        // (this is the ratio of how much distance needs to be covered in the x and y directions)
        double factor = distance / totalDistance;

        //calculates the new x-coordinate (newX) and y-coordinate (newY)
        //by adding the scaled difference in x and y coordinates to the source coordinates.
        double newX = source.getX() + distx * factor;
        double newY = source.getY() + disty * factor;

        return Point(newX, newY);
    }



}