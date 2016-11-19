#include "mbed.h"
//LED
DigitalOut myled1(LED1);
DigitalOut myled4(LED4);
//フォトインタラプタ さえぎっていると０
DigitalIn mycnz(p12, PullDown);

//DCモーター
PwmOut out1(p26);
PwmOut out2(p25);

int flag;
int counter;

int main() {
    out1 = 0;
    out2 = 0;
    myled1 = 0;
    myled4 = 0;
    flag = 0;
    while(1) {
        myled1 = 0;
        myled4 = 0;
        
        if(mycnz == 1){
         out1 = 0;
         out2 = 0;   
        }else if(flag == 0 && mycnz == 0){   
            out1 = 0.4;
            out2 = 0;
            myled1 = 1;
            wait(1.0);
            counter++;
        }else if(flag == 1 && mycnz == 0){
            out1 = 0;
            out2 = 0.4;
            myled4 = 1;   
            wait(1.0);
            counter++;
        }
        
        if(mycnz == 1 && flag == 0 && counter > 1){
            flag = 1;
        }else if(mycnz == 1 && flag == 1 && counter > 1){
            flag = 0;    
        }
        
    }
}


