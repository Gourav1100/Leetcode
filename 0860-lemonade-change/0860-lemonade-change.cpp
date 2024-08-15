class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change_5 = 0, change_10 = 0;
        for(auto& bill: bills) {
            int remaining_amount = bill - 5;
            int bill_10_case_0 = remaining_amount / 10;
            int bill_5_case_0 = (remaining_amount - (bill_10_case_0 * 10)) / 5;
            int bill_5_case_1 = remaining_amount / 5;
            change_5 -= change_10 >= bill_10_case_0 ? bill_5_case_0 : bill_5_case_1;
            change_10 -= change_10 >= bill_10_case_0 ? bill_10_case_0 : 0;
            if (change_10 < 0 || change_5 < 0) return false;
            change_10 += bill == 10;
            change_5 += bill == 5;
        }
        return true;
    }
};