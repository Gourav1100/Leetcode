class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int front = 0, back = 0, n = nums.size();
        unordered_map<int, int> freq;
        long long pairs = 0;
        long long result = 0;
        for(; front < n; front++) {
            long long N = freq[nums[front]];
            pairs -= (N * (N - 1)) >> 1;
            freq[nums[front]]++;
            N++;
            pairs += (N * (N - 1)) >> 1;
            if (pairs >= k) {
                result += n - front;
            }
            while(pairs >= k && back < front) {
                long long N = freq[nums[back]];
                pairs -= (N * (N - 1)) >> 1;
                freq[nums[back]]--;
                N--;
                pairs += (N * (N - 1)) >> 1;
                back++;
                if (pairs >= k) {
                    result += n - front;
                }
            }
        }
        return result;
    }
};