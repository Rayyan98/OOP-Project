#include "TrivediBabu.h"
#include "Arena.h"
#include "Hadouken.h"

enum{projectileHadouken, projectileFire, projectileFire1};

enum{stanceT, crouchT, guardT, crouchGuardT, jumpT, crouchJabT, shortKickT,
     strongJabT, walkForwardT, walkBackwardT, crouchKickT, crouchTurnT, combo1T,jumpJabT,jumpKickT,crouchKick1T,combo2T,
     getHitCrouchT, getHitStandingHighT,
     getHitStandingLowT, hCreationT, hDestructionT,knockDownT, victoryT,numElementsT};

 enum{crouchKick1LeftT, crouchKick1RightT};

 enum{cNone, cHultHult, cHultHigh, cHultLow,
            cHighHult, cHighHigh, cHighLow,
            cLowHult , cLowHigh , cLowLow};

TrivediBabu::TrivediBabu()
{

}


TrivediBabu::TrivediBabu(Point position1, bool orientation, bool player2) : Character(position1, orientation, player2)
{
    cCombo = -1;
    crouchKick1Status = -1;
//    cout << position.x << position.y << endl;
Sprite** stanceFrames = new Sprite*[6];
Point stanceHighHit[] = {Point(9,15), Point(61,50), Point(-700,-700)};
Point stanceHighHit1[] = {Point(81,15), Point(137,50), Point(-700,-700)};
Point stanceHighHit2[] = {Point(156,15), Point(210,50), Point(-700,-700)};
Point stanceHighHit3[] = {Point(228,15), Point(282,50), Point(-700,-700)};
Point stanceHighHit4[] = {Point(300,15), Point(356,50), Point(-700,-700)};
Point stanceHighHit5[] = {Point(375,15), Point(431,50), Point(-700,-700)};

Point stanceLowHit[] = {Point(9,50), Point(61,98), Point(-700,-700)};
Point stanceLowHit1[] = {Point(81,50), Point(137,98), Point(-700,-700)};
Point stanceLowHit2[] = {Point(156,50), Point(210,98), Point(-700,-700)};
Point stanceLowHit3[] = {Point(228,50), Point(282,98), Point(-700,-700)};
Point stanceLowHit4[] = {Point(300,50), Point(356,98), Point(-700,-700)};
Point stanceLowHit5[] = {Point(375,50), Point(431,98), Point(-700,-700)};

stanceFrames[0] = new Sprite(Global::TrivediBabuAnimations[stanceT], Point(0,0), Point(66,98),
                             Point(8, 98), stanceHighHit, stanceLowHit, 0, 0);
stanceFrames[1] = new Sprite(Global::TrivediBabuAnimations[stanceT], Point(74, 0), Point(140, 98),
                             Point(83, 98), stanceHighHit1, stanceLowHit1, 0, 0);
stanceFrames[2] = new Sprite(Global::TrivediBabuAnimations[stanceT], Point(146, 0), Point(213, 98),
                             Point(157, 98), stanceHighHit2, stanceLowHit2, 0, 0);
stanceFrames[3] = new Sprite(Global::TrivediBabuAnimations[stanceT], Point(220,0), Point(286, 98),
                             Point(230, 98), stanceHighHit3, stanceLowHit3, 0, 0);
stanceFrames[4] = new Sprite(Global::TrivediBabuAnimations[stanceT], Point(295, 0), Point(360, 98),
                             Point(303, 98), stanceHighHit4, stanceLowHit4, 0, 0);
stanceFrames[5] = new Sprite(Global::TrivediBabuAnimations[stanceT], Point(370, 0), Point(443, 98),
                             Point(377, 98), stanceHighHit5, stanceLowHit5, 0, 0);


Sprite** crouchFrames = new Sprite*[2];
Point crouchLowHit[] = {Point(74,17), Point(133,89), Point(-700,-700)};
Point crouchLowHit1[] = {Point(145,26), Point(202,89), Point(-700,-700)};

crouchFrames[0] = new Sprite(Global::TrivediBabuAnimations[crouchT], Point(70, 0), Point(133,89),
                         Point(81, 89),0,crouchLowHit,0, 0);
crouchFrames[1] = new Sprite(Global::TrivediBabuAnimations[crouchT], Point(141, 0), Point(202, 89),
                         Point(152, 94),0 ,crouchLowHit1,0, 0);


Sprite** guardFrames = new Sprite*[1];
Point guardHighHit[] = {Point(0,0), Point(60,45), Point(-700,-700)};

Point guardLowHit[] = {Point(0,45), Point(65,92), Point(-700,-700)};

guardFrames[0] = new Sprite(Global::TrivediBabuAnimations[guardT], Point(0,0), Point(65,92),
                            Point(10, 92),guardHighHit,guardLowHit,0, 0);


Sprite** crouchGuardFrames = new Sprite*[1];
Point crouchGuardLowHit[] = {Point(0,0), Point(64,64), Point(-700,-700)};

crouchGuardFrames[0] = new Sprite(Global::TrivediBabuAnimations[crouchGuardT], Point(0,0), Point(64,64),
                                  Point(13,64),0,crouchGuardLowHit,0, 0);


Sprite** jumpFrames = new Sprite*[4];
Point jumpHighHit[] = {Point(0,0), Point(64,43), Point(-700,-700)};
Point jumpHighHit1[] = {Point(72,18), Point(133,56), Point(-700,-700)};
Point jumpHighHit2[] = {Point(141,22), Point(203,88), Point(-700,-700)};
Point jumpHighHit3[] = {Point(211,2), Point(274,49), Point(-700,-700)};

Point jumpLowHit[] = {Point(0,43), Point(58,88), Point(-700,-700)};
Point jumpLowHit1[] = {Point(72,56), Point(122,88), Point(-700,-700)};
Point jumpLowHit3[] = {Point(216,49), Point(258,88), Point(-700,-700)};

jumpFrames[0] = new Sprite(Global::TrivediBabuAnimations[jumpT], Point(0,0), Point(64,88),
                           Point(15,88),jumpHighHit,jumpLowHit,0, 0);
jumpFrames[1] = new Sprite(Global::TrivediBabuAnimations[jumpT], Point(71,0), Point(274,88),
                           Point(80,88),jumpHighHit1,jumpLowHit1,0, 0);
jumpFrames[2] = new Sprite(Global::TrivediBabuAnimations[jumpT], Point(141,0), Point(202,88),
                           Point(154,88),jumpHighHit2,0,0, 0);
jumpFrames[3] = new Sprite(Global::TrivediBabuAnimations[jumpT], Point(209,0), Point(274,88),
                           Point(231,88),jumpHighHit3,jumpLowHit3,0, 0);


Sprite** crouchJabFrames = new Sprite*[4];

Point crouchJabLowHit[] = {Point(0,0), Point(62,66), Point(-700,-700)};
Point crouchJabLowHit1[] = {Point(70,0), Point(134,66), Point(-700,-700)};
Point crouchJabLowHit2[] = {Point(142,0), Point(208,66), Point(-700,-700)};
Point crouchJabLowHit3[] = {Point(251,0), Point(315,66), Point(-700,-700)};

Point crouchJabHurt[] = {Point(10,18), Point(23,28), Point(-700,-700)};
Point crouchJabHurt1[] = {Point(99,15), Point(111,24), Point(-700,-700)};
Point crouchJabHurt2[] = {Point(230,11), Point(243,20), Point(-700,-700)};
Point crouchJabHurt3[] = {Point(278,16), Point(292,24), Point(-700,-700)};

crouchJabFrames[0] = new Sprite(Global::TrivediBabuAnimations[crouchJabT], Point(0,0), Point(62,66),
                           Point(10,66),0,crouchJabLowHit,crouchJabHurt, 0);
crouchJabFrames[1] = new Sprite(Global::TrivediBabuAnimations[crouchJabT], Point(70,0), Point(134,66),
                           Point(80,66),0,crouchJabLowHit1,crouchJabHurt1, 0);
crouchJabFrames[2] = new Sprite(Global::TrivediBabuAnimations[crouchJabT], Point(142,0), Point(243,66),
                           Point(154,66),0,crouchJabLowHit2,crouchJabHurt2, 0);
crouchJabFrames[3] = new Sprite(Global::TrivediBabuAnimations[crouchJabT], Point(251,0), Point(315,66),
                           Point(261,66),0,crouchJabLowHit3,crouchJabHurt3, 0);


Sprite** shortKickFrames = new Sprite*[6];
Point KickHighHit[] = {Point(22,20), Point(59,47), Point(-700,-700)};
Point KickHighHit1[] = {Point(99,23), Point(135,47), Point(-700,-700)};
Point KickHighHit2[] = {Point(173,21), Point(209,47), Point(-700,-700)};
Point KickHighHit3[] = {Point(269,23), Point(309,49), Point(-700,-700)};
Point KickHighHit4[] = {Point(354,21), Point(397,50), Point(-700,-700)};
Point KickHighHit5[] = {Point(427,19), Point(482,50), Point(-700,-700)};

Point KickLowHit[] = {Point(30,47), Point(61,101), Point(-700,-700)};
Point KickLowHit1[] = {Point(104,47), Point(140,101), Point(-700,-700)};
Point KickLowHit2[] = {Point(177,47), Point(220,101), Point(-700,-700)};
Point KickLowHit3[] = {Point(276,49), Point(322,101), Point(-700,-700)};
Point KickLowHit4[] = {Point(354,50), Point(404,101), Point(-700,-700)};
Point KickLowHit5[] = {Point(428,50), Point(487,101), Point(-700,-700)};

Point KickHurt[] = {Point(0,54), Point(26,66), Point(-700,-700)};
Point KickHurt1[] = {Point(92,58), Point(108,71), Point(-700,-700)};
Point KickHurt2[] = {Point(240,73), Point(259,86), Point(-700,-700)};
Point KickHurt3[] = {Point(302,83), Point(318,100), Point(-700,-700)};
Point KickHurt4[] = {Point(330,88), Point(346,101), Point(-700,-700)};
Point KickHurt5[] = {Point(422,91), Point(441,101), Point(-700,-700)};


shortKickFrames[0] = new Sprite(Global::TrivediBabuAnimations[shortKickT], Point(0,0), Point(83,101),
                                    Point(14,101), KickHighHit,KickLowHit,KickHurt, 0);
shortKickFrames[1] = new Sprite(Global::TrivediBabuAnimations[shortKickT], Point(91,0), Point(150, 101),
                                    Point(98, 101),KickHighHit1,KickLowHit1,KickHurt1, 0);
shortKickFrames[2] = new Sprite(Global::TrivediBabuAnimations[shortKickT], Point(158,0), Point(260, 101),
                                    Point(176,101),KickHighHit2,KickLowHit2,KickHurt2, 0);
shortKickFrames[3] = new Sprite(Global::TrivediBabuAnimations[shortKickT], Point(267,0), Point(323, 101),
                                    Point(276,101),KickHighHit3,KickLowHit3,KickHurt3, 0);
shortKickFrames[4] = new Sprite(Global::TrivediBabuAnimations[shortKickT], Point(330,0), Point(413,101),
                                    Point(340,101),KickHighHit4,KickLowHit4,KickHurt4, 0);
shortKickFrames[5] = new Sprite(Global::TrivediBabuAnimations[shortKickT], Point(421,0), Point(487,101),
                                    Point(429,101),KickHighHit5,KickLowHit5,KickHurt5, 0);


Sprite** strongJabFrames = new Sprite*[6];
Point JabHurt[] = {Point(29,46), Point(39,57), Point(-700,-700)};
Point JabHurt1[] = {Point(154,35), Point(167,48), Point(-700,-700)};
Point JabHurt2[] = {Point(230,0), Point(246,8), Point(-700,-700)};
Point JabHurt3[] = {Point(329,36), Point(342,47), Point(-700,-700)};
Point JabHurt4[] = {Point(400,49), Point(413,58), Point(-700,-700)};
Point JabHurt5[] = {Point(468,47), Point(480,56), Point(-700,-700)};

Point JabHighHit[] = {Point(17,23), Point(76,65), Point(-700,-700)};
Point JabHighHit1[] = {Point(102,19), Point(148,63), Point(-700,-700)};
Point JabHighHit2[] = {Point(200,20), Point(235,62), Point(-700,-700)};
Point JabHighHit3[] = {Point(280,22), Point(325,59), Point(-700,-700)};
Point JabHighHit4[] = {Point(360,20), Point(413,65), Point(-700,-700)};
Point JabHighHit5[] = {Point(433,20), Point(487,63), Point(-700,-700)};

Point JabLowHit[] = {Point(16,65), Point(23,112), Point(-700,-700)};
Point JabLowHit1[] = {Point(107,63), Point(148,112), Point(-700,-700)};
Point JabLowHit2[] = {Point(203,62), Point(238,112), Point(-700,-700)};
Point JabLowHit3[] = {Point(284,59), Point(323,112), Point(-700,-700)};
Point JabLowHit4[] = {Point(359,65), Point(416,112), Point(-700,-700)};
Point JabLowHit5[] = {Point(433,63), Point(490,112), Point(-700,-700)};


strongJabFrames[0] = new Sprite(Global::TrivediBabuAnimations[strongJabT], Point(0,0), Point(76,112),
                                    Point(17,112),JabHighHit,JabLowHit,JabHurt, 0);
strongJabFrames[1] = new Sprite(Global::TrivediBabuAnimations[strongJabT], Point(84,0), Point(168,112),
                                    Point(96,112),JabHighHit1,JabLowHit1,JabHurt1, 0);
strongJabFrames[2] = new Sprite(Global::TrivediBabuAnimations[strongJabT], Point(176,0), Point(251,112),
                                    Point(187,112),JabHighHit2,JabLowHit2,JabHurt2, 0);
strongJabFrames[3] = new Sprite(Global::TrivediBabuAnimations[strongJabT], Point(258,0), Point(342,112),
                                    Point(270,112),JabHighHit3,JabLowHit3,JabHurt3, 0);
strongJabFrames[4] = new Sprite(Global::TrivediBabuAnimations[strongJabT], Point(351,0), Point(417,112),
                                    Point(360,112),0,0,0, 0);
strongJabFrames[5] = new Sprite(Global::TrivediBabuAnimations[strongJabT], Point(424,0), Point(490,112),
                                    Point(433,112),0,0,0, 0);

Sprite** combo1Frames = new Sprite*[13];
Point combo1Hurt[] = {Point(40,99), Point(53,107), Point(-700,-700)};
Point combo1Hurt1[] = {Point(131,85), Point(144,95), Point(-700,-700)};
Point combo1Hurt2[] = {Point(205,84), Point(217,95), Point(-700,-700)};
Point combo1Hurt3[] = {Point(290,58), Point(304,79), Point(-700,-700)};
Point combo1Hurt4[] = {Point(376,59), Point(389,83), Point(-700,-700)};
Point combo1Hurt5[] = {Point(427,1), Point(458,36), Point(-700,-700)};
Point combo1Hurt6[] = {Point(500,0), Point(529,31), Point(-700,-700)};
Point combo1Hurt7[] = {Point(556,12), Point(593,40), Point(-700,-700)};
Point combo1Hurt8[] = {Point(618,6), Point(657,44), Point(-700,-700)};
Point combo1Hurt9[] = {Point(655,10), Point(685,36), Point(-700,-700)};
Point combo1Hurt10[] = {Point(734,9), Point(756,35), Point(-700,-700)};
Point combo1Hurt11[] = {Point(807,29), Point(825,45), Point(-700,-700)};
Point combo1Hurt12[] = {Point(879,30), Point(894,43), Point(-700,-700)};


Point combo1HighHit[] = {Point(0,0), Point(0,0), Point(-700,-700)};
Point combo1HighHit1[] = {Point(95,66), Point(141,106), Point(-700,-700)};
Point combo1HighHit2[] = {Point(165,67), Point(216,105), Point(-700,-700)};
Point combo1HighHit3[] = {Point(250,52), Point(288,88), Point(-700,-700)};
Point combo1HighHit4[] = {Point(334,52), Point(376,72), Point(-700,-700)};
Point combo1HighHit5[] = {Point(412,46), Point(454,63), Point(-700,-700)};
Point combo1HighHit6[] = {Point(483,45), Point(515,68), Point(-700,-700)};
Point combo1HighHit7[] = {Point(555,49), Point(589,75), Point(-700,-700)};
Point combo1HighHit8[] = {Point(620,48), Point(653,76), Point(-700,-700)};
Point combo1HighHit9[] = {Point(681,49), Point(715,80), Point(-700,-700)};
Point combo1HighHit10[] = {Point(751,50), Point(785,81), Point(-700,-700)};
Point combo1HighHit11[] = {Point(821,48), Point(864,81), Point(-700,-700)};
Point combo1HighHit12[] = {Point(887,50), Point(931,82), Point(-700,-700)};


Point combo1LowHit[] = {Point(14,70), Point(68,131), Point(-700,-700)};
Point combo1LowHit1[] = {Point(98,106), Point(140,131), Point(-700,-700)};
Point combo1LowHit2[] = {Point(174,105), Point(215,131), Point(-700,-700)};
Point combo1LowHit3[] = {Point(251,88), Point(284,131), Point(-700,-700)};
Point combo1LowHit4[] = {Point(334,72), Point(371,131), Point(-700,-700)};
Point combo1LowHit5[] = {Point(412,63), Point(461,131), Point(-700,-700)};
Point combo1LowHit6[] = {Point(487,68), Point(532,131), Point(-700,-700)};
Point combo1LowHit7[] = {Point(559,75), Point(591,131), Point(-700,-700)};
Point combo1LowHit8[] = {Point(622,76), Point(654,131), Point(-700,-700)};
Point combo1LowHit9[] = {Point(682,80), Point(727,131), Point(-700,-700)};
Point combo1LowHit10[] = {Point(751,81), Point(799,131), Point(-700,-700)};
Point combo1LowHit11[] = {Point(819,81), Point(867,131), Point(-700,-700)};
Point combo1LowHit12[] = {Point(887,82), Point(937,131), Point(-700,-700)};


combo1Frames[0] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(0,0), Point(69,131),
                                    Point(9,131),combo1HighHit,combo1LowHit,combo1Hurt, 0);
