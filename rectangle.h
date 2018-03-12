#ifndef __RECTANGLE_H
#define __RECTANGLE_H
#include"figure.h"
#include"functions.h"
class Rectangle:public Figure
{
private:
    //tochka first e A, tochka second e C, tochka third e ili C ili D, tochka fourth e ili D ili C
    Point first;
    Point second;
    double degrees; //ygylyt mejdu pravata, koqto minava prez first, i abcisata v gradusi
public:
    Rectangle();
    Rectangle(double x1,double y1,double x2,double y2,double _degrees);
    char* type();
    Point getFirst() const;
    Point getSecond() const;
    double getDegrees() const;
    double k_first() const;
    double n_first() const; //pravq taka che ako k=inf togava n=x tyi kato taka direktno dostigam x na tochkata i nqma golqmo znachenie n kolko e v tozi sluchai ( imame grafika na funkciq ot vida x=a)
    double k_second() const;
    double n_second() const;
    Point third() const;
    Point fourth() const;
    double a() const;
    double b() const;
    double area() const;
    double perim() const;
   /* bool isInside(Point p) const
    {
        Triangle t1(first.x,first.y,third().x,third().y,p.x,p.y),t2(third().x,third().y,second.x,second.y,p.x,p.y),
                 t3(second.x,second.y,fourth().x,fourth().y,p.x,p.y),t4(fourth().x,fourth().y,first.x,first.y,p.x,p.y);
        double tArea=t1.area()+t2.area()+t3.area()+t4.area();
        cout<<t1.area()+t2.area()+t3.area()+t4.area()<<endl;
        cout<<area()<<endl;
        return ((int)tArea==(int)area())&&(t1.area()!=0)&&(t2.area()!=0)&&(t3.area()!=0)&&(t4.area()!=0); //sravnqvaneto ne raboti s double-li, tyi kato raboti s tochni stoinosti, a ne priblijeni
    }*/
    bool isInside(const Point& p) const;
    Point centroid() const;
    void translation(const Point& p);
    void rotationAroundCenter();
    friend istream& operator>>(istream &is,Rectangle& r);
    friend ostream& operator<<(ostream& os,const Rectangle& r);
};
#endif // __RECTANGLE_H
