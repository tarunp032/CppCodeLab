#include <iostream>
#include <cmath>

using namespace std;

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int states = minutesToTest / minutesToDie + 1;
    int pigs = ceil(log(buckets) / log(states));
    return pigs;
}

int main() {
    int buckets, minutesToDie, minutesToTest;
    
    cout << "Enter the number of buckets: ";
    cin >> buckets;
    
    cout << "Enter the minutes to die: ";
    cin >> minutesToDie;
    
    cout << "Enter the minutes to test: ";
    cin >> minutesToTest;
    
    int pigs = poorPigs(buckets, minutesToDie, minutesToTest);
    
    cout << "Minimum number of pigs required: " << pigs << endl;
    
    return 0;
}