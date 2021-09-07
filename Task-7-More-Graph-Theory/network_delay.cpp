/*

    You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

    We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

*/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < times.size(); i++) g[times[i][0]].push_back({times[i][1], times[i][2]});
        vector<long> delay(n + 1, 1e8);
        vector<bool> visited(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, k});
        delay[k] = 0;
        while (!q.empty()) {
            int node = q.top().second, w = q.top().first;
            q.pop();
            visited[node] = true;
            for (pair<int, int> child : g[node]) {
                if (visited[child.first]) continue;
                int currDelay = child.second + delay[node];
                if (currDelay < delay[child.first]) {
                    delay[child.first] = currDelay;
                    q.push({currDelay, child.first});
                }
            }
        }
        long d = 0;
        for (int i = 1; i < n + 1; i++) d = max(d, delay[i]);
        if (d >= 1e8) return -1;
        else return d;
    }
};