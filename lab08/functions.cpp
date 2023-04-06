#include "functions.h"

vector <Points> neighborhoodListFromFile(char *input) {
    int nrPoints, nrEdges;
    ifstream f(input);
    f >> nrPoints >> nrEdges;
    vector <Point> points(nrPoints);
    for (int i = 0; i < nrEdges; i++) {
        int from, to;
        f >> from >> to;
        points.at(from - 1).neighbors.push_back(to - 1);
        points.at(to - 1).neighbors.push_back(from - 1);
    }
    for (int i = 0; i < nrPoints; ++i) {
        char c;
        f >> c;
        points[i].character = c;
    }
    for (int i = 0; i < nrPoints; i++) {
        sort(points.at(i).neighbors.begin(), points.at(i).neighbors.end());
    }
    return points;
}

vector<int> bfs_vector(vector <Point> &points, int startingPoint) {
    for (int i = 0; i < points.size(); i++) {
        points.at(i).color = 0;
        points.at(i).father = 0;
        points.at(i).distance = INT_MAX;
    }
    int distance = 0;
    points.at(startingPoint).color = 1;
    points.at(startingPoint).distance = (distance++);
    queue<int> queue;
    vector<int> bfs;
    queue.push(startingPoint);
    while (!queue.empty()) {
        int u = queue.front();
        bfs.push_back(u);
        for (int i = 0; i < points.at(u).neighbors.size(); i++) {
            if (points.at(points.at(u).neighbors.at(i)).color == 0) {
                points.at(points.at(u).neighbors.at(i)).color = 1;
                points.at(points.at(u).neighbors.at(i)).father = 0;
                points.at(points.at(u).neighbors.at(i)).distance = (distance++);
                queue.push(points.at(u).neighbors.at(i));
            }
        }
        points.at(u).color = 2;
        queue.pop();
    }
    return bfs;
}

void print_characters(vector<int> vec, vector<Point> points) {
    for (int element : vec) {
        cout << points[element].character;
    }
    cout << endl;
}

void print_vector(vector<int> vector1) {
    for (int element : vector1) {
        cout << element + 1 << " ";
    }
    cout << endl;
}

void print_points(vector<Point> points) {

    for (int i = 0; i < points.size(); ++i) {
        cout << "point: " << i + 1 <<
             " color: " << points.at(i).color <<
             " distance: " << points.at(i).distance <<
             " father: " << points.at(i).father + 1 << "\n";
    }
    cout << endl;
}
