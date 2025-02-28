class Solution {
public:
    string shortestCommonSupersequence(string& str1, string& str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        for(int i = n; i >= 0; i--) {
            for(int j = m; j >= 0; j--) {
                if (i == n && j == m) {
                    dp[i][j] = 0;
                } else if (i == n) {
                    dp[i][j] = dp[i][j + 1] + 1;
                } else if (j == m) {
                    dp[i][j] = dp[i + 1][j] + 1;
                } else {
                    dp[i][j] = min(min(dp[i][j + 1] + 1, dp[i + 1][j] + 1), str1[i] == str2[j] ? (dp[i + 1][j + 1] + 1) : INT_MAX);
                }
            }
        }
        int i = 0, j = 0;
        string res = "";
        while(i < n && j < m) {
            if (str1[i] != str2[j]) {
                if (dp[i][j + 1] <= dp[i + 1][j]) {
                    res += str2[j++];
                } else {
                    res += str1[i++];
                }
            } else {
                if (dp[i][j + 1] <= dp[i + 1][j]) {
                    if (dp[i][j + 1] <= dp[i + 1][j + 1]) {
                        res += str2[j++];
                    } else {
                        res += str2[j++];
                        i++;
                    }
                } else {
                    if (dp[i + 1][j] <= dp[i + 1][j + 1]) {
                        res += str1[i++];
                    } else {
                        res += str1[i++];
                        j++;
                    }
                }
            }
        }
        while(i < n) {
            res += str1[i++];
        }
        while(j < m) {
            res += str2[j++];
        }
        return res;
    }
};