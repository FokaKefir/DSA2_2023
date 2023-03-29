#include <iostream>
#include "functions.h"

using namespace std;

void task1() {
    int n = 12;
    int *v = new int[n];

    srand(time(0));
    generateRandomElementsRecursive(v, n);
    printElementRecursive(v, n);
    cout << "\n";
    cout << "Sum of odd elements: " << sumOddElementsRecursive(v, n) << "\n";
    cout << "Number of primes in vector " << countPrimeElementsRecursive(v, n) << "\n";

    int maxi = maxElementsRecursive(v, n);
    int numOfDigits = countDigitsMaxElementRecursive(maxi);
    int sumOfDigits = sumDigitsMaxElementRecursive(maxi);
    cout << "Max element in vector: " << maxi << "\n";
    cout << "Number of digits in max element: " << numOfDigits << "\n";
    cout << "Sum of digits in max element: " << sumOfDigits << "\n";
    cout << "Average of digits in maxi: " << averageDigitsMaxElement(sumOfDigits, numOfDigits) << "\n";

    cout << "\n";
    int num = v[n / 2];
    sortElements(v, n);
    cout << "Elements after sort:\n";
    printElementRecursive(v, n);
    cout << "\n";
    cout << "Number of steps to find " << num << ": " << nrStepBinarySearchRecursive(v, 0, n - 1, num, 1) << "\n";

    delete[] v;
}

void task2() {
    vector<Point> points = readNeighborsFromFile("file.in");
    printNeighbors(points);
    cout << "Number of one way streets: " << nrOfOneWayStreets(points) << "\n";
    int k = 0;
    cout << haveAccessToEveryBuildingFromX(points, k);
}


int main() {
    //task1();
    task2();
}