#include "7segled.h"

void main(int argc, char **argv)
{
    int i = 0;
    char chNumAlpha[] = {CHAR_0, CHAR_1, CHAR_2, CHAR_3, CHAR_4, CHAR_5,
                         CHAR_6, CHAR_7, CHAR_8, CHAR_9, CHAR_A, CHAR_b,
                         CHAR_C, CHAR_c, CHAR_d, CHAR_E, CHAR_F, CHAR_H,
                         CHAR_h, CHAR_J, CHAR_L, CHAR_o, CHAR_P, CHAR_S,
                         CHAR_U, CHAR_u};

    if(0 != init7SegLedDisplay())
        exit(EXIT_FAILURE);

    while(1)
    {  
        displayChar(chNumAlpha[i]);
        DELAY_MILLI_SECONDS(900);

        i++;
        if(i == 26)
            i = 0;
    }
}
