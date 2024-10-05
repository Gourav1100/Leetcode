class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int c[26] = {};
        int c2[26] = {};
        if (s1.size() > s2.size()) {
            return false;
        }
        for(auto& ch: s1) {
            c[ch - 'a']++;
        }
        int back = 0;
        for(int i = 0; i < s2.size(); i++) {
            if (i >= s1.size()) {
                if (equal(begin(c), end(c), begin(c2))) return true;
                c2[s2[back++] - 'a']--;
            }
            c2[s2[i] - 'a']++;
        }
        if (equal(begin(c), end(c), begin(c2))) return true;
        return false;
    }
};