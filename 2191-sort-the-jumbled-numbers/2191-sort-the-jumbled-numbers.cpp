class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> new_system_nums;
        unordered_map<int, vector<int>> m;
        unordered_map<int, int> indices;
        for(auto& num : nums) {
            string s = to_string(num);
            int new_num = 0;
            for(auto& ch: s) {
                new_num = new_num * 10 + mapping[ch - '0'];
            }
            new_system_nums.push_back(new_num);
            m[new_num].push_back(num);
            indices[new_num] = -1;
        }
        sort(new_system_nums.begin(), new_system_nums.end());
        int size = new_system_nums.size();
        for(int i = 0; i < size; i++) {
            indices[new_system_nums[i]] = indices[new_system_nums[i]] + 1;
            new_system_nums[i] = m[new_system_nums[i]][indices[new_system_nums[i]]];
        }
        return new_system_nums;
    }
};