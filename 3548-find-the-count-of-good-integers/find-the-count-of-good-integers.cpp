class Solution {
    unordered_map<int, int> dp;
    int fact(int n) {
        if (dp[n] != 0) {
            return dp[n];
        }
        if (n == 1 || n == 0) {
            return dp[1] = 1;
        }
        return dp[n] = n * fact(n - 1);
    }
public:
    long long countGoodIntegers(int n, int k) {
        set<string> pal;
        int base = pow(10, (n - 1) >> 1);
        int skip = n >> 1 << 1 == n ? 0 : 1;
        for(int i = base; i < base * 10; i++) {
            string left = to_string(i);
            string right = to_string(i);
            reverse(right.begin(), right.end());
            right = right.substr(skip);
            string num = left + right;
            long long i_num = stoll(num);
            if (i_num % k == 0) {
                sort(num.begin(), num.end());
                pal.insert(num);
            }
        }
        int res = 0;
        for(auto& item: pal) {
            int count[10] = {};
            for(auto& ch: item) {
                count[ch - '0']++;
            }
            long long temp = (n - count[0]) * fact(n - 1);
            for(int i = 0; i < 10; i++) {
                temp /= fact(count[i]);
            }
            res += temp;
        }
        return res;
    }
};