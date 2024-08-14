class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int front = 0, back = *max_element(nums.begin(), nums.end()), n = nums.size();
        sort(nums.begin(), nums.end());
        while(front < back) {
            int mid = front + ((back - front) >> 1);
            int count = 0, start = 0, end = 0;
            while (end < n) {
                while (nums[end] - nums[start] > mid) {
                    start++;
                }
                count += end++ - start;
            }
            if (count < k) {
                front = mid + 1;
            } else {
                back = mid;
            }
        }
        return back;
    }
};