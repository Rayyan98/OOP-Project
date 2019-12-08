#include "PhoolanDevi.h"
#include "Arena.h"


/*bool Global::LoadPhoolanDevi(SDL_Renderer* gRenderer)
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
}*/

enum{stanceP, crouchP, guardP, crouchGuardP, jumpP, crouchJabP, shortKickP,
     strongJabP, walkForwardP, walkBackwardP, crouchKickP, crouchTurnP,jumpJabP, jumpKickP,crouchKick1P,combo1P,combo2P,
     getHitCrouchP, getHitStandingHighP,
     getHitStandingLowP, getHitAirP,knockDownP, victoryP, numElementsP};


enum{crouchKick1LeftP, crouchKick1RightP};

enum{cNone, cHultHult, cHultHigh, cHultLow,
            cHighHult, cHighHigh, cHighLow,
            cLowHult , cLowHigh , cLowLow};

PhoolanDevi::PhoolanDevi()
{

}


PhoolanDevi::PhoolanDevi(Point position1, bool orientation, bool player2) : Character(position1, orientation, player2)
{
    cCombo = -1;
    crouchKick1Status = -1;

    Sprite** getHitCrouchFrames = new Sprite*[3];
    Point getHitCrouchLowHit[] = {Point(0,0), Point(75,64), Point(-700,-700)};
    Point getHitCrouchLowHit1[] = {Point(74,0), Point(169,64), Point(-700,-700)};
    Point getHitCrouchLowHit2[] = {Point(170,0), Point(268,64), Point(-700,-700)};

    getHitCrouchFrames[0] = new Sprite(Global::PhoolanDeviAnimations[getHitCrouchP],
                                       Point(0,0), Point(75,64), Point(21,64), 0, getHitCrouchLowHit,0,0);
    getHitCrouchFrames[1] = new Sprite(Global::PhoolanDeviAnimations[getHitCrouchP],
                                       Point(73,0), Point(169,64), Point(118,64), 0, getHitCrouchLowHit1,0,0);
    getHitCrouchFrames[2] = new Sprite(Global::PhoolanDeviAnimations[getHitCrouchP],
                                       Point(171,0), Point(268,64), Point(228,64), 0, getHitCrouchLowHit2,0,0);

    Sprite** getHitStandingLowFrames = new Sprite*[4];

    Point getHitStandingLowHigh[] = {Point(0,0),Point(88,42),Point(-700,-700)};
    Point getHitStandingLowHigh1[] = {Point(92,0),Point(169,42),Point(-700,-700)};
    Point getHitStandingLowHigh2[] = {Point(173,0),Point(255,42),Point(-700,-700)};
    Point getHitStandingLowHigh3[] = {Point(262,0),Point(335,42),Point(-700,-700)};

    Point getHitStandingLowLow[] = {Point(0,42),Point(86,84),Point(-700,-700)};
    Point getHitStandingLowLow1[] = {Point(95,42),Point(175,84),Point(-700,-700)};
    Point getHitStandingLowLow2[] = {Point(180,42),Point(264,84),Point(-700,-700)};
    Point getHitStandingLowLow3[] = {Point(267,42),Point(352,84),Point(-700,-700)};

    getHitStandingLowFrames[0] = new Sprite(Global::PhoolanDeviAnimations[getHitStandingLowP],
                                Point(0,0),Point(88,84),Point(6,84),getHitStandingLowHigh,
                                            getHitStandingLowLow,0,0);
    getHitStandingLowFrames[1] = new Sprite(Global::PhoolanDeviAnimations[getHitStandingLowP],
                                Point(88,0),Point(180,84),Point(90,84),getHitStandingLowHigh1,
                                            getHitStandingLowLow1,0,0);
    getHitStandingLowFrames[2] = new Sprite(Global::PhoolanDeviAnimations[getHitStandingLowP],
                                Point(170,0),Point(267,84),Point(195,84),getHitStandingLowHigh2,
                                            getHitStandingLowLow2,0,0);
    getHitStandingLowFrames[3] = new Sprite(Global::PhoolanDeviAnimations[getHitStandingLowP],
                                Point(258,0),Point(352,84),Point(292,84),getHitStandingLowHigh3,
                                            getHitStandingLowLow3,0,0);


    Sprite** getHitStandingHighFrames = new Sprite*[4];

    Point getHitStandingHighFramesHighHit[] = {Point(0,0),Point(81,44),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit1[] = {Point(87,0),Point(182,44),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit2[] = {Point(189,0),Point(285,44),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit3[] = {Point(297 ,0),Point(395,44),Point(-700,-700)};

    Point getHitStandingHighFramesLowHit[] = {Point(0, 44),Point(88,86),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit1[] = {Point(101,44),Point(186,86),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit2[] = {Point(215,44),Point(296,86),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit3[] = {Point(327,44),Point(405,86),Point(-700,-700)};

    getHitStandingHighFrames[0] = new Sprite(Global::PhoolanDeviAnimations[getHitStandingHighP],
                                       Point(0,0), Point(92,86), Point(7,86), getHitStandingHighFramesHighHit,
                                       getHitStandingHighFramesLowHit,0,0);
    getHitStandingHighFrames[1] = new Sprite(Global::PhoolanDeviAnimations[getHitStandingHighP],
                                       Point(85,0), Point(191,86), Point(107,86), getHitStandingHighFramesHighHit1,
                                             getHitStandingHighFramesLowHit1,0,0);
    getHitStandingHighFrames[2] = new Sprite(Global::PhoolanDeviAnimations[getHitStandingHighP],
                                       Point(188,0), Point(297,86), Point(219,86), getHitStandingHighFramesHighHit2,
                                             getHitStandingHighFramesLowHit2,0,0);
    getHitStandingHighFrames[3] = new Sprite(Global::PhoolanDeviAnimations[getHitStandingHighP],
                                       Point(293,0), Point(405,86), Point(329,86), getHitStandingHighFramesHighHit3,
                                             getHitStandingHighFramesLowHit3,0,0);
    //hulihul
    Sprite** stanceFrames = new Sprite*[13];
    Point stanceHighHit[] = {Point(16,19), Point(81,42), Point(-700,-700)};
    Point stanceHighHit1[] = {Point(102,19), Point(170,42), Point(-700,-700)};
    Point stanceHighHit2[] = {Point(186,19), Point(253,42), Point(-700,-700)};
    Point stanceHighHit3[] = {Point(265,19), Point(333,42), Point(-700,-700)};
    Point stanceHighHit4[] = {Point(342,19), Point(412,42), Point(-700,-700)};
    Point stanceHighHit5[] = {Point(420,19), Point(493,42), Point(-700,-700)};
    Point stanceHighHit6[] = {Point(500,19), Point(574,42), Point(-700,-700)};
    Point stanceHighHit7[] = {Point(580,19), Point(657,42), Point(-700,-700)};
    Point stanceHighHit8[] = {Point(679,19), Point(753,42), Point(-700,-700)};
    Point stanceHighHit9[] = {Point(781,19), Point(853,42), Point(-700,-700)};
    Point stanceHighHit10[] = {Point(883,19), Point(954,42), Point(-700,-700)};
    Point stanceHighHit11[] = {Point(981,19), Point(1050,42), Point(-700,-700)};
    Point stanceHighHit12[] = {Point(1074,19), Point(1141,42), Point(-700,-700)};


    Point stanceLowHit[] = {Point(16,42), Point(81,92), Point(-700,-700)};
    Point stanceLowHit1[] = {Point(91,42), Point(170,92), Point(-700,-700)};
    Point stanceLowHit2[] = {Point(178,42), Point(235,92), Point(-700,-700)};
    Point stanceLowHit3[] = {Point(261,42), Point(313,92), Point(-700,-700)};
    Point stanceLowHit4[] = {Point(341,42), Point(386,92), Point(-700,-700)};
    Point stanceLowHit5[] = {Point(420,42), Point(467,92), Point(-700,-700)};
    Point stanceLowHit6[] = {Point(500,42), Point(548,92), Point(-700,-700)};
    Point stanceLowHit7[] = {Point(580,42), Point(635,92), Point(-700,-700)};
    Point stanceLowHit8[] = {Point(665,42), Point(730,92), Point(-700,-700)};
    Point stanceLowHit9[] = {Point(760,42), Point(830,92), Point(-700,-700)};
    Point stanceLowHit10[] = {Point(861,42), Point(954,92), Point(-700,-700)};
    Point stanceLowHit11[] = {Point(962,42), Point(1050,92), Point(-700,-700)};
    Point stanceLowHit12[] = {Point(1058,42), Point(1141,92), Point(-700,-700)};

    stanceFrames[0] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(0,0), Point(83,92),
                                 Point(3, 92), stanceHighHit, stanceLowHit, 0, 0);
    stanceFrames[1] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(91, 0), Point(170, 92),
                                 Point(96, 92), stanceHighHit1, stanceLowHit1, 0, 0);
    stanceFrames[2] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(178, 0), Point(253, 92),
                                 Point(181, 92), stanceHighHit2,stanceLowHit2,0, 0);
    stanceFrames[3] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(261,0), Point(333, 92),
                                 Point(265, 92), stanceHighHit3,stanceLowHit3,0, 0);
    stanceFrames[4] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(341, 0), Point(412, 92),
                                 Point(348, 92), stanceHighHit4,stanceLowHit4,0, 0);
    stanceFrames[5] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(420, 0), Point(493, 92),
                                 Point(431, 92), stanceHighHit5,stanceLowHit5,0, 0);
    stanceFrames[6] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(500, 0), Point(574, 92),
                                 Point(508, 92),stanceHighHit6,stanceLowHit6,0, 0);
    stanceFrames[7] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(580,0), Point(657,92),
                                 Point(588, 92), stanceHighHit7, stanceLowHit7, 0, 0);
    stanceFrames[8] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(665, 0), Point(753, 92),
                                 Point(674, 92), stanceHighHit8, stanceLowHit8, 0, 0);
    stanceFrames[9] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(760, 0), Point(853, 92),
                                 Point(765, 92), stanceHighHit9,stanceLowHit9,0, 0);
    stanceFrames[10] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(861,0), Point(954, 92),
                                 Point(866, 92), stanceHighHit10,stanceLowHit10,0, 0);
    stanceFrames[11] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(962, 0), Point(1050, 92),
                                 Point(968, 92), stanceHighHit11,stanceLowHit11,0, 0);
    stanceFrames[12] = new Sprite(Global::PhoolanDeviAnimations[stanceP], Point(1058, 0), Point(1141, 92),
                                 Point(1064, 92), stanceHighHit2,stanceLowHit12,0, 0);

    Sprite** crouchFrames = new Sprite*[2];

    Point crouchLowHit[] = {Point(0,0), Point(91,79), Point(-700,-700)};
    Point crouchLowHit1[] = {Point(106,14), Point(176,79), Point(-700,-700)};

    crouchFrames[0] = new Sprite(Global::PhoolanDeviAnimations[crouchP], Point(0, 0), Point(91,79),
                             Point(5, 79),0,crouchLowHit,0, 0);
    crouchFrames[1] = new Sprite(Global::PhoolanDeviAnimations[crouchP], Point(99, 0), Point(176, 79),
                             Point(106, 79),0 ,crouchLowHit1,0, 0);


    Sprite** guardFrames = new Sprite*[1];

    Point guardHighHit[] = {Point(111,8), Point(159,39), Point(-700,-700)};

    Point guardLowHit[] = {Point(96,39), Point(184,94), Point(-700,-700)};

    guardFrames[0] = new Sprite(Global::PhoolanDeviAnimations[guardP], Point(96,0), Point(184,94),
                                Point(117, 94),guardHighHit,guardLowHit,0, 0);


    Sprite** crouchGuardFrames = new Sprite*[1];

    Point crouchGuardLowHit[] = {Point(76,0), Point(148,71), Point(-700,-700)};

    crouchGuardFrames[0] = new Sprite(Global::PhoolanDeviAnimations[crouchGuardP], Point(76,0), Point(148,71),
                                      Point(86,71),0,crouchGuardLowHit,0, 0);

    Sprite** jumpFrames = new Sprite*[12];
    Point jumpHighHit1[] = {Point(83,0), Point(20,53), Point(-700,-700)};
    Point jumpHighHit2[] = {Point(160,33), Point(212,53), Point(-700,-700)};
    Point jumpHighHit7[] = {Point(574,35), Point(624,53), Point(-700,-700)};
    Point jumpHighHit8[] = {Point(643,0), Point(687,53), Point(-700,-700)};
    Point jumpHighHit9[] = {Point(716,0), Point(755,53), Point(-700,-700)};
    Point jumpHighHit11[] = {Point(949,38), Point(988,53), Point(-700,-700)};

    Point jumpLowHit[] = {Point(0,53), Point(78,117), Point(-700,-700)};
    Point jumpLowHit1[] = {Point(85,53), Point(142,117), Point(-700,-700)};
    Point jumpLowHit2[] = {Point(149,53), Point(211,117), Point(-700,-700)};
    Point jumpLowHit3[] = {Point(218,53), Point(295,117), Point(-700,-700)};
    Point jumpLowHit4[] = {Point(303,53), Point(376,117), Point(-700,-700)};
    Point jumpLowHit5[] = {Point(384,53), Point(460,117), Point(-700,-700)};
    Point jumpLowHit6[] = {Point(467,53), Point(546,117), Point(-700,-700)};
    Point jumpLowHit7[] = {Point(553,53), Point(624,117), Point(-700,-700)};
    Point jumpLowHit8[] = {Point(632,53), Point(699,117), Point(-700,-700)};
    Point jumpLowHit9[] = {Point(701,53), Point(767,117), Point(-700,-700)};
    Point jumpLowHit10[] = {Point(843,53), Point(921,117), Point(-700,-700)};
    Point jumpLowHit11[] = {Point(929,53), Point(1019,117), Point(-700,-700)};

    jumpFrames[0] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(0,0), Point(78,117),
                               Point(7,117),0,jumpLowHit,0, 0);
    jumpFrames[1] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(85,0), Point(142,117),
                               Point(99,117),jumpHighHit1,jumpLowHit1,0, 0);
    jumpFrames[2] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(149,0), Point(211,117),
                               Point(164,117),jumpHighHit2,jumpLowHit2,0, 0);
    jumpFrames[3] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(218,0), Point(295,117),
                               Point(238,117),0,jumpLowHit3,0, 0);
    jumpFrames[4] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(303,0), Point(376,117),
                               Point(320,117),0,jumpLowHit4,0, 0);
    jumpFrames[5] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(384,0), Point(460,117),
                               Point(409,117),0,jumpLowHit5,0, 0);
    jumpFrames[6] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(467,0), Point(546,117),
                               Point(491,117),0,jumpLowHit6,0, 0);
    jumpFrames[7] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(553,0), Point(624,117),
                               Point(577,117),jumpHighHit7,jumpLowHit7,0, 0);
    jumpFrames[8] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(632,0), Point(699,117),
                               Point(654,117),jumpHighHit8,jumpLowHit8,0, 0);
    jumpFrames[9] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(701,0), Point(767,117),
                               Point(723,117),jumpHighHit9,jumpLowHit9,0, 0);
    jumpFrames[10] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(843,0), Point(921,117),
                               Point(852,117),0,jumpLowHit10,0, 0);
    jumpFrames[11] = new Sprite(Global::PhoolanDeviAnimations[jumpP], Point(929,0), Point(1019,117),
                               Point(936,117),jumpHighHit11,jumpLowHit11,0, 0);


    Sprite** crouchJabFrames = new Sprite*[7];

    Point crouchJabLowHit[] = {Point(0,7), Point(77,76), Point(-700,-700)};
    Point crouchJabLowHit1[] = {Point(84,7), Point(158,76), Point(-700,-700)};
    Point crouchJabLowHit2[] = {Point(202,7), Point(271,76), Point(-700,-700)};
    Point crouchJabLowHit3[] = {Point(316,7), Point(388,76), Point(-700,-700)};
    Point crouchJabLowHit4[] = {Point(430,7), Point(494,76), Point(-700,-700)};
    Point crouchJabLowHit5[] = {Point(529,7), Point(590,76), Point(-700,-700)};
    Point crouchJabLowHit6[] = {Point(606,7), Point(675,76), Point(-700,-700)};

    Point crouchJabHurt1[] = {Point(167,42), Point(194,66), Point(-700,-700)};
    Point crouchJabHurt2[] = {Point(283,42), Point(308,66), Point(-700,-700)};
    Point crouchJabHurt3[] = {Point(398,42), Point(425,66), Point(-700,-700)};


    crouchJabFrames[0] = new Sprite(Global::PhoolanDeviAnimations[crouchJabP], Point(0,0), Point(77,76),
                              Point(10,76),0,crouchJabLowHit,0, 0);
    crouchJabFrames[1] = new Sprite(Global::PhoolanDeviAnimations[crouchJabP], Point(84,0), Point(192,76),
                              Point(94,76),0,crouchJabLowHit1,crouchJabHurt1, 0);
    crouchJabFrames[2] = new Sprite(Global::PhoolanDeviAnimations[crouchJabP], Point(202,0), Point(308,76),
                              Point(210,76),0,crouchJabLowHit2,crouchJabHurt2, 0);
    crouchJabFrames[3] = new Sprite(Global::PhoolanDeviAnimations[crouchJabP], Point(316,0), Point(423,76),
                              Point(326,76),0,crouchJabLowHit3,crouchJabHurt3, 0);
    crouchJabFrames[4] = new Sprite(Global::PhoolanDeviAnimations[crouchJabP], Point(430,0), Point(520,76),
                              Point(441,76),0,crouchJabLowHit4,0, 0);
    crouchJabFrames[5] = new Sprite(Global::PhoolanDeviAnimations[crouchJabP], Point(529,0), Point(598,76),
                              Point(538,76),0,crouchJabLowHit5,0, 0);
    crouchJabFrames[6] = new Sprite(Global::PhoolanDeviAnimations[crouchJabP], Point(606,0), Point(675,76),
                              Point(614,76),0,crouchJabLowHit6,0, 0);


    Sprite** shortKickFrames = new Sprite*[13];
    Point shortKickHighHit[] = {Point(40,19), Point(81,55), Point(-700,-700)};
    Point shortKickHighHit1[] = {Point(140,19), Point(172,55), Point(-700,-700)};
    Point shortKickHighHit2[] = {Point(210,19), Point(236,55), Point(-700,-700)};
    Point shortKickHighHit3[] = {Point(270,19), Point(297,55), Point(-700,-700)};
    Point shortKickHighHit4[] = {Point(375,19), Point(403,55), Point(-700,-700)};
    Point shortKickHighHit5[] = {Point(473,19), Point(511,55), Point(-700,-700)};
    Point shortKickHighHit6[] = {Point(553,19), Point(595,55), Point(-700,-700)};
    Point shortKickHighHit7[] = {Point(675,19), Point(713,55), Point(-700,-700)};
    Point shortKickHighHit8[] = {Point(770,19), Point(804,55), Point(-700,-700)};
    Point shortKickHighHit9[] = {Point(857,19), Point(891,55), Point(-700,-700)};
    Point shortKickHighHit10[] = {Point(945,19), Point(977,55), Point(-700,-700)};
    Point shortKickHighHit11[] = {Point(1051,19), Point(1082,55), Point(-700,-700)};
    Point shortKickHighHit12[] = {Point(1136,19), Point(1170,55), Point(-700,-700)};

    Point shortKickLowHit[] = {Point(40,55), Point(81,115), Point(-700,-700)};
    Point shortKickLowHit1[] = {Point(140,55), Point(172,115), Point(-700,-700)};
    Point shortKickLowHit2[] = {Point(210,55), Point(236,115), Point(-700,-700)};
    Point shortKickLowHit3[] = {Point(270,55), Point(297,115), Point(-700,-700)};
    Point shortKickLowHit4[] = {Point(375,55), Point(403,115), Point(-700,-700)};
    Point shortKickLowHit5[] = {Point(473,55), Point(511,115), Point(-700,-700)};
    Point shortKickLowHit6[] = {Point(553,55), Point(595,115), Point(-700,-700)};
    Point shortKickLowHit7[] = {Point(675,55), Point(713,115), Point(-700,-700)};
    Point shortKickLowHit8[] = {Point(770,55), Point(804,115), Point(-700,-700)};
    Point shortKickLowHit9[] = {Point(857,55), Point(891,115), Point(-700,-700)};
    Point shortKickLowHit10[] = {Point(945,55), Point(977,115), Point(-700,-700)};
    Point shortKickLowHit11[] = {Point(1051,55), Point(1082,115), Point(-700,-700)};
    Point shortKickLowHit12[] = {Point(1136,55), Point(1170,115), Point(-700,-700)};

    Point shortKickHurt6[] = {Point(595,23), Point(641,79), Point(-700,-700)};
    Point shortKickHurt7[] = {Point(705,1), Point(752,42), Point(-700,-700)};
    Point shortKickHurt8[] = {Point(809,6), Point(843,41), Point(-700,-700)};
    Point shortKickHurt9[] = {Point(897,8), Point(935,45), Point(-700,-700)};
    Point shortKickHurt10[] = {Point(991,40), Point(1039,53), Point(-700,-700)};


    shortKickFrames[0] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(0,0), Point(105,115),
                                    Point(7,115), shortKickHighHit,shortKickLowHit,0, 0);
    shortKickFrames[1] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(114,0), Point(195, 115),
                                    Point(116, 115),shortKickHighHit1,shortKickLowHit1,0, 0);
    shortKickFrames[2] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(203,0), Point(251, 115),
                                    Point(218,115),shortKickHighHit2,shortKickLowHit2,0, 0);
    shortKickFrames[3] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(259,0), Point(356, 115),
                                    Point(287,115),shortKickHighHit3,shortKickLowHit3,0, 0);
    shortKickFrames[4] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(362,0), Point(454,115),
                                    Point(401,115),shortKickHighHit4,shortKickLowHit4,0, 0);
    shortKickFrames[5] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(461,0), Point(542,115),
                                    Point(502,115), shortKickHighHit5,shortKickLowHit5,0, 0);
    shortKickFrames[6] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(549,0), Point(657, 115),
                                    Point(596 , 115),shortKickHighHit6,shortKickLowHit6,shortKickHurt6, 0);
    shortKickFrames[7] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(663,0), Point(752, 115),
                                    Point(700,115),shortKickHighHit7,shortKickLowHit7,shortKickHurt7, 0);
    shortKickFrames[8] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(760,0), Point(843, 115),
                                    Point(797,115),shortKickHighHit8,shortKickLowHit8,shortKickHurt8, 0);
    shortKickFrames[9] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(851,0), Point(933,115),
                                    Point(887,115),shortKickHighHit9,shortKickLowHit9,shortKickHurt9, 0);
    shortKickFrames[10] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(940,0), Point(1039,115),
                                    Point(976,115), shortKickHighHit10,shortKickLowHit10,shortKickHurt10, 0);
    shortKickFrames[11] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(1046,0), Point(1119,115),
                                    Point(1067,115),shortKickHighHit11,shortKickLowHit11,0, 0);
    shortKickFrames[12] = new Sprite(Global::PhoolanDeviAnimations[shortKickP], Point(1127,0), Point(1196,115),
                                    Point(1131,115), shortKickHighHit12,shortKickLowHit12,0, 0);



    Sprite** strongJabFrames = new Sprite*[8];
    Point strongJabHighHit[] = {Point(36,0), Point(102,33), Point(-700,-700)};
    Point strongJabHighHit1[] = {Point(154,0), Point(207,33), Point(-700,-700)};
    Point strongJabHighHit2[] = {Point(252,0), Point(294,33), Point(-700,-700)};
    Point strongJabHighHit3[] = {Point(393,0), Point(428,33), Point(-700,-700)};
    Point strongJabHighHit4[] = {Point(511,0), Point(562,33), Point(-700,-700)};
    Point strongJabHighHit5[] = {Point(609,0), Point(654,33), Point(-700,-700)};
    Point strongJabHighHit6[] = {Point(695,0), Point(744,33), Point(-700,-700)};
    Point strongJabHighHit7[] = {Point(789,0), Point(839,33), Point(-700,-700)};

    Point strongJabLowHit[] = {Point(0,33), Point(102,88), Point(-700,-700)};
    Point strongJabLowHit1[] = {Point(111,33), Point(207,88), Point(-700,-700)};
    Point strongJabLowHit2[] = {Point(216,33), Point(294,88), Point(-700,-700)};
    Point strongJabLowHit3[] = {Point(347,33), Point(428,88), Point(-700,-700)};
    Point strongJabLowHit4[] = {Point(476,33), Point(562,88), Point(-700,-700)};
    Point strongJabLowHit5[] = {Point(570,33), Point(654,88), Point(-700,-700)};
    Point strongJabLowHit6[] = {Point(661,33), Point(744,88), Point(-700,-700)};
    Point strongJabLowHit7[] = {Point(750,33), Point(839,88), Point(-700,-700)};

    Point strongJabHurt2[] = {Point(288,12), Point(339,27), Point(-700,-700)};
    Point strongJabHurt3[] = {Point(426,16), Point(468,26), Point(-700,-700)};

    strongJabFrames[0] = new Sprite(Global::PhoolanDeviAnimations[strongJabP], Point(0,0), Point(102,88),
                                    Point(8,88),strongJabHighHit,strongJabLowHit,0, 0);
    strongJabFrames[1] = new Sprite(Global::PhoolanDeviAnimations[strongJabP], Point(111,0), Point(207,88),
                                    Point(114,88),strongJabHighHit1,strongJabLowHit1,0, 0);
    strongJabFrames[2] = new Sprite(Global::PhoolanDeviAnimations[strongJabP], Point(216,0), Point(341,88),
                                    Point(219,88),strongJabHighHit2,strongJabLowHit2,strongJabHurt2, 0);
    strongJabFrames[3] = new Sprite(Global::PhoolanDeviAnimations[strongJabP], Point(347,0), Point(469,88),
                                    Point(355,88),strongJabHighHit3,strongJabLowHit3,strongJabHurt3, 0);
    strongJabFrames[4] = new Sprite(Global::PhoolanDeviAnimations[strongJabP], Point(476,0), Point(562,88),
                                    Point(483,88),strongJabHighHit4,strongJabLowHit4,0, 0);
    strongJabFrames[5] = new Sprite(Global::PhoolanDeviAnimations[strongJabP], Point(570,0), Point(654,88),
                                    Point(578,88),strongJabHighHit5,strongJabLowHit5,0, 0);
    strongJabFrames[6] = new Sprite(Global::PhoolanDeviAnimations[strongJabP], Point(661,0), Point(744,88),
                                    Point(670,88),strongJabHighHit6,strongJabLowHit6,0, 0);
    strongJabFrames[7] = new Sprite(Global::PhoolanDeviAnimations[strongJabP], Point(750,0), Point(839,88),
                                    Point(757,88),strongJabHighHit7,strongJabLowHit7,0, 0);

    Sprite** walkForwardFrames = new Sprite*[8];
    Point walkForwardHighHit[] = {Point(102,13), Point(195,41), Point(-700,-700)};
    Point walkForwardHighHit1[] = {Point(203,13), Point(291,41), Point(-700,-700)};
    Point walkForwardHighHit2[] = {Point(297,13), Point(375,41), Point(-700,-700)};
    Point walkForwardHighHit3[] = {Point(382,13), Point(455,41), Point(-700,-700)};
    Point walkForwardHighHit4[] = {Point(622,13), Point(694,41), Point(-700,-700)};
    Point walkForwardHighHit5[] = {Point(702,13), Point(777,41), Point(-700,-700)};
    Point walkForwardHighHit6[] = {Point(785,13), Point(861,41), Point(-700,-700)};
    Point walkForwardHighHit7[] = {Point(868,13), Point(948,41), Point(-700,-700)};

    Point walkForwardLowHit[] = {Point(102,41), Point(185,93), Point(-700,-700)};
    Point walkForwardLowHit1[] = {Point(203,41), Point(274,93), Point(-700,-700)};
    Point walkForwardLowHit2[] = {Point(297,41), Point(354,93), Point(-700,-700)};
    Point walkForwardLowHit3[] = {Point(382,41), Point(432,93), Point(-700,-700)};
    Point walkForwardLowHit4[] = {Point(622,41), Point(674,93), Point(-700,-700)};
    Point walkForwardLowHit5[] = {Point(702,41), Point(759,93), Point(-700,-700)};
    Point walkForwardLowHit6[] = {Point(785,41), Point(842,93), Point(-700,-700)};
    Point walkForwardLowHit7[] = {Point(868,41), Point(938,93), Point(-700,-700)};

    walkForwardFrames[0] = new Sprite(Global::PhoolanDeviAnimations[walkForwardP], Point(102,0), Point(195,93),
                                      Point(108,93),walkForwardHighHit,walkForwardLowHit,0, 0);
    walkForwardFrames[1] = new Sprite(Global::PhoolanDeviAnimations[walkForwardP], Point(203,0), Point(291,93),
                                      Point(213,93),walkForwardHighHit1,walkForwardLowHit1,0, 0);
    walkForwardFrames[2] = new Sprite(Global::PhoolanDeviAnimations[walkForwardP], Point(297,0), Point(375,93),
                                      Point(306,93),walkForwardHighHit2,walkForwardLowHit2,0, 0);
    walkForwardFrames[3] = new Sprite(Global::PhoolanDeviAnimations[walkForwardP], Point(382,0), Point(455,93),
                                      Point(393,93),walkForwardHighHit3,walkForwardLowHit3,0, 0);
    walkForwardFrames[4] = new Sprite(Global::PhoolanDeviAnimations[walkForwardP], Point(622,0), Point(694,93),
                                      Point(628,93),walkForwardHighHit4,walkForwardLowHit4,0, 0);
    walkForwardFrames[5] = new Sprite(Global::PhoolanDeviAnimations[walkForwardP], Point(702,0), Point(777,93),
                                      Point(708,93),walkForwardHighHit5,walkForwardLowHit5,0, 0);
    walkForwardFrames[6] = new Sprite(Global::PhoolanDeviAnimations[walkForwardP], Point(785,0), Point(861,93),
                                      Point(789,93),walkForwardHighHit6,walkForwardLowHit6,0, 0);
    walkForwardFrames[7] = new Sprite(Global::PhoolanDeviAnimations[walkForwardP], Point(868,0), Point(948,93),
                                      Point(873,93),walkForwardHighHit7,walkForwardLowHit7,0, 0);

    Sprite** walkBackwardFrames = new Sprite*[8];
    Point walkBackwardHighHit[] = {Point(91,15), Point(171,46), Point(-700,-700)};
    Point walkBackwardHighHit1[] = {Point(178,15), Point(253,46), Point(-700,-700)};
    Point walkBackwardHighHit2[] = {Point(261,15), Point(334,46), Point(-700,-700)};
    Point walkBackwardHighHit3[] = {Point(341,15), Point(412,46), Point(-700,-700)};
    Point walkBackwardHighHit4[] = {Point(419,15), Point(493,46), Point(-700,-700)};
    Point walkBackwardHighHit5[] = {Point(501,15), Point(574,46), Point(-700,-700)};
    Point walkBackwardHighHit6[] = {Point(581,15), Point(657,46), Point(-700,-700)};
    Point walkBackwardHighHit7[] = {Point(664,15), Point(754,46), Point(-700,-700)};

    Point walkBackwardLowHit[] = {Point(91,46), Point(161,92), Point(-700,-700)};
    Point walkBackwardLowHit1[] = {Point(178,46), Point(235,92), Point(-700,-700)};
    Point walkBackwardLowHit2[] = {Point(261,46), Point(312,92), Point(-700,-700)};
    Point walkBackwardLowHit3[] = {Point(341,46), Point(388,92), Point(-700,-700)};
    Point walkBackwardLowHit4[] = {Point(419,46), Point(467,92), Point(-700,-700)};
    Point walkBackwardLowHit5[] = {Point(501,46), Point(548,92), Point(-700,-700)};
    Point walkBackwardLowHit6[] = {Point(581,46), Point(635,92), Point(-700,-700)};
    Point walkBackwardLowHit7[] = {Point(664,46), Point(735,92), Point(-700,-700)};

    walkBackwardFrames[0] = new Sprite(Global::PhoolanDeviAnimations[walkBackwardP], Point(91,0), Point(171, 92),
                                       Point(96,92),walkBackwardHighHit,walkBackwardLowHit,0, 0);
    walkBackwardFrames[1] = new Sprite(Global::PhoolanDeviAnimations[walkBackwardP], Point(178,0), Point(253, 92),
                                       Point(182,92),walkBackwardHighHit1,walkBackwardLowHit1,0, 0);
    walkBackwardFrames[2] = new Sprite(Global::PhoolanDeviAnimations[walkBackwardP], Point(261,0), Point(334, 92),
                                       Point(266,92),walkBackwardHighHit2,walkBackwardLowHit2,0, 0);
    walkBackwardFrames[3] = new Sprite(Global::PhoolanDeviAnimations[walkBackwardP], Point(341,0), Point(412, 92),
                                       Point(348,92),walkBackwardHighHit3,walkBackwardLowHit3,0, 0);
    walkBackwardFrames[4] = new Sprite(Global::PhoolanDeviAnimations[walkBackwardP], Point(419,0), Point(493, 92),
                                       Point(431,92),walkBackwardHighHit4,walkBackwardLowHit4,0, 0);
    walkBackwardFrames[5] = new Sprite(Global::PhoolanDeviAnimations[walkBackwardP], Point(501,0), Point(574, 92),
                                       Point(509,92),walkBackwardHighHit5,walkBackwardLowHit5,0, 0);
    walkBackwardFrames[6] = new Sprite(Global::PhoolanDeviAnimations[walkBackwardP], Point(581,0), Point(657, 92),
                                       Point(590,92),walkBackwardHighHit6,walkBackwardLowHit6,0, 0);
    walkBackwardFrames[7] = new Sprite(Global::PhoolanDeviAnimations[walkBackwardP], Point(664,0), Point(754, 92),
                                       Point(676,92),walkBackwardHighHit7,walkBackwardLowHit7,0, 0);

    Sprite** jumpJabFrames = new Sprite*[5];
    Point jumpJabHighHit[] = {Point(0,21), Point(61,100), Point(-700,-700)};
    Point jumpJabHighHit1[] = {Point(69,0), Point(118,100), Point(-700,-700)};
    Point jumpJabHighHit2[] = {Point(167,0), Point(223,100), Point(-700,-700)};
    Point jumpJabHighHit3[] = {Point(271,0), Point(322,100), Point(-700,-700)};
    Point jumpJabHighHit4[] = {Point(368,18), Point(429,100), Point(-700,-700)};

    Point jumpJabHurt1[] = {Point(120,22), Point(166,30), Point(-700,-700)};
    Point jumpJabHurt2[] = {Point(221,22), Point(263,30), Point(-700,-700)};
    Point jumpJabHurt3[] = {Point(327,22), Point(367,30), Point(-700,-700)};

    jumpJabFrames[0] = new Sprite(Global::PhoolanDeviAnimations[jumpJabP], Point(0,0), Point(61, 100),
                                       Point(12,100),jumpJabHighHit,0,0, 0);
    jumpJabFrames[1] = new Sprite(Global::PhoolanDeviAnimations[jumpJabP], Point(69,0), Point(166, 100),
                                       Point(88,100),jumpJabHighHit1,0,jumpJabHurt1, 0);
    jumpJabFrames[2] = new Sprite(Global::PhoolanDeviAnimations[jumpJabP], Point(167,0), Point(263, 100),
                                       Point(187,100),jumpJabHighHit2,0,jumpJabHurt2, 0);
    jumpJabFrames[3] = new Sprite(Global::PhoolanDeviAnimations[jumpJabP], Point(271,0), Point(367, 100),
                                       Point(291,100),jumpJabHighHit3,0,jumpJabHurt3, 0);
    jumpJabFrames[4] = new Sprite(Global::PhoolanDeviAnimations[jumpJabP], Point(368,0), Point(429, 100),
                                       Point(385,100),jumpJabHighHit4,0,0, 0);


    Sprite** crouchKickFrames = new Sprite*[13];
    Point crouchKickLowHit[] = {Point(0,9), Point(88,98), Point(-700,-700)};
    Point crouchKickLowHit1[] = {Point(94,9), Point(185,98), Point(-700,-700)};
    Point crouchKickLowHit2[] = {Point(193,9), Point(303,98), Point(-700,-700)};
    Point crouchKickLowHit3[] = {Point(311,9), Point(390,98), Point(-700,-700)};
    Point crouchKickLowHit4[] = {Point(397,9), Point(442,98), Point(-700,-700)};
    Point crouchKickLowHit5[] = {Point(450,9), Point(510,61), Point(-700,-700)};
    Point crouchKickLowHit6[] = {Point(561,9), Point(612,71), Point(-700,-700)};
    Point crouchKickLowHit7[] = {Point(682,49), Point(740,98), Point(-700,-700)};
    Point crouchKickLowHit8[] = {Point(800,49), Point(853,98), Point(-700,-700)};
    Point crouchKickLowHit9[] = {Point(917,49), Point(1012,98), Point(-700,-700)};
    Point crouchKickLowHit10[] = {Point(1020,49), Point(1096,98), Point(-700,-700)};
    Point crouchKickLowHit11[] = {Point(1104,49), Point(1181,98), Point(-700,-700)};
    Point crouchKickLowHit12[] = {Point(1190,18), Point(1280,98), Point(-700,-700)};

    Point crouchKickHurt5[] = {Point(506,41), Point(552,60), Point(-700,-700)};
    Point crouchKickHurt6[] = {Point(615,38), Point(675,61), Point(-700,-700)};
    Point crouchKickHurt7[] = {Point(735,61), Point(793,92), Point(-700,-700)};
    Point crouchKickHurt8[] = {Point(849,68), Point(911,94), Point(-700,-700)};


    crouchKickFrames[0] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(0,0), Point(88, 98),
                                           Point(3,98),0,crouchKickLowHit,0, 0);
    crouchKickFrames[1] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(94,0), Point(185, 98),
                                           Point(105,98),0,crouchKickLowHit1,0, 0);
    crouchKickFrames[2] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(193,0), Point(303, 98),
                                           Point(214,98),0,crouchKickLowHit2,0, 0);
    crouchKickFrames[3] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(311,0), Point(390, 98),
                                           Point(334,98),0,crouchKickLowHit3,0, 0);
    crouchKickFrames[4] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(397,0), Point(442, 98),
                                           Point(405,98),0,crouchKickLowHit4,0, 0);
    crouchKickFrames[5] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(450,0), Point(553, 98),
                                           Point(468,98),0,crouchKickLowHit5,crouchKickHurt5, 0);
    crouchKickFrames[6] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(561,0), Point(673, 98),
                                           Point(571,98),0,crouchKickLowHit6,crouchKickHurt6, 0);
    crouchKickFrames[7] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(682,0), Point(792, 98),
                                           Point(701,98),0,crouchKickLowHit7,crouchKickHurt7, 0);
    crouchKickFrames[8] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(800,0), Point(911, 98),
                                           Point(817,98),0,crouchKickLowHit8,crouchKickHurt8, 0);
    crouchKickFrames[9] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(917,0), Point(1012, 98),
                                           Point(937,98),0,crouchKickLowHit9,0, 0);
    crouchKickFrames[10] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(1020,0), Point(1096, 98),
                                           Point(1047,98),0,crouchKickLowHit10,0, 0);
    crouchKickFrames[11] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(1104,0), Point(1181, 98),
                                           Point(1124,98),0,crouchKickLowHit11,0, 0);
    crouchKickFrames[12] = new Sprite(Global::PhoolanDeviAnimations[crouchKickP], Point(1190,0), Point(1280, 98),
                                           Point(1207,98),0,crouchKickLowHit12,0, 0);


    Sprite** crouchTurnFrames = new Sprite*[3];
    crouchTurnFrames[0] = new Sprite(Global::PhoolanDeviAnimations[crouchTurnP], Point(0,0), Point(67,63),
                                     Point(7,63), 0,0,0, 0);
    crouchTurnFrames[1] = new Sprite(Global::PhoolanDeviAnimations[crouchTurnP], Point(75,0), Point(142,63),
                                     Point(81,63), 0,0,0, 0);
    crouchTurnFrames[2] = new Sprite(Global::PhoolanDeviAnimations[crouchTurnP], Point(149,0), Point(219,63),
                                     Point(156,63), 0,0,0, 0);


    Sprite** jumpKickFrames = new Sprite*[4];
    Point jumpKickHighHit[] = {Point(0,14), Point(62,89), Point(-700,-700)};
    Point jumpKickHighHit1[] = {Point(63,0), Point(115,57), Point(-700,-700)};
    Point jumpKickHighHit2[] = {Point(161,0), Point(216,57), Point(-700,-700)};
    Point jumpKickHighHit3[] = {Point(253,13), Point(314,89), Point(-700,-700)};

    Point jumpKickHurt1[] = {Point(111,45), Point(153,89), Point(-700,-700)};
    Point jumpKickHurt2[] = {Point(214,45), Point(251,89), Point(-700,-700)};

    jumpKickFrames[0] = new Sprite(Global::PhoolanDeviAnimations[jumpKickP], Point(0,0), Point(60, 89),
                                           Point(27,89),jumpKickHighHit,0,0, 0);
    jumpKickFrames[1] = new Sprite(Global::PhoolanDeviAnimations[jumpKickP], Point(63,0), Point(153, 89),
                                           Point(100,89),jumpKickHighHit1,0,jumpKickHurt1, 0);
    jumpKickFrames[2] = new Sprite(Global::PhoolanDeviAnimations[jumpKickP], Point(161,0), Point(252, 89),
                                           Point(195,89),jumpKickHighHit2,0,jumpKickHurt2, 0);
    jumpKickFrames[3] = new Sprite(Global::PhoolanDeviAnimations[jumpKickP], Point(253,0), Point(314, 89),
                                           Point(283,89),jumpKickHighHit3,0,0, 0);


    Sprite** crouchKick1Frames = new Sprite*[8];

    Point crouchKick1Hurt[] = {Point(0,0), Point(67,56), Point(-700,-700)};
    Point crouchKick1Hurt1[] = {Point(75,0), Point(125,56), Point(-700,-700)};
    Point crouchKick1Hurt2[] = {Point(133,0), Point(200,56), Point(-700,-700)};
    Point crouchKick1Hurt3[] = {Point(208,0), Point(258,56), Point(-700,-700)};


    crouchKick1Frames[0] = new Sprite(Global::PhoolanDeviAnimations[crouchKick1P], Point(0,0), Point(67,56),
                              Point(13,56),0,0,crouchKick1Hurt, 0);
    crouchKick1Frames[1] = new Sprite(Global::PhoolanDeviAnimations[crouchKick1P], Point(75,0), Point(125,56),
                              Point(85,56),0,0,crouchKick1Hurt1, 0);
    crouchKick1Frames[2] = new Sprite(Global::PhoolanDeviAnimations[crouchKick1P], Point(133,0), Point(200,56),
                              Point(143,56),0,0,crouchKick1Hurt2, 0);
    crouchKick1Frames[3] = new Sprite(Global::PhoolanDeviAnimations[crouchKick1P], Point(208,0), Point(258,56),
                              Point(212,56),0,0,crouchKick1Hurt3, 0);
    crouchKick1Frames[4] = new Sprite(Global::PhoolanDeviAnimations[crouchKick1P], Point(0,0), Point(67,56),
                              Point(13,56),0,0,crouchKick1Hurt, 0);
    crouchKick1Frames[5] = new Sprite(Global::PhoolanDeviAnimations[crouchKick1P], Point(75,0), Point(125,56),
                              Point(85,56),0,0,crouchKick1Hurt1, 0);
    crouchKick1Frames[6] = new Sprite(Global::PhoolanDeviAnimations[crouchKick1P], Point(133,0), Point(200,56),
                              Point(143,56),0,0,crouchKick1Hurt2, 0);
    crouchKick1Frames[7] = new Sprite(Global::PhoolanDeviAnimations[crouchKick1P], Point(208,0), Point(258,56),
                              Point(212,56),0,0,crouchKick1Hurt3, 0);

    Sprite** combo1Frames = new Sprite*[5];
    Point combo1HighHit[] = {Point(16,41), Point(44,72), Point(-700,-700)};
    Point combo1HighHit1[] = {Point(114,41), Point(147,72), Point(-700,-700)};
    Point combo1HighHit2[] = {Point(219,41), Point(244,72), Point(-700,-700)};
    Point combo1HighHit3[] = {Point(315,41), Point(345,72), Point(-700,-700)};
    Point combo1HighHit4[] = {Point(429,41), Point(470,72), Point(-700,-700)};
    Point combo1HighHit5[] = {Point(564,41), Point(604,72), Point(-700,-700)};


    Point combo1LowHit[] = {Point(9,72), Point(50,119), Point(-700,-700)};
    Point combo1LowHit1[] = {Point(112,72), Point(139,119), Point(-700,-700)};
    Point combo1LowHit2[] = {Point(196,72), Point(239,119), Point(-700,-700)};
    Point combo1LowHit3[] = {Point(300,72), Point(354,119), Point(-700,-700)};
    Point combo1LowHit4[] = {Point(413,72), Point(478,119), Point(-700,-700)};
    Point combo1LowHit5[] = {Point(557,72), Point(615,119), Point(-700,-700)};


    Point combo1Hurt3[] = {Point(334,12), Point(354,48), Point(-700,-700)};
    Point combo1Hurt4[] = {Point(482,18), Point(513,74), Point(-700,-700)};
    Point combo1Hurt5[] = {Point(624,23), Point(645,74), Point(-700,-700)};


    combo1Frames[0] = new Sprite(Global::PhoolanDeviAnimations[combo1P], Point(0,0), Point(70,119),
                              Point(22,119),combo1HighHit,combo1LowHit,0, 0);
    combo1Frames[1] = new Sprite(Global::PhoolanDeviAnimations[combo1P], Point(77,0), Point(160,119),
                              Point(102,119),combo1HighHit1,combo1LowHit1,0, 0);
    combo1Frames[2] = new Sprite(Global::PhoolanDeviAnimations[combo1P], Point(167,0), Point(258,119),
                              Point(178,119),combo1HighHit2,combo1LowHit2,0, 0);
    combo1Frames[3] = new Sprite(Global::PhoolanDeviAnimations[combo1P], Point(266,0), Point(376,119),
                              Point(273,119),combo1HighHit3,combo1LowHit3,combo1Hurt3, 0);
    combo1Frames[4] = new Sprite(Global::PhoolanDeviAnimations[combo1P], Point(384,0), Point(513,119),
                              Point(387,119),combo1HighHit4,combo1LowHit4,combo1Hurt4, 0);
    combo1Frames[5] = new Sprite(Global::PhoolanDeviAnimations[combo1P], Point(521,0), Point(650,119),
                              Point(523,119),combo1HighHit5,combo1LowHit5,combo1Hurt5, 0);

    Sprite** combo2Frames = new Sprite*[15];
    Point combo2HighHit[] = {Point(16,41), Point(44,72), Point(-700,-700)};
    Point combo2HighHit1[] = {Point(114,41), Point(147,72), Point(-700,-700)};
    Point combo2HighHit2[] = {Point(219,41), Point(244,72), Point(-700,-700)};
    Point combo2HighHit3[] = {Point(315,41), Point(345,72), Point(-700,-700)};
    Point combo2HighHit4[] = {Point(429,41), Point(470,72), Point(-700,-700)};
    Point combo2HighHit5[] = {Point(564,41), Point(604,72), Point(-700,-700)};
    Point combo2HighHit6[] = {Point(697,41), Point(727,72), Point(-700,-700)};
    Point combo2HighHit7[] = {Point(804,41), Point(844,72), Point(-700,-700)};
    Point combo2HighHit8[] = {Point(893,50), Point(921,72), Point(-700,-700)};
    Point combo2HighHit9[] = {Point(1000,50), Point(1040,72), Point(-700,-700)};
    Point combo2HighHit10[] = {Point(1104,50), Point(1141,72), Point(-700,-700)};
    Point combo2HighHit11[] = {Point(1210,50), Point(1238,72), Point(-700,-700)};
    Point combo2HighHit12[] = {Point(1295,45), Point(1326,72), Point(-700,-700)};
    Point combo2HighHit13[] = {Point(1379,45), Point(1404,72), Point(-700,-700)};
    Point combo2HighHit14[] = {Point(1458,45), Point(1492,72), Point(-700,-700)};

    Point combo2LowHit[] = {Point(9,72), Point(50,119), Point(-700,-700)};
    Point combo2LowHit1[] = {Point(112,72), Point(139,119), Point(-700,-700)};
    Point combo2LowHit2[] = {Point(196,72), Point(239,119), Point(-700,-700)};
    Point combo2LowHit3[] = {Point(300,72), Point(354,119), Point(-700,-700)};
    Point combo2LowHit4[] = {Point(413,72), Point(478,119), Point(-700,-700)};
    Point combo2LowHit5[] = {Point(557,72), Point(615,119), Point(-700,-700)};
    Point combo2LowHit6[] = {Point(693,72), Point(734,119), Point(-700,-700)};
    Point combo2LowHit7[] = {Point(815,72), Point(840,119), Point(-700,-700)};
    Point combo2LowHit8[] = {Point(882,72), Point(916,119), Point(-700,-700)};
    Point combo2LowHit9[] = {Point(987,72), Point(1026,119), Point(-700,-700)};
    Point combo2LowHit10[] = {Point(1092,72), Point(1129,119), Point(-700,-700)};
    Point combo2LowHit11[] = {Point(1193,72), Point(1229,119), Point(-700,-700)};
    Point combo2LowHit12[] = {Point(1283,72), Point(1320,119), Point(-700,-700)};
    Point combo2LowHit13[] = {Point(1378,72), Point(1419,119), Point(-700,-700)};
    Point combo2LowHit14[] = {Point(1461,72), Point(1510,119), Point(-700,-700)};

    Point combo2Hurt3[] = {Point(334,12), Point(354,48), Point(-700,-700)};
    Point combo2Hurt4[] = {Point(482,18), Point(513,74), Point(-700,-700)};
    Point combo2Hurt5[] = {Point(624,23), Point(645,74), Point(-700,-700)};
    Point combo2Hurt6[] = {Point(766,36), Point(769,81), Point(-700,-700)};
    Point combo2Hurt7[] = {Point(835,8), Point(863,38), Point(-700,-700)};
    Point combo2Hurt8[] = {Point(926,9), Point(970,102), Point(-700,-700)};
    Point combo2Hurt9[] = {Point(1047,19), Point(1070,104), Point(-700,-700)};


    combo2Frames[0] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(0,0), Point(70,119),
                              Point(22,119),combo1HighHit,combo1LowHit,0, 0);
    combo2Frames[1] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(77,0), Point(160,119),
                              Point(102,119),combo1HighHit1,combo1LowHit1,0, 0);
    combo2Frames[2] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(167,0), Point(258,119),
                              Point(178,119),combo1HighHit2,combo1LowHit2,0, 0);
    combo2Frames[3] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(266,0), Point(376,119),
                              Point(273,119),combo1HighHit3,combo1LowHit3,combo2Hurt3, 0);
    combo2Frames[4] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(384,0), Point(513,119),
                              Point(387,119),combo1HighHit4,combo1LowHit4,combo2Hurt4, 0);
    combo2Frames[5] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(521,0), Point(650,119),
                              Point(523,119),combo2HighHit5,combo2LowHit5,combo2Hurt5, 0);
    combo2Frames[6] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(657,0), Point(774,119),
                              Point(657,119),combo2HighHit6,combo2LowHit6,combo2Hurt6, 0);
    combo2Frames[7] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(780,0), Point(862,119),
                              Point(800,119),combo2HighHit7,combo2LowHit7,combo2Hurt7, 0);
    combo2Frames[8] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(870,0), Point(971,119),
                              Point(891,119),combo2HighHit8,combo2LowHit8,combo2Hurt8, 0);
    combo2Frames[9] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(977,0), Point(1077,119),
                              Point(1004,119),combo2HighHit9,combo2LowHit9,combo2Hurt9, 0);
    combo2Frames[10] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(1084,0), Point(1180,119),
                              Point(1107,119),combo2HighHit10,combo2LowHit10,0, 0);
    combo2Frames[11] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(1186,0), Point(1274,119),
                              Point(1208,119),combo2HighHit11,combo2LowHit11,0, 0);
    combo2Frames[12] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(1280,0), Point(1361,119),
                              Point(1288,119),combo2HighHit12,combo2LowHit12,0, 0);
    combo2Frames[13] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(1370,0), Point(1428,119),
                              Point(1371,119),combo2HighHit13,combo2LowHit13,0, 0);
    combo2Frames[14] = new Sprite(Global::PhoolanDeviAnimations[combo2P], Point(1437,0), Point(1523,119),
                              Point(1443,119),combo2HighHit14,combo2LowHit14,0, 0);


    Sprite** knockDownFrames = new Sprite*[8];

    knockDownFrames[0] = new Sprite(Global::PhoolanDeviAnimations[knockDownP], Point(0,0), Point(84,97),
                              Point(6,97),0,0,0, 0);
    knockDownFrames[1] = new Sprite(Global::PhoolanDeviAnimations[knockDownP], Point(91,0), Point(160,97),
                              Point(108,97),0,0,0, 0);
    knockDownFrames[2] = new Sprite(Global::PhoolanDeviAnimations[knockDownP], Point(162,0), Point(256,97),
                              Point(216,97),0,0,0, 0);
    knockDownFrames[3] = new Sprite(Global::PhoolanDeviAnimations[knockDownP], Point(264,0), Point(360,97),
                              Point(319,97),0,0,0, 0);
    knockDownFrames[4] = new Sprite(Global::PhoolanDeviAnimations[knockDownP], Point(361,0), Point(480,97),
                              Point(454,97),0,0,0, 0);
    knockDownFrames[5] = new Sprite(Global::PhoolanDeviAnimations[knockDownP], Point(488,0), Point(612,97),
                              Point(589,97),0,0,0, 0);
    knockDownFrames[6] = new Sprite(Global::PhoolanDeviAnimations[knockDownP], Point(619,0), Point(709,97),
                              Point(687,97),0,0,0, 0);
    knockDownFrames[7] = new Sprite(Global::PhoolanDeviAnimations[knockDownP], Point(619,0), Point(709,97),
                              Point(687,97),0,0,0, 0);


    Sprite** victoryFrames = new Sprite*[7];

    victoryFrames[0] = new Sprite(Global::PhoolanDeviAnimations[victoryP], Point(0,0), Point(100,105),
                              Point(24,105),0,0,0, 0);
    victoryFrames[1] = new Sprite(Global::PhoolanDeviAnimations[victoryP], Point(107,0), Point(225,105),
                              Point(153,105),0,0,0, 0);
    victoryFrames[2] = new Sprite(Global::PhoolanDeviAnimations[victoryP], Point(232,0), Point(322,105),
                              Point(266,105),0,0,0, 0);
    victoryFrames[3] = new Sprite(Global::PhoolanDeviAnimations[victoryP], Point(331,0), Point(406,105),
                              Point(348,105),0,0,0, 0);
    victoryFrames[4] = new Sprite(Global::PhoolanDeviAnimations[victoryP], Point(413,0), Point(482,105),
                              Point(425,105),0,0,0, 0);
    victoryFrames[5] = new Sprite(Global::PhoolanDeviAnimations[victoryP], Point(490,0), Point(556,105),
                              Point(497,105),0,0,0, 0);
    victoryFrames[6] = new Sprite(Global::PhoolanDeviAnimations[victoryP], Point(563,0), Point(629,105),
                              Point(573,105),0,0,0, 0);


    allAnimations = new Sprite**[numElementsP];
    allAnimations[stanceP] = stanceFrames;
    allAnimations[crouchP] = crouchFrames;
    allAnimations[guardP] = guardFrames;
    allAnimations[crouchGuardP] = crouchGuardFrames;
    allAnimations[jumpP] = jumpFrames;
    allAnimations[crouchJabP] = crouchJabFrames;
    allAnimations[shortKickP] = shortKickFrames;
    allAnimations[strongJabP] = strongJabFrames;
    allAnimations[walkForwardP] = walkForwardFrames;
    allAnimations[walkBackwardP] = walkBackwardFrames;
    allAnimations[crouchKickP] = crouchKickFrames;
    allAnimations[crouchTurnP] = crouchTurnFrames;
    allAnimations[jumpJabP] = jumpJabFrames;
    allAnimations[jumpKickP] = jumpKickFrames;
    allAnimations[crouchKick1P] = crouchKick1Frames;
    allAnimations[combo1P] = combo1Frames;
    allAnimations[combo2P] = combo2Frames;
    allAnimations[getHitCrouchP] = getHitCrouchFrames;
    allAnimations[getHitStandingHighP] = getHitStandingHighFrames;
    allAnimations[getHitStandingLowP] = getHitStandingLowFrames;
    allAnimations[knockDownP] = knockDownFrames;
    allAnimations[victoryP] = victoryFrames;

    currentAnimation = -1;
    currentAnimationInd = -1;
    Stance();
}

