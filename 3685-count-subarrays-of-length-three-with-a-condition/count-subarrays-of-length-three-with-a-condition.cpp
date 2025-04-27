class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n - 2; i++) {
            res += ((nums[i] + nums[i + 2]) << 1) == nums[i + 1];
        }
        return res;
    }
};