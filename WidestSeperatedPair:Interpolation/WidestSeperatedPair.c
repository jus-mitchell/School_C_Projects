#include "jsmfvy.h"

// Finds the minimum and maximum elements in an array of floats.
void findMinMax(float * array, int n, float *min, float *max) {
    // Initialize min and max to the first element in the array.
    *min = *max = array[0];

    // Iterate over the array starting from the second element.
    for (int i = 1; i < n; i++) {
        // If the current element is less than the current min, update min.
        if (array[i] < *min) {
            *min = array[i];
        }
        // If the current element is greater than the current max, update max.
        if (array[i] > *max) {
            *max = array[i];
        }
    }
}

// Generates an index for a value 'x' relative to the range [min, max] scaled to [0, n-1].
int genIndex(float min, float max, float x, int n) {
    // Scales down x's position within the range min to max to a range 0 to n-1.
    return (int)(((x - min) / (max - min)) * (n - 1));
}

// Returns the maximum value from the last non-empty bucket in an array of buckets.
float maxInBucketArray(Bucket * B, int n) {
    // Start from the second last bucket.
    int i = n-2;
    // Move backwards until a non-empty bucket is found.
    while(B[i].size == 0) {
        i--;
    }
    // Return the max value from the last non-empty bucket.
    return B[i].max;
}

// Returns the minimum value from the first non-empty bucket in an array of buckets.
float minInBucketArray(Bucket * B) {
    // Start from the first bucket.
    int i = 0;
    // Move forwards until a non-empty bucket is found.
    while (B[i].size == 0) {
        i++;
    }
    // Return the min value from the first non-empty bucket.
    return B[i].min;
}

// Inserts a float value into a bucket, updating the bucket's properties.
void insertBucket(float n, Bucket * B) {
    // Handle the insert based on the current size of the bucket.
    switch (B->size) {
        case 0: // Bucket is empty.
            // Set the bucket's min and max to the new number and increment size.
            B->max = B->min = n;
            B->size = 1;
            break;
        case 1: // Bucket contains one element.
            // Determine if new number should be new min or max and update size.
            if(n < B->min) {
                B->min = n;
                B->size = 2;
            } else if(n > B->max) {
                B->max = n;
                B->size = 2;
            }
            break;
        case 2: // Bucket contains two elements.
            // Update min or max if the new number is outside current range.
            if(n < B->min) {
                B->min = n;
            } else if(n > B->max) {
                B->max = n;
            }
            break;
        default:
            // For other cases, no action is needed.
            break;
    }
}

// Creates an array of buckets for given float values, excluding the min and max of the array.
Bucket * createArrayBuckets(float * array, int n, float min, float max) {
    // Allocate memory for the bucket array.
    Bucket * bucketArray = malloc((n-1) * sizeof(Bucket));

    // If memory allocation fails, return NULL.
    if(!bucketArray) {
        return NULL;
    } else {
        // Initialize all buckets to empty.
        for (int i = 0; i < n - 1; i++) {
            bucketArray[i].size = 0;
        }
        // Insert each array element into a corresponding bucket, if it's not the min or max.
        for (int i = 0; i < n; i++) {
            if(array[i] != min && array[i] != max) {
                insertBucket(array[i], &(bucketArray[genIndex(min, max, array[i], n)]));
            }
        }
        // Return the populated bucket array.
        return bucketArray;
    }
}

// Finds and returns the number with the largest gap to its next neighbor in a sorted version of the array.
// O(n) time complexity
float findClusterExtreme(float * array, int n) {
    // If there is one or no element, return the maximum float value as an error indication.
    if (n <= 1) {
        return FLT_MAX;
    } else {
        // Find the min and max of the array.
        float min, max;
        findMinMax(array, n, &min, &max);

        // If the array has only two elements, return the smaller one.
        if (n == 2) {
            return min;
        } else {
            // Create a bucket array for the float values.
            Bucket * bucketArray = createArrayBuckets(array, n, min, max);

            // If memory allocation for the buckets failed, return maximum float value as error.
            if (!bucketArray) {
                return FLT_MAX;
            } else {
                // Find the smallest number that has the largest gap with its next number.
                float minOfPair = min;
                float widestSeparation = minInBucketArray(bucketArray) - min;

                // Iterate through the buckets to find the maximum gap.
                for (int i = 0; i < n - 1; i++) {
                    if (bucketArray[i].size != 0) {
                        int j = i + 1;
                        while (j < n - 1 && bucketArray[j].size == 0) {
                            j++;
                        }
                        if (j < n - 1 && bucketArray[j].size != 0) {
                            float gap = bucketArray[j].min - bucketArray[i].max;
                            if (gap > widestSeparation) {
                                widestSeparation = gap;
                                minOfPair = bucketArray[i].max;
                            }
                        }
                        i = j - 1;
                    }
                }

                // Compare the largest gap at the end of the array to the current largest gap.
                if ((max - maxInBucketArray(bucketArray, n)) > widestSeparation) {
                    minOfPair = maxInBucketArray(bucketArray, n);
                }

                // Free the allocated memory for the bucket array.
                free(bucketArray);

                // Return the smallest number with the largest gap to its next neighbor.
                return minOfPair;
            }
        }
    }
}

// Comments are generated by AI