PhoolanDevi::~PhoolanDevi()
{
    delete [] allAnimations;
}


void PhoolanDevi::RecieveInput(Uint32 type, int key)
{
    if(type == SDL_KEYDOWN)
    {
        switch(key)
        {
        case iDown:
            if(state != sJumping)
            {
                state = sCrouching;
                if(negativeFrames == 0 && ifAcceptingInput)
                {
                    Crouch();
                }
            }
            break;
        case iKeyL:
            if(negativeFrames == 0 && ifAcceptingInput && cCombo > 0 && state == sNormal && super == 100)
            {
                Combo2();
                cCombo = -1;
            }
            if(negativeFrames == 0 && ifAcceptingInput)
            {
                if(state == sCrouching)
                {
                    CrouchKick1();
                }
                else if(state == sNormal)
                {
                    cCombo = 15 * Global::dF;
                }
            }

            break;
        case iKeyI:
            if(state == sCrouching && negativeFrames == 0)
            {
                ifAcceptingInput = false;
                blockType = bLow;
                CrouchGuarding();
            }
            else if(state == sNormal && negativeFrames == 0)
            {
                ifAcceptingInput = false;
                blockType = bHigh;
                Guarding();
            }
            break;
        case iKeyK:
            if(negativeFrames == 0 && ifAcceptingInput)
            {
                if(state == sCrouching)
                {
                    CrouchLightJab();
                }
                else if(state == sJumping)
                {
                    JumpJab();
                }
                else if(state == sNormal)
                {
                    StrongJab();
                }
            }
            break;
        case iSemiColon:
            if(negativeFrames == 0 && ifAcceptingInput)
            {
                if(state == sNormal)
                {
                    ShortKick();
                }
                else if(state == sJumping)
                {
                    JumpKick();
                }
                else if(state == sCrouching)
                {
                    CrouckKick();
                }
            }
            break;
        case iRight:
            if(negativeFrames == 0 && ifAcceptingInput)
            {
                if(state == sNormal)
                {
                    if(!orientation)
                    {
                        movement = mForward;
                        WalkForward();
                    }
                    else
                    {
                        movement = mBackward;
                        WalkBackward();
                    }
                }
                else if(state == sJumping)
                {
                    if(!orientation)
                    {
                        movement = mForward;
                    }
                    else
                    {
                        movement = mBackward;
                    }
                }
            }
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1P)
            {
                crouchKick1Status = crouchKick1RightP;
            }
            break;
        case iLeft:
            if(negativeFrames == 0 && ifAcceptingInput)
            {
                if(state == sNormal)
                {
                    if(!orientation)
                    {
                        movement = mBackward;
                        WalkBackward();
                    }
                    else
                    {
                        movement = mForward;
                        WalkForward();
                    }
                }
                else if(state == sJumping && negativeFrames == 0)
                {
                    if(!orientation)
                    {
                        movement = mBackward;
                    }
                    else
                    {
                        movement = mForward;
                    }
                }
            }
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1P)
            {
                crouchKick1Status = crouchKick1LeftP;
            }
            break;
        case iSpace:
            if(state == sCrouching && negativeFrames == 0 && ifAcceptingInput)
            {
                CrouchTurn();
            }
            else if(state == sNormal && negativeFrames == 0 && ifAcceptingInput)
            {
                Turn();
            }
            if(currentAnimation == crouchKick1P)
            {
                Turn();
            }
            break;
        case iUp:
            if(negativeFrames == 0 && ifAcceptingInput)
            {
                if(state == sCrouching)
                {
                    Jump();
                }
                else if(state == sNormal)
                {
                    JumpFromStand();
                }
                state = sJumping;
            }
            break;
        }
    }
    if(type == SDL_KEYUP)
    {
        switch(key)
        {
        case iDown:
            //state = sNormal;
           if(state != sJumping)
            {
                state = sNormal;
            }
            if(negativeFrames == 0 && ifAcceptingInput)
            {
                Stance();
            }
            break;
        case iKeyI:
            ifAcceptingInput = true;
            blockType = bNone;
            if(state == sCrouching)
            {
                Crouching();
            }
            else if(state == sNormal)
            {
                Stance();
            }
            break;
        case iRight:
            if((movement == mForward && !orientation) ||
               (movement == mBackward && orientation))
            {
                movement = mNone;
                if(negativeFrames == 0 && ifAcceptingInput && state == sNormal)
                {
                    Stance();
                }
            }
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1P)
            {
                crouchKick1Status = -1;
            }
            break;
        case iLeft:
            if((movement == mBackward && !orientation) ||
               (movement == mForward && orientation))
            {
                movement = mNone;
                if(negativeFrames == 0 && ifAcceptingInput && state == sNormal)
                {
                    Stance();
                }
            }
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1P)
            {
                crouchKick1Status = -1;
            }
            break;
        }
    }
}

