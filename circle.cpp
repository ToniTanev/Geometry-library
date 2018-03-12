#include"circle.h"
Circle::Circle(){}
Circle::Circle(double x1,double y1,double _radius)
{
    center.x=x1;
    center.y=y1;
    radius=_radius;
}
char* Circle::type() {return "Circle";}
Point Circle::getCenter() const {return center;}
double Circle::diameter() const {return radius*2;}
double Circle::getRadius() const {return radius;}
double Circle::area() const {return pi*radius*radius;}
double Circle::perim() const {return 2*pi*radius;}
bool Circle::isInside(const Point& p) const
{
    return ((p.x-center.x)*(p.x-center.x)+(p.y-center.y)*(p.y-center.y))<radius*radius;
}
int Circle::numberOfInsideCircles(const Circle& other)
{
    if(other.radius>(radius/2.0)) return 1;
    Circle c(0,0,radius-other.radius); //okrajnostta koqto shte namalqva
    int sum=0;
    while(c.radius>=other.radius)
    {
        sum+=numbOfCirclesOnCircle(c,other);
        c.radius-=other.diameter();
    }
    if(c.radius>=0) sum+=1; //ako se poluchava >=0 radius kolkoto i maluk da e vinagi shte moje da se pobere edna posledna okrujnost
    return sum;
}
void Circle::translation(const Point& p)
{
    center.x+=p.x;
    center.y+=p.y;
}
void Circle::rotationAroundCenter()
{
    center.x=-center.x;
    center.y=-center.y;
}
int numbOfCirclesOnCircle(const Circle& bigCircle,const Circle& smallCircle)
{
    double sin=smallCircle.getRadius()/bigCircle.getRadius();
    double alpha=asin(sin);
    return pi/alpha;
}

/*istream& operator>>(istream& is,Circle& c)
{
    is>>c.center;
    is>>c.radius;
    return is;
}
ostream& operator<<(ostream& os,const Circle& c)
{
    os<<c.center<<endl<<c.radius<<endl;
    return os;
}*/
