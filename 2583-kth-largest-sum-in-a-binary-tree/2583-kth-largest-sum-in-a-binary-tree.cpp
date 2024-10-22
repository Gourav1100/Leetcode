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
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<long long> levels;
        q.push(root);
        while(!q.empty()) {
            long long sum = 0, size = q.size();
            while(size--) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left != nullptr) {
                    q.push(front->left);
                }
                if (front->right != nullptr) {
                    q.push(front->right);
                }
                sum += front->val;
            }
            levels.push_back(sum);
        }
        if (levels.size() < k) {
            return -1;
        }
        sort(levels.begin(), levels.end(), greater<long long>());
        return levels[k - 1];
    }
};