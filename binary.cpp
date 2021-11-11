#include "GA.h"

int bin2dec(const int N_bit, bool *binary){
    /*2進数→10進数変換*/
    int v { 0 };
    int base { 1 };

    for(int i = 0; i < N_bit; i++){
        v += int(binary[i]) * base;
        base *= 2;
    }
    return v;
}