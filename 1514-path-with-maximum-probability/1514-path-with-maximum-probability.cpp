class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int size = edges.size();
        unordered_map<int, vector<pair<int, double>>> adj;
        vector<double> visited(n, 0);
        for(int i = 0; i < size; i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        queue<pair<int, double>> q;
        double result = 0;
        q.push({start, 1});
        visited[start] = 1;
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                int front = q.front().first;
                double prob = q.front().second;
                q.pop();
                if(front == end) {
                    result = result < prob ? prob : result;
                }
                for(auto& item : adj[front]) {
                    if(visited[item.first] < prob * item.second) {
                        q.push({item.first, prob * item.second});
                        visited[item.first] = prob * item.second;
                    }
                }
            }
        }
        return result;
    }
};