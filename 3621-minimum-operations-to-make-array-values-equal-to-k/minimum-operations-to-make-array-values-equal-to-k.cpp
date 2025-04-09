class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto& item: nums) {
            if (item < k) return -1;
            if (item != k) {
                freq[item]++;
            }
        }
        return freq.size();
    }
};