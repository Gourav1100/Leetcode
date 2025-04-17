class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                res += ((i * j) % k == 0 && nums[i] == nums[j]);
            }
        }
        return res;
    }
};