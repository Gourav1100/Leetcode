class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> sums;
        int MAX = 0, count = 0;
        for(int i = 1; i <= n; i++) {
            int sum = 0, temp = i;
            while(temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }
            sums[sum]++;
            if (MAX == sums[sum]) {
                count++;
            } else if (MAX < sums[sum]) {
                MAX = sums[sum];
                count = 1;
            }
        }
        return count;
    }
};