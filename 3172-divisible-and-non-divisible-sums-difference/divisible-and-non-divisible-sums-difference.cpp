class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = ((n * (n + 1)) >> 1), quo = n / m, sum_2 = m * (quo * (quo + 1));
        return sum - sum_2;
    }
};