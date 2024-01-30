#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main(int argc, char *argv[])
{
    Employee ls[MAX_EMPLOYEES];

    for (int i = 0; i < 5; i++) {
        Employee emp;
        printf("Name: ");   scanf("%s", emp.name);
        printf("Salary: "); scanf("%d", &emp.salary);
        ls[i] = emp;
        printf("\n");
    }

    printf("Before: ");
    printList(ls, MAX_EMPLOYEES);

    heapSort(ls, MAX_EMPLOYEES);

    printf("\nAfter:  ");
    printList(ls, MAX_EMPLOYEES);

    printf("\n");
    return 1;
}
