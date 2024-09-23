#define i front
#define j last
#define temp s.substr(front, last - front + 1)
class Solution {
    unordered_map<string, bool> dict;
    int dp[51][51];
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof(dp));
        for(auto& item : dictionary) {
            dict[item] = true;
        }
        return solve(s);
    }
    int solve(string& s, int front = 0, int last = 0) {
        if(last == s.size()) {
            if(dict[temp]) return 0;
            return temp.size();
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(dict[temp]) {
            return dp[i][j] = min(solve(s, last + 1, last + 1), solve(s, front, last + 1));
        }
        return dp[i][j] = min(solve(s, last + 1, last + 1) + int(temp.size()), solve(s, front, last + 1));
    }
};