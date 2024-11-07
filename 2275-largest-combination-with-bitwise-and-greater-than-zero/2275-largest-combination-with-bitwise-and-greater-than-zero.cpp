class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> result(32, 0);
        for(auto& item: candidates) {
            int index = 0;
            while(item != 0) {
                result[index++] += (item >> 1 << 1 != item);
                item >>= 1;
            }
        }
        return *max_element(result.begin(), result.end());
    }
};