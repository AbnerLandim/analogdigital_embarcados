#include <tb3bim.h>

void initButt(){
    // PortB - SE NECESS�RIO
    /*GPIO_PORTB_DIR_R |= 0x04; // {2} � input
    GPIO_PORTB_DATA_R = 0x00;
    GPIO_PORTB_IS_R = 0x00; // Define sensibilidade do bot�o - [0 borda / 1 sinal cont�nuo]
    GPIO_PORTB_IEV_R = 0x00; // Define evento - [0 descida/baixo] ou [1 subida/alto]
    GPIO_PORTB_IBE_R = 0x00; // Desabilita interrupt por ambas as bordas
    GPIO_PORTB_DEN_R |= 0x04; // Habilita {2}
    GPIO_PORTB_IM_R = 0x04; // Habilita interrupt no pino
    GPIO_PORTB_PUR_R = 0x04;
    NVIC_EN0_R = 1 << 1; // Habilita interrupt no PortB*/

    // PortD
    GPIO_PORTD_DIR_R |= 0x01; // {1} � input
    GPIO_PORTD_DATA_R = 0x00;
    GPIO_PORTD_IS_R = 0x00;
    GPIO_PORTD_IEV_R = 0x00;
    GPIO_PORTD_IBE_R = 0x00;
    GPIO_PORTD_DEN_R |= 0x01; // Habilita {1}
    GPIO_PORTD_IM_R = 0x01;
    GPIO_PORTD_PUR_R = 0x01;
    NVIC_EN0_R = 1 << 3;

    // PortF
    GPIO_PORTF_DIR_R |= 0x11; // {0 e 4} s�o inputs
    GPIO_PORTF_DATA_R = 0x00;
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0x01;
    GPIO_PORTF_IS_R = 0x00;
    GPIO_PORTF_IEV_R = 0x00;
    GPIO_PORTF_IBE_R = 0x00;
    GPIO_PORTF_DEN_R |= 0x11; // Habilita {1}
    GPIO_PORTF_IM_R = 0x11;
    GPIO_PORTF_PUR_R = 0x11;
    NVIC_EN0_R = 1 << 30;
}

void interruptPortB(){
    if ((GPIO_PORTB_RIS_R & 0x04) == 0x04){ // Verifica��o de qual pino gerou a interrupt
        GPIO_PORTB_ICR_R = 0x04; // Limpa flag de int. do pino que gerou a interrupt
    }
}

void interruptPortD(){
    if ((GPIO_PORTD_RIS_R & 0x01) == 0x01){
        GPIO_PORTD_ICR_R = 0x01;
    }
}

void interruptPortF(){
    if ((GPIO_PORTF_RIS_R & 0x01) == 0x01){
        GPIO_PORTF_ICR_R = 0x01;
    }
    if ((GPIO_PORTF_RIS_R & 0x10) == 0x10){
            GPIO_PORTF_ICR_R = 0x10;
    }
}
