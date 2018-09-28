#include <fstream>
#include <iomanip>
#include<iostream>
#include "cpu_utils.h"
int main(){
    cpu_util a;
    int len=a.read();
    for(int i=a.PC;i<len;i++){
        std::cout<< std::setfill('0') << std::setw(2)<<std::hex<<(int)a.memory[i]<<std::endl;
    }
    return 0;
}
