class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change_5 = 0, change_10 = 0;
        for(auto& bill: bills) {
            change_5 -= change_10 >= ((bill - 5) / 10) ? (bill - 5 - (((bill - 5) / 10) * 10)) / 5 : ((bill - 5) / 5);
            change_10 -= change_10 >= ((bill - 5) / 10) ? (bill - 5) / 10 : 0;
            if (change_10 < 0 || change_5 < 0) return false;
            change_10 += bill == 10;
            change_5 += bill == 5;
        }
        return true;
    }
};