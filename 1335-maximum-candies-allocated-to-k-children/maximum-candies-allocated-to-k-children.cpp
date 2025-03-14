class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int front = 1, end = 10e7;
        long long count = 0;
        while(front <= end) {
            int mid = end - ((end - front) >> 1);
            count = 0;
            for (int i = 0; i < candies.size(); i++) {
                count += candies[i] / mid;
            }
            if (count >= k) {
                front = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }
};