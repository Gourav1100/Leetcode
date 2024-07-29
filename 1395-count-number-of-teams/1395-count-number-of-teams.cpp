class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> dp_greater(n, 0);
        vector<int> dp_lesser(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                dp_greater[i] += rating[i] < rating[j];
                dp_lesser[i] += rating[i] > rating[j];
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                result += rating[i] < rating[j] ? dp_greater[j] : 0;
                result += rating[i] > rating[j] ? dp_lesser[j] : 0;
            }
        }
        return result;
    }
};
