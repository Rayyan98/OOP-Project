#pragma once
#include "Point.h"

class floatAnchor
{
public:
    float x;
    float y;
public:
    floatAnchor();
    ~floatAnchor();
    floatAnchor(float, float);
    Point superImpose(int, int);
};