Projectile* PhoolanDevi::UpdateSprite()
{
    oldPosition = position;
    Projectile* tempP = 0;
    if(cCombo > -1)
    {
        cCombo--;
    }
    if(cCombo == 0)
    {
        Combo1();
        cCombo--;
    }

    int a [] = {1 , -1};
    if(state == sJumping && negativeFrames == 0)
    {
        if(movement == mForward && !orientation || orientation && movement == mBackward)
        {
            position.x += 5;
        }
        else if(movement == mBackward && !orientation || orientation && movement == mForward)
        {
            position.x -= 5;
        }
    }

    currentAnimationInd++;
    if(currentAnimationInd / spread >= currentAnimationCap)
    {
        if(currentAnimation == victoryP || currentAnimation == knockDownP)
        {
            currentAnimationInd--;
            return 0;
        }
        if(currentAnimation == crouchKick1P)
        {
            crouchKick1Status = -1;
        }
        if(blockType == bNone)
        {
            if(state == sCrouching)
            {
                Crouching();
            }
            else if(state == sNormal)
            {
                if(movement == mForward)
                {
                    WalkForward();
                }
                else if(movement == mNone)
                {
                    Stance();
                }
                else if(movement == mBackward)
                {
                    if(currentAnimation == walkBackwardP)
                    {
                        WalkBackward();
                    }
                    else
                    {
                        WalkBackward(true);
                    }
                }
            }
            else if(state == sJumping)
            {
                Jumping();
            }
        }
        else if(blockType == bHigh)
        {
            Guarding();
        }
        else if(blockType == bLow)
        {
            CrouchGuarding();
        }
    }

    if(currentAnimationInd < 0)
    {
        currentAnimationInd = 0;
    }
    if(currentAnimation == jumpKickP)
    {
        yVelocity = 0;
        position.x += 3 * a[orientation];
        position.y += 3;
    }
    if(currentAnimation == crouchKickP && currentAnimationInd < 75)
    {
        position.x += 1 * a[orientation];
    }
    if(crouchKick1Status == crouchKick1LeftP)
    {
        position.x -= 5;
    }
    else if(crouchKick1Status == crouchKick1RightP)
    {
        position.x += 5;
    }

    if(currentAnimation == walkForwardP)
    {
        this->position.x += ((currentAnimationInd % spread) == 0 && currentAnimationInd > 0
                             && (currentAnimationInd / spread) <= 4) * 20
                              * (a[orientation])/* */;
    }
    else if(currentAnimation == walkBackwardP)
    {
        this->position.x -= (((currentAnimationInd % spread) == 0) /*&& (currentAnimationInd > 0)*/
                             && (((currentAnimationInd / spread) > 4) ||
                                 (currentAnimationInd == 0)))
                             * 20 * (a[orientation])/* */;
    }

    if(negativeFrames > 0)
    {
        negativeFrames--;
    }

    if(countToTurn > -1)
    {
        countToTurn--;
    }
    if(countToTurn == 0)
    {
        orientation = !orientation;
        int a = 249 - 213;
        if(orientation == 1)
        {
            position.x += a;
        }
        else
        {
            position.x -= a;
        }
    }
    if(currentAnimation == combo1P && currentAnimationInd < (spread*(currentAnimationCap - 2)))
    {
        position.x += 1*a[orientation];
    }
    if(currentAnimation == shortKickP && currentAnimationInd < spread * 3)
    {
//        cout << "called " << endl;
        position.x += 2;
    }
    if(!orientation)
    {
        if(position.x < 0)
        {
            position.x = 0;
        }
        else if(position.x > Global::SCREEN_WIDTH - 36)
        {
            position.x = Global::SCREEN_WIDTH - 36;
        }
    }
    else
    {
        if(position.x > Global::SCREEN_WIDTH)
        {
            position.x = Global::SCREEN_WIDTH;
        }
        else if(position.x < 36)
        {
            position.x = 36;
        }
    }
    if(position.y < Arena::baseLine || yVelocity < 0)
    {
        yVelocity += Arena::gravity;
        position.y += yVelocity;
    }
    if(position.y >= Arena::baseLine)
    {
        if(state == sJumping && yVelocity >= 0 || currentAnimation == jumpKickP)
        {
            if(currentAnimation == jumpKickP)
            {
                Stance();
            }
            state = sNormal;
            position.y = Arena::baseLine;
            yVelocity = 0;
        }
    }

//    cout << currentAnimationInd/spread << endl;
    nextSprite = allAnimations[currentAnimation][currentAnimationInd / spread];
    nextSprite->UpdateSprite(position, orientation);
    return tempP;
}

