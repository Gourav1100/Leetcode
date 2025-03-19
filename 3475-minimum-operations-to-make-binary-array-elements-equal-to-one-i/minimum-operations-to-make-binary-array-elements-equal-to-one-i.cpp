class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == 0) {
                for(int j = 0; j < 3; j++) {
                    nums[i + j] = 1 - nums[i + j];
                }
                res++;
            }
        }
        for(int i = nums.size() - 3; i < nums.size(); i++) {
            if (!nums[i]) {
                return -1;
            }
        }
        return res;
    }
};