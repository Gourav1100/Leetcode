class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int front = 1, end = 10e7;
        while(front <= end) {
            int mid = end - ((end - front) >> 1);
            long long count = 0;
            for (int i = 0; i < candies.size(); i++) {
                count += candies[i] / mid;
            }
            front = count >= k ? mid + 1 : front;
            end = count >= k ? end : mid - 1;
        }
        return end;
    }
};