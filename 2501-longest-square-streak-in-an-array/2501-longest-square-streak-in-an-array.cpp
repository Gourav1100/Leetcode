class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, int> m;
        unordered_map<long long, int> visited;
        for(auto& item: nums) {
            m[item] = 1;
        }
        int MAX = 0;
        for(auto& item: nums) {
            if (!visited[item]) {
                __int128 current = item;
                int length = 0;
                while(m[current]) {
                    visited[current] = 1;
                    current = current * current;
                    length++;
                }
                MAX = max(MAX, length);
            }
        }
        return MAX > 1 ? MAX : -1;
    }
};