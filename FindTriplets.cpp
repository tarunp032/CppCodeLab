#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findTriplets(vector<int>& arr) {
    int n = arr.size();
    bool found = false;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0) {
                cout << "Triplet found: " << arr[i] << ", " << arr[left] << ", " << arr[right] << endl;
                found = true;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    if (!found) {
        cout << "No triplets with zero sum found." << endl;
    }
}

int main() {
    vector<int> arr = {0, -1, 2, -3, 1};

    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    findTriplets(arr);

    return 0;
}