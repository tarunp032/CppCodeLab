#include <iostream>

using namespace std;

int countOccurrences(int arr[], int size, int element) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 2;

    int occurrences = countOccurrences(arr, size, element);
    cout << "Element " << element << " occurs " << occurrences << " times in the array." << endl;

    return 0;
}
