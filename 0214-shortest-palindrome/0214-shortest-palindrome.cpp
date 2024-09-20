class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size(), i = 0, j = n - 1;
        while(j >= 0) {
            if (s[i] == s[j--])
                i++;
        }
        if (i == n) {
            return s;
        }
        string remain_rev = s.substr(i, n);
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};