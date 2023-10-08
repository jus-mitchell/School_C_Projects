#include <stdio.h>
#include <stdlib.h>

char * strAlloc(int size);
int strLen(char *str);
void strCpy(char *source, char *dest);
int strRev(char *source, char *dest);
void strFree(char *str);