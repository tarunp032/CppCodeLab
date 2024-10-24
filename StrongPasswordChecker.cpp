#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool isStrongPassword(string password) {
    int n = password.size();
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    unordered_set<char> specialChars = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};

    for (char c : password) {
        if (islower(c)) hasLower = true;
        else if (isupper(c)) hasUpper = true;
        else if (isdigit(c)) hasDigit = true;
        else if (specialChars.count(c)) hasSpecial = true;
    }

    if (n < 6 || n > 20 || !hasLower || !hasUpper || !hasDigit || !hasSpecial) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (password[i] == password[i - 1] && password[i] == password[i - 2]) {
            return false;
        }
    }

    return true;
}

int main() {
    string password;
    cout << "Enter the password to check: ";
    cin >> password;

    if (isStrongPassword(password)) {
        cout << "The password is strong." << endl;
    } else {
        cout << "The password is weak." << endl;
    }

    return 0;
}