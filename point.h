#ifndef __POINT_H
#define __POINT_H
#include<iostream>
using namespace std;
struct Point
{
    double x;
    double y;
    Point();
    Point(double _x,double _y);
    void setPoint(double _x,double _y);
    double operator*(const Point& other) const; //skalarno proizvedenie za sluchaite, kogato tochkata reprezentira koordinati na vektor
};
#endif // __POINT_H
