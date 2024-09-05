class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sum = mean * (n + m);
        while(m > 0) {
            sum -= rolls[--m];
        }
        int quo = sum / n, rem = sum % n;
        if (quo > 6 || quo <= 0 || (quo == 6 && rem != 0)) {
            return {};
        }
        vector<int> result(n, quo);
        while(rem != 0) {
            result[m++]++;
            rem--;
        }
        return result;
    }
};