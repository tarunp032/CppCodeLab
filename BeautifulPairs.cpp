#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int beautifulPairs(vector<int>& A, vector<int>& B) {
    unordered_map<int, int> freqA, freqB;
    for (int num : A) {
        freqA[num]++;
    }
    for (int num : B) {
        freqB[num]++;
    }
    
    int commonPairs = 0;
    for (auto& elem : freqA) {
        int number = elem.first;
        int countInA = elem.second;
        int countInB = freqB[number];
        commonPairs += min(countInA, countInB);
    }
    
    if (commonPairs == A.size()) {
        return commonPairs - 1;
    }
    return commonPairs + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    
    int result = beautifulPairs(A, B);
    cout << result << endl;
    
    return 0;
}