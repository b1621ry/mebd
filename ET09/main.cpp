#include "mbed.h"

//LED
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

//DCモーター
PwmOut out1(p26);
PwmOut out2(p25);

//温度センサー
AnalogIn myLM35DZ(p15);
Serial pc(USBTX, USBRX);
float temp;

float speed;

int main() {
    myled1 =0;
    myled2 =0;
    myled3 =0;
    myled4 =0;
    
    while(1) {
        temp = myLM35DZ.read()*3.3*100;
        if(temp <= 50.0){
            speed = temp * 2 * 0.01;
        }else{
            speed = 1.0;
        }
        if(temp < 25.0){
            myled1 = 0;
            myled2 = 0;
            myled3 = 0;
            myled4 = 0;
        }else if(temp >= 25.0 && temp < 28.0){
            myled1 = 1;
            myled2 = 0;
            myled3 = 0;
            myled4 = 0;
        }else if(temp >= 28.0 && temp < 31.0){
            myled1 = 1;
            myled2 = 1;
            myled3 = 0;
            myled4 = 0;
        }else if(temp >= 31.0 && temp < 34.0){
            myled1 = 1;
            myled2 = 1;
            myled3 = 1;
            myled4 = 0;
        }else if(temp > 34.0){
            myled1 = 1;
            myled2 = 1;
            myled3 = 1;
            myled4 = 1;            
        }
        out1 = speed;
        out2 = 0;
        wait(1.0);
        pc.printf("%f\n", temp);
        pc.printf("%f\n", speed);
    }
}
