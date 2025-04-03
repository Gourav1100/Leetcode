class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        int p = INT_MIN, s = INT_MIN;
        long long res = 0;
        for(int i = 0; i < n; i++) {
            p = max(p, nums[i]);
            s = max(s, nums[n - i - 1]);
            prefix[i] = p;
            suffix[n - i - 1] = s;
        }
        for(int j = 1; j < n - 1; j++) {
            cout << prefix[j - 1] << " " << nums[j] << " " << suffix[j + 1];
            res = max(res, (prefix[j - 1] - nums[j]) * (long long)suffix[j + 1]);
        }
        return res;
    }
};