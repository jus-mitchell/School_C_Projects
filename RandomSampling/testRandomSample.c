#include "header.h"

int testRandomSample() {

    srand48(time(NULL)); // sets the seed for drand48() so it doesnt have to be set in main()

    int target = 20; // the integer from the sequence we are testing for. Could be any integer know to be in the sequence
    int testSequence[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,INT_MAX}; // sequence used for testing

    int count = 0;  // Count of how many times the target integer is obtained

    for (int i = 0; i < 1000000; i++) { // loops one million times
        int sample = obtainRandomSample(testSequence);
        if (sample == target) {
            count++;
        }
    }

    double expectedRatio = 1.0 / 20;  // Because there are 20 integers in the sequence
    double observedRatio = (double) count / 1000000; //

    // printf("\n%f\n", observedRatio);

    if (fabs(observedRatio - expectedRatio) < 0.01) { // 0.01 is the accepted deviation
        return 0;  // Signifies that the obtainRandomSmaple passed the test
    } else {
        return -1;  // Signifies that the obtainRandomSmaple failed the test
    }
}
