#include "GaneshGaitonde.h"
#include "Fire.h"
#include "Arena.h"
#include "Fire1.h"
#include "ProjectileFactory.h"

enum{projectileHadouken, projectileFire, projectileFire1};


enum{stanceG, crouchG, guardG, crouchGuardG, jumpG, crouchJabG, shortKickG,
     strongJabG, walkForwardG, walkBackwardG, crouchKickG, crouchTurnG,jumpJabG,
     jumpKickG,crouchKick1G,combo1G,combo2G, getHitCrouchG, getHitStandingHighG,
     getHitStandingLowG, fire1G, fire2G, knockDownG, victoryG,numElementsG};

enum{crouchKick1LeftG, crouchKick1RightG};

enum{cNone, cHultHult, cHultHigh, cHultLow,
            cHighHult, cHighHigh, cHighLow,
            cLowHult , cLowHigh , cLowLow};

GaneshGaitonde::GaneshGaitonde()
{

}

GaneshGaitonde::GaneshGaitonde(Point position1, bool orientation, bool player2) : Character(position1, orientation,player2)
{
    cCombo = -1;
    crouchKick1Status = -1;

//    healthBar = new HealthBar()
    Sprite** getHitCrouchFrames = new Sprite*[3];
    Point getHitCrouchLowHit[] = {Point(0,15), Point(64,80), Point(-700,-700)};
    Point getHitCrouchLowHit1[] = {Point(101,15), Point(176,79), Point(-700,-700)};
    Point getHitCrouchLowHit2[] = {Point(199,21), Point(270,19), Point(-700,-700)};

    getHitCrouchFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[getHitCrouchG],
                                       Point(0,0), Point(94,80), Point(16,79), 0, getHitCrouchLowHit,0,0);
    getHitCrouchFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[getHitCrouchG],
                                       Point(94,0), Point(195,80), Point(136,79), 0, getHitCrouchLowHit1,0,0);
    getHitCrouchFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[getHitCrouchG],
                                       Point(195,0), Point(292,80), Point(226,79), 0, getHitCrouchLowHit2,0,0);

    Sprite** getHitStandingHighFrames = new Sprite*[4];

    Point getHitStandingHighFramesHighHit[] = {Point(4,9),Point(44,48),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit1[] = {Point(93,18),Point(140,44),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit2[] = {Point(191,23),Point(243,46),Point(-700,-700)};
    Point getHitStandingHighFramesHighHit3[] = {Point(293,24),Point(350,48),Point(-700,-700)};

    Point getHitStandingHighFramesLowHit[] = {Point(8, 48),Point(52,96),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit1[] = {Point(112,44),Point(155,88),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit2[] = {Point(215,46),Point(263,91),Point(-700,-700)};
    Point getHitStandingHighFramesLowHit3[] = {Point(325,48),Point(376,94),Point(-700,-700)};

    getHitStandingHighFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[getHitStandingHighG],
                                       Point(0,0), Point(88,102), Point(16,101), getHitStandingHighFramesHighHit,
                                       getHitStandingHighFramesLowHit,0,0);
    getHitStandingHighFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[getHitStandingHighG],
                                       Point(88,0), Point(187,102), Point(119,101), getHitStandingHighFramesHighHit1,
                                             getHitStandingHighFramesLowHit1,0,0);
    getHitStandingHighFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[getHitStandingHighG],
                                       Point(187,0), Point(288,102), Point(225,101), getHitStandingHighFramesHighHit2,
                                             getHitStandingHighFramesLowHit2,0,0);
    getHitStandingHighFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[getHitStandingHighG],
                                       Point(288,0), Point(385,102), Point(337,101), getHitStandingHighFramesHighHit3,
                                             getHitStandingHighFramesLowHit3,0,0);

