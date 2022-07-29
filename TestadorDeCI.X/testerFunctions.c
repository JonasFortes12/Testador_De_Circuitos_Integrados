/*
 * File:   testerFunctions.c
 * Author: jonas
 *
 * Created on 18 de Junho de 2022, 18:06
 */
#include <pic18f4550.h>
#include <stdio.h>
#include "testerFunctions.h"
#include "lcd.h"


/*Combinacao de entradas para os CIs*/
int input1[] = {0, 0, 1, 1};
int input2[] = {0, 1, 0, 1};

int errors = 0;//contador de falhas

void in_out_config_1(){
   /*Definição de entradas e saidas para os CIs 7408 e 7432*/
    TRISD = 0x00;//Definicao das saidas para entradas do CI
    TRISC = 0b11110000;//Definicao de entradas para a saidas do CI
}

void in_out_config_2(){
    /*Definição de entradas e saidas para o CI 7404*/
    TRISD = 0b01100110;
    TRISC = 0b10100000;
}

void test_7408(){
    errors = 0; // assume 0 erros no incio do teste
    limpa_lcd();
    /*Definindo entradas/saidas*/
    in_out_config_1();
    /*Combinacao de saida para o CI 7408*/
    int output[] = {0, 0, 0, 1};
    
    caracter_inicio(1,0);
    printf("Teste CI-7408");
    
    for(int i=0; i<4; i++){
        caracter_inicio(2,0);
        printf("Entrada %d %d", input1[i], input2[i]);
        __delay_ms(500);
        
        /*Definindo as entradas do CI (saidas do Micro)*/
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
        printf("                  ");
        caracter_inicio(2,0);
        printf("CI pronto");
    }else{
        caracter_inicio(2,0);
        printf("                  ");
        caracter_inicio(2,0);
        printf("%d falhas",&errors);
    }
}

void test_7404(){
    limpa_lcd();
    /*Definindo entradas/saidas*/
    in_out_config_2();
    /*Combinacao de saida para o CI 7408*/
    int output[] = {1, 0};
    
    
    caracter_inicio(1,0);
    printf("Teste CI-7404");
    
    for(int i=0; i<2; i++){
        errors = 0; // assume 0 erros no incio do teste
        caracter_inicio(2,0);
        printf("                  ");
        caracter_inicio(2,0);
        printf("Entrada %d ", input2[i]);
        __delay_ms(500);
        
        /*Definindo as entradas do CI (saidas do Micro)*/
        PORTDbits.RD0 = PORTCbits.RC4 = PORTDbits.RD3 = PORTDbits.RD4 
            = PORTCbits.RC6 = PORTDbits.RD7 = input2[i];

        
        /*Testando as saidas do CI___________*/
        if(!(PORTDbits.RD1 == output[i])){
            caracter_inicio(2,0);
            printf("                  ");
            caracter_inicio(2,0);
            printf("Falha pino 12");
            errors++;
            __delay_ms(900);
        }

        if(!(PORTDbits.RD2 == output[i])){
            caracter_inicio(2,0);
            printf("                  ");
            caracter_inicio(2,0);
            printf("Falha pino 10");
            errors++;
            __delay_ms(900);
        }

        if(!(PORTCbits.RC5 == output[i])){
            caracter_inicio(2,0);
            printf("                  ");
            caracter_inicio(2,0);
            printf("Falha pino 8");
            errors++;
            __delay_ms(900);
        }

        if(!(PORTDbits.RD5 == output[i])){
            caracter_inicio(2,0);
            printf("                  ");
            caracter_inicio(2,0);
            printf("Falha pino 2");
            errors++;
            __delay_ms(900);
        }
        
        if(!(PORTDbits.RD6 == output[i])){
            caracter_inicio(2,0);
            printf("                  ");
            caracter_inicio(2,0);
            printf("Falha pino 4");
            errors++;
            __delay_ms(900);
        }
        
        if(!(PORTCbits.RC7 == output[i])){
            caracter_inicio(2,0);
            printf("                  ");
            caracter_inicio(2,0);
            printf("Falha pino 6");
            errors++;
            __delay_ms(900);
        }
        
    } 
    /*Verificando Falhas*/
    if(errors == 0){
        caracter_inicio(2,0);
        printf("                  ");
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

void test_7432(){
    errors = 0; // assume 0 erros no incio do teste
    limpa_lcd();
    /*Definindo entradas/saidas*/
    in_out_config_1();
    /*Combinacao de saida para o CI 7408*/
    int output[] = {0, 1, 1, 1};
    
    caracter_inicio(1,0);
    printf("Teste CI-7432");
    
    for(int i=0; i<4; i++){
        caracter_inicio(2,0);
        printf("                  ");
        caracter_inicio(2,0);
        printf("Entradas %d %d", input1[i], input2[i]);
         __delay_ms(500);
         
        /*Definindo as entradas do CI (saidas do Micro)*/
        PORTDbits.RD0 = PORTDbits.RD2 = PORTDbits.RD4 = PORTDbits.RD6 = input1[i];
        PORTDbits.RD1 = PORTDbits.RD3 = PORTDbits.RD5 = PORTDbits.RD7 = input2[i];
        
        /*Testando as saidas do CI___________*/
        if(!(PORTCbits.RC4 == output[i])){
            caracter_inicio(2,0);
            printf("                  ");
            caracter_inicio(2,0);
            printf("Falha pino 11");
            errors++;
            __delay_ms(900);
        }

        if(!(PORTCbits.RC5 == output[i])){
            caracter_inicio(2,0);
            printf("                  ");
            caracter_inicio(2,0);
            printf("Falha pino 8");
            errors++;
            __delay_ms(900);
        }

        if(!(PORTCbits.RC6 == output[i])){
            caracter_inicio(2,0);
            printf("                  ");
            caracter_inicio(2,0);
            printf("Falha pino 3");
            errors++;
            __delay_ms(900);
        }

        if(!(PORTCbits.RC7 == output[i])){
            caracter_inicio(2,0);
            printf("                  ");
            caracter_inicio(2,0);
            printf("Falha pino 6");
            errors++;
            __delay_ms(900);
        }
        
    } 
    /*Verificando Falhas*/
    if(errors == 0){
        caracter_inicio(2,0);
        printf("             ");
        caracter_inicio(2,0);
        printf("CI pronto");
    }else{
        caracter_inicio(2,0);
        printf("                  ");
        caracter_inicio(2,0);
        printf("%d falha(s)",errors);
    }
}


