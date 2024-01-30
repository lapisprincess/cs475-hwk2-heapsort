#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
    buildHeap(A, n);

    while (n > 0) {
        swap(&A[n-1], &A[0]);
        n--;
        heapify(A, 0, n-1);
    }

    // while n > 0:
        // swap A[n-1] with A[0], since A[0] is the smallest number.
        // A[n-1] now sorted in place, so decrement n
        // Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
}


/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
    for (int i = n / 2; i >= 0 ; i--) heapify(A, i, n);
}


/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
    int smaller = i;
    int left, right;

    left = 2 * (i + 1) - 1;
    if (left < n && A[i].salary > A[left].salary) smaller = left;

    right = 2 * (i + 1);
    if (right < n && A[i].salary > A[right].salary) smaller = right;

    if (smaller != i) {
        swap(&A[smaller], &A[i]);
        heapify(A, smaller, n);
    }
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
    Employee temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}


/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
    for (int i = 0; i < n; i++) {
        Employee emp = A[i];
        printf(" [id=%s sal=%d]", emp.name, emp.salary);
    }
}
