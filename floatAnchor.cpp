#include "floatAnchor.h"

floatAnchor::floatAnchor()
{

}

floatAnchor::floatAnchor(float x, float y)
{
    this->x = x;
    this->y = y;
}

floatAnchor::~floatAnchor()
{

}

Point floatAnchor::superImpose(int width, int height)
{
    Point temp;
    temp.x = this->x * width;
    temp.y = this->y * height;
    return temp;
}
