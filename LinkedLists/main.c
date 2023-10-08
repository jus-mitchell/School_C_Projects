#include <stdio.h>
#include <stdlib.h>
#include "lab5.h"

int main(void) {

    int array01[5] = {1,2,3,4,5};
    int array02[7] = {7,6,5,4,3,2,1};
    Node * list;

    makeList(&list);

    insertAtTail(&list, (void*) array01);
    insertAtTail(&list, (void*) array02);

    printf("%d\n", getSize(list));

    int * p = removeFromHead(&list);

    printf("%d\n", getSize(list));

    printf("%d\n", p[0]);

}