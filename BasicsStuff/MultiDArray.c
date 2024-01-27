// Name: Justice Mitchell

#include <stdio.h>
#define COLS 3
#define ROWS 12
#define CURVEROWS 4

void Print2DArray(int array[][COLS], int rows);

void PrintStudentGrades(int grades[][COLS], int cutoffs[][COLS], int whichrow); 

//char convertCS(int arrayValue);

//char convertMath(int arrayValue);

//char convertEnglish(int arrayValue);

int main(void) {
    // grades array
    int numGrades[ROWS][COLS] = {{30, 66, 90}, {95, 88, 95}, {93, 97, 86}, {98, 77, 98}, {99, 92, 90}, {47, 32, 27}, {97, 99, 75}, {85, 95, 91}, {96, 91, 99}, {94, 90, 74}, {98, 98, 90}, {76, 82, 98}};
    // curve array
    int curve[CURVEROWS][COLS] = {{85, 90, 90}, {75, 80, 75}, {60, 70, 55}, {50, 60, 40}};

    printf("Here are the scores:\n");
    // calls the Print2DArray func for numGrades array
    Print2DArray(numGrades, ROWS);

    printf("\nHere are the grade cutoffs:\n");
    // calls the Print2DArray func for curve array
    Print2DArray(curve, CURVEROWS);

    printf("\nHere are the grades:\n");
    // calls the func to print the grades as letters
    PrintStudentGrades(numGrades, curve, ROWS);

}

// prints the contents of an array
void Print2DArray(int array[][COLS], int rows) {

    for(int i = 0; i < rows; i++) {

        printf("ROW %d: ", i);

        for(int j = 0; j < COLS; j++) {

            printf("%d ", array[i][j]);            
        }

        printf("\n");
    }
}
// converts a CS1050 grade to a letter grade
/* char convertCS(int arrayValue) {
    if (arrayValue >= 85) {
        return 'A';
    }
    else if(arrayValue >= 75) {
        return 'B';
    }
    else if(arrayValue >= 60) {
        return 'C';
    }
    else if(arrayValue >= 50) {
        return 'D';
    }
    else {
        return 'F';
    }
    
}
// converts a Math grade to a letter grade
char convertMath(int arrayValue) {
    if (arrayValue >= 90) {
        return 'A';
    }
    else if(arrayValue >= 80) {
        return 'B';
    }
    else if(arrayValue >= 70) {
        return 'C';
    }
    else if(arrayValue >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
    
} 
// converts an English grade to a letter grade
char convertEnglish(int arrayValue) {
    if (arrayValue >= 90) {
        return 'A';
    }
    else if(arrayValue >= 75) {
        return 'B';
    }
    else if(arrayValue >= 55) {
        return 'C';
    }
    else if(arrayValue >= 40) {
        return 'D';
    }
    else {
        return 'F';
    }
    
} */

char convertGrade(int cutoffs[][COLS], int column, int arrayValue) {

        if (arrayValue >= cutoffs[0][column]) {
            return 'A';
        }
        else if (arrayValue >= cutoffs[1][column]) {
            return 'B';
        }
        else if (arrayValue >= cutoffs[2][column]) {
            return 'C';
        }
        else if (arrayValue >= cutoffs[3][column]) {
            return 'D';
        }
        else {
            return 'F';
        }
    
}

/*char convertMathGrade(int cutoffs[][COLS], int arrayValue) {

        if (arrayValue >= cutoffs[0][1]) {
            return 'A';
        }
        else if (arrayValue >= cutoffs[1][1]) {
            return 'B';
        }
        else if (arrayValue >= cutoffs[2][1]) {
            return 'C';
        }
        else if (arrayValue >= cutoffs[3][1]) {
            return 'D';
        }
        else {
            return 'F';
        }
    
}*/

/*char convertEnglishGrade(int cutoffs[][COLS], int arrayValue) {

        if (arrayValue >= cutoffs[0][2]) {
            return 'A';
        }
        else if (arrayValue >= cutoffs[1][2]) {
            return 'B';
        }
        else if (arrayValue >= cutoffs[2][2]) {
            return 'C';
        }
        else if (arrayValue >= cutoffs[3][2]) {
            return 'D';
        }
        else {
            return 'F';
        }
    
}*/

// prints the students grade as a letter grade
void PrintStudentGrades(int grades[][COLS], int cutoffs[][COLS], int rows) {
    
    
    for (int i = 0; i < rows; i++) {
         
         printf("Student %d: ", i);

         for(int j = 0; j < COLS; j++) {
            if (j == 0) {
                printf("%c ", convertGrade(cutoffs, j, grades[i][j]));
            }
            else if (j == 1) {
                printf("%c ", convertGrade(cutoffs, j, grades[i][j]));
            }
            else if (j == 2) {
                printf("%c ", convertGrade(cutoffs, j, grades[i][j]));
            }
         }

         printf("\n");

     }

}