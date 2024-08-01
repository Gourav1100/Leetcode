class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0;
        for(auto& item: details) {
            if ((item[11] == '6' && item[12] > '0') || item[11] > '6') {
                result++;
            }
        }
        return result;
    }
};