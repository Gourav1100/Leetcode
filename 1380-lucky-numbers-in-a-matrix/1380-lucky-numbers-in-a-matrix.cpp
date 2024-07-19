class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row_min_list(n, INT_MAX);
        vector<int> col_max_list(m, 0);
        vector<int> result;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row_min_list[i] = min(matrix[i][j], row_min_list[i]);
                col_max_list[j] = max(matrix[i][j], col_max_list[j]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (row_min_list[i] == col_max_list[j]) {
                    result.push_back(row_min_list[i]);
                }
            }
        }
        return result;
    }
};