#include <iostream>
#include <cmath>

using namespace std;

double area(double radius) {
    return M_PI * radius * radius;
}

double area(double length, double width) {
    return length * width;
}

double area(double base, double height) {
    return 0.5 * base * height;
}

int main() {
    double radius, length, width, base, height;

    cout << "Enter radius of the circle: ";
    cin >> radius;
    cout << "Area of the circle: " << area(radius) << endl;

    cout << "\nEnter length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of the rectangle: " << area(length, width) << endl;

    cout << "\nEnter base and height of the triangle: ";
    cin >> base >> height;
    cout << "Area of the triangle: " << area(base, height) << endl;

    return 0;
}
