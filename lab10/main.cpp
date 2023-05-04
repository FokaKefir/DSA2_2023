#include <iostream>
#include "greedy.h"
using namespace std;

/**
 * 102/322988
 */

/* file.in
1 2 5
1 4 3
1 5 4
2 3 2
2 5 1
3 4 3
4 5 7
 */

int main() {
    vector<Edge> edges = readFromFile("file.in");
    printEdgeList(edges);
    printf("\n");
    vector<Edge> treeEdges = kruskal(edges);
    printEdgeList(treeEdges);
}