#include <iostream>

using namespace std;

int calculate(int a, int b) {
    return a + b;
}

float calculate(float a, float b) {
    return a - b;
}

double calculate(double a, int b) {
    return a * b;
}

float calculate(int a, int b, char op) {
    if (op == '/') {
        return static_cast<float>(a) / b;
    } else {
        cout << "Invalid operation!" << endl;
        return 0;
    }
}

int main() {
    int x = 10, y = 20;
    float f1 = 7.5f, f2 = 2.3f;
    double d = 3.6;
    char operation = '/';

    cout << "Addition of " << x << " and " << y << ": " << calculate(x, y) << endl;
    cout << "Subtraction of " << f1 << " and " << f2 << ": " << calculate(f1, f2) << endl;
    cout << "Multiplication of " << d << " and " << x << ": " << calculate(d, x) << endl;
    cout << "Division of " << x << " by " << y << ": " << calculate(x, y, operation) << endl;

    return 0;
}