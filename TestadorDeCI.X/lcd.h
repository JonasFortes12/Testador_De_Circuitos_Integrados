
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H
#include <xc.h> 

#define _XTAL_FREQ 4000000

#define lcd_rs     PORTBbits.RB7 // pino rs (register select)do LCD                                                                  // (0) para comandos (1) para dados
#define lcd_enable PORTBbits.RB6 // pino enable do LCD
#define lcd_db4    PORTBbits.RB0 // pino de dados d4 do LCD
#define lcd_db5    PORTBbits.RB1 // pino de dados d5 do LCD
#define lcd_db6    PORTBbits.RB2 // pino de dados d6 do LCD
#define lcd_db7    PORTBbits.RB3 // pino de dados d7 do LCD

/***************************************************************************/
/* Rotinas para o LCD */
/***************************************************************************/
 void envia_nibble_lcd(char dado);
 void envia_byte_lcd(char endereco,char dado);
 inline void escreve_lcd(char c);
 void limpa_lcd(void);
 void inicializa_lcd(void);
 void caracter_inicio(char linha,char coluna);

#endif	/* XC_HEADER_TEMPLATE_H */
