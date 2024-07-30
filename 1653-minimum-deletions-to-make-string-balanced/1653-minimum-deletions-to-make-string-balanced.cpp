class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for(int i = s.size() - 1; i >= 0; i--) {
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