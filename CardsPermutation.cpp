#include <iostream>
#include <vector>
#include <set>
using namespace std;

int minMovesToSort(const vector<int>& cards) {
    int n = cards.size();
    int moves = 0, expected = 1;
    
    for (int i = 0; i < n; ++i) {
        if (cards[i] == expected) {
            expected++;
        } else {
            moves++;
        }
    }
    
    return moves;
}

int main() {
    int n;
    cout << "Enter the number of cards: ";
    cin >> n;
    vector<int> cards(n);

    cout << "Enter the cards sequence: ";
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    int result = minMovesToSort(cards);
    cout << "Minimum moves to sort: " << result << endl;

    return 0;
}