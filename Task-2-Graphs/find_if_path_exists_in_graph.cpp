/*

    There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

    You want to determine if there is a valid path that exists from vertex start to vertex end.

    Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.

*/

void traverse(unordered_map<int, vector<int>> &map, vector<int> &nodes, int start, int end) {
    if (nodes[start] || map[start].size() == 0) return;
    nodes[start]++;
    if (start == end) return;
    for (int n : map[start]) {
        traverse(map, nodes, n, end);
        if (nodes[end]) return;
    }
}
    
bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    if (start == end) return true;
    unordered_map<int, vector<int>> visited;
    bool valid = false;
    for (vector<int> v : edges) {
        visited[v[0]].push_back(v[1]);
        visited[v[1]].push_back(v[0]);
    }
    vector<int> nodes(n);
    traverse(visited, nodes, start, end);
    return nodes[end];
}