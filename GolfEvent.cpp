#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> trees;
        int m = forest.size();
        int n = forest[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i * n + j});
                }
            }
        }

        sort(trees.begin(), trees.end());

        int totalSteps = 0;
        int startRow = 0, startCol = 0;

        for (const auto& tree : trees) {
            int targetRow = tree.second / n;
            int targetCol = tree.second % n;
            int steps = bfs(forest, startRow, startCol, targetRow, targetCol);
            if (steps == -1) return -1;
            totalSteps += steps;
            startRow = targetRow;
            startCol = targetCol;
        }

        return totalSteps;
    }

    int bfs(const vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        if (sr == tr && sc == tc) return 0;
        int m = forest.size();
        int n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        int steps = 0;

        vector<int> dirs = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            int size = q.size();
            steps++;
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int newRow = row + dirs[d];
                    int newCol = col + dirs[d + 1];
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                        forest[newRow][newCol] != 0 && !visited[newRow][newCol]) {
                        if (newRow == tr && newCol == tc) return steps;
                        q.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> forest = {
        {1, 2, 3},
        {0, 0, 4},
        {7, 6, 5}
    };

    Solution sol;
    int result = sol.cutOffTree(forest);
    cout << "Minimum steps to cut all trees: " << result << endl;

    return 0;
}