#define MOD 1000000007
class Solution {
    int dp[1001];
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    int numTilings(int n) {
        if(n == 0 || n == 1) {
            return 1;
        } else if(n == 2) {
            return 2;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        long long int x = numTilings(n - 1) + numTilings(n - 2);
        for(int i = 3; i <= n; i++) {
            x += (2 * numTilings(n - i));
        }
        return dp[n] = (x % MOD);
    }
};