#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point
{
public:
    int x;
    int y;
    Point();
    Point(int,int);
    bool operator!=(Point pointer);
    Point operator-(Point pointer);
    ~Point();
};

#endif // POINT_H
