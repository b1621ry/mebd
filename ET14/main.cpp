#include "mbed.h"

Serial pc(USBTX, USBRX);
SPI l3gd20_spi(p5, p6, p7);
DigitalOut cs(p8);

//付属LED
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

int main() {
    char result_gyro[6];

    cs = 1;
    l3gd20_spi.format(8, 3);

    cs = 0;
    l3gd20_spi.write(0x20);
    l3gd20_spi.write(0x0F);
    cs = 1;

    while (1) {
        wait(0.1);

        cs = 0;
        l3gd20_spi.write(0xE8);
        for (int i = 0; i < 6; i++)
            result_gyro[i] = l3gd20_spi.write(0x00);
        cs = 1;
        int16_t gyro_z = ((int16_t)result_gyro[5] << 8) | result_gyro[4];
        float z = (float)gyro_z * 0.00875;
        myled1 = 0;
        myled2 = 0;
        myled3 = 0;
        myled4 = 0;
        if(z > 90.0){
         z = z - 90.0;
         z = z + (-90.0); 
        

        }else if( z < -90.0){
         z = z + 90.0;
         z = 90.0  + z;
         

        }
        if(-30.0 < z && 30.0 > z){
            myled2 = 1;
            myled3 = 1;
        }else if(30.0 <= z && 60.0 > z){
            myled1 = 1;
            myled2 = 1;
        }else if(-30.0 >= z && -60.0 < z){
            myled3 = 1;
            myled4 = 1;
        }else if(60.0 <= z){
          myled1 = 1;
             
        }else if(-60.0 >= z){
            myled4 = 1;    
        }
        pc.printf("z = %f\n",z);
        
    }
}

