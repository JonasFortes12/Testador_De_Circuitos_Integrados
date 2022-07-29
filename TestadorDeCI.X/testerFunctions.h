/*
 * File:   testerFunctions.h
 * Author: jonas
 *
 * Created on 18 de Junho de 2022, 18:06
 */
 #include <xc.h> 

//____________________botoes________________________
#define button_UP     PORTAbits.RA0 //Botao para cima
#define button_DOWN   PORTAbits.RA1 //Botao para baixo
#define button_SELECT PORTAbits.RA2 //Botao Selecionar

void in_out_config_1();
void in_out_config_2();

void test_7408(); //rotina de teste do CI7408
void test_7404(); //rotina de teste do CI7404
void test_7432(); //rotina de teste do CI7432




