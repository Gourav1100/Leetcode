class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long *result = new long long[n];
        for(int i = n - 1; i >= 0; i--) {
            long long next = i + questions[i][1] + 1 < n ? result[i + questions[i][1] + 1] : 0;
            result[i] = max((long long)questions[i][0] + next, i + 1 < n ? (long long)result[i + 1] : 0);
        }
        return result[0];
    }
};