combo1Frames[1] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(76,0), Point(143,131),
                                    Point(88,131),combo1HighHit1,combo1LowHit1,combo1Hurt1, 0);
combo1Frames[2] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(151,0), Point(218,131),
                                    Point(163,131),combo1HighHit2,combo1LowHit2,combo1Hurt2, 0);
combo1Frames[3] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(226,0), Point(304,131),
                                    Point(237,131),combo1HighHit3,combo1LowHit3,combo1Hurt3, 0);
combo1Frames[4] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(312,0), Point(391,131),
                                    Point(322,131),combo1HighHit4,combo1LowHit4,combo1Hurt4, 0);
combo1Frames[5] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(398,0), Point(461,131),
                                    Point(421,131),combo1HighHit5,combo1LowHit5,combo1Hurt5, 0);
combo1Frames[6] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(469,0), Point(532,131),
                                    Point(493,131),combo1HighHit6,combo1LowHit6,combo1Hurt6, 0);
combo1Frames[7] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(539,0), Point(594,131),
                                    Point(576,131),combo1HighHit7,combo1LowHit7,combo1Hurt7, 0);
combo1Frames[8] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(602,0), Point(657,131),
                                    Point(637,131),combo1HighHit8,combo1LowHit8,combo1Hurt8, 0);
