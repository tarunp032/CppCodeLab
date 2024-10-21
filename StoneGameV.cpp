#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int stoneGameV(vector<int>& stoneValue) {
    int n = stoneValue.size();
    vector<int> prefixSum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                int leftSum = prefixSum[k + 1] - prefixSum[i];
                int rightSum = prefixSum[j + 1] - prefixSum[k + 1];

                if (leftSum < rightSum) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + leftSum);
                } else if (leftSum > rightSum) {
                    dp[i][j] = max(dp[i][j], dp[k + 1][j] + rightSum);
                } else {
                    dp[i][j] = max(dp[i][j], max(dp[i][k] + leftSum, dp[k + 1][j] + rightSum));
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> stoneValue = {6, 2, 3, 4, 5, 5};
    cout << "Maximum score Alice can achieve: " << stoneGameV(stoneValue) << endl;
    return 0;
}
