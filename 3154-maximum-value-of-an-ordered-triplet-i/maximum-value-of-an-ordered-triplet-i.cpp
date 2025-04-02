class Solution {
    long long max(long long a, long long b) {
        return a > b ? a : b;
    }
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    res = max(res, (nums[i] - nums[j]) * (long long)nums[k]);
                }
            }
        }
        return res;
    }
};