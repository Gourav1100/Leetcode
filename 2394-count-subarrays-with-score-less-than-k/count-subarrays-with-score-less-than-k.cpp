class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0, sum = 0;
        long long back = 0, n = nums.size(), prev = 0;
        for(long long front = 0; front < n; front++) {
            if ((sum + nums[front]) * (front - back + 1) < k) {
                sum += nums[front];
            } else {
                long long size = front - back;
                long long last_size = prev - back;
                long long temp_size = size + 1;
                res += ((size * (size + 1)) >> 1) - ((last_size * (last_size + 1)) >> 1);
                prev = front;
                sum += nums[front];
                while(sum * (temp_size--) >= k && back <= front) {
                    sum -= nums[back++];
                }
            }
        }
        long long size = n - back;
        long long last_size = prev - back;
        res += ((size * (size + 1)) >> 1) - ((last_size * (last_size + 1)) >> 1);
        return res;
    }
};