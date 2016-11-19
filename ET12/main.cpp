#include "mbed.h"

AnalogIn GP2Y0A(p16);
PwmOut mysound(p21);
Serial pc(USBTX, USBRX);

float time(float dis){
    float timeinterval;
    timeinterval = (dis - 0.5) * 0.008;
    return timeinterval;
}

float hertz(float dis){
    float hz;
    hz = (dis - 0.5) * 590;
    hz = hz + 220;
    return hz;
}

int main() {
    float dis;
    float hz;
    float timeint;
    
    while(1) {
        dis = GP2Y0A.read() * 3.3;
            
        if(dis >= 0.5){
            hz = hertz(dis);
            timeint = time(dis);    
            mysound = 0.5;
            mysound.period(1.0 / hz);
            wait(timeint);
        }else{
            mysound = 0;
            wait(1.0);    
        }
        pc.printf("%f\n", dis);
        pc.printf("%f\n", hz);
        pc.printf("%f\n", timeint);
        pc.printf("------------------\n");
        wait(0.5);    
    }
}
