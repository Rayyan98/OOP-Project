#include "Collision Detection.h"

int CollisionDetection::lastCall = -1;

enum{cNone, cHultHult, cHultHigh, cHultLow,
            cHighHult, cHighHigh, cHighLow,
            cLowHult , cLowHigh , cLowLow};

bool CollisionDetection::Check(SDL_Rect* rect1, SDL_Rect* rect2, Point point1, Point point2)
{
//    cout << " passed check three" << endl;
//    cout << point1.x << " " << point1.y <<  " point 1"<< endl;
//    cout << point2.x << " " << point2.y << " point 2"<<endl;
//    cout << rect1->x << " " << rect1->y << " " << rect1->w << " " << rect1->h << endl;
//    cout << rect2->x << " " << rect2->y << " " << rect2->w << " " << rect2->h << endl;
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = rect1->x + point1.x;
    rightA = leftA + rect1->w;
    topA = rect1->y + point1.y;
    bottomA = topA + rect1->h;

    leftB = rect2->x + point2.x;
    rightB = leftB + rect2->w;
    topB = rect2->y + point2.y;
    bottomB = topB + rect2->h;

    if( bottomA <= topB )
    {
//        cout << " check failed 1" << endl;
//        cout << bottomA << " " << topB << endl;
        return false;
    }
    if( topA >= bottomB )
    {
//        cout << " check failed 2" << endl;
//        cout << topA << " " << bottomB << endl;
        return false;
    }
    if( rightA <= leftB )
    {
//        cout << " check failed 3" << endl;
//        cout << rightA << " " << leftB << endl;
        return false;
    }
    if( leftA >= rightB )
    {
//        cout << " check failed 4" << endl;
//        cout << leftA << " " << rightB << endl;
        return false;
    }
    return true;
}

bool CollisionDetection::Check(SDL_Rect** rect, SDL_Rect* rect2, Point& point1, Point& point2)
{
    if(rect == 0)
    {
        return false;
    }
    int i = 0;
//    cout << " passed check 2" << endl;
    while( rect[i] != 0 )
    {
//        cout << "passed check 2.1 " << endl;
        if (Check(rect[i], rect2, point1, point2))
        {
            return true;
        }
        i++;
    }
    return false;
}

bool CollisionDetection::Check(SDL_Rect** rect, SDL_Rect** recta, Point& point1, Point& point2)
{
    if(rect == 0 || recta == 0)
    {
        return false;
    }
//    cout << "passed check 1" << endl;
    int i = 0;
    while( rect[i] != 0 )
    {
        if (Check(recta, rect[i], point2, point1))
        {
            return true;
        }
        i++;
    }
    return false;
}

int CollisionDetection::Check(Sprite* sp1, Sprite* sp2)
{
    if(!Check((sp1->GetDestRect()), (sp2->GetDestRect())))
    {
        return cNone;
    }
//    cout << "reacehd -----------------" << endl;
    Point p1;
    Point p2;
    p1.x = sp1->GetDestRect()->x;
    p1.y = sp1->GetDestRect()->y;
    p2.x = sp2->GetDestRect()->x;
    p2.y = sp2->GetDestRect()->y;
//    cout << " called " << endl;
    if(Check(sp1->GetHultRects(), sp2->GetHultRects(),p1,p2))
    {
        return cHultHult;
    }
    if(Check(sp1->GetHultRects(), sp2->GetHighHitRects(),p1,p2))
    {
        return cHultHigh;
    }
    if(Check(sp1->GetHultRects(), sp2->GetLowHitRects(),p1,p2))
    {
//        cout << "condition here ---------------------------------------------" << endl;
        return cHultLow;
    }
//    cout << " break off here ---------------------------------------------" << endl;
    if(Check(sp1->GetHighHitRects(), sp2->GetHultRects(),p1,p2))
    {
        return cHighHult;
    }
    if(Check(sp1->GetLowHitRects(), sp2->GetHultRects(),p1,p2))
    {
        return cLowHult;
    }
    if(Check(sp1->GetHighHitRects(), sp2->GetHighHitRects(),p1,p2))
    {
        return cHighHigh;
    }
    if(Check(sp1->GetHighHitRects(), sp2->GetLowHitRects(),p1,p2))
    {
        return cHighLow;
    }
    if(Check(sp1->GetLowHitRects(), sp2->GetHighHitRects(),p1,p2))
    {
        return cLowHigh;
    }
    if(Check(sp1->GetLowHitRects(), sp2->GetLowHitRects(),p1,p2))
    {
        return cLowLow;
    }
    return cNone;
}
