#include "myarray.h"

int *initializeArray(int numOfElements) {
    return new int[numOfElements];
}

void readArray(int *&array, int &numOfElements, char *input) {
    ifstream fin(input);
    if (!fin) {
        cout << "Cannot open file\n";
        exit(1);
    }
    fin >> numOfElements;
    array = initializeArray(numOfElements);
    if (array == nullptr) {
        cout << "Memory error!\n";
        exit(1);
    }
    for (int i = 0; i < numOfElements; ++i) {
        fin >> array[i];
    }
    fin.close();
}

void printArray(int *array, int numOfElements) {
    if (array == nullptr) {
        cout << "Nullptr\n";
        exit(1);
    }
    for (int i = 0; i < numOfElements; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void printReverseArray(int *array, int numOfElements) {
    if (array == nullptr) {
        cout << "Nullptr\n";
        exit(1);
    }
    for (int i = numOfElements - 1; i >= 0; i--) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void printArrayToFile(int *array, int numOfElements, char *dest) {
    if (array == nullptr) {
        cout << "Error\n";
        exit(1);
    }
    ofstream fout(dest);
    if (!fout) {
        cout << "Cannot open file\n";
        exit(1);
    }
    for (int i = 0; i < numOfElements; ++i) {
        fout << array[i] << " ";
    }
    fout.close();
}

void sortArray(int *array, int numOfElements) {
    sort(array, array + numOfElements);
}

