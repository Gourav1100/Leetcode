class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            bool isValid = true;
            for(int j = 0; j < n; j++) {
                if (goal[j] != s[(i + j) % n]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                return true;
            }
        }
        return false;
    }
};