#include <SDL_image.h>
#include <SDL_Mixer.h>

#include "Global.h"
#include "Point.h"
#include "floatAnchor.h"
#include "ACharacter.h"

int charSpritesNum = 108;
ACharacter** Global::allCharacters = new ACharacter*[charSpritesNum];
SDL_Texture* Global::mainMenuTexture = 0;
SDL_Texture* Global::characterSelectTexture = 0;
SDL_Texture* Global::charPortraits = 0;
SDL_Texture* Global::LoadingScreenTexture = 0;
SDL_Texture* Global::charIcons = 0;

SDL_Texture** Global::GaneshGaitondeAnimations = 0;
SDL_Texture** Global::TrivediBabuAnimations = 0;
SDL_Texture** Global::PhoolanDeviAnimations = 0;
SDL_Texture** Global::RobertRotorAnimations = 0;

SDL_Texture**Global::backgrounds = 0;

SDL_Texture* Global::creditsScreen = 0;
SDL_Texture* Global::controlScreen = 0;

SDL_Texture* Global::healthBarTexture = 0;
SDL_Texture* Global::manaBarTexture = 0;

Mix_Music* Global::creditsMusic = 0;


SDL_Texture* Global::stages = 0;

Mix_Music* Global::mainMenuMusic = 0;
Mix_Music* Global::arenaMusic = 0;
Mix_Music* Global::currentMusic = 0;

int Global::superCount = -1;

bool Global::LoadBars(SDL_Renderer* gRenderer)
{
    LoadImage(healthBarTexture, "Gameplay\\Bars.png", gRenderer);
    LoadImage(manaBarTexture,"Gameplay\\ComboBoxes.png",gRenderer);
}


bool Global::LoadBackgrounds(SDL_Renderer* gRenderer)
{
    backgrounds = new SDL_Texture*[5];
    LoadImage(backgrounds[0],"BackGroundScreens\\s1.png",gRenderer);
    LoadImage(backgrounds[1],"BackGroundScreens\\s2.png",gRenderer);
    LoadImage(backgrounds[2],"BackGroundScreens\\s3.png",gRenderer);
    LoadImage(backgrounds[3],"BackGroundScreens\\s4.png",gRenderer);
    LoadImage(backgrounds[4],"BackGroundScreens\\s5.png",gRenderer);
    return 0;
}

bool Global::InitControls(SDL_Renderer* gRenderer)
{
    return LoadImage(controlScreen,"BackGroundScreens\\Controls.png",gRenderer);
}

bool Global::InitCredits(SDL_Renderer* gRenderer)
{
    LoadImage(creditsScreen,"BackGroundScreens\\Credits.png",gRenderer);
    LoadMusic(creditsMusic, "Music and Sounds\\Credits.mp3");
}

bool Global::LoadGaneshGaitonde(SDL_Renderer* gRenderer)
{
enum{stanceG, crouchG, guardG, crouchGuardG, jumpG, crouchJabG, shortKickG,
     strongJabG, walkForwardG, walkBackwardG, crouchKickG, crouchTurnG,jumpJabG,
     jumpKickG,crouchKick1G,combo1G,combo2G, getHitCrouchG, getHitStandingHighG,
     getHitStandingLowG, fire1G, fire2G, knockDownG, victoryG,numElementsG};

    GaneshGaitondeAnimations = new SDL_Texture*[numElementsG];
    LoadImage(GaneshGaitondeAnimations[stanceG], "Sprites\\Dhalsim\\STANCE.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[crouchG], "Sprites\\Dhalsim\\CROUCH.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[guardG], "Sprites\\Dhalsim\\GUARD.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[crouchGuardG], "Sprites\\Dhalsim\\CROUCH_GUARD.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[jumpG], "Sprites\\Dhalsim\\JUMP.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[crouchJabG], "Sprites\\Dhalsim\\STRETCHED_CROUCH_JAB.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[shortKickG], "Sprites\\Dhalsim\\STRETCHED_FORWARD_KICK.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[strongJabG], "Sprites\\Dhalsim\\STRETCHED_1.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[walkForwardG], "Sprites\\Dhalsim\\WALK_FORWARD.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[walkBackwardG], "Sprites\\Dhalsim\\WALK_BACKWARD.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[crouchKickG], "Sprites\\Dhalsim\\STRETCHED_CROUCH_KICK.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[crouchTurnG], "Sprites\\Dhalsim\\CROUCH_TURN.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[jumpJabG], "Sprites\\Dhalsim\\STRETCHED_JUMP_JAB.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[jumpKickG], "Sprites\\Dhalsim\\COMBO_1.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[crouchKick1G], "Sprites\\Dhalsim\\JUMP_STRETCHED_ROUNDHOUSE.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[combo1G], "Sprites\\Dhalsim\\FIRE_COMBO_1.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[combo2G], "Sprites\\Dhalsim\\FIRE_COMBO_4.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[getHitCrouchG], "Sprites\\Dhalsim\\CROUCH_HIT.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[getHitStandingHighG], "Sprites\\Dhalsim\\HIGH_HIT.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[getHitStandingLowG], "Sprites\\Dhalsim\\LOW_HIT.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[fire1G], "Sprites\\Dhalsim\\FIRE_2.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[fire2G], "Sprites\\Dhalsim\\FIRE_3.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[knockDownG], "Sprites\\Dhalsim\\KNOCKED_DOWN.png", gRenderer);
    LoadImage(GaneshGaitondeAnimations[victoryG], "Sprites\\Dhalsim\\VICTORY.png", gRenderer);
    return 0;
}

