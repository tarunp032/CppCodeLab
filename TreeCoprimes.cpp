#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const int MAXN = 100005;
vector<int> tree[MAXN];
vector<int> result;
int depth[MAXN];
int parent[MAXN];

void dfs(int node, int par, vector<vector<int>>& ancestors, const vector<int>& values) {
    int closestAncestor = -1;
    for (int v = 1; v <= 50; ++v) {
        if (!ancestors[v].empty() && __gcd(values[node], v) == 1) {  
            if (closestAncestor == -1 || depth[ancestors[v].back()] > depth[closestAncestor]) {
                closestAncestor = ancestors[v].back();
            }
        }
    }
    result[node] = closestAncestor;
    ancestors[values[node]].push_back(node);
    depth[node] = depth[par] + 1;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node, ancestors, values);
        }
    }
    ancestors[values[node]].pop_back();
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    result.resize(n, -1);
    depth[0] = 0;
    parent[0] = -1;
    vector<vector<int>> ancestors(51);
    dfs(0, -1, ancestors, values);
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}