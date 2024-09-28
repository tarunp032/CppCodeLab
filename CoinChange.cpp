#include <iostream>
#include <climits>
using namespace std;

int minCoins(int coins[], int n, int amount) {
    static int memo[1000];
    
    if (memo[0] != 0) {
        for (int i = 0; i < 1000; i++) {
            memo[i] = -1;
        }
    }

    if (amount == 0) return 0;

    if (memo[amount] != -1) return memo[amount];
    
    int result = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        if (coins[i] <= amount) {
            int sub_result = minCoins(coins, n, amount - coins[i]);
            
            if (sub_result != INT_MAX && sub_result + 1 < result) {
                result = sub_result + 1;
            }
        }
    }
    
    memo[amount] = result;
    
    return result;
}

int main() {
    int coins[] = {1, 3, 4};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 6;
    
    int result = minCoins(coins, n, amount);
    
    if (result == INT_MAX) {
        cout << "It's not possible to make the amount with the given coins." << endl;
    } else {
        cout << "Minimum coins needed: " << result << endl;
    }
    
    return 0;
}
