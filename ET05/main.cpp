#include "mbed.h"

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);

DigitalIn myswitch(p8);

int prev_sw = 0;

bool check_sw();

int main() {
    myswitch.mode(PullUp);
    
    //初期状態
    myled1 = 1;
    myled2 = 1;
    
    while(1) {
        if (check_sw() && prev_sw == 0) {
            prev_sw = 1;
        }else if(check_sw() && prev_sw == 1){
            prev_sw = 0;    
        }
        
        if(prev_sw == 1){
             myled2 = 1;
        }else{
            myled2 = 1;
            wait(0.001);
            myled2 = 0;
            wait(0.007);    
        }
    }
}

bool check_sw() {
    bool sw_state = false;
    if (myswitch.read() == 0) {
        wait(0.001);
        if (myswitch.read() == 0) sw_state = true;
    }
    return sw_state;
}

    