#include "TextButton.h"
#include "Global.h"


TextButton::TextButton()
{

}

TextButton::~TextButton()
{
    delete this->word;
}

TextButton::TextButton(string text, Point position, int defaultHeight,
                       int selectedHeight, string defaultColor, string selectedColor,
                       floatAnchor inVariant) : Button(defaultHeight, selectedHeight,
                                                       position, inVariant)
{
    this->defaultColor = defaultColor;
    if(selectedColor == string("null"))
    {
        this->selectedColor = defaultColor;
    }
    else
    {
        this->selectedColor = selectedColor;
    }
    this->word = new Word(text);
}

void TextButton::Render(SDL_Renderer* gRenderer, bool selected, Point position)
{
    if(position.x == -700 && position.y == -700)
    {
        position = this->position;
    }
    string tempColor;
    if(selected)
    {
        tempColor = this->selectedColor;
        if(this->currentHeight < this->selectedHeight)
        {
            this->currentHeight += (this->selectedHeight - this->defaultHeight) / buttonAnimationFrames;
        }
        if(this->currentHeight > this->selectedHeight)
        {
            this->currentHeight = this->selectedHeight;
        }
    }
    else
    {
        tempColor = this->defaultColor;
        if(this->currentHeight > defaultHeight)
        {
            this->currentHeight -= (this->selectedHeight - this->defaultHeight) / buttonAnimationFrames;
        }
        if(this->currentHeight < defaultHeight)
        {
            this->currentHeight = this->defaultHeight;
        }
    }

    int projWidth = word->GetProjectedWidth(this->currentHeight);
    Point anchor = inVariant.superImpose(projWidth, this->currentHeight);
    Point correctedPos = Global::CorrectedPos(anchor, position);
    word->Render(gRenderer, correctedPos, this->currentHeight, tempColor);
}

void TextButton:: ChangeWord(string str)
{
    Word* temp = this->word;
    this->word = new Word(str);
    delete temp;
}