//    cout << position.x << position.y << endl;
    Sprite** stanceFrames = new Sprite*[7];
    Point stanceHighHit[] = {Point(19,10), Point(59,50), Point(-700,-700)};
    Point stanceHighHit1[] = {Point(121,10), Point(166,50), Point(-700,-700)};
    Point stanceHighHit2[] = {Point(224,10), Point(271,50), Point(-700,-700)};
    Point stanceHighHit3[] = {Point(324,10), Point(369,50), Point(-700,-700)};
    Point stanceHighHit4[] = {Point(424,10), Point(469,50), Point(-700,-700)};
    Point stanceHighHit5[] = {Point(524,10), Point(569,50), Point(-700,-700)};
    Point stanceHighHit6[] = {Point(624,10), Point(669,50), Point(-700,-700)};

    Point stanceLowHit[] = {Point(14,50), Point(64,102), Point(-700,-700)};
    Point stanceLowHit1[] = {Point(121,50), Point(168,102), Point(-700,-700)};
    Point stanceLowHit2[] = {Point(224,50), Point(274,102), Point(-700,-700)};
    Point stanceLowHit3[] = {Point(325,50), Point(375,102), Point(-700,-700)};
    Point stanceLowHit4[] = {Point(429,50), Point(479,102), Point(-700,-700)};
    Point stanceLowHit5[] = {Point(529,50), Point(579,102), Point(-700,-700)};
    Point stanceLowHit6[] = {Point(629,50), Point(679,102), Point(-700,-700)};

    stanceFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[stanceG], Point(0,0), Point(102,102),
                                 Point(16, 102), stanceHighHit, stanceLowHit, 0, 0);
    stanceFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[stanceG], Point(102, 0), Point(207, 102),
                                 Point(120, 102), stanceHighHit1, stanceLowHit1, 0, 0);
    stanceFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[stanceG], Point(207, 0), Point(310, 102),
                                 Point(224, 102), stanceHighHit2,stanceLowHit2,0, 0);
    stanceFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[stanceG], Point(310,0), Point(412, 102),
                                 Point(327, 101), stanceHighHit3,stanceLowHit3,0, 0);
    stanceFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[stanceG], Point(412, 0), Point(513, 102),
                                 Point(428, 102), stanceHighHit4,stanceLowHit4,0, 0);
    stanceFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[stanceG], Point(513, 0), Point(613, 102),
                                 Point(529, 102), stanceHighHit5,stanceLowHit5,0, 0);
    stanceFrames[6] = new Sprite(Global::GaneshGaitondeAnimations[stanceG], Point(613, 0), Point(705, 102),
                                 Point(630, 102),stanceHighHit6,stanceLowHit6,0, 0);


    Sprite** crouchFrames = new Sprite*[2];

    Point crouchLowHit[] = {Point(90,24), Point(151,94), Point(-700,-700)};
    Point crouchLowHit1[] = {Point(159,24), Point(219,94), Point(-700,-700)};

    crouchFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[crouchG], Point(88, 0), Point(157,94),
                             Point(107, 94),0,crouchLowHit,0, 0);
    crouchFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[crouchG], Point(157, 0), Point(219, 94),
                             Point(176, 94),0 ,crouchLowHit1,0, 0);


    Sprite** guardFrames = new Sprite*[1];

    Point guardHighHit[] = {Point(106,11), Point(159,42), Point(-700,-700)};

    Point guardLowHit[] = {Point(113,42), Point(164,94), Point(-700,-700)};

    guardFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[guardG], Point(99,0), Point(164,100),
                                Point(117, 99),guardHighHit,guardLowHit,0, 0);


    Sprite** crouchGuardFrames = new Sprite*[1];

    Point crouchGuardLowHit[] = {Point(69,0), Point(126,72), Point(-700,-700)};

    crouchGuardFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[crouchGuardG], Point(66,0), Point(126,72),
                                      Point(82,71),0,crouchGuardLowHit,0, 0);


    Sprite** jumpFrames = new Sprite*[12];
    Point jumpHighHit[] = {Point(0,0), Point(0,0), Point(-700,-700)};
    Point jumpHighHit1[] = {Point(91,43), Point(128,70), Point(-700,-700)};
    Point jumpHighHit2[] = {Point(153,28), Point(189,52), Point(-700,-700)};
    Point jumpHighHit3[] = {Point(210,28), Point(252,52), Point(-700,-700)};
    Point jumpHighHit4[] = {Point(265,43), Point(308,70), Point(-700,-700)};
    Point jumpHighHit5[] = {Point(334,47), Point(382,88), Point(-700,-700)};
    Point jumpHighHit6[] = {Point(0,0), Point(0,0), Point(-700,-700)};
    Point jumpHighHit7[] = {Point(473,47), Point(527,88), Point(-700,-700)};
    Point jumpHighHit8[] = {Point(538,43), Point(590,70), Point(-700,-700)};
    Point jumpHighHit9[] = {Point(593,28), Point(635,52), Point(-700,-700)};
    Point jumpHighHit10[] = {Point(652,28), Point(691,52), Point(-700,-700)};
    Point jumpHighHit11[] = {Point(0,0), Point(0,0), Point(-700,-700)};

    Point jumpLowHit[] = {Point(0,56), Point(60,126), Point(-700,-700)};
    Point jumpLowHit1[] = {Point(85,70), Point(134,126), Point(-700,-700)};
    Point jumpLowHit2[] = {Point(158,52), Point(194,126), Point(-700,-700)};
    Point jumpLowHit3[] = {Point(216,52), Point(252,126), Point(-700,-700)};
    Point jumpLowHit4[] = {Point(270,70), Point(312,126), Point(-700,-700)};
    Point jumpLowHit5[] = {Point(329,88), Point(382,126), Point(-700,-700)};
    Point jumpLowHit6[] = {Point(407,57), Point(457,126), Point(-700,-700)};
    Point jumpLowHit7[] = {Point(470,88), Point(522,126), Point(-700,-700)};
    Point jumpLowHit8[] = {Point(539,70), Point(584,126), Point(-700,-700)};
    Point jumpLowHit9[] = {Point(600,52), Point(635,126), Point(-700,-700)};
    Point jumpLowHit10[] = {Point(656,52), Point(693,126), Point(-700,-700)};
    Point jumpLowHit11[] = {Point(714,56), Point(764,126), Point(-700,-700)};

    jumpFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(0,0), Point(63,126),
                               Point(16,125),jumpHighHit,jumpLowHit,0, 0);
    jumpFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(63,0), Point(151,126),
                               Point(83,125),jumpHighHit1,jumpLowHit1,0, 0);
    jumpFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(151,0), Point(207,126),
                               Point(169,125),jumpHighHit2,jumpLowHit2,0, 0);
    jumpFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(207,0), Point(261,126),
                               Point(227,125),jumpHighHit3,jumpLowHit3,0, 0);
    jumpFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(261,0), Point(323,126),
                               Point(283,125),jumpHighHit4,jumpLowHit4,0, 0);
    jumpFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(323,0), Point(391,126),
                               Point(349,125),jumpHighHit5,jumpLowHit5,0, 0);
    jumpFrames[6] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(391,0), Point(463,126),
                               Point(421,125),jumpHighHit6,jumpLowHit6,0, 0);
    jumpFrames[7] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(463,0), Point(533,126),
                               Point(490,125),jumpHighHit7,jumpLowHit7,0, 0);
    jumpFrames[8] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(533,0), Point(591,126),
                               Point(556,125),jumpHighHit8,jumpLowHit8,0, 0);
    jumpFrames[9] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(591,0), Point(646,126),
                               Point(610,125),jumpHighHit9,jumpLowHit9,0, 0);
    jumpFrames[10] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(646,0), Point(702,126),
                               Point(668,125),jumpHighHit10,jumpLowHit10,0, 0);
    jumpFrames[11] = new Sprite(Global::GaneshGaitondeAnimations[jumpG], Point(702,0), Point(764,126),
                               Point(720,125),jumpHighHit11,jumpLowHit11,0, 0);


    Sprite** crouchJabFrames = new Sprite*[11];

    Point crouchJabLowHit[] = {Point(0,0), Point(72,67), Point(-700,-700)};
    Point crouchJabLowHit1[] = {Point(80,0), Point(167,67), Point(-700,-700)};
    Point crouchJabLowHit2[] = {Point(173,0), Point(246,67), Point(-700,-700)};
    Point crouchJabLowHit3[] = {Point(254,0), Point(344,67), Point(-700,-700)};
    Point crouchJabLowHit4[] = {Point(353,0), Point(437,67), Point(-700,-700)};
    Point crouchJabLowHit5[] = {Point(487,0), Point(574,67), Point(-700,-700)};
    Point crouchJabLowHit6[] = {Point(733,0), Point(819,67), Point(-700,-700)};
    Point crouchJabLowHit7[] = {Point(868,0), Point(995,67), Point(-700,-700)};
    Point crouchJabLowHit8[] = {Point(1004,0), Point(1093,67), Point(-700,-700)};
    Point crouchJabLowHit9[] = {Point(1101,0), Point(1173,67), Point(-700,-700)};
    Point crouchJabLowHit10[] = {Point(1181,0), Point(1267,67), Point(-700,-700)};

    Point crouchJabHurt3[] = {Point(330,37), Point(344,45), Point(-700,-700)};
    Point crouchJabHurt4[] = {Point(460,32), Point(478,44), Point(-700,-700)};
    Point crouchJabHurt5[] = {Point(580,35), Point(725,45), Point(-700,-700)};
    Point crouchJabHurt6[] = {Point(837,30), Point(995,45), Point(-700,-700)};
    Point crouchJabHurt7[] = {Point(1077,37), Point(1093,45), Point(-700,-700)};

    crouchJabFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(0,0), Point(72,67),
                              Point(12,67),0,crouchJabLowHit,0, 0);
    crouchJabFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(80,0), Point(167,67),
                              Point(91,67),0,crouchJabLowHit1,0, 0);
    crouchJabFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(173,0), Point(246,67),
                              Point(185,67),0,crouchJabLowHit2,0, 0);
    crouchJabFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(254,0), Point(344,67),
                              Point(266,67),0,crouchJabLowHit3,crouchJabHurt3, 0);
    crouchJabFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(353,0), Point(478,67),
                              Point(364,67),0,crouchJabLowHit4,crouchJabHurt4, 0);
    crouchJabFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(487,0), Point(725,67),
                              Point(498,67),0,crouchJabLowHit5,crouchJabHurt5, 0);
    crouchJabFrames[6] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(733,0), Point(860,67),
                              Point(746,67),0,crouchJabLowHit6,crouchJabHurt6, 0);
    crouchJabFrames[7] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(868,0), Point(995,67),
                              Point(880,67),0,crouchJabLowHit7,crouchJabHurt7, 0);
    crouchJabFrames[8] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(1004,0), Point(1093,67),
                              Point(1014,67),0,crouchJabLowHit8,0, 0);
    crouchJabFrames[9] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(1101,0), Point(1173,70),
                              Point(1112,67),0,crouchJabLowHit9,0, 0);
    crouchJabFrames[10] = new Sprite(Global::GaneshGaitondeAnimations[crouchJabG], Point(1181,0), Point(1267,70),
                              Point(1195,67),0,crouchJabLowHit10,0, 0);



    Sprite** shortKickFrames = new Sprite*[11];
    Point shortKickHighHit[] = {Point(34,30), Point(53,60), Point(-700,-700)};
    Point shortKickHighHit1[] = {Point(114,29), Point(148,60), Point(-700,-700)};
    Point shortKickHighHit2[] = {Point(196,29), Point(227,60), Point(-700,-700)};
    Point shortKickHighHit3[] = {Point(273,29), Point(312,60), Point(-700,-700)};
    Point shortKickHighHit4[] = {Point(408,29), Point(447,60), Point(-700,-700)};
    Point shortKickHighHit5[] = {Point(647,29), Point(684,60), Point(-700,-700)};
    Point shortKickHighHit6[] = {Point(780,29), Point(820,60), Point(-700,-700)};
    Point shortKickHighHit7[] = {Point(906,29), Point(946,60), Point(-700,-700)};
    Point shortKickHighHit8[] = {Point(989,29), Point(1028,60), Point(-700,-700)};
    Point shortKickHighHit9[] = {Point(1101,29), Point(1143,60), Point(-700,-700)};
    Point shortKickHighHit10[] = {Point(1209,29), Point(1248,60), Point(-700,-700)};

    Point shortKickLowHit[] = {Point(0,60), Point(61,119), Point(-700,-700)};
    Point shortKickLowHit1[] = {Point(84,60), Point(144,119), Point(-700,-700)};
    Point shortKickLowHit2[] = {Point(190,60), Point(239,119), Point(-700,-700)};
    Point shortKickLowHit3[] = {Point(255,60), Point(323,119), Point(-700,-700)};
    Point shortKickLowHit4[] = {Point(389,60), Point(460,119), Point(-700,-700)};
    Point shortKickLowHit5[] = {Point(629,60), Point(699,119), Point(-700,-700)};
    Point shortKickLowHit6[] = {Point(763,60), Point(831,119), Point(-700,-700)};
    Point shortKickLowHit7[] = {Point(900,60), Point(949,119), Point(-700,-700)};
    Point shortKickLowHit8[] = {Point(964,60), Point(1019,119), Point(-700,-700)};
    Point shortKickLowHit9[] = {Point(1072,60), Point(1130,119), Point(-700,-700)};
    Point shortKickLowHit10[] = {Point(1177,60), Point(1239,119), Point(-700,-700)};

    Point shortKickHurt3[] = {Point(349,34), Point(381,47), Point(-700,-700)};
    Point shortKickHurt4[] = {Point(518,19), Point(620,46), Point(-700,-700)};
    Point shortKickHurt5[] = {Point(724,34), Point(754,47), Point(-700,-700)};
    Point shortKickHurt6[] = {Point(867,35), Point(893,47), Point(-700,-700)};

    shortKickFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(0,0), Point(78,119),
                                    Point(12,119), shortKickHighHit,shortKickLowHit,0, 0);
    shortKickFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(84,0), Point(183, 119),
                                    Point(96, 119),shortKickHighHit1,shortKickLowHit1,0, 0);
    shortKickFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(190,0), Point(246, 119),
                                    Point(188,119),shortKickHighHit2,shortKickLowHit2,0, 0);
    shortKickFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(255,0), Point(381, 119),
                                    Point(267,119),shortKickHighHit3,shortKickLowHit3,shortKickHurt3, 0);
    shortKickFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(389,0), Point(621,119),
                                    Point(398,119),shortKickHighHit4,shortKickLowHit4,shortKickHurt4, 0);
    shortKickFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(629,0), Point(755,119),
                                    Point(639,119), shortKickHighHit5,shortKickLowHit5,shortKickHurt5, 0);
    shortKickFrames[6] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(763,0), Point(892, 119),
                                    Point(771 , 119),shortKickHighHit6,shortKickLowHit6,shortKickHurt6, 0);
    shortKickFrames[7] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(900,0), Point(956, 119),
                                    Point(900,119),shortKickHighHit7,shortKickLowHit7,0, 0);
    shortKickFrames[8] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(964,0), Point(1064, 119),
                                    Point(974,119),shortKickHighHit8,shortKickLowHit8,0, 0);
    shortKickFrames[9] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(1072,0), Point(1170,119),
                                    Point(1083,119),shortKickHighHit9,shortKickLowHit9,0, 0);
    shortKickFrames[10] = new Sprite(Global::GaneshGaitondeAnimations[shortKickG], Point(1177,0), Point(1254,119),
                                    Point(1190,119), shortKickHighHit10,shortKickLowHit10,0, 0);



    Sprite** strongJabFrames = new Sprite*[8];
    Point strongJabHighHit[] = {Point(10,15), Point(71,46), Point(-700,-700)};
    Point strongJabHighHit1[] = {Point(144,29), Point(183,46), Point(-700,-700)};
    Point strongJabHighHit2[] = {Point(244,29), Point(287,46), Point(-700,-700)};
    Point strongJabHighHit3[] = {Point(399,29), Point(436,46), Point(-700,-700)};
    Point strongJabHighHit4[] = {Point(641,29), Point(685,46), Point(-700,-700)};
    Point strongJabHighHit5[] = {Point(796,29), Point(830,46), Point(-700,-700)};
    Point strongJabHighHit6[] = {Point(933,29), Point(965,46), Point(-700,-700)};
    Point strongJabHighHit7[] = {Point(999,29), Point(1049,46), Point(-700,-700)};

    Point strongJabLowHit[] = {Point(37,46), Point(86,92), Point(-700,-700)};
    Point strongJabLowHit1[] = {Point(137,46), Point(190,92), Point(-700,-700)};
    Point strongJabLowHit2[] = {Point(237,46), Point(291,92), Point(-700,-700)};
    Point strongJabLowHit3[] = {Point(384,46), Point(439,92), Point(-700,-700)};
    Point strongJabLowHit4[] = {Point(629,46), Point(684,92), Point(-700,-700)};
    Point strongJabLowHit5[] = {Point(773,46), Point(832,92), Point(-700,-700)};
    Point strongJabLowHit6[] = {Point(923,46), Point(982,92), Point(-700,-700)};
    Point strongJabLowHit7[] = {Point(1002,46), Point(1072,92), Point(-700,-700)};

    Point strongJabHurt2[] = {Point(309,31), Point(336,40), Point(-700,-700)};
    Point strongJabHurt3[] = {Point(478,31), Point(583,40), Point(-700,-700)};
    Point strongJabHurt4[] = {Point(706,31), Point(728,40), Point(-700,-700)};
    Point strongJabHurt5[] = {Point(843,31), Point(877,40), Point(-700,-700)};

    strongJabFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[strongJabG], Point(0,0), Point(86,92),
                                    Point(11,92),strongJabHighHit,strongJabLowHit,0, 0);
    strongJabFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[strongJabG], Point(94,0), Point(191,92),
                                    Point(101,92),strongJabHighHit1,strongJabLowHit1,0, 0);
    strongJabFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[strongJabG], Point(198,0), Point(336,92),
                                    Point(204,92),strongJabHighHit2,strongJabLowHit2,strongJabHurt2, 0);
    strongJabFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[strongJabG], Point(344,0), Point(581,92),
                                    Point(350,92),strongJabHighHit3,strongJabLowHit3,strongJabHurt3, 0);
    strongJabFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[strongJabG], Point(589,0), Point(727,92),
                                    Point(594,92),strongJabHighHit4,strongJabLowHit4,strongJabHurt4, 0);
    strongJabFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[strongJabG], Point(735,0), Point(877,92),
                                    Point(740,92),strongJabHighHit5,strongJabLowHit5,strongJabHurt5, 0);
    strongJabFrames[6] = new Sprite(Global::GaneshGaitondeAnimations[strongJabG], Point(884,0), Point(980,92),
                                    Point(893,92),strongJabHighHit6,strongJabLowHit6,0, 0);
    strongJabFrames[7] = new Sprite(Global::GaneshGaitondeAnimations[strongJabG], Point(988,0), Point(1072,92),
                                    Point(1000,92),strongJabHighHit7,strongJabLowHit7,0, 0);

    Sprite** walkForwardFrames = new Sprite*[8];
    Point walkForwardHighHit[] = {Point(10,15), Point(49,46), Point(-700,-700)};
    Point walkForwardHighHit1[] = {Point(90,15), Point(131,46), Point(-700,-700)};
    Point walkForwardHighHit2[] = {Point(162,15), Point(206,46), Point(-700,-700)};
    Point walkForwardHighHit3[] = {Point(233,15), Point(273,46), Point(-700,-700)};
    Point walkForwardHighHit4[] = {Point(307,15), Point(348,46), Point(-700,-700)};
    Point walkForwardHighHit5[] = {Point(382,15), Point(423,46), Point(-700,-700)};
    Point walkForwardHighHit6[] = {Point(449,15), Point(490,46), Point(-700,-700)};
    Point walkForwardHighHit7[] = {Point(521,15), Point(562,46), Point(-700,-700)};

    Point walkForwardLowHit[] = {Point(10,46), Point(49,101), Point(-700,-700)};
    Point walkForwardLowHit1[] = {Point(90,46), Point(131,101), Point(-700,-700)};
    Point walkForwardLowHit2[] = {Point(162,46), Point(206,101), Point(-700,-700)};
    Point walkForwardLowHit3[] = {Point(233,46), Point(273,101), Point(-700,-700)};
    Point walkForwardLowHit4[] = {Point(307,46), Point(348,101), Point(-700,-700)};
    Point walkForwardLowHit5[] = {Point(382,46), Point(423,101), Point(-700,-700)};
    Point walkForwardLowHit6[] = {Point(449,46), Point(490,101), Point(-700,-700)};
    Point walkForwardLowHit7[] = {Point(521,46), Point(562,101), Point(-700,-700)};

    walkForwardFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[walkForwardG], Point(0,0), Point(81,101),
                                      Point(2,97),walkForwardHighHit,walkForwardLowHit,0, 0);
    walkForwardFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[walkForwardG], Point(81,0), Point(154,101),
                                      Point(97,97),walkForwardHighHit1,walkForwardLowHit1,0, 0);
    walkForwardFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[walkForwardG], Point(154,0), Point(223,101),
                                      Point(179,97),walkForwardHighHit2,walkForwardLowHit2,0, 0);
    walkForwardFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[walkForwardG], Point(223,0), Point(290,101),
                                      Point(252,97),walkForwardHighHit3,walkForwardLowHit3,0, 0);
    walkForwardFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[walkForwardG], Point(290,0), Point(365,101),
                                      Point(333,97),walkForwardHighHit4,walkForwardLowHit4,0, 0);
    walkForwardFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[walkForwardG], Point(365,0), Point(438,101),
                                      Point(400,97),walkForwardHighHit5,walkForwardLowHit5,0, 0);
    walkForwardFrames[6] = new Sprite(Global::GaneshGaitondeAnimations[walkForwardG], Point(438,0), Point(511,101),
                                      Point(463,97),walkForwardHighHit6,walkForwardLowHit6,0, 0);
    walkForwardFrames[7] = new Sprite(Global::GaneshGaitondeAnimations[walkForwardG], Point(511,0), Point(582,101),
                                      Point(523,97),walkForwardHighHit7,walkForwardLowHit7,0, 0);

    Sprite** walkBackwardFrames = new Sprite*[8];
    Point walkBackwardHighHit[] = {Point(0,15), Point(47,46), Point(-700,-700)};
    Point walkBackwardHighHit1[] = {Point(77,15), Point(115,46), Point(-700,-700)};
    Point walkBackwardHighHit2[] = {Point(148,15), Point(185,46), Point(-700,-700)};
    Point walkBackwardHighHit3[] = {Point(223,15), Point(259,46), Point(-700,-700)};
    Point walkBackwardHighHit4[] = {Point(294,15), Point(332,46), Point(-700,-700)};
    Point walkBackwardHighHit5[] = {Point(358,15), Point(395,46), Point(-700,-700)};
    Point walkBackwardHighHit6[] = {Point(424,15), Point(458,46), Point(-700,-700)};
    Point walkBackwardHighHit7[] = {Point(491,15), Point(534,46), Point(-700,-700)};

    Point walkBackwardLowHit[] = {Point(0,46), Point(47,102), Point(-700,-700)};
    Point walkBackwardLowHit1[] = {Point(77,46), Point(115,102), Point(-700,-700)};
    Point walkBackwardLowHit2[] = {Point(148,46), Point(185,102), Point(-700,-700)};
    Point walkBackwardLowHit3[] = {Point(223,46), Point(259,102), Point(-700,-700)};
    Point walkBackwardLowHit4[] = {Point(294,46), Point(332,102), Point(-700,-700)};
    Point walkBackwardLowHit5[] = {Point(358,46), Point(395,102), Point(-700,-700)};
    Point walkBackwardLowHit6[] = {Point(424,46), Point(458,102), Point(-700,-700)};
    Point walkBackwardLowHit7[] = {Point(491,46), Point(534,102), Point(-700,-700)};

    walkBackwardFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[walkBackwardG], Point(0,0), Point(70, 102),
                                       Point(5,98),walkBackwardHighHit,walkBackwardLowHit,0, 0);
    walkBackwardFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[walkBackwardG], Point(70,0), Point(145, 102),
                                       Point(88,98),walkBackwardHighHit1,walkBackwardLowHit1,0, 0);
    walkBackwardFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[walkBackwardG], Point(145,0), Point(214, 102),
                                       Point(167,98),walkBackwardHighHit2,walkBackwardLowHit2,0, 0);
    walkBackwardFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[walkBackwardG], Point(214,0), Point(285, 102),
                                       Point(243,98),walkBackwardHighHit3,walkBackwardLowHit3,0, 0);
    walkBackwardFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[walkBackwardG], Point(285,0), Point(352, 102),
                                       Point(326,98),walkBackwardHighHit4,walkBackwardLowHit4,0, 0);
    walkBackwardFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[walkBackwardG], Point(352,0), Point(418, 102),
                                       Point(384,98),walkBackwardHighHit5,walkBackwardLowHit5,0, 0);
    walkBackwardFrames[6] = new Sprite(Global::GaneshGaitondeAnimations[walkBackwardG], Point(418,0), Point(487, 102),
                                       Point(442,98),walkBackwardHighHit6,walkBackwardLowHit6,0, 0);
    walkBackwardFrames[7] = new Sprite(Global::GaneshGaitondeAnimations[walkBackwardG], Point(487,0), Point(553, 102),
                                       Point(506,98),walkBackwardHighHit7,walkBackwardLowHit7,0, 0);

    Sprite** jumpJabFrames = new Sprite*[8];
    Point jumpJabHighHit[] = {Point(0,50), Point(69,133), Point(-700,-700)};
    Point jumpJabHighHit1[] = {Point(77,50), Point(134,133), Point(-700,-700)};
    Point jumpJabHighHit2[] = {Point(143,50), Point(221,133), Point(-700,-700)};
    Point jumpJabHighHit3[] = {Point(229,0), Point(292,80), Point(-700,-700)};
    Point jumpJabHighHit4[] = {Point(346,50), Point(423,133), Point(-700,-700)};
    Point jumpJabHighHit5[] = {Point(431,50), Point(509,133), Point(-700,-700)};
    Point jumpJabHighHit6[] = {Point(517,50), Point(575,133), Point(-700,-700)};
    Point jumpJabHighHit7[] = {Point(582,50), Point(651,133), Point(-700,-700)};

    Point jumpJabHurt2[] = {Point(203,102), Point(221,116), Point(-700,-700)};
    Point jumpJabHurt3[] = {Point(296,60), Point(339,133), Point(-700,-700)};
    Point jumpJabHurt4[] = {Point(407,100), Point(425,113), Point(-700,-700)};

    jumpJabFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[jumpJabG], Point(0,0), Point(69, 133),
                                       Point(17,133),jumpJabHighHit,0,0, 0);
    jumpJabFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[jumpJabG], Point(77,0), Point(134, 133),
                                       Point(93,133),jumpJabHighHit1,0,0, 0);
    jumpJabFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[jumpJabG], Point(143,0), Point(221, 133),
                                       Point(155,133),jumpJabHighHit2,0,jumpJabHurt2, 0);
    jumpJabFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[jumpJabG], Point(229,0), Point(339, 133),
                                       Point(245,133),jumpJabHighHit3,0,jumpJabHurt3, 0);
    jumpJabFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[jumpJabG], Point(346,0), Point(423, 133),
                                       Point(361,133),jumpJabHighHit4,0,jumpJabHurt4, 0);
    jumpJabFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[jumpJabG], Point(431,0), Point(509, 133),
                                       Point(446,133),jumpJabHighHit5,0,0, 0);
    jumpJabFrames[6] = new Sprite(Global::GaneshGaitondeAnimations[jumpJabG], Point(517,0), Point(575, 133),
                                       Point(534,133),jumpJabHighHit6,0,0, 0);
    jumpJabFrames[7] = new Sprite(Global::GaneshGaitondeAnimations[jumpJabG], Point(582,0), Point(651, 133),
                                       Point(598,133),jumpJabHighHit7,0,0, 0);

    Sprite** crouchKickFrames = new Sprite*[6];
    Point crouchKickLowHit[] = {Point(0,2), Point(76,70), Point(-700,-700)};
    Point crouchKickLowHit1[] = {Point(84,14), Point(155,70), Point(-700,-700)};
    Point crouchKickLowHit2[] = {Point(190,31), Point(265,70), Point(-700,-700)};
    Point crouchKickLowHit3[] = {Point(344,32), Point(430,70), Point(-700,-700)};
    Point crouchKickLowHit4[] = {Point(494,15), Point(552,70), Point(-700,-700)};
    Point crouchKickLowHit5[] = {Point(603,2), Point(666,70), Point(-700,-700)};

    Point crouchKickHurt1[] = {Point(170,55), Point(188,70), Point(-700,-700)};
    Point crouchKickHurt2[] = {Point(287,55), Point(336,70), Point(-700,-700)};
    Point crouchKickHurt3[] = {Point(455,55), Point(492,70), Point(-700,-700)};
    Point crouchKickHurt4[] = {Point(573,55), Point(597,70), Point(-700,-700)};


    crouchKickFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[crouchKickG], Point(0,0), Point(76, 70),
                                           Point(21,70),0,crouchKickLowHit,0, 0);
    crouchKickFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[crouchKickG], Point(84,0), Point(187, 70),
                                           Point(113,70),0,crouchKickLowHit1,crouchKickHurt1, 0);
    crouchKickFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[crouchKickG], Point(188,0), Point(336, 70),
                                           Point(215,70),0,crouchKickLowHit2,crouchKickHurt2, 0);
    crouchKickFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[crouchKickG], Point(344,0), Point(492, 70),
                                           Point(372,70),0,crouchKickLowHit3,crouchKickHurt3, 0);
    crouchKickFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[crouchKickG], Point(494,0), Point(597, 70),
                                           Point(514,70),0,crouchKickLowHit4,crouchKickHurt4, 0);
    crouchKickFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[crouchKickG], Point(606,0), Point(666, 70),
                                           Point(616,70),0,crouchKickLowHit5,0, 0);


    Sprite** crouchTurnFrames = new Sprite*[3];
    crouchTurnFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[crouchTurnG], Point(65,0), Point(133,73),
                                     Point(82,72), 0,0,0, 0);
    crouchTurnFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[crouchTurnG], Point(133,0), Point(203,73),
                                     Point(161,72), 0,0,0, 0);
    crouchTurnFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[crouchTurnG], Point(203,0), Point(265,73),
                                     Point(213,72), 0,0,0, 0);


    Sprite** jumpKickFrames = new Sprite*[6];
    Point jumpKickHighHit[] = {Point(0,0), Point(68,76), Point(-700,-700)};

    Point jumpKickHurt1[] = {Point(76,34), Point(218,76), Point(-700,-700)};
    Point jumpKickHurt2[] = {Point(226,34), Point(366,76), Point(-700,-700)};
    Point jumpKickHurt3[] = {Point(375,34), Point(515,76), Point(-700,-700)};
    Point jumpKickHurt4[] = {Point(523,34), Point(662,76), Point(-700,-700)};


    jumpKickFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[jumpKickG], Point(0,0), Point(68, 76),
                                           Point(6,76),jumpKickHighHit,0,0, 0);
    jumpKickFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[jumpKickG], Point(76,0), Point(218, 76),
                                           Point(78,76),0,0,jumpKickHurt1, 0);
    jumpKickFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[jumpKickG], Point(226,0), Point(366, 76),
                                           Point(230,76),0,0,jumpKickHurt2, 0);
    jumpKickFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[jumpKickG], Point(375,0), Point(515, 76),
                                           Point(375,76),0,0,jumpKickHurt3, 0);
    jumpKickFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[jumpKickG], Point(523,0), Point(662, 76),
                                           Point(524,76),0,0,jumpKickHurt4, 0);


    Sprite** crouchKick1Frames = new Sprite*[10];
    Point crouchKick1HighHit[] = {Point(0,24), Point(72,53), Point(-700,-700)};
    Point crouchKick1HighHit1[] = {Point(70,24), Point(129,53), Point(-700,-700)};
    Point crouchKick1HighHit2[] = {Point(137,24), Point(190,53), Point(-700,-700)};
    Point crouchKick1HighHit3[] = {Point(198,24), Point(236,53), Point(-700,-700)};
    Point crouchKick1HighHit4[] = {Point(269,24), Point(314,53), Point(-700,-700)};
    Point crouchKick1HighHit5[] = {Point(376,24), Point(421,53), Point(-700,-700)};
    Point crouchKick1HighHit6[] = {Point(609,24), Point(652,53), Point(-700,-700)};
    Point crouchKick1HighHit7[] = {Point(716,24), Point(762,53), Point(-700,-700)};
    Point crouchKick1HighHit8[] = {Point(821,24), Point(891,53), Point(-700,-700)};
    Point crouchKick1HighHit9[] = {Point(899,24), Point(973,53), Point(-700,-700)};

    Point crouchKick1LowHit[] = {Point(0,53), Point(72,113), Point(-700,-700)};
    Point crouchKick1LowHit1[] = {Point(70,53), Point(129,113), Point(-700,-700)};
    Point crouchKick1LowHit2[] = {Point(137,53), Point(190,113), Point(-700,-700)};
    Point crouchKick1LowHit3[] = {Point(198,53), Point(236,113), Point(-700,-700)};
    Point crouchKick1LowHit4[] = {Point(269,53), Point(314,113), Point(-700,-700)};
    Point crouchKick1LowHit5[] = {Point(376,53), Point(421,113), Point(-700,-700)};
    Point crouchKick1LowHit6[] = {Point(609,53), Point(652,113), Point(-700,-700)};
    Point crouchKick1LowHit7[] = {Point(716,53), Point(762,113), Point(-700,-700)};
    Point crouchKick1LowHit8[] = {Point(821,53), Point(891,113), Point(-700,-700)};
    Point crouchKick1LowHit9[] = {Point(899,53), Point(973,113), Point(-700,-700)};

    Point crouchKick1Hurt4[] = {Point(338,30), Point(367,56), Point(-700,-700)};
    Point crouchKick1Hurt5[] = {Point(486,0), Point(603,43), Point(-700,-700)};
    Point crouchKick1Hurt6[] = {Point(671,32), Point(709,54), Point(-700,-700)};
    Point crouchKick1Hurt7[] = {Point(773,32), Point(812,52), Point(-700,-700)};

    crouchKick1Frames[0] = new Sprite(Global::GaneshGaitondeAnimations[crouchKick1G], Point(0,0), Point(72,113),
                              Point(36,113),crouchKick1HighHit,crouchKick1LowHit,0, 0);
    crouchKick1Frames[1] = new Sprite(Global::GaneshGaitondeAnimations[crouchKick1G], Point(70,0), Point(129,113),
                              Point(95,113),crouchKick1HighHit1,crouchKick1LowHit1,0, 0);
    crouchKick1Frames[2] = new Sprite(Global::GaneshGaitondeAnimations[crouchKick1G], Point(137,0), Point(190,113),
                              Point(155,113),crouchKick1HighHit2,crouchKick1LowHit2,0, 0);
    crouchKick1Frames[3] = new Sprite(Global::GaneshGaitondeAnimations[crouchKick1G], Point(198,0), Point(262,113),
                              Point(223,113),crouchKick1HighHit3,crouchKick1LowHit3,0, 0);
    crouchKick1Frames[4] = new Sprite(Global::GaneshGaitondeAnimations[crouchKick1G], Point(269,0), Point(368,113),
                              Point(295,113),crouchKick1HighHit4,crouchKick1LowHit4,crouchKick1Hurt4, 0);
    crouchKick1Frames[5] = new Sprite(Global::GaneshGaitondeAnimations[crouchKick1G], Point(376,0), Point(602,113),
                              Point(404,113),crouchKick1HighHit5,crouchKick1LowHit5,crouchKick1Hurt5, 0);
    crouchKick1Frames[6] = new Sprite(Global::GaneshGaitondeAnimations[crouchKick1G], Point(609,0), Point(708,113),
                              Point(636,113),crouchKick1HighHit6,crouchKick1LowHit6,crouchKick1Hurt6, 0);
    crouchKick1Frames[7] = new Sprite(Global::GaneshGaitondeAnimations[crouchKick1G], Point(716,0), Point(814,113),
                              Point(743,113),crouchKick1HighHit7,crouchKick1LowHit7,crouchKick1Hurt7, 0);
    crouchKick1Frames[8] = new Sprite(Global::GaneshGaitondeAnimations[crouchKick1G], Point(821,0), Point(891,113),
                              Point(852,113),crouchKick1HighHit8,crouchKick1LowHit8,0, 0);
    crouchKick1Frames[9] = new Sprite(Global::GaneshGaitondeAnimations[crouchKick1G], Point(899,0), Point(973,113),
                              Point(930,113),crouchKick1HighHit9,crouchKick1LowHit9,0, 0);

    Sprite** combo1Frames = new Sprite*[4];
    Point combo1HighHit[] = {Point(0,26), Point(76,53), Point(-700,-700)};
    Point combo1HighHit1[] = {Point(84,26), Point(165,53), Point(-700,-700)};
    Point combo1HighHit2[] = {Point(173,26), Point(231,53), Point(-700,-700)};
    Point combo1HighHit3[] = {Point(239,36), Point(331,64), Point(-700,-700)};

    Point combo1LowHit[] = {Point(0,53), Point(76,118), Point(-700,-700)};
    Point combo1LowHit1[] = {Point(84,53), Point(165,118), Point(-700,-700)};
    Point combo1LowHit2[] = {Point(173,53), Point(231,118), Point(-700,-700)};
    Point combo1LowHit3[] = {Point(239,64), Point(331,118), Point(-700,-700)};

    combo1Frames[0] = new Sprite(Global::GaneshGaitondeAnimations[combo1G], Point(0,0), Point(76,118),
                              Point(32,118),combo1HighHit,combo1LowHit,0, 0);
    combo1Frames[1] = new Sprite(Global::GaneshGaitondeAnimations[combo1G], Point(84,0), Point(165,118),
                              Point(121,118),combo1HighHit1,combo1LowHit1,0, 0);
    combo1Frames[2] = new Sprite(Global::GaneshGaitondeAnimations[combo1G], Point(173,0), Point(231,118),
                              Point(186,118),combo1HighHit2,combo1LowHit2,0, 0);
    combo1Frames[3] = new Sprite(Global::GaneshGaitondeAnimations[combo1G], Point(239,0), Point(331,118),
                              Point(252,118),combo1HighHit3,combo1LowHit3,0, 0);

    Sprite** combo2Frames = new Sprite*[4];
    Point combo2HighHit[] = {Point(0,32), Point(76,53), Point(-700,-700)};
    Point combo2HighHit1[] = {Point(84,32), Point(165,53), Point(-700,-700)};

    Point combo2LowHit[] = {Point(0,53), Point(76,120), Point(-700,-700)};
    Point combo2LowHit1[] = {Point(84,53), Point(165,120), Point(-700,-700)};
    Point combo2LowHit2[] = {Point(173,66), Point(278,120), Point(-700,-700)};
    Point combo2LowHit3[] = {Point(286,66), Point(388,120), Point(-700,-700)};

    combo2Frames[0] = new Sprite(Global::GaneshGaitondeAnimations[combo2G], Point(0,0), Point(76,120),
                              Point(33,120),combo2HighHit,combo2LowHit,0, 0);
    combo2Frames[1] = new Sprite(Global::GaneshGaitondeAnimations[combo2G], Point(84,0), Point(165,120),
                              Point(122,120),combo2HighHit1,combo2LowHit1,0, 0);
    combo2Frames[2] = new Sprite(Global::GaneshGaitondeAnimations[combo2G], Point(173,0), Point(278,120),
                              Point(184,120),0,combo2LowHit2,0, 0);
    combo2Frames[3] = new Sprite(Global::GaneshGaitondeAnimations[combo2G], Point(286,0), Point(388,120),
                              Point(298,120),0,combo2LowHit3,0, 0);

    Sprite** getHitStandingLowFrames = new Sprite*[4];

    Point getHitStandingLowHigh[] = {Point(8,6),Point(51,53),Point(-700,-700)};
    Point getHitStandingLowHigh1[] = {Point(100,13),Point(149,50),Point(-700,-700)};
    Point getHitStandingLowHigh2[] = {Point(198,11),Point(251,50),Point(-700,-700)};
    Point getHitStandingLowHigh3[] = {Point(297,10),Point(348,51),Point(-700,-700)};

    Point getHitStandingLowLow[] = {Point(5,53),Point(55,87),Point(-700,-700)};
    Point getHitStandingLowLow1[] = {Point(101,50),Point(151,85),Point(-700,-700)};
    Point getHitStandingLowLow2[] = {Point(207,50),Point(246,48),Point(-700,-700)};
    Point getHitStandingLowLow3[] = {Point(307,51),Point(346,79),Point(-700,-700)};

    getHitStandingLowFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[getHitStandingLowG],
                                Point(0,0),Point(93,92),Point(16,91),getHitStandingLowHigh,
                                            getHitStandingLowLow,0,0);
    getHitStandingLowFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[getHitStandingLowG],
                                Point(93,0),Point(191,92),Point(118,91),getHitStandingLowHigh1,
                                            getHitStandingLowLow1,0,0);
    getHitStandingLowFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[getHitStandingLowG],
                                Point(191,0),Point(293,92),Point(232,91),getHitStandingLowHigh2,
                                            getHitStandingLowLow2,0,0);
    getHitStandingLowFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[getHitStandingLowG],
                                Point(293,0),Point(387,92),Point(332,91),getHitStandingLowHigh3,
                                            getHitStandingLowLow3,0,0);

    Sprite** knockDownFrames = new Sprite*[7];

    knockDownFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[knockDownG], Point(0,0), Point(72,109),
                              Point(13,109),0,0,0, 0);
    knockDownFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[knockDownG], Point(77,0), Point(168,109),
                              Point(94,109),0,0,0, 0);
    knockDownFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[knockDownG], Point(176,0), Point(270,109),
                              Point(219,109),0,0,0, 0);
    knockDownFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[knockDownG], Point(277,0), Point(408,109),
                              Point(376,109),0,0,0, 0);
    knockDownFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[knockDownG], Point(416,0), Point(543,109),
                              Point(541,109),0,0,0, 0);
    knockDownFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[knockDownG], Point(550,0), Point(653,109),
                              Point(654,109),0,0,0, 0);
    knockDownFrames[6] = new Sprite(Global::GaneshGaitondeAnimations[knockDownG], Point(416,0), Point(543,109),
                              Point(541,109),0,0,0, 0);


    Sprite** victoryFrames = new Sprite*[10];

    victoryFrames[0] = new Sprite(Global::GaneshGaitondeAnimations[victoryG], Point(0,0), Point(94,127),
                              Point(13,127),0,0,0, 0);
    victoryFrames[1] = new Sprite(Global::GaneshGaitondeAnimations[victoryG], Point(101,0), Point(153,127),
                              Point(116,127),0,0,0, 0);
    victoryFrames[2] = new Sprite(Global::GaneshGaitondeAnimations[victoryG], Point(160,0), Point(212,127),
                              Point(178,127),0,0,0, 0);
    victoryFrames[3] = new Sprite(Global::GaneshGaitondeAnimations[victoryG], Point(219,0), Point(270,127),
                              Point(238,127),0,0,0, 0);
    victoryFrames[4] = new Sprite(Global::GaneshGaitondeAnimations[victoryG], Point(278,0), Point(329,127),
                              Point(293,127),0,0,0, 0);
    victoryFrames[5] = new Sprite(Global::GaneshGaitondeAnimations[victoryG], Point(336,0), Point(393,127),
                              Point(356,127),0,0,0, 0);
    victoryFrames[6] = new Sprite(Global::GaneshGaitondeAnimations[victoryG], Point(400,0), Point(461,127),
                              Point(422,127),0,0,0, 0);
    victoryFrames[7] = new Sprite(Global::GaneshGaitondeAnimations[victoryG], Point(468,0), Point(534,127),
                              Point(495,127),0,0,0, 0);
    victoryFrames[8] = new Sprite(Global::GaneshGaitondeAnimations[victoryG], Point(539,0), Point(634,127),
                              Point(577,127),0,0,0, 0);
    victoryFrames[9] = new Sprite(Global::GaneshGaitondeAnimations[victoryG], Point(643,0), Point(736,127),
                              Point(681,127),0,0,0, 0);


    allAnimations = new Sprite**[numElementsG];
    allAnimations[stanceG] = stanceFrames;
    allAnimations[crouchG] = crouchFrames;
    allAnimations[guardG] = guardFrames;
    allAnimations[crouchGuardG] = crouchGuardFrames;
    allAnimations[jumpG] = jumpFrames;
    allAnimations[crouchJabG] = crouchJabFrames;
    allAnimations[shortKickG] = shortKickFrames;
    allAnimations[strongJabG] = strongJabFrames;
    allAnimations[walkForwardG] = walkForwardFrames;
    allAnimations[walkBackwardG] = walkBackwardFrames;
    allAnimations[crouchKickG] = crouchKickFrames;
    allAnimations[crouchTurnG] = crouchTurnFrames;
    allAnimations[jumpJabG] = jumpJabFrames;
    allAnimations[jumpKickG] = jumpKickFrames;
    allAnimations[crouchKick1G] = crouchKick1Frames;
    allAnimations[combo1G] = combo1Frames;
    allAnimations[combo2G] = combo2Frames;
    allAnimations[getHitCrouchG] = getHitCrouchFrames;
    allAnimations[getHitStandingHighG] = getHitStandingHighFrames;
    allAnimations[getHitStandingLowG] = getHitStandingLowFrames;
    allAnimations[knockDownG] = knockDownFrames;
    allAnimations[victoryG] = victoryFrames;
    currentAnimation = -1;
    currentAnimationInd = -1;
    Stance();
}

