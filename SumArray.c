/* 
Name: Justice Mitchell
*/


#include <stdio.h>
#define SIZE 60 // defines a size for array1

// initializes array1 of odd integers 1 to 99
int array1[SIZE] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63,65,67,69,71,73,75,77,79,81,83,85,87,89,91,93,95,97,99,101,103,105,107,109,111,113,115,117,119};

// main function
int main(void) {

   // initailizes variables
   int totalEvens = 0;
   float avergageEvens;
   int totalOdds = 0;
   float avergageOdds;
   //int x;
   /*if (SIZE % 2 == 0) {
    x = 0.5;
   }
   else {
    x = 0;
   }*/

    // prints of the array index and value for ever item
    for(int i = 0; i < SIZE; i++) {
        printf("array1[%d]=%d, ", i, array1[i]);
    }

    for(int i = 0; i < SIZE; i++) {
        if (i % 2 == 0) {
            totalEvens += array1[i];
        }
        else {
            totalOdds += array1[i];
        }
    }
    
    // sums all the values with an even index
    /*for(int i = 0; i <= 48; i += 2) {
        totalEvens += array1[i];
    }*/

    // caculates the average of the evens
    avergageEvens = (float) totalEvens / (SIZE / 2);

    // sums all the values with an odd index
    //for(int i = 1; i <= 49; i += 2) {
    //    totalOdds += array1[i];
    //}

    // caculates the average of the odds
    avergageOdds = (float) totalOdds / (SIZE / 2);

    //prints the totals and averages
    printf("\nTotal of of array even elements = %d, average = %.2f\n", totalEvens, avergageEvens);
    printf("Total of of array odd elements = %d, average = %.2f\n", totalOdds, avergageOdds);

    return 0;
}