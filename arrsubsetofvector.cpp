#include <iostream>
#include <vector>
#include <unordered_set>

bool isArraySubsetOfVector(const int arr[], int arrSize, const std::vector<int>& vec) {
    // Insert all elements of the vector into an unordered set for fast lookup
    std::unordered_set<int> vecSet(vec.begin(), vec.end());

    // Check if every element of the array is present in the set
    for (int i = 0; i < arrSize; ++i) {
        if (vecSet.find(arr[i]) == vecSet.end()) {
            return false; // If any element is not found, return false
        }
    }
    return true; // All elements of the array were found in the vector
}

int main() {
    int arr[] = {1, 3, 5};
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    if (isArraySubsetOfVector(arr, 3, vec)) {
        std::cout << "The array is a subset of the vector." << std::endl;
    } else {
        std::cout << "The array is not a subset of the vector." << std::endl;
    }

    return 0;
}