class Solution {
public:
    string shortestPalindrome(string& s) {
        int n = s.size(), i = 0, j = n - 1;
        string temp = "", remain_rev = s;
        while(j >= 0) {
            if (s[i] == s[j--]) {
                temp += s[i];
                remain_rev.erase(0, 1);
                i++;
            }
        }
        if (i == n) {
            return s;
        }
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(temp) + s.substr(i);
    }
};