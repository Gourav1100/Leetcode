class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        for(auto& c : chalk) {
            sum += c;
        }
        k %= sum;
        int index = 0;
        for(auto& c : chalk) {
            if (k < c) {
                break;
            }
            k -= c;
            index++;
        }
        return index;
    }
};