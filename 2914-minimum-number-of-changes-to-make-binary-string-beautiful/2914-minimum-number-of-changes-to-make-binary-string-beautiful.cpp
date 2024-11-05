class Solution {
public:
    int minChanges(string s) {
        vector<char> chars;
        vector<int> count;
        int c = 0;
        for(auto& ch: s) {
            if (chars.size() == 0 || chars[chars.size() - 1] != ch) {
                chars.push_back(ch);
                if (c != 0) {
                    count.push_back(c);
                }
                c = 1;
            } else {
                c++;
            }
        }
        count.push_back(c);
        int result = 0;
        for(int i = 0; i < chars.size(); i++) {
            if (count[i] % 2) {
                count[i]--;
                result++;
                count[i + 1]++;
            }
        }
        return result;
    }
};