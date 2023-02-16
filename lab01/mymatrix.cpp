#include "mymatrix.h"

int **initializeMatrix(int numOfRows, int numOfColumns) {
    int **matrix = new int*[numOfRows];
    for (int i = 0; i < numOfRows; ++i) {
        matrix[i] = new int[numOfColumns];
    }
    return matrix;
}

void readMatrix(int **&matrix, int &numOfRows, int &numOfColumns, char *input) {
    ifstream fin(input);
    if (!fin) {
        cout << "Cannot open file\n";
        exit(1);
    }
    fin >> numOfRows >> numOfColumns;
    matrix = initializeMatrix(numOfRows, numOfColumns);
    if (matrix == nullptr) {
        cout << "Memory error!\n";
        exit(1);
    }
    for (int i = 0; i < numOfRows; ++i) {
        for (int j = 0; j < numOfColumns; ++j) {
            fin >> matrix[i][j];
        }
    }
    fin.close();
}

void printMatrix(int **matrix, int numOfRows, int numOfColumns) {
    if (matrix == nullptr) {
        cout << "Memory error!\n";
        exit(1);
    }
    for (int i = 0; i < numOfRows; ++i) {
        for (int j = 0; j < numOfColumns; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
