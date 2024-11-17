#include <iostream>
#include <string>

using namespace std;

int countingValleys(int steps, const string& path) {
    int seaLevel = 0;
    int valleys = 0;
    int currentLevel = 0;

    for (char step : path) {
        if (step == 'U') {
            currentLevel++;
        } else if (step == 'D') {
            currentLevel--;
        }
        
        if (currentLevel == 0 && step == 'U') {
            valleys++;
        }
    }

    return valleys;
}

int main() {
    int steps;
    string path;

    cout << "Enter the number of steps: ";
    cin >> steps;

    cout << "Enter the path (sequence of 'U' for uphill and 'D' for downhill): ";
    cin >> path;

    int result = countingValleys(steps, path);
    cout << "The number of valleys traversed: " << result << endl;

    return 0;
}