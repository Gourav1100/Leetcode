class Solution {
    unordered_map<int, unordered_map<int, int>> dp;
public:
    bool canPartition(vector<int>& nums) {
        int s = 0, n = nums.size();
        for(auto& num: nums) {
            s += num;
        }
        if (s >> 1 << 1 != s) {
            return false;
        }
        return solve(nums, s >> 1);
    }
    bool solve(vector<int>& nums, int target, int index = 0) {
        if (index == nums.size()) {
            dp[index][target] = 1 + target == 0;
            return target == 0;
        }
        if (target == 0) {
            dp[index][target] = 2;
            return true;
        }
        if (dp[index][target] != 0) {
            return dp[index][target] - 1;
        }
        dp[index][target] = 1 + (solve(nums, target - nums[index], index + 1) || solve(nums, target, index + 1));
        return dp[index][target] - 1;
    }
};