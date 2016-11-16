#include "gpio.h"

void main(int argc, char **argv)
{
    int iVal = 0, iRet = 0;
    char *pchGreenLedPin = NULL, *pchRedLedPin = NULL, *pchSwitchPin = NULL;
   
    if (argc == 4)
    {
        asprintf(&pchGreenLedPin,"%s", argv[1]);
        asprintf(&pchRedLedPin, "%s", argv[2]);
        asprintf(&pchSwitchPin, "%s", argv[3]);
    } else {
        printf("\nInvalid Arguments ! Defaulting to: \nGreen LED Port = P8_39 \nRed LED Port = P8_41 \nSwitch Port = P8_40\n");
        asprintf(&pchGreenLedPin, "%s", P8_39);
        asprintf(&pchRedLedPin, "%s", P8_41);
        asprintf(&pchSwitchPin, "%s", P8_40);
    }

    //Setup Switch Pin
    //if (0 != setPinMode(pchSwitchPin, PIN_MODE_DEFAULT))
    //    exit(EXIT_FAILURE);
    if (0 != exportPin(pchSwitchPin)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(pchSwitchPin, GPIO_DIR_IN))
        exit(EXIT_FAILURE);
    
    //Setup LED Pin
    // Green
    //if (0 != setPinMode(pchGreenLedPin, PIN_MODE_DEFAULT))
    //    exit(EXIT_FAILURE);
    if (0 != exportPin(pchGreenLedPin)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(pchGreenLedPin, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    // Red 
    //if (0 != setPinMode(pchRedLedPin, PIN_MODE_DEFAULT))
    //    exit(EXIT_FAILURE);
    if (0 != exportPin(pchRedLedPin)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(pchRedLedPin, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    int iFlag = 1; 
    while(1)
    {
        iRet = getPinValue(pchSwitchPin, &iVal);
        if (0 != iRet)
            exit(EXIT_FAILURE);
        usleep(10000);
        iRet = getPinValue(pchSwitchPin, &iVal);
        if (0 != iRet)
            exit(EXIT_FAILURE);

        if((iVal == 1) && (iFlag == 0)) {
            iFlag = 1;
            printf("Switch Pressed -> Green LED ON | Red LED OFF\n");
            if (0 != setPinValue(pchGreenLedPin, GPIO_HIGH))
                exit(EXIT_FAILURE);
            if (0 != setPinValue(pchRedLedPin, GPIO_LOW))
                exit(EXIT_FAILURE);
        } else if((iVal == 0) && (iFlag == 1)) {
            iFlag = 0;
            if (0 != setPinValue(pchGreenLedPin, GPIO_LOW))
                exit(EXIT_FAILURE);
            if (0 != setPinValue(pchRedLedPin, GPIO_HIGH))
                exit(EXIT_FAILURE);
            printf("Switch Released -> Green LED OFF | Red LED ON\n");
        }

        usleep(100000);
    }
}

