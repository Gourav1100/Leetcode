class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto& num: nums) {
            freq[num]++;
        }
        for(auto& item: freq) {
            if (item.second >> 1 << 1 !=  item.second) {
                return false;
            }
        }
        return true;
    }
};