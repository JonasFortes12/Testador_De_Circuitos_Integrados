
#pragma config FOSC = XT_XT     // Oscillator Selection bits (XT oscillator (XT))
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#include <stdio.h>
#include "lcd.h"
#include "testerFunctions.h"

int nOption = 0;

// para escrever caracteres no lcd com printf()
void putch(char data)
{
  escreve_lcd(data);   
}

void main(void)
{
 PORTB = 0;
 TRISB = 0x00;
 TRISD = 0x00;
 TRISC = 0b00001111;

 inicializa_lcd();
 limpa_lcd();
 
 caracter_inicio(1,0);  //define o ponto de inicio da frase na primeira linha
 printf("_Testador de CI_");
 
 //________________Opcoes de CIs______
 char op1[8] = "CI 7408";
 char op2[8] = "CI 7463";
 
 char *opions[2];
 opions[0] = &op1;
 opions[1] = &op2;
 
 
 while(1) {
    caracter_inicio(2,2);  //define o ponto de inicio da frase na primeira linha   
    
    printf(">> %s <<", opions[nOption++]);
    
    
    __delay_ms(250);//macro
    __delay_ms(250);//macro
    __delay_ms(250);//macro
    __delay_ms(250);//macro
    caracter_inicio(2,2);  //define o ponto de inicio da frase na primeira linha
    
    printf(">> %s <<", opions[nOption--]);

    
    __delay_ms(250);//macro
    __delay_ms(250);//macro
    __delay_ms(250);//macro
    __delay_ms(250);//macro
    
    }
}