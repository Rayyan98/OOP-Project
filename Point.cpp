#include "Point.h"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

bool Point::operator!=(Point pointer)
{
    if (this->x != pointer.x)
    {
        return true;
    }
    else if (this->y != pointer.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Point Point::operator-(Point pointer)
{
    Point points;
    points.x = this->x - pointer.x;
    points.y = this->y - pointer.y;
    return points;
}
Point::~Point()
{

}
