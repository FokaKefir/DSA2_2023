#include <iostream>
#include "recursion.h"
using namespace std;

int main() {
    ifstream fin("in.txt");
    int n;
    fin >> n;
    int* a = new int[n];
    recReadArray(a, n, &fin);
    recPrintArray(a, n);
    cout << "\n";
    cout << "Sum of odd elements: " << sumOddElementsOfArray(a, n);
}