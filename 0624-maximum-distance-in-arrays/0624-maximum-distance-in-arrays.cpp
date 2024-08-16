class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN = INT_MAX, MIN_FROM = -1, MAX = INT_MIN, MAX_FROM = -1, n = arrays.size();
        for(int i = 0; i < n; i++) {
            if (MAX < arrays[i][arrays[i].size() - 1] || (MAX == arrays[i][arrays[i].size() - 1] && arrays[i][0] > arrays[MAX_FROM][0])) {
                MAX = arrays[i][arrays[i].size() - 1];
                MAX_FROM = i;
            }
        }
        for(int i = 0; i < n; i++) {
            if (i != MAX_FROM && (MIN > arrays[i][0] || (MIN == arrays[i][0] && arrays[i][arrays[i].size() - 1] > arrays[MIN_FROM][arrays[MIN_FROM].size() - 1]))) {
                MIN = arrays[i][0];
                MIN_FROM = i;
            }
        }
        return max(MAX - MIN, abs(arrays[MIN_FROM][arrays[MIN_FROM].size() - 1] - arrays[MAX_FROM][0]));
    }
};