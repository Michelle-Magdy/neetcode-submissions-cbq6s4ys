class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // dist[node][stops]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        // {cost, node, stops}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<>
        > pq;

        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            if (u == dst) return cost;
            if (stops > k) continue;

            for (auto [v, w] : adj[u]) {
                if (cost + w < dist[v][stops + 1]) {
                    dist[v][stops + 1] = cost + w;
                    pq.push({cost + w, v, stops + 1});
                }
            }
        }

        return -1;
    }
};
