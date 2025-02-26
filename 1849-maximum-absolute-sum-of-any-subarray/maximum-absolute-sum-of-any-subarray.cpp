class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEndingSum = 0, minEndingSum = 0;
        int resMax = 0, resMin = 0;
        for(auto& item: nums) {
            maxEndingSum = max(maxEndingSum + item, item);
            resMax = max(resMax, maxEndingSum);
            minEndingSum = min(minEndingSum + item, item);
            resMin = min(resMin, minEndingSum);
        }
        return max(abs(resMax), abs(resMin));
    }
};