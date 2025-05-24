class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        unordered_map<int, unordered_map<char, int>> freqs;
        int index = 0;
        vector<int> result;
        for(auto& word: words) {
            for(auto& ch: word) {
                freqs[index][ch]++;
            }
            index++;
        }
        for(auto& item: freqs) {
            if (item.second[x]) {
                result.push_back(item.first);
            }
        }
        return result;
    }
};