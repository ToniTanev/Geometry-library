#include <iostream>

using namespace std;
#include"circle.h"
#include"triangle.h"
#include"rectangle.h"
#include"square.h"
#include"picture.h"
void testTriangle()
{
    Triangle t(0,0,0,1,1,0);
    Point p(227,32);
    cout<<t.angle("AC","AB")<<endl; //in radians
    cout<<t.signedArea()<<endl;
    cout<<t.isInside(p)<<endl;
    Triangle t1(18,35,33,17,82,9);
    t1.centroid();
    t1.incenter();
    Triangle t2(2,1,2,3,4,5);
    t2.circumcenter();
    Triangle t3(0,1,0,2,0,3);
    cout<<t3.area()<<' '<<t3.signedArea()<<endl;
}
void testCircle()
{
    Circle c(0,0,256.64),insideCircle(0,0,8.98);
    cout<<c.numberOfInsideCircles(insideCircle)<<endl;
    cout<<c.perim()<<endl<<insideCircle.perim();
}
void testIntersectPoint()
{
    Point p;
    p=intersectPoint(1,0,-1,4);
   // cout<<p;
}
void testRectangle()
{
    Rectangle r(0,0,1,2,90);
    cout<<r.k_first()<<endl;
    cout<<r.k_second()<<endl;
    cout<<r.area()<<' '<<r.a()<<' '<<r.perim()<<endl;
    cout<<r.third().x<<' '<<r.third().y<<' '<<r.fourth().x<<' '<<r.fourth().y<<endl;
    Rectangle r1(0,0,5,5,0);
    Point p(6,6);
    cout<<r1.isInside(p)<<' '<<r1.area()<<endl;
}
void testSquare()
{
    Square s(0,0,2,0);
    //cout<<s.second()<<endl<<s.third()<<endl<<s.fourth();
    Point p(1.9,1.9);
    cout<<endl<<s.isInside(p)<<endl;
}
void testPicture()
{
    Picture p;
    Square s(0,0,2,90);
    Circle c(0,0,3);
    Rectangle r(0,0,0,4,0);
    Triangle t(0,0,0,1,5,0);
    p.addCircle(c);
    p.addRectangle(r);
    p.addTriangle(t);
    p.addSquare(s);
    p.deleteFigure(2);
    Point point(0,0);
    Point trVector(6,6);
    for(int i=0;i<p.figures.size();i++)
    {
        //cout<<p.figures[i]->area()<<endl;
       // cout<<p.figures[i]->perim()<<endl;
        cout<<p.figures[i]->isInside(point)<<endl;
        //cout<<p.figures[i]->centroid()<<endl;
        p.figures[i]->translation(trVector);
        cout<<p.figures[i]->isInside(point)<<endl;
    }
}
int main()
{
    testTriangle();
    //testCircle();
    //testIntersectPoint();
    //testRectangle();
    //testSquare();
    //testPicture();
    return 0;
}
