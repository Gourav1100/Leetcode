class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto& num: target) {
            mp[num]++;
        }
        for(auto& num: arr) {
            mp[num]--;
            if (mp[num] < 0) return false;
        }
        return true;
    }
};