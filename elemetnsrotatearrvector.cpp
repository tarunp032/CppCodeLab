#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to rotate an array by k positions to the right
void rotateArray(int arr[], int size, int k) {
    k = k % size; // To handle cases where k > size
    reverse(arr, arr + size);           // Reverse the entire array
    reverse(arr, arr + k);              // Reverse the first k elements
    reverse(arr + k, arr + size);       // Reverse the remaining elements
}

// Function to rotate a vector by k positions to the right
void rotateVector(vector<int>& vec, int k) {
    int size = vec.size();
    k = k % size; // To handle cases where k > size
    reverse(vec.begin(), vec.end());           // Reverse the entire vector
    reverse(vec.begin(), vec.begin() + k);     // Reverse the first k elements
    reverse(vec.begin() + k, vec.end());       // Reverse the remaining elements
}

int main() {
    // Array and Vector initialization
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec = {6, 7, 8, 9, 10};

    int k = 2; // Number of positions to rotate

    // Rotate the array
    rotateArray(arr, size, k);
    cout << "Rotated array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Rotate the vector
    rotateVector(vec, k);
    cout << "Rotated vector: ";
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
