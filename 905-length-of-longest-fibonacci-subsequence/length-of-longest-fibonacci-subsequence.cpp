class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int res = 0, n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 2; i < n; i++) {
            int front = 0, end = i - 1;
            while(front < end) {
                int s = arr[front] + arr[end];
                if (s > arr[i]) {
                    end--;
                } else if (s < arr[i]) {
                    front++;
                } else {
                    dp[end][i] = dp[front][end] + 1;
                    res = max(res, dp[end][i]);
                    end--;
                    front++;
                }
            }
        }
        return res == 0 ? 0 : res + 2;
    }
};