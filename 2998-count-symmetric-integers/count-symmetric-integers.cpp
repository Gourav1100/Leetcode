class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i <= high; i++) {
            string s_i = to_string(i);
            int size = s_i.size(), half = size >> 1;
            if (half << 1 == size) {
                int left_sum = 0, right_sum = 0;
                for(int j = 0; j < half; j++) {
                    left_sum += s_i[j] - '0';
                    right_sum += s_i[j + half] - '0';
                }
                res += left_sum == right_sum;
            }
        }
        return res;
    }
};