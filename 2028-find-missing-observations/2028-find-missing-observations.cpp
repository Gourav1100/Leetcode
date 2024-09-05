class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean * (n + rolls.size());
        for(auto& num: rolls) {
            sum -= num;
        }
        int quo = sum / n, rem = sum % n, index = 0;
        if (quo > 6 || quo <= 0 || (quo == 6 && rem != 0)) {
            return {};
        }
        vector<int> result(n, quo);
        while(rem != 0) {
            result[index++]++;
            rem--;
        }
        return result;
    }
};