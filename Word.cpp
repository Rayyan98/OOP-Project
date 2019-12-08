#include "Word.h"
#include "Global.h"
#include "ACharacter.h"
#include <string>

string gold("gold");
string black("black");
string red("red");

Word::Word()
{

}

Word::Word(string word, Point anchor)
{
    this->length = word.size();
    this->anchor = anchor;
    this->word = word;
    this->charTextures = new ACharacter*[this->length];
    char asciiChar;
    int tempAsciiNum;
    for(int i = 0; i < this->length; i++)
    {
        asciiChar = word[i];
        asciiChar = toupper(asciiChar);
        tempAsciiNum = asciiChar;
        if(48 <= tempAsciiNum && tempAsciiNum <= 57)
        {
            charTextures[i] = Global::allCharacters[tempAsciiNum - 48];
        }
        else if(65 <= tempAsciiNum && tempAsciiNum <= 90)
        {
            charTextures[i] = Global::allCharacters[tempAsciiNum - 65 + 10];
        }
        else if (tempAsciiNum == 32)
        {
            charTextures[i] = 0;
        }
        else
        {
            std::cout << "bad character" << std::endl;
        }
    }
}

Word::~Word()
{
    delete [] charTextures;
}

void Word::Render(SDL_Renderer* gRenderer, Point position, int height, string color)
{
    int factor = 0;
    if(color == gold)
    {
        factor = 36;
    }
    else if (color == red)
    {
        factor = 72;
    }
    Point temp = Global::CorrectedPos(anchor, position);
    for(int i = 0; i < this->length; i++)
    {
        if(charTextures[i] == 0)
        {
            temp.x += height / 2;
        }
        else
        {
            int indOfChar = Global::FindIndOfChar(charTextures[i]);
            if(indOfChar < 0)
            {
                std::cout << "char not found" << std::endl;
            }
            Global::allCharacters[indOfChar + factor]->Render(gRenderer, temp, height);
            temp.x += Global::allCharacters[indOfChar + factor]->lastWidth;
        }
    }
}

int Word::GetProjectedWidth(int height)
{
    int projWidth = 0;
    for(int i = 0; i < this->length; i++)
    {
        if(charTextures[i] != 0)
        {
            projWidth += charTextures[i]->GetProjectedWidth(height);
        }
        else
        {
            projWidth += height / 2;
        }
    }
    return projWidth;
}
