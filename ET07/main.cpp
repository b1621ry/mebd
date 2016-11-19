#include "mbed.h"


//温度センサー
AnalogIn myLM35DZ(p15);
Serial pc(USBTX, USBRX);

//温度
float temp;

int main() {
    
    
    DigitalOut stepA(p13);
    DigitalOut stepB(p14);
    
    //左回り用
    int stepLeft1[] = {1, 1, 0, 0};
    int stepLeft2[] = {0, 1, 1, 0};
    //右回り用
    int stepRight1[] = {0, 0, 1, 1};
    int stepRight2[] = {0, 1, 1, 0};
    
    int count = 0;
    
    
    while(1) {
        
        count = 0;
        temp = myLM35DZ.read()*3.3*100;
        
        if(temp <= 32.0){
            if(temp < 30.0){
                //30度以下
                while(count < 4){
                    stepA = stepLeft1[count];
                    stepB = stepLeft2[count];
                    wait(0.01);
                    count++;
                }
            }else if(temp >= 30.0){
                //30度以上32度以下
                while(count < 4){
                    stepA = stepLeft1[count];
                    stepB = stepLeft2[count];
                    wait(0.02);
                    count++;
                }
            }    
        }else if(temp > 32.0){
            if(temp > 34.0){
                //34度以上
                while(count < 4){
                    stepA = stepRight1[count];
                    stepB = stepRight2[count];
                    wait(0.01);
                    count++;
                }
            }else if(temp <=34.0){
               //32度より大きく34度以下
               while(count < 4){
                    stepA = stepRight1[count];
                    stepB = stepRight2[count];
                    wait(0.02);
                    count++;
                }
            }
        }
        pc.printf("%f\n", temp);
    }
}

