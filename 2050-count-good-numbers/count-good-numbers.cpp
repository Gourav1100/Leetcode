#define MOD 1000000007
class Solution {
public:
    int countGoodNumbers(long long n) {
        return (solve(5, n - (n >> 1)) * solve(4, n >> 1)) % MOD; 
    }
    long long solve(long long num, long long n) {
        long long res = 1;
        while(n != 0) {
            if (n >> 1 << 1 == n) {
                num = (num * num) % MOD;
                n >>= 1;
            } else {
                res = (res * num) % MOD;
                n--;
            }
        }
        return res;
    }
};