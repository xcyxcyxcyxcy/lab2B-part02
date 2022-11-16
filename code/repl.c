#include "hardware/pio.h"                                                               //Standard RP2040 library
#include "pico/stdlib.h"                                                                
#include <stdio.h>                                                                      
#include "stdlib.h"                                                                     
#include "hardware/gpio.h"                                                              
#include "hardware/structs/sio.h"                                                       
#include "register_read&write.h"                                                        


int main(){
    stdio_init_all();                                                                   
    VALUE a;                                                                            
    long int command;                                                                   
    long int value;                                                                     
    char operation;                                                                     
    int mode;                                                                           
    printf("Waiting for RP1-RP2\n");                                                        
    while (!stdio_usb_connected()) {
      printf(".");
      sleep_ms(500);
    }
    printf("\nRP1-RP2 detected!\n");
    printf("\nPlease choose a mode\n");                          
    while(true){
        printf("\n>>>");                                                              
        sleep_ms(10);
        scanf(" %c",&operation);                                                        
        switch(operation){                                                              
            case 'r':                                                                   
                printf("\nRead Mode , Enter Address:");
                sleep_ms(10);
                scanf(" %x",&command);                                                                                                 
                a = register_read((ADDRESS)command);                                    
                printf("\n%x\n",a);                                                     
                break;                                                                  
            case 'w':                                                                   
                printf("\nWrite Mode , Enter Address:");
                sleep_ms(10);                                                           
                scanf(" %x",&command);                                                  
                printf("\nWrite Mode , Enter Value to be Set:");                 
                sleep_ms(10);                                                   
                scanf(" %x",&value);                                                    
                register_write((ADDRESS)command,(VALUE)value);                          
                break;
        }
        sleep_ms(10);

    }
    return 0;
}