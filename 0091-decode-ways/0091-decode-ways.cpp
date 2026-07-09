class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1, -1);
        if(s[0] == '0') return 0;
        return solve(s, n-1, dp);
    }

    int solve(string s, int idx, vector<int>&dp){
        if(idx <= 0) return 1;

        if(dp[idx] != -1) return dp[idx];
        int ans = 0;

        if(s[idx] == '0'){
            int num = stoi(s.substr(idx-1, 2));
            if(num <= 26 && num > 9) ans += solve(s, idx-2, dp);
            if(num == 0) return 0;
        }
        else{
            ans += solve(s, idx-1, dp);
            int num = 27;
            if(idx >= 1){
                num = stoi(s.substr(idx-1, 2));
            }

            if(num <= 26 && num > 9){
                ans += solve(s, idx-2, dp);
            }
            if(num == 0) return 0;
        }

        return dp[idx] = ans;
    }
};