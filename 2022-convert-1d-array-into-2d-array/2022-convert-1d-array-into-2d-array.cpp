class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n, 0));
        int size = original.size();
        if (size != n * m) return {};
        for(int i = 0; i < size; i++) {
            result[i / n][i % n] = original[i];
        }
        return result;
    }
};