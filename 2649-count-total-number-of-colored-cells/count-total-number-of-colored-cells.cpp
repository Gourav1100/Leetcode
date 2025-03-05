class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1, next = 4;
        while(n-- > 1) {
            res += next;
            next += 4;
        }
        return res;
    }
};