
#pragma config FOSC = XT_XT     // Oscillator Selection bits (XT oscillator (XT))
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#include <stdio.h>
#include "lcd.h"
#include "testerFunctions.h"

unsigned char index;//contem a selecao da opcao que sera mostrada - indice


void putch(char data)// para escrever caracteres no lcd com printf()
{
  escreve_lcd(data);   
}

void refreshOption(){

    switch(index){
        case 0:
            caracter_inicio(2,2);//define o ponto de inicio da frase na primeira linha
            printf("CI-7408");
        
        case 1:
            caracter_inicio(2,2);//define o ponto de inicio da frase na primeira linha
            printf("CI-XXXX"); 
    }

}


void main(void) {

 TRISB = 0x00;//Entradas para comunicacao com o Display LCD
 PORTB = 0;
 ADCON1 = 0xFF; //Definir o PortA como portas digitais
 TRISA = 0b00000111;//Definicao das entradas para os botoes
// in_out_config_1(); //Definicao das entradas/saidas
 
 index = 0; // indice comeca mostrando primeira opcao 
 
 inicializa_lcd();
 
 limpa_lcd();
 
 
 caracter_inicio(1,0);  //define o ponto de inicio da frase na primeira linha
 printf("_Testador de CI_");

 while(1) {
   
     
     if(button_SELECT) test_7404();
     
     
     
//    if(button_UP) ++index;
//    if(button_DOWN) --index;
//    if(index > 1) index = 0;
//    if(index == 255) index = 1;
//    __delay_ms(50);
//    refreshOption();
     
    }
}