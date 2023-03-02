#include "recursion.h"

int power1(int x, int n) {
    int pow = 1;
    for (int i = 0; i < n; ++i) {
        pow = pow * x;
    }
    return pow;
}

int recPower1(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        if (n % 2 == 0) {
            int pow = recPower1(x, n / 2);
            return pow * pow;
        } else {
            int pow = recPower1(x, (n - 1) / 2);
            return pow * pow * x;
        }
    }
}

int recPower2(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return recPower2(x, n - 1) * x;
    }
}

int recGCD(int a, int b) {
    if (a == b) return a;
    else if (a > b) return recGCD(a - b, b);
    else return recGCD(a, b - a);
}

int recLCM2(int a, int b) {
    return a * b / recGCD(a, b);
}

int recLCM1(int a, int b, int a1, int b1) {
    if (a > b)
        if (a % b1 == 0) return a;
        else return recLCM1(a + a1, b, a1, b1);
    else if (b % a1 == 0)
        return b;
    else return recLCM1(a, b + b1, a1, b1);

}

void recReadArray(int *a, int n, ifstream *f) {
    if (n == 0)
        return;
    recReadArray(a, n - 1, f);
    (*f) >> a[n - 1];
}

void recPrintArray(int *a, int n) {
    if (n == 0)
        return;
    recPrintArray(a, n - 1);
    cout << a[n - 1] << " ";

}

int sumOddElementsOfArray(int *a, int n) {
    if (n == 0)
        return 0;
    if (a[n - 1] % 2 != 0) /// odd
        return sumOddElementsOfArray(a, n - 1) + a[n - 1];
    return sumOddElementsOfArray(a, n - 1);
}

void printDigitsOfNumber(int n) {
    if(n/10==0) cout<<n<<' ';
    else {
        printDigitsOfNumber(n/10);
        cout<<n%10<<' ';
    }
}
void printDigitsOfNumberReverse(int n) {
    if(n/10==0) cout<<n<<' ';
    else {
        cout<<n%10<<' ';
        printDigitsOfNumberReverse(n/10);
    }
}

float averageDigitsOfNumber(int n, int numberOfDigits, int sum) {
    if(n/10==0) {
        sum+=n;
        numberOfDigits++;
        return (float)sum/numberOfDigits;
    }
    sum=sum+n%10;
    return averageDigitsOfNumber(n/10,numberOfDigits+1,sum);
}
