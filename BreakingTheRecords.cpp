#include <iostream>
#include <vector>
using namespace std;

vector<int> breakingRecords(const vector<int>& scores) {
    int minScore = scores[0];
    int maxScore = scores[0];
    int minBreaks = 0;
    int maxBreaks = 0;

    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            maxBreaks++;
        }
        else if (scores[i] < minScore) {
            minScore = scores[i];
            minBreaks++;
        }
    }
    return {maxBreaks, minBreaks};
}

int main() {
    int n;
    cout << "Enter the number of games: ";
    cin >> n;

    vector<int> scores(n);
    cout << "Enter the scores: ";
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    vector<int> result = breakingRecords(scores);
    cout << "Max record breaks: " << result[0] << "\n";
    cout << "Min record breaks: " << result[1] << "\n";

    return 0;
}