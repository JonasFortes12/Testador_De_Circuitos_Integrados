/*
 * File:   testerFunctions.c
 * Author: jonas
 *
 * Created on 18 de Junho de 2022, 18:06
 */
#include "testerFunctions.h"
#include "lcd.h"

/*Combinacao de entradas para os CIs*/
int input1[4] = {0, 0, 1, 1};
int input2[4] = {0, 1, 0, 1};


int errors = 0;//contador de falhas

void test_7408(){
    /*Combinacao de saida para o CI 7408*/
    int output[4] = {0, 0, 0, 1};
    
    caracter_inicio(1,0);
    printf("Teste CI-7408");
    
    for(int i=0; i<4; i++){
        __delay_ms(500);
        caracter_inicio(2,0);
        printf("Entrada %d %d", input1, input2);
        
        /*Definindo as entradas do CI*/
        PORTDbits.RD0 = PORTDbits.RD2 = PORTDbits.RD4 = PORTDbits.RD6 = input1[i];
        PORTDbits.RD1 = PORTDbits.RD3 = PORTDbits.RD5 = PORTDbits.RD7 = input2[i];
        
        /*Testando as saidas do CI___________*/
        if(!(PORTCbits.RC4 == output[i])){
            caracter_inicio(2,0);
            printf("Falha pino 11");
            errors++;
            __delay_ms(900);
        }

        if(!(PORTCbits.RC5 == output[i])){
            caracter_inicio(2,0);
            printf("Falha pino 8");
            errors++;
            __delay_ms(900);
        }

        if(!(PORTCbits.RC6 == output[i])){
            caracter_inicio(2,0);
            printf("Falha pino 3");
            errors++;
            __delay_ms(900);
        }

        if(!(PORTCbits.RC7 == output[i])){
            caracter_inicio(2,0);
            printf("Falha pino 6");
            errors++;
            __delay_ms(900);
        }
        
    } 
    /*Verificando Falhas*/
    if(errors == 0){
        caracter_inicio(2,0);
        printf("CI pronto");
    }else{
        caracter_inicio(2,0);
        printf("                  ");
        caracter_inicio(2,0);
        printf("%d falhas",&errors);
    }
    errors = 0;
}



