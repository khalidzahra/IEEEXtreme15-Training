/*

    You are given flights route map of a country consisting of N cities and M undirected flight routes. Each city has an airport and each airport can work as layover. The airport will be in two states, Loading and Running. In loading state, luggage is loaded into the planes. In the running state, planes will leave the airport for the next city. All the airports will switch their states from Loading to Running and vice versa after every T minutes. You can cross a city if its airport state is running. Initially, all the airports are in running state. At an airport, if its state is loading, you have to wait for it to switch its state to running. The time taken to travel through any flight route is C minutes. Find the lexicographically smallest path which will take the minimum amount of time (in minutes) required to move from city X to city Y.

    It is guaranteed that the given flight route map will be connected. Graph won't contain multiple edges and self loops. A self loop is an edge that connects a vertex to itself.

    Input Format:
    The first line contains 4 space separated integers, N, M, T and C. Next M lines contains two space separated integers each, U and V denoting that there is a bidirectional road between city U and city V. Next line contains two space separated integers, X and Y.

    Output Format:
    In the first line print an integer K, denoting the number of city you need to go through to reach city Y from the city X. In next line, print K space separated integers denoting the path which will take the minimum amount of time (in minutes) required by to move from city X to city Y. There can be multiple paths. Print the lexicographically smallest one.

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> traverse(vector<vector<int>> &g, int start, int end, int n) {
    vector<bool> visited(n + 1, false);
    visited[start] = true;
    queue<int> q;
    q.push(start);
    vector<int> prev(n + 1, -1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        prev.push_back(node);
        if (node == end)
            break;
        for (int next: g[node]) {
            if (!visited[next]) {
                q.push(next);
                prev[next] = node;
                visited[next] = true;
            }
        }
    }
    return prev;
}

int main() {
    int n, m, t, c, x, y;
    cin >> n >> m >> t >> c;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> x >> y;
    for (int i = 0; i < graph.size(); i++) sort(graph[i].begin(), graph[i].end());
    vector<int> prev = traverse(graph, x, y, n), path;
    int curr = y;
    while (curr != -1)  {
        path.push_back(curr);
        curr = prev[curr];
    }
    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for (int i: path) cout << i << " ";
    return 0;
}
