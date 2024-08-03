class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int mp[1001] = {}, size = target.size();
        for(int index = 0; index < size; index++) {
            mp[target[index]]++;
            mp[arr[index]]--;
        }
        for(int i = 0; i <= 1000; i++) {
            if (mp[i] < 0) return false;
        }
        return true;
    }
};