GaneshGaitonde::~GaneshGaitonde()
{
    delete [] allAnimations;
}


void GaneshGaitonde::RecieveInput(Uint32 type, int key)
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
                else if(state == sJumping && !movedOnJump)
                {
                    movedOnJump = true;
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
                else if(state == sJumping && !movedOnJump)
                {
                    movedOnJump = true;
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
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1G)
            {
                crouchKick1Status = crouchKick1RightG;
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
                else if(state == sJumping)
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
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1G)
            {
                crouchKick1Status = crouchKick1LeftG;
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
            if(currentAnimation == crouchKick1G)
            {
                Turn();
            }
            break;

        case iUp:
            if(negativeFrames == 0 && ifAcceptingInput)
            {
                if(state == sCrouching)
                {
                    movedOnJump = false;
                    Jump();
                }
                else if(state == sNormal)
                {
                    JumpFromStand();
                    movedOnJump = false;
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
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1G)
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
            else if(ifAcceptingInput && negativeFrames > 0 && currentAnimation == crouchKick1G)
            {
                crouchKick1Status = -1;
            }
            break;
        }
    }
}

Projectile* GaneshGaitonde::UpdateSprite()
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
        if((movement == mForward && !orientation) || (orientation && movement == mBackward))
        {
            position.x += 5;
        }
        else if((movement == mBackward && !orientation) || (orientation && movement == mForward))
        {
            position.x -= 5;
        }
    }

    currentAnimationInd++;
    if(currentAnimationInd / spread >= currentAnimationCap)
    {
        if(currentAnimation == victoryG || currentAnimation == knockDownG)
        {
            currentAnimationInd--;
            return 0;
        }
        if(currentAnimation == crouchKick1G)
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
                    if(currentAnimation == walkBackwardG)
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
    if(currentAnimation == jumpKickG && currentAnimationInd >= spread)
    {
        yVelocity = 0;
        position.y += 2;
//        yVelocity -= 10;
        position.x += 5*a[orientation];
    }
    if(currentAnimation == crouchKickG)
    {
        position.x += 3*a[orientation];
    }

    if(currentAnimationInd < 0)
    {
        currentAnimationInd = 0;
    }

    if(crouchKick1Status == crouchKick1LeftG)
    {
        position.x -= 5;
    }
    else if(crouchKick1Status == crouchKick1RightG)
    {
        position.x += 5;
    }

    if(currentAnimation == walkForwardG)
    {
        this->position.x += ((currentAnimationInd % spread) == 0 && currentAnimationInd > 0
                             && (currentAnimationInd / spread) <= 4) * 20
                              * (a[orientation])/* */;
    }
    else if(currentAnimation == walkBackwardG)
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
        if((state == sJumping && yVelocity >= 0) || currentAnimation == jumpKickG)
        {
            if(currentAnimation == jumpKickG)
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
//    nextSprite = allAnimations[crouchJabG][6];
    nextSprite->UpdateSprite(position, orientation);
    if(currentAnimation == combo1G && (currentAnimationInd / spread) == (currentAnimationCap - 1)
       && (currentAnimationInd % spread == 0))
    {
        Point t;
        SDL_Rect* r = nextSprite->GetDestRect();
        if(orientation)
        {
            t.x = r->x - 5;
        }
        else
        {
            t.x = r->x + r->w + 5;
        }
        t.y = r->y + (r->h * 13)/ 21;
        tempP = ProjectileFactory::createProjectile(projectileFire, t, orientation);
        currentAnimationInd = (currentAnimationInd / spread) * 70;
        spread = 70;
    }
    if(currentAnimation == combo2G && (currentAnimationInd / spread) == (currentAnimationCap - 1)
       && (currentAnimationInd % spread == 0))
    {
        Point t;
        SDL_Rect* r = nextSprite->GetDestRect();
        if(orientation)
        {
            t.x = r->x - 5;
        }
        else
        {
            t.x = r->x + r->w + 5;
        }
        t.y = r->y + (r->h);
        tempP = ProjectileFactory::createProjectile(projectileFire1, t, orientation);
        currentAnimationInd = (currentAnimationInd / spread) * 70;
        spread = 60;
        Global::superCount = spread;
    }
    return tempP;
}

void GaneshGaitonde::Render(SDL_Renderer* gRenderer)
{
    nextSprite->Render(gRenderer);
    healthBar->renderBar(gRenderer);
    superBar->renderBar(gRenderer);
//    SDL_SetRenderDrawColor(gRenderer, 0, 255 ,0 ,0);
//    SDL_RenderDrawPoint(gRenderer, position.x, position.y);
}


void GaneshGaitonde::Turn()
{
    countToTurn = 1;
}

void GaneshGaitonde::CrouchTurn()
{
    currentAnimation = crouchTurnG;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    countToTurn = negativeFrames;
}

void GaneshGaitonde::CrouckKick()
{
//    int a[] = {1,-1};
//    position.x += a[orientation]*75;
    hasDamaged = false;
    currentAnimation = crouchKickG;
    currentAnimationCap = 6;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    damage = 5;
}

void GaneshGaitonde::Jump()
{
    currentAnimation = jumpG;
    spread = 4 * Global::dF;
    currentAnimationInd = spread - 1;
    currentAnimationCap = 11;
    yVelocity = -7 * Global::dF;
    negativeFrames = 0;
}

void GaneshGaitonde::JumpFromStand()
{
    currentAnimation = jumpG;
    spread = 4 * Global::dF;
    currentAnimationInd = 2 * spread - 1;
    currentAnimationCap = 9;
    yVelocity = -7 * Global::dF;
    negativeFrames = 0;
}

void GaneshGaitonde::Jumping()
{
    currentAnimation = jumpG;
    currentAnimationCap = 10;
    spread = 1;
    currentAnimationInd = 9;
    negativeFrames = 0;
}

void GaneshGaitonde::Stance()
{
    currentAnimationInd = -1;
    currentAnimation = stanceG;
    currentAnimationCap = 7;
    spread = 9 * Global::dF;
    negativeFrames = 0;
}

void GaneshGaitonde::Guarding()
{
    currentAnimation = guardG;
    currentAnimationCap = 1;
    spread = 1;
    currentAnimationInd = 0;
    negativeFrames = 0;
}

void GaneshGaitonde::CrouchGuarding()
{
    currentAnimation = crouchGuardG;
    currentAnimationCap = 1;
    spread = 1;
    currentAnimationInd = 0;
    negativeFrames = 0;
}

void GaneshGaitonde::WalkForward()
{
    currentAnimation = walkForwardG;
    currentAnimationInd = -1;
    currentAnimationCap = 8;
    spread = 4 * Global::dF;
    negativeFrames = 0;
}

void GaneshGaitonde::WalkBackward(bool justIn)
{
    currentAnimation = walkBackwardG;
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

void GaneshGaitonde::Crouching()
{
    currentAnimation = crouchG;
    currentAnimationCap = 2;
    spread = 1;
    currentAnimationInd = 1;
    negativeFrames = 0;
}

void GaneshGaitonde::Crouch()
{
    currentAnimation = crouchG;
    currentAnimationCap = 2;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void GaneshGaitonde::StrongJab()
{
    hasDamaged = false;
    currentAnimation = strongJabG;
    currentAnimationInd = -1;
    currentAnimationCap = 8;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    damage = 5;
}

void GaneshGaitonde::CrouchLightJab()
{
    hasDamaged = false;
    currentAnimation = crouchJabG;
    currentAnimationInd = -1;
    currentAnimationCap = 11;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    damage = 5;
}

void GaneshGaitonde::ShortKick()
{
    hasDamaged = false;
    damage = 5;
    currentAnimation = shortKickG;
    currentAnimationCap = 11;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void GaneshGaitonde::JumpJab()
{
        hasDamaged = false;
    damage = 5;
    currentAnimation = jumpJabG;
    currentAnimationCap = 8;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void GaneshGaitonde::JumpKick()
{    hasDamaged = false;
    damage = 5;
//    int a[] = {1,-1};
//    position.x += a[orientation]*100;
//    position.y += a[orientation]*100;
    currentAnimation = jumpKickG;
    currentAnimationCap = 5;
    currentAnimationInd = -1;
    spread = 20 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void GaneshGaitonde::CrouchKick1()
{    hasDamaged = false;
    damage = 5;
    currentAnimation = crouchKick1G;
    currentAnimationCap = 10;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void GaneshGaitonde::Combo1()
{
    currentAnimation = combo1G;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * (currentAnimationCap - 1) + 70;
}
void GaneshGaitonde::Combo2()
{
    super = 0;
    superBar->emptyBar();
    currentAnimation = combo2G;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
    Global::superCount = negativeFrames * 2;
}

void GaneshGaitonde::GetHitCrouch(int power)
{
    currentAnimation = getHitCrouchG;
    currentAnimationCap = 3;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void GaneshGaitonde::GetHitStandingHigh(int power)
{
    currentAnimation = getHitStandingHighG;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void GaneshGaitonde::GetHitStandingLow(int power)
{
    currentAnimation = getHitStandingLowG;
    currentAnimationCap = 4;
    currentAnimationInd = -1;
    spread = power * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

void GaneshGaitonde::KnockDown()
{
    currentAnimation = knockDownG;
    currentAnimationCap = 7;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}
void GaneshGaitonde::Victory()
{
    currentAnimation = victoryG;
    currentAnimationCap = 10;
    currentAnimationInd = -1;
    spread = 8 * Global::dF;
    negativeFrames = spread * currentAnimationCap;
}

bool GaneshGaitonde::HandleHit(int hitType, int damage, int frames)
{
    if(cHultHult == hitType || hitType == cLowLow || hitType == cHighHigh
       || cHighLow == hitType || hitType == cLowHigh)
    {
        PushBack(2);
        return false;
    }
    if(cHultHigh == hitType)
    {
        if(currentAnimation == guardG)
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
        if(currentAnimation == crouchGuardG)
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
