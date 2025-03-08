class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = INT_MAX, whites = 0, back = 0, n = blocks.size();
        for(int i = 0; i < n; i++) {
            if (i >= k) {
                res = min(res, whites);
                whites -= blocks[back] == 'W';
                back++;
            }
            whites += blocks[i] == 'W';
        }
        res = min(res, whites);
        return res;
    }
};