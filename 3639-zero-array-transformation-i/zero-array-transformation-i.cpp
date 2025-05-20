class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int temp[100001] = {}, tempp[100001] = {}, sum = 0, n = nums.size();
        for(auto& query: queries) {
            temp[query[0]]++;
            tempp[query[1]]--;
        }
        for(int i = 0; i < n; i++) {
            if (temp[i] > 0) {
                sum += temp[i];
            }
            if (sum < nums[i]) {
                return false;
            }
            if (tempp[i] < 0) {
                sum += tempp[i];
            }
        }
        return true;
    }
};