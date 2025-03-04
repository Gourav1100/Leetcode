class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n >= 3) {
            int greatest = 1, prev = 0;
            while(greatest <= n) {
                prev = greatest;
                greatest *= 3;
            }
            n -= prev;
            if (n >= prev) return false;
        }
        return n < 2;
    }
};