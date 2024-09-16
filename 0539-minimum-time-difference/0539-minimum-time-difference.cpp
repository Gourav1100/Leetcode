class Solution {
    int diff(string& a, string& b) {
        int hr_0 = (a[0] - '0') * 10 + (a[1] - '0'), hr_1 = (b[0] - '0') * 10 + (b[1] - '0');
        int mi_0 = (a[3] - '0') * 10 + (a[4] - '0'), mi_1 = (b[3] - '0') * 10 + (b[4] - '0');
        return min(((hr_1 - hr_0) * 60 + mi_1 - mi_0), ((24 - hr_1 + hr_0) * 60 - mi_1 + mi_0));
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();
        int res = INT_MAX;
        for(int i = 0; i < n; i++) {
            int lt = i + 1 == n ? 0 : i, ht = i + 1 == n ? n - 1 : i + 1;
            res = min(res, diff(timePoints[lt], timePoints[ht]));
        }
        return res;
    }
};