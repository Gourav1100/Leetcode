class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(auto& st: arr) {
            mp[st]++;
        }
        string result = "";
        for(auto& st: arr) {
            if (mp[st] == 1 && --k == 0) {
                result = st;
                break;
            }
        }
        return result;
    }
};