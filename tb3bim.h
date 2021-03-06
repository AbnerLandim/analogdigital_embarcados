#ifndef TB3BIM_H_
#define TB3BIM_H_

#include <inttypes.h>
#include <tm4c123gh6pm.h>

#define EEPROM_INIT_OK 0
#define EEPROM_INIT_ERROR 2
#define PWM_FREQ 16000

void systickWait(int);
void uDelay(int);
void enablePulsoLcd(void);
void initLcd();
void cmdLcd(char data);
void initSysTick();
void initButt();
void initPwm();
void gravaEstado();
uint32_t initEeprom();
uint32_t EEPROM_read(uint8_t block, uint8_t offset);
void EEPROM_write(uint8_t block, uint8_t offset, uint32_t word);

void interruptPortB();
void interruptPortD();
void interruptPortF();


#endif
