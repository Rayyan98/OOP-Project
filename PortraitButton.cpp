#include "PortraitButton.h"
#include "CharacterSelect.h"
#include "Global.h"


PortraitButton::PortraitButton()
{

}

PortraitButton::~PortraitButton()
{

}

PortraitButton::PortraitButton(SDL_Texture* img, Point startPos, Point endPos,
                               Point position, int defaultHeight, int selectedHeight,
                               floatAnchor inVariant) : Button(defaultHeight, selectedHeight,
                                                               position, inVariant)
{
    this->characterPortraits = img;
    srcRect.x = startPos.x;
    srcRect.y = startPos.y;
    srcRect.w = endPos.x - startPos.x;
    srcRect.h = endPos.y - startPos.y;
}

void PortraitButton::Render(SDL_Renderer* gRenderer, bool selected, Point position)
{
    if(position.x == -700 && position.y == -700)
    {
        position = this->position;
    }
    if(selected)
    {
        if(currentHeight < selectedHeight)
        {
            currentHeight += (selectedHeight - defaultHeight) / buttonAnimationFrames;
        }
        if(currentHeight > selectedHeight)
        {
            currentHeight = selectedHeight;
        }
    }
    else
    {
        if(currentHeight > defaultHeight)
        {
            currentHeight -= (selectedHeight - defaultHeight) / buttonAnimationFrames;
        }
        if(currentHeight < defaultHeight)
        {
            currentHeight = defaultHeight;
        }
    }

    SDL_Rect dstRect;
    dstRect.w = Global::CorrectWidth(srcRect.w, srcRect.h, currentHeight);
    dstRect.h = currentHeight;
    Point tempPoint = Global::CorrectedPos(inVariant.superImpose(dstRect.w, dstRect.h), position);
    dstRect.x = tempPoint.x;
    dstRect.y = tempPoint.y;
//    cout << dstRect.x << " " << dstRect.y << endl;
//e    cout << srcRect.x << " " << srcRect.y << endl;
    SDL_RenderCopy(gRenderer, characterPortraits, &srcRect, &dstRect);
}
