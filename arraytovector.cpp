#include <iostream>
#include <vector>

using namespace std;

vector<int> arrayToVector(int arr[], int size) {
    vector<int> vec(arr, arr + size);
    return vec;
}

void printVector(const vector<int>& vec) {
    for (int element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> vec = arrayToVector(arr, size);
    
    cout << "Vector elements: ";
    printVector(vec);

    return 0;
}
