#include <iostream>

using namespace std;

void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapValues(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swapping integers: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swapping integers: x = " << x << ", y = " << y << endl;

    float a = 1.5, b = 3.8;
    cout << "\nBefore swapping floats: a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "After swapping floats: a = " << a << ", b = " << b << endl;

    return 0;
}
