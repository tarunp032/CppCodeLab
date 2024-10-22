#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<char, int> letterToDigit;
vector<char> letters;
vector<int> usedDigits(10, 0);

bool isValidSolution(const vector<string>& words, const string& result) {
    int sum = 0;
    for (const string& word : words) {
        int num = 0;
        for (char c : word) {
            num = num * 10 + letterToDigit[c];
        }
        sum += num;
    }

    int resultNum = 0;
    for (char c : result) {
        resultNum = resultNum * 10 + letterToDigit[c];
    }

    return sum == resultNum;
}

bool solvePuzzleHelper(const vector<string>& words, const string& result, int idx) {
    if (idx == letters.size()) {
        return isValidSolution(words, result);
    }

    for (int digit = 0; digit < 10; ++digit) {
        if (!usedDigits[digit]) {
            letterToDigit[letters[idx]] = digit;
            usedDigits[digit] = 1;

            if (solvePuzzleHelper(words, result, idx + 1)) {
                return true;
            }

            usedDigits[digit] = 0;
        }
    }

    return false;
}

bool solvePuzzle(const vector<string>& words, const string& result) {
    unordered_map<char, bool> seenLetters;
    for (const string& word : words) {
        for (char c : word) {
            if (!seenLetters[c]) {
                letters.push_back(c);
                seenLetters[c] = true;
            }
        }
    }
    for (char c : result) {
        if (!seenLetters[c]) {
            letters.push_back(c);
            seenLetters[c] = true;
        }
    }

    if (letters.size() > 10) {
        return false;
    }

    return solvePuzzleHelper(words, result, 0);
}

int main() {
    int n;
    cout << "Enter number of words in the puzzle: ";
    cin >> n;
    
    vector<string> words(n);
    cout << "Enter the words (one by one):\n";
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    string result;
    cout << "Enter the result word: ";
    cin >> result;

    if (solvePuzzle(words, result)) {
        cout << "Solution found! Letter to digit mapping:\n";
        for (const auto& pair : letterToDigit) {
            cout << pair.first << " -> " << pair.second << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
