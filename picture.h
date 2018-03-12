#ifndef __PICTURE_H
#define __PICTURE_H
#include"square.h"
#include"circle.h"
#include"rectangle.h"
#include"triangle.h"
#include<vector>
class Picture
{
private:
    vector<Point> points;
public:
    vector<Figure*> figures;
    void addTriangle(const Triangle& t);
    void addRectangle(const Rectangle& r);
    void addCircle(const Circle& c);
    void addSquare(const Square& s);
    void deleteFigure();
    void deleteFigure(int index);
    double minimumX();
    double minimumY();
    double maximumX();
    double maximumY();
    bool isInsideIt(const Point& p);
    vector<Point> pictureIntersectPoints(Picture other);
};
#endif // __PICTURE_H
