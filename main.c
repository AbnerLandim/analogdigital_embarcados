/* PINAGEM
But1 -> PF0 [-]
But2 -> PF4 [+]
But3 -> PD0 [Altera tipo de carga]
But4 -> PB2 [PWM/Acionamento]

LED1 -> PB6 [M0PWM0]
LED2 -> PB7 [M0PWM1]
LED3 -> PB4 [M0PWM2]
LED4 -> PB5 [M0PWM3]

[04] RS   - PB1
[05] R/W  - PB0
[06] E    - PA2
[11] DB4  - PB3
[12] DB5  - PA5
[13] DB6  - PA6
[14] DB7  - PA7

TO-DO:
- Descobrir se é preciso setar o DIR no PortB para o funcionamento do PWM (Acredito que não, o código do prof. não tinha)
- Tratamento dos botões para aumentar a porcentagem
- Menu LCD
- Descobrir como fazer o tempo individual para cada carga de acionamento
*/

#include <tb3bim.h>

uint32_t g_tempoSystick = 80000000; // 5s
uint32_t g_porcentagem[] = {0, 0, 0, 0};

void main(){
    uint32_t i;

    SYSCTL_RCGCGPIO_R = 0x3B; // Habilita os Ports {A, B, D, E, F}

    initSysTick();
    initButt();
    initLcd();
    initPwm();

    if (initEeprom() == 0)
        for (i = 0; i < 4; i++)
            g_porcentagem[i] = EEPROM_read(0, 0);
    else
        return;

    while (1)
        __asm("WFI");
}
