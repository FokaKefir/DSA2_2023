#include <climits>
#include "function.h"

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
            queue.pop();
            points.at(u).color = 2;
    }
    return bfs;
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


vector<int> DFS(vector<Point> &mPoints) {
    for (int i = 0; i < mPoints.size(); i++) {
        mPoints.at(i).color = 0;
        mPoints.at(i).father = 0;
        mPoints.at(i).distance = INT_MAX;
    }
    vector<int> dfs;
    for (int i = 0; i < mPoints.size(); i++) {
        if (mPoints.at(i).color == 0) {
            dfsRun(mPoints, i, dfs);
            mPoints.at(i).father = -1;
        }
    }
    return dfs;
}

void dfsRun(vector<Point> &mPoints, int current, vector<int> &dfs) {
    static int dis = 0;
    mPoints.at(current).distance = dis++;
    dfs.push_back(current);
    mPoints.at(current).color = 1;
    for (int v = 0; v < mPoints.at(current).neighbors.size(); v++) {
        if (mPoints.at(mPoints.at(current).neighbors.at(v)).color == 0) {
            mPoints.at(mPoints.at(current).neighbors.at(v)).father = current;//kimenti a csomópont apját
            //mPoints.at(mPoints.at(current).neighbors.at(v)).distance = (dis++); //feltolti a distance mezot
            dfsRun(mPoints, mPoints.at(current).neighbors.at(v) , dfs);
        }
    }
    mPoints.at(current).color = 2;
}
