class Solution {
public:
    int minSwaps(vector<int>& nums) {
        queue<int> q;
        int count_one = 0, result = INT_MAX, current_one = 0, index = 0, size = nums.size();
        for(index = 0; index < size; index++) {
            count_one += nums[index];
            nums.push_back(nums[index]);
        }
        if (!count_one) {
            return 0;
        }
        for(auto& num: nums) {
            if (q.size() == count_one) {
                result = min(result, count_one - current_one);
                current_one -= q.front();
                q.pop();
            }
            q.push(num);
            current_one += num;
        }
        if (q.size() == count_one) {
            result = min(result, count_one - current_one);
            current_one -= q.front();
            q.pop();
        }
        return result;
    }
};