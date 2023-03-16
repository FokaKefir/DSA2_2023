#include <iostream>
#include "function.h"

using namespace std;

int main() {
    vector<Points> points = neighborhoodListFromFile("input.txt");
    vector<int> res1 = bfs_vector(points, 0);
    print_vector(res1);
    print_points(points);

    vector<int> res2 = DFS(points);
    print_vector(res2);
    print_points(points);


}