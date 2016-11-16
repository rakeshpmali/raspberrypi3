#include "gpio.h"
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

// Function definitions
int pinInit(char *pchPin, char *pchDir)
{
    //first export the pin if not exported already
    if (0 != exportPin(pchPin)) 
        exit(EXIT_FAILURE);
    //set the pin direction (in / out)
    if (0 != setPinDirection(pchPin, pchDir))
        exit(EXIT_FAILURE);
    //if direction is out then initilise the pin with low value
    if( strncmp(pchDir, GPIO_DIR_OUT, strlen(GPIO_DIR_OUT)) ) {
        if (0 != setPinValue(pchPin, GPIO_LOW))
            exit(EXIT_FAILURE);
    }

    return 0;
}

int pinWrite(char *pchPin, int iValue)
{
    return (setPinValue(pchPin, iValue));
}

int pinRead(char *pchPin, int *piValue)
{
    return (getPinValue(pchPin, piValue));
}

int getPinFromTable(char *pchPin)
{
    int i = 0;
    
    for (i = 0; i < MAX_PIN_COUNT; i++) {
        if(!strncmp(pchPin, PIN_TABLE[i].chPin, strlen(pchPin)))
            return PIN_TABLE[i].iPin;
    }
    
    printf("\nERROR: getPinFromTable(): Invalid Pin Information: %s\n", pchPin);
    return -1;
}

/*obsolete function
int setPinState(char *pchPin, char *pchMode)
{
    char *pchFile = NULL, *pchCmd = NULL, chBuff[256];
    int iRet = 0;
    FILE *pfCmd = NULL;
    
    if (setuid(0)) {
printf("\nERROR: setPinMode(): Not a root user. Please run with root previleges (sudo) \n");
        return -1;
    }
    
    asprintf(&pchFile, "/sys/devices/ocp/ocp:%s_pinmux/state", pchPin);
    iRet = access(pchFile, F_OK);
    if (0 != iRet) {
        if (ENOENT == errno) { 
            printf("\nERROR: setPinMode(): (%d) File/Path does not exist: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        } else if (EACCES == errno) {
            printf("\nERROR: setPinMode(): (%d) File access failed, permission denied: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        } else {
            printf("\nERROR: setPinMode(): (%d) Unknown error: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        }
    }

    //echo default > /sys/devices/ocp/ocp:P8_39_pinmux/state
    asprintf(&pchCmd, "echo %s > %s", pchMode, pchFile);
    pfCmd = popen(pchCmd,"r");

    fclose(pfCmd);
    free(pchFile);
    free(pchCmd);
    return iRet;
}
*/

