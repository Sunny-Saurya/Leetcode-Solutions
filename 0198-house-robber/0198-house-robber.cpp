class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int>dp(n+1, -1);
        return solveMemo(n,nums, dp);
    }

    // Memoizatino
    int solveMemo(int idx, vector<int>&nums, vector<int>&dp){
        if(idx == 0 ) return nums[0];
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solveMemo(idx-2, nums, dp);
        int noteTake = 0 + solveMemo(idx-1, nums, dp);

        return dp[idx] = max(take, noteTake);

    }

    // Tabulation
    int solveTab(int idx, vector<int>&nums){
        vector<int>dp(nums.size(), 0);

        dp[0] = nums[0];
        if(idx < 0) return 0;

        for(int idx = 1; idx <= nums.size(); idx++){
            int take = nums[idx] + dp[idx-2];
            int noteTake = 0 + dp[idx-1];

            dp[idx] = max(take, noteTake);
        }

        return dp[nums.size()-1];
    }
};