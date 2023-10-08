/* 
Name: Justice Mitchell
*/

#include <stdio.h> 

// my function prototypes
int Summation(int n);
int Square(int x);

// prints the value of the summation
int main(void){

    for(int i = 1; i <= 10; i++) {
        printf("Summation of 1 through %d squared = %d\n", i, Summation(i));
    }

}

// squares an integer x and returns the square
int Square(int x) {
    return (x * x);
}

// returns the summation of 1 squared through n squared
int Summation(int n) {

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += Square(i);
    }

    return sum;

}