class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // return solve(n-1, m-1, s, t);
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solveMem(n - 1, m - 1, s, t, dp);
        // return solveTab(n, m, s,t);
        return solveSpace(n, m, s,t);
    }

    int solve(int i, int j, string& s, string& t) {
        // base case
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (s[i] == t[j]) {
            return (solve(i - 1, j - 1, s, t) + solve(i - 1, j, s, t));
        } else {
            return solve(i - 1, j, s, t);
        }
    }

    int solveMem(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        // base case
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = (solveMem(i - 1, j - 1, s, t, dp) +
                               solveMem(i - 1, j, s, t, dp));
        } else {
            return dp[i][j] = solveMem(i - 1, j, s, t, dp);
        }
    }

    int solveTab(int i, int j, string &s, string &t) {
        // base case
        // 1 based indexing
        int n = s.size(), m = t.size();
        vector<vector<double >> dp(n+1, vector<double>(m+1, 0));

        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        for(int j = 1; j <= m; j++){
            dp[0][j] = 0;
        }


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = (dp[i - 1][j - 1]+
                                       dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }

    int solveSpace(int i, int j, string &s, string &t) {
        // base case
        // 1 based indexing
        int n = s.size(), m = t.size();
        vector<double>prev(m+1, 0), curr(m+1, 0);

        prev[0] = curr[0] = 1;


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    curr[j] = (prev[j - 1]+
                                       prev[j]);
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};