#ifndef DSA2_EDGELIST_FUNCTIONS_H
#define DSA2_EDGELIST_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "constants.h"

#define FILENAME "input.txt"

using namespace std;

typedef struct Point {
    vector<int> neighbors;
} Point;

typedef struct Edge {
    int begin, end;
} Edge;

// edgelist
vector<Edge> edgeListFromFile(char *input);
void printEdgeList(vector<Edge> edges, char *output);

// adjacency matrix
int **initializeAdjacencyMatrix(int rows, int cols);
void readAdjacencyMatrix(int **&matrix, int &rows, char *input);
void printAdjacencyMatrix(int **matrix, int rows, char *output);

// neighborhood list
vector<Point> neighborhoodListFromFile(char *input);
void printNeighborhoodList(vector<Point> neighborhoodList, char *output);

#endif //DSA2_EDGELIST_FUNCTIONS_H
