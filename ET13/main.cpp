#include "mbed.h"
#define ADXL345_I2C 0x3A

Serial pc(USBTX, USBRX);
I2C i2c(p28, p27);

//付属LED
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);


int main() {
    char cmd[2];
    char result[6];
    
    cmd[0] = 0x00;
    i2c.write(ADXL345_I2C, cmd, 1);
    i2c.read(ADXL345_I2C, result, 1);
    pc.printf("cmd[0] = %x, result[0] = %x\n", cmd[0], result[0]);

    cmd[0] = 0x2d;
    cmd[1] = 0x08;
    i2c.write(ADXL345_I2C, cmd, 2);
    i2c.write(ADXL345_I2C, cmd, 1);
    i2c.read(ADXL345_I2C, result, 1);
    pc.printf("cmd[0] = %x, cmd[1] = %x, result[0] = %x\n", cmd[0], cmd[1], result[0]);
    
    cmd[0] = 0x32;
    i2c.write(ADXL345_I2C, cmd, 1);
    i2c.read(ADXL345_I2C, result, 6);
    
    int flag;
    while(1) {
        cmd[0] = 0x32;
        i2c.write(ADXL345_I2C, cmd, 1);
        i2c.read(ADXL345_I2C, result, 6);
        int16_t acc_x = ((int16_t)result[1] << 8) | result[0];
        int16_t acc_y = ((int16_t)result[3] << 8) | result[2];
        int16_t acc_z = ((int16_t)result[5] << 8) | result[4];
        
        flag = 0;
        myled1 = 0;
        myled2 = 0;
        myled3 = 0;
        myled4 = 0;
        
        if(acc_x > 64 || acc_x < -64){
            myled1 = 1;
            if(flag == 0){
                flag = 1;    
            }
        }
        if(acc_y > 64 || acc_y < -64){
            myled2 = 1;
            if(flag == 0){
                flag = 1;    
            }
        }
        if(acc_y > 320 || acc_y < -192){
            myled3 = 1;
            if(flag == 0){
                flag = 1;    
            }    
        }
        
        if(flag == 1){
            wait(2.0);    
        }else{
            myled4 = 1;    
        }
        pc.printf("acc_x = %d, acc_y = %d, acc_z = %d\n", acc_x, acc_y, acc_z);
        wait(0.5);
    }
}
