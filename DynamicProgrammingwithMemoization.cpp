#include <iostream>
#include <vector>

using namespace std;

int fibonacciMemo(int n, vector<int> &memo) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    
    return memo[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> memo(n + 1, -1);

    int result = fibonacciMemo(n, memo);

    cout << "Fibonacci(" << n << ") = " << result << endl;

    return 0;
}
