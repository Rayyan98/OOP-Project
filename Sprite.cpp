#pragma once
#include "Sprite.h"
#include "Point.h"
#include "floatAnchor.h"
#include <SDL.h>
#include "Global.h"

Sprite::Sprite()
{

}

Sprite::Sprite(SDL_Texture* spriteSheet, Point startPosition, Point endPosition, Point anchor,
               Point* highHitRects, Point* lowHitRects, Point* hultRects, bool defaultOrientation)
{
    this->spriteSheet = spriteSheet;
    this->anchor.x = anchor.x - startPosition.x;
    this->anchor.y = anchor.y - startPosition.y;
    this->reverseAnchor.y = anchor.y;
    this->reverseAnchor.x = endPosition.x - anchor.x;
    this->srcRect.x = startPosition.x;
    this->srcRect.y = startPosition.y;
    this->srcRect.w = endPosition.x - startPosition.x;
    this->srcRect.h = endPosition.y - startPosition.y;
    this->defaultOrientation = defaultOrientation;
    Point hitPosition;
    Point hultPosition;

    if(highHitRects != 0)
    {
        this->numberHighHitBoxes = (checkLength(highHitRects)/2);
        this->highHitRects = new SDL_Rect*[numberHighHitBoxes+1]; //last is null character
        this->reverseHighHitRects = new SDL_Rect*[numberHighHitBoxes+1];
        for (int i = 0; i < (numberHighHitBoxes*2); i+=2)
        {
//            cout << "called ";
            hitPosition = highHitRects[i+1] - highHitRects[i];
            this->highHitRects[i/2] = new SDL_Rect;
            this->highHitRects[i/2]->w = hitPosition.x;
            this->highHitRects[i/2]->h = hitPosition.y;
            this->highHitRects[i/2]->x = highHitRects[i].x - startPosition.x;
            this->highHitRects[i/2]->y = highHitRects[i].y - startPosition.y;
            this->reverseHighHitRects[i/2] = new SDL_Rect;
            this->reverseHighHitRects[i/2]->x = endPosition.x - highHitRects[i+1].x;
            this->reverseHighHitRects[i/2]->y = this->highHitRects[i/2]->y;
            this->reverseHighHitRects[i/2]->w = this->highHitRects[i/2]->w;
            this->reverseHighHitRects[i/2]->h = this->highHitRects[i/2]->h;
        }
        this->highHitRects[numberHighHitBoxes] = 0;
        this->reverseHighHitRects[numberHighHitBoxes] = 0;
    }
    else
    {
        this->highHitRects = 0;
        this->numberHighHitBoxes = 0;
        this->reverseHighHitRects = 0;
    }

    if(lowHitRects != 0)
    {
        this->numberLowHitBoxes = (checkLength(lowHitRects)/2);
        this->lowHitRects = new SDL_Rect*[numberLowHitBoxes+1]; //last is null character
        this->reverseLowHitRects = new SDL_Rect*[numberLowHitBoxes+1];
        for (int i = 0; i < (numberLowHitBoxes*2); i+=2)
        {
            hitPosition = lowHitRects[i+1] - lowHitRects[i];
            this->lowHitRects[i/2] = new SDL_Rect;
            this->lowHitRects[i/2]->w = hitPosition.x;
            this->lowHitRects[i/2]->h = hitPosition.y;
            this->lowHitRects[i/2]->x = lowHitRects[i].x - startPosition.x;
            this->lowHitRects[i/2]->y = lowHitRects[i].y - startPosition.y;
            this->reverseLowHitRects[i/2] = new SDL_Rect;
            this->reverseLowHitRects[i/2]->x = endPosition.x - lowHitRects[i+1].x;
            this->reverseLowHitRects[i/2]->y = this->lowHitRects[i/2]->y;
            this->reverseLowHitRects[i/2]->w = this->lowHitRects[i/2]->w;
            this->reverseLowHitRects[i/2]->h = this->lowHitRects[i/2]->h;
        }
        this->reverseLowHitRects[numberLowHitBoxes] = 0;
        this->lowHitRects[numberLowHitBoxes] = 0;
    }
    else
    {
        this->lowHitRects = 0;
        this->numberLowHitBoxes = 0;
        this->reverseLowHitRects = 0;
    }

    if (hultRects != 0)
    {
        this->numberHultBoxes = (checkLength(hultRects)/2);
        this->hultRects = new SDL_Rect*[numberHultBoxes+1];
        this->reverseHultRects = new SDL_Rect*[numberHultBoxes+1];
        for (int i = 0; i < (numberHultBoxes*2); i+=2)
        {
            hultPosition = hultRects[i+1] - hultRects[i];
            this->hultRects[i/2] = new SDL_Rect;
            this->hultRects[i/2]->w = hultPosition.x;
            this->hultRects[i/2]->h = hultPosition.y;
            this->hultRects[i/2]->x = hultRects[i].x - startPosition.x;
            this->hultRects[i/2]->y = hultRects[i].y - startPosition.y;
            this->reverseHultRects[i/2] = new SDL_Rect;
            this->reverseHultRects[i/2]->x = endPosition.x - hultRects[i+1].x;
            this->reverseHultRects[i/2]->h = this->hultRects[i/2]->h;
            this->reverseHultRects[i/2]->w = this->hultRects[i/2]->w;
            this->reverseHultRects[i/2]->y = this->hultRects[i/2]->y;
        }
        this->hultRects[numberHultBoxes] = 0;
        this->reverseHultRects[numberHultBoxes] = 0;
    }
    else
    {
        this->hultRects = 0;
        this->numberHultBoxes = 0;
        this->reverseHultRects = 0;
    }
}

