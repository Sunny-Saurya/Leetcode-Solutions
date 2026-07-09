class Solution {
public:
    int numSquares(int n) {
        vector<int>ans;
        for(int i = 1; i*i <= n; i++){
            ans.push_back(i*i);
        }
        vector<vector<int>> dp(n+1, vector<int>(ans.size(), -1));
        return solve(n, ans, 0, dp);

    }

    int solve(int temp, vector<int>& ans, int idx, vector<vector<int>>&dp){
        if(temp == 0) return 0;
        if(idx >= ans.size() || temp < 0) return 1e9;

        if(dp[temp][idx] != -1) return dp[temp][idx];
        // take
        int take = 1+ solve(temp - ans[idx], ans, idx, dp);
        // not take
        int notTake = solve(temp, ans, idx+1, dp);

        return dp[temp][idx] = min(take, notTake);

        
    }
};