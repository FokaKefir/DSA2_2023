#ifndef DSA2_BACKTRACKING_H
#define DSA2_BACKTRACKING_H

#include <iostream>
#include <string>

using namespace std;

void permutation(int n, int ind, int *v, bool *b);
void permutationK(int n, int ind, int *v, bool *b, int k);
void permutationKFast(int n, int *v, bool *b, int k);
void printVec(int n, int *v);

void permStart(int n, string *eggs, string exEgg1, string exEgg2);
void permEggs(int n, int ind, int *v, bool *b, string *eggs, int k1, int k2);
void printEggs(int n, int *v, string *eggs);

#endif //DSA2_BACKTRACKING_H
