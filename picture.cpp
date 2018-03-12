#include"picture.h"
void Picture::addTriangle(const Triangle& t)
{
    Figure* tr=new Triangle(t.getA().x,t.getA().y,t.getB().x,t.getB().y,t.getC().x,t.getC().y);
    figures.push_back(tr);
    points.push_back(t.getA());
    points.push_back(t.getB());
    points.push_back(t.getC());
}
void Picture::addRectangle(const Rectangle& r)
{
    Figure* rect=new Rectangle(r.getFirst().x,r.getFirst().y,r.getSecond().x,r.getSecond().y,r.getDegrees());
    figures.push_back(rect);
    points.push_back(r.getFirst());
    points.push_back(r.getSecond());
    points.push_back(r.third());
    points.push_back(r.fourth());
}
void Picture::addCircle(const Circle& c)
{
    Figure* circle=new Circle(c.getCenter().x,c.getCenter().y,c.getRadius());
    figures.push_back(circle);
    Point top(c.getCenter().x,c.getCenter().y+c.getRadius()),right(c.getCenter().x+c.getRadius(),c.getCenter().y),
          bot(c.getCenter().x,c.getCenter().y-c.getRadius()),left(c.getCenter().x-c.getRadius(),c.getCenter().y);
    points.push_back(left);
    points.push_back(right);
    points.push_back(top);
    points.push_back(bot);
}
void Picture::addSquare(const Square& s)
{
    Square* sq=new Square(s.getFirst().x,s.getFirst().y,s.getA(),s.getDegrees());
    figures.push_back(sq);
    points.push_back(s.getFirst());
    points.push_back(s.second());
    points.push_back(s.third());
    points.push_back(s.fourth());
}
void Picture::deleteFigure()
{
    figures.pop_back();
}
void Picture::deleteFigure(int index)
{
    swap(figures[index],figures[figures.size()-1]);
    figures.pop_back();
}
double Picture::minimumX()
{
    double minimum=points[0].x;
    for(int i=1;i<points.size();i++)
    {
        if(points[i].x<minimum) minimum=points[i].x;
    }
    return minimum;
}
double Picture::minimumY()
{
    double minimum=points[0].y;
    for(int i=1;i<points.size();i++)
    {
        if(points[i].y<minimum) minimum=points[i].y;
    }
    return minimum;
}
double Picture::maximumX()
{
    double maximum=points[0].x;
    for(int i=1;i<points.size();i++)
    {
        if(points[i].x>maximum) maximum=points[i].x;
    }
    return maximum;
}
double Picture::maximumY()
{
    double maximum=points[0].y;
    for(int i=1;i<points.size();i++)
    {
        if(points[i].y>maximum) maximum=points[i].y;
    }
    return maximum;
}
bool Picture::isInsideIt(const Point& p)
{
    for(int i=0;i<figures.size();i++)
        if(figures[i]->isInside(p)) return true;
    return false;
}
vector<Point> Picture::pictureIntersectPoints(Picture other)
{
    vector<Point> intersectPoints;
    for(int i=minimumX()-1;i<=maximumX()+1;i++)
    {
        for(int j=minimumY()-1;j<=maximumY()+1;j++)
        {
            Point p(i,j);
            if(isInsideIt(p)&&other.isInsideIt(p))
                intersectPoints.push_back(p);
        }
    }
    return intersectPoints;
}
