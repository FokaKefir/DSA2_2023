#include <iostream>
#include "edgelist_functions.h"

using namespace std;

int main() {
    vector<Edge> edges = edgeListFromFile(FILENAME);
    printEdgeList(edges, "out1.txt");

    int **matrix;
    int rows;
    readAdjacencyMatrix(matrix, rows, FILENAME);
    printAdjacencyMatrix(matrix, rows, "out2.txt");

    vector<Point> neighborhoodList = neighborhoodListFromFile(FILENAME);
    printNeighborhoodList(neighborhoodList, "out3.txt");
}