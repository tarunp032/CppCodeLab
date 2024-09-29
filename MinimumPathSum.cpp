#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int grid_00, grid_01, grid_10, grid_11;

    cout << "Enter value for cell (0,0): ";
    cin >> grid_00;

    cout << "Enter value for cell (0,1): ";
    cin >> grid_01;

    cout << "Enter value for cell (1,0): ";
    cin >> grid_10;

    cout << "Enter value for cell (1,1): ";
    cin >> grid_11;

    int min_path_to_11 = grid_00 + min(grid_01 + grid_11, grid_10 + grid_11);

    cout << "Minimum path sum from (0,0) to (1,1): " << min_path_to_11 << endl;

    return 0;
}
