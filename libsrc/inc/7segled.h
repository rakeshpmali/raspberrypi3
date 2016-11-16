#include "gpio.h"

//led segments : mapped ports
#define LED_a (P8_31)
#define LED_b (P8_32)
#define LED_c (P8_33)
#define LED_d (P8_34)
#define LED_e (P8_35)
#define LED_f (P8_36)
#define LED_g (P8_37)

//numbers
#define CHAR_0 ('0')
#define CHAR_1 ('1')
#define CHAR_2 ('2')
#define CHAR_3 ('3')
#define CHAR_4 ('4')
#define CHAR_5 ('5')
#define CHAR_6 ('6')
#define CHAR_7 ('7')
#define CHAR_8 ('8')
#define CHAR_9 ('9')
//alphabets
#define CHAR_A ('A')
#define CHAR_a ('a') // not supported
#define CHAR_B ('B') // not supported
#define CHAR_b ('b')
#define CHAR_C ('C')
#define CHAR_c ('c')
#define CHAR_D ('D') // not supported  
#define CHAR_d ('d')
#define CHAR_E ('E')
#define CHAR_e ('e') // not supported
#define CHAR_F ('F')
#define CHAR_f ('f') // not supported
#define CHAR_G ('G') // not supported
#define CHAR_g ('g') // not supported
#define CHAR_H ('H')
#define CHAR_h ('h')
#define CHAR_I ('I') // not supported
#define CHAR_i ('i') // not supported
#define CHAR_J ('J')
#define CHAR_j ('j') // not supported
#define CHAR_K ('K') // not supported
#define CHAR_k ('k') // not supported
#define CHAR_L ('L')
#define CHAR_l ('l') // not supported
#define CHAR_M ('M') // not supported
#define CHAR_m ('m') // not supported
#define CHAR_N ('N') // not supported
#define CHAR_n ('n') // not supported
#define CHAR_O ('O') // displayed same as num 0
#define CHAR_o ('o')
#define CHAR_P ('P')
#define CHAR_p ('p') // not supported
#define CHAR_Q ('Q') // not supported
#define CHAR_q ('q') // not supported
#define CHAR_R ('R') // not supported
#define CHAR_r ('r') // not supported
#define CHAR_S ('S')
#define CHAR_s ('s') // not supported
#define CHAR_T ('T') // not supported
#define CHAR_t ('t') // not supported
#define CHAR_U ('U')
#define CHAR_u ('u')
#define CHAR_V ('V') // not supported
#define CHAR_v ('v') // not supported
#define CHAR_W ('W') // not supported
#define CHAR_w ('w') // not supported
#define CHAR_X ('X') // not supported
#define CHAR_x ('x') // not supported
#define CHAR_Y ('Y') // not supported
#define CHAR_y ('y') // not supported
#define CHAR_Z ('Z') // not supported
#define CHAR_z ('z') // not supported

int init7SegLedDisplay(void);
int displayChar(const char aiChar);
int clearDisplay(void);
int displayNum_0(void);
int displayNum_1(void);
int displayNum_2(void);
int displayNum_3(void);
int displayNum_4(void);
int displayNum_5(void);
int displayNum_6(void);
int displayNum_7(void);
int displayNum_8(void);
int displayNum_9(void);
int displayAlpha_A(void);
int displayAlpha_b(void);
int displayAlpha_C(void);
int displayAlpha_c(void);
int displayAlpha_d(void);
int displayAlpha_E(void);
int displayAlpha_F(void);
int displayAlpha_H(void);
int displayAlpha_h(void);
int displayAlpha_J(void);
int displayAlpha_L(void);
int displayAlpha_o(void);
int displayAlpha_P(void);
int displayAlpha_S(void);
int displayAlpha_U(void);


