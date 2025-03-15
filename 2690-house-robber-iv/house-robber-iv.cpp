class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int end = *max_element(nums.begin(), nums.end()), front = *min_element(nums.begin(), nums.end());
        while(front <= end) {
            int mid = end - ((end - front) >> 1);
            if (isValid(nums, mid, k)) {
                end = mid - 1;
            } else {
                front = mid + 1;
            }
        }
        // cout << front << " " << end << endl;
        return front;
    }
    bool isValid(vector<int>& nums, int mid, int k) {
        int count = 0, n = nums.size(), allowed = 0;
        vector<int> visited(n + 1, 0);
        for(int i = 0; i < n; i++) {
            allowed += nums[i] <= mid;
            if (!visited[i + 1] && (i == 0 || !visited[i - 1]) && nums[i] <= mid) {
                visited[i] = 1;
                count++;
            }
        }
        // cout << mid << " " << count << " " << allowed << endl;
        return count >= k || (allowed - count >= k);
    }
};