class Solution {
public:
    int minimumPushes(string word) {
        int counts[26] = {};
        map<int, vector<int>> mp;
        for(auto& ch: word) {
            counts[ch - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if (counts[i] != 0) {
                mp[-counts[i]].push_back(i);
            }
        }
        int index = 0, result = 0;
        for(auto& row: mp) {
            for(auto& item: row.second) {
                result += ((index++ / 8) + 1) * -row.first;
            }
        }
        return result;
    }
};