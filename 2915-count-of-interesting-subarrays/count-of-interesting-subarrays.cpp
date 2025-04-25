class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size(), prefix = 0;
        unordered_map<int, int> counts;
        long long res = 0;
        counts[0] = 1;
        for(int i = 0; i < n; i++) {
            prefix += (nums[i] % modulo == k);
            cout << prefix << endl;
            res += counts[(prefix - k + modulo) % modulo];
            counts[prefix % modulo]++;
        }
        return res;
    }
};