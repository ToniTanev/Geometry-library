#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H
#include<cmath>
#include"point.h"
class Circle;
const double pi=3.14159265359;
double degreesToRadians(double degrees);
double _cos(double x); //pravq tova, tyi kato cos na cmath ne vryshta 0 pri pi/2
double distBetweenPoints(const Point& p1,const Point& p2);
Point intersectPoint(double k1,double n1,double k2,double n2); //samo kogato presichame dve perpendikulqrni pravi, toest e izpylneno k1*k2=-1
Point bisectorSectionPoint(Point A,Point B,Point C);
#endif // __FUNCTIONS_H
