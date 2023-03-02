#include "recursion.h"

void recReadArray(int *a, int n, ifstream *f) {
    if (n == 0)
        return;
    recReadArray(a, n - 1, f);
    (*f) >> a[n - 1];
}

void recPrintArray(int *a, int n) {
    if (n == 0)
        return;
    recPrintArray(a, n - 1);
    cout << a[n - 1] << " ";

}

int sumOddElementsOfArray(int *a, int n) {
    if (n == 0)
        return 0;
    if (a[n - 1] % 2 != 0) /// odd
        return sumOddElementsOfArray(a, n - 1) + a[n - 1];
    return sumOddElementsOfArray(a, n - 1);
}
