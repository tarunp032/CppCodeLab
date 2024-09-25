#include <iostream>

using namespace std;

void printUpperHalf(int n, int i) {
    if (i > n) {
        return; 
    }

    for (int j = i; j < n; j++) {
        cout << " ";
    }

    for (int j = 0; j < (2 * i - 1); j++) {
        cout << "*";
    }

    cout << endl;

    printUpperHalf(n, i + 1);
}

void printLowerHalf(int n, int i) {
    if (i <= 0) {
        return;
    }

    for (int j = n; j > i; j--) {
        cout << " ";
    }

    for (int j = 0; j < (2 * i - 1); j++) {
        cout << "*";
    }

    cout << endl;

    printLowerHalf(n, i - 1);
}

void printDiamond(int n) {
    printUpperHalf(n, 1); 
    printLowerHalf(n, n);
}

int main() {
    int n;

    cout << "Enter the height of the diamond: ";
    cin >> n;

    printDiamond(n); 

    return 0;
}
