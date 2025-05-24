class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int freqs[51][26] = {}, index = 0;
        vector<int> result;
        for(auto& word: words) {
            for(auto& ch: word) {
                freqs[index][ch - 'a']++;
            }
            index++;
        }
        for(index = 0; index < 50; index++) {
            if (freqs[index][x - 'a']) {
                result.push_back(index);
            }
        }
        return result;
    }
};