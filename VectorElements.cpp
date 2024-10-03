#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

int findMax(const vector<int>& v) {
    int maxElement = v.at(0);
    for (size_t i = 1; i < v.size(); i++) {
        if (v.at(i) > maxElement) {
            maxElement = v.at(i);
        }
    }
    return maxElement;
}

void swapFirstLast(vector<int>& v) {
    if (v.size() > 1) {
        int temp = v.at(0);
        v.at(0) = v.at(v.size() - 1);
        v.at(v.size() - 1) = temp;
    }
}

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    printVector(vec);

    cout << "Maximum element: " << findMax(vec) << endl;

    swapFirstLast(vec);

    printVector(vec);

    return 0;
}
