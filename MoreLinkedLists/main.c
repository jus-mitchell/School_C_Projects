#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

int main(void) {

    int array01[5] = {1,2,3,4,5};
    int array02[7] = {7,6,5,4,3,2,1};
    Node * list;
    int i;

    makeList(&list);

    insertAtTail(list, (void*) array01);
    insertAtTail(list, (void*) array02);
    insertAtTail(list, (void*) array02);

    printf("%d\n", getSize(list));

    int * p = removeFromHead(list);

    for(i = 0; i < 5; i++) {
        printf("%d\n", p[i]);
    }





}