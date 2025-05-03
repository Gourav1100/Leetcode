class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(), res = INT_MAX;
        int freq[7] = {}, freq_top[7] = {}, freq_bottom[7] = {};
        for(int i = 0; i < n; i++) {
            freq[tops[i]]++;
            freq_top[tops[i]]++;
            freq_bottom[bottoms[i]]++;
            if (bottoms[i] != tops[i]) {
                freq[bottoms[i]]++;
            }
        }
        for(int i = 1; i < 7; i++) {
            if (freq[i] == n) {
                res = min(res, min(n - freq_top[i], n - freq_bottom[i]));
            }
        }
        if (res == INT_MAX) return -1;
        return res;
    }
};