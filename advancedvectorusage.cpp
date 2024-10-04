#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> mergeVectors(const vector<int>& v1, const vector<int>& v2) {
    vector<int> merged = v1;
    merged.insert(merged.end(), v2.begin(), v2.end());
    return merged;
}

void removeDuplicates(vector<int>& v) {
    unordered_set<int> seen;
    auto it = v.begin();
    while (it != v.end()) {
        if (seen.find(*it) != seen.end()) {
            it = v.erase(it);
        } else {
            seen.insert(*it);
            ++it;
        }
    }
}

void rotateRight(vector<int>& v, int k) {
    int n = v.size();
    k = k % n;
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());
}

int main() {
    vector<int> vec1 = {1, 2, 3, 4};
    vector<int> vec2 = {3, 4, 5, 6};
    
    vector<int> mergedVector = mergeVectors(vec1, vec2);
    cout << "Merged vector: ";
    for (int num : mergedVector) {
        cout << num << " ";
    }
    cout << endl;
    
    removeDuplicates(mergedVector);
    cout << "After removing duplicates: ";
    for (int num : mergedVector) {
        cout << num << " ";
    }
    cout << endl;
    
    int k = 2;
    rotateRight(mergedVector, k);
    cout << "After rotating by " << k << " positions: ";
    for (int num : mergedVector) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
