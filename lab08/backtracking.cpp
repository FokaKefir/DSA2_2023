#include "backtracking.h"

void permutation(int n, int ind, int *v, bool *b) {
    if (ind == n) {
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

void permutationK(int n, int ind, int *v, bool *b, int k) {
    if (ind == n) {
        if (v[0] == k - 1)
            printVec(n, v);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!b[i]) {
            v[ind] = i;
            b[i] = true;
            permutationK(n, ind + 1, v, b, k);
            b[i] = false;
        }
    }
}

void printVec(int n, int *v) {
    for (int i = 0; i < n; ++i) {
        cout << v[i] + 1 << " ";
    }
    cout << endl;

}

void permutationKFast(int n, int *v, bool *b, int k) {
    b[k - 1] = true;
    v[0] = k - 1;
    permutation(n, 1, v, b);
    b[k - 1] = false;
}

void permStart(int n, string *eggs, string exEgg1, string exEgg2) {
    int k1, k2;
    for (int i = 0; i < n; ++i) {
        if (eggs[i] == exEgg1)
            k1 = i;
        else if (eggs[i] == exEgg2)
            k2 = i;
    }

    int *v = new int[n];
    bool *b = new bool[n]{false};
    permEggs(n, 0, v, b, eggs, k1, k2);
}

void permEggs(int n, int ind, int *v, bool *b, string *eggs, int k1, int k2) {
    if (ind == n) {
        printEggs(n, v, eggs);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!b[i] && (ind == 0
                      || (ind > 0 && i == k1 && v[ind - 1] != k2)
                      || (ind > 0 && i == k2 && v[ind - 1] != k1)
                      || (ind > 0 && i != k1 && i != k2))) {
            v[ind] = i;
            b[i] = true;
            permEggs(n, ind + 1, v, b, eggs, k1, k2);
            b[i] = false;
        }
    }
}

void printEggs(int n, int *v, string *eggs) {
    for (int i = 0; i < n; ++i) {
        cout << eggs[v[i]] << " ";
    }
    cout << endl;
}


