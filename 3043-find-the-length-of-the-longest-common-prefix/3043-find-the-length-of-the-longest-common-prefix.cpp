class TrieNode {
    public:
        int isEnd = false;
        TrieNode* children[10] = {};
        void insert(string& num, int index = 0) {
            if (index == num.size()) {
                isEnd = true;
                return;
            }
            int child = num[index] - '0';
            // cout << (children[child] == nullptr) << endl;
            if (children[child] == nullptr) {
                children[child] = new TrieNode();
            }
            // cout << num << " " << child << endl;
            children[child]->insert(num, index + 1);
        }
};

int match(string& num, TrieNode* node, int index = 0) {
    if (index == num.size() || node->children[num[index] - '0'] == nullptr) {
        // cout << num[index] << " " << num[index] - '0' << " return ";
        return 0;
    }
    // cout << num[index] << " " << num[index] - '0' << " -> ";
    return 1 + match(num, node->children[num[index] - '0'], index + 1);
}

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* head = new TrieNode();
        for(auto& num: arr1) {
            string n = to_string(num);
            head->insert(n);
        }
        int result = 0;
        for(auto& num: arr2) {
            string n = to_string(num);
            result = max(result, match(n, head));
            // cout << endl;
            // cout << n << " " << result << endl;
        }
        return result;
    }
};