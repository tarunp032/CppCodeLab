#include <iostream>
#include <vector>

using namespace std;

// Function to partition an array into even and odd elements
void partitionArray(int arr[], int size, vector<int>& even, vector<int>& odd) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }
}

// Function to partition a vector into even and odd elements
void partitionVector(const vector<int>& vec, vector<int>& even, vector<int>& odd) {
    for (int element : vec) {
        if (element % 2 == 0)
            even.push_back(element);
        else
            odd.push_back(element);
    }
}

int main() {
    // Array and vector initialization
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec = {7, 8, 9, 10, 11, 12};

    // Vectors to store even and odd elements
    vector<int> evenArray, oddArray;
    vector<int> evenVector, oddVector;

    // Partition the array
    partitionArray(arr, size, evenArray, oddArray);

    // Partition the vector
    partitionVector(vec, evenVector, oddVector);

    // Output the results
    cout << "Even elements in array: ";
    for (int i : evenArray)
        cout << i << " ";
    cout << endl;

    cout << "Odd elements in array: ";
    for (int i : oddArray)
        cout << i << " ";
    cout << endl;

    cout << "Even elements in vector: ";
    for (int i : evenVector)
        cout << i << " ";
    cout << endl;

    cout << "Odd elements in vector: ";
    for (int i : oddVector)
        cout << i << " ";
    cout << endl;

    return 0;
}
