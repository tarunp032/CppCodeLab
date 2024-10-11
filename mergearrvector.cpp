#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the median of a sorted vector
double findMedian(const vector<int>& mergedVec) {
    int size = mergedVec.size();
    if (size % 2 == 0) {
        // If even, the median is the average of the two middle elements
        return (mergedVec[size / 2 - 1] + mergedVec[size / 2]) / 2.0;
    } else {
        // If odd, the median is the middle element
        return mergedVec[size / 2];
    }
}

int main() {
    // Initialize an array and a vector
    int arr[] = {1, 3, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec = {2, 4, 6, 8};

    // Create a new vector to merge the array and vector
    vector<int> mergedVec(arr, arr + size);  // Insert array elements into the merged vector
    mergedVec.insert(mergedVec.end(), vec.begin(), vec.end());  // Insert vector elements

    // Sort the merged vector
    sort(mergedVec.begin(), mergedVec.end());

    // Find and print the median
    double median = findMedian(mergedVec);
    cout << "The median of the merged array and vector is: " << median << endl;

    return 0;
}
