#include"point.h"
Point::Point(){x=y=0;}
Point::Point(double _x,double _y):x(_x),y(_y){}
void Point::setPoint(double _x,double _y)
{
    x=_x;
    y=_y;
}
double Point::operator*(const Point& other) const //skalarno proizvedenie za sluchaite, kogato tochkata reprezentira koordinati na vektor
{
    return x*other.x+y*other.y;
}
ostream& operator<<(ostream& os,const Point& p)
{
    os<<p.x<<' '<<p.y;
    return os;
}
istream& operator>>(istream& is,Point& p)
{
    is>>p.x>>p.y;
    return is;
}
