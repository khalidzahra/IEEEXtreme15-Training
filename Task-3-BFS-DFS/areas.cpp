/*

    You are given a 2D grid. A '#' represents an obstacle and a '.' represents free space. 
    You need to find the areas of the disconnected components. 
    The cells (i+1, j), (i, j+1), (i-1, j), (i, j-1) are the adjacent to the cell (i, j).

*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool solve(vector<vector<int>> &grid, int r, int c, int &count, vector<int> &countArr) {
    if (grid[r][c] == -1 || grid[r][c] > 0) return false;
    grid[r][c] = count;
    if (count >= countArr.size()) countArr.push_back(1);
    else countArr[count]++;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= grid.size() || nr < 0 || nc >= grid[r].size() || nc < 0) continue;
        solve(grid, nr, nc, count, countArr);
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c, -1));
        for (int j = 0; j < r; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == '.') grid[j][k] = 0;
            }
        }
        int count = 1;
        vector<int> countArr(2);
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < grid[j].size(); k++) {
                count += solve(grid, j, k, count, countArr);
            }
        }
        cout << countArr.size() - 1 << endl;
        for (int j = 1; j < countArr.size(); j++) {
            if (countArr[j] > 0) cout << countArr[j] << " ";
        }
        cout << endl;
    }
}
