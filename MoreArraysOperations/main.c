#include "lab4.h"
#include <stdlib.h>
#include <stdio.h>

void setColorCount(InventoryItem * array, int index, short colorCount);

int main(void) {

    InventoryItem * inventoryArray;
    int i,j, size = 5;

    inventoryArray = makeArray(size, sizeof(InventoryItem));

    printf(" size is %d\n", getSize(inventoryArray));

    for(i = 0; i < getSize(inventoryArray); i++) {
        setColorCount(inventoryArray, i, 3);
    }

    for(j = 0; j < getSize(inventoryArray); j++) {
        printf("%d\n", inventoryArray[j].colors);
    }
    
    printf("%d\n", countWithColors(inventoryArray, 4));

    // for(i = 0; i < getSize(inventoryArray); i++) {
    //     printf("ID is %d, weight is %f, stockcount is %d\n", inventoryArray[i].ID, inventoryArray[i].weight, inventoryArray[i].stockCount);
    // }

    freeArray(inventoryArray);

}

void setColorCount(InventoryItem * array, int index, short colorCount) {

     array[index].colors = colorCount;

}

// int setEmpSalary(Employee * employeeArray, int empID, float salary) {
//     Employee * employee;
//     employee = getEmployeeByID(employeeArray, empID);
//     if(employee != NULL) {
//         employee->salary = salary;
//         return 0;
//     }
//     else {
//         return 1;
//     }
// }