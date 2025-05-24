class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size(), index = 0;
        vector<int> result;
        for(auto& word: words) {
            for(auto& ch: word) {
                if (ch == x) {
                    result.push_back(index);
                    break;
                }
            }
            index++;
        }
        return result;
    }
};