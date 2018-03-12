#ifndef __SQUARE_H
#define __SQUARE_H
#include"figure.h"
#include"functions.h"
#include"rectangle.h"
#include"circle.h"
class Square:public Figure
{
private:
    //first e A, second e B, third e D, fourth e C
    Point first;
    double a; //strana na kvadrata
    double degrees;
public:
    Square();
    Square(double x1,double y1,double _a,double _degrees);
    char* type();
    Point getFirst() const;
    double getA() const;
    double getDegrees() const;
    Point second() const;
    Point third() const;
    Point fourth() const;
    bool isInside(const Point& p) const;
    double area() const;
    double perim() const;
    Point centroid() const;
    Circle incircle() const;
    void translation(const Point& p);
    void rotationAroundCenter();
    friend istream& operator>>(istream& is,Square& s);
    friend ostream& operator<<(ostream& os,const Square& s);
};
#endif // __SQUARE_H
