#include <tb3bim.h>

extern uint32_t g_tempoSystick;

void initSysTick(){
    NVIC_ST_RELOAD_R = g_tempoSystick;
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_INTEN | NVIC_ST_CTRL_ENABLE;
}

void systickWait(int delayClock){
    volatile unsigned long elapsedTime;
    unsigned long startTime = NVIC_ST_CURRENT_R;
    do {
        elapsedTime = (startTime - NVIC_ST_CURRENT_R) & 0x00FFFFFF;
    } while (elapsedTime <= delayClock);
}

void uDelay(int delayTime){
    unsigned long i;
    for (i = 0; i < delayTime; i++)
        systickWait(6);
}
