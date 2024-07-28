class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> times(n + 1, vector<int>(2, INT_MAX));
        queue<pair<int, int>> q;
        q.push({1, 0});
        times[1][0] = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int t = q.front().second;
            q.pop();

            int cycle = 2 * change;
            int waitTime = 0;
            if ((t / change) % 2 == 1) {
                waitTime = cycle - (t % cycle);
            }

            int nextTime = t + time + waitTime;

            for (int nextNode : adj[node]) {
                if (nextTime < times[nextNode][0]) {
                    times[nextNode][1] = times[nextNode][0];
                    times[nextNode][0] = nextTime;
                    q.push({nextNode, nextTime});
                } else if (nextTime > times[nextNode][0] && nextTime < times[nextNode][1]) {
                    times[nextNode][1] = nextTime;
                    q.push({nextNode, nextTime});
                }
            }
        }

        return times[n][1];
    }
};
