#ifndef DSA2_FUNCTIONS_H
#define DSA2_FUNCTIONS_H

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int sumVector(int n, int *v);
int minVector(int n, int *v);
int maxVector(int n, int *v);
double avgVector(int n, int *v, int ind, int sum);
int prodVector(int n, int *v);
int sumVectorEvenK(int n, int *v, int k, int ind);
int numberOfDigits(int num);
int mirrorNumber(int num, int &k);
bool isPalindrome(int num);
bool isBinaryNumber(int num);
bool areDigitsAscending(int num);

int stepsBinarySearch(int *v, int num, int f, int l);

#endif //DSA2_FUNCTIONS_H
