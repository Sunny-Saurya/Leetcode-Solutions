class Solution {
public:
    int climbStairs(int n) {  
        //recursion  
        // return solve(n);
        // vector<int>dp(n+1, -1);

        // memo
        // return solveMemo(n, dp);

        // tabulation
        // return solveTab(n);

        // sapce

        return solveSpace(n);
    }

    int solve(int n){
        if(n == 0 || n == 1) return 1;

        return solve(n-1) + solve(n-2);
    }

    // memoization 
    int solveMemo(int n, vector<int>&dp){
        
        if(n == 0 || n == 1) return 1;
        if(dp[n] !=  -1) return dp[n];
        return dp[n] =  solveMemo(n-1, dp) + solveMemo(n-2, dp);
    }

    // Tabulation 

    int solveTab(int n){
        vector<int>dp(n+1, 0);
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    // Space

     int solveSpace(int n){
        vector<int>dp(n+1, 0);
        int pp = 1;
        int p = 1;
        
        for(int i = 2; i <= n; i++){
            int curr = pp+p;
            pp = p;
            p = curr;
        }

        return p;
    }

};