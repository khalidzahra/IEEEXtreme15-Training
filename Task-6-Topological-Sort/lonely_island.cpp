/*

    There are many islands that are connected by one-way bridges, that is, if a bridge connects islands  and , then you can only use the bridge to go from  to  but you cannot travel back by using the same. If you are on island , then you select (uniformly and randomly) one of the islands that are directly reachable from  through the one-way bridge and move to that island. You are stuck on an island if you cannot move any further. It is guaranteed that after leaving any island it is not possible to come back to that island.

    Find the island that you are most likely to get stuck on. Two islands are considered equally likely if the absolute difference of the probabilities of ending up on them is <= 1e-9.

*/

#include "bits/stdc++.h"

#define vvi vector<vector<int>>

using namespace std;

double findMax(vector<double> &v, vvi &g) {
    double m = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > m && g[i].size() == 0) m = v[i];
    }
    return m;
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vvi g(n + 1);
    vector<int> degree(n + 1);
    vector<double> prob(n + 1);
    prob[r] = 1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        degree[v]++;
    }
    queue<int> q;
    for (int i = 1; i < n + 1; i++) {
        if (degree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int child : g[node]) {
            degree[child]--;
            prob[child] += prob[node] * (1.0 / g[node].size());
            if (degree[child] == 0) q.push(child);
        }
    }
    double maxProb = findMax(prob, g);
    for (int i = 1; i < n + 1; i++) {
        if (g[i].size() == 0 && abs(prob[i] - maxProb) <= 1e-9) cout << i << " ";
    }
    return 0;
}

