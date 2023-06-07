#include "functions.h"

int deleteFirstAndReverse(int number) {
    // Számjegyek szétválasztása
    int lastDigit = number % 10;
    int remainingNumber = number / 10;

    // Rekurzió alapfeltétele
    if (remainingNumber == 0) {
        return 0;
    }

    // Rekurziós hívás a maradék számra
    int reversed = deleteFirstAndReverse(remainingNumber);

    // A maradék számot megfordítjuk és hozzáadjuk az utolsó számjegyet
    reversed = (reversed * 10) + lastDigit;

    return reversed;
}

void task1() {
    int num = 123789;
    cout << "Number: " << num << endl;
    cout << "Number after removing non-prime digits: " << primeDigits(num, 1) << endl;
    cout << "Number after removing first and last digit: " << removeFirstAndLastDigitFromNumber(num, 0) << endl;
}

void task2() {
    string characters = "wxzy";
    sort(characters.begin(), characters.end());
    string res = "";
    permutation(characters, res);
}

void task3() {
    int num = 1234567;
    int n = numberOfDigits(num);
    int digit = 5;
    if (binarySearchDigit(num, digit, 0, n - 1, 1)) {
        cout << digit << " is in " << num << endl;
    } else {
        cout << "not found\n";
    }
}

void task4() {
    vector<Bottle> bottles = readBottlesFromFile("bottles.txt");
    int maxWeight = 89;
    vector<Bottle> fBottles = filterBottles(bottles, maxWeight);
    printBottles(fBottles);
    cout << "Total weight: " << totalWeightOfBottles(fBottles) << endl;
}

int main() {
    task4();
}