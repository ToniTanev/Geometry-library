#include"square.h"
Square::Square(){}
Square::Square(double x1,double y1,double _a,double _degrees)
{
    first.x=x1;
    first.y=y1;
    a=_a;
    degrees=_degrees;
}
char* Square::type() {return "Square";}
Point Square::getFirst() const {return first;}
double Square::getA() const {return a;}
double Square::getDegrees() const {return degrees;}
Point Square::second() const
{
    Point p(first.x+_cos(degreesToRadians(degrees))*a,first.y+sin(degreesToRadians(degrees))*a);
    return p;
}
Point Square::third() const
{
    Point p(first.x-_cos(degreesToRadians(90-degrees))*a,first.y+sin(degreesToRadians(90-degrees))*a);
    return p;
}
Point Square::fourth() const
{
    //pravata koqto minava prez A i C e s 45+degrees gradusa
    double diagonal=sqrt(2)*a;
    Point p(first.x+_cos(degreesToRadians(degrees+45))*diagonal,first.y+sin(degreesToRadians(degrees+45))*diagonal);
    return p;
}
bool Square::isInside(const Point& p) const
{
    Rectangle r(first.x,first.y,fourth().x,fourth().y,degrees);
    return r.isInside(p);
}
double Square::area() const {return a*a;}
double Square::perim() const {return 4*a;}
Point Square::centroid() const
{
    Point p((first.x+fourth().x)/2.0,(first.x+fourth().x)/2.0);
    return p;
}
Circle Square::incircle() const
{
    Circle c(centroid().x,centroid().y,a/2.0);
    return c;
}
void Square::translation(const Point& p)
{
    first.x+=p.x;
    first.y+=p.y;
}
void Square::rotationAroundCenter()
{
    first.x=-first.x;
    first.y=-first.y;
}
/*istream& operator>>(istream& is,Square& s)
{
    is>>s.first;
    is>>s.a;
    is>>s.degrees;
    return is;
}
ostream& operator<<(ostream& os,const Square& s)
{
    os<<s.first<<endl<<s.a<<endl<<s.degrees<<endl;
    return os;
}*/
