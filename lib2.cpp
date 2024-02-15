#include "lib.h"

// Наивный алгоритм
int GCF(int A, int B){
    int min;

    if (A > B){
        min = B;
    }
    else if (A < B){
        min = A;
    }
    else{
        return A;
    }

    int q = min;

    while (q != 0){
        if (A % q == 0 && B % q == 0){
            return q;
        }
        --q;
    }

    return -1;
}

// Формула Валлиса
float Pi(int K){
    float pi = 2;

    for (int i = 1; i <= K; i++){
        pi *= (4.0 * i * i) / ((4.0 * i * i) - 1);
    }

    return pi;
}