class Solution {
    unordered_map<int, unordered_map<int, unordered_map<int, pair<int, int>>>> dp;
public:
    int stoneGameII(vector<int>& piles) {
        return solve(piles).first;
    }
    pair<int, int> solve(vector<int>& piles, int M = 1, int index = 0, int turn = 0) {
        int n = piles.size(), sum = 0;
        pair<int, int> res = {0, 0};
        if (dp[M][index][turn].first != 0 || dp[M][index][turn].second != 0) {
            return dp[M][index][turn];
        }
        for(int X = 1; X <= 2 * M; X++) {
            int current = index + X - 1;
            if (current < n) {
                sum += piles[current];
                pair<int, int> result = solve(piles, max(X, M), current + 1, !turn);
                result.first += !turn ? sum : 0;
                result.second += turn ? sum : 0;
                if ((turn && res.second < result.second) || (!turn && res.first < result.first)) {
                    res = result;
                }
            }
        }
        return dp[M][index][turn] = res;
    }
};