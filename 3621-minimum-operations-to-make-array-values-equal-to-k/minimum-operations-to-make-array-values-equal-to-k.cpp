class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int freq[101] = {};
        int count = 0;
        for(auto& item: nums) {
            if (item < k) return -1;
            freq[item]++;
            count += item != k && freq[item] == 1;
        }
        return count;
    }
};