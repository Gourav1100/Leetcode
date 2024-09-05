class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean * (n + rolls.size());
        for(auto& num: rolls) {
            sum -= num;
        }
        if (sum / n > 6 || sum / n <= 0 || (sum / n == 6 && sum % n != 0)) {
            return {};
        }
        vector<int> result(n, sum / n);
        int remaining = sum % n, index = 0;
        while(remaining != 0) {
            result[index++]++;
            remaining--;
        }
        return result;
    }
};