#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty()) return 0;
    
    int n = prices.size();
    std::vector<int> leftProfit(n, 0), rightProfit(n, 0);
    
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        leftProfit[i] = std::max(leftProfit[i - 1], prices[i] - minPrice);
        minPrice = std::min(minPrice, prices[i]);
    }
    
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightProfit[i] = std::max(rightProfit[i + 1], maxPrice - prices[i]);
        maxPrice = std::max(maxPrice, prices[i]);
    }
    
    int maxTotalProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxTotalProfit = std::max(maxTotalProfit, leftProfit[i] + rightProfit[i]);
    }
    
    return maxTotalProfit;
}

int main() {
    std::vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    std::cout << "Maximum Profit: " << maxProfit(prices) << std::endl;
    return 0;
}
