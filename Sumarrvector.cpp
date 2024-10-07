#include <iostream>
#include <vector>

using namespace std;

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int sumVector(const vector<int>& vec) {
    int sum = 0;
    for (int element : vec) {
        sum += element;
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> vec = {6, 7, 8, 9, 10};

    int totalSum = sumArray(arr, size) + sumVector(vec);
    
    cout << "The sum of all elements in the array and vector is: " << totalSum << endl;

    return 0;
}