combo1Frames[9] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(665,0), Point(728,131),
                                    Point(692,131),combo1HighHit9,combo1LowHit9,combo1Hurt9, 0);
combo1Frames[10] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(735,0), Point(798,131),
                                    Point(763,131),combo1HighHit10,combo1LowHit10,combo1Hurt10, 0);
combo1Frames[11] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(805,0), Point(867,131),
                                    Point(818,131),combo1HighHit11,combo1LowHit11,combo1Hurt11, 0);
combo1Frames[12] = new Sprite(Global::TrivediBabuAnimations[combo1T], Point(875,0), Point(937,131),
                                    Point(890,131),combo1HighHit12,combo1LowHit12,combo1Hurt12, 0);


Sprite** jumpKickFrames = new Sprite*[5];
Point jumpKickHighHit[] = {Point(0,0), Point(64,64), Point(-700,-700)};
Point jumpKickHighHit1[] = {Point(72,0), Point(138,64), Point(-700,-700)};
Point jumpKickHighHit2[] = {Point(146,0), Point(215,64), Point(-700,-700)};
Point jumpKickHighHit3[] = {Point(279,0), Point(345,64), Point(-700,-700)};
Point jumpKickHighHit4[] = {Point(353,0), Point(417,64), Point(-700,-700)};

