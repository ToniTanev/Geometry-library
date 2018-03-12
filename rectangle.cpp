#include"rectangle.h"
Rectangle::Rectangle(){}
Rectangle::Rectangle(double x1,double y1,double x2,double y2,double _degrees)
{
    first.x=x1;
    first.y=y1;
    second.x=x2;
    second.y=y2;
    degrees=_degrees;
}
char* Rectangle::type() {return "Rectangle";}
Point Rectangle::getFirst() const {return first;}
Point Rectangle::getSecond() const {return second;}
double Rectangle::getDegrees() const {return degrees;}
double Rectangle::k_first() const {return degrees==90?INFINITY:tan(degreesToRadians(degrees));}
double Rectangle::n_first() const {return k_first()==INFINITY||k_first()==-INFINITY?first.x:first.y-first.x*k_first();} //pravq taka che ako k=inf togava n=x tyi kato taka direktno dostigam x na tochkata i nqma golqmo znachenie n kolko e v tozi sluchai ( imame grafika na funkciq ot vida x=a)
double Rectangle::k_second() const {return -1/(k_first());}
double Rectangle::n_second() const {return k_second()==INFINITY||k_second()==-INFINITY?second.x:second.y-second.x*k_second();}
Point Rectangle::third() const {return intersectPoint(k_first(),n_first(),k_second(),n_second());}
Point Rectangle::fourth() const
{
    double k1=k_first();
    double n1=k_first()==INFINITY||k_first()==-INFINITY?second.x:second.y-second.x*k_first();
    double k2=k_second();
    double n2=k_second()==INFINITY||k_second()==-INFINITY?first.x:first.y-first.x*k_second();
    return intersectPoint(k1,n1,k2,n2);
}
double Rectangle::a() const {return distBetweenPoints(first,third());}
double Rectangle::b() const {return distBetweenPoints(second,third());}
double Rectangle::area() const {return a()*b();}
double Rectangle::perim() const {return 2*a()+2*b();}
   /* bool isInside(Point p) const
    {
        Triangle t1(first.x,first.y,third().x,third().y,p.x,p.y),t2(third().x,third().y,second.x,second.y,p.x,p.y),
                 t3(second.x,second.y,fourth().x,fourth().y,p.x,p.y),t4(fourth().x,fourth().y,first.x,first.y,p.x,p.y);
        double tArea=t1.area()+t2.area()+t3.area()+t4.area();
        cout<<t1.area()+t2.area()+t3.area()+t4.area()<<endl;
        cout<<area()<<endl;
        return ((int)tArea==(int)area())&&(t1.area()!=0)&&(t2.area()!=0)&&(t3.area()!=0)&&(t4.area()!=0); //sravnqvaneto ne raboti s double-li, tyi kato raboti s tochni stoinosti, a ne priblijeni
    }*/
bool Rectangle::isInside(const Point& p) const
{
    //pravq si vektori
    Point AB(third().x-first.x,third().y-first.y);
    Point AD(fourth().x-first.x,fourth().y-first.y);
    Point AP(p.x-first.x,p.y-first.y);
    return AP*AB<AB*AB&&AP*AB>0&&AP*AD<AD*AD&&AP*AD>0;
}
Point Rectangle::centroid() const
{
    Point p((first.x+second.x)/2.0,(first.y+second.y)/2.0);
    return p;
}
void Rectangle::translation(const Point& p)
{
    first.x+=p.x;
    first.y+=p.y;
    second.x+=p.x;
    second.y+=p.y;
}
void Rectangle::rotationAroundCenter()
{
    first.x=-first.x;
    first.y=-first.y;
    second.x=-first.x;
    second.y=-first.y;
}
/*istream& operator>>(istream& is,Rectangle& r)
{
    is>>r.first;
    is>>r.second;
    is>>r.degrees;
    return is;
}
ostream& operator<<(ostream& os,const Rectangle& r)
{
    os<<r.first<<endl<<r.second<<endl<<r.degrees<<endl;
    return os;
}*/
