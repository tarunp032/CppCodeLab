#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; ++i) {
            int next2 = ugly[p2] * 2;
            int next3 = ugly[p3] * 3;
            int next5 = ugly[p5] * 5;
            int nextUgly = min({next2, next3, next5});
            ugly[i] = nextUgly;
            if (nextUgly == next2) ++p2;
            if (nextUgly == next3) ++p3;
            if (nextUgly == next5) ++p5;
        }

        return ugly[n - 1];
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "th ugly number is: " << solution.nthUglyNumber(n) << endl;
    return 0;
}