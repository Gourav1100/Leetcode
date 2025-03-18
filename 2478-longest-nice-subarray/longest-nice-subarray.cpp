class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int front = 0, end = min((int)nums.size(), 30);
        while(front <= end) {
            int mid = end - ((end - front) >> 1);
            bool valid = false;
            for(int i = 0; i < nums.size() - mid && !valid; i++) {
                bool isCurrentValid = true;
                for(int j = i; j < i + mid + 1 && isCurrentValid; j++) {
                    for(int k = j; k < i + mid + 1 && isCurrentValid; k++) {
                        int bitAND = nums[j] & nums[k];
                        if (j != k && bitAND != 0) {
                            isCurrentValid = false;
                        }
                    }
                }
                if (isCurrentValid) {
                    valid = true;
                }
            }
            if (valid) {
                front = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        // cout << front << " " << end << endl;
        return front;
    }
};