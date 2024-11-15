#include <iostream>
#include <vector>
using namespace std;

int divisibleSumPairs(int n, int k, const vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) % k == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the divisor (k): ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = divisibleSumPairs(n, k, arr);
    cout << "Number of divisible sum pairs: " << result << endl;

    return 0;
}