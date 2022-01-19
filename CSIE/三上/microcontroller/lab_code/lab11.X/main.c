#include "setting_hardaware/setting.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./setting_hardaware/uart.h"
// using namespace std;

char str[20];
void Mode1(){
    ClearBuffer();
    UART_Write_Text("Enter mode1\0"); // TODO
    return;
}

void Mode2(){
    ClearBuffer();
    UART_Write_Text("Enter mode2 \0");
    set_exit();
    while(get_exit_bit()){
        show_adc();
    }
    return;
}
void main(void) 
{
    
    SYSTEM_Initialize(); 
    ClearBuffer();
    /*
    while(1) {nothing need to detect when you are in basic
      
    }
    */
    while(1) {
        strcpy(str, GetString());
        if(str[0]=='m' && str[1]=='o' && str[2] == 'd' && str[3] == 'e' && str[4] == '1'){ // Mode1
            Mode1();
            ClearBuffer();
        }
        else if(str[0]=='m' && str[1]=='o' && str[2] == 'd' && str[3] == 'e' && str[4] == '2'){ // Mode2
            Mode2();// TODO
            ClearBuffer();
        }
    }
    return;
}