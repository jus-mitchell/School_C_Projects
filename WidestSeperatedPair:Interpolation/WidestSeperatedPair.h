#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

typedef struct bucketStruct {
    float min;
    float max;
    int size;
} Bucket;

float findClusterExtreme(float * array, int n);
float findClusterExtremeWithQsort(float * array, int n);
float findClusterExtremeBsort(float * array, int n);


