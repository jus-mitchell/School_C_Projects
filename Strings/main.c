#include <stdio.h>
#include "lab3.h"

void populateString(char * str);

int main(void) {

    char * source = strAlloc(2);
    char * dest = strAlloc(7);

    populateString(source);




    strCpy(source, dest);


    printf("%s\n", dest);

    //printf("%c\n", dest[4]);

    //printf("%d\n", strLen(source) - 1);

}

// void addNullTerminator(char * str) {
//     int index = strLen(str) - 1;
//     str[index];
// }

void populateString(char * str) {
    
    str[0] = 'H';
    str[1] = 'E';
//     //str[strLen(str) - 1] = '\0';
}

