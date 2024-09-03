class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        string transformed = "";
        for(auto& ch: s) {
            transformed += to_string(ch - 'a' + 1);
        }
        s = transformed;
        while(k--) {
            res = 0;
            for(auto& ch: s) {
                res += ch - '0';
            }
            s = to_string(res);
        }
        return res;
    }
};