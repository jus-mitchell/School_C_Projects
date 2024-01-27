    /* 
	 Name: Justice Mitchell
 	*/

#include <stdio.h>

int main(void) {

    int i;
    int j;

    for (i = 1; i <=99; i += 1) {

        j = (i % 10);

        if ( (i  == 10 ) ) {
           printf("Ten, ");
         }
        else if ( i / 10 == 1 && i != 10) {
           switch ( j ) {
              case 1:
                  printf("Eleven, ");
                  break;
              case 2: 
                  printf("Twelve, ");
                  break;
              case 3: 
                  printf("Thirteen, ");
                  break; 
              case 4: 
                  printf("Fourteen, ");
                  break;
              case 5: 
                  printf("Fifteen, ");
                  break;
              case 6: 
                  printf("Sixteen, ");
                  break;
              case 7: 
                  printf("Seventeen, ");
                  break;
              case 8: 
                  printf("Eighteen, ");
                  break;
              case 9: 
                  printf("Nineteen, ");
                  break;   
           }
        } 
        else if ( i /10 == 2 ) {
          printf("Twenty ");
        }

        else if ( i /10 == 3 ) {
          printf("Thirty ");
        }

        else if ( i /10 == 4 ) {
          printf("Forty ");
        }

        else if ( i /10 == 5 ) {
          printf("Fifty ");
        }

        else if ( i /10 == 6 ) {
          printf("Sixty ");
        }

        else if ( i /10 == 7 ) {
          printf("Seventy ");
        }

        else if ( i /10 == 8 ) {
          printf("Eighty ");
        }

        else if ( i /10 == 9 ) {
          printf("Ninety ");
        } 

        if ( i / 10 != 1) {

          switch ( j ) {

              case 1:
                printf("One, ");
                break;
              case 2:
                printf("Two, ");
                break;
              case 3:
                printf("Three, ");
                break;
              case 4:
                printf("Four, ");
                break;
              case 5:
                printf("Five, ");
                break;
              case 6:
                printf("Six, ");
                break;
              case 7:
                printf("Seven, ");
                break;
              case 8:
                printf("Eight, ");
                break;
              case 9:
                printf("Nine, ");
                break;
          }
        }
   }

 }