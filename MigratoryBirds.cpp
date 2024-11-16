#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int migratoryBirds(vector<int>& birds) {
    map<int, int> frequency;

    for (int bird : birds) {
        frequency[bird]++;
    }

    int maxCount = 0;
    int result = 0;

    for (const auto& pair : frequency) {
        if (pair.second > maxCount || (pair.second == maxCount && pair.first < result)) {
            maxCount = pair.second;
            result = pair.first;
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of birds: ";
    cin >> n;

    vector<int> birds(n);
    cout << "Enter the bird types: ";
    for (int i = 0; i < n; ++i) {
        cin >> birds[i];
    }

    int result = migratoryBirds(birds);
    cout << "The most frequent bird type is: " << result << endl;

    return 0;
}