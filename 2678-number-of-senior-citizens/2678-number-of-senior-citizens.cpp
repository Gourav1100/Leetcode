class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0, size = details.size();
        for(int i = 0; i < size; i++) {
            if ((details[i][11] == '6' && details[i][12] > '0') || details[i][11] > '6') result++;
        }
        return result;
    }
};