#ifndef BEJARASOK_FUNCTIONS_H
#define BEJARASOK_FUNCTIONS_H

#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;

typedef struct Point{
    int color;
    int father;
    int distance;
    vector<int>neighbors;
}Points;
vector <Points> neighborhoodListFromFile(char * input);
vector <int> bfs_vector(vector <Point>&points,int startingPoint);
void print_vector(vector<int>vector1);
void print_points(vector<Point> points);
vector<int> DFS(vector<Point> &mPoints);
void dfsRun(vector<Point> &points, int current, vector<int> &dfs);

#endif //BEJARASOK_FUNCTIONS_H
