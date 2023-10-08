#include "lab4.h"
#include <stdlib.h>
#include <stdio.h>


// this fuction allocates memory for an array of any type, It takes the size of the array and the size of the datatype as its parameters
// it returns a void pointer to the allocatesd memory
// it also stores the size array in the element before the array. 
void * makeArray(int arraySize, int elementSize) {

    int * array;
    array = malloc(arraySize * sizeof(elementSize) + sizeof(int)); // allocates the memory assigns it to an address
    if(array) { // checks to make sure malloc succeeded
        array[0] = arraySize; // stores the size in the first element
        array++; // then increments the pointer
        return (void *) array; // returns the pointer
    }
    else {
        return NULL; // if malloc failed returns null
    }

}

// this function just returns the elment stored before the array by the previous function, takes a void * array as its parameter
int getSize(void *array) {

    return *(((int *)array) - 1);

}

//This function takes an array of InventoryItems, and returns the number of items in the array which have a number of colors equal to the given colorCount
int countWithColors(InventoryItem *items, short colorCount) {

    int i, count = 0;
    for(i = 0; i < getSize(items); i++) { // increments through array
        if(items[i].colors == colorCount) { // checks to see if the number of colors an item has is equal to the color count
            count++; // increments the count
        }
    }
    return count; // returns the count

}

// this function frees the memory allocated by makeArray;
void freeArray(void *array) {

    free(((int *) array) - 1);

}