class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, unordered_map<int, int>> m;
        int res = 0;
        for(auto& item: dominoes) {
            int front = min(item[0], item[1]), back = max(item[0], item[1]);
            m[front][back]++;
        }
        for(auto& item: m) {
            for(auto& jtem: item.second) {
                res += (jtem.second * (jtem.second - 1)) >> 1;
            }
        }
        return res;
    }
};