Point jumpKickHurt[] = {Point(37,47), Point(50,64), Point(-700,-700)};
Point jumpKickHurt1[] = {Point(122,40), Point(139,54), Point(-700,-700)};
Point jumpKickHurt2[] = {Point(248,50), Point(272,64), Point(-700,-700)};
Point jumpKickHurt3[] = {Point(330,41), Point(345,50), Point(-700,-700)};
Point jumpKickHurt4[] = {Point(392,45), Point(405,64), Point(-700,-700)};

jumpKickFrames[0] = new Sprite(Global::TrivediBabuAnimations[jumpKickT], Point(0,0), Point(64,64),
                                      Point(18,64),jumpKickHighHit,0,jumpKickHurt, 0);
jumpKickFrames[1] = new Sprite(Global::TrivediBabuAnimations[jumpKickT], Point(72,0), Point(138,64),
                                      Point(88,64),jumpKickHighHit1,0,jumpKickHurt1, 0);
jumpKickFrames[2] = new Sprite(Global::TrivediBabuAnimations[jumpKickT], Point(146,0), Point(271,64),
                                      Point(161,64),jumpKickHighHit2,0,jumpKickHurt2, 0);
jumpKickFrames[3] = new Sprite(Global::TrivediBabuAnimations[jumpKickT], Point(279,0), Point(345,64),
                                      Point(295,64),jumpKickHighHit3,0,jumpKickHurt3, 0);
jumpKickFrames[4] = new Sprite(Global::TrivediBabuAnimations[jumpKickT], Point(353,0), Point(417,64),
                                      Point(371,64),jumpKickHighHit4,0,jumpKickHurt4, 0);


Sprite** walkForwardFrames = new Sprite*[5];
Point walkForwardHighHit[] = {Point(78,12), Point(133,47), Point(-700,-700)};
Point walkForwardHighHit1[] = {Point(156,12), Point(209,46), Point(-700,-700)};
Point walkForwardHighHit2[] = {Point(225,12), Point(274,43), Point(-700,-700)};
Point walkForwardHighHit3[] = {Point(285,12), Point(338,48), Point(-700,-700)};
Point walkForwardHighHit4[] = {Point(347,12), Point(402,46), Point(-700,-700)};

Point walkForwardLowHit[] = {Point(87,47), Point(126,96), Point(-700,-700)};
Point walkForwardLowHit1[] = {Point(164,46), Point(203,96), Point(-700,-700)};
Point walkForwardLowHit2[] = {Point(230,43), Point(268,96), Point(-700,-700)};
Point walkForwardLowHit3[] = {Point(287,48), Point(330,96), Point(-700,-700)};
Point walkForwardLowHit4[] = {Point(347,46), Point(403,96), Point(-700,-700)};

walkForwardFrames[0] = new Sprite(Global::TrivediBabuAnimations[walkForwardT], Point(64,0), Point(133,96),
                                      Point(72,96),walkForwardHighHit,walkForwardLowHit,0, 0);
walkForwardFrames[1] = new Sprite(Global::TrivediBabuAnimations[walkForwardT], Point(142,0), Point(210,96),
                                      Point(151,96),walkForwardHighHit1,walkForwardLowHit1,0, 0);
walkForwardFrames[2] = new Sprite(Global::TrivediBabuAnimations[walkForwardT], Point(225,0), Point(277,96),
                                      Point(227,96),walkForwardHighHit2,walkForwardLowHit2,0, 0);
walkForwardFrames[3] = new Sprite(Global::TrivediBabuAnimations[walkForwardT], Point(285,0), Point(339,96),
                                      Point(296,96),walkForwardHighHit3,walkForwardLowHit3,0, 0);
walkForwardFrames[4] = new Sprite(Global::TrivediBabuAnimations[walkForwardT], Point(347,0), Point(403,96),
                                      Point(362,96),walkForwardHighHit4,walkForwardLowHit4,0, 0);


Sprite** walkBackwardFrames = new Sprite*[6];
Point walkBackwardHighHit[] = {Point(399,15), Point(452,52), Point(-700,-700)};
Point walkBackwardHighHit1[] = {Point(334,14), Point(389,44), Point(-700,-700)};
Point walkBackwardHighHit2[] = {Point(262,13), Point(317,43), Point(-700,-700)};
Point walkBackwardHighHit3[] = {Point(194,15), Point(248,46), Point(-700,-700)};
Point walkBackwardHighHit4[] = {Point(132,15), Point(186,47), Point(-700,-700)};
Point walkBackwardHighHit5[] = {Point(62,20), Point(117,47), Point(-700,-700)};

Point walkBackwardLowHit[] = {Point(396,52), Point(459,96), Point(-700,-700)};
Point walkBackwardLowHit1[] = {Point(326,44), Point(386,96), Point(-700,-700)};
Point walkBackwardLowHit2[] = {Point(256,43), Point(318,96), Point(-700,-700)};
Point walkBackwardLowHit3[] = {Point(198,46), Point(248,96), Point(-700,-700)};
Point walkBackwardLowHit4[] = {Point(140,47), Point(182,96), Point(-700,-700)};
Point walkBackwardLowHit5[] = {Point(68,47), Point(124,96), Point(-700,-700)};

walkBackwardFrames[5] = new Sprite(Global::TrivediBabuAnimations[walkBackwardT], Point(398,0), Point(459, 96),
                                       Point(406,96),walkBackwardHighHit,walkBackwardLowHit,0, 0);
walkBackwardFrames[4] = new Sprite(Global::TrivediBabuAnimations[walkBackwardT], Point(324,0), Point(389, 96),
                                       Point(334,96),walkBackwardHighHit1,walkBackwardLowHit1,0, 0);
walkBackwardFrames[3] = new Sprite(Global::TrivediBabuAnimations[walkBackwardT], Point(256,0), Point(317, 96),
                                       Point(266,96),walkBackwardHighHit2,walkBackwardLowHit2,0, 0);
walkBackwardFrames[2] = new Sprite(Global::TrivediBabuAnimations[walkBackwardT], Point(194,0), Point(249, 96),
                                       Point(206,96),walkBackwardHighHit3,walkBackwardLowHit3,0, 0);
walkBackwardFrames[1] = new Sprite(Global::TrivediBabuAnimations[walkBackwardT], Point(132,0), Point(187, 96),
                                       Point(150,96),walkBackwardHighHit4,walkBackwardHighHit4,0, 0);
