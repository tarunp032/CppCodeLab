#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    for (int i = 0; i < rows; i++) {
        // Printing spaces to make the triangle shape
        for (int space = 1; space <= rows - i; space++)
            cout << " ";

        // Calculating and printing the values for Pascal's triangle
        int val = 1;
        for (int j = 0; j <= i; j++) {
            cout << val << " ";
            val = val * (i - j) / (j + 1);
        }
        cout << endl;
    }
    
    return 0;
}
