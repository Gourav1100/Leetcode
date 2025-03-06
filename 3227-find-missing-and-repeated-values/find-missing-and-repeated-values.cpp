class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), n_square = n * n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                grid[i][j]--;
                int h = (grid[i][j] % n_square) / n, k = grid[i][j] % n;
                grid[h][k] += n_square;
            }
        }
        vector<int> res = {0, 0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] < n_square) {
                    res[1] = i * n + j + 1;
                } else if (grid[i][j] >= 2 * n_square) {
                    res[0] = i * n + j + 1;
                }
            }
        }
        return res;
    }
};