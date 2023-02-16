#ifndef DSA2_MYMATRIX_H
#define DSA2_MYMATRIX_H

#include <fstream>
#include <iostream>

using namespace std;

int **initializeMatrix(int numOfRows, int numOfColumns);
void readMatrix(int **&matrix, int &numOfRows, int &numOfColumns, char input[20]);
void printMatrix(int **matrix, int numOfRows, int numOfColumns);


#endif //DSA2_MYMATRIX_H
