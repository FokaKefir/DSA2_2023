#include "functions.h"

// region 1. feladat
bool isPrimeRec(int num, int k) {
    if (num <= 1)
        return false;

    if (k * k > num)
        return true;

    if (num % k == 0)
        return false;


    if (k == 2)
        return isPrimeRec(num, 3);
    return isPrimeRec(num, k + 2);
}

int primeDigits(int num, int k) {
    if (num == 0)
        return 0;
    if (num % 10 == 2 or num % 10 == 3 or num % 10 == 5 or num % 10 == 7) {
        return num % 10 * k + primeDigits(num / 10, k * 10);
    } else {
        return primeDigits(num / 10, k);
    }
}

int removeFirstAndLastDigitFromNumber(int num, int numberOfDigits) {
    if (num < 10)
        return 0;
    if (numberOfDigits == 0)
        return removeFirstAndLastDigitFromNumber(num / 10, numberOfDigits + 1);
    return (num % 10) + 10 * removeFirstAndLastDigitFromNumber(num / 10, numberOfDigits + 1);
}
// endregion

// region 2. feladat
bool promising(string res, char c) {
    for (char c1 : res) {
        if (c1 == c)
            return false;
    }

    int length = res.size();
    if (length == 0 and c == 'x')
        return false;

    if (length > 0 and c == 'z' and res[length - 1] == 'w')
        return false;

    if (length > 0 and c == 'w' and res[length - 1] == 'z')
        return false;

    return true;
}

void permutation(string chars, string res) {
    if (res.size() == 2) {
        cout << res << endl;
        return;
    }
    for (char c : chars) {
        if (promising(res, c)) {
            res.push_back(c);
            permutation(chars, res);
            res.pop_back();
        }
    }
}
// endregion

// region 3. feladat
int numberOfDigits(int num) {
    if (num < 10)
        return 1;
    else
        return 1 + numberOfDigits(num / 10);
}

int getDigitFromBackOfNumber(int num, int pos) {
    while (pos != 0 and num > 9) {
        num /= 10;
        pos--;
    }
    if (pos != 0)
        return -1;
    return num % 10;
}

bool binarySearchDigit(int num, int digit, int f, int l, int steps) {
    if (f > l)
        return false;

    int pos = (f + l) / 2;
    int digitFromPos = getDigitFromBackOfNumber(num, pos);
    if (digitFromPos == digit) {
        cout << "steps: " << steps << endl;
        return true;
    } else {
        if (digitFromPos < digit)
            return binarySearchDigit(num, digit, f, pos - 1, steps + 1);
        else
            return binarySearchDigit(num, digit, pos + 1, l, steps + 1);
    }

}

// endregion

// region 4. feladat

vector<Bottle> readBottlesFromFile(char *filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Error opening file\n";
        exit(1);
    }

    int n;
    fin >> n;

    vector<Bottle> bottles;
    for (int i = 0; i < n; ++i) {
        int price, weight;
        fin >> price >> weight;
        Bottle b = {price, weight};
        bottles.push_back(b);
    }

    fin.close();
    return bottles;
}

void printBottles(vector<Bottle> bottles) {
    for (Bottle b : bottles) {
        cout << b.price << " " << b.weight << endl;
    }
    cout << endl;
}

vector<Bottle> filterBottles(vector<Bottle> bottles, int maxWeight) {
    sort(bottles.begin(), bottles.end(), [](const Bottle &b1, const Bottle &b2){
        return b1.weight < b2.weight;
    });

    vector<Bottle> fBottles;
    for (Bottle b : bottles) {
        if (b.weight <= maxWeight) {
            fBottles.push_back(b);
            maxWeight -= b.weight;
        } else {
            break;
        }
    }

    return fBottles;
}

int totalWeightOfBottles(vector<Bottle> bottles) {
    int w = 0;
    for (Bottle b : bottles) {
        w += b.weight;
    }
    return w;
}

// endregion



