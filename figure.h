#ifndef __FIGURE_H
#define __FIGURE_H
#include<iostream>
#include"point.h"
using namespace std;
class Figure
{
public:
    virtual double area() const {}
    virtual double perim()const {}
    virtual bool isInside(const Point&) const {}
    virtual char* type()=0;
    virtual Point centroid() const
    {
        Point p(0,0);
        cout<<"It is not a polygon"<<endl;
        return p;
    }
    virtual void translation(const Point&){}
    virtual void rotationAroundCenter(){}
    //virtual Circle incircle(){}
};
#endif // __FIGURE_H
