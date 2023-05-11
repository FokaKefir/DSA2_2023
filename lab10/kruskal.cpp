#include <algorithm>
#include "kruskal.h"

int n = 0;

vector<Edge> readFromFile(char *input) {
    ifstream fin(input);
    if (!fin) {
        cout << "File open error\n";
        exit(1);
    }

    vector<Edge> edges = {};

    int from, to, w;
    while (fin >> from >> to >> w) {
        Edge edge;
        edge.from = from;
        edge.to = to;
        edge.weight = w;
        edges.push_back(edge);
        n = max(n, max(from, to));
    }

    fin.close();
    return edges;
}

void printEdgeList(vector<Edge> edges) {
    for (Edge edge : edges) {
        cout << edge.from << " - " << edge.to << ": " << edge.weight << "\n";
    }
}

bool comp(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}


vector<Edge> kruskal(vector<Edge> edges) {
    int *t = new int[n + 1];
    for (int i = 1; i <= n; ++i) {
        t[i] = i;
    }

    sort(edges.begin(), edges.end(), comp);

    vector<Edge> treeEdges;
    int i = 0;
    while (treeEdges.size() < n - 1 && i < edges.size()) {
        Edge edge = edges[i];
        if (t[edge.from] != t[edge.to]) {
            int k1 = t[edge.from];
            int k2 = t[edge.to];
            for (int j = 1; j <= n; ++j) {
                if (t[j] == k1)
                    t[j] = k2;
            }
            treeEdges.push_back(edge);
        }
        i++;
    }
    return treeEdges;
}


