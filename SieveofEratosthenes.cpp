/*Here is the C++ program implementing the Sieve of Eratosthenes 
to find all prime numbers up to a given number N*/

#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int N) {
    // Step 1: Create a boolean array "isPrime[0..N]" and initialize all entries as true.
    // A value in isPrime[i] will be false if i is not a prime, true if i is a prime.
    vector<bool> isPrime(N + 1, true);
    
    // Step 2: Mark 0 and 1 as non-prime since they are not prime numbers
    isPrime[0] = isPrime[1] = false;
    
    // Step 3: Start the loop from the first prime number, which is 2
    for (int p = 2; p * p <= N; p++) {
        // If isPrime[p] is still true, it means p is a prime
        if (isPrime[p]) {
            // Mark all multiples of p as non-prime
            for (int i = p * p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    // Step 4: Print all prime numbers
    cout << "Prime numbers up to " << N << ": ";
    for (int p = 2; p <= N; p++) {
        if (isPrime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    sieveOfEratosthenes(N);

    return 0;
}