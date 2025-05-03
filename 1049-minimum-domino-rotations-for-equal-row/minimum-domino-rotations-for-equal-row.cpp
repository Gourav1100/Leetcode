class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        unordered_map<int, int> freq;
        unordered_map<int, int> freq_top;
        unordered_map<int, int> freq_bottom;
        for(int i = 0; i < n; i++) {
            freq[tops[i]]++;
            freq_top[tops[i]]++;
            freq_bottom[bottoms[i]]++;
            if (bottoms[i] != tops[i]) {
                freq[bottoms[i]]++;
            }
        }
        int res = INT_MAX;
        for(auto& item: freq) {
            if (item.second == n) {
                res = min(res, min(n - freq_top[item.first], n - freq_bottom[item.first]));
            }
        }
        if (res == INT_MAX) {
            return -1;
        }
        return res;
    }
};