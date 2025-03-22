class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> visited;
        unordered_map<int, unordered_map<int, int>> adj;
        for(auto& edge: edges) {
            adj[edge[0]][edge[1]] = 1;
            adj[edge[1]][edge[0]] = 1;
        }
        int res = 0;
        for(int item = 0; item < n; item++) {
            if (!visited[item]) {
                bool isComplete = true;
                queue<int> q;
                q.push(item);
                visited[item] = 1;
                vector<int> nodes;
                while(!q.empty()) {
                    int size = q.size();
                    while(size--) {
                        int front = q.front();
                        nodes.push_back(front);
                        q.pop();
                        for(auto& node: adj[front]) {
                            if (!visited[node.first]) {
                                q.push(node.first);
                                visited[node.first] = 1;
                            }
                        }
                    }
                }
                for(auto& node_a: nodes) {
                    for(auto& node_b: nodes) {
                        if (node_a == node_b) continue;
                        if (!adj[node_a][node_b]) {
                            isComplete = false;
                        }
                    }
                }
                if (isComplete) {
                    res++;
                }
            }
        }
        return res;
    }
};