#ifndef DSA2_FUNCTIONS_H
#define DSA2_RECURSION_H

using namespace std;
#include <iostream>
#include "constants.h"
#include <fstream>
#include <iomanip>

/**
*
* @param x basis
* @param n exponent
* @return n power of x iterative
*/
int power1(int x, int n);

/**
*
* @param x basis
* @param n exponent
* @return n-th power of x recursive with constant value
*/
int recPower1(int x, int n);

/**
*
* @param x basis
* @param n exponent
* @return n-th power of x recursive with a given factor
*/
int recPower2(int x, int n);

/**
*
* @param a first number
* @param b second number
* @return greatest common divisor
*/
int recGCD(int a, int b);

/**
*
* @param a first number
* @param b second number
* @param a1 first number
* @param b1 second number
* @return least common multiple
*/
int recLCM1(int a, int b, int a1, int b1);

/**
*
* @param a first number
* @param b second number
* @param a1 first number
* @param b1 second number
* @return least common multiple using function GCD
*/
int recLCM2(int a, int b);

/**
*
* @param a array
* @param n number of array
* @param f input file
*/
void recReadArray(int *a, int n,ifstream *f);

/**
*
* @param a array
* @param n number of array
*/
void recPrintArray(int *a, int n);

/**
*
* @param a array
* @param n number of array
* @return sum odd elements of array a
*/
int sumOddElementsOfArray(int *a, int n);

/**
*
* @param n natural number
*/
void printDigitsOfNumber(int n);
void printDigitsOfNumberReverse(int n);

/**
*
* @param n natural number
* @param numberOfDigits initial is 0
* @param sum initial is 0
* @return average digits number of number n
*/
float averageDigitsOfNumber(int n, int numberOfDigits, int sum);

#endif //DSA2_FUNCTIONS_H
