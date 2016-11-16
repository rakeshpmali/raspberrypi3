#include "lcd.h"

int lcdScrollText(char *pchText, int iDelayMilliSec, int iCount);

void main(int argc, char **argv)
{
    lcdInit();

    lcdDisplayText("***********\nBeagle Bone\n***********");
    DELAY_SECONDS(5);

    lcdClear();
    lcdGoToXY(1,5);
    lcdDisplayText("Welcome");
    lcdGoToXY(2,5);
    lcdDisplayText("Rakesh");
    lcdGoToXY(3,5);
    lcdDisplayText("Mali");
    DELAY_SECONDS(5);
        
    lcdClear();
    lcdGoToXY(3,0);
    lcdScrollText("<<Scroll>>", 100, 10);
}

int lcdScrollText(char *pchText, int iDelayMilliSec, int iCount)
{
    int i = 0;
    lcdDisplayText(pchText);
    while(iCount)
    {
        for(i=0; i<(LCD_COLUMNS-strlen(pchText)); i++)
        {
            lcdSendCmd4Bit(SHIFT_DISP_RIGHT);
            DELAY_MILLI_SECONDS(iDelayMilliSec);
        }
        for(i=0; i<(LCD_COLUMNS-strlen(pchText)); i++) 
        {
            lcdSendCmd4Bit(SHIFT_DISP_LEFT);
            DELAY_MILLI_SECONDS(iDelayMilliSec);
        }
        
        iCount--;
    }
    return 0;
}


