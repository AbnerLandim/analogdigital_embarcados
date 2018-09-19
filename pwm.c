#include <tb3bim.h>

void initPwm(){
    /* M0PWM0 e M0PWM1 usam o elemento 0, isto é, o gerador de frequências 0
     * M0PWM2 e M0PWM3 usam o elemento 1, isto é, o gerador de frequências 1*/

    // Habilita função alternativa aos PB{4, 5, 6 e 7}
    GPIO_PORTB_AFSEL_R = 0xF0;

    // Define que a função alternativa dos PB{4, 5, 6 e 7} é PWM
    GPIO_PORTB_PCTL_R = 0x44440000;

    // Habilita PB{4, 5, 6 e 7} digitalmente
    GPIO_PORTB_DEN_R |= 0xF0;

    // Ativa o módulo de PWM 0
    SYSCTL_RCGCPWM_R = 0x01;

    // Nível baixo em LOAD / Nivel alto em CMPA
    PWM0_0_GENA_R = 0xC8; // PB6
    PWM0_0_GENB_R = 0xC8; // PB7

    PWM0_1_GENA_R = 0xC8; // PB4
    PWM0_1_GENB_R = 0xC8; // PB5

    // Valor de frequencia do PWM, em ciclos de clock
    PWM0_0_LOAD_R = PWM_FREQ;
    PWM0_1_LOAD_R = PWM_FREQ;

    // Valor de porcentagem do PWM, em ciclos de clock
    PWM0_0_CMPA_R = (PWM_FREQ * g_porcentagem[0]) / 100;
    PWM0_0_CMPB_R = (PWM_FREQ * g_porcentagem[1]) / 100;

    PWM0_1_CMPA_R = (PWM_FREQ * g_porcentagem[2]) / 100;
    PWM0_1_CMPB_R = (PWM_FREQ * g_porcentagem[3]) / 100;

    // Ativa o controle do elemento 0 e 1 do PWM0
    PWM0_0_CTL_R = 0x01;
    PWM0_1_CTL_R = 0x01;

    // Inicializa o PWM -> M0PWM{0, 1, 2, 3} - Gerador
    PWM0_ENABLE_R = 0x0F;
}
