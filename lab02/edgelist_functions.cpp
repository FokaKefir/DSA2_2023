

#include "edgelist_functions.h"

vector<Edge> edgeListFromFile(char *input) {
    ifstream fin(input);
    if (!fin) {
        cout << FILE_OPEN_ERROR_MESSAGE;
        exit(FILE_OPEN_ERROR_CODE);
    }

    vector<Edge> edges;
    int nPoints, nEdges;
    fin >> nPoints >> nEdges;
    for (int i = 0; i < nEdges; ++i) {
        Edge e;
        fin >> e.begin >> e.end;
        edges.push_back(e);
    }

    fin.close();
    return edges;
}

void printEdgeList(vector<Edge> edges, char *output) {
    ofstream fout(output);
    if (!fout) {
        cout << FILE_OPEN_ERROR_MESSAGE;
        exit(FILE_OPEN_ERROR_CODE);
    }

    for (Edge e : edges) {
        fout << e.begin << " " << e.end << "\n";
    }
    fout.close();
}

int **initializeAdjacencyMatrix(int rows, int cols) {
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

void readAdjacencyMatrix(int **&matrix, int &rows, char *input) {
    ifstream fin(input);
    if (!fin) {
        cout << FILE_OPEN_ERROR_MESSAGE;
        exit(FILE_OPEN_ERROR_CODE);
    }

    int nPoints, nEdges;
    fin >> nPoints >> nEdges;
    rows = nPoints;
    matrix = initializeAdjacencyMatrix(rows + 1, rows + 1);
    for (int i = 0; i < nEdges; ++i) {
        int x, y;
        fin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }

    fin.close();
}


void printAdjacencyMatrix(int **matrix, int rows, char *output) {
    ofstream fout(output);
    if (!fout) {
        cout << FILE_OPEN_ERROR_MESSAGE;
        exit(FILE_OPEN_ERROR_CODE);
    }

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= rows; ++j) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
}

vector<Point> neighborhoodListFromFile(char *input) {
    ifstream fin(input);
    if (!fin) {
        cout << FILE_OPEN_ERROR_MESSAGE;
        exit(FILE_OPEN_ERROR_CODE);
    }

    int nPoints, nEdges;
    fin >> nPoints >> nEdges;
    vector<Point> neighborhoodList(nPoints + 1);
    for (int i = 0; i < nEdges; ++i) {
        Edge e;
        fin >> e.begin >> e.end;
        neighborhoodList[e.begin].neighbors.push_back(e.end);
        neighborhoodList[e.end].neighbors.push_back(e.begin);
    }

    for (int i = 1; i < neighborhoodList.size(); ++i) {
        std::sort(neighborhoodList[i].neighbors.begin(), neighborhoodList[i].neighbors.end());
    }

    fin.close();
    return neighborhoodList;
}

void printNeighborhoodList(vector<Point> neighborhoodList, char *output) {
    ofstream fout(output);
    if (!fout) {
        cout << FILE_OPEN_ERROR_MESSAGE;
        exit(FILE_OPEN_ERROR_CODE);
    }

    for (int i = 1; i < neighborhoodList.size(); ++i) {
        vector<int> neighbors = neighborhoodList[i].neighbors;
        fout << neighbors.size() << ": ";
        for (int point : neighbors) {
            fout << point << " ";
        }
        fout << "\n";
    }

    fout.close();
}





