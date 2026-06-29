class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, l = 0, r = 0, n = nums.size();
        int maxi = INT_MIN;
        while(r < n){
            sum += nums[r];
            maxi = max(maxi, sum);
            if(sum < 0){
                sum = 0;
            }
            r++;
        }
        return maxi;
    }
};