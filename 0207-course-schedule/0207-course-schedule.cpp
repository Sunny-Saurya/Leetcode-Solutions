class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        int v = numCourses;
        vector<vector<int>>adj(v);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int>vis(v, 0), dfsVis(v, 0);

        for(int i = 0; i < v; i++){
            if(!vis[i]){
                if(dfs(i,vis, adj, dfsVis)){
                    return false;
                }
            }
        }

        return true;
    }

    bool  dfs(int node, vector<int>&vis, vector<vector<int>>&adj, vector<int>&dfsVis){
        vis[node] = 1;
        dfsVis[node]  = 1;

        for(auto nei : adj[node]){
            if(!vis[nei]){
                if(dfs(nei, vis, adj, dfsVis)) return true;
            }
            else if(dfsVis[nei]){
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }
};