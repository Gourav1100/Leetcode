class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        n--;
        long long last = -1;
        unordered_map<long long, bool> m;
        priority_queue<long long> pq;
        pq.push(-2);
        pq.push(-3);
        pq.push(-5);
        while(n != 0) {
            long long num = pq.top();
            last = -num;
            pq.pop();
            if (!m[num * 2]) {
                pq.push(num * 2);
                m[num * 2] = true;
            }
            if (!m[num * 3]) {
                pq.push(num * 3);
                m[num * 3] = true;
            }
            if (!m[num * 5]) {
                pq.push(num * 5);
                m[num * 5] = true;
            }
            n--;
        }
        return last;
    }
};