#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long aVeryBigSum(const vector<long long>& arr) {
    return accumulate(arr.begin(), arr.end(), 0LL);
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << aVeryBigSum(arr) << endl;
    return 0;
}