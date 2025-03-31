class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> pq1, pq2;
        int n = weights.size();
        for(int i = 0; i < n - 1; i++) {
            pq1.push(weights[i] + weights[i + 1]);
            pq2.push(-(weights[i] + weights[i + 1]));
        }
        long long sum_max = 0, sum_min = 0;
        for(int i = 0; i < k - 1; i++) {
            sum_max += pq1.top();
            pq1.pop();
            sum_min += -pq2.top();
            pq2.pop();
        }
        return sum_max - sum_min;
    }
};