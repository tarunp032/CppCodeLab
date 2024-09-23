#include <bits/stdc++.h>

int reverse(int x) {
    int reversedNum = 0;
    
    while (x != 0) {
        int digit = x % 10;  
        x /= 10;            
        
        if (reversedNum > INT_MAX / 10 || (reversedNum == INT_MAX / 10 && digit > 7)) {
            return 0; 
        }
        if (reversedNum < INT_MIN / 10 || (reversedNum == INT_MIN / 10 && digit < -8)) {
            return 0;  
        }
        
        reversedNum = reversedNum * 10 + digit;  
    }
    
    return reversedNum;
}

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    
    int result = reverse(num);
    
    if (result != 0) {
        std::cout << "Reversed integer: " << result << std::endl;
    } else {
        std::cout << "Reversal caused overflow, result is 0." << std::endl;
    }
    
    return 0;
}
