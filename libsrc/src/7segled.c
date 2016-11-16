#include "7segled.h"

int init7SegLedDisplay()
{
    //Initialise GPIO pins for out operation
    if (0 != exportPin(LED_a)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_a, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    if (0 != exportPin(LED_b)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_b, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    if (0 != exportPin(LED_c)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_c, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    if (0 != exportPin(LED_d)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_d, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    if (0 != exportPin(LED_e)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_e, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    if (0 != exportPin(LED_f)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_f, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    if (0 != exportPin(LED_g)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_g, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    //all segments OFF
    if (0 != setPinValue(LED_a, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_b, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_HIGH))
        exit(EXIT_FAILURE);

    return 0;
}

int displayChar(const char achChar)
{
    clearDisplay();

    switch(achChar)
    {
        case CHAR_0:
        case CHAR_O:
            {
                displayNum_0();
                break;
            }

        case CHAR_1:
            {
                displayNum_1();
                break;
            }

        case CHAR_2:
            {
                displayNum_2();
                break;
            }

        case CHAR_3:
            {
                displayNum_3();
                break;
            }

        case CHAR_4:
            {
                displayNum_4();
                break;
            }

        case CHAR_5:
        case CHAR_S:
            {
                displayNum_5();
                break;
            }

        case CHAR_6:
            {
                displayNum_6();
                break;
            }

        case CHAR_7:
            {
                displayNum_7();
                break;
            }

        case CHAR_8:
            {
                displayNum_8();
                break;
            }

        case CHAR_9:
            {
                displayNum_9();
                break;
            }

        case CHAR_A:
            {
                displayAlpha_A();
                break;
            }

        case CHAR_b:
            {
                displayAlpha_b();
                break;
            }
        
        case CHAR_C:
            {
                displayAlpha_C();
                break;
            }

        case CHAR_c:
            {
                displayAlpha_c();
                break;
            }
        
        case CHAR_d:
            {
                displayAlpha_d();
                break;
            }
        
        case CHAR_E:
            {
                displayAlpha_E();
                break;
            }
        
        case CHAR_F:
            {
                displayAlpha_F();
                break;
            }
        
        case CHAR_H:
            {
                displayAlpha_H();
                break;
            }

        case CHAR_h:
            {
                displayAlpha_h();
                break;
            }

        case CHAR_J:
            {
                displayAlpha_J();
                break;
            }

        case CHAR_L:
            {
                displayAlpha_L();
                break;
            }

        case CHAR_o:
            {
                displayAlpha_o();
                break;
            }

        case CHAR_P:
            {
                displayAlpha_P();
                break;
            }

        /*case CHAR_S:
            {
                displayAlpha_S();
                break;
            }
        */
        case CHAR_U:
            {
                displayAlpha_U();
                break;
            }
        
        case CHAR_u:
            {
                displayAlpha_u();
                break;
            }
        
        default:
            {
                printf("\nERROR: displayChar(): %c Invalid or Un-Supported Character !", achChar);
            /*  CHAR_a ('a')    CHAR_B ('B')    CHAR_D ('D')    CHAR_e ('e')    CHAR_f ('f')    CHAR_G ('G')    CHAR_g ('g')
                CHAR_I ('I')    CHAR_i ('i')    CHAR_j ('j')    CHAR_K ('K')    CHAR_k ('k')    CHAR_l ('l')    CHAR_M ('M')
                CHAR_m ('m')    CHAR_N ('N')    CHAR_n ('n')    CHAR_p ('p')    CHAR_Q ('Q')    CHAR_q ('q')    CHAR_R ('R')    
                CHAR_r ('r')    CHAR_s ('s')    CHAR_T ('T')    CHAR_t ('t')    CHAR_V ('V')    CHAR_v ('v')    CHAR_W ('W')    
                CHAR_w ('w')    CHAR_X ('X')    CHAR_x ('x')    CHAR_Y ('Y')    CHAR_y ('y')    CHAR_Z ('Z')    CHAR_z ('z')    
            */
            }
    }

    return 0;
}

int clearDisplay()
{
    //all segments OFF
    if (0 != setPinValue(LED_a, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_b, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_HIGH))
        exit(EXIT_FAILURE);

    return 0;
}

int displayNum_0()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayNum_1()
{
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayNum_2()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayNum_3()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayNum_4()
{
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayNum_5()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayNum_6()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayNum_7()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayNum_8()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayNum_9()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayAlpha_A()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayAlpha_b()
{
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_C()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int displayAlpha_c()
{
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_d()
{
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_E()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_F()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_H()
{
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_h()
{
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_J()
{
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_L()
{
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_o()
{
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_P()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

/*int displayAlpha_S()
{
    if (0 != setPinValue(LED_a, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_g, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}*/

int displayAlpha_U()
{
    if (0 != setPinValue(LED_b, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_f, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int displayAlpha_u()
{
    if (0 != setPinValue(LED_c, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_d, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_e, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}
