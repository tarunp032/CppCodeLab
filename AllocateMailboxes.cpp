#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minDistance(vector<int>& houses, int k) {
    int n = houses.size();
    sort(houses.begin(), houses.end());
    
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int median = houses[(i + j) / 2];
            for (int m = i; m <= j; ++m) {
                cost[i][j] += abs(houses[m] - median);
            }
        }
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int m = 0; m < i; ++m) {
                if (dp[m][j - 1] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[m][j - 1] + cost[m][i - 1]);
                }
            }
        }
    }

    return dp[n][k];
}

int main() {
    vector<int> houses = {1, 4, 8, 10, 20};
    int k = 3;
    cout << "Minimum distance to allocate " << k << " mailboxes: " << minDistance(houses, k) << endl;
    return 0;
}