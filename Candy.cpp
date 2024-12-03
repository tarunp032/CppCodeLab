#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candyDistribution(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);

    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int totalCandies = 0;
    for (int candy : candies) {
        totalCandies += candy;
    }

    return totalCandies;
}

int main() {
    vector<int> ratings = {1, 0, 2};
    int result = candyDistribution(ratings);
    cout << "Minimum candies required: " << result << endl;

    return 0;
}