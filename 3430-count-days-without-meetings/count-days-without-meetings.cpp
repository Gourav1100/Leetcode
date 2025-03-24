class Solution {
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), comp);
        int res = meetings[0][0] - 1, n = meetings.size();
        for(int i = 1; i < n; i++) {
            if (meetings[i][0] > meetings[i - 1][1]) {
                res += meetings[i][0] - meetings[i - 1][1] - 1;
            } else {
                meetings[i][0] = min(meetings[i][0], meetings[i - 1][0]);
                meetings[i][1] = max(meetings[i][1], meetings[i - 1][1]);
            }
        }
        res += days - meetings[n - 1][1];
        return res;
    }
};