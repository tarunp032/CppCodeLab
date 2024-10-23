#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool canCross(vector<int>& stones) {
    unordered_map<int, unordered_set<int>> jumps; 
    jumps[stones[0]].insert(0);

    for (int i = 0; i < stones.size(); ++i) {
        int stone = stones[i];
        for (int jump : jumps[stone]) {
            for (int step = jump - 1; step <= jump + 1; ++step) {
                if (step > 0 && jumps.find(stone + step) != jumps.end()) {
                    jumps[stone + step].insert(step);
                }
            }
        }
    }

    return !jumps[stones.back()].empty();
}

int main() {
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;
    
    vector<int> stones(n);
    cout << "Enter the positions of the stones: ";
    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
    }

    if (canCross(stones)) {
        cout << "The frog can cross the river!" << endl;
    } else {
        cout << "The frog cannot cross the river." << endl;
    }

    return 0;
}