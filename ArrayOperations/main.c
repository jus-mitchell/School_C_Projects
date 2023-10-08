#include "lab2.h"
#include <stdio.h>

int main(void) {

    int * array;// {0,0,12,13,15};
    int size = 5, i;

    makeArray(&array, size);

    initArray(array, size);

    //int numMultiplied = multiplyOdd(array, size, 2);

    for(i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }

    freeArray(&array);

    //printf("\n%d\n", numMultiplied);

    //printf("\n%d\n", numMultiplied);

    

}