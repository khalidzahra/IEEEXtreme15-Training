#include "bits/stdc++.h"

#define pil pair<int, long>
#define INF (long)1e15

using namespace std;

void dijkstra(int node, vector<vector<pil>> &g, vector<long> &arr, int length) {
    bool v[length];
    priority_queue<pil > q;
    q.push({node, 0});
    arr[node] = 0;
    while (!q.empty()) {
        int n = q.top().first;
        long s = q.top().second;
        q.pop();
        v[n] = true;
        for (pil p : g[n]) {
            if (v[p.first]) continue;
            long c = s + p.second;
            if (arr[p.first] > c) {
                arr[p.first] = c;
                q.push({p.first, c});
            }
        }
    }
}

void solve(int start, int end, vector<pair<int, int>> &levels, vector<vector<long>> &arr, long *res, int length) {
    bool v[length];
    priority_queue<pil > q;
    q.push({start, 0});
    res[start] = 0;
    while (!q.empty()) {
        int n = q.top().first;
        long s = q.top().second;
        q.pop();
        v[n] = true;
        if (n == end) break;
        for (int i = 1; i < length; i++) {
            if (levels[n].first < arr[n][i]) continue;
            long c = s + levels[n].second;
            if (c < res[i]) {
                res[i] = c;
                q.push({i, c});
            }
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<pil>> g(n + 1);
    vector<pair<int, int>> levels(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        long z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        levels[i + 1] = {x, y};
    }
    vector<vector<long>> s(n + 1, vector<long>(n + 1));
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
            s[i][j] = INF;
    for (int i = 1; i < n + 1; i++) dijkstra(i, g, s[i], n + 1);
    long res[n + 1];
    for (int i = 0; i < n + 1; i++) res[i] = INF;
    solve(a, b, levels, s, res, n + 1);
    if (res[b] < INF) cout << res[b] << endl;
    else cout << -1 << endl;
    return 0;
}

