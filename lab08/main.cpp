#include "functions.h"
#include "backtracking.h"
using namespace std;

void task1() {
    vector<Points> points = neighborhoodListFromFile("input.txt");
    vector<int> res1 = bfs_vector(points, 0);
    print_vector(res1);
    print_characters(res1, points);
    //print_points(points);
}

void task2() {
    int n = 5;
    bool *b = new bool[n] {false};
    int *v = new int[n];
    permutationK(n, 0, v, b, 5);
    cout << endl;
    permutationKFast(n, v, b, 5);
}

void task3() {
    ifstream fin("tojas.txt");
    if(!fin) {
        printf("File open error!\n");
        exit(1);
    }

    int n;
    fin >> n;

    string *eggs = new string[n];
    for (int i = 0; i < n; ++i) {
        fin >> eggs[i];
    }

    permStart(n, eggs, "sarga", "zold");

    fin.close();
}

int main() {
    task3();
}