class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, res = 0;
        for(auto& ch: s) {
            if (ch == '(') {
                open++;
            } else {
                if (open == 0) {
                    res++;
                }
                open = max(open - 1, 0);
            }
        }
        return res + open;
    }
};