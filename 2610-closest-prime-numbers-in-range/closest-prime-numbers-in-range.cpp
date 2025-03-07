class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> seive(right + 1, 0);
        for(int i = 2; i < right + 1; i++) {
            if (seive[i] == 0) {
                for(int j = i + i; j < right + 1; j += i) {
                    seive[j] = 1;
                }
            }
        }
        int num1 = -1, num2 = -1, res_0 = -1, res_1 = -1;
        for(int i = left; i <= right; i++) {
            if (seive[i] == 0 && i > 1) {
                if (num1 == -1) {
                    num1 = i;
                    res_0 = i;
                } else if (num2 == -1) {
                    num2 = i;
                    res_1 = i;
                } else {
                    num1 = num2;
                    num2 = i;
                }
                if (num1 != -1 && num2 != -1 && num2 - num1 < res_1 - res_0) {
                    res_0 = num1;
                    res_1 = num2;
                }
            }
        }
        if (res_0 == -1 || res_1 == -1) {
            return {-1, -1};
        }
        return {res_0, res_1};
    }
};