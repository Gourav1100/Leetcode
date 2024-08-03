class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int mp[1001] = {};
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