void PhoolanDevi::Render(SDL_Renderer* gRenderer)
{
    nextSprite->Render(gRenderer);
    healthBar->renderBar(gRenderer);
    superBar->renderBar(gRenderer);
//    SDL_SetRenderDrawColor(gRenderer, 0, 255 ,0 ,0);
//    SDL_RenderDrawPoint(gRenderer, position.x, position.y);
}


void PhoolanDevi::Turn()
{
    countToTurn = 1;
}

void PhoolanDevi::CrouchTurn()
{
    currentAnimation = crouchTurnP;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    countToTurn = negativeFrames;
}

void PhoolanDevi::CrouckKick()
{
    hasDamaged = false;
    damage = 5;
    //    int a[] = {1,-1};
//    position.x += a[orientation]*75;
    currentAnimation = crouchKickP;
    currentAnimationCap = 13;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void PhoolanDevi::Jump()
{
    currentAnimation = jumpP;
    spread = 4 * Global::dF;
    currentAnimationInd = spread - 1;
    currentAnimationCap = 11;
    yVelocity = -7 * Global::dF;
    negativeFrames = 0;
}

void PhoolanDevi::JumpFromStand()
{
    currentAnimation = jumpP;
    spread = 4 * Global::dF;
    currentAnimationInd = 2 * spread - 1;
    currentAnimationCap = 9;
    yVelocity = -7 * Global::dF;
    negativeFrames = 0;
}

void PhoolanDevi::Jumping()
{
    currentAnimation = jumpP;
    currentAnimationCap = 10;
    spread = 1;
    currentAnimationInd = 9;
    negativeFrames = 0;
}

void PhoolanDevi::Stance()
{
    currentAnimationInd = -1;
    currentAnimation = stanceP;
    currentAnimationCap = 13;
    spread = 8 * Global::dF;
    negativeFrames = 0;
}

void PhoolanDevi::Guarding()
{
    currentAnimation = guardP;
    currentAnimationCap = 1;
    spread = 1;
    currentAnimationInd = 0;
    negativeFrames = 0;
}

void PhoolanDevi::CrouchGuarding()
{
    currentAnimation = crouchGuardP;
    currentAnimationCap = 1;
    spread = 1;
    currentAnimationInd = 0;
    negativeFrames = 0;
}

void PhoolanDevi::WalkForward()
{
    currentAnimation = walkForwardP;
    currentAnimationInd = -1;
    currentAnimationCap = 8;
    spread = 4 * Global::dF;
    negativeFrames = 0;
}

void PhoolanDevi::WalkBackward(bool justIn)
{
    currentAnimation = walkBackwardP;
    if(justIn)
    {
        currentAnimationInd = 3;
    }
    else
    {
        currentAnimationInd = -1;
    }
    currentAnimationCap = 8;
    spread = 4 * Global::dF;
    negativeFrames = 0;
}

void PhoolanDevi::Crouching()
{
    currentAnimation = crouchP;
    currentAnimationCap = 2;
    spread = 1;
    currentAnimationInd = 1;
    negativeFrames = 0;
}

void PhoolanDevi::Crouch()
{
    currentAnimation = crouchP;
    currentAnimationCap = 2;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void PhoolanDevi::StrongJab()
{
    hasDamaged = false;
    damage = 5;
        currentAnimation = strongJabP;
    currentAnimationInd = -1;
    currentAnimationCap = 8;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void PhoolanDevi::CrouchLightJab()
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = crouchJabP;
    currentAnimationInd = -1;
    currentAnimationCap = 7;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void PhoolanDevi::ShortKick()
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = shortKickP;
    currentAnimationCap = 13;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void PhoolanDevi::JumpJab()
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = jumpJabP;
    currentAnimationCap = 5;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void PhoolanDevi::JumpKick()
{
        hasDamaged = false;
    damage = 5;
//    int a[] = {1,-1};
//    position.x += a[orientation]*100;
//    position.y += a[orientation]*100;
    currentAnimation = jumpKickP;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = 20 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void PhoolanDevi::CrouchKick1()
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = crouchKick1P;
    currentAnimationCap = 8;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void PhoolanDevi::Combo1()
{    hasDamaged = false;
    damage = 25;
    currentAnimation = combo1P;
    currentAnimationCap = 6;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void PhoolanDevi::Combo2()
{
    super = 0;
    superBar->emptyBar();
        hasDamaged = false;
    damage = 45;
    currentAnimation = combo2P;
    currentAnimationCap = 15;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    Global::superCount = negativeFrames * 1.1;
}


void PhoolanDevi::GetHitCrouch(int power)
{
    currentAnimation = getHitCrouchP;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void PhoolanDevi::GetHitStandingHigh(int power)
{
    currentAnimation = getHitStandingHighP;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void PhoolanDevi::GetHitStandingLow(int power)
{
    currentAnimation = getHitStandingLowP;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void PhoolanDevi::KnockDown()
{
    currentAnimation = knockDownP;
    currentAnimationCap = 8;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void PhoolanDevi::Victory()
{
    currentAnimation = victoryP;
    currentAnimationCap = 7;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

bool PhoolanDevi::HandleHit(int hitType, int damage, int frames)
{
    if(cHultHult == hitType || hitType == cLowLow || hitType == cHighHigh
       || cHighLow == hitType || hitType == cLowHigh)
    {
        PushBack(2);
        return false;
    }
    if(cHultHigh == hitType)
    {
        if(currentAnimation == guardP)
        {
            return false;
        }
        else
        {
            GetHitStandingHigh(frames);
            DecreaseHealth(damage);
            return true;
        }
    }
    if(cHultLow == hitType)
    {
        if(currentAnimation == crouchGuardP)
        {
            return false;
        }
        else
        {
            if(state == sCrouching)
            {
                DecreaseHealth(damage);
                GetHitCrouch(frames);
            }
            else
            {
                DecreaseHealth(damage);
                GetHitStandingLow(frames);
            }
            return true;
        }
    }
    return false;
}
