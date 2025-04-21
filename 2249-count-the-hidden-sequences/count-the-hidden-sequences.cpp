class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long MIN = 0, MAX = 0, running = 0;
        for(auto& num: differences) {
            running += num;
            MIN = min(MIN, running);
            MAX = max(MAX, running);
        }
        return max((long long)0, upper - MAX - lower + MIN + 1);
    }
};