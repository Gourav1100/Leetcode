class Solution {
public:
    string compressedString(string word) {
        int count = 0;
        char prev = '0';
        string comp = "";
        for(auto& ch: word) {
            if (prev != ch || count == 9) {
                if (prev != '0') {
                    comp += to_string(count);
                    comp += prev;
                }
                prev = ch;
                count = 1;
            } else if (prev == ch) {
                count++;
            }
        }
        comp += to_string(count);
        comp += prev;
        return comp;
    }
};