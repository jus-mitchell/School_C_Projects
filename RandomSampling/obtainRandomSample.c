#include "header.h"

int obtainRandomSample(int * sequence) { // obtains a random sample from a sequence of integers terminated by INT_MAX
    int k;
    int s = sequence[0]; // Initializing the selected sample

    for (k = 0; sequence[k] != INT_MAX; k++) {
        if (drand48() < 1.0 / (k + 1)) { // will select the kth element with 1/k probability
            s = sequence[k];
        }
    }

    return s; 
}