#include "backtracking.h"

int s = 0;

void printVec(int n, int *v) {
    for (int i = 0; i < n; ++i) {
        cout << v[i] + 1 << " ";
    }
    cout << endl;

}

void permutation(int n, int ind, int *v, bool *b) {
    if (ind == n - 1) {
        s++;
        //if (s == 15)
        printVec(n, v);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!b[i]) {
            v[ind] = i;
            b[i] = true;
            permutation(n, ind + 1, v, b);
            b[i] = false;
        }
    }
}

void cakePerm(int n, int ind, int s, Cake *cakes, bool *b) {

}

void printCakes(int n, Cake *cakes) {
    for (int i = 0; i < n; ++i) {
        cout << cakes[i].name << "(" << cakes[i].price << ") ";
    }
    cout << endl;
}
