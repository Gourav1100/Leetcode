class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), m = 0;
        vector<int> dp(n, 1);
        vector<int> result;
        sort(nums.begin(), nums.end());
        for(int i = n - 1; i >= 0; i--) {
            int MAX = 0;
            for(int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0) {
                    MAX = max(MAX, dp[j] + 1);
                }
            }
            dp[i] = max(dp[i], MAX);
            m = max(m, dp[i]);
        }
        for(int i = 0; i < n; i++) {
            if (dp[i] == m && (result.size() == 0 || nums[i] % result[result.size() - 1] == 0)) {
                m--;
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};