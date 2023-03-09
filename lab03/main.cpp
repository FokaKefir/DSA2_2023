#include <iostream>
#include "recursion.h"
using namespace std;

int main() {
    ifstream fin("in.txt");
    if (!fin) {
        cout << FILE_OPEN_ERROR_MESSAGE;
        exit(FILE_OPEN_ERROR_CODE);
    }

    int n;
    fin >> n;
    int* a = new int[n];
    recReadArray(a, n, &fin);
    fin.close();
    recPrintArray(a, n);
    cout << "\n";
    cout << "Sum of odd elements: " << sumOddElementsOfArray(a, n);
}