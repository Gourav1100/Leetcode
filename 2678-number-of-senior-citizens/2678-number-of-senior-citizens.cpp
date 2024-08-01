class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0;
        for(auto& item: details) {
            string temp = "";
            temp += item[11];
            temp += item[12];
            if (temp > "60") {
                result++;
            }
        }
        return result;
    }
};