bool Global:: InitBackgroundSelect(SDL_Renderer* gRenderer)
{
    return LoadImage(stages, "BackGroundScreens\\Background_select.png",gRenderer);
}

bool Global::LoadPhoolanDevi(SDL_Renderer* gRenderer)
{
enum{stanceP, crouchP, guardP, crouchGuardP, jumpP, crouchJabP, shortKickP,
     strongJabP, walkForwardP, walkBackwardP, crouchKickP, crouchTurnP,jumpJabP, jumpKickP,crouchKick1P,combo1P,combo2P,
     getHitCrouchP, getHitStandingHighP,
     getHitStandingLowP, getHitAirP, knockDownP, victoryP,numElementsP};

    PhoolanDeviAnimations = new SDL_Texture*[numElementsP];
    LoadImage(PhoolanDeviAnimations[stanceP], "Sprites\\Karin\\IdleStance.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[crouchP], "Sprites\\Karin\\Crouch.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[guardP], "Sprites\\Karin\\Guard.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[crouchGuardP], "Sprites\\Karin\\CrouchGuard.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[jumpP], "Sprites\\Karin\\Jump.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[crouchJabP], "Sprites\\Karin\\CrouchStrong.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[shortKickP], "Sprites\\Karin\\MujinKyaku.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[strongJabP], "Sprites\\Karin\\GurenKen.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[walkForwardP], "Sprites\\Karin\\WalkForward.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[walkBackwardP], "Sprites\\Karin\\WalkBackward.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[crouchKickP], "Sprites\\Karin\\YashiroKuzushi.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[crouchTurnP], "Sprites\\Karin\\CrouchTurn.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[jumpJabP], "Sprites\\Karin\\JumStrong.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[jumpKickP], "Sprites\\Karin\\JumpShort.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[crouchKick1P], "Sprites\\Karin\\Roll.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[combo1P], "Sprites\\Karin\\RessenHa.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[combo2P], "Sprites\\Karin\\RessenHa.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[getHitCrouchP], "Sprites\\Karin\\CrouchHit.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[getHitStandingHighP], "Sprites\\Karin\\HeadHit.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[getHitStandingLowP], "Sprites\\Karin\\BodyHit.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[knockDownP], "Sprites\\Karin\\KnockedDown.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[victoryP], "Sprites\\Karin\\VictoryPose2.png", gRenderer);
    return 0;
}

bool Global::LoadTrivediBabu(SDL_Renderer* gRenderer)
{
enum{stanceT, crouchT, guardT, crouchGuardT, jumpT, crouchJabT, shortKickT,
     strongJabT, walkForwardT, walkBackwardT, crouchKickT, crouchTurnT, combo1T,jumpJabT,jumpKickT,crouchKick1T,combo2T,
     getHitCrouchT, getHitStandingHighT,
     getHitStandingLowT, hCreationT, hDestructionT,knockDownT, victoryT,numElementsT};


    TrivediBabuAnimations = new SDL_Texture*[numElementsT];
    LoadImage(TrivediBabuAnimations[stanceT], "Sprites\\Ken\\Stance.png", gRenderer);
    LoadImage(TrivediBabuAnimations[crouchT], "Sprites\\Ken\\Crouch.png", gRenderer);
    LoadImage(TrivediBabuAnimations[guardT], "Sprites\\Ken\\Guard.png", gRenderer);
    LoadImage(TrivediBabuAnimations[crouchGuardT], "Sprites\\Ken\\CrouchGuard.png", gRenderer);
    LoadImage(TrivediBabuAnimations[jumpT], "Sprites\\Ken\\Jump(notes).png", gRenderer);
    LoadImage(TrivediBabuAnimations[crouchJabT], "Sprites\\Ken\\CrouchStrong.png", gRenderer);
    LoadImage(TrivediBabuAnimations[shortKickT], "Sprites\\Ken\\ShortKick.png", gRenderer);
    LoadImage(TrivediBabuAnimations[strongJabT], "Sprites\\Ken\\CloseFierce.png", gRenderer);
    LoadImage(TrivediBabuAnimations[walkForwardT], "Sprites\\Ken\\WalkForward.png", gRenderer);
    LoadImage(TrivediBabuAnimations[walkBackwardT], "Sprites\\Ken\\WalkBackward.png", gRenderer);
    LoadImage(TrivediBabuAnimations[crouchKickT], "Sprites\\Ken\\CrouchStrongKick.png", gRenderer);
    LoadImage(TrivediBabuAnimations[crouchTurnT], "Sprites\\Ken\\CrouchTurn.png", gRenderer);
    LoadImage(TrivediBabuAnimations[combo1T], "Sprites\\Ken\\ShouryuuReppaEnder.png", gRenderer);
    LoadImage(TrivediBabuAnimations[jumpJabT], "Sprites\\Ken\\JumpJab.png", gRenderer);
    LoadImage(TrivediBabuAnimations[jumpKickT], "Sprites\\Ken\\ForwardJumpRoundhouseKick.png", gRenderer);
    LoadImage(TrivediBabuAnimations[crouchKick1T], "Sprites\\Ken\\TatsumakiSenpuuKyaku.png", gRenderer);
    LoadImage(TrivediBabuAnimations[combo2T], "Sprites\\Ken\\HadouKen.png", gRenderer);
    LoadImage(TrivediBabuAnimations[getHitCrouchT], "Sprites\\Ken\\CrouchHit.png", gRenderer);
    LoadImage(TrivediBabuAnimations[getHitStandingHighT], "Sprites\\Ken\\HighHit.png", gRenderer);
    LoadImage(TrivediBabuAnimations[getHitStandingLowT], "Sprites\\Ken\\LowHit.png", gRenderer);
    LoadImage(TrivediBabuAnimations[hCreationT], "Sprites\\Ken\\HadouKenBall1.png", gRenderer);
    LoadImage(TrivediBabuAnimations[hDestructionT], "Sprites\\Ken\\HadouKenBall2.png", gRenderer);
    LoadImage(TrivediBabuAnimations[knockDownT], "Sprites\\Ken\\KnockedDown.png", gRenderer);
    LoadImage(TrivediBabuAnimations[victoryT], "Sprites\\Ken\\Victory2.png", gRenderer);
    return 0;
}


bool Global::LoadRobertRotor(SDL_Renderer* gRenderer)
{
enum{stance, crouch, guard, crouchGuard, jump, crouchJab, shortKick,
     strongJab, walkForward, walkBackward, crouchKick, crouchTurn, jumpJab, jumpKick, comboFierce,comboChain,
     getHitCrouch, getHitStandingHigh,
     getHitStandingLow, getHitAir, knockDown, victory,numElements};

    RobertRotorAnimations = new SDL_Texture*[numElements];
    LoadImage(RobertRotorAnimations[stance], "Sprites\\Birdie\\STANCE.png", gRenderer);
    LoadImage(RobertRotorAnimations[crouch], "Sprites\\Birdie\\CROUCH.png", gRenderer);
    LoadImage(RobertRotorAnimations[guard], "Sprites\\Birdie\\Guard.png", gRenderer);
    LoadImage(RobertRotorAnimations[crouchGuard], "Sprites\\Birdie\\CrouchGuard.png", gRenderer);
    LoadImage(RobertRotorAnimations[jump], "Sprites\\Birdie\\Jump.png", gRenderer);
    LoadImage(RobertRotorAnimations[crouchJab], "Sprites\\Birdie\\CrouchJab.png", gRenderer);
    LoadImage(RobertRotorAnimations[shortKick], "Sprites\\Birdie\\ShortKick.png", gRenderer);
    LoadImage(RobertRotorAnimations[strongJab], "Sprites\\Birdie\\Strong.png", gRenderer);
    LoadImage(RobertRotorAnimations[walkForward], "Sprites\\Birdie\\WalkForward(ReverseForBackward).png", gRenderer);
    LoadImage(RobertRotorAnimations[walkBackward], "Sprites\\Birdie\\WalkForward(ReverseForBackward).png", gRenderer);
    LoadImage(RobertRotorAnimations[crouchKick], "Sprites\\Birdie\\CrouchForwardKick.png", gRenderer);
    LoadImage(RobertRotorAnimations[crouchTurn], "Sprites\\Birdie\\CrouchTurn.png", gRenderer);
    LoadImage(RobertRotorAnimations[jumpJab], "Sprites\\Birdie\\JumpFierce.png", gRenderer);
    LoadImage(RobertRotorAnimations[jumpKick], "Sprites\\Birdie\\JumpShortKick.png", gRenderer);
    LoadImage(RobertRotorAnimations[comboFierce], "Sprites\\Birdie\\Fierce.png", gRenderer);
    LoadImage(RobertRotorAnimations[comboChain], "Sprites\\Birdie\\MurdererChain(note in list).png", gRenderer);
    LoadImage(RobertRotorAnimations[getHitCrouch], "Sprites\\Birdie\\CrouchHit.png", gRenderer);
    LoadImage(RobertRotorAnimations[getHitStandingHigh], "Sprites\\Birdie\\HighHit.png", gRenderer);
    LoadImage(RobertRotorAnimations[getHitStandingLow], "Sprites\\Birdie\\LowHit.png", gRenderer);
    LoadImage(RobertRotorAnimations[knockDown], "Sprites\\Birdie\\KnockedDown.png", gRenderer);
    LoadImage(RobertRotorAnimations[victory], "Sprites\\Birdie\\Victory1.png", gRenderer);
    return 0;
}

Uint32 Global::QueueMusic(Uint32 interval, void* queuedMusic)
{
    PlayMusic(static_cast<Mix_Music*>(queuedMusic));
    return 0;
}

void Global::PlayMusic(Mix_Music* newMusic)
{
    if(Mix_PlayingMusic() == 0)
    {
        Global::currentMusic = newMusic;
        Mix_FadeInMusic(Global::currentMusic, -1, 4000);
    }
    else
    {
        if(Global::currentMusic != newMusic)
        {
            Mix_FadeOutMusic(2000);
            SDL_AddTimer(2001, QueueMusic, newMusic);
        }
    }
}

bool Global::LoadSound(Mix_Chunk*& sound, char name[])
{
    return 0;
}

bool Global::LoadMusic(Mix_Music*& mus, char name[])
{
    mus = Mix_LoadMUS(name);
    if(mus == 0)
    {
        cout << name << " could not be loaded" << endl;
        return 1;
    }
    return 0;
}

bool Global::InitArenaMusic()
{
    return LoadMusic(arenaMusic, "Music and Sounds\\gameplay.mp3");
}

bool Global::InitMainMenuMusic()
{
    return LoadMusic(mainMenuMusic, "Music and Sounds\\main.mp3");
}

int Global::CorrectWidth(int currentWidth, int currentHeight, int projectedHeight)
{
    return (projectedHeight * currentWidth) / currentHeight;
}

int Global::CorrectHeight(int currentWidth, int currentHeight, int protectedWidth)
{
    return (protectedWidth * currentHeight) / currentWidth;
}

Point Global::CorrectedPos(Point anchor, Point position)
{
    Point p;
    p.x = position.x - anchor.x;
    p.y = position.y - anchor.y;
    return p;
};

bool Global::InitAllCharacters(SDL_Renderer* gRenderer)
{
    string s[3];
    s[0] = string("black");
    s[1] = string("gold");
    s[2] = string("red");
    string current;
    for(int i = 0; i < charSpritesNum; i += 36)
    {
        for(int j = 0; j < 10; j++)
        {
            current = char(j + 48);
            allCharacters[i + j] = new ACharacter(gRenderer, current, s[i/36]);
        }
        for(int j = 0; j < 26; j++)
        {
            current = char(j + 65);
            allCharacters[i + 10 + j] = new ACharacter(gRenderer, current, s[i/36]);
        }
    }
    return 0;
}

void Global::Quit()
{
    delete [] allCharacters;
    SDL_DestroyTexture(mainMenuTexture);
    SDL_DestroyTexture(characterSelectTexture);
    SDL_DestroyTexture(charPortraits);
    SDL_DestroyTexture(LoadingScreenTexture);
    SDL_DestroyTexture(charIcons);
    Mix_FreeMusic(mainMenuMusic);
    Mix_FreeMusic(arenaMusic);
//    cout << "hello in Quit " << endl;

    for(int i = 0; i < 24; i++)
    {
//        cout << i << endl;
        SDL_DestroyTexture(GaneshGaitondeAnimations[i]);
    }
    for(int i = 0; i < 23; i++)
    {
//        cout << i << endl;
        SDL_DestroyTexture(PhoolanDeviAnimations[i]);
    }
    for(int i = 0; i < 24; i++)
    {
//        cout << i << endl;
        SDL_DestroyTexture(TrivediBabuAnimations[i]);
    }
    for(int i = 0; i < 22; i++)
    {
//        cout << i << endl;
        SDL_DestroyTexture(RobertRotorAnimations[i]);
    }
//    cout << "hello after loop in Quit " << endl;
    delete [] GaneshGaitondeAnimations;
    delete [] RobertRotorAnimations;
    delete [] TrivediBabuAnimations;
    delete [] PhoolanDeviAnimations;

    SDL_DestroyTexture(Global::creditsScreen);
    SDL_DestroyTexture(Global::controlScreen);
    Mix_FreeMusic(creditsMusic);
    for(int i = 0; i < 5; i++)
    {
//        cout << i << endl;
        SDL_DestroyTexture(backgrounds[i]);
    }


}

int Global::FindIndOfChar(ACharacter* test)
{
    for(int i = 0; i < charSpritesNum; i++)
    {
        if(allCharacters[i] == test)
        {
            return i;
        }
    }
    return -1;
}

bool Global::InitMainMenuBackGround(SDL_Renderer* gRenderer)
{
    return LoadImage(mainMenuTexture, "BackGroundScreens\\Main Menu BG.png", gRenderer);
}

bool Global::InitCharacterSelectBackGround(SDL_Renderer* gRenderer)
{
    return LoadImage(characterSelectTexture, "BackGroundScreens\\background_final.png", gRenderer);
}

bool Global::InitCharPortraits(SDL_Renderer* gRenderer)
{
    return LoadImage(charPortraits, "BackGroundScreens\\CHAR_COMP.png", gRenderer);
}

bool Global::InitCharIcons(SDL_Renderer* gRenderer)
{
    return LoadImage(charIcons, "BackGroundScreens\\characters.png", gRenderer);
}

bool Global::LoadImage(SDL_Texture*& texture, char name[], SDL_Renderer* gRenderer)
{
    SDL_Surface* temp = 0;
    temp = IMG_Load(name);
    if(temp == 0)
    {
        cout << name << " could not be loaded" << endl;
        return 1;
    }
    texture = SDL_CreateTextureFromSurface(gRenderer, temp);
    if(texture == 0)
    {
        cout << "could not create texture for " << name << endl;
        return 1;
    }
    SDL_FreeSurface(temp);
    temp = 0;
    return 0;
}

void Global::LoadingScreen(SDL_Renderer* gRenderer)
{
    LoadImage(LoadingScreenTexture, "BackGroundScreens\\main menu LOADING.png", gRenderer);
    SDL_Rect tempRect;
    SDL_QueryTexture(LoadingScreenTexture, 0, 0, &tempRect.w, &tempRect.h);
    tempRect.w = CorrectWidth(tempRect.w, tempRect.h, SCREEN_HEIGHT);
    tempRect.h = SCREEN_HEIGHT;
    Point tempPoint = CorrectedPos(floatAnchor(1,1).superImpose(tempRect.w, tempRect.h),
                                   Point(SCREEN_WIDTH, SCREEN_HEIGHT));
    tempRect.x = tempPoint.x;
    tempRect.y = tempPoint.y;

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0 , 0);
    SDL_RenderClear(gRenderer);

    SDL_RenderCopy(gRenderer, LoadingScreenTexture, 0, &tempRect);

    /* update the screen */

    SDL_RenderPresent(gRenderer);

}
