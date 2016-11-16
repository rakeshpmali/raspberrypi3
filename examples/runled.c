#include "gpio.h"

// runled.o 1000 10 1
void main(int argc, char **argv)
{
    int iMicroSecs = 0, iCount = 0, iPattern = 1, i = 0;

    //check user inputs
    if (argc == 4)  //valid inputs form user
    {
        iMicroSecs = strtol(argv[1], NULL, 10) * 1000;
        iCount = strtol(argv[2], NULL, 10);
        iPattern = strtol(argv[3], NULL, 10);
        
    } else {        //invalid inputs, use default values
        printf("\nNo/Invalid Arguments ! Running Default:");
        iMicroSecs = 1000000;
        iCount = 50;
        iPattern = 1;
        printf("\nBlink Rate = %d ms\nCount = %d\nPattern = %d\n", iMicroSecs, iCount, iPattern);
    }

    //Initialise GPIO pins for out operation
    //if (0 != setPinMode(P8_32, PIN_MODE_DEFAULT))
    //    exit(EXIT_FAILURE);
    if (0 != exportPin(P8_32)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(P8_32, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);
    
    //if (0 != setPinMode(P8_33, PIN_MODE_DEFAULT))
    //    exit(EXIT_FAILURE);
    if (0 != exportPin(P8_33)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(P8_33, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);
    
    //if (0 != setPinMode(P8_38, PIN_MODE_DEFAULT))
    //    exit(EXIT_FAILURE);
    if (0 != exportPin(P8_38)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(P8_38, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    //if (0 != setPinMode(P8_39, PIN_MODE_DEFAULT))
    //    exit(EXIT_FAILURE);
    if (0 != exportPin(P8_39)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(P8_39, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    switch(iPattern) {
        case 1:
            {
                for (i = 0; i < iCount; i++) {
                    if (0 != setPinValue(P8_32, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_33, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_38, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_39, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);
                    if (0 != setPinValue(P8_32, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_33, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_38, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_39, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);
                }
                
                break;
            }
            
        case 2:
            {
                for (i = 0; i < iCount; i++) {
                    // all led OFF
                    if (0 != setPinValue(P8_39, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_32, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_33, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_38, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);

                    // led 1 : ON
                    if (0 != setPinValue(P8_32, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);

                    // led 2 : ON
                    if (0 != setPinValue(P8_33, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);
                    
                    // led 3 : ON
                    if (0 != setPinValue(P8_38, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);
                    
                    // led 4 : ON
                    if (0 != setPinValue(P8_39, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);
                }
                
                break;
                
            }
        
        case 3:
            {
                for (i = 0; i < iCount; i++) {
                    // led 1 : ON
                    if (0 != setPinValue(P8_32, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);

                    // led 2 : ON, led 1 : OFF
                    if (0 != setPinValue(P8_33, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_32, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);
                    
                    // led 3 : ON, led 2 : OFF
                    if (0 != setPinValue(P8_38, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_33, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);
                    
                    // led 4 : ON, led 3 : OFF
                    if (0 != setPinValue(P8_39, GPIO_HIGH))
                        exit(EXIT_FAILURE);
                    if (0 != setPinValue(P8_38, GPIO_LOW))
                        exit(EXIT_FAILURE);
                    usleep(iMicroSecs);
                    
                    //led 4 : OFF
                    if (0 != setPinValue(P8_39, GPIO_LOW))
                        exit(EXIT_FAILURE);
                }
                
                break;
                
            }

        default:
            {
                //never reaches here
            }        
    }
}

