#include <stdlib.h>
#include <stdio.h>
#include "lab3.h"

// this function allocates memory for a character array of size equal to the the size parameter passed to the function. 
// It takes a single integer as its parameter and returns a character pointer to the array
char * strAlloc(int size) {
    // defines variables
    int * array;
    char * ptr = NULL; // we can return this null pointer if malloc fails
    array = malloc(size * sizeof(char) + sizeof(int)); // allocates the memory and assigns the address
    if(array != NULL) { // if malloc was successful this will make the first array element the size of the array and then increment the pointer to the next memory location
        array[0] = size;
        array++;
        return (char *) array; // returns the allocated char array
    }
    else {
        return ptr; // returns a null pointer if malloc didn't work
    }
}

// this function just returns the element in the memory location before the array, which if it was created using strAlloc then it would be the size
// takes a char array as its parameter and returns an int
int strLen(char *str) {
    return *(((int *)str)-1);
}

// this function copies characters from a source array to a destination array. 
// it takes the addresses to the source and destination arrays as its parameters
void strCpy(char *source, char *dest) {
    int i;
    for(i = 0; i < strLen(source); i++) { // loops through the source array and sets each of the destination array elements equal to the source array element of the correponding index
        dest[i] = source[i];
    }
}

// this function does the same thing as strcCpy except it copies in reverse order
// returns either 1 or 0, depending on if the the source and destination arrays are of the same length. same parameters as strCpy
int strRev(char *source, char *dest) {
    int i,j = 0;
    for(i = strLen(source)-1; i >= 0; i--) { // loops from the end of the array and increments downward, copying the last element of the source into the first element of the destination
        dest[j] = source[i];
        j++;
    }
    if (strLen(source) == strLen(dest)) { // this just returns 1 if the lengths of the two arrays are equal and zero if they are not
        return 1;
    }
    else {
        return 0;
    }
    return 1;
}

// this function frees the memory allocated by strAlloc
void strFree(char *str) {
    free(((int *)str)-1);
}