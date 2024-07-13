Uptime Timer and Watchdog Heartbeat
-----------------------------------

Create an interrupt timer in MCC for the PIC and configure it for 10mSec

Use in code

#include "timing.h"

extern UpTime elapsedtime; 

void main(void) {
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    //Timing init
    timingReset();

    //Add to the MCC handler
    TMR1_SetInterruptHandler(addMsec);

    while(1) {
       if (getHeartbeat()) {
         callsomefunction(elapsedtime.sec);
       }
    }
}

