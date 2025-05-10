class Solution {
    long long max(long long a, long long b) {
        return a > b ? a : b;
    }
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long a = 0, sum_a = 0, b = 0, sum_b = 0;
        for(auto& num: nums1) {
            a += num == 0;
            sum_a += num;
        }
        for(auto& num: nums2) {
            b += num == 0;
            sum_b += num;
        }
        if (a == 0 && b == 0) {
            return sum_a == sum_b ? sum_a : -1;       
        }
        if (a == 0) {
            return sum_a <= sum_b ? -1 : ((sum_a - sum_b) >= b ? sum_a : -1);
        }
        if (b == 0) {
            return sum_b <= sum_a ? -1 : ((sum_b - sum_a) >= a ? sum_b : -1);
        }
        long long a_used = min(a, max(sum_a, sum_b) - sum_a);
        long long b_used = min(b, max(sum_a, sum_b) - sum_b);
        cout << sum_a << " " << sum_b << endl;
        cout << a << " " << b << endl;
        return max(sum_a, sum_b) + max(a - a_used, b - b_used);
    }
};