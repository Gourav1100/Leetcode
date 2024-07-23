class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, vector<int>> m;
        int n = nums.size(), back = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < n; i++) {
            if (i > 0 && nums[i] != nums[i - 1]) {
                m[i - back].push_back(nums[i - 1]);
                back = i;
            }
        }
        m[n - back].push_back(nums[n - 1]);
        vector<int> result;
        for(auto& item: m) {
            for(auto& num: item.second) {
                for(int i = 0; i < item.first; i++) {
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};