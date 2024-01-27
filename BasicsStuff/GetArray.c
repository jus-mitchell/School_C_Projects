// Name: Justice Mitchell

#include <stdio.h> 

// function prototypes
void GetIntArray(int * outputArray, int * count);

void PrintArray(int * array, int count);

int TotalArray(int * array, int count);

double AvgArray(int * array, int count);

// calls functions and defines variables
int main(void) {
    
    int size = 100;
    printf("Welcome to Lab 8!\n");
    int array[size];
    GetIntArray(array, &size);
    PrintArray(array, size);
    printf("Total of array = %d\n", TotalArray(array, size));
    printf("Average of array = %.3f\n", AvgArray(array, size));
}

// gets the array values and array size from user
void GetIntArray(int * outputArray, int * count) {

    printf("How many integers would you like to enter?\n");
    scanf("%d", count);

    for(int i = 0; i < *count; i++) {
        printf("Enter element #%d: ", (i));
        scanf("%d", &outputArray[i]); 
    }

}
// prints the array
void PrintArray(int * array, int count) {

    printf("Here are the %d elements of your array\n", count);
    for(int i=0; i < count; i++) {
        printf("Element %d: %d\n", i, array[i]);
    }
}
// calculates the total of the array elements
int TotalArray(int * array, int count) {   
    int total = 0; 
    for(int i = 0; i < count; i++) {
        total += array[i];
    }
    return total;
}
// calculates the average of the array elements
double AvgArray(int * array, int count) {
    return (double) TotalArray(array, count) / count;
}

