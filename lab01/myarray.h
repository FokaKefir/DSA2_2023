#ifndef DSA2_MYARRAY_H
#define DSA2_MYARRAY_H

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int *initializeArray(int numOfElements);
void readArray(int *&array, int &numOfElements, char input[20]);
void printArray(int *array, int numOfElements);
void printReverseArray(int *array, int numOfElements);
void printArrayToFile(int *array, int numOfElements, char dest[20]);
void sortArray(int *array, int numOfElements);

#endif //DSA2_MYARRAY_H
