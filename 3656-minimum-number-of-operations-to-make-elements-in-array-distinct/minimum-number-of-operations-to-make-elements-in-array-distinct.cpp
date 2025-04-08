class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0, back = 0, front = 0;
        unordered_map<int, int> freq;
        for(;front < nums.size(); front++) {
            // cout << front << endl;
            if (freq[nums[front]] == 1) {
                operations++;
                for(int i = 0; i < 3 && back < nums.size(); i++) {
                    // cout << back << " ";
                    freq[nums[back]] = max(0, freq[nums[back]] - 1);
                    back++;
                }
                // cout << endl;
                if (back > front) {
                    front = back - 1;
                } else {
                    front--;
                }
            } else {
                freq[nums[front]]++;
            }
        }
        return operations;
    }
};