#include "gpio.h"

#define LCD_ROWS (4)
#define LCD_COLUMNS (20)

//LCD control pins
#define LCD_RW (P8_6)
#define LCD_RS (P8_8)
#define LCD_EN (P8_10)
//LCD data pins - higher nibble
#define LCD_D7 (P8_12)
#define LCD_D6 (P8_14)
#define LCD_D5 (P8_16)
#define LCD_D4 (P8_18)
/*
//LCD data pins - lower nibble
#define LCD_D3 (P8_20)
#define LCD_D2 (P8_22)
#define LCD_D1 (P8_24)
#define LCD_D0 (P8_26)
*/

//LCD Commands
#define _8BIT_1LINE_5x7DOTS     (0x30)  //8-bit, 1 Line, 5x7 Dots
#define _8BIT_2LINE_5x7DOTS     (0x38)  //8-bit, 2 Line, 5x7 Dots
#define _4BIT_1LINE_5x7DOTS     (0x20)  //4-bit, 1 Line, 5x7 Dots
#define _4BIT_2LINE_5x7DOTS     (0x28)  //4-bit, 2 Line, 5x7 Dots
#define ENTRY_MODE              (0x06)  //Entry Mode
#define DISP_OFF_CURS_OFF       (0x08)  //Display off Cursor off (clearing display without clearing DDRAM content)
#define DISP_ON_CURS_ON         (0x0E)  //Display on Cursor on
#define DISP_ON_CURS_OFF        (0x0C)  //Display on Cursor off
#define DISP_ON_CURS_BLINK      (0x0F)  //Display on Cursor blinking
#define SHIFT_DISP_LEFT         (0x18)  //Shift entire display left
#define SHIFT_DISP_RIGHT        (0x1C)  //Shift entire display right
#define MOVE_CURS_LEFT          (0x10)  //Move cursor left by one character
#define MOVE_CURS_RIGHT         (0x14)  //Move cursor right by one character
#define CLEAR_DISP              (0x01)  //Clear Display (also clear DDRAM content)
#define LCD_STARTUP_INIT        (0x33)  //Startup initialization sequence
#define LCD_4BIT_INIT           (0x32)  //4-Bit Mode Init
#define LCD_8BIT_INIT           (0x33)  //8-Bit Mode Init

//LCD Line Addresses
#define LCD_LINE1_START_ADDR    (0x00)  //Line 1 : 0x00 to 0x13
#define LCD_LINE1_END_ADDR      (0x13)  

#define LCD_LINE2_START_ADDR    (0x40)  //Line 2 : 0x40 to 0x53   
#define LCD_LINE2_END_ADDR      (0x53)  

#define LCD_LINE3_START_ADDR    (0x14)  //Line 3 : 0x14 to 0x27
#define LCD_LINE3_END_ADDR      (0x27)  

#define LCD_LINE4_START_ADDR    (0x54)  //Line 4 : 0x54 to 0x67
#define LCD_LINE4_END_ADDR      (0x67)  

//API functions
#define lcdSendCmd4Bit(x)       lcdSendData4Bit(x,GPIO_LOW)
#define lcdSendText4Bit(x)      lcdSendData4Bit(x,GPIO_HIGH)

//Function Declaration
int lcdInit();
int lcdSendData4Bit(int iCmdCode, int iRS_State);
int lcdDisplayText(char *pchText);
int lcdGoToXY(int iRow, int iColumn);
int lcdGoToAddr(int iAddr);
int lcdClear();
void printBinary(int n);

//Global Variables
static int gi_CURRENT_ROW = 1; // keeps track of current row
