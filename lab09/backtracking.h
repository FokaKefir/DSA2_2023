#ifndef DSA2_BACKTRACKING_H
#define DSA2_BACKTRACKING_H

#include <iostream>
#include <string>

using namespace std;

extern int s;

void printVec(int n, int *v);
void permutation(int n, int ind, int *v, bool *b);

struct Cake {
    char name[20];
    int price;
};

void printCakes(int n, Cake *cakes);
void cakePerm(int n, int ind, int s, Cake *cakes, bool *b);

#endif //DSA2_BACKTRACKING_H
