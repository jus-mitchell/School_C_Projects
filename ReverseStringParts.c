// Name: Justice Mitchell

#include <stdio.h>
#define MAXSIZE 512
//Prototypes
void getString(char * const stringArray);
int getStringLength(const char * const stringArray, int * length);
void reverseString(char * const stringArray, int length);
//main function
int main(void) {

char string[MAXSIZE];
int stringLength;
printf("***Welcome to lab9***\n");
getString(string);
printf("You entered %s\n", string);
getStringLength(string, &stringLength);
reverseString(string, stringLength);
printf("Reversed string: %s\n", string);
}
// gets string form user
void getString(char * const stringArray) {
    printf("Please enter a string: ");
    scanf("%s", stringArray);
}
//gets string length
int getStringLength(const char * const stringArray, int * length) {
    int i;
    for(i = 0; stringArray[i] != '\0'; i++);
    *length = i;
    return i;
}
// reverses string
void reverseString(char * const stringArray, int length) {
		
		if (length % 2 == 0) {
		if(length >= 6) {
		for(int i = 0; i < (length/2)-2; i++) {
			int hold;
			hold = stringArray[i];
			stringArray[i] = stringArray[((length/2)-1)-i];
			stringArray[((length/2)-1)-i] = hold;
		}
		for(int i = 0; i < length/2-2; i++) {
			int hold;
                        hold = stringArray[length/2+i];
                        stringArray[length/2+i] = stringArray[((length)-1)-i];
                        stringArray[(length-1)-i] = hold;
		}
		}
		else if (length > 1 && length < 6) {
		for(int i = 0; i < 1; i++) {
                        int hold;
                        hold = stringArray[i];
                        stringArray[i] = stringArray[((length/2)-1)-i];
                        stringArray[((length/2)-1)-i] = hold;
		}
		for(int i = 0; i < 1; i++) {
                        int hold;
                        hold = stringArray[length/2+i];
                        stringArray[length/2+i] = stringArray[((length)-1)-i];
                        stringArray[(length-1)-i] = hold;
		}
		}
		}
		else {
		if (length > 5){
		for(int i = 0; i < (length/2)-2; i++) {
                        int hold;
                        hold = stringArray[i];
                        stringArray[i] = stringArray[((length/2)-1)-i];
                        stringArray[((length/2)-1)-i] = hold;
                }
                for(int i = 0; i < length/2-2; i++) {
                        int hold;
                        hold = stringArray[length/2+1+i];
                        stringArray[length/2+1+i] = stringArray[((length)-1)-i];
                        stringArray[(length-1)-i] = hold;
                }
		}
		if (length == 5) {
		 for(int i = 0; i < 1; i++) {
                        int hold;
                        hold = stringArray[i];
                        stringArray[i] = stringArray[((length/2)-1)-i];
                        stringArray[((length/2)-1)-i] = hold;
                }
                for(int i = 0; i < 1; i++) {
                        int hold;
                        hold = stringArray[length/2+1+i];
                        stringArray[length/2+1+i] = stringArray[((length)-1)-i];
                        stringArray[(length-1)-i] = hold;
                }
		}
		}
}

