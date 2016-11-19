#include "mbed.h"

AnalogIn GP2Y0A(p16);
Serial pc(USBTX, USBRX);

int main() {
    while(1) {
        pc.printf("%f\n", GP2Y0A.read()*3.3);
        wait(1.0);
    }
}