int Sprite::checkLength(Point* points)
{
    int length = 0;
    while(points[length] != Point(-700,-700))
    {
        length++;
    }
    return length;
}

Sprite::~Sprite()
{
    delete [] hultRects;
    delete [] lowHitRects;
    delete [] highHitRects;
    delete [] reverseHighHitRects;
    delete [] reverseHultRects;
    delete [] reverseLowHitRects;
}


void Sprite::UpdateSprite(Point pos, bool currentOrientation)
{
    Point tempAnchor;
    this->currentOrientation = currentOrientation;
    if (currentOrientation == defaultOrientation)
    {
        tempAnchor = this->anchor;
    }
    else
    {
        tempAnchor = this->reverseAnchor;
    }
    Point newPosition = Global::CorrectedPos(tempAnchor,pos);
    destRect.x = newPosition.x;
    destRect.y = newPosition.y;
//    cout << destRect.x << " " << destRect.y << " position top left " << endl;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

void Sprite::Render(SDL_Renderer* gRenderer)
{
    SDL_Rect r;
    if (currentOrientation == defaultOrientation)
    {
        SDL_RenderCopy(gRenderer, spriteSheet, &srcRect, &destRect);
//        cout << srcRect.x << " " << srcRect.y << " " << srcRect.w << " " << srcRect.h << endl;
//        SDL_SetRenderDrawColor(gRenderer, 0 , 0, 0,255);
//        SDL_RenderDrawRect(gRenderer, &destRect);
//        for(int i = 0; i < numberHighHitBoxes; i++)
//        {
//            SDL_SetRenderDrawColor(gRenderer, 0 ,255,255,255);
//            r = *highHitRects[i];
//            r.x += destRect.x;
//            r.y += destRect.y;
//            SDL_RenderDrawRect(gRenderer, &r);
//        }
//        for(int i = 0; i < numberLowHitBoxes; i++)
//        {
//            SDL_SetRenderDrawColor(gRenderer, 0 ,255,0,255);
//            r = *lowHitRects[i];
//            r.x += destRect.x;
//            r.y += destRect.y;
//            SDL_RenderDrawRect(gRenderer, &r);
//        }
//        for(int i = 0; i < numberHultBoxes; i++)
//        {
//            SDL_SetRenderDrawColor(gRenderer, 255 ,0,0,255);
//            r = *hultRects[i];
//            r.x += destRect.x;
//            r.y += destRect.y;
//            SDL_RenderDrawRect(gRenderer, &r);
//        }
    }
    else
    {
        SDL_RenderCopyEx( gRenderer, spriteSheet, &srcRect, &destRect, 0, 0, SDL_FLIP_HORIZONTAL);
//        for(int i = 0; i < numberHighHitBoxes; i++)
//        {
//            r = *reverseHighHitRects[i];
//            r.x += destRect.x;
//            r.y += destRect.y;
//            SDL_SetRenderDrawColor(gRenderer, 0 ,255,255,255);
//            SDL_RenderDrawRect(gRenderer, &r);
//        }
//        for(int i = 0; i < numberLowHitBoxes; i++)
//        {
//            r = *reverseLowHitRects[i];
//            r.x += destRect.x;
//            r.y += destRect.y;
//            SDL_SetRenderDrawColor(gRenderer, 0 ,255,0,255);
//            SDL_RenderDrawRect(gRenderer, &r);
//
//        }
//        for(int i = 0; i < numberHultBoxes; i++)
//        {
//            r = *reverseHultRects[i];
//            r.x += destRect.x;
//            r.y += destRect.y;
//            SDL_SetRenderDrawColor(gRenderer, 255 ,0,0,255);
//            SDL_RenderDrawRect(gRenderer, &r);
//        }
    }
}

SDL_Rect** Sprite::GetHighHitRects()
{
    if(currentOrientation == defaultOrientation)
    {
        return highHitRects;
    }
    else
    {
        return reverseHighHitRects;
    }
}

SDL_Rect** Sprite::GetLowHitRects()
{
    if(currentOrientation == defaultOrientation)
    {
        return lowHitRects;
    }
    else
    {
        return reverseLowHitRects;
    }
}

SDL_Rect** Sprite::GetHultRects()
{
    if(currentOrientation == defaultOrientation)
    {
        return hultRects;
    }
    else
    {
        return reverseHultRects;
    }
}

SDL_Rect* Sprite::GetDestRect()
{
    return &destRect;
}

