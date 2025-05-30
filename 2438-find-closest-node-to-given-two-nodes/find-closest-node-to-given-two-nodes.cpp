class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> arr(n, INT_MAX);
        vector<int> brr(n, INT_MAX);
        int dist = 0;
        while(node1 != -1 && arr[node1] == INT_MAX) {
            arr[node1] = dist++;
            node1 = edges[node1];
        }
        dist = 0;
        while(node2 != -1 && brr[node2] == INT_MAX) {
            brr[node2] = dist++;
            node2 = edges[node2];
        }
        int MIN = 0;
        for(int i = 0; i < n; i++) {
            arr[i] = max(arr[i], brr[i]);
            if(arr[MIN] > arr[i]) {
                MIN = i;
            }
        }
        return arr[MIN] == INT_MAX ? -1 : MIN;
    }
};