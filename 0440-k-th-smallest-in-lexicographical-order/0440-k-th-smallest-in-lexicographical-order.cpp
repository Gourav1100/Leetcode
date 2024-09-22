long long min(long long a, long long b) {
    return a > b ? b : a;
}
class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;
        while (k != 1) {
            long long count = 1, temp = 10;
            while(current * temp <= n) {
                count += min(current * temp + temp - 1, n) - (current * temp) + 1;
                temp = temp * 10;
            }
            current = count >= k ? current * 10 : current + 1;
            k -= count >= k ? 1 : count;
        }
        return current;
    }
};