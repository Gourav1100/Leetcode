class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size(), i = 0, j = 0;
        vector<long long> prev(m, 0);
        vector<long long> left(m, 0);
        vector<long long> right(m, 0);
        long long MAX = 0;
        while(i++ < n) {
            while(j++ < m) {
                left[j - 1] = max(j - 2 >= 0 ? left[j - 2] - 1 : 0, prev[j - 1]);
                right[m - j] = max((m - j + 1 < m) ? (right[m - j + 1] - 1) : 0, prev[m - j]);
            }
            j--;
            while(--j >= 0) {
                prev[j] = points[i - 1][j] + max(left[j], right[j]);
                MAX = MAX < prev[j] ? prev[j] : MAX;
            }
            j++;
        }
        return MAX;
    }
};