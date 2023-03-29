#include "functions.h"

void generateRandomElementsRecursive(int *v, int n) {
    if (n == 0)
        return;
    v[n - 1] = rand() % (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
    generateRandomElementsRecursive(v, n - 1);
}

void printElementRecursive(int *v, int n) {
    if (n == 0)
        return;
    printElementRecursive(v, n - 1);
    cout << v[n - 1] << " ";
}

int sumOddElementsRecursive(int *v, int n) {
    if (n == 0)
        return 0;
    if (v[n - 1] % 2 == 1)
        return v[n - 1] + sumOddElementsRecursive(v, n - 1);
    return sumOddElementsRecursive(v, n - 1);
}

bool primeTest(int x, int div) {
    if (div * div > x)
        return true;
    if (x % div == 0 or x % 2 == 0)
        return false;
    if (div == 2)
        return primeTest(x, 3);
    return primeTest(x, div + 2);

}

int countPrimeElementsRecursive(int *v, int n) {
    if (n == 0)
        return 0;
    if (primeTest(v[n - 1], 2))
        return 1 + countPrimeElementsRecursive(v, n - 1);
    return countPrimeElementsRecursive(v, n - 1);
}

void sortElements(int *v, int n) {
    int k = n;
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < k - 1; ++i) {
            if (v[i + 1] < v[i]) {
                swap(v[i], v[i + 1]);
                ok = true;
            }
        }
        k--;
    }
}

int nrStepBinarySearchRecursive(int *v, int low, int high, int x, int steps) {
    int mid = (low + high) / 2;
    if (v[mid] == x)
        return steps;
    else if (v[mid] < x) {
        return nrStepBinarySearchRecursive(v, mid + 1, high, x, steps + 1);
    } else if (v[mid] > x) {
        return nrStepBinarySearchRecursive(v, low, mid - 1, x, steps + 1);
    }
    return -1;
}

int maxElementsRecursive(int *v, int n) {
    if (n == 1)
        return v[0];
    return max(v[n - 1], maxElementsRecursive(v, n - 1));
}

int countDigitsMaxElementRecursive(int e) {
    if (e < 10)
        return 1;
    return 1 + countDigitsMaxElementRecursive(e / 10);
}

int sumDigitsMaxElementRecursive(int e) {
    if (e == 0)
        return 0;
    return e % 10 + sumDigitsMaxElementRecursive(e / 10);
}

float averageDigitsMaxElement(int sum, int count) {
    return (float) sum / (float) count;
}

vector<Point> readNeighborsFromFile(char *filename) {
    int n, m;
    ifstream fin(filename);
    if (!fin) {
        cout << "Cannot open file\n";
        exit(1);
    }

    fin >> n >> m;
    vector<Point> points(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        points.at(a).neighbors.push_back(b);
    }
    for (int i = 0; i < n; ++i) {
        sort(points.at(i).neighbors.begin(), points.at(i).neighbors.end());
    }
    return points;
}

void printNeighbors(vector<Point> points) {
    for (int i = 0; i < points.size(); ++i) {
        cout << i << ": ";
        for (int k : points.at(i).neighbors) {
            cout << k << " ";
        }
        cout << endl;
    }
}

int nrOfOneWayStreets(vector<Point> points) {
    int s = 0;
    for (int i = 0; i < points.size(); ++i) {
        for (int k : points.at(i).neighbors) {
            if (find(points.at(k).neighbors.begin(), points.at(k).neighbors.end(), i) != points.at(k).neighbors.end())
                s++;
        }
    }
    return s;
}

bool haveAccessToEveryBuildingFromX(vector<Point> points, int x) {
    int n = points.size();
    return (n == points.at(x).neighbors.size() + 1);
}
