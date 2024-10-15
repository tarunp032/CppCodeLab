#include <iostream>
#include <unordered_set>

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    std::unordered_set<int> seenNumbers;
    while (n != 1 && seenNumbers.find(n) == seenNumbers.end()) {
        seenNumbers.insert(n);
        n = sumOfSquares(n);
    }
    return n == 1;
}

int main() {
    int num = 19;
    if (isHappy(num)) {
        std::cout << num << " is a Happy Number." << std::endl;
    } else {
        std::cout << num << " is not a Happy Number." << std::endl;
    }
    return 0;
}