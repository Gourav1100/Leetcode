class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = 0, z = 0;
        for(auto& item: nums) {
            if (item > 0) break;
            n += item < 0;
            z += item == 0;
        }
        return max(n, (int)nums.size() - n - z);
    }
};