#include "mbed.h"

DigitalOut pd_sck(PA_5);
DigitalIn dout(PA_4);

void pwr_down(){
    pd_sck = 1;
    wait_us(70);
}

bool is_ready(){
    if(dout==0){
        return 1;
    }
    return 0;
}

bool* data_receive(unsigned char resolution = 128){
    bool* result = new bool[24];
    if(is_ready()){
        for(int i=0; i<24; i++){
            pd_sck =1;
            wait_us(10);
            result[i] = dout;
            wait_us(15);
            pd_sck =0;
            wait_us(10);
        }
        if (resolution == 128){
            pd_sck = 1;
            wait_us(35);
            pd_sck = 0;
            wait_us(35);
        }
        else if (resolution == 32){
            pd_sck = 1;
            wait_us(35);
            pd_sck = 0;
            wait_us(35);
            pd_sck = 1;
            wait_us(35);
            pd_sck = 0;
            wait_us(35);
        }
        else if (resolution == 64){
            pd_sck = 1;
            wait_us(35);
            pd_sck = 0;
            wait_us(35);
            pd_sck = 1;
            wait_us(35);
            pd_sck = 0;
            wait_us(35);
            pd_sck = 1;
            wait_us(35);
            pd_sck = 0;
            wait_us(35);
        }
    }
    
    return result;
}

int main() {
  //use the functions above defined for the integration of hx711 with Bluepill [stm32f103c8t6]
}
