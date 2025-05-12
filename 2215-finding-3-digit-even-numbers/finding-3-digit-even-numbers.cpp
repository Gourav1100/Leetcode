class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        unordered_map<int, int> visited;
        int n = digits.size();
        sort(digits.begin(), digits.end());
        for(int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;
            for(int j = 0; j < n; j++) {
                if (j == i) continue;
                for(int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (!visited[num] && num >> 1 << 1 == num) {
                        visited[num] = 1;
                        result.push_back(num);
                    }
                }
            }
        }
        return result;
    }
};