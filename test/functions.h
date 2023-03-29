#ifndef DSA2_FUNCTIONS_H
#define DSA2_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>

#define MIN_VALUE 2
#define MAX_VALUE 99

using namespace std;

// task 1

void generateRandomElementsRecursive(int *v, int n);
void printElementRecursive(int *v, int n);
int sumOddElementsRecursive(int *v, int n);
bool primeTest(int x, int div);
int countPrimeElementsRecursive(int *v, int n);
void sortElements(int *v, int n);
int nrStepBinarySearchRecursive(int *v, int low, int high, int x, int steps);
int maxElementsRecursive(int *v, int n);
int countDigitsMaxElementRecursive(int e);
int sumDigitsMaxElementRecursive(int e);
float averageDigitsMaxElement(int sum, int count);

// task2
struct Point {
    vector<int> neighbors;
};

vector<Point> readNeighborsFromFile(char *filename);
void printNeighbors(vector<Point> points);
int nrOfOneWayStreets(vector<Point> points);
bool haveAccessToEveryBuildingFromX(vector<Point> points, int x);


#endif //DSA2_FUNCTIONS_H
