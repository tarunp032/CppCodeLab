#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareEnvelopes(const vector<int>& e1, const vector<int>& e2) {
    if (e1[0] == e2[0])
        return e1[1] > e2[1];
    return e1[0] < e2[0];
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), compareEnvelopes);
    vector<int> lis;

    for (const auto& envelope : envelopes) {
        int height = envelope[1];
        auto it = lower_bound(lis.begin(), lis.end(), height);
        
        if (it == lis.end()) {
            lis.push_back(height);
        } else {
            *it = height;
        }
    }
    
    return lis.size();
}

int main() {
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    
    cout << "Maximum number of envelopes: " << maxEnvelopes(envelopes) << endl;
    
    return 0;
}