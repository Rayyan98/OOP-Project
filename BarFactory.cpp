#include "BarFactory.h"
#include "HealthBar.h"
#include "ComboBar.h"

enum{barHealth, barCombo};

Bars* BarFactory::createBar(int barType, bool player2)
{
    if(barType == barHealth)
    {
        return new HealthBar(player2);
    }
    else if(barType == barCombo)
    {
        return new ComboBar(player2);
    }
    return 0;
}
