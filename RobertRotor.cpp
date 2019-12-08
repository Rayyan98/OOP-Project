#include "RobertRotor.h"
#include "Arena.h"
 /*   LoadImage(RobertRotorAnimations[getHitCrouch], "Sprites\\Birdie\\CrouchHit.png", gRenderer);
    LoadImage(RobertRotorAnimations[getHitStandingHigh], "Sprites\\Birdie\\HighHit.png", gRenderer);
    LoadImage(RobertRotorAnimations[getHitStandingLow], "Sprites\\Birdie\\LowHit.png", gRenderer);
    LoadImage(RobertRotorAnimations[getHitAir], "Sprites\\Birdie\\MidairHit(notes).png", gRenderer);*/

enum{stance, crouch, guard, crouchGuard, jump, crouchJab, shortKick,
     strongJab, walkForward, walkBackward, crouchKick, crouchTurn, jumpJab, jumpKick, comboFierce,comboChain,
     getHitCrouch, getHitStandingHigh,
     getHitStandingLow, getHitAir, knockDown, victory,numElements};


enum{cNone, cHultHult, cHultHigh, cHultLow,
            cHighHult, cHighHigh, cHighLow,
            cLowHult , cLowHigh , cLowLow};

RobertRotor::RobertRotor()
{

}

