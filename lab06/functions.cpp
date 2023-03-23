#include "functions.h"

int sumVector(int n, int *v) {
    if (n == 0) {
        return 0;
    }
    return v[n - 1] + sumVector(n - 1, v);

}

int minVector(int n, int *v) {
    if (n == 1)
        return v[0];
    return min(v[n - 1], minVector(n - 1, v));
}

int maxVector(int n, int *v) {
    if (n == 1)
        return v[0];
    return max(v[n - 1], maxVector(n - 1, v));
}

double avgVector(int n, int *v, int ind, int sum) {
    if (ind == n)
        return (double) sum / n;
    return avgVector(n, v, ind + 1, sum + v[ind]);
}

int prodVector(int n, int *v) {
    if (n == 0)
        return 1;
    return v[n - 1] * prodVector(n - 1, v);
}

int sumVectorEvenK(int n, int *v, int k, int ind) {
    if (k == 0)
        return 0;
    if (ind == n) {
        return -1;
    }
    if (v[ind] % 2 == 0) {
        int res = sumVectorEvenK(n, v, k - 1, ind + 1);
        if (res == -1)
            return -1;
        return v[ind] + res;
    }
    return sumVectorEvenK(n, v, k, ind + 1);
}

int numberOfDigits(int num) {
    if (num < 10)
        return 1;
    return 1 + numberOfDigits(num / 10);
}

int mirrorNumber(int num, int &k) {
    if (num < 10)
        return num;
    int res = mirrorNumber(num / 10, k);
    k *= 10;
    return (num % 10) * k + res;
}

bool isPalindrome(int num) {
    int k = 1;
    return (num == mirrorNumber(num, k));
}

bool isBinaryNumber(int num) {
    if (num % 10 > 1)
        return false;
    if (num == 0)
        return true;
    return isBinaryNumber(num / 10);
}

bool areDigitsAscending(int num) {
    if (num < 10)
        return true;
    int b = (num / 10) % 10;
    int a = num % 10;
    return (b <= a) && areDigitsAscending(num / 10);
}

int stepsBinarySearch(int *v, int num, int f, int l) {
    int ind = (f + l) / 2;
    if (v[ind] == num)
        return 1;
    else {
        if (v[ind] > num) {
            return 1 + stepsBinarySearch(v, num, f, ind - 1);
        } else {
            return 1 + stepsBinarySearch(v, num, ind + 1, l);
        }
    }
}

