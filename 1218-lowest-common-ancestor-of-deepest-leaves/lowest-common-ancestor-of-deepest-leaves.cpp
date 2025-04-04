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
    TreeNode* result = nullptr;
    int count = 0;
    int solve(TreeNode* r, int d) {
        if (r == nullptr) {
            return 0;
        }
        if (d == 0) {
            return 1;
        }
        int left = solve(r->left, d - 1);
        int right = solve(r->right, d - 1);
        if (left + right == count && result == nullptr) {
            result = r;
        }
        return left + right;
    };
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* last = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        int depth = -1;
        while(!q.empty()) {
            int size = q.size();
            count = q.size();
            depth++;
            while(size--) {
                TreeNode* node = q.front();
                last = node;
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        if (count == 1) {
            return last;
        }
        // cout << depth << " " << count << endl;
        solve(root, depth);
        return result;
    }
};