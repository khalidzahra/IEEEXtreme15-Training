/*

    Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

    Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

    Notice that you can return the vertices in any order.

*/

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> degrees(n);
    for (vector<int> edge : edges) {
        degrees[edge[1]]++;
    }
    vector<int> verticies;
    for (int i = 0; i < degrees.size(); i++) {
        if (degrees[i] == 0) verticies.push_back(i);
    }
    return verticies;
}