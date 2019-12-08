#include "Screen.h"

Screen::Screen()
{
    this->nextScreen = 0;
    this->ifNextScreen = false;
    this->quit = false;
    this->overlyingScreen = 0;
}

Screen::~Screen()
{
    // some code here
}

void Screen::SaveToFile(ofstream& f)
{

}

void Screen::ReadFromFile(ifstream& f)
{

}

bool Screen::IfMoveToNextScreen()
{
    return this->ifNextScreen;
}

void Screen:: PlayMusic()
{

}