walkBackwardFrames[0] = new Sprite(Global::TrivediBabuAnimations[walkBackwardT], Point(63,0), Point(124, 96),
                                       Point(84,96),walkBackwardHighHit5,walkBackwardLowHit5,0, 0);


Sprite** crouchKickFrames = new Sprite*[3];
Point crouchKickLowHit[] = {Point(0,0), Point(76,65), Point(-700,-700)};
Point crouchKickLowHit1[] = {Point(84,0), Point(150,65), Point(-700,-700)};
Point crouchKickLowHit2[] = {Point(201,0), Point(277,65), Point(-700,-700)};

Point crouchKickHurt[] = {Point(55,55), Point(77,65), Point(-700,-700)};
Point crouchKickHurt1[] = {Point(174,50), Point(193,65), Point(-700,-700)};
Point crouchKickHurt2[] = {Point(265,55), Point(277,65), Point(-700,-700)};

crouchKickFrames[0] = new Sprite(Global::TrivediBabuAnimations[crouchKickT], Point(0,0), Point(76, 65),
                                           Point(8,65),0,crouchKickLowHit,crouchKickHurt, 0);
crouchKickFrames[1] = new Sprite(Global::TrivediBabuAnimations[crouchKickT], Point(84,0), Point(193, 65),
                                           Point(95,65),0,crouchKickLowHit1,crouchKickHurt1, 0);
crouchKickFrames[2] = new Sprite(Global::TrivediBabuAnimations[crouchKickT], Point(201,0), Point(277, 65),
                                           Point(209,65),0,crouchKickLowHit2,crouchKickHurt2, 0);


Sprite** crouchKick1Frames = new Sprite*[9];
Point crouchKick1HighHit[] = {Point(0,20), Point(58,60), Point(-700,-700)};
Point crouchKick1HighHit1[] = {Point(80,7), Point(128,34), Point(-700,-700)};
Point crouchKick1HighHit2[] = {Point(186,11), Point(230,37), Point(-700,-700)};
Point crouchKick1HighHit3[] = {Point(300,12), Point(340,40), Point(-700,-700)};
Point crouchKick1HighHit4[] = {Point(363,18), Point(399,44), Point(-700,-700)};
Point crouchKick1HighHit5[] = {Point(436,11), Point(466,34), Point(-700,-700)};
Point crouchKick1HighHit6[] = {Point(495,13), Point(530,39), Point(-700,-700)};
Point crouchKick1HighHit7[] = {Point(560,16), Point(591,38), Point(-700,-700)};
Point crouchKick1HighHit8[] = {Point(611,17), Point(647,38), Point(-700,-700)};

Point crouchKick1LowHit[] = {Point(0,60), Point(48,99), Point(-700,-700)};
Point crouchKick1LowHit1[] = {Point(86,34), Point(171,99), Point(-700,-700)};
Point crouchKick1LowHit2[] = {Point(188,37), Point(235,99), Point(-700,-700)};
Point crouchKick1LowHit3[] = {Point(296,40), Point(330,99), Point(-700,-700)};
Point crouchKick1LowHit4[] = {Point(363,44), Point(392,99), Point(-700,-700)};
Point crouchKick1LowHit5[] = {Point(435,34), Point(472,99), Point(-700,-700)};
Point crouchKick1LowHit6[] = {Point(494,39), Point(537,99), Point(-700,-700)};
Point crouchKick1LowHit7[] = {Point(555,38), Point(590,99), Point(-700,-700)};
Point crouchKick1LowHit8[] = {Point(611,38), Point(661,99), Point(-700,-700)};

Point crouchKick1Hurt[] = {Point(6,81), Point(14,92), Point(-700,-700)};
Point crouchKick1Hurt1[] = {Point(152,42), Point(170,54), Point(-700,-700)};
Point crouchKick1Hurt2[] = {Point(216,42), Point(233,54), Point(-700,-700)};
Point crouchKick1Hurt3[] = {Point(243,39), Point(263,55), Point(-700,-700)};
Point crouchKick1Hurt4[] = {Point(348,38), Point(363,50), Point(-700,-700)};

crouchKick1Frames[0] = new Sprite(Global::TrivediBabuAnimations[crouchKick1T], Point(0,0), Point(60, 99),
                                           Point(31,99),crouchKick1HighHit,crouchKick1LowHit,crouchKick1Hurt, 0);
crouchKick1Frames[1] = new Sprite(Global::TrivediBabuAnimations[crouchKick1T], Point(68,0), Point(170, 99),
                                           Point(89,99),crouchKick1HighHit1,crouchKick1LowHit1,crouchKick1Hurt1, 0);
crouchKick1Frames[2] = new Sprite(Global::TrivediBabuAnimations[crouchKick1T], Point(178,0), Point(236, 99),
                                           Point(226,99),crouchKick1HighHit2,crouchKick1LowHit2,crouchKick1Hurt2, 0);
crouchKick1Frames[3] = new Sprite(Global::TrivediBabuAnimations[crouchKick1T], Point(244,0), Point(341, 99),
                                           Point(318,99),crouchKick1HighHit3,crouchKick1LowHit3,crouchKick1Hurt3, 0);
crouchKick1Frames[4] = new Sprite(Global::TrivediBabuAnimations[crouchKick1T], Point(347,0), Point(410, 99),
                                           Point(368,99),crouchKick1HighHit4,crouchKick1LowHit4,crouchKick1Hurt4, 0);
crouchKick1Frames[5] = new Sprite(Global::TrivediBabuAnimations[crouchKick1T], Point(417,0), Point(478, 99),
                                           Point(440,99),crouchKick1HighHit5,crouchKick1LowHit5,0, 0);
crouchKick1Frames[6] = new Sprite(Global::TrivediBabuAnimations[crouchKick1T], Point(484,0), Point(539, 99),
                                           Point(533,99),crouchKick1HighHit6,crouchKick1LowHit6,0, 0);
crouchKick1Frames[7] = new Sprite(Global::TrivediBabuAnimations[crouchKick1T], Point(547,0), Point(601, 99),
                                           Point(579,99),crouchKick1HighHit7,crouchKick1LowHit7,0, 0);
crouchKick1Frames[8] = new Sprite(Global::TrivediBabuAnimations[crouchKick1T], Point(609,0), Point(661, 99),
                                           Point(618,99),crouchKick1HighHit8,crouchKick1LowHit8,0, 0);


Sprite** jumpJabFrames = new Sprite*[3];
Point jumpJabHighHit[] = {Point(0,0), Point(55,73), Point(-700,-700)};
Point jumpJabHighHit1[] = {Point(63,0), Point(121,73), Point(-700,-700)};
Point jumpJabHighHit2[] = {Point(163,0), Point(218,73), Point(-700,-700)};

Point jumpJabHurt[] = {Point(42,19), Point(53,31), Point(-700,-700)};
Point jumpJabHurt1[] = {Point(141,32), Point(155,48), Point(-700,-700)};
Point jumpJabHurt2[] = {Point(206,21), Point(217,31), Point(-700,-700)};

