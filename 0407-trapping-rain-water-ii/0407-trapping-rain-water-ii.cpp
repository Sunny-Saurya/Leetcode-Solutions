class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m < 3 || n < 3) return 0;

        // {height, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Push all boundary cells
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            vis[i][0] = true;
            vis[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            vis[0][j] = true;
            vis[m - 1][j] = true;
        }

        int water = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int height = curr[0];
            int r = curr[1];
            int c = curr[2];

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc])
                    continue;

                vis[nr][nc] = true;

                // Water trapped at this cell
                water += max(0, height - heightMap[nr][nc]);

                // Push the effective height
                pq.push({max(height, heightMap[nr][nc]), nr, nc});
            }
        }

        return water;
    }
};