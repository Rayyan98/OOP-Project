#include "Figure.h"
#include "Global.h"

Figure::Figure()
{

}

Figure::Figure(SDL_Texture* spriteSheet, Point startPos, Point endPos,
               Point nextSprite, int totalSprites, bool defaultOrientation,
               bool loop, floatAnchor fAnchor)
{
    this->spriteSheet = spriteSheet;
    this->nextSprite = nextSprite;
    this->srcRect.x = startPos.x;
    this->srcRect.y = startPos.y;
    this->srcRect.w = endPos.x - startPos.x;
    this->height = this->srcRect.h = endPos.y - startPos.y;
    this->totalSprites = totalSprites;
    this->defaultOrientation = defaultOrientation;
    this->loop = loop;
    this->fAnchor = fAnchor;
    this->currentSprite = 1;
}

Figure::~Figure()
{

}

void Figure::Render(SDL_Renderer* gRenderer, Point pos, int height, bool orientation, bool animate)
{
    if(animate)
    {
        if(currentSprite < totalSprites)
        {
            srcRect.x += nextSprite.x;
            srcRect.y += nextSprite.y;
            currentSprite ++;
        }
        else if(loop)
        {
            currentSprite = 1;
            srcRect.x -= (totalSprites - currentSprite)*nextSprite.x;
            srcRect.y -= (totalSprites - currentSprite)*nextSprite.y;
        }
    }
    SDL_Rect dstRect;
    if(height == 0)
    {
        dstRect = srcRect;
    }
    else
    {
        dstRect.w = Global::CorrectWidth(srcRect.w, srcRect.h, height);
        dstRect.h = height;
    }
    Point temp = Global::CorrectedPos(fAnchor.superImpose(dstRect.w, dstRect.h), pos);
    dstRect.x = temp.x;
    dstRect.y = temp.y;

    if(orientation == defaultOrientation)
    {
        SDL_RenderCopy(gRenderer, spriteSheet, &srcRect, &dstRect);
    }
    else
    {
        SDL_RenderCopyEx(gRenderer, spriteSheet, &srcRect, &dstRect, 0.0, 0, SDL_FLIP_HORIZONTAL);
    }
}

int Figure::ProjectedWidth(int height)
{
    return (height * srcRect.w) / srcRect.h;
}
