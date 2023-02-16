#include <iostream>
#include "myarray.h"
#include "mymatrix.h"

void task1() {
    int n;
    int *array;
    readArray(array, n, "file1.in");
    printArray(array, n);
    printReverseArray(array, n);
    sortArray(array, n);
    printArrayToFile(array, n, "file1.out");
}

void task2() {
    int n, m;
    int **matrix;
    readMatrix(matrix, n, m, "matrix.in");
    printMatrix(matrix, n, m);
}

int main() {
    task1();
    //task2();
}
