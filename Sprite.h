#pragma once
#include "Point.h"
#include "floatAnchor.h"
#include <SDL.h>
#include "Global.h"
//har image aik invidual sprite conustittue kregi.
//width hieght.
//anchor. a point which is called, sprties ko allign kese krna hai. if a point 30,30 on screen tou
//attribute : width highrt image location , rectangle ,
// two arrays SDL_RECT  1st array will have hit boxes yahan lagi tou damage. second array : store hut boxes.
//defualt constructor.
//bigger constructore (with 5-6 parameter)
//destructos : delets all what created.
// point storing start and end point (in a sprite sheet)
// point in constructor (storing default position)
//render ke andar G rendered.
class Sprite
{
    private:
        SDL_Texture* spriteSheet;
        SDL_Rect srcRect;
        Point anchor;
        SDL_Rect** highHitRects;
        SDL_Rect** lowHitRects;
        SDL_Rect** hultRects;
        bool defaultOrientation;  //will be 0 or 1 and facing right is 0 default.
        int numberHighHitBoxes;
        int numberLowHitBoxes;
        int numberHultBoxes;

        Point reverseAnchor;
        SDL_Rect** reverseHighHitRects;
        SDL_Rect** reverseLowHitRects;
        SDL_Rect** reverseHultRects;

        SDL_Rect destRect;
        bool currentOrientation;

        int checkLength(Point* points);

    public:
        Sprite();
        ~Sprite();
        Sprite(SDL_Texture*, Point, Point, Point,Point*, Point*, Point*,bool);
        SDL_Rect** GetHighHitRects();
        SDL_Rect** GetLowHitRects();
        SDL_Rect** GetHultRects();
        SDL_Rect* GetDestRect();
        void UpdateSprite(Point, bool orientation);
        void Render(SDL_Renderer* gRenderer);// dest rect . //render copy functiuo from SDL.
};
