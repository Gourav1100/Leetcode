class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int idx1 = 0, idx2 =  0, n = nums1.size(), m = nums2.size();
        vector<vector<int>> result;
        while(idx1 < n && idx2 < m) {
            if (nums1[idx1][0] < nums2[idx2][0]) {
                result.push_back(nums1[idx1++]);
            } else if (nums1[idx1][0] == nums2[idx2][0]) {
                result.push_back({nums1[idx1][0], nums1[idx1++][1] + nums2[idx2++][1]});
            } else {
                result.push_back(nums2[idx2++]);
            }
        }
        while(idx1 < n) {
            result.push_back(nums1[idx1++]);
        }
        while(idx2 < m) {
            result.push_back(nums2[idx2++]);
        }
        return result;
    }
};