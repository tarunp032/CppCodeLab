#include <iostream>
#include <cmath>
using namespace std;

string catAndMouse(int catA, int catB, int mouseC) {
    int distCatA = abs(catA - mouseC);
    int distCatB = abs(catB - mouseC);
    if (distCatA == distCatB) return "Mouse C";
    else if (distCatA < distCatB) return "Cat A";
    else return "Cat B";
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int catA, catB, mouseC;
        cin >> catA >> catB >> mouseC;
        cout << catAndMouse(catA, catB, mouseC) << endl;
    }
    return 0;
}