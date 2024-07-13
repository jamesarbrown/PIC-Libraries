#include "timing.h"

UpTime elapsedtime;
char heartbeatON = 0;

//Set to 0 unsigned long
void timingReset(void) {
    elapsedtime.msec = 0ul;
    elapsedtime.min = 0ul;
    elapsedtime.sec = 0ul;
    elapsedtime.hour = 0ul;
    return;
}

//Called by Interrupt handler eg TMR1_SetInterruptHandler(addMsec);
void addMsec(void) {
    //The interrupt is set at 10msec
    elapsedtime.msec = elapsedtime.msec + 10;
    if (elapsedtime.msec == 1000) {
        elapsedtime.msec = 0;
        elapsedtime.sec++;
    }
    if (elapsedtime.sec == 60) {
        elapsedtime.sec = 0;
        elapsedtime.min++;
    }
    if (elapsedtime.min == 60) {
        elapsedtime.min = 0;
        elapsedtime.hour++;
    }
    
    //Every 4 sec
    if (elapsedtime.sec % 4 == 0 & heartbeatON == 0) {
        heartbeatON = 1;
    }

    if (heartbeatON == 1 & elapsedtime.sec % 4 != 0) {
        heartbeatON = 0;
    }
}

char getHeartbeat(void) {
    return heartbeatON;
}

