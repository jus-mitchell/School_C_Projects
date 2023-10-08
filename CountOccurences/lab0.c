#include "lab0.h"
/* REQUIRED CODE GOES HERE */

// counts the number of occurences of a certain query integer in an array
int countOccurrences(int size, int array[], int queryInt) {
    
    // variables i'll need
    int i;
    int occurrences = 0;

    // loops through the array 
    for(i = 0; i < size; i++) {

        //checks if the current array item is equal to the query integer
        if(array[i] == queryInt) {

            // if it is equal it increments the occurences variable by 1
            occurrences++;
        }
    }

    // the number of occurences of the query integer
    return occurrences;
}