#include <iostream>
using namespace std;

void tetranacci(int n) {
    if (n >= 1) cout << "0 ";
    if (n >= 2) cout << "0 ";
    if (n >= 3) cout << "0 ";
    if (n >= 4) cout << "1 ";

    int a = 0, b = 0, c = 0, d = 1;

    for (int i = 5; i <= n; i++) {
        int nextTerm = a + b + c + d;
        cout << nextTerm << " ";

        a = b;
        b = c;
        c = d;
        d = nextTerm;
    }

    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Tetranacci series up to " << n << " terms:" << endl;
    tetranacci(n);

    return 0;
}
