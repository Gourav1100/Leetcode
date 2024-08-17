class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<long long> prev(m, 0);
        vector<long long> left(m, 0);
        vector<long long> right(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                left[j] = max(j - 1 >= 0 ? left[j - 1] - 1 : INT_MIN, prev[j]);
                right[m - 1 - j] = max((m - j < m) ? (right[m - j] - 1) : INT_MIN, prev[m - j - 1]);
            }
            for(int j = 0; j < m; j++) {
                prev[j] = points[i][j] + max(left[j], right[j]);
            }
        }
        return *max_element(prev.begin(), prev.end());
    }
};