class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int **dp = new int*[n + 1];
        dp[n] = new int[2];
        memset(dp[n], 0, sizeof(dp[n]));
        for(int i = s.size() - 1; i >= 0; i--) {
            dp[i] = new int[2];
            memset(dp[i], 0, sizeof(dp[i]));
            for (int j = 0; j < 2; j++) {
                if (!j && s[i] == 'b') {
                    dp[i][j] = min(1 + dp[i + 1][j], dp[i + 1][!j]);
                } else if (j && s[i] == 'a') {
                     dp[i][j] = 1 + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
                
            }
        }
        return dp[0][0];
    }
};