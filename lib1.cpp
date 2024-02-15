#include "lib.h"

// Алгоритм Евклида
int GCF(int A, int B){
    int max, min;

    if (A > B){
        max = A;
        min = B;
    }
    else if(A < B){
        max = B;
        min = A;
    }
    else{
        return A;
    }

    while (min != 0){
        int q = min;
        min = max % min;
        max = q;
    }

    return max;
}

// Ряд Лейбница
float Pi(int K){
    float pi = 0;
    int sign = 1;

    for (int i = 0; i < K; i++){
        pi += sign / (2.0 * i + 1);
        sign *= -1;
    }

    return pi * 4;
}