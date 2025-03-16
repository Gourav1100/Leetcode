class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        long long front = 0, end = 10e17;
        while(front <= end) {
            long long mid = end - ((end - front) >> 1);
            if (isValid(ranks, mid, cars)) {
                end = mid - 1;
            } else {
                front = mid + 1;
            }
        }
        // cout << front << " " << end << endl;
        return front;
    }
    bool isValid(vector<int>& ranks, long long mid, long long cars) {
        for(int i = 0; i < ranks.size(); i++) {
            long long c = floor(sqrt(mid / ranks[i]));
            cars -= c;
        }
        return cars <= 0;
    }
};