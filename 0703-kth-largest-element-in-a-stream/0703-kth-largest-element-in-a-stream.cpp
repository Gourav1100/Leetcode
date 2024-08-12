class KthLargest {
    priority_queue<int> pq;
    int m;
public:
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        pq = priority_queue<int>();
        m = k;
        for(int i = 0; i < n; i++) pq.push(-nums[i]);
        while(pq.size() > k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(-val);
        if(pq.size() > m) pq.pop();
        return -pq.top();
    }
};