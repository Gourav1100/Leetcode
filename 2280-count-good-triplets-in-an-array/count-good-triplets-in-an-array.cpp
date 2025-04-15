class SegmentTree {
    vector<vector<int>> array;
    long long size = 0;
    int depth = 0;
    public:
        SegmentTree(long long n) {
            long long temp = pow(2, ceil(log2((float) n)));
            size = temp;
            depth = 0;
            while(temp != 0) {
                array.push_back(vector<int>(size, 0));
                temp >>= 1;
                depth++;
            }
        }
        void insert(long long index, int value) {
            for(int i = 0; i < depth; i++) {
                array[i][index] += value;
                index >>= 1;
            }
        }
        long long left_sum(long long index) {
            // Bottom Up
            long long d = 0, temp = index;
            while(temp != 0) {
                d++;
                temp >>= 1;
            }
            // Top Down
            long long result = array[d][0];
            while(temp != index) {
                bool right = (index - (temp * (1 << d))) >> (d - 1);
                temp <<= 1;
                if (!right) {
                    result -= array[d - 1][temp + 1];
                } else {
                    temp++;
                }
                d--;
            }
            return result - array[d][index];
        }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> positions;
        int n = nums1.size();
        for(int i = 0; i < n; i++) {
            positions[nums2[i]] = i;
        }

        vector<int> lefts(n, 0);
        vector<int> rights(n, 0);
        SegmentTree visited(n);
        for(int i = 0; i < n; i++) {
            visited.insert(positions[nums1[i]], 1);
            lefts[i] = visited.left_sum(positions[nums1[i]]);
        }
        visited = SegmentTree(n);
        for(int i = n - 1; i >= 0; i--) {
            visited.insert(n - 1 - positions[nums1[i]], 1);
            rights[i] = visited.left_sum(n - 1 - positions[nums1[i]]);
        }
        long long result = 0;
        for(int i = 0; i < n; i++) {
            result += (long long) lefts[i] * (long long) rights[i];
        }
        return result;
    }
};