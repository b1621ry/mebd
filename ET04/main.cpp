#include "mbed.h"

//外部LED
DigitalOut outled(p8);

//付属LED
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

int main() {
        int j;
        while(1){
        for(j=0;j<3;j++){
            outled = 1;
            wait(1);
            outled = 0;
            wait(0.5);
        }
        
        for(j=0;j<3;j++){
            myled1 = 1;
            wait(1);
            myled1 = 0;
            wait(0.5);
        }
        
        for(j=0;j<3;j++){
            myled2 = 1;
            wait(1);
            myled2 = 0;
            wait(0.5);
        }
        
        for(j=0;j<3;j++){
            myled3 = 1;
            wait(1);
            myled3 = 0;
            wait(0.5);
        }
        
        for(j=0;j<3;j++){
            myled4 = 1;
            wait(1);
            myled4 = 0;
            wait(0.5);
        }
    }
}
