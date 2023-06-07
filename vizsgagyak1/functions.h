#ifndef DSA2_FUNCTIONS_H
#define DSA2_FUNCTIONS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

// 1. feladat
bool isPrimeRec(int num, int k);
int primeDigits(int num, int k);
int removeFirstAndLastDigitFromNumber(int num, int numberOfDigits);


// 2. feladat
void permutation(string chars, string res);

// 3. feladat
int numberOfDigits(int num);
int getDigitFromBackOfNumber(int num, int pos);
bool binarySearchDigit(int num, int digit, int f, int l, int steps);

// 4. feladat
struct Bottle {
    int price;
    int weight;
};

vector<Bottle> readBottlesFromFile(char *filename);
void printBottles(vector<Bottle> bottles);
vector<Bottle> filterBottles(vector<Bottle> bottle, int maxWeight);
int totalWeightOfBottles(vector<Bottle> bottles);

#endif //DSA2_FUNCTIONS_H
