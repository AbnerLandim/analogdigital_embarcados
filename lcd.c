#include <tb3bim.h>

void enablePulsoLcd(void){
    GPIO_PORTA_DATA_R = 0b00000100;
    uDelay(100000);
    GPIO_PORTA_DATA_R = 0b00000000;
}

void initLcd(){
    GPIO_PORTA_DIR_R = 0b11100100;
    GPIO_PORTA_DATA_R = 0b00000000;
    GPIO_PORTA_DEN_R = 0b11100100;
    GPIO_PORTB_DIR_R = 0b00001011;
    GPIO_PORTB_DATA_R = 0b00000000;
    GPIO_PORTB_DEN_R = 0b00001011;

    uDelay(20000);
    GPIO_PORTB_DATA_R = 0b00001000;
    GPIO_PORTA_DATA_R = 0b00100000;
    enablePulsoLcd();
    uDelay(5000);
    enablePulsoLcd();
    uDelay(2000);
    enablePulsoLcd();
    enablePulsoLcd();

    // modo 4 bit
    GPIO_PORTB_DATA_R = 0b00000000;
    GPIO_PORTA_DATA_R = 0b00100000;
    enablePulsoLcd();

    // 2linhas - 5x7
    GPIO_PORTB_DATA_R = 0b00000000;
    GPIO_PORTA_DATA_R = 0b00100000;
    enablePulsoLcd();
    GPIO_PORTB_DATA_R = 0b00000000;
    GPIO_PORTA_DATA_R = 0b10000000;
    enablePulsoLcd();

    // Desliga o Display
    GPIO_PORTB_DATA_R = 0b00000000;
    GPIO_PORTA_DATA_R = 0b00000000;
    enablePulsoLcd();
    GPIO_PORTB_DATA_R = 0b00000000;
    GPIO_PORTA_DATA_R = 0b10000000;
    enablePulsoLcd();

    // Limpa o Display
    GPIO_PORTB_DATA_R = 0b00000000;
    GPIO_PORTA_DATA_R = 0b00000000;
    enablePulsoLcd();
    GPIO_PORTB_DATA_R = 0b00001000;
    GPIO_PORTA_DATA_R = 0b00000000;
    enablePulsoLcd();

    // Funcionamento do Display
    GPIO_PORTB_DATA_R = 0b00000000;
    GPIO_PORTA_DATA_R = 0b00000000;
    enablePulsoLcd();
    GPIO_PORTB_DATA_R = 0b00000000;
    GPIO_PORTA_DATA_R = 0b01100000;
    enablePulsoLcd();
}

void cmdLcd(char data){
    GPIO_PORTB_DATA_R = data & 0b00001000;
    GPIO_PORTA_DATA_R = data & 0b11100000;
    enablePulsoLcd();
    GPIO_PORTB_DATA_R = data << 4 & 0b00001000;
    GPIO_PORTA_DATA_R = data << 4 & 0b11100000;
    enablePulsoLcd();
}
