/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int, int> d;
    vector<TreeNode*> result;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        d.clear();
        for(auto &item: to_delete) {
            d[item] = 1;
        }
        if (!d[root->val]) {
            result.push_back(root);
        }
        solve(root);
        return result;
    }
    TreeNode* solve(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* oldLeft = root->left;
        TreeNode* oldRight = root->right;
        root->left = solve(root->left);
        root->right = solve(root->right);
        if (d[root->val]) {
            if (oldLeft != nullptr && !d[oldLeft->val]) {
                result.push_back(oldLeft);
            }
            if (oldRight != nullptr && !d[oldRight->val]) {
                result.push_back(oldRight);
            }
            return nullptr;
        }
        return root;
    }
};