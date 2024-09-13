class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> result;
        for(int i = 1; i < n; i++) {
            arr[i] = arr[i] ^ arr[i - 1];
        }
        for(auto& query: queries) {
            int left = query[0] - 1 >= 0 ? arr[query[0] - 1] : 0, right = arr[query[1]];
            result.push_back(right ^ left);
        }
        return result;
    }
};