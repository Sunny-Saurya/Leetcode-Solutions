class Solution {
public:
    int climbStairs(int n) {
        // base case
        // if(n == 0 || n == 1) return 1;

        // this solution gives TLE
        // return climbStairs(n-1) + climbStairs(n-2);
        vector<int>dp(n, -1);
        return solveMemo(n, dp);
    }

    int solveMemo(int n, vector<int>&dp){

        // base cases
        if(n == 0 || n == 1) return 1;
        if(dp[n-1] != -1) return dp[n-1];
        return dp[n-1] = solveMemo(n-1, dp) + solveMemo(n-2, dp);
    }
};