#ifndef DSA2_FUNCTIONS_H
#define DSA2_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef struct Point{
    int color;
    int father;
    int distance;
    char character;
    vector<int>neighbors;
}Points;
vector <Points> neighborhoodListFromFile(char * input);
vector <int> bfs_vector(vector <Point>&points,int startingPoint);
void print_vector(vector<int>vector1);
void print_points(vector<Point> points);
void print_characters(vector<int> vec, vector<Point> points);

#endif //DSA2_FUNCTIONS_H
