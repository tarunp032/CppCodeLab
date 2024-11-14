#include <iostream>
#include <vector>
using namespace std;

int birthday(const vector<int>& s, int d, int m) {
    int count = 0;
    for (int i = 0; i <= s.size() - m; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += s[i + j];
        }
        if (sum == d) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number of chocolate squares: ";
    cin >> n;
    
    vector<int> s(n);
    cout << "Enter chocolate square values: ";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int d, m;
    cout << "Enter Ron's birth day and month: ";
    cin >> d >> m;

    int result = birthday(s, d, m);
    cout << "Number of ways to divide the chocolate: " << result << endl;

    return 0;
}