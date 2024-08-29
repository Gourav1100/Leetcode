class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> X;
        unordered_map<int, vector<int>> Y;
        for(int i = 0; i < n; i++) {
            X[stones[i][0]].push_back(stones[i][1]);
            Y[stones[i][1]].push_back(stones[i][0]);
        }
        map<pair<int, int>, int> visited;
        for(int i = 0; i < n; i++) {
            visited[{stones[i][0], stones[i][1]}] = 0;
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[{stones[i][0], stones[i][1]}]) {
                res++;
                dfs(X, Y, visited, stones[i][0], stones[i][1]);
            }
        }
        return n - res;
    }
    void dfs(unordered_map<int, vector<int>>& X, unordered_map<int, vector<int>>& Y, map<pair<int, int>, int>& visited, int i, int j) {
        if(visited[{i, j}]) {
            return;
        }
        int n = X[i].size(), m = Y[j].size();
        visited[{i, j}] = 1;
        for(int a = 0; a < n; a++) {
            dfs(X, Y, visited, i, X[i][a]);
        }
        for(int a = 0; a < m; a++) {
            dfs(X, Y, visited, Y[j][a], j);
        }
    }
};