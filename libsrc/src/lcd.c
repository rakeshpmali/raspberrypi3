#include "lcd.h"

//Function Definitions
int lcdInit()
{
    //Initialize the LCD pins
    //LCD control pins
    pinInit(LCD_RW, GPIO_DIR_OUT);
    pinInit(LCD_RS, GPIO_DIR_OUT);
    pinInit(LCD_EN, GPIO_DIR_OUT);
    //LCD data pins - higher nibble (4-bit mode)
    pinInit(LCD_D7, GPIO_DIR_OUT);
    pinInit(LCD_D6, GPIO_DIR_OUT);
    pinInit(LCD_D5, GPIO_DIR_OUT);
    pinInit(LCD_D4, GPIO_DIR_OUT);

    //wake up
    DELAY_MILLI_SECONDS(15);
    lcdSendCmd4Bit(LCD_STARTUP_INIT);
    DELAY_MILLI_SECONDS(15);
    lcdSendCmd4Bit(LCD_4BIT_INIT);          // 4-bit mode 
    DELAY_MILLI_SECONDS(15);

    lcdSendCmd4Bit(_4BIT_2LINE_5x7DOTS);    //N = 1 (2 line display) F = 0 (5x8 characters)
    lcdSendCmd4Bit(DISP_OFF_CURS_OFF);      //Display on/off control D=0,C=0, B=0 
    lcdSendCmd4Bit(CLEAR_DISP);             //Clear Display
    lcdSendCmd4Bit(ENTRY_MODE);             //Entry mode set - I/D = 1 (increment cursor) & S = 0 (no shift) 
    lcdSendCmd4Bit(DISP_ON_CURS_OFF);       //Display on/off control. D = 1, C and B = 0. (Cursor and blink, last two bits)  
}

int lcdSendData4Bit(int iCmdCode, int iRS_State)
{
    pinWrite(LCD_RS, iRS_State);
    //printBinary(iCmdCode);
    //printf("\nlcdSendData4Bit(%d%d%d%d%d%d%d%d)\n", ((iCmdCode & (1<<7))>>7), ((iCmdCode & (1<<6))>>6), ((iCmdCode & (1<<5))>>5), ((iCmdCode & (1<<4))>>4), ((iCmdCode & (1<<3))>>3), ((iCmdCode & (1<<2))>>2), ((iCmdCode & (1<<1))>>1), ((iCmdCode & (1<<0))>>0));
    pinWrite(LCD_D4, ((iCmdCode & (1<<4))>>4));
    pinWrite(LCD_D5, ((iCmdCode & (1<<5))>>5));
    pinWrite(LCD_D6, ((iCmdCode & (1<<6))>>6));
    pinWrite(LCD_D7, ((iCmdCode & (1<<7))>>7));

    pinWrite(LCD_EN, GPIO_LOW);
    DELAY_MICRO_SECONDS(1);
    pinWrite(LCD_EN, GPIO_HIGH);
    DELAY_MICRO_SECONDS(1);
    pinWrite(LCD_EN, GPIO_LOW);
    DELAY_MICRO_SECONDS(1);

    pinWrite(LCD_D4, ((iCmdCode & (1<<0))>>0));
    pinWrite(LCD_D5, ((iCmdCode & (1<<1))>>1));
    pinWrite(LCD_D6, ((iCmdCode & (1<<2))>>2));
    pinWrite(LCD_D7, ((iCmdCode & (1<<3))>>3));

    pinWrite(LCD_EN, GPIO_LOW);
    DELAY_MICRO_SECONDS(1);
    pinWrite(LCD_EN, GPIO_HIGH);
    DELAY_MICRO_SECONDS(1);
    pinWrite(LCD_EN, GPIO_LOW);

    DELAY_MILLI_SECONDS(1); //LCD busy - wait
    //TODO: check busy flag here
}

int lcdDisplayText(char *pchText)
{
    while(*pchText)
    {
        if(*pchText == '\n')
        {
            if(gi_CURRENT_ROW <= 3)
                ++gi_CURRENT_ROW;
            else
                gi_CURRENT_ROW = 1;

            lcdGoToXY(gi_CURRENT_ROW,0);
            ++pchText;
        } else {    
            lcdSendText4Bit(*pchText++);
        }
    }
    
    return 0;
}

int lcdGoToXY(int iRow, int iColumn)
{
    int iAddr = 0;
    switch(iRow)
    {
        case 1: iAddr = LCD_LINE1_START_ADDR; gi_CURRENT_ROW = 1; break; 
        case 2: iAddr = LCD_LINE2_START_ADDR; gi_CURRENT_ROW = 2; break; 
        case 3: iAddr = LCD_LINE3_START_ADDR; gi_CURRENT_ROW = 3; break; 
        case 4: iAddr = LCD_LINE4_START_ADDR; gi_CURRENT_ROW = 4; break; 
        default: gi_CURRENT_ROW = 1; printf("\nERROR: lcdGoToXY(): Invalid X &/or Y position!"); 
    }
   
    if (iColumn) 
        iAddr += --iColumn;
    //printf("\nAddress = %X\n", iAddr);
    
    lcdGoToAddr(iAddr);
    
    return 0;
}

int lcdGoToAddr(int iAddr)
{
    int iCmd = 0x80|iAddr;
    lcdSendCmd4Bit(iCmd);
    return 0;
}

int lcdClear()
{
    lcdSendCmd4Bit(CLEAR_DISP);
    return 0;
}

void printBinary(int n)
{
    printf("\n\n");
    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");

        n >>= 1;
    }
    printf("\n");
}
