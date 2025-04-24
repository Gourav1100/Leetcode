class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> total;
        unordered_map<int, int> current;
        int n = nums.size(), back = 0;
        for(auto& num: nums) {
            total[num]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            current[nums[i]]++;
            while (current.size() == total.size()) {
                res += n - i;
                current[nums[back]]--;
                if (current[nums[back]] == 0) {
                    current.erase(nums[back]); 
                }
                back++;
            }
        }
        return res;
    }
};