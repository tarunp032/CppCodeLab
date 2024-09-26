#include <iostream>
using namespace std;

int sumOfSeries(int n, int start, int increment) {
    int sum = 0;
    int currentTerm = start;
    
    cout << "Series: ";
    for (int i = 0; i < n; i++) {
        cout << currentTerm << " ";
        sum += currentTerm;
        currentTerm += increment;
    }
    cout << endl;
    
    return sum;
}

int main() {
    int n, start, increment;
    
    cout << "Enter the number of terms in the series: ";
    cin >> n;
    cout << "Enter the starting value: ";
    cin >> start;
    cout << "Enter the increment value: ";
    cin >> increment;
    
    int sum = sumOfSeries(n, start, increment);
    
    cout << "Sum of the series: " << sum << endl;

    return 0;
}
