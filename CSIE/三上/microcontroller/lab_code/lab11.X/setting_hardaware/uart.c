#include <xc.h>
#include <stdio.h>
#include "adc.h"
#include "uart.h"
#include<pic18f4520.h>
//setting TX/RX

#define _XTAL_FREQ 8000000//__delay_ms()

char mystring[20];
int lenStr = 0;
int exit_adc = 0;//if exit_adc = 0, exit mode2, else still in mode2 

void UART_Initialize() {
           
    /*       TODObasic   
           Serial Setting      
        1.   Setting Baud rate
        2.   choose sync/async mode 
        3.   enable Serial port (configures RX/DT and TX/CK pins as serial port pins)
        3.5  enable Tx, Rx Interrupt(optional)
        4.   Enable Tx & RX
     */
           
    TRISCbits.TRISC6 = 1;            
    TRISCbits.TRISC7 = 1;            
    
    //  Setting baud rate
    TXSTAbits.SYNC = 0;           
    BAUDCONbits.BRG16 = 0;          
    TXSTAbits.BRGH = 0;
    SPBRG = 51;//osc=8MHz, in setting.c
    
    //Serial enable
    RCSTAbits.SPEN = 1;              
    PIR1bits.TXIF = 1;//transmit interrupt flag
    PIR1bits.RCIF = 0;//receieve interrupt flag, in begining, RCREG is empty, is 0
    TXSTAbits.TXEN = 1;
    RCSTAbits.CREN = 1;
    PIE1bits.TXIE = 0;//enable transmit       
    IPR1bits.TXIP = 0;//both transmit and receieve are low priority, combine with your interrupt function            
    PIE1bits.RCIE = 1;//enable receieve
    IPR1bits.RCIP = 0;
           
    }

void UART_Write(unsigned char data)  // Output on Terminal
{
    while(!TXSTAbits.TRMT);
    TXREG = data;              //write to TXREG will send data 
}

char *GetString(){ // 
    return mystring;
}

void UART_Write_Text(char* text) { // Output on Terminal, limit:10 chars
    for(int i=0;text[i]!='\0';i++)
        UART_Write(text[i]);
}

void ClearBuffer(){
    for(int i = 0; i < 20 ; i++)
        mystring[i] = '\0';
    lenStr = 0;
}

void MyusartRead()
{
    /* TODObasic: try to use UART_Write to finish this function */
    mystring[lenStr] = RCREG;
    if(mystring[lenStr] == '\r')//may use when it occur '\r\n'
        UART_Write('\n');
    UART_Write(mystring[lenStr]);//print things you enter
    if(exit_adc == 1){
        if(mystring[lenStr] == 'e'){
            exit_adc = 0;
        }
        //if we are in mode2, detect if enter is 'e'
        //leave mode 2 after detect 'e'
    }
    lenStr++;
    lenStr%=10;//only use 10 location
    return ;
}



// void interrupt low_priority Lo_ISR(void)
void __interrupt(low_priority)  Lo_ISR(void)
{
    if(RCIF)
    {
        if(RCSTAbits.OERR)
        {
            CREN = 0;
            Nop();
            CREN = 1;
        }
        
        MyusartRead();
    }
   // process other interrupt sources here, if required
    return;
}

void show_adc(void)//0.00~5.00
{
    char num[5];
    num[4] = '\0';//Write Text check read with \0
    sprintf(num, "%.2f", ((float)ADC_Read(7)/1023*5));//put integer you read into num
    UART_Write_Text(num);
    __delay_ms(1000);//delay, so it wouldn't change so fast
    UART_Write_Text(" ");
    return;
}

int get_exit_bit()
{
    return exit_adc;
}

void set_exit()
{
    exit_adc = 1;
    return;
}