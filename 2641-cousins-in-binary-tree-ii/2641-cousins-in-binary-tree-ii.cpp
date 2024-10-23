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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        queue<pair<TreeNode*, TreeNode*>> temp;
        q.push({nullptr, root});
        while(!q.empty()) {
            int size = q.size();
            unordered_map<TreeNode*, int> sums;
            while(size--) {
                TreeNode *parent = q.front().first, *node = q.front().second;
                q.pop();
                temp.push({parent, node});
                sums[parent] += node->val;
            }
            long long sum = 0;
            for(auto& item: sums) {
                sum += item.second;
            }
            for(auto& item: sums) {
                item.second = sum - item.second;
            }
            size = temp.size();
            while(size--) {
                TreeNode *parent = temp.front().first, *node = temp.front().second;
                temp.pop();
                node->val = sums[parent];
                if (node->left != nullptr) {
                    q.push({node, node->left});
                }
                if (node->right != nullptr) {
                    q.push({node, node->right});
                }
            }
        }
        return root;
    }
};