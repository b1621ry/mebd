#include "mbed.h"

DigitalOut myled(LED1);
PwmOut myservo(p21);

AnalogIn myLM35DZ(p15);
Serial pc(USBTX, USBRX);

float temp;
int angle;
float result;

const int per_angle = 89;

int main() {
    //初期化
    myservo.pulsewidth_us(1200);
    wait(0.5);
    
    while(1) {
        temp = myLM35DZ.read()*3.3*100;
        
        if(temp < 25.0){angle = 2122;}
        if(temp > 35.0){angle = 878;}
        if(temp >= 25.0 && temp <= 35.0){
            result = ((temp-25.0) * per_angle);
            angle = 2122 - result;    
        }
        pc.printf("%f\n", temp);
        pc.printf("%d\n", angle);
        myservo.pulsewidth_us(angle);
        wait(0.5);
    }
   
}


