class Solution {
    vector<vector<int>> visited;
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        int res = 0;
        visited = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    res += dfs(grid1, grid2, i, j);
                }
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) return 1;
        if (visited[i][j] || grid1[i][j] != grid2[i][j] || grid2[i][j] == 0) return grid1[i][j] == grid2[i][j] || !grid2[i][j];
        visited[i][j] = 1;
        int left = dfs(grid1, grid2, i, j - 1);
        int right = dfs(grid1, grid2, i, j + 1);
        int up = dfs(grid1, grid2, i - 1, j);
        int down = dfs(grid1, grid2, i + 1, j);
        return left && right && up && down;
    }
};