#include "gpio.h"

// ledBlink.o P3_39 1000 10
void main(int argc, char **argv)
{
    int iMicroSecs = 0, iCount = 0;
    char *pchPin = NULL;
    
    if (argc == 4)
    {
        asprintf(&pchPin, "%s", argv[1]);
        iMicroSecs = strtol(argv[2], NULL, 10) * 1000;
        iCount = strtol(argv[3], NULL, 10);
    } else {
        printf("\nInvalid Arguments ! Defaulting to: \nPort = J8_7 \nBlink Rate = 1000 ms\nCount = 10\n");
        asprintf(&pchPin, "%s", J8_7);
        iMicroSecs = 1000000;
        iCount = 10;
    }
    
    if (0 != pinInit(pchPin, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);
    
    int i = 0;
    for (i = 0; i < iCount; i++) {
        if (0 != pinWrite(pchPin, GPIO_HIGH))
            exit(EXIT_FAILURE);
        usleep(iMicroSecs);
        if (0 != pinWrite(pchPin, GPIO_LOW))
            exit(EXIT_FAILURE);
        usleep(iMicroSecs);
    }
}

