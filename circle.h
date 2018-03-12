#ifndef __CIRCLE_H
#define __CIRCLE_H
#include"figure.h"
#include"functions.h"
using namespace std;
class Circle:public Figure  //ne e poligon
{
private:
    Point center;
    double radius;
public:
    Circle();
    Circle(double x1,double y1,double _radius);
    char* type();
    Point getCenter() const;
    double diameter() const;
    double getRadius() const;
    double area() const;
    double perim() const;
    bool isInside(const Point& p) const;
    int numberOfInsideCircles(const Circle& other);
    void translation(const Point& p);
    void rotationAroundCenter();
    friend istream& operator>>(istream& is,Circle& c);
    friend ostream& operator<<(ostream& os,const Circle& c);
};
int numbOfCirclesOnCircle(const Circle& bigCircle,const Circle& smallCircle);
#endif // __CIRCLE_H
