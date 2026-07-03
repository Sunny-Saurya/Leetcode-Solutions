class Solution {
private:
    bool dfs(int node, int col, vector<int>& color,
             unordered_map<int, list<int>>& adj) {
        color[node] = col;
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (dfs(it, !col, color, adj) == false)
                    return false;
            } else if (color[it] == col)
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, list<int>> adj;
        int V = graph.size();

        for (int i = 0; i < V; i++) {
            for (int neighbor : graph[i]) {
                adj[i].push_back(neighbor);
            }
        }

        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, adj) == false)
                    return false;
            }
        }
        return true;
    }
};