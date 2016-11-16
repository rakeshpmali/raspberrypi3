#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GPIO_DIR_OUT    ("out")
#define GPIO_DIR_IN     ("in")
#define GPIO_HIGH       (1)
#define GPIO_LOW        (0)

#define MAX_PIN_COUNT   (28)
#define PORT_PIN_LENGTH (6)

#define J8_3   ("J8_3")
//#define J8_4   ("J8_4")
#define J8_5   ("J8_5")
//#define J8_6   ("J8_6")
#define J8_7   ("J8_7")
#define J8_8   ("J8_8")
//#define J8_9   ("J8_9")
#define J8_10   ("J8_10")
#define J8_11   ("J8_11")
#define J8_12   ("J8_12")
#define J8_13   ("J8_13")
//#define J8_14   ("J8_14")
#define J8_15   ("J8_15")
#define J8_16   ("J8_16")
//#define J8_17   ("J8_17")
#define J8_18   ("J8_18")
#define J8_19   ("J8_19")
//#define J8_20   ("J8_20")
#define J8_21   ("J8_21")
#define J8_22   ("J8_22")
#define J8_23   ("J8_23")
#define J8_24   ("J8_24")
//#define J8_25   ("J8_25")
#define J8_26   ("J8_26")
#define J8_27   ("J8_27")
#define J8_28   ("J8_28")
#define J8_29   ("J8_29")
//#define J8_30   ("J8_30")
#define J8_31   ("J8_31")
#define J8_32   ("J8_32")
#define J8_33   ("J8_33")
//#define J8_34   ("J8_34")
#define J8_35   ("J8_35")
#define J8_36   ("J8_36")
#define J8_37   ("J8_37")
#define J8_38   ("J8_38")
//#define J8_39   ("J8_39")
#define J8_40   ("J8_40")

#define DELAY_SECONDS(d) (usleep(d*1000000))
#define DELAY_MILLI_SECONDS(d) (usleep(d*1000))
#define DELAY_MICRO_SECONDS(d) (usleep(d))

// structure having pin details
typedef struct
{
    char chPin[PORT_PIN_LENGTH];          // BBB PIN. e.g. P8.39
    int iPin;               // pin = gpio base * 32 + pin number
                            // e.g. for P8.39, mode 7 is GPIO2_12 then, pin = 2 * 32 + 12 = 76
} PIN;

// Table containing details of all pins
static PIN PIN_TABLE[MAX_PIN_COUNT] = 
{
    { J8_3, /*GPIO2*/ 2 },
    { J8_5, /*GPIO3*/ 3 },
    { J8_7, /*GPIO4*/ 4 },
    { J8_8, /*GPIO14*/ 14 },
    { J8_10, /*GPIO15*/ 15 },
    { J8_11, /*GPIO17*/ 17 },
    { J8_12, /*GPIO18*/ 18 },
    { J8_13, /*GPIO27*/ 27 },
    { J8_15, /*GPIO22*/ 22 },
    { J8_16, /*GPIO23*/ 23 },
    { J8_18, /*GPIO24*/ 23 },
    { J8_19, /*GPIO10*/ 10 },
    { J8_21, /*GPIO9*/ 9 },
    { J8_22, /*GPIO25*/ 25 },
    { J8_23, /*GPIO11*/ 11 },
    { J8_24, /*GPIO8*/ 8 },
    { J8_26, /*GPIO7*/ 7 },
    { J8_27, /*GPIO0*/ 0 },
    { J8_28, /*GPIO1*/ 1 },
    { J8_29, /*GPIO5*/ 5 },
    { J8_31, /*GPIO6*/ 6 },
    { J8_32, /*GPIO12*/ 12 },
    { J8_33, /*GPIO13*/ 13 },
    { J8_35, /*GPIO19*/ 19 },
    { J8_36, /*GPIO16*/ 16 },
    { J8_37, /*GPIO26*/ 26 },
    { J8_38, /*GPIO20*/ 20 },
    { J8_40, /*GPIO21*/ 21 }
};

// Function Declerations
//library functions (API)
int pinInit(char *pchPin, char *pchDir);
int pinWrite(char *pchPin, int iValue);
int pinRead(char *pchPin, int *piValue);

//internal functions
int getPinFromTable(char *pchPin);
int exportPin(char *pchPin);
int setPinDirection(char *pchPin, char *pchDir);
int setPinValue(char *pchPin, int iValue);
int getPinValue(char *pchPin, int *piValue);
/*obsolete
int setPinState(char *pchPin, char *pchMode);
*/

