class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mods;
        for(auto& item: arr) {
            mods[(k + (item % k)) % k]++;
        }
        for(auto& item: mods) {
            // cout << item.first << " " << item.second << endl;
            if ((item.first == 0 && item.second % 2 != 0) || (item.first != 0 && mods[k - item.first] != item.second)) return false;
        }
        return true;
    }
};