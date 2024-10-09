#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the sum of squared differences between an array and a vector
int sumOfSquaredDifferences(int arr[], vector<int>& vec, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int diff = arr[i] - vec[i];
        sum += diff * diff;
    }
    return sum;
}

int main() {
    // Array and vector initialization
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vec = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Calculating the sum of squared differences
    int sum = sumOfSquaredDifferences(arr, vec, size);
    
    cout << "Sum of squared differences: " << sum << endl;

    return 0;
}
