class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int lt = 0, gt = 0, eq = 0, n = nums.size();
        for(auto& num: nums) {
            lt += num < pivot;
            eq += num == pivot;
            gt += num > pivot;
        }
        gt = lt + eq;
        eq = lt;
        lt = 0;
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                result[lt++] = nums[i];
            } else if (nums[i] == pivot) {
                result[eq++] = nums[i];
            } else {
                result[gt++] = nums[i];
            }
        }
        return result;
    }
};