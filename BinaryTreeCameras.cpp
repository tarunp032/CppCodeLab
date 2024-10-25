#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if (dfs(root, cameras) == UNCOVERED) {
            cameras++;
        }
        return cameras;
    }

private:
    enum NodeState { HAS_CAMERA, COVERED, UNCOVERED };
    
    NodeState dfs(TreeNode* node, int& cameras) {
        if (!node) return COVERED;
        
        NodeState left = dfs(node->left, cameras);
        NodeState right = dfs(node->right, cameras);

        if (left == UNCOVERED || right == UNCOVERED) {
            cameras++;
            return HAS_CAMERA;
        }
        if (left == HAS_CAMERA || right == HAS_CAMERA) {
            return COVERED;
        }
        return UNCOVERED;
    }
};

int main() {
    Solution solution;

    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    
    cout << "Minimum number of cameras needed: " << solution.minCameraCover(root) << endl;

    return 0;
}