jumpJabFrames[0] = new Sprite(Global::TrivediBabuAnimations[jumpJabT], Point(0,0), Point(55, 73),
                                           Point(16,73),jumpJabHighHit,0,jumpJabHurt, 0);
jumpJabFrames[1] = new Sprite(Global::TrivediBabuAnimations[jumpJabT], Point(63,0), Point(155, 73),
                                           Point(84,73),jumpJabHighHit1,0,jumpJabHurt1, 0);
jumpJabFrames[2] = new Sprite(Global::TrivediBabuAnimations[jumpJabT], Point(163,0), Point(218, 73),
                                           Point(181,73),jumpJabHighHit2,0,jumpJabHurt2, 0);


Sprite** crouchTurnFrames = new Sprite*[3];
crouchTurnFrames[0] = new Sprite(Global::TrivediBabuAnimations[crouchTurnT], Point(65,0), Point(133,73),
                                     Point(82,72), 0,0,0, 0);
crouchTurnFrames[1] = new Sprite(Global::TrivediBabuAnimations[crouchTurnT], Point(133,0), Point(203,73),
                                     Point(161,72), 0,0,0, 0);
crouchTurnFrames[2] = new Sprite(Global::TrivediBabuAnimations[crouchTurnT], Point(203,0), Point(265,73),
                                     Point(213,72), 0,0,0, 0);


Sprite** combo2Frames = new Sprite*[5];
Point combo2HighHit[] = {Point(0,0), Point(59,45), Point(-700,-700)};
Point combo2HighHit1[] = {Point(98,24), Point(138,45), Point(-700,-700)};
Point combo2HighHit2[] = {Point(213,21), Point(244,45), Point(-700,-700)};
Point combo2HighHit3[] = {Point(343,21), Point(371,45), Point(-700,-700)};
Point combo2HighHit4[] = {Point(465,25), Point(493,45), Point(-700,-700)};

Point combo2LowHit[] = {Point(0,45), Point(61,90), Point(-700,-700)};
Point combo2LowHit1[] = {Point(93,45), Point(173,90), Point(-700,-700)};
Point combo2LowHit2[] = {Point(201,45), Point(276,90), Point(-700,-700)};
Point combo2LowHit3[] = {Point(327,45), Point(390,90), Point(-700,-700)};
Point combo2LowHit4[] = {Point(452,45), Point(527,90), Point(-700,-700)};

combo2Frames[0] = new Sprite(Global::TrivediBabuAnimations[combo2T], Point(0,0), Point(75,90),
                             Point(10, 90), combo2HighHit, combo2LowHit, 0, 0);
combo2Frames[1] = new Sprite(Global::TrivediBabuAnimations[combo2T], Point(84, 0), Point(172, 90),
                             Point(91, 90), combo2HighHit1, combo2LowHit1, 0, 0);
combo2Frames[2] = new Sprite(Global::TrivediBabuAnimations[combo2T], Point(179, 0), Point(276, 90),
                             Point(195, 90), combo2HighHit2, combo2LowHit2, 0, 0);
combo2Frames[3] = new Sprite(Global::TrivediBabuAnimations[combo2T], Point(291,0), Point(405, 90),
                             Point(301, 90), combo2HighHit3, combo2LowHit3, 0, 0);
combo2Frames[4] = new Sprite(Global::TrivediBabuAnimations[combo2T], Point(412, 0), Point(527, 90),
                             Point(423, 90), combo2HighHit4, combo2LowHit4, 0, 0);

Sprite** getHitStandingLowFrames = new Sprite*[4];

    Point getHitStandingLowHigh[] = {Point(0,11),Point(66,40),Point(-700,-700)};
    Point getHitStandingLowHigh1[] = {Point(73,11),Point(141,40),Point(-700,-700)};
    Point getHitStandingLowHigh2[] = {Point(149,11),Point(217,40),Point(-700,-700)};
    Point getHitStandingLowHigh3[] = {Point(225,11),Point(311,40),Point(-700,-700)};

    Point getHitStandingLowLow[] = {Point(0,40),Point(66,88),Point(-700,-700)};
    Point getHitStandingLowLow1[] = {Point(73,40),Point(141,88),Point(-700,-700)};
    Point getHitStandingLowLow2[] = {Point(149,40),Point(217,88),Point(-700,-700)};
    Point getHitStandingLowLow3[] = {Point(225,40),Point(311,88),Point(-700,-700)};

    getHitStandingLowFrames[0] = new Sprite(Global::TrivediBabuAnimations[getHitStandingLowT],
                                Point(0,0),Point(66,88),Point(18,88),getHitStandingLowHigh,
                                            getHitStandingLowLow,0,0);
    getHitStandingLowFrames[1] = new Sprite(Global::TrivediBabuAnimations[getHitStandingLowT],
                                Point(73,0),Point(141,88),Point(99,88),getHitStandingLowHigh1,
                                            getHitStandingLowLow1,0,0);
    getHitStandingLowFrames[2] = new Sprite(Global::TrivediBabuAnimations[getHitStandingLowT],
                                Point(149,0),Point(217,88),Point(180,88),getHitStandingLowHigh2,
                                            getHitStandingLowLow2,0,0);
    getHitStandingLowFrames[3] = new Sprite(Global::TrivediBabuAnimations[getHitStandingLowT],
                                Point(225,0),Point(311,88),Point(254,88),getHitStandingLowHigh3,
                                            getHitStandingLowLow3,0,0);


