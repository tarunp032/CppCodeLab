#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string encryption(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    int len = s.length();
    int rows = floor(sqrt(len));
    int cols = ceil(sqrt(len));
    if (rows * cols < len) {
        rows++;
    }
    
    string encrypted = "";
    for (int col = 0; col < cols; col++) {
        for (int row = 0; row < rows; row++) {
            int index = row * cols + col;
            if (index < len) {
                encrypted += s[index];
            }
        }
        encrypted += " ";
    }
    return encrypted;
}

int main() {
    string s;
    cout << "Enter the text to encrypt: ";
    getline(cin, s);
    string result = encryption(s);
    cout << "Encrypted text: " << result << endl;
    return 0;
}