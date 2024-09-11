class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        while(start != 0 || goal != 0) {
            int b_s = start - ((start >> 1) << 1), b_g = goal - ((goal >> 1) << 1);
            res += b_s != b_g;
            start >>= 1;
            goal >>= 1;
        }
        return res;
    }
};