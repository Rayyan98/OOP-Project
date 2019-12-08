#include "ACharacter.h"
#include <SDL_image.h>
#include "Global.h"

ACharacter::ACharacter()
{

}

ACharacter::ACharacter(SDL_Renderer* gRenderer, string str, string color, Point anchor)
{
    this->anchor = anchor;
    this->chr = str;
    this->color = color;
    string string1("Alphabets OOP Project FINAL\\");
    string string2("_");
    string string3(".png");
    string tempString = string1+str+string2+color+string3;
    int length = tempString.size();
    path = new char[length + 1];
    for(int i = 0; i < length; i++)
    {
        path[i] = tempString[i];
    }
    path[length] = 0;
    this->temp  = IMG_Load(path);
    if(temp == NULL)
    {
        std::cout << "| IMG Load failed "+tempString+" |";
    }
    else
    {
        this->img = SDL_CreateTextureFromSurface(gRenderer, temp);
        SDL_FreeSurface(this->temp);
        temp = 0;
        SDL_QueryTexture(img, NULL, NULL, &(this->origWidth), &(this->origHeight));
        this->lastWidth = this->origWidth;
        this->lastHeight = this->origHeight;
    }
}

ACharacter::~ACharacter()
{
    SDL_DestroyTexture(img);
    delete path;
}

void ACharacter::Render(SDL_Renderer* gRenderer, Point& point, int height)
{
    if(this->img != 0)
    {
        Point temp = Global::CorrectedPos(this->anchor, point);
        this->dstRect.x = temp.x;
        this->dstRect.y = temp.y;
        this->lastWidth = this->dstRect.w = Global::CorrectWidth(this->origWidth, this->origHeight, height);
        this->lastHeight = this->dstRect.h = height;
        SDL_RenderCopy(gRenderer, img, NULL, &dstRect);
    }
}

int ACharacter::GetProjectedWidth(int height)
{
    return Global::CorrectWidth(this->origWidth, this->origHeight, height);
}
