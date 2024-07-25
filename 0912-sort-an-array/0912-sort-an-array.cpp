class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto& num: nums) {
            pq.push(-num);
        }
        int index = 0;
        while(!pq.empty()) {
            nums[index++] = -pq.top();
            pq.pop();
        }
        return nums;
    }
};