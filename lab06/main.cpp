#include <iostream>
#include "functions.h"

using namespace std;

void task1() {
    int n = 5;
    int *v = new int[n] {3, 4, 1, 7, 8};
    cout << sumVector(n, v);
}

void task2() {
    int n = 5;
    int *v = new int[n] {3, 4, 1, 7, 8};
    cout << minVector(n, v);
}

void task3() {
    int n = 5;
    int *v = new int[n] {9, 4, 1, 7, 8};
    cout << maxVector(n, v);
}

void task4() {
    int n = 5;
    int *v = new int[n] {9, 4, 1, 7, 8};
    cout << avgVector(n, v, 0, 0);
}

void task5() {
    int n = 5;
    int *v = new int[n] {9, 4, 1, 7, 8};
    cout << prodVector(n, v);
}

void task6() {
    int n = 5;
    int *v = new int[n] {9, 4, 2, 7, 8};
    cout << sumVectorEvenK(n, v, 2, 0);
}

void task7() {
    int num = 12345;
    cout << numberOfDigits(num);
}

void task8() {
    int num = 12321;
    int k = 1;
    int mNum = mirrorNumber(num, k);
    cout << mNum << endl;
    cout << "Is " << num << " palindrome? " << isPalindrome(num);
}

void task9() {
    int num = 10010001;
    cout << isBinaryNumber(num);
}

void task10() {
    int num = 12234;
    cout << areDigitsAscending(num);
}

void task14() {
    int n = 7;
    int* v = new int[n] {3, 5, -7, 8, -1, 6};
    sort(v, v + 7);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    int num = -1;
    cout << stepsBinarySearch(v, num, 0, n - 1);
}

int main() {
    task14();
}