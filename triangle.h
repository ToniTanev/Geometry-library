#ifndef __TRIANGLE_H
#define __TRIANGLE_H
#include"figure.h"
#include"circle.h"
#include"functions.h"
#include<cmath>
class Triangle:public Figure
{
private:
    Point A;
    Point B;
    Point C;
public:
    Triangle();
    Triangle(double x1,double y1,double x2,double y2,double x3,double y3);
    char* type();
    Point getA() const;
    Point getB() const;
    Point getC() const;
    double AB() const;
    double BC() const;
    double AC() const;
    double angle(char* first,char* second) const;
    double perim() const;
    double area() const;
    double signedArea() const;
    bool isInside(const Point& p) const;     //vzeto ot StackOverflow
    Point centroid() const;
    Point incenter() const;
    Circle incircle() const;
    Point circumcenter() const;
    Circle circumscribedCircle() const;
    void translation(const Point& p);
    void rotationAroundCenter();
    friend istream& operator>>(istream& is,Triangle& t);
    friend ostream& operator<<(ostream& os,const Triangle& t);
};
#endif // __TRIANGLE_H
