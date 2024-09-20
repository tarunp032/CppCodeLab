#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    // Loop through each row
    for (int i = 1; i <= rows; i++) {
        // Loop through each column in a row
        for (int j = 1; j <= i; j++) {
            // Print '*' for the first and last columns, and the last row
            if (j == 1 || j == i || i == rows)
                cout << "*";
            else
                cout << " ";  // Print space for the hollow part
        }
        cout << endl;  // Move to the next line after each row
    }
    
    return 0;
}
