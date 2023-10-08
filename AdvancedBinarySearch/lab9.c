#include <stdlib.h>
#include <stdio.h>
#include "lab9.h"

// helper function
// searches a client array for a particular account number and returns the index of the client with that number
// returns -1 if the account Number doesnt exist
int binarySearch(Client * array, unsigned long queryAccountNumber, int low, int high) {

    int mid;

    if (low == high) {
        return -1;
    } 
    mid = low + (high - low)/2;
    if (queryAccountNumber < array[mid].accountNumber) {
        return binarySearch(array, queryAccountNumber, low, mid);
    }
    else if (queryAccountNumber > array[mid].accountNumber) {
        return binarySearch(array, queryAccountNumber, mid+1, high);
    }

    return mid;
    
}

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

// returns the size of an array allocated by makeArray
int getSize(void *array) {

    return *(((int *)array) - 1);

}

// this function frees the memory allocated by makeArray;
void freeArray(void *array) {

    free(((int *) array) - 1);

}

// this function searches through an array of Clients. Once it finds the right account number it returns the index of the particular Client or -1 if the account number does not exist or the array or query are NULL
// it takes an array of clients and a pointer to the query client as its parameter
int searchClients(Client * array, Client * query) {

    if (array && query) {
        int low = 0, high = (getSize(array)-1); // declares variables
        unsigned long queryAccountNumber = query->accountNumber;
        return binarySearch(array, queryAccountNumber, low, high); // calls the binarySearch function and returns the index
    }
    else {
        return -1;
    }

}

// this function takes to pointers to clients and compares them by their account worth
// if the worth of the first client is greater then the second it returns 1, if the opposite it returns -1, if equal it returns 0
int compareClients(Client * a, Client * b) {

    if(a->accountWorth > b->accountWorth) {
        return 1;
    }
    else if(a->accountWorth < b->accountWorth) {
        return -1;
    }
    else {
        return 0;
    }
}