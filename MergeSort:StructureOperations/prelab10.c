#include "prelab10.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void MergeByID(Employee ** array, int l, int m, int r) {

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    Employee * L[n1];
    Employee * R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i]->ID <= R[j]->ID) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }


} 


void SortByID(Employee ** inputArray, int first, int last) {

    int mid;

    if (last <= first) {
        return;
    }
    mid = (first + last) / 2;
    SortByID(inputArray, first, mid);
    SortByID(inputArray, mid+1, last);
    MergeByID(inputArray, first, mid, last);

}


Employee ** sortBySSN(Employee ** inputArray, int n) {

    int violationsFound, i;
    Employee * temp;

    do {
        violationsFound = 0;
        for (i=0; i < n-1; i++) {
            if (inputArray[i]->SSN > inputArray[i+1]->SSN) { 
                temp = inputArray[i];
                inputArray[i] = inputArray[i+1];
                inputArray[i+1] = temp;
                violationsFound = 1;
            }
        }
    } while (violationsFound);

    return inputArray;
    
}

int binarySearchByID(int query, Employee ** inputArray, int low, int high) {

    int mid;

    if (low == high) {
        return -1;
    } 

    mid = low + (high - low)/2;

    if (query < inputArray[mid]->ID) {
        return binarySearchByID(query, inputArray, low, mid);
    }

    else if (query > inputArray[mid]->ID) {
        return binarySearchByID(query, inputArray, mid+1, high);
    }

    return mid;

}

int binarySearchBySSN(int query, Employee ** inputArray, int low, int high) {

    int mid;

    if (low == high) {
        return -1;
    } 

    mid = low + (high - low)/2;

    if (query < inputArray[mid]->SSN) {
        return binarySearchBySSN(query, inputArray, low, mid);
    }

    else if (query > inputArray[mid]->SSN) {
        return binarySearchBySSN(query, inputArray, mid+1, high);
    }

    return mid;

}


EmpDatabase createSearchableEmployeeDB(Employee ** inputArray, int n) {

    EmpDatabase outputDatabase;
    int i;

    outputDatabase.empArraySortedByID = malloc(n * sizeof(Employee *));
    outputDatabase.empArraySortedBySSN = malloc(n * sizeof(Employee *));
    outputDatabase.ec = 0;

    if (outputDatabase.empArraySortedByID) {
        sortByID(inputArray, 0, n-1);
        Employee ** sortedArrayByID = inputArray;
        for(i = 0; i < n; i++) {
            outputDatabase.empArraySortedByID[i] = sortedArrayByID[i];
        }
        outputDatabase.ec = 0;
    }

    if (outputDatabase.empArraySortedBySSN) {
        Employee ** sortedArrayBySSN = sortBySSN(inputArray, n);
        for(i = 0; i < n; i++) {
            outputDatabase.empArraySortedBySSN[i] = sortedArrayBySSN[i];
        }
        outputDatabase.ec = 0; 
    }

    else if(!(outputDatabase.empArraySortedByID) || !(outputDatabase.empArraySortedBySSN)) {
        outputDatabase.ec = 1;
    }

    outputDatabase.size = n;

    return outputDatabase;  

}

Employee * findEmpBySSN(int SSN, EmpDatabase inputDatabase) {

    Employee ** empArray = inputDatabase.empArraySortedBySSN;

    return empArray[binarySearchBySSN(SSN, empArray, 0, inputDatabase.size - 1)];

}

Employee * findEmpByID(int ID, EmpDatabase inputDatabase) {

    Employee ** empArray = inputDatabase.empArraySortedByID;

    return empArray[binarySearchBySSN(ID, empArray, 0, inputDatabase.size - 1)];

}

void freeEmpDatabase(EmpDatabase inputDatabase) {

    free(inputDatabase.empArraySortedByID);
    free(inputDatabase.empArraySortedBySSN);

}

int getErrorCode(EmpDatabase inputDatabase) {

    return inputDatabase.ec;

}

int countEmpsInSalaryRange(int min, int max, EmpDatabase inputDatabase) {

    return (binarySearchByID(max, inputDatabase.empArraySortedByID, 0, inputDatabase.size - 1) -  binarySearchByID(min, inputDatabase.empArraySortedByID, 0, inputDatabase.size - 1));
    
}
