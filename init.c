#include <tb3bim.h>

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
[06] E    - PA2  --- era PB5
[11] DB4  - PB3  --- era PB4
[12] DB5  - PA5
[13] DB6  - PA6
[14] DB7  - PA7*/

void initSysTick(){
    NVIC_ST_RELOAD_R = g_tempoSystick;
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_INTEN | NVIC_ST_CTRL_ENABLE;
}

void initButt(){
    // PortA
    GPIO_PORTA_DIR_R = 0xE4; // PA{2, 5, 6 e 7} são outputs
    GPIO_PORTA_DATA_R = 0x00;
    GPIO_PORTA_DEN_R = 0xE4; // Habilita PA{2, 5, 6 e 7}
    //GPIO_PORTA_PUR_R |= 0xE4;

    // PortB
    GPIO_PORTB_DIR_R = 0x0B; // PB{0, 1 e 3} são outputs; PB{2} é input
    GPIO_PORTB_DATA_R = 0x00;
    GPIO_PORTB_DEN_R = 0x0F; // Habilita PB{0, 1, 2 e 3}
    GPIO_PORTB_PUR_R = 0x04; // PB{2}

    // PortD
    GPIO_PORTD_DIR_R = 0x00; // Todos são inputs
    GPIO_PORTD_DATA_R = 0x00;
    GPIO_PORTD_DEN_R = 0x40; // Habilita {6}
    GPIO_PORTD_PUR_R = 0x40;

    // PortE
    GPIO_PORTE_DIR_R = 0x00; // Todos são inputs
    GPIO_PORTE_DATA_R = 0x00;
    GPIO_PORTB_DEN_R = 0x40; // Habilita {6}
    GPIO_PORTB_PUR_R = 0x40;

    // PortF
    GPIO_PORTF_DIR_R = 0x00; // Todos são inputs
    GPIO_PORTF_DATA_R = 0x00;
    GPIO_PORTF_DEN_R = 0x40; // Habilita {6}
    GPIO_PORTF_PUR_R = 0x40;
}