RobertRotor::RobertRotor(Point position1, bool orientation, bool player2) : Character(position1, orientation, player2)
{
  ///  cCombo = -1;
//    crouchKick1Status = -1;

    Sprite** getHitCrouchFrames = new Sprite*[3];
    Point getHitCrouchLowHit[] = {Point(0,0), Point(103,87), Point(-700,-700)};
    Point getHitCrouchLowHit1[] = {Point(102,0), Point(214,87), Point(-700,-700)};
    Point getHitCrouchLowHit2[] = {Point(216,0), Point(330,87), Point(-700,-700)};

    getHitCrouchFrames[0] = new Sprite(Global::RobertRotorAnimations[getHitCrouch],
                                       Point(0,0), Point(103,87), Point(16,87), 0, getHitCrouchLowHit,0,0);
    getHitCrouchFrames[1] = new Sprite(Global::RobertRotorAnimations[getHitCrouch],
                                       Point(94,0), Point(195,87), Point(136,87), 0, getHitCrouchLowHit1,0,0);
    getHitCrouchFrames[2] = new Sprite(Global::RobertRotorAnimations[getHitCrouch],
                                       Point(214,0), Point(330,87), Point(265,87), 0, getHitCrouchLowHit2,0,0);

    Sprite** getHitStandingLowFrames = new Sprite*[4];

    Point getHitStandingLowHigh[] = {Point(0,0),Point(101,53),Point(-700,-700)};
    Point getHitStandingLowHigh1[] = {Point(104,0),Point(211,64),Point(-700,-700)};
    Point getHitStandingLowHigh2[] = {Point(216,0),Point(340,65),Point(-700,-700)};
    Point getHitStandingLowHigh3[] = {Point(337,0),Point(460,63),Point(-700,-700)};

    Point getHitStandingLowLow[] = {Point(0,53),Point(86,112),Point(-700,-700)};
    Point getHitStandingLowLow1[] = {Point(101,64),Point(195,112),Point(-700,-700)};
    Point getHitStandingLowLow2[] = {Point(214,65),Point(314,112),Point(-700,-700)};
    Point getHitStandingLowLow3[] = {Point(342,63),Point(437,112),Point(-700,-700)};

    getHitStandingLowFrames[0] = new Sprite(Global::RobertRotorAnimations[getHitStandingLow],
                                Point(0,0),Point(100,112),Point(16,112),getHitStandingLowHigh,
                                            getHitStandingLowLow,0,0);
    getHitStandingLowFrames[1] = new Sprite(Global::RobertRotorAnimations[getHitStandingLow],
                                Point(105,0),Point(210,112),Point(118,112),getHitStandingLowHigh1,
                                            getHitStandingLowLow1,0,0);
    getHitStandingLowFrames[2] = new Sprite(Global::RobertRotorAnimations[getHitStandingLow],
                                Point(213,0),Point(333,112),Point(236,112),getHitStandingLowHigh2,
                                            getHitStandingLowLow2,0,0);
    getHitStandingLowFrames[3] = new Sprite(Global::RobertRotorAnimations[getHitStandingLow],
                                Point(340,0),Point(460,112),Point(337,112),getHitStandingLowHigh3,
                                            getHitStandingLowLow3,0,0);


    Sprite** getHitStandingHighFrames = new Sprite*[4];

    Point getHitStandingHighFramesHighHit[] = {Point(0,0),Point(94,61),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit1[] = {Point(96,0),Point(212,71),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit2[] = {Point(218,0),Point(318,66),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit3[] = {Point(318 ,0),Point(430,60),Point(-700,-700)};

    Point getHitStandingHighFramesLowHit[] = {Point(0, 61),Point(92,119),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit1[] = {Point(97,71),Point(211,119),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit2[] = {Point(211,66),Point(318,119),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit3[] = {Point(318,60),Point(430,119),Point(-700,-700)};

    getHitStandingHighFrames[0] = new Sprite(Global::RobertRotorAnimations[getHitStandingHigh],
                                       Point(0,0), Point(88,119), Point(12,119), getHitStandingHighFramesHighHit,
                                       getHitStandingHighFramesLowHit,0,0);
    getHitStandingHighFrames[1] = new Sprite(Global::RobertRotorAnimations[getHitStandingHigh],
                                       Point(93,0), Point(212,119), Point(112,119), getHitStandingHighFramesHighHit1,
                                             getHitStandingHighFramesLowHit1,0,0);
    getHitStandingHighFrames[2] = new Sprite(Global::RobertRotorAnimations[getHitStandingHigh],
                                       Point(206,0), Point(322,119), Point(229,119), getHitStandingHighFramesHighHit2,
                                             getHitStandingHighFramesLowHit2,0,0);
    getHitStandingHighFrames[3] = new Sprite(Global::RobertRotorAnimations[getHitStandingHigh],
                                       Point(323,0), Point(430,119), Point(351,119), getHitStandingHighFramesHighHit3,
                                             getHitStandingHighFramesLowHit3,0,0);

//    cout << position.x << position.y << endl;
    Sprite** stanceFrames = new Sprite*[4];
    //Sprite** stanceFrames = new Sprite*[6];
    Point stanceHighHit[] = {Point(14,0), Point(100,50), Point(-700,-700)};
    Point stanceHighHit1[] = {Point(123,0), Point(195,50), Point(-700,-700)};
    Point stanceHighHit2[] = {Point(231,0), Point(304,50), Point(-700,-700)};
    Point stanceHighHit3[] = {Point(337,0), Point(412,50), Point(-700,-700)};

    Point stanceLowHit[] = {Point(2,50), Point(85,110), Point(-700,-700)};
    Point stanceLowHit1[] = {Point(107,50), Point(193,110), Point(-700,-700)};
    Point stanceLowHit2[] = {Point(217,50), Point(301,110), Point(-700,-700)};
    Point stanceLowHit3[] = {Point(325,50), Point(406,110), Point(-700,-700)};

    stanceFrames[0] = new Sprite(Global::RobertRotorAnimations[stance], Point(0,0), Point(101,109),
                                 Point(4,110), stanceHighHit, stanceLowHit, 0, 0);
    stanceFrames[1] = new Sprite(Global::RobertRotorAnimations[stance], Point(101, 0), Point(200, 109),
                                 Point(115, 110), stanceHighHit1, stanceLowHit1, 0, 0);
    stanceFrames[2] = new Sprite(Global::RobertRotorAnimations[stance], Point(212, 0), Point(320, 109),
                                 Point(224, 110), stanceHighHit2,stanceLowHit2,0, 0);
    stanceFrames[3] = new Sprite(Global::RobertRotorAnimations[stance], Point(320,0), Point(423, 109),
                                 Point(329, 110), stanceHighHit3,stanceLowHit3,0, 0);

    Sprite** crouchFrames = new Sprite*[2];

    Point crouchLowHit[] = {Point(0,0), Point(98,103), Point(-700,-700)};
    Point crouchLowHit1[] = {Point(105,17), Point(204,103), Point(-700,-700)};
    Point crouchLowHit2[] = {Point(213,17), Point(311,103), Point(-700,-700)};

    crouchFrames[0] = new Sprite(Global::RobertRotorAnimations[crouch], Point(0, 0), Point(100,100),
                             Point(12, 103),0,crouchLowHit,0, 0);
    crouchFrames[1] = new Sprite(Global::RobertRotorAnimations[crouch], Point(100, 0), Point(205, 100),
                             Point(116, 103),0,crouchLowHit1,0, 0);
    crouchFrames[2] = new Sprite(Global::RobertRotorAnimations[crouch], Point(205, 0), Point(311, 100),
                             Point(222, 103),0 ,crouchLowHit2,0, 0);

    Sprite** guardFrames = new Sprite*[2];


    Point guardHighHit[] = {Point(4,0), Point(90,54), Point(-700,-700)};
    Point guardHighHit1[] = {Point(92,0), Point(195,54), Point(-700,-700)};

    Point guardLowHit[] = {Point(4,54), Point(90,117), Point(-700,-700)};
    Point guardLowHit1[] = {Point(92,54), Point(195,117), Point(-700,-700)};
    guardFrames[0] = new Sprite(Global::RobertRotorAnimations[guard], Point(0,0), Point(85,116),
                                Point(15, 117),guardHighHit,guardLowHit,0, 0);
    guardFrames[1] = new Sprite(Global::RobertRotorAnimations[guard], Point(85,0), Point(195,116),
                                Point(118, 117),guardHighHit1,guardLowHit1,0, 0);


    Sprite** crouchGuardFrames = new Sprite*[2];

    Point crouchguardLowHit[] = {Point(0,0), Point(87,85), Point(-700,-700)};
    Point crouchguardLowHit1[] = {Point(92,0), Point(195,85), Point(-700,-700)};
    crouchGuardFrames[0] = new Sprite(Global::RobertRotorAnimations[crouchGuard], Point(0,0), Point(87,85),
                                      Point(12,85),0,crouchguardLowHit,0, 0);
    crouchGuardFrames[1] = new Sprite(Global::RobertRotorAnimations[crouchGuard], Point(95,0), Point(195,85),
                                      Point(110,84),0,crouchguardLowHit1,0,0);

    Point jumpHighHit[] = {Point(6,40), Point(100,89), Point(-700,-700)};
    Point jumpHighHit1[] = {Point(100,0), Point(225,67), Point(-700,-700)};
    Point jumpHighHit2[] = {Point(233,30), Point(338,81), Point(-700,-700)};
    Point jumpHighHit7[] = {Point(804,29), Point(916,96), Point(-700,-700)};
    Point jumpHighHit8[] = {Point(921,0), Point(1030,70), Point(-700,-700)};
    Point jumpHighHit9[] = {Point(1035,41), Point(1137,86), Point(-700,-700)};

    Point jumpLowHit[] = {Point(6,40), Point(100,145), Point(-700,-700)};
    Point jumpLowHit1[] = {Point(121,67), Point(193,148), Point(-700,-700)};
    Point jumpLowHit2[] = {Point(224,81), Point(301,148), Point(-700,-700)};
    Point jumpLowHit3[] = {Point(343,65), Point(448,148), Point(-700,-700)};
    Point jumpLowHit4[] = {Point(451,60), Point(564,148), Point(-700,-700)};
    Point jumpLowHit5[] = {Point(564,50), Point(685,148), Point(-700,-700)};
    Point jumpLowHit6[] = {Point(685,55), Point(796,148), Point(-700,-700)};
    Point jumpLowHit7[] = {Point(801,76), Point(883,148), Point(-700,-700)};
    Point jumpLowHit8[] = {Point(911,70), Point(1011,148), Point(-700,-700)};
    Point jumpLowHit9[] = {Point(1036,86), Point(1137,148), Point(-700,-700)};

    Sprite** jumpFrames = new Sprite*[12];   //quick
    jumpFrames[0] = new Sprite(Global::RobertRotorAnimations[jump], Point(0,0), Point(100,148),
                               Point(6,148),jumpHighHit,jumpLowHit,0, 0);

    jumpFrames[1] = new Sprite(Global::RobertRotorAnimations[jump], Point(224,0), Point(337,148),
                               Point(237,148),jumpHighHit2,jumpLowHit2,0, 0);
    jumpFrames[2] = new Sprite(Global::RobertRotorAnimations[jump], Point(104,0), Point(217,148),
                               Point(130,148),jumpHighHit1,jumpLowHit1,0, 0);
    jumpFrames[3] = new Sprite(Global::RobertRotorAnimations[jump], Point(224,0), Point(337,148),
                               Point(237,148),jumpHighHit2,jumpLowHit2,0, 0);
    jumpFrames[4] = new Sprite(Global::RobertRotorAnimations[jump], Point(341,0), Point(448,148),
                               Point(367,148),0,jumpLowHit3,0, 0);
    jumpFrames[5] = new Sprite(Global::RobertRotorAnimations[jump], Point(458,0), Point(561,148),
                               Point(483,148),0,jumpLowHit4,0, 0);
    jumpFrames[6] = new Sprite(Global::RobertRotorAnimations[jump], Point(569,0), Point(681,148),
                               Point(593,148),0,jumpLowHit5,0, 0);
    jumpFrames[7] = new Sprite(Global::RobertRotorAnimations[jump], Point(687,0), Point(796,148),
                               Point(709,148),0,jumpLowHit6,0, 0);
    jumpFrames[8] = new Sprite(Global::RobertRotorAnimations[jump], Point(800,0), Point(912,148),
                               Point(810,148),jumpHighHit7,jumpLowHit7,0, 0);

    jumpFrames[9] = new Sprite(Global::RobertRotorAnimations[jump], Point(918,0), Point(1031,148),
                               Point(947,148),jumpHighHit8,jumpLowHit8,0, 0);

    jumpFrames[10] = new Sprite(Global::RobertRotorAnimations[jump], Point(800,0), Point(912,148),
                               Point(810,148),jumpHighHit7,jumpLowHit7,0, 0);
    jumpFrames[11] = new Sprite(Global::RobertRotorAnimations[jump], Point(1037,0), Point(1137,148),
                               Point(1094,148),jumpHighHit9,jumpLowHit9,0, 0);
    //jumpFrames[10] = new Sprite(Global::RobertRotorAnimations[jump], Point(646,0), Point(702,148),
         //                      Point(668,148),0,0,0, 0);
    //jumpFrames[11] = new Sprite(Global::RobertRotorAnimations[jump], Point(702,0), Point(764,148),
           //                    Point(720,148),0,0,0, 0);

    Sprite** crouchJabFrames = new Sprite*[4]; //very quick
    Point crouchJabLowHit[] = {Point(0,0), Point(111,93), Point(-700,-700)};
    Point crouchJabLowHit1[] = {Point(111,0), Point(263,93), Point(-700,-700)};
    Point crouchJabLowHit2[] = {Point(271,0), Point(378,93), Point(-700,-700)};
    Point crouchJabLowHit3[] = {Point(380,0), Point(489,93), Point(-700,-700)};

    Point crouchJabLowHurt1[] = {Point(200,0), Point(263,48), Point(-700,-700)};
    Point crouchJabLowHurt2[] = {Point(349,15), Point(376,50), Point(-700,-700)};

    crouchJabFrames[0] = new Sprite(Global::RobertRotorAnimations[crouchJab], Point(0,0), Point(110,93),
                              Point(10,93),0,crouchJabLowHit,0, 0);
    crouchJabFrames[1] = new Sprite(Global::RobertRotorAnimations[crouchJab], Point(116,0), Point(262,93),
                              Point(129,93),0,crouchJabLowHit1,crouchJabLowHurt1, 0);
    crouchJabFrames[2] = new Sprite(Global::RobertRotorAnimations[crouchJab], Point(270,0), Point(375,93),
                              Point(279,93),0,crouchJabLowHit2,crouchJabLowHurt2, 0);
    crouchJabFrames[3] = new Sprite(Global::RobertRotorAnimations[crouchJab], Point(385,0), Point(488,93),
                              Point(392,93),0,crouchJabLowHit3,0, 0);

    Sprite** shortKickFrames = new Sprite*[5]; //CHECK MATHS very quixk
    Point shortKickHighHit[] = {Point(0,0), Point(90,60), Point(-700,-700)};
    Point shortKickHighHit1[] = {Point(95,0), Point(187,52), Point(-700,-700)};
    Point shortKickHighHit2[] = {Point(235,0), Point(335,52), Point(-700,-700)};

    Point shortKickLowHit[] = {Point(1,60), Point(81,111), Point(-700,-700)};
    Point shortKickLowHit1[] = {Point(95,52), Point(225,111), Point(-700,-700)};
    Point shortKickLowHit2[] = {Point(231,52), Point(330,111), Point(-700,-700)};


    Point shortKickLowHurt[] = {Point(52,48), Point(88,88), Point(-700,-700)};
    Point shortKickLowHurt1[] = {Point(184,48), Point(229,111), Point(-700,-700)};

    shortKickFrames[0] = new Sprite(Global::RobertRotorAnimations[shortKick], Point(0,0), Point(89,111),
                                    Point(15,111),shortKickHighHit,shortKickLowHit, shortKickLowHurt,0);
    shortKickFrames[1] = new Sprite(Global::RobertRotorAnimations[shortKick], Point(94,0), Point(228, 111),
                                    Point(123 , 111),shortKickHighHit1,shortKickLowHit1,shortKickLowHurt1, 0);
    shortKickFrames[2] = new Sprite(Global::RobertRotorAnimations[shortKick], Point(230,0), Point(335, 111),
                                    Point(240,111),shortKickHighHit2,shortKickLowHit2,0, 0);
   // shortKickFrames[3] = new Sprite(Global::RobertRotorAnimations[shortKick], Point(279,0), Point(408, 113),
                                    //Point(333-44,112),0,0,0, 0);
    //shortKickFrames[4] = new Sprite(Global::RobertRotorAnimations[shortKick], Point(408,0), Point(469,113),
                                    //Point(455-44,112),0,0,0, 0);

    Sprite** strongJabFrames = new Sprite*[6];
    Point strongJabHighHit[] = {Point(0,0), Point(122,63), Point(-700,-700)};
    Point strongJabHighHit1[] = {Point(136,0), Point(236,65), Point(-700,-700)};
    Point strongJabHighHit2[] = {Point(261,0), Point(403,62), Point(-700,-700)};
    Point strongJabHighHit3[] = {Point(429,0), Point(574,60), Point(-700,-700)};
    Point strongJabHighHit4[] = {Point(604,0), Point(700,62), Point(-700,-700)};
    Point strongJabHighHit5[] = {Point(731,0), Point(808,60), Point(-700,-700)};

    Point strongJabLowHit[] = {Point(0,63), Point(91,126), Point(-700,-700)};
    Point strongJabLowHit1[] = {Point(130,65), Point(222,126), Point(-700,-700)};
    Point strongJabLowHit2[] = {Point(241,62), Point(343,126), Point(-700,-700)};
    Point strongJablowHit3[] = {Point(411,60), Point(512,126), Point(-700,-700)};
    Point strongJabLowHit4[] = {Point(579,62), Point(673,126), Point(-700,-700)};
    Point strongJabLowHit5[] = {Point(706,60), Point(794,126), Point(-700,-700)};

    Point strongJabHurt1[] = {Point(172,12), Point(210,47), Point(-700,-700)};
    Point strongJabHurt2[] = {Point(337,16), Point(404,61), Point(-700,-700)};
    Point strongJabHurt3[] = {Point(504,12), Point(575,64), Point(-700,-700)};
    Point strongJabHurt4[] = {Point(658,28), Point(700,72), Point(-700,-700)};


    strongJabFrames[0] = new Sprite(Global::RobertRotorAnimations[strongJab], Point(0,0), Point(125,126),
                                    Point(8,126),strongJabHighHit,strongJabLowHit,0, 0);
    strongJabFrames[1] = new Sprite(Global::RobertRotorAnimations[strongJab], Point(129,0), Point(236,126),
                                    Point(146,126),strongJabHighHit1,strongJabLowHit1,strongJabHurt1, 0);
    strongJabFrames[2] = new Sprite(Global::RobertRotorAnimations[strongJab], Point(239,0), Point(403,126),
                                    Point(253,126),strongJabHighHit2,strongJabLowHit2,strongJabHurt2, 0);
    strongJabFrames[3] = new Sprite(Global::RobertRotorAnimations[strongJab], Point(407,0), Point(574,126),
                                    Point(424,126),strongJabHighHit3,strongJablowHit3,strongJabHurt3, 0);
    strongJabFrames[4] = new Sprite(Global::RobertRotorAnimations[strongJab], Point(579,0), Point(699,126),
                                    Point(589,126),strongJabHighHit4,strongJabHighHit4,strongJabHurt4, 0);
    strongJabFrames[5] = new Sprite(Global::RobertRotorAnimations[strongJab], Point(702,0), Point(808,126),
                                    Point(716,126),strongJabHighHit5,strongJabLowHit5,0, 0);

    Sprite** walkForwardFrames = new Sprite*[8];

    Point walkForwardHighHit[] = {Point(17,0), Point(96,66), Point(-700,-700)};
    Point walkForwardHighHit1[] = {Point(124,0), Point(219,66), Point(-700,-700)};
    Point walkForwardHighHit2[] = {Point(225,0), Point(312,66), Point(-700,-700)};
    Point walkForwardHighHit3[] = {Point(313,0), Point(398,66), Point(-700,-700)};
    Point walkForwardHighHit4[] = {Point(410,0), Point(495,66), Point(-700,-700)};
    Point walkForwardHighHit5[] = {Point(518,0), Point(596,66), Point(-700,-700)};
    Point walkForwardHighHit6[] = {Point(601,0), Point(684,66), Point(-700,-700)};
    Point walkForwardHighHit7[] = {Point(691,0), Point(775,66), Point(-700,-700)};

    Point walkForwardLowHit[] = {Point(0,66), Point(101,124), Point(-700,-700)};
    Point walkForwardLowHit1[] = {Point(103,66), Point(202,124), Point(-700,-700)};
    Point walkForwardLowHit2[] = {Point(218,66), Point(293,124), Point(-700,-700)};
    Point walkForwardLowHit3[] = {Point(319,66), Point(370,124), Point(-700,-700)};
    Point walkForwardLowHit4[] = {Point(402,66), Point(491,124), Point(-700,-700)};
    Point walkForwardLowHit5[] = {Point(499,66), Point(585,124), Point(-700,-700)};
    Point walkForwardLowHit6[] = {Point(610,66), Point(666,124), Point(-700,-700)};
    Point walkForwardLowHit7[] = {Point(686,66), Point(775,124), Point(-700,-700)};

    walkForwardFrames[0] = new Sprite(Global::RobertRotorAnimations[walkForward], Point(0,0), Point(100,124),
                                      Point(5,124),walkForwardHighHit,walkForwardLowHit,0, 0);
    walkForwardFrames[1] = new Sprite(Global::RobertRotorAnimations[walkForward], Point(105,0), Point(214,124),
                                      Point(117,124),walkForwardHighHit1,walkForwardLowHit1,0, 0);
    walkForwardFrames[2] = new Sprite(Global::RobertRotorAnimations[walkForward], Point(218,0), Point(312,124),
                                      Point(226,124),walkForwardHighHit2,walkForwardLowHit2,0, 0);
    walkForwardFrames[3] = new Sprite(Global::RobertRotorAnimations[walkForward], Point(314,0), Point(395,124),
                                      Point(342,124),walkForwardHighHit3,walkForwardLowHit3,0, 0);
    walkForwardFrames[4] = new Sprite(Global::RobertRotorAnimations[walkForward], Point(403,0), Point(495,124),
                                      Point(462,124),walkForwardHighHit4,walkForwardLowHit4,0, 0);
    walkForwardFrames[5] = new Sprite(Global::RobertRotorAnimations[walkForward], Point(498,0), Point(602,124),
                                      Point(560,124),walkForwardHighHit5,walkForwardLowHit5,0, 0);
    walkForwardFrames[6] = new Sprite(Global::RobertRotorAnimations[walkForward], Point(603,0), Point(685,124),
                                      Point(639,124),walkForwardHighHit6,walkForwardLowHit6,0, 0);
    walkForwardFrames[7] = new Sprite(Global::RobertRotorAnimations[walkForward], Point(689,0), Point(775,124),
                                      Point(704,124),walkForwardHighHit7,walkForwardLowHit7,0, 0);

    Sprite** walkBackwardFrames = new Sprite*[8];
    Point walkBackwardHighHit[] = {Point(17,0), Point(96,66), Point(-700,-700)};
    Point walkBackwardHighHit1[] = {Point(124,0), Point(219,66), Point(-700,-700)};
    Point walkBackwardHighHit2[] = {Point(225,0), Point(312,66), Point(-700,-700)};
    Point walkBackwardHighHit3[] = {Point(313,0), Point(398,66), Point(-700,-700)};
    Point walkBackwardHighHit4[] = {Point(410,0), Point(495,66), Point(-700,-700)};
    Point walkBackwardHighHit5[] = {Point(518,0), Point(596,66), Point(-700,-700)};
    Point walkBackwardHighHit6[] = {Point(601,0), Point(684,66), Point(-700,-700)};
    Point walkBackwardHighHit7[] = {Point(691,0), Point(775,66), Point(-700,-700)};

    Point walkBackwardLowHit[] = {Point(0,66), Point(101,124), Point(-700,-700)};
    Point walkBackwardLowHit1[] = {Point(103,66), Point(202,124), Point(-700,-700)};
    Point walkBackwardLowHit2[] = {Point(218,66), Point(293,124), Point(-700,-700)};
    Point walkBackwardLowHit3[] = {Point(319,66), Point(370,124), Point(-700,-700)};
    Point walkBackwardLowHit4[] = {Point(402,66), Point(491,124), Point(-700,-700)};
    Point walkBackwardLowHit5[] = {Point(499,66), Point(585,124), Point(-700,-700)};
    Point walkBackwardLowHit6[] = {Point(610,66), Point(666,124), Point(-700,-700)};
    Point walkBackwardLowHit7[] = {Point(686,66), Point(775,124), Point(-700,-700)};
    walkBackwardFrames[7] = new Sprite(Global::RobertRotorAnimations[walkBackward], Point(0,0), Point(100,124),
                                      Point(5,124),walkBackwardHighHit,walkBackwardLowHit,0, 0);
    walkBackwardFrames[6] = new Sprite(Global::RobertRotorAnimations[walkBackward], Point(105,0), Point(214,124),
                                      Point(117,124),walkBackwardHighHit1,walkBackwardLowHit1,0, 0);
    walkBackwardFrames[5] = new Sprite(Global::RobertRotorAnimations[walkBackward], Point(218,0), Point(312,124),
                                      Point(226,124),walkBackwardHighHit2,walkBackwardLowHit2,0, 0);
    walkBackwardFrames[4] = new Sprite(Global::RobertRotorAnimations[walkBackward], Point(314,0), Point(395,124),
                                      Point(342,124),walkBackwardHighHit3,walkBackwardLowHit3,0, 0);
    walkBackwardFrames[3] = new Sprite(Global::RobertRotorAnimations[walkBackward], Point(403,0), Point(495,124),
                                      Point(462,124),walkBackwardHighHit4,walkBackwardLowHit4,0, 0);
    walkBackwardFrames[2] = new Sprite(Global::RobertRotorAnimations[walkBackward], Point(498,0), Point(599,124),
                                      Point(560,124),walkBackwardHighHit5,walkBackwardLowHit5,0, 0);
    walkBackwardFrames[1] = new Sprite(Global::RobertRotorAnimations[walkBackward], Point(603,0), Point(685,124),
                                      Point(639,124),walkBackwardHighHit6,walkBackwardLowHit6,0, 0);
    walkBackwardFrames[0] = new Sprite(Global::RobertRotorAnimations[walkBackward], Point(689,0), Point(775,124),
                                      Point(704,124),walkBackwardHighHit7,walkBackwardLowHit7,0, 0);

    Sprite** crouchKickFrames = new Sprite*[6];

    Point crouchKickHurt1[] = {Point(178,25), Point(229,71), Point(-700,-700)};
    Point crouchKickHurt2[] = {Point(337,23), Point(416,63), Point(-700,-700)};
    Point crouchKickHurt3[] = {Point(493,38), Point(560,83), Point(-700,-700)};

    Point crouchKickLowHit[] = {Point(0,0), Point(111,102), Point(-700,-700)};
    Point crouchKickLowHit1[] = {Point(111,0), Point(226,102), Point(-700,-700)};
    Point crouchKickLowHit2[] = {Point(228,0), Point(416,102), Point(-700,-700)};
    Point crouchKickLowHit3[] = {Point(410,0), Point(560,102), Point(-700,-700)};
    Point crouchKickLowHit4[] = {Point(556,0), Point(673,102), Point(-700,-700)};
    Point crouchKickLowHit5[] = {Point(673,0), Point(776,102), Point(-700,-700)};


    crouchKickFrames[0] = new Sprite(Global::RobertRotorAnimations[crouchKick], Point(0,0), Point(99, 102),
                                           Point(16,102),0,crouchKickLowHit,0, 0);
    crouchKickFrames[1] = new Sprite(Global::RobertRotorAnimations[crouchKick], Point(104,0), Point(226, 102),
                                           Point(171,102),0,crouchKickLowHit1,crouchKickHurt1, 0);
    crouchKickFrames[2] = new Sprite(Global::RobertRotorAnimations[crouchKick], Point(226,0), Point(417, 102),
                                           Point(312,102),0,crouchKickLowHit2,crouchKickHurt2, 0);
    crouchKickFrames[3] = new Sprite(Global::RobertRotorAnimations[crouchKick], Point(419,0), Point(554, 102),
                                           Point(469,102),0,crouchKickLowHit3,crouchKickHurt3, 0);
    crouchKickFrames[4] = new Sprite(Global::RobertRotorAnimations[crouchKick], Point(551,0), Point(667, 102),
                                           Point(570,102),0,crouchKickLowHit4,0, 0);
    crouchKickFrames[5] = new Sprite(Global::RobertRotorAnimations[crouchKick], Point(676,0), Point(776, 102),
                                           Point(686,102),0,crouchKickLowHit5,0, 0);


    Sprite** crouchTurnFrames = new Sprite*[3];

    Point crouchTurnLowHit[] = {Point(0,0), Point(98,103), Point(-700,-700)};
    Point crouchTurnLowHit1[] = {Point(105,17), Point(204,103), Point(-700,-700)};
    Point crouchTurnLowHit2[] = {Point(213,17), Point(311,103), Point(-700,-700)};

    crouchTurnFrames[0] = new Sprite(Global::RobertRotorAnimations[crouchTurn], Point(0,0), Point(100,84),
                                     Point(15,84), 0,crouchTurnLowHit,0, 0);
    crouchTurnFrames[1] = new Sprite(Global::RobertRotorAnimations[crouchTurn], Point(105,0), Point(203,84),
                                     Point(139,84), 0,crouchTurnLowHit1,0, 0);
    crouchTurnFrames[2] = new Sprite(Global::RobertRotorAnimations[crouchTurn], Point(206,0), Point(308,84),
                                     Point(251,84), 0,crouchTurnLowHit2,0, 0);

    Sprite** jumpJabFrames = new Sprite*[3];   //jump fierce

    Point jumpJabLowHit[] = {Point(0,0), Point(90,137), Point(-700,-700)};
    Point jumpJabLowHit1[] = {Point(97,70), Point(199,137), Point(-700,-700)};
    Point jumpJabLowHit2[] = {Point(203,0), Point(331,137), Point(-700,-700)};

    Point jumpJabHighHit1[] = {Point(117,0), Point(195,70), Point(-700,-700)};

    Point jumpJabHurt0[] = {Point(3,15), Point(95,70), Point(-700,-700)};
    Point jumpJabHurt1[] = {Point(135,0), Point(201,198), Point(-700,-700)};
    Point jumpJabHurt2[] = {Point(245,64), Point(328,137), Point(-700,-700)};

    jumpJabFrames[0] = new Sprite(Global::RobertRotorAnimations[jumpJab], Point(0,0), Point(90,137),
                                     Point(11,137), 0,jumpJabLowHit,jumpJabHurt0, 0);
    jumpJabFrames[1] = new Sprite(Global::RobertRotorAnimations[jumpJab], Point(97,0), Point(199,137),
                                     Point(112,137), jumpJabHighHit1,jumpJabHurt1,0, 0);
    jumpJabFrames[2] = new Sprite(Global::RobertRotorAnimations[jumpJab], Point(203,0), Point(331,137),
                                     Point(234,137), 0,jumpJabLowHit2,jumpJabHurt2, 0);

    Sprite** jumpKickFrames = new Sprite*[3];   //jump fierce

    Point jumpKickLowHit[] = {Point(0,0), Point(92,104), Point(-700,-700)};
    Point jumpKickLowHit1[] = {Point(101,55), Point(170,87), Point(-700,-700)};
    Point jumpKickLowHit2[] = {Point(227,0), Point(332,104), Point(-700,-700)};

    Point jumpKickHighHit1[] = {Point(97,0), Point(182,50), Point(-700,-700)};

    Point jumpKickHurt1[] = {Point(177,45), Point(226,104), Point(-700,-700)};
    jumpKickFrames[0] = new Sprite(Global::RobertRotorAnimations[jumpKick], Point(0,0), Point(92,104),
                                     Point(19,137), 0,jumpKickLowHit,0, 0);
    jumpKickFrames[1] = new Sprite(Global::RobertRotorAnimations[jumpKick], Point(95,0), Point(226,104),
                                     Point(120,137), jumpKickHighHit1,jumpKickHurt1,jumpKickHurt1, 0);
    jumpKickFrames[2] = new Sprite(Global::RobertRotorAnimations[jumpKick], Point(228,0), Point(322,104),
                                     Point(259,104), 0,jumpKickLowHit2,0, 0);

    Sprite** comboFierceFrames = new Sprite*[9];

    Point comboFierceHighHit[] = {Point(0,34), Point(88,67), Point(-700,-700)};
    Point comboFierceHighHit1[] = {Point(161,31), Point(236,71), Point(-700,-700)};
    Point comboFierceHighHit2[] = {Point(315,48), Point(372,86), Point(-700,-700)};
    Point comboFierceHighHit7[] = {Point(1100,31), Point(1170,81), Point(-700,-700)};
    Point comboFierceHighHit8[] = {Point(1238,30), Point(1297,82), Point(-700,-700)};

    Point comboFierceLowHit[] = {Point(0,67), Point(110,133), Point(-700,-700)};
    Point comboFierceLowHit1[] = {Point(114,71), Point(237,133), Point(-700,-700)};
    Point comboFierceLowHit2[] = {Point(237,86), Point(376,133), Point(-700,-700)};
    Point comboFierceLowHit3[] = {Point(389,42), Point(575,133), Point(-700,-700)};
    Point comboFierceLowHit4[] = {Point(573,42), Point(752,133), Point(-700,-700)};
    Point comboFierceLowHit5[] = {Point(762,50), Point(941,133), Point(-700,-700)};
    Point comboFierceLowHit6[] = {Point(944,45), Point(1075,133), Point(-700,-700)};
    Point comboFierceLowHit7[] = {Point(1076,81), Point(1208,133), Point(-700,-700)};
    Point comboFierceLowHit8[] = {Point(1209,82), Point(1325,133), Point(-700,-700)};

    Point comboFierceHurt[] = {Point(0,0), Point(89,40), Point(-700,-700)};
    Point comboFierceHurt1[] = {Point(139,0), Point(237,52), Point(-700,-700)};
    Point comboFierceHurt2[] = {Point(318,0), Point(390,63), Point(-700,-700)};
    Point comboFierceHurt3[] = {Point(525,63), Point(575,115), Point(-700,-700)};
    Point comboFierceHurt4[] = {Point(709,63), Point(755,118), Point(-700,-700)};
    Point comboFierceHurt5[] = {Point(893,66), Point(939,116), Point(-700,-700)};

    comboFierceFrames[0] = new Sprite(Global::RobertRotorAnimations[comboFierce], Point(0,0), Point(109,133),
                                      Point(14,133),comboFierceHighHit,comboFierceLowHit,comboFierceHurt, 0);
    comboFierceFrames[1] = new Sprite(Global::RobertRotorAnimations[comboFierce], Point(113,0), Point(237,133),
                                      Point(127,133),comboFierceHighHit1,comboFierceLowHit1,comboFierceHurt1, 0);
    comboFierceFrames[2] = new Sprite(Global::RobertRotorAnimations[comboFierce], Point(237,0), Point(388,133),
                                      Point(251,133),comboFierceHighHit2,comboFierceLowHit2,comboFierceHurt2, 0);
    comboFierceFrames[3] = new Sprite(Global::RobertRotorAnimations[comboFierce], Point(384,48), Point(570,133),
                                      Point(397,133),0,comboFierceLowHit3,comboFierceHurt3, 0);
    comboFierceFrames[4] = new Sprite(Global::RobertRotorAnimations[comboFierce], Point(569,51), Point(757,133),
                                      Point(583,133),0,comboFierceLowHit4,comboFierceHurt4, 0);
    comboFierceFrames[5] = new Sprite(Global::RobertRotorAnimations[comboFierce], Point(758,49), Point(942,133),
                                      Point(770,133),0,comboFierceLowHit5,comboFierceHurt5, 0);
    comboFierceFrames[6] = new Sprite(Global::RobertRotorAnimations[comboFierce], Point(943,48), Point(1079,133),
                                      Point(955,133),0,comboFierceLowHit6,0, 0);
    comboFierceFrames[7] = new Sprite(Global::RobertRotorAnimations[comboFierce], Point(1078,29), Point(1202,133),
                                      Point(1092,133),comboFierceHighHit7,comboFierceLowHit7,0, 0);
    comboFierceFrames[8] = new Sprite(Global::RobertRotorAnimations[comboFierce], Point(1202,26), Point(1325,133),
                                      Point(1217,133),comboFierceHighHit8,comboFierceLowHit8,0, 0);


    Sprite** comboChainFrames = new Sprite*[16];

    Point comboChainHighHit[] = {Point(0,20), Point(99,87), Point(-700,-700)};
    Point comboChainHighHit1[] = {Point(134,18), Point(257,88), Point(-700,-700)};
    Point comboChainHighHit2[] = {Point(272,18), Point(381,86), Point(-700,-700)};
    Point comboChainHighHit3[] = {Point(405,21), Point(494,86), Point(-700,-700)};
    Point comboChainHighHit4[] = {Point(502,21), Point(594,86), Point(-700,-700)};
    Point comboChainHighHit5[] = {Point(612,16), Point(703,86), Point(-700,-700)};
    Point comboChainHighHit6[] = {Point(712,0), Point(822,76), Point(-700,-700)};
    Point comboChainHighHit7[] = {Point(823,0), Point(943,76), Point(-700,-700)};
    Point comboChainHighHit8[] = {Point(943,0), Point(1049,75), Point(-700,-700)};
    Point comboChainHighHit9[] = {Point(1050,0), Point(1164,76), Point(-700,-700)};
    Point comboChainHighHit10[] = {Point(1164,0), Point(1282,76), Point(-700,-700)};
    Point comboChainHighHit11[] = {Point(1282,0), Point(1397,76), Point(-700,-700)};


    Point comboChainLowHit[] = {Point(0,86), Point(89,148), Point(-700,-700)};
    Point comboChainLowHit1[] = {Point(106,86), Point(208,148), Point(-700,-700)};
    Point comboChainLowHit2[] = {Point(255,86), Point(356,148), Point(-700,-700)};
    Point comboChainLowHit3[] = {Point(384,86), Point(480,148), Point(-700,-700)};
    Point comboChainLowHit4[] = {Point(506,86), Point(590,148), Point(-700,-700)};
    Point comboChainLowHit5[] = {Point(590,86), Point(693,148), Point(-700,-700)};
    Point comboChainLowHit6[] = {Point(708,76), Point(806,148), Point(-700,-700)};
    Point comboChainLowHit7[] = {Point(820,76), Point(920,148), Point(-700,-700)};
    Point comboChainLowHit8[] = {Point(939,76), Point(1033,148), Point(-700,-700)};
    Point comboChainLowHit9[] = {Point(1047,76), Point(1145,148), Point(-700,-700)};
    Point comboChainLowHit10[] = {Point(1162,76), Point(1258,148), Point(-700,-700)};
    Point comboChainLowHit11[] = {Point(1274,76), Point(1373,148), Point(-700,-700)};
    Point comboChainLowHit12[] = {Point(1387,55), Point(1505,148), Point(-700,-700)};
    Point comboChainLowHit13[] = {Point(1505,55), Point(1623,148), Point(-700,-700)};
    Point comboChainLowHit14[] = {Point(1623,55), Point(1782,148), Point(-700,-700)};
    Point comboChainLowHit15[] = {Point(1784,55), Point(1877,148), Point(-700,-700)};

    Point comboChainHurt1[] = {Point(205,28), Point(253,85), Point(-700,-700)};
    Point comboChainHurt2[] = {Point(322,28), Point(382,77), Point(-700,-700)};
    Point comboChainHurt3[] = {Point(472,46), Point(488,89), Point(-700,-700)};
    Point comboChainHurt4[] = {Point(503,44), Point(578,90), Point(-700,-700)};
    Point comboChainHurt5[] = {Point(676,43), Point(705,88), Point(-700,-700)};
    Point comboChainHurt6[] = {Point(770,0), Point(817,49), Point(-700,-700)};
    Point comboChainHurt7[] = {Point(888,0), Point(933,52), Point(-700,-700)};
    Point comboChainHurt8[] = {Point(1000,0), Point(1044,45), Point(-700,-700)};
    Point comboChainHurt9[] = {Point(1109,0), Point(1160,48), Point(-700,-700)};
    Point comboChainHurt10[] = {Point(1224,0), Point(1280,47), Point(-700,-700)};
    Point comboChainHurt11[] = {Point(1343,0), Point(1394,50), Point(-700,-700)};
    Point comboChainHurt12[] = {Point(1464,0), Point(1506,77), Point(-700,-700)};

    comboChainFrames[0] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(2,19), Point(105,148),
                                      Point(7,141),comboChainHighHit,comboChainLowHit,0, 0);
    comboChainFrames[1] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(105,19), Point(260,148),
                                      Point(127,148),comboChainHighHit1,comboChainLowHit1,comboChainHurt1, 0);
    comboChainFrames[2] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(257,22), Point(388,148),
                                      Point(273,148),comboChainHighHit2,comboChainLowHit2,comboChainHurt2, 0);
    comboChainFrames[3] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(385,21), Point(497,133),
                                      Point(399,148),comboChainHighHit3,comboChainLowHit3,comboChainHurt3, 0);
    comboChainFrames[4] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(495,24), Point(595,148),
                                      Point(520,148),comboChainHighHit4,comboChainLowHit4,comboChainHurt4, 0);
    comboChainFrames[5] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(598,20), Point(708,148),
                                      Point(611,148),comboChainHighHit5,comboChainLowHit5,comboChainHurt5, 0);
    comboChainFrames[6] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(710,0), Point(825,148),
                                      Point(723,148),comboChainHighHit6,comboChainLowHit6,comboChainHurt6, 0);
    comboChainFrames[7] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(823,0), Point(940,148),
                                      Point(842,148),comboChainHighHit7,comboChainLowHit7,comboChainHurt7, 0);
    comboChainFrames[8] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(930,0), Point(1051,148),
                                      Point(954,148),comboChainHighHit8,comboChainLowHit8,comboChainHurt8, 0);
    comboChainFrames[9] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(1046,0), Point(1164,148),
                                      Point(1068,148),comboChainHighHit9,comboChainLowHit9,comboChainHurt9, 0);
    comboChainFrames[10] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(1164,0), Point(1278,148),
                                      Point(1177,148),comboChainHighHit10,comboChainLowHit10,comboChainHurt10, 0);
    comboChainFrames[11] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(1278,0), Point(1396,148),
                                      Point(1290,148),comboChainHighHit11,comboChainLowHit11,comboChainHurt11, 0);
    comboChainFrames[12] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(1396,0), Point(1513,148),
                                      Point(1423,148),0,comboChainLowHit12,comboChainHurt12, 0);
    comboChainFrames[13] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(1505,47), Point(1617,148),
                                      Point(1539,148),0,comboChainLowHit13,0, 0);
    comboChainFrames[14] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(1618,47), Point(1779,148),
                                      Point(1698,148),0,comboChainLowHit14,0, 0);
    comboChainFrames[15] = new Sprite(Global::RobertRotorAnimations[comboChain], Point(1779,60), Point(1877,148),
                                      Point(1797,148),0,comboChainLowHit15,0, 0);

    Sprite** knockDownFrames = new Sprite*[7];

    knockDownFrames[0] = new Sprite(Global::RobertRotorAnimations[knockDown], Point(0,0), Point(90,138),
                              Point(37,138),0,0,0, 0);
    knockDownFrames[1] = new Sprite(Global::RobertRotorAnimations[knockDown], Point(98,0), Point(206,138),
                              Point(164,138),0,0,0, 0);
    knockDownFrames[2] = new Sprite(Global::RobertRotorAnimations[knockDown], Point(214,0), Point(352,138),
                              Point(314,138),0,0,0, 0);
    knockDownFrames[3] = new Sprite(Global::RobertRotorAnimations[knockDown], Point(357,0), Point(531,138),
                              Point(500,138),0,0,0, 0);
    knockDownFrames[4] = new Sprite(Global::RobertRotorAnimations[knockDown], Point(539,0), Point(715,138),
                              Point(702,138),0,0,0, 0);
    knockDownFrames[5] = new Sprite(Global::RobertRotorAnimations[knockDown], Point(723,0), Point(860,138),
                              Point(809,138),0,0,0, 0);
    knockDownFrames[6] = new Sprite(Global::RobertRotorAnimations[knockDown], Point(539,0), Point(715,138),
                              Point(702,138),0,0,0, 0);


    Sprite** victoryFrames = new Sprite*[8];

    victoryFrames[0] = new Sprite(Global::RobertRotorAnimations[victory], Point(0,0), Point(107,129),
                              Point(21,129),0,0,0, 0);
    victoryFrames[1] = new Sprite(Global::RobertRotorAnimations[victory], Point(115,0), Point(224,129),
                              Point(133,129),0,0,0, 0);
    victoryFrames[2] = new Sprite(Global::RobertRotorAnimations[victory], Point(229,0), Point(354,129),
                              Point(248,129),0,0,0, 0);
    victoryFrames[3] = new Sprite(Global::RobertRotorAnimations[victory], Point(361,0), Point(490,129),
                              Point(382,129),0,0,0, 0);
    victoryFrames[4] = new Sprite(Global::RobertRotorAnimations[victory], Point(497,0), Point(618,129),
                              Point(520,129),0,0,0, 0);
    victoryFrames[5] = new Sprite(Global::RobertRotorAnimations[victory], Point(625,0), Point(746,129),
                              Point(647,129),0,0,0, 0);
    victoryFrames[6] = new Sprite(Global::RobertRotorAnimations[victory], Point(753,0), Point(881,129),
                              Point(773,129),0,0,0, 0);
    victoryFrames[7] = new Sprite(Global::RobertRotorAnimations[victory], Point(887,0), Point(1016,129),
                              Point(909,129),0,0,0, 0);



    allAnimations = new Sprite**[numElements];
    allAnimations[stance] = stanceFrames;
    allAnimations[crouch] = crouchFrames;
    allAnimations[guard] = guardFrames;
    allAnimations[crouchGuard] = crouchGuardFrames;
    allAnimations[jump] = jumpFrames;
    allAnimations[crouchJab] = crouchJabFrames;
    allAnimations[shortKick] = shortKickFrames;
    allAnimations[strongJab] = strongJabFrames;
    allAnimations[walkForward] = walkForwardFrames;
    allAnimations[walkBackward] = walkBackwardFrames;
    allAnimations[crouchKick] = crouchKickFrames;
    allAnimations[crouchTurn] = crouchTurnFrames;
    allAnimations[jumpJab] = jumpJabFrames;
    allAnimations[jumpKick] = jumpKickFrames;
    allAnimations[comboFierce] = comboFierceFrames;
    allAnimations[comboChain] = comboChainFrames;
    allAnimations[getHitCrouch] = getHitCrouchFrames;
    allAnimations[getHitStandingHigh] = getHitStandingHighFrames;
    allAnimations[getHitStandingLow] = getHitStandingLowFrames;
    allAnimations[knockDown] = knockDownFrames;
    allAnimations[victory] = victoryFrames;

    currentAnimation = -1;
    currentAnimationInd = -1;
    Stance();
}

