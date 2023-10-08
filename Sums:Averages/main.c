#include <stdio.h>
#include "lab1.h"

int main(void) {

    int array[3] = {};

    float result1;
    int result2;

    getAverage(array, 0, &result1);

    sumPositive(array, 0, &result2);

    printf("result 1 is %.2f\nresult 2 is %d\n", result1, result2);

}