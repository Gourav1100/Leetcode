class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, pair<int, int>> freq;
        unordered_map<string, int> freq_eq;
        int res = 0;
        for(auto& word: words) {
            if (word[0] == word[1]) {
                freq_eq[word]++;
            } else {
                bool flag = (word[0] < word[1]);
                sort(word.begin(), word.end());
                freq[word] = {freq[word].first + flag, freq[word].second + !flag};
            }
        }
        for(auto& item: freq) {
            // cout << item.first << " " << item.second.first << " " << item.second.second << " " << (min(item.second.first, item.second.second) << 2) << endl;
            res += min(item.second.first, item.second.second) << 2;
        }
        bool is_odd = false;
        for(auto& item: freq_eq) {
            // cout << item.first << " " << item.second << " " << (item.second >> 1 << 2) << endl;
            res += item.second >> 1 << 2;
            is_odd = is_odd || (item.second >> 1 << 1) != item.second;
        }
        res += is_odd << 1;
        return res;
    }
};