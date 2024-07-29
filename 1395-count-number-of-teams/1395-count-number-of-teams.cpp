class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> dp_greater(n, 0);
        vector<int> dp_lesser(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            int count_greater = 0, count_lesser = 0;
            for(int j = i + 1; j < n; j++) {
                if (rating[i] < rating[j]) {
                    count_greater++;
                } else if (rating[i] > rating[j]) {
                    count_lesser++;
                }
            }
            dp_greater[i] = count_greater;
            dp_lesser[i] = count_lesser;
        }
        int result = 0;
        for(int i = 0; i < n; i++) {
            int count_greater = 0, count_lesser = 0;
            for(int j = i + 1; j < n; j++) {
                result += rating[i] < rating[j] ? dp_greater[j] : 0;
                result += rating[i] > rating[j] ? dp_lesser[j] : 0;
            }
        }
        return result;
    }
};
