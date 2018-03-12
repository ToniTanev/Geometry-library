#include"functions.h"

double degreesToRadians(double degrees)
{
    return degrees*(pi/180.0);
}
double _cos(double x) //pravq tova, tyi kato cos na cmath ne vryshta 0 pri pi/2
{
    return (x==degreesToRadians(90)||x==pi/2)?0:cos(x);
}
double distBetweenPoints(const Point& p1,const Point& p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
Point intersectPoint(double k1,double n1,double k2,double n2) //samo kogato presichame dve perpendikulqrni pravi, toest e izpylneno k1*k2=-1
{
    Point p;
    if(k1==0)
    {
        p.x=n2;
        p.y=n1;
        return p;
    }
    if(k2==0)
    {
        p.x=n1;
        p.y=n2;
        return p;
    }
    p.x=(n2-n1)/(k1-k2);
    p.y=k1*p.x+n1;
    return p;
}
Point bisectorSectionPoint(Point A,Point B,Point C)
{
    Point L;
    double coef=distBetweenPoints(A,C)/distBetweenPoints(B,C);
    L.x=(coef*B.x+A.x)/(1+coef);
    L.y=(coef*B.y+A.y)/(1+coef);
    return L;
}
