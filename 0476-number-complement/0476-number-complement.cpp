class Solution {
public:
    int findComplement(int num) {
        int p = log2(num) + 1;
        return pow(2, p) - 1 - num;
    }
};