class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long max_per_child = min(limit, n), res = 0;
        for(int i = 0; i <= max_per_child; i++) {
            int l_bound = max(n - i - limit, 0), u_bound = min(n - i, limit);
            res += max(u_bound - l_bound + 1, 0);
        }
        return res;
    }
};