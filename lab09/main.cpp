#include "backtracking.h"

using namespace std;

void task1() {
    int n;
    cin >> n;
    int *v = new int[n];
    bool *b = new bool[n];
    permutation(n, 0, v, b);
    cout << s;
}

void task2() {
    int n = 6;
    Cake *cakes = new Cake[n] {
            {"papanaj", 12},
            {"dobos", 14},
            {"marlenka", 20},
            {"mezes", 5},
            {"retes", 10},
            {"tiramisu", 15}
    };
    bool *b = new bool[n];
    s = 0;
    cakePerm(n, 0, s, cakes, b)
}

int main() {
    task1();
}