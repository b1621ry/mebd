#include "mbed.h"

AnalogIn myLM35DZ(p15);
Serial pc(USBTX, USBRX);

//付属LED
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

float temperature;

int main() {
    
    myled1 = 0;
    myled2 = 0;
    myled3 = 0;
    myled4 = 0;
    
    while(1) {
        temperature = myLM35DZ.read()*3.3*100;
        pc.printf("%f\n", temperature);
        if(temperature < 27.0){
            myled1 = 1;
            myled2 = 1;
            myled3 = 1;
            myled4 = 1; 
        }else if(temperature > 27.0 && temperature < 28.0){
            myled1 = 1;
            myled2 = 0;
            myled3 = 0;
            myled4 = 0;
        }else if(temperature > 28.0 && temperature < 29.0){
            myled1 = 0;
            myled2 = 1;
            myled3 = 0;
            myled4 = 0;
        }else if(temperature > 29.0 && temperature < 30.0){
            myled1 = 0;
            myled2 = 0;
            myled3 = 1;
            myled4 = 0;
        }else if(temperature > 30.0){
            myled1 = 0;
            myled2 = 0;
            myled3 = 0;
            myled4 = 1;
        }
        wait(1);
    }
}
