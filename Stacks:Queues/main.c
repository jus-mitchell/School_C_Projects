#include "lab7.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {

    Stack s = initStack();

    int array01[5] = {1,2,3,4,5};
    int array02[7] = {7,6,5,4,3,2,1};

    printf("%d\n", pushStack(s, array01));

    pushStack(s, array02);

    printf("%d\n", getSize(s));

    printf("%d\n", stackContains(s, array02));

    int * p = popStack(s);

    printf("%d\n", stackContains(s, array02));

    printf("%d\n", p[2]);

    freeStack(s);

}