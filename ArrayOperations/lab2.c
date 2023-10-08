#include "lab2.h"
#include <stdio.h>
#include <stdlib.h>

// this function allocates memory for an array of a given size. it takes as its parameters a pointer to the address of an array and the size of the array
int makeArray(int **array, int size) {

    int * memoryAddress; // creates a random address in memory

    if(size > 0 && *array != NULL) { // checks to make sure the size is not given as 0 or a negative number or that the address passed by the user is not null
        memoryAddress = malloc(size * sizeof(int)); // allocates memory of the gizen size to the address
        if(memoryAddress != NULL) { // checks to make sure that the memory was allocated successfully
            *array = memoryAddress; // assins the memory allocated to the address given by the user
            return 0; // returns 0 to signify function success
        }
        else {
            return 1; // if malloc fails this will return one to signify function failure
        }
    }
    else {
        return 1; // if the size is invalid or the user passed in a faulty address the function will return one to signify failure
    }

}

// this functions initializes an arrays elements to 0. its params are an array and its sizze
void initArray(int *array, int size) {

    if(array != NULL && size > 0) { // checks to make sure that the array address and size are valid
        int i;
        for(i = 0; i < size; i++) { // loops through and makes every element 0
            array[i] = 0; 
        }
    }

}

// this function takes an array and an integer representing its size and multiplies each of its odd elements by the multipicand provided by the user
int multiplyOdd(int *array, int size, int multiplicand) {

    if(array != NULL && size > 0) { // checks to make sure that the array address and size are valid
        int i; 
        int numMultiplied = 0;
        for(i = 0; i < size; i++) { // loops through array
            if((array[i] != 0) && (array[i] % 2 != 0)) { // checks if an array element is odd and not zero
                array[i] = array[i] * multiplicand; // if odd and not zero the element will me multiplied by the multiplicand and the result will take its place
                numMultiplied++; // counts the number of elements that were multiplied
            }
        } 
        return numMultiplied; // returns the number of elements multiplied will return 0 if no elements were multiplied
    }
    else {
        return 0; // returns zero to signify that no elements were multiplied (in this case because the array address or size was invalid)
    }
    
}

// this function frees the array and makes the address NULL. takes in a pointer to the address of an array as its parameter
void freeArray(int **array) {

    free(*array);

    *array = NULL;

}