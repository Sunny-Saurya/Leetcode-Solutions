class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cnt = e[2];

            adj[u].push_back({v, cnt + 1});
            adj[v].push_back({u, cnt + 1});
        }

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto &[v, w] : adj[u]) {

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        long long ans = 0;

        // Count reachable original nodes
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves)
                ans++;
        }

        // Count reachable subdivided nodes
        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int cnt = e[2];

            long long fromU = 0;
            long long fromV = 0;

            if (dist[u] <= maxMoves)
                fromU = maxMoves - dist[u];

            if (dist[v] <= maxMoves)
                fromV = maxMoves - dist[v];

            ans += min((long long)cnt, fromU + fromV);
        }

        return (int)ans;
    }
};