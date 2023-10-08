#include "lab1.h"

// gets the average of the array
int getAverage(int array[], int size, float *result) {

    // checks to make sure the array address is not equal to Null or if the array has a size of zero (dont want to divide by zero)
    if((array != NULL) && size != 0) {

        // needed varibles
        int i, total = 0;
        float average;
        
        // loops through array
        for(i = 0; i < size; i++) {
            // adds up all the array elements
            total += array[i];
        }

        // calculates the average as a float
        average = (float) total / size;

        // places the average in the result variable
        *result = average;

        // returns 0 to indicate success
        return 0;
    }
    else {
        // returns 1 to indicate failure
        return 1;
    }

}

// gets the sum of all the positive elements in the array
int sumPositive(int array[], int size, int *result) {

    // checks to make sure the array address is not equal to Null 
    if ((array != NULL) && size != 0) {

        // needed varibles
        int i, sum = 0;

        // loops through the array
        for(i = 0; i < size; i++) {

            // adds the positive elements
            if(array[i] > 0) {
                sum += array[i];
            }
        }

        // places the sum in the result variable
        *result = sum;

        // returns 0 to indicate success 
        return 0;
    }
    else {
        // returns 1 to indicate failure
        return 1;
    }

}