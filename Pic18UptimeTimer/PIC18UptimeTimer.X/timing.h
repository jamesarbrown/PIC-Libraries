#ifndef TIMING_H
#define	TIMING_H

#include <stdint.h>

//Max 255 Hours
struct time {
    uint16_t msec;
    uint8_t  sec;
    uint8_t  min;
    uint8_t  hour;
};
typedef struct time UpTime;

//Function Prototypes
void timingReset(void);
void addMsec(void);
char getHeartbeat(void);

#endif	/* TIMING_H */

