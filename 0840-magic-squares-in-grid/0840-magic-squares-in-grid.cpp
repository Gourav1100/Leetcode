class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < m - 2; j++) {
//                 check nums
                if (grid[i][j] < 1 || grid[i][j] > 9 || grid[i][j + 1] < 1 || grid[i][j + 1] > 9 || grid[i][j + 2] < 1 || grid[i][j + 2] > 9 || grid[i + 1][j] < 1 || grid[i + 1][j] > 9 || grid[i + 1][j + 1] < 1 || grid[i + 1][j + 1] > 9 || grid[i + 1][j + 2] < 1 || grid[i + 1][j + 2] > 9 || grid[i + 2][j] < 1 || grid[i + 2][j] > 9 || grid[i + 2][j + 1] < 1 || grid[i + 2][j + 1] > 9 || grid[i + 2][j + 2] < 1 || grid[i + 2][j + 2] > 9) continue;
//                 check count
                set<int> s;
                s.insert(grid[i][j]);
                s.insert(grid[i][j + 1]);
                s.insert(grid[i][j + 2]);
                s.insert(grid[i + 1][j]);
                s.insert(grid[i + 1][j + 1]);
                s.insert(grid[i + 1][j + 2]);
                s.insert(grid[i + 2][j]);
                s.insert(grid[i + 2][j + 1]);
                s.insert(grid[i + 2][j + 2]);
//              calc sum
                int row_1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                int row_2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
                int row_3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                int col_1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                int col_2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
                int col_3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
                int dia_1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int dia_2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
//                 check sum
                if (row_1 == row_2 && row_2 == row_3 && col_1 == col_2 && col_2 == col_3 && dia_1 == dia_2 && row_1 == col_1 && row_1 == dia_1 && s.size() == 9) {
                    count++;
                }
            }
        }
        return count;
    }
};