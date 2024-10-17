#include <iostream>
#include <vector>
#include <algorithm>

int calculateMinimumHP(const std::vector<std::vector<int>>& dungeon) {
    int rows = dungeon.size();
    int cols = dungeon[0].size();
    
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
    
    dp[rows - 1][cols - 1] = std::max(1, 1 - dungeon[rows - 1][cols - 1]);
    
    for (int i = rows - 2; i >= 0; --i) {
        dp[i][cols - 1] = std::max(1, dp[i + 1][cols - 1] - dungeon[i][cols - 1]);
    }
    
    for (int j = cols - 2; j >= 0; --j) {
        dp[rows - 1][j] = std::max(1, dp[rows - 1][j + 1] - dungeon[rows - 1][j]);
    }
    
    for (int i = rows - 2; i >= 0; --i) {
        for (int j = cols - 2; j >= 0; --j) {
            int fromRight = std::max(1, dp[i][j + 1] - dungeon[i][j]);
            int fromDown = std::max(1, dp[i + 1][j] - dungeon[i][j]);
            dp[i][j] = std::min(fromRight, fromDown);
        }
    }
    
    return dp[0][0];
}

int main() {
    std::vector<std::vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    
    std::cout << "Minimum initial health needed: " << calculateMinimumHP(dungeon) << std::endl;
    return 0;
}