Sprite** getHitStandingHighFrames = new Sprite*[4];

    Point getHitStandingHighFramesHighHit[] = {Point(0,0),Point(46,40),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit1[] = {Point(77,0),Point(121,40),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit2[] = {Point(158,0),Point(205,40),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit3[] = {Point(240,0),Point(291,40),Point(-700,-700)};

    Point getHitStandingHighFramesLowHit[] = {Point(6,40),Point(63,92),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit1[] = {Point(88,40),Point(139,92),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit2[] = {Point(177,40),Point(225,92),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit3[] = {Point(267,40),Point(312,92),Point(-700,-700)};

    getHitStandingHighFrames[0] = new Sprite(Global::TrivediBabuAnimations[getHitStandingHighT],
                                       Point(0,0), Point(70,92), Point(14,92), getHitStandingHighFramesHighHit,
                                       getHitStandingHighFramesLowHit,0,0);
    getHitStandingHighFrames[1] = new Sprite(Global::TrivediBabuAnimations[getHitStandingHighT],
                                       Point(77,0), Point(151,92), Point(96,92), getHitStandingHighFramesHighHit1,
                                             getHitStandingHighFramesLowHit1,0,0);
    getHitStandingHighFrames[2] = new Sprite(Global::TrivediBabuAnimations[getHitStandingHighT],
                                       Point(158,0), Point(232,92), Point(182,92), getHitStandingHighFramesHighHit2,
                                             getHitStandingHighFramesLowHit2,0,0);
    getHitStandingHighFrames[3] = new Sprite(Global::TrivediBabuAnimations[getHitStandingHighT],
                                       Point(240,0), Point(332,92), Point(270,92), getHitStandingHighFramesHighHit3,
                                             getHitStandingHighFramesLowHit3,0,0);


Sprite** getHitCrouchFrames = new Sprite*[3];
    Point getHitCrouchLowHit[] = {Point(0,0), Point(73,65), Point(-700,-700)};
    Point getHitCrouchLowHit1[] = {Point(81,0), Point(159,65), Point(-700,-700)};
    Point getHitCrouchLowHit2[] = {Point(166,0), Point(248,65), Point(-700,-700)};

    getHitCrouchFrames[0] = new Sprite(Global::TrivediBabuAnimations[getHitCrouchT],
                                       Point(0,0), Point(73,65), Point(34,65), 0, getHitCrouchLowHit,0,0);
    getHitCrouchFrames[1] = new Sprite(Global::TrivediBabuAnimations[getHitCrouchT],
                                       Point(81,0), Point(159,65), Point(119,65), 0, getHitCrouchLowHit1,0,0);
    getHitCrouchFrames[2] = new Sprite(Global::TrivediBabuAnimations[getHitCrouchT],
                                       Point(166,0), Point(248,65), Point(207,65), 0, getHitCrouchLowHit2,0,0);

Sprite** knockDownFrames = new Sprite*[7];

    knockDownFrames[0] = new Sprite(Global::TrivediBabuAnimations[knockDownT], Point(0,0), Point(52,115),
                              Point(19,115),0,0,0, 0);
    knockDownFrames[1] = new Sprite(Global::TrivediBabuAnimations[knockDownT], Point(58,0), Point(127,115),
                              Point(104,115),0,0,0, 0);
    knockDownFrames[2] = new Sprite(Global::TrivediBabuAnimations[knockDownT], Point(135,0), Point(248,115),
                              Point(210,115),0,0,0, 0);
    knockDownFrames[3] = new Sprite(Global::TrivediBabuAnimations[knockDownT], Point(254,0), Point(378,115),
                              Point(353,115),0,0,0, 0);
    knockDownFrames[4] = new Sprite(Global::TrivediBabuAnimations[knockDownT], Point(385,0), Point(511,115),
                              Point(509,115),0,0,0, 0);
    knockDownFrames[5] = new Sprite(Global::TrivediBabuAnimations[knockDownT], Point(518,0), Point(634,115),
                              Point(631,115),0,0,0, 0);
    knockDownFrames[6] = new Sprite(Global::TrivediBabuAnimations[knockDownT], Point(518,0), Point(634,115),
                              Point(631,115),0,0,0, 0);


    Sprite** victoryFrames = new Sprite*[3];

    victoryFrames[0] = new Sprite(Global::TrivediBabuAnimations[victoryT], Point(0,0), Point(60,101),
                              Point(10,101),0,0,0, 0);
    victoryFrames[1] = new Sprite(Global::TrivediBabuAnimations[victoryT], Point(68,0), Point(130,101),
                              Point(77,101),0,0,0, 0);
    victoryFrames[2] = new Sprite(Global::TrivediBabuAnimations[victoryT], Point(140,0), Point(216,101),
                              Point(148,101),0,0,0, 0);


allAnimations = new Sprite**[numElementsT];
allAnimations[stanceT] = stanceFrames;
allAnimations[crouchT] = crouchFrames;
allAnimations[guardT] = guardFrames;
allAnimations[crouchGuardT] = crouchGuardFrames;
allAnimations[jumpT] = jumpFrames;
allAnimations[crouchJabT] = crouchJabFrames;
allAnimations[shortKickT] = shortKickFrames;
allAnimations[strongJabT] = strongJabFrames;
allAnimations[walkForwardT] = walkForwardFrames;
allAnimations[walkBackwardT] = walkBackwardFrames;
allAnimations[crouchKickT] = crouchKickFrames;
allAnimations[crouchTurnT] = crouchTurnFrames;
allAnimations[combo1T] = combo1Frames;
allAnimations[jumpJabT] = jumpJabFrames;
allAnimations[jumpKickT] = jumpKickFrames;
allAnimations[crouchKick1T] = crouchKick1Frames;
allAnimations[combo2T] = combo2Frames;
allAnimations[getHitCrouchT] = getHitCrouchFrames;
allAnimations[getHitStandingHighT] = getHitStandingHighFrames;
allAnimations[getHitStandingLowT] = getHitStandingLowFrames;
allAnimations[knockDownT] = knockDownFrames;
allAnimations[victoryT] = victoryFrames;

currentAnimation = -1;
currentAnimationInd = -1;
Stance();
}

TrivediBabu::~TrivediBabu()
{
    delete [] allAnimations;
}


void TrivediBabu::RecieveInput(Uint32 type, int key)
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

        case iKeyL:
            if(negativeFrames == 0 && ifAcceptingInput && cCombo > 0 && state == sNormal
               && super == 100)
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
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1T)
            {
                crouchKick1Status = crouchKick1RightT;
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
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1T)
            {
                crouchKick1Status = crouchKick1LeftT;
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
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1T)
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
             else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1T)
            {
                crouchKick1Status = -1;
            }
           break;
        }
    }
}

