#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n, q;
    unordered_map<string, int> frequency;

    cout << "Enter number of strings: ";
    cin >> n;

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        frequency[str]++;
    }

    cout << "Enter number of queries: ";
    cin >> q;

    cout << "Enter queries:\n";
    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        cout << "Frequency of '" << query << "': " << frequency[query] << endl;
    }

    return 0;
}