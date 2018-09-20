/* PINAGEM
But1 -> PF0 [-]
But2 -> PF4 [+]
But3 -> PD0 [Func]
But4 -> PB2 [Reservado] --- era PB6

LED1 -> PB6 [M0PWM0]
LED2 -> PB7 [M0PWM1]
LED3 -> PB4 [M0PWM2]
LED4 -> PB5 [M0PWM3]

[04] RS   - PB1
[05] R/W  - PB0
[06] E    - PA2  --- era PB5 (Já está modificado no código do LCD)
[11] DB4  - PB3  --- era PB4 (Já está modificado no código do LCD)
[12] DB5  - PA5
[13] DB6  - PA6
[14] DB7  - PA7

TO-DO:
- Arrumar os contadores do PWM, para que seja possível manipular o duty-cicle de cada saída individualmente (Não tenho certeza se já faz isso)
- Descobrir se é preciso setar o DIR no PortB para o funcionamento do PWM (Acredito que não)
- Fazer a gravação do EEPROM assim que terminar a leitura de um botão
- Desbloquear o PF0 usando o CR e o LOCK
*/

#include <tb3bim.h>

uint32_t g_tempoSystick = 200000;
uint32_t g_porcentagem[] = {0, 0, 0, 0};

void main(){
    uint32_t i;

    //EEPROM_write(0, 0, g_porcentagem); //Jogar no trataSystick()

    SYSCTL_RCGCGPIO_R = 0x3B; // Habilita os Ports {A, B, D, E, F}

    //initSysTick();
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