Projectile* TrivediBabu::UpdateSprite()
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
    if(position.y < Arena::baseLine || yVelocity < 0)
    {
        yVelocity += Arena::gravity;
        position.y += yVelocity;
    }
    if(position.y >= Arena::baseLine)
    {
        if(state == sJumping && yVelocity >= 0)
        {
            state = sNormal;
            position.y = Arena::baseLine;
            yVelocity = 0;
        }
    }

    int a [] = {1 , -1};
    if(state == sJumping && negativeFrames == 0)
    {
        if(movement == mForward && !orientation || orientation && movement == mBackward)
        {
            position.x += 3;
        }
        else if(movement == mBackward && !orientation || orientation && movement == mForward)
        {
            position.x -= 3;
        }
    }

    currentAnimationInd++;
    if(currentAnimationInd / spread >= currentAnimationCap)
    {
        if(currentAnimation == victoryT || currentAnimation == knockDownT)
        {
            currentAnimationInd--;
            return 0;
        }
        if(currentAnimation == crouchKick1T)
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
                    if(currentAnimation == walkBackwardT)
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
    if(currentAnimation == combo1T && currentAnimationInd < 8)
    {
        position.x += 6 * a[orientation];
    }
    if(currentAnimation == jumpKickT && currentAnimationInd < 8)
    {
        position.x += 6 * a[orientation];
    }
    if(currentAnimationInd < 0)
    {
        currentAnimationInd = 0;
    }

    if(crouchKick1Status == crouchKick1LeftT)
    {
        position.x -= 5;
    }
    else if(crouchKick1Status == crouchKick1RightT)
    {
        position.x += 5;
    }
    if(currentAnimation == walkForwardT)
    {
        this->position.x += ((currentAnimationInd % spread) == 0 && currentAnimationInd > 0
                             && (currentAnimationInd / spread) > 1) * 20
                              * (a[orientation])/* */;
    }
    else if(currentAnimation == walkBackwardT)
    {
        this->position.x -= (((currentAnimationInd % spread) == 0)
                             && (((currentAnimationInd / spread) >= 2) &&
                                 (currentAnimationInd / spread < 8)))
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

//    cout << currentAnimationInd/spread << endl;
    nextSprite = allAnimations[currentAnimation][currentAnimationInd / spread];
    nextSprite->UpdateSprite(position, orientation);
    if(currentAnimation == combo2T && (currentAnimationInd % spread == 0)
       && (currentAnimationInd / spread == (currentAnimationCap - 1)))
    {
        SDL_Rect* r = nextSprite->GetDestRect();
        Point t;
        if(orientation)
        {
            t.x = r->x;
        }
        else
        {
            t.x = r->x + r->w;
        }
        t.y = r->y + r->h / 3;
        tempP = ProjectileFactory::createProjectile(projectileHadouken,t,orientation);
    }
    return tempP;
}

void TrivediBabu::Render(SDL_Renderer* gRenderer)
{
    nextSprite->Render(gRenderer);
    healthBar->renderBar(gRenderer);
    superBar->renderBar(gRenderer);

//    SDL_SetRenderDrawColor(gRenderer, 0, 255 ,0 ,0);
//    SDL_RenderDrawPoint(gRenderer, position.x, position.y);
}


void TrivediBabu::Turn()
{
    countToTurn = 1;
}

void TrivediBabu::CrouchTurn()
{
    currentAnimation = crouchTurnT;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    countToTurn = negativeFrames;
}

void TrivediBabu::CrouckKick()
{
    hasDamaged = false;
    damage = 5;
        currentAnimation = crouchKickT;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void TrivediBabu::Jump()
{
    currentAnimation = jumpT;
    spread = 4 * Global::dF;
    currentAnimationInd = spread - 1;
    currentAnimationCap = 4;
    yVelocity = -7* Global::dF;
    negativeFrames = 0;
}

void TrivediBabu::JumpFromStand()
{
    currentAnimation = jumpT;
    spread = 4 * Global::dF;
    currentAnimationInd = 2 * spread - 1;
    currentAnimationCap = 4;
    yVelocity = -7 * Global::dF;
    negativeFrames = 0;
}

void TrivediBabu::Jumping()
{
    currentAnimation = jumpT;
    currentAnimationCap = 4;
    spread = 1;
    currentAnimationInd = 3;
    negativeFrames = 0;
}

void TrivediBabu::Stance()
{
    currentAnimationInd = -1;
    currentAnimation = stanceT;
    currentAnimationCap = 6;
    spread = 9 * Global::dF;
    negativeFrames = 0;
}

void TrivediBabu::Guarding()
{
    currentAnimation = guardT;
    currentAnimationCap = 1;
    spread = 1;
    currentAnimationInd = 0;
    negativeFrames = 0;
}

void TrivediBabu::CrouchGuarding()
{
    currentAnimation = crouchGuardT;
    currentAnimationCap = 1;
    spread = 1;
    currentAnimationInd = 0;
    negativeFrames = 0;
}

void TrivediBabu::WalkForward()
{
    currentAnimation = walkForwardT;
    currentAnimationInd = -1;
    currentAnimationCap = 5;
    spread = 4 * Global::dF;
    negativeFrames = 0;
}

void TrivediBabu::WalkBackward(bool justIn)
{
    currentAnimation = walkBackwardT;
    //currentAnimationInd = -1;
    if(justIn)
    {
        currentAnimationInd = 3;
    }
    else
    {
        currentAnimationInd = -1;
    }
    currentAnimationCap = 6;
    spread = 4 * Global::dF;
    negativeFrames = 0;
}

void TrivediBabu::Crouching()
{
    currentAnimation = crouchT;
    currentAnimationCap = 2;
    spread = 1;
    currentAnimationInd = 1;
    negativeFrames = 0;
}

void TrivediBabu::Crouch()
{
    currentAnimation = crouchT;
    currentAnimationCap = 2;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void TrivediBabu::StrongJab()
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = strongJabT;
    currentAnimationInd = -1;
    currentAnimationCap = 6;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void TrivediBabu::JumpJab()
{    hasDamaged = false;
    damage = 5;
    currentAnimation = jumpJabT;
    currentAnimationInd = -1;
    currentAnimationCap = 3;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void TrivediBabu::Combo1()
{    hasDamaged = false;
    damage = 25;
//    int a[] = {1,-1};
//    position.x += a[orientation]*50;
    currentAnimation = combo1T;
    currentAnimationInd = -1;
    currentAnimationCap = 13;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    yVelocity = -7 * Global::dF;
    state = sJumping;
}
void TrivediBabu::CrouchLightJab()
{
    hasDamaged = false;
    damage = 5;
        currentAnimation = crouchJabT;
    currentAnimationInd = -1;
    currentAnimationCap = 4;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void TrivediBabu::ShortKick()
{    hasDamaged = false;
    damage = 5;
    currentAnimation = shortKickT;
    currentAnimationCap = 6;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void TrivediBabu::CrouchKick1()
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = crouchKick1T;
    currentAnimationCap = 9;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void TrivediBabu::JumpKick()
{
        hasDamaged = false;
    damage = 5;
//    int a[] = {1,-1};
//    position.x += a[orientation]*50;
    currentAnimation = jumpKickT;
    currentAnimationCap = 5;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void TrivediBabu::Combo2()
{
    super = 0;
    superBar->emptyBar();
    currentAnimation = combo2T;
    currentAnimationCap = 5;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    Global::superCount = negativeFrames * 2;
}

void TrivediBabu::GetHitCrouch(int power)
{
    currentAnimation = getHitCrouchT;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void TrivediBabu::GetHitStandingHigh(int power)
{
    currentAnimation = getHitStandingHighT;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void TrivediBabu::GetHitStandingLow(int power)
{
    currentAnimation = getHitStandingLowT;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void TrivediBabu::KnockDown()
{
    currentAnimation = knockDownT;
    currentAnimationCap = 7;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void TrivediBabu::Victory()
{
    currentAnimation = victoryT;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

bool TrivediBabu::HandleHit(int hitType, int damage, int frames)
{
    if(cHultHult == hitType || hitType == cLowLow || hitType == cHighHigh
       || cHighLow == hitType || hitType == cLowHigh)
    {
        PushBack(2);
        return false;
    }
    if(cHultHigh == hitType)
    {
        if(currentAnimation == guardT)
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
        if(currentAnimation == crouchGuardT)
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