int exportPin(char *pchPin)
{
    char *pchFile, *pchCmd = NULL, chBuff[256];
    int iPin = 0, iRet = 0;
    FILE *pfCmd = NULL;
    
    if (setuid(0)) {
        printf("\nERROR: exportPin(): Not a root user. Please run with root previleges (sudo) \n");
        return -1;
    }

    iPin = getPinFromTable(pchPin);
    if (iPin == -1) {
        return iPin;
    }
     
    asprintf(&pchFile, "/sys/class/gpio/gpio%d", iPin);
    iRet = access(pchFile, F_OK);
    if (0 == iRet) {
        return iRet;
    }

    asprintf(&pchFile, "/sys/class/gpio/export");
    iRet = access(pchFile, F_OK);
    if (0 != iRet) {
        if (ENOENT == errno) { 
            printf("\nERROR: exportPin(): (%d) File/Path does not exist: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        } else if (EACCES == errno) {
            printf("\nERROR: exportPin(): (%d) File access failed, permission denied: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        } else {
            printf("\nERROR: exportPin(): (%d) Unknown error: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        }
    }
    //echo 76 > /sys/class/gpio/export
    asprintf(&pchCmd, "echo %d > %s", iPin, pchFile);
    pfCmd = popen(pchCmd,"r");

    fclose(pfCmd);
    free(pchCmd);
    free(pchFile);
    return iRet;
}

int setPinDirection(char *pchPin, char *pchDir)
{
    char *pchFile, *pchCmd = NULL, chBuff[256];
    int iPin = 0, iRet = 0;
    FILE *pfCmd = NULL;
    
    if (setuid(0)) {
        printf("\nERROR: setPinDirection(): Not a root user. Please run with root previleges (sudo) \n");
        return -1;
    }
    
    if( (!strncmp(pchDir, GPIO_DIR_IN, strlen(GPIO_DIR_IN))) && 
        (!strncmp(pchDir, GPIO_DIR_OUT, strlen(GPIO_DIR_OUT))) ) {
        printf("\nERROR: setPinDirection(): Invalid Pin Direction ! (it should be 'in' or 'out')\n");
        return -1;
    }

    iPin = getPinFromTable(pchPin);
    if (iPin == -1) {
        return iPin;
    }
    
    asprintf(&pchFile, "/sys/class/gpio/gpio%d/direction", iPin);
    iRet = access(pchFile, F_OK);
    if (0 != iRet) {
        if (ENOENT == errno) { 
            printf("\nERROR: setPinDirection(): (%d) File/Path does not exist: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        } else if (EACCES == errno) {
            printf("\nERROR: setPinDirection(): (%d) File access failed, permission denied: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        } else {
            printf("\nERROR: setPinDirection(): (%d) Unknown error: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        }
    }
    //echo out > /sys/class/gpio/gpio76/direction
    asprintf(&pchCmd, "echo %s > %s", pchDir, pchFile);
    pfCmd = popen(pchCmd,"r");
    
    fclose(pfCmd);
    free(pchFile);
    free(pchCmd);
    //usleep(500000);

    return iRet;
}

int setPinValue(char *pchPin, int iValue)
{
    char *pchFile = NULL, *pchCmd = NULL, chBuff[256];
    int iPin = 0, iRet = 0;
    FILE *pfCmd = NULL;

    if (setuid(0)) {
        printf("\nERROR: setPinValue(): Not a root user. Please run with root previleges (sudo) \n");
        return -1;
    }

    if((iValue != GPIO_LOW) && (iValue != GPIO_HIGH)) {
        printf("\nERROR: setPinValue(): Invalid Pin Value ! (it should be '0' or '1')) \n");
        return -1;
    }

    iPin = getPinFromTable(pchPin);
    if (iPin == -1) {
        return iPin;
    }

    asprintf(&pchFile, "/sys/class/gpio/gpio%d/value", iPin);
    iRet = access(pchFile, F_OK);
    if (0 != iRet) {
        if (ENOENT == errno) { 
            printf("\nERROR: setPinValue(): (%d) File/Path does not exist: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        } else if (EACCES == errno) {
            printf("\nERROR: setPinValue(): (%d) File access failed, permission denied: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        } else {
            printf("\nERROR: setPinValue(): (%d) Unknown error: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        }
    }
    //echo 1 > /sys/class/gpio/gpio76/value
    asprintf(&pchCmd, "echo %d > %s", iValue, pchFile);
    pfCmd = popen(pchCmd,"r");
    
    fclose(pfCmd);
    free(pchFile);
    free(pchCmd);
    return iRet;
}

int getPinValue(char *pchPin, int *piValue)
{
    char *pchFile = NULL, *pchCmd = NULL, chBuff[2];
    int iPin = 0, iRet = 0, iRead = 0;
    FILE *pFile = NULL;

    if (setuid(0)) {
        printf("\nERROR: getPinValue(): Not a root user. Please run with root previleges (sudo) \n");
        return -1;
    }
    
    iPin = getPinFromTable(pchPin);
    if (iPin == -1) {
        return iPin;
    }
    
    asprintf(&pchFile, "/sys/class/gpio/gpio%d/value", iPin);
    iRet = access(pchFile, F_OK);
    if (0 != iRet) {
        if (ENOENT == errno) { 
            printf("\nERROR: getPinValue(): (%d) File/Path does not exist: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        } else if (EACCES == errno) {
            printf("\nERROR: getPinValue(): (%d) File access failed, permission denied: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        } else {
            printf("\nERROR: getPinValue(): (%d) Unknown error: %s\n", errno, pchFile);
            free(pchFile);
            return -1;
        }
    }

    pFile = fopen(pchFile,"r"); 
    iRead = fread(&chBuff, 1, 1, pFile);

    if (iRead < 1) {
        printf("\nERROR: Failed to read file: %s\n", pchFile);
        fclose(pFile);
        return -1; 
    }

    *piValue = atoi(chBuff);
    
    fclose(pFile);
    return iRet;
}
