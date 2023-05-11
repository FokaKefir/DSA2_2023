#ifndef DSA2_KRUSKAL_H
#define DSA2_KRUSKAL_H

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

extern int n;

vector <Edge> readFromFile(char *input);
void printEdgeList(vector<Edge> edges);
vector<Edge> kruskal(vector<Edge> edges);

#endif //DSA2_KRUSKAL_H