RobertRotor::~RobertRotor()
{
    delete [] allAnimations;
}


void RobertRotor::RecieveInput(Uint32 type, int key)
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
                ComboChain();
                cCombo = -1;
            }
            if(negativeFrames == 0 && ifAcceptingInput)
            {
                if(state == sNormal)
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
                else if (state == sJumping)
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
                else if(state == sCrouching)
                {
                    CrouckKick();
                }
                else if (state == sJumping)
                {
                    JumpKick();
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
            break;
        }
    }
}

Projectile* RobertRotor::UpdateSprite()
{
    oldPosition = position;
    Projectile* tempP = 0;
    if(cCombo > -1)
    {
        cCombo--;
    }
    if(cCombo == 0)
    {
        ComboFierce();
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
        if(currentAnimation == victory || currentAnimation == knockDown)
        {
            currentAnimationInd--;
            return 0;
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
                    if(currentAnimation == walkBackward)
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
//    if(currentAnimation == jumpKick)
//    {
//        yVelocity = 0;
//        position.x += 3;
//        position.y += 3;
//    }
//    if(currentAnimation == crouchKick && currentAnimationInd < 75)
//    {
//        position.x += 1;
//    }

    if(currentAnimation == walkForward)
    {
        this->position.x += ((currentAnimationInd % spread) == 0 && currentAnimationInd > 0
                             && (2 <= (currentAnimationInd / spread)
                                 && (currentAnimationInd / spread) <= 4)) * 40
                              * (a[orientation])/* */;
    }
    else if(currentAnimation == walkBackward)
    {
        this->position.x -= (((currentAnimationInd % spread) == 0) /*&& (currentAnimationInd > 0)*/
                             && (((currentAnimationInd / spread) >= 4 && currentAnimationInd/spread <= 6)))
                             * 40 * (a[orientation])/* */;
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
//    if(currentAnimation == comboFierce && currentAnimationInd < (spread*(currentAnimationCap - 2)))
//    {
//        position.x += 1;
//    }
//    if(currentAnimation == shortKick && currentAnimationInd < spread * 3)
//    {
////        cout << "called " << endl;
//        position.x += 2;
//    }
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
        if(state == sJumping && yVelocity >= 0 || currentAnimation == jumpKick)
        {
            if(currentAnimation == jumpKick)
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
//    cout << currentAnimation << " " << currentAnimationCap << " " << currentAnimationInd << endl;
    return tempP;
}

void RobertRotor::Render(SDL_Renderer* gRenderer)
{
    nextSprite->Render(gRenderer);
    healthBar->renderBar(gRenderer);
    superBar->renderBar(gRenderer);
//    SDL_SetRenderDrawColor(gRenderer, 0, 255 ,0 ,0);
//    SDL_RenderDrawPoint(gRenderer, position.x, position.y);
}


void RobertRotor::Turn()
{
    countToTurn = 1;
}

void RobertRotor::CrouchTurn()
{
    currentAnimation = crouchTurn;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    countToTurn = negativeFrames;
}

void RobertRotor::CrouckKick()
{
    hasDamaged = false;
    damage = 5;
        currentAnimation = crouchKick;
    currentAnimationCap = 6;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void RobertRotor::Jump()  //GLITH IN SOME SPRITE
{
    currentAnimation = jump;
    spread = 8 * Global::dF;
    currentAnimationInd = spread - 1;
    currentAnimationCap = 11;
    yVelocity = -7 * Global::dF;
    negativeFrames = 0;
}

void RobertRotor::JumpFromStand()
{
    currentAnimation = jump;
    spread = 8 * Global::dF;
    currentAnimationInd = 2 * spread - 1;
    currentAnimationCap = 9;
    yVelocity = -7 * Global::dF;
    negativeFrames = 0;
}

void RobertRotor::Jumping()
{
    currentAnimation = jump;
    currentAnimationCap = 10;
    spread = 1;
    currentAnimationInd = 9;
    negativeFrames = 0;
}

void RobertRotor::Stance()
{
    currentAnimationInd = -1;
    currentAnimation = stance;
    currentAnimationCap = 4;
    spread = 8 * Global::dF;
    negativeFrames = 0;
}

void RobertRotor::Guarding()
{
    currentAnimation = guard;
    currentAnimationCap = 1;
    spread = 1;
    currentAnimationInd = 0;
    negativeFrames = 0;
}

void RobertRotor::CrouchGuarding()
{
    currentAnimation = crouchGuard;
    currentAnimationCap = 1;
    spread = 1;
    currentAnimationInd = 0;
    negativeFrames = 0;
}

void RobertRotor::WalkForward()
{
    currentAnimation = walkForward;
    currentAnimationInd = -1;
    currentAnimationCap = 8;
    spread = 8 * Global::dF;
    negativeFrames = 0;
}

void RobertRotor::WalkBackward(bool justIn)
{
    currentAnimation = walkBackward;
    if(justIn)
    {
        currentAnimationInd = 3;
    }
    else
    {
        currentAnimationInd = -1;
    }
    currentAnimationCap = 8;
    spread = 8 * Global::dF;
    negativeFrames = 0;
}

void RobertRotor::Crouching()
{
    currentAnimation = crouch;
    currentAnimationCap = 2;
    spread = 1;
    currentAnimationInd = 1;
    negativeFrames = 0;
}

void RobertRotor::Crouch()
{
    currentAnimation = crouch;
    currentAnimationCap = 2;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void RobertRotor::StrongJab()
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = strongJab;
    currentAnimationInd = -1;
    currentAnimationCap = 6;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void RobertRotor::CrouchLightJab()
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = crouchJab;
    currentAnimationInd = -1;
    currentAnimationCap = 4;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void RobertRotor::ShortKick()
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = shortKick;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void RobertRotor::JumpJab()  // VERY FAST
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = jumpJab;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void RobertRotor::JumpKick()   //Fast
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = jumpKick;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void RobertRotor::ComboFierce()  //with 'c'
{
    super = 0;
        hasDamaged = false;
    damage = 25;
    currentAnimation = comboFierce;
    spread = 8 * Global::dF;
    currentAnimationInd = - 1;
    currentAnimationCap = 9;
    negativeFrames = spread * currentAnimationCap;
}

void RobertRotor::ComboChain()  //with 'x'
{
    superBar->emptyBar();
    hasDamaged = false;
    damage = 45;
        currentAnimation = comboChain;
    spread = 40 * Global::dF;
    currentAnimationInd = - 1;
    currentAnimationCap = 16;
    negativeFrames = spread * currentAnimationCap;
}


void RobertRotor::GetHitCrouch(int power)
{
    currentAnimation = getHitCrouch;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void RobertRotor::GetHitStandingHigh(int power)
{
    currentAnimation = getHitStandingHigh;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void RobertRotor::GetHitStandingLow(int power)
{
    currentAnimation = getHitStandingLow;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void RobertRotor::KnockDown()
{
    currentAnimation = knockDown;
    currentAnimationCap = 7;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void RobertRotor::Victory()
{
    currentAnimation = victory;
    currentAnimationCap = 8;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

bool RobertRotor::HandleHit(int hitType, int damage, int frames)
{
    if(cHultHult == hitType || hitType == cLowLow || hitType == cHighHigh
       || cHighLow == hitType || hitType == cLowHigh)
    {
        PushBack(2);
        return false;
    }
    if(cHultHigh == hitType)
    {
        if(currentAnimation == guard)
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
        if(currentAnimation == crouchGuard)
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


