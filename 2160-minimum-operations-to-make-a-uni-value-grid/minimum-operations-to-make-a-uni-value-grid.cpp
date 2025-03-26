class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        bool is_valid = true;
        int n = grid.size(), m = grid[0].size(), rem = grid[0][0] % x;
        vector<int> nums;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                nums.push_back(grid[i][j] / x);
                if (grid[i][j] % x != rem) {
                    is_valid = false;
                }
            }
        }
        if (!is_valid) {
            return -1;
        }
        sort(nums.begin(), nums.end());
        int res = 0, i = nums.size() >> 1;
        for(auto& item: nums) {
            res += abs(item - nums[i]);
        }
        return res;
    }
};