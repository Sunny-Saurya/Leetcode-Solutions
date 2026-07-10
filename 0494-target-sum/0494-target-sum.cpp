class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        solve(0, nums, target, 0, count);
        return count;
    }

    void solve(int idx, vector<int>&nums, int target, int resSoFar, int &count){
        if(idx == nums.size()){
            if(resSoFar == target){
                count++;
            } 
                return;
        }

        solve(idx+1, nums, target, resSoFar + nums[idx], count);
        solve(idx+1, nums, target, resSoFar - nums[idx], count);
    }
};