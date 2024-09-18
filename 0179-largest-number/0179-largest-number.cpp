class Solution {
    static bool comp(string& a, string& b) {
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num_s;
        for(auto& num: nums) {
            num_s.push_back(to_string(num));
        }
        sort(num_s.begin(), num_s.end(), comp);
        string result = "";
        for(auto& num: num_s) {
            result += num;
        }
        try {
            return to_string(stoll(result));
        } catch (...) {}
        return result;
    }
};