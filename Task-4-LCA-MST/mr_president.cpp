#include "bits/stdc++.h"

using namespace std;

int compareTo(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
    return a.second < b.second;
}

int find(int a, int *parent) {
    int root = a;
    while (parent[root] != root) root = parent[root];
    while (parent[a] != root) {
        int temp = parent[a];
        parent[a] = root;
        a = temp;
    }
    return root;
}

bool unify(int a, int b, int *parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a == b) return false;
    parent[a] = b;
    return true;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<pair<pair<int, int>, int>> paths;
    for (int i = 0; i < m; i++) {
        int a, b;
        int weight;
        cin >> a >> b >> weight;
        paths.push_back(make_pair(make_pair(a, b), weight));
    }
    sort(paths.begin(), paths.end(), compareTo);
    int parent[n + 1], components = n, minTrans = n - 1 <= k ? n - 1 : -1;
    for (int i = 0; i < n + 1; i++) parent[i] = i;
    long long total = 0;
    for (pair<pair<int, int>, int> p : paths) {
        if (components <= 1) break;
        if (unify(p.first.first, p.first.second, parent)) {
            components--;
            total += p.second;
            if (total + components - 1 <= k) minTrans = components - 1;
        }
    }
    if (components > 1) minTrans = -1;
    cout << minTrans << endl;
    return 0;
}

