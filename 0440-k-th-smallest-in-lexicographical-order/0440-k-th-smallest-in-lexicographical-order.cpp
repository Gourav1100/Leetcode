class Solution {
    long long min(long long a, long long b) {
        return a > b ? b : a;
    }
public:
    int findKthNumber(int n, int k) {
        long long current = 1;
        while (k != 1) {
            long long count = 1, temp = current * 10, level_elements = 9;
            while(temp <= n) {
                count += min(temp + level_elements, n) - temp + 1;
                level_elements = level_elements * 10 + 9;
                temp = temp * 10;
            }
            // cout << current << " " << count << " " << k << endl;
            if (count >= k) {
                current = current * 10;
                k--;
            } else {
                k -= count;
                current++;
            }
        }
        return current;
    }
};