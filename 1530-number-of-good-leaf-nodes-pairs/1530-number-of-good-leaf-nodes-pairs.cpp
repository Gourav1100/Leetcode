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
unordered_map<int, unordered_map<int, int>> mp;
unordered_map<int, int> parent;
queue<TreeNode*> q;
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int index = 0;
        int next_index = 1;
        vector<TreeNode*> leaf_nodes;
        vector<TreeNode*> tree;
        q.push(root);
        while(!q.empty()) {
            TreeNode* front = q.front();
            tree.push_back(front);
            front->val = index;
            q.pop();
            if (front->left == nullptr && front->right == nullptr) {
                leaf_nodes.push_back(front);
                index++;
                continue;
            }
            if (front->left != nullptr) {
                q.push(front->left);
                parent[next_index++] = index;
            }
            if (front->right != nullptr) {
                q.push(front->right);
                parent[next_index++] = index;
            }
            index++;
        }
        int n = tree.size(), m = leaf_nodes.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                TreeNode* node = tree[i];
                TreeNode* node_2 = tree[j];
                if ((node->left != nullptr && node->left->val == node_2->val) || (node->right != nullptr && node->right->val == node_2->val)) {
                    mp[i][j] = 1;
                } else {
                    mp[i][j] = (i == parent[j] ? 0 : mp[min(parent[j], i)][max(parent[j], i)]) + 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (mp[min(leaf_nodes[i]->val, leaf_nodes[j]->val)][max(leaf_nodes[i]->val, leaf_nodes[j]->val)] <= distance) {
                    res++;
                }
            }
        }
        return res;
    }
};