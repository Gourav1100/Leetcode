class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int max = *max_element(nums.begin(), nums.end()), max_count = 0;
        for(int back = 0, front = 0; front < nums.size(); front++) {
            max_count += nums[front] == max;
            if (max_count == k) {
                while(max_count == k && back <= front) {
                    res += (nums.size() - front);
                    max_count -= nums[back++] == max;
                }
            }
        }
        return res;
    }
};