class TrieNode {
    public:
        TrieNode* children[26] = {};
        int count = 0;
        void insert(string& word, int index = 0) {
            if (index == word.size()) {
                return;
            }
            if (children[word[index] - 'a'] == nullptr) {
                children[word[index] - 'a'] = new TrieNode();
            }
            children[word[index] - 'a']->count++;
            children[word[index] - 'a']->insert(word, index + 1);
        }
        int match(string& word) {
            TrieNode* node = this; 
            int result = 0;
            for(int i = 0; i < word.size(); i++) {
                result += node->count;
                node = node->children[word[i] - 'a'];
            }
            result += node->count;
            return result;
        }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> results;
        TrieNode* head = new TrieNode();
        for(auto& word: words) {
            head->insert(word);
        }
        for(auto& word: words) {
            int result = 0;
            results.push_back(head->match(word));
        }
        return results;
    }
};