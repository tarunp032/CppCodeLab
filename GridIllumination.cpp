#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class GridIllumination {
private:
    int N;
    unordered_map<int, int> row, col, diag, antiDiag;
    unordered_set<long long> lamps;

    long long hash(int x, int y) {
        return ((long long)x << 32) + y;
    }

    void addLamp(int x, int y) {
        if (lamps.count(hash(x, y)) > 0) return;
        lamps.insert(hash(x, y));
        row[x]++;
        col[y]++;
        diag[x - y]++;
        antiDiag[x + y]++;
    }

    void removeLamp(int x, int y) {
        if (lamps.count(hash(x, y)) == 0) return;
        lamps.erase(hash(x, y));
        if (--row[x] == 0) row.erase(x);
        if (--col[y] == 0) col.erase(y);
        if (--diag[x - y] == 0) diag.erase(x - y);
        if (--antiDiag[x + y] == 0) antiDiag.erase(x + y);
    }

public:
    GridIllumination(int N, vector<vector<int>>& initialLamps, vector<vector<int>>& queries) : N(N) {
        for (auto& lamp : initialLamps) {
            addLamp(lamp[0], lamp[1]);
        }
        vector<int> results = processQueries(queries);
        for (int res : results) {
            cout << res << " ";
        }
        cout << endl;
    }

    vector<int> processQueries(vector<vector<int>>& queries) {
        vector<int> results;
        vector<pair<int, int>> directions = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        for (auto& query : queries) {
            int x = query[0], y = query[1];
            if (row.count(x) || col.count(y) || diag.count(x - y) || antiDiag.count(x + y)) {
                results.push_back(1);
            } else {
                results.push_back(0);
            }

            for (auto& d : directions) {
                int nx = x + d.first, ny = y + d.second;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    removeLamp(nx, ny);
                }
            }
        }
        return results;
    }
};

int main() {
    int N = 5;
    vector<vector<int>> initialLamps = {{0, 0}, {4, 4}};
    vector<vector<int>> queries = {{1, 1}, {1, 0}, {4, 4}};
    GridIllumination grid(N, initialLamps, queries);
    return 0;
}