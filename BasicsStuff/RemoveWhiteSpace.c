/*
Name Justice Mitchell
 */

// includes
#include <stdio.h>
#include <ctype.h>

// Symbolic Constants
#define S1 "1, 2, 3, 4 tell me that you love me more.  Sleepless long nights, that is what my youth was for."
#define S2 "\t99 dreams I have had.  In every 1 a red balloon."
#define S3 "And you'll start cryin' 96 tears."
#define S4 "I demand the sum of.....$1,000,000.00!"
#define STRINGCOUNT 4

////////////////
// Prototypes //
////////////////
char * Filter(char *s);

// Main
int main(void)
{
    char s[STRINGCOUNT][256]=
    {
        S1,S2,S3,S4,
    };

    printf("**** Original Strings ****\n");
    for (int i=0;i<STRINGCOUNT;i++)
    {
        printf("#%d: %s\n",i,s[i]);
    }

    printf("\n\n**** Strings after filtering ****\n");
    for (int i=0;i<STRINGCOUNT;i++)
    {
        printf("#%d: %s\n",i,Filter(s[i]));
    }
}

// Filters a given string
char * Filter(char *s)
{
    // Removes all whitspace from the string
    int nonSpaceCount = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        if(!(isspace(s[i])) && !(ispunct(s[i]))) {
            s[nonSpaceCount] = s[i];
            nonSpaceCount++;
        }
    }
    s[nonSpaceCount] = '\0';

    // Makes upper case letters into lower case and lowercase into uppercase
    for(int i = 0; s[i] != '\0'; i++) {
        if(islower(s[i])) {
            s[i] = toupper(s[i]);
        }
        else if(isupper(s[i])) {
            s[i] = tolower(s[i]);
        }
    }
  
    return s;
}