#pragma once
#include <SDL_image.h>
#include <SDL_Mixer.h>
#include "Point.h"
#include "Sprite.h"

class CollisionDetection
{
    public:
        static int lastCall;
        static bool Check(SDL_Rect*, SDL_Rect*, Point point1 = Point(0,0), Point point2 = Point(0,0));
        static bool Check(SDL_Rect**, SDL_Rect*, Point&, Point&);
        static bool Check(SDL_Rect**, SDL_Rect**, Point&, Point&);
        static int Check(Sprite*, Sprite*);
    protected:

    private:
};
