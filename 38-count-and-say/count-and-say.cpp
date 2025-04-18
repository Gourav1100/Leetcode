class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 0; i < n - 1; i++) {
            string temp = "";
            char prev = '0';
            int count = 0;
            for(auto& ch: result) {
                if (prev != ch) {
                    if (count) {
                        temp += to_string(count);
                        temp += prev;
                    }
                    prev = ch;
                    count = 1;
                } else {
                    count++;
                }
            }
            temp += to_string(count);
            temp += prev;
            result = temp;
        }
        return